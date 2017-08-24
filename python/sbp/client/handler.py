# Copyright (C) 2015 Swift Navigation Inc.
# Contact: Mark Fine <mark@swiftnav.com>
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
"""
The :mod:`sbp.client.handler` module contains classes related to
SBP message handling.
"""

import collections
import threading
import weakref
from Queue import Queue


class Handler(object):
    """
    Handler

    The :class:`Handler` class provides an interface for connecting handlers
    to a driver providing SBP messages.  Also provides queued and filtered
    iterators for synchronous, blocking use in other threads.

    Parameters
    ----------
    source : Iterable of tuple(SBP message, {'time':'ISO 8601 str'})
      Stream of SBP messages
    """

    def __init__(self, source):
        self._source = source
        self._callbacks = collections.defaultdict(set)
        self._receive_thread = threading.Thread(
            target=self._recv_thread, name="Handler")
        self._receive_thread.daemon = True
        self._sinks = []  # This is a list of weakrefs to upstream iterators
        self._dead = False
        self._write_lock = threading.Lock()

    def _recv_thread(self):
        """
        Internal thread to iterate over source messages and dispatch callbacks.
        """
        for msg, metadata in self._source:
            if msg.msg_type:
                self._call(msg, **metadata)
        # Break any upstream iterators
        for sink in self._sinks:
            i = sink()
            if i is not None:
                i.breakiter()
        self._dead = True

    def __enter__(self):
        self.start()
        return self

    def __exit__(self, *args):
        self.stop()

    # This exception is raised when a message is dispatched to a garbage
    # collected upstream iterator.
    class _DeadCallbackException(Exception):
        pass

    def filter(self, msg_type=None, maxsize=0):
        """
        Get a filtered iterator of messages for synchronous, blocking use in
        another thread.
        """
        if self._dead:
            return iter(())
        iterator = Handler._SBPQueueIterator(maxsize)
        # We use a weakref so that the iterator may be garbage collected if it's
        # consumer no longer has a reference.
        ref = weakref.ref(iterator)
        self._sinks.append(ref)

        def feediter(msg, **metadata):
            i = ref()
            if i is not None:
                i(msg, **metadata)
            else:
                raise Handler._DeadCallbackException

        self.add_callback(feediter, msg_type)
        return iterator

    def __iter__(self):
        """
        Get a queued iterator that will provide the same unfiltered messages
        read from the source iterator.
        """
        return self.filter()

    def add_callback(self, callback, msg_type=None):
        """
        Add per message type or global callback.

        Parameters
        ----------
        callback : fn
          Callback function
        msg_type : int | iterable
          Message type to register callback against. Default `None` means global callback.
          Iterable type adds the callback to all the message types.
        """
        try:
            for mt in iter(msg_type):
                self._callbacks[mt].add(callback)
        except TypeError:
            self._callbacks[msg_type].add(callback)

    def remove_callback(self, callback, msg_type=None):
        """
        Remove per message type of global callback.

        Parameters
        ----------
        callback : fn
          Callback function
        msg_type : int | iterable
          Message type to remove callback from. Default `None` means global callback.
          Iterable type removes the callback from all the message types.
        """
        if msg_type is None:
            msg_type = self._callbacks.keys()

        try:
            for mt in iter(msg_type):
                try:
                    self._callbacks[mt].remove(callback)
                except KeyError:
                    pass
        except TypeError as e:
            self._callbacks[msg_type].remove(callback)

    def _gc_dead_sinks(self):
        """
        Remove any dead weakrefs.
        """
        deadsinks = []
        for i in self._sinks:
            if i() is None:
                deadsinks.append(i)
        for i in deadsinks:
            self._sinks.remove(i)

    def _get_callbacks(self, msg_type):
        """
        Return all callbacks (global and per message type) for a message type.

        Parameters
        ----------
        msg_type : int
          Message type to return callbacks for.
        """
        return self._callbacks[None] | self._callbacks[msg_type]

    def _call(self, msg, **metadata):
        """
        Process message with all callbacks (global and per message type).
        """
        if msg.msg_type:
            for callback in self._get_callbacks(msg.msg_type):
                try:
                    callback(msg, **metadata)
                except Handler._DeadCallbackException:
                    # The callback was an upstream iterator that has been garbage
                    # collected.  Remove it from our internal structures.
                    self.remove_callback(callback)
                    self._gc_dead_sinks()
                except SystemExit:
                    raise
                except:
                    import traceback
                    traceback.print_exc()

    def start(self):
        """
        Start processing SBP messages with handlers.
        """
        self._receive_thread.start()

    def stop(self):
        """
        Stop processing SBP messages.
        """
        try:
            self._source.breakiter()
            self._receive_thread.join(0.1)
        except:
            pass

    def is_alive(self):
        """
        Return whether the processes thread is alive.
        """
        return self._receive_thread.is_alive()

    def wait(self, msg_type, timeout=1.0):
        """
        Wait for a SBP message.

        Parameters
        ----------
        msg_type : int
          SBP message type.
        timeout : float
          Waiting period
        """
        event = threading.Event()
        payload = {'data': None}

        def cb(sbp_msg, **metadata):
            payload['data'] = sbp_msg
            event.set()

        self.add_callback(cb, msg_type)
        event.wait(timeout)
        self.remove_callback(cb, msg_type)
        return payload['data']

    def wait_callback(self, callback, msg_type=None, timeout=1.0):
        """
        Wait for a SBP message with a callback.

        Parameters
        ----------
        callback : fn
          Callback function
        msg_type : int | iterable
          Message type to register callback against. Default `None` means global callback.
          Iterable type adds the callback to all the message types.
        timeout : float
          Waiting period
        """
        event = threading.Event()

        def cb(msg, **metadata):
            callback(msg, **metadata)
            event.set()

        self.add_callback(cb, msg_type)
        event.wait(timeout)
        self.remove_callback(cb, msg_type)

    def __call__(self, msg, **metadata):
        with self._write_lock:
            self._source(msg, **metadata)

    class _SBPQueueIterator(object):
        """
        Class for upstream iterators.  Implements callable interface for adding
        messages into the queue, and iterable interface for getting them out.
        """

        def __init__(self, maxsize):
            self._queue = Queue(maxsize)
            self._broken = False

        def __iter__(self):
            return self

        def __call__(self, msg, **metadata):
            self._queue.put((msg, metadata), False)

        def breakiter(self):
            self._broken = True
            self._queue.put(None, True, 1.0)

        def next(self):
            if self._broken and self._queue.empty():
                raise StopIteration
            m = self._queue.get(True)
            if self._broken and m is None:
                raise StopIteration
            return m
