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

import warnings
import collections
import threading
import weakref
import six
from six.moves.queue import Queue


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
    autostart : Boolean
      If false, start() shall be skipped when entering context scope and it
      should be explicitly called by the parent. This will prevent losing
      messages in case where receive thread would otherwise be started before
      consumers are ready.
    """

    def __init__(self, source, autostart=True):
        self._autostart = autostart
        self._source = source
        self._callbacks = collections.defaultdict(set)
        self._receive_thread = threading.Thread(
            target=self._recv_thread, name="Handler")
        self._receive_thread.daemon = True
        self._sinks = []  # This is a list of weakrefs to upstream iterators
        self._dead = False
        self._exception = None
        self._write_lock = threading.Lock()

    def _recv_thread(self):
        """
        Internal thread to iterate over source messages and dispatch callbacks.
        """
        def gen_messages():
            for msg, metadata in self._source:
                if msg.msg_type:
                    yield (msg, metadata)

        messages = gen_messages()
        while True:
            msg_and_metadata = None
            try:
                msg_and_metadata = next(messages, None)
            except Exception as exc:
                self._exception = exc
                break
            if msg_and_metadata is None:
                break
            msg, metadata = msg_and_metadata
            self._call(msg, **metadata)
        # Break any upstream iterators
        for sink in self._sinks:
            i = sink()
            if i is not None:
                i.breakiter(self._exception)
        self._dead = True

    def __enter__(self):
        if self._autostart:
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

    def _to_iter(self, maybe_iter):
        try:
            return iter(maybe_iter)
        except TypeError:
            return None

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
        cb_keys = self._to_iter(msg_type)
        if cb_keys is not None:
            for msg_type_ in cb_keys:
                self._callbacks[msg_type_].add(callback)
        else:
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
        cb_keys = self._to_iter(msg_type)
        if cb_keys is not None:
            for msg_type_ in cb_keys:
                try:
                    self._callbacks[msg_type_].remove(callback)
                except KeyError:
                    pass
        else:
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
        except Exception as exc:
            warnings.warn("Handler stop error: %s" % (exc,))
            pass

    def join(self, timeout=None):
        self._receive_thread.join(timeout)

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

    def __call__(self, *msgs, **metadata):
        """
        Pass messages to the `source` to be consumed.  Typically this means
        the messages will be framed and transmitted via whatever transport
        layer is currently active.

        Parameters
        ----------
        msgs : SBP messages
          SBP messages to send.
        metadata : dict
          Metadata for this batch of messages, passed to the `source`.
        """
        with self._write_lock:
            self._source(*msgs, **metadata)

    class _SBPQueueIterator(six.Iterator):
        """
        Class for upstream iterators.  Implements callable interface for adding
        messages into the queue, and iterable interface for getting them out.
        """

        def __init__(self, maxsize):
            self._queue = Queue(maxsize)
            self._broken = False
            self._exception = None  # type: Optional[Exception]

        def __iter__(self):
            return self

        def __call__(self, msg, **metadata):
            self._queue.put((msg, metadata), False)

        def breakiter(self, exc=None):
            self._broken = True
            self._exception = exc
            self._queue.put(None, True, 1.0)

        def __next__(self):
            if self._broken and self._queue.empty():
                raise StopIteration
            m = self._queue.get(True)
            if self._broken and m is None:
                if self._exception is not None:
                    raise self._exception
                raise StopIteration
            return m
