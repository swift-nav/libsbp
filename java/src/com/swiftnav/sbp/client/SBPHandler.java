/*
 * Copyright (C) 2015 Swift Navigation Inc.
 * Contact: Gareth McMullin <gareth@swiftnav.com>
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */
package com.swiftnav.sbp.client;

import com.swiftnav.sbp.SBPMessage;

import java.lang.ref.Reference;
import java.lang.ref.WeakReference;
import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.NoSuchElementException;
import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;
import java.util.concurrent.LinkedBlockingQueue;

/** Provide an interface for queueing and filtering messages.
 */
public class SBPHandler implements Iterable<SBPMessage> {
    private Iterable<SBPMessage> source;
    private static final int THREAD_WAIT_TIMEOUT = 1000;
    private static final int DEFAULT_QUEUE_SIZE = 0;

    private final HashMap<Integer, List<Reference<SBPCallback>>> callbacks;
    private final List<SBPCallback> strongCallbacks;
    private ReceiveThread receiveThread;

    public SBPHandler(Iterable<SBPMessage> source_) {
        source = source_;
        callbacks = new HashMap<>();
        strongCallbacks = new LinkedList<>();
    }

    public Iterable<SBPMessage> filter(int id, int queue_size) {
        return filter(new int[] {id}, queue_size);
    }

    public Iterable<SBPMessage> filter(int[] ids, int queue_size) {
        SBPQueueIterator iter = new SBPQueueIterator(queue_size);
        addCallbackMulti(ids, new WeakReference<SBPCallback>(iter));
        return iter;
    }

    @Override
    public Iterator<SBPMessage> iterator() {
        return filter(null, DEFAULT_QUEUE_SIZE).iterator();
    }

    /** Start the listener/dispatch thread */
    public void start() {
        assert(receiveThread == null);
        receiveThread = new ReceiveThread();
        receiveThread.start();
    }

    /** Request to stop the listener/dispatch thread */
    public void stop() {
        if (receiveThread == null)
            return;

        receiveThread.finish();
        try {
            receiveThread.join(THREAD_WAIT_TIMEOUT);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        receiveThread = null;
    }


    public void addCallback(Integer id, SBPCallback cb) {
        synchronized (callbacks) {
            addCallback(id, new WeakReference<>(cb));
            strongCallbacks.add(cb);
        }
    }

    /** Register a message handler for a specific message ID. */
    public void addCallback(Integer id, Reference<SBPCallback> cb) {
        synchronized (callbacks) {
            List<Reference<SBPCallback>> cblist;
            if (callbacks.containsKey(id)) {
                cblist = callbacks.get(id);
            } else {
                cblist = new LinkedList<>();
                callbacks.put(id, cblist);
            }
            cblist.add(cb);
        }
    }

    public void addCallbackMulti(int[] ids, SBPCallback cb) {
        synchronized (callbacks) {
            addCallbackMulti(ids, new WeakReference<>(cb));
            strongCallbacks.add(cb);
        }
    }

    /** Register a message handler for a list of message IDs */
    public void addCallbackMulti(int[] ids, Reference<SBPCallback> cb) {
        if (ids == null) {
            addCallback(null, cb);
            return;
        }
        for (int id : ids)
            addCallback(id, cb);
    }

    public void removeCallback(SBPCallback cb) {
        synchronized (callbacks) {
            for (List<Reference<SBPCallback>> cblist : callbacks.values()) {
                for (Reference<SBPCallback> ref : cblist) {
                    if (ref.get() == cb) {
                        cblist.remove(ref);
                    }
                }
            }
            strongCallbacks.remove(cb);
        }
    }

    private class ReceiveThread extends Thread {
        private boolean stopFlag = false;

        @Override
        public void run() {
            for (SBPMessage msg : source) {
                if (stopFlag)
                    break;

                if (msg == null)
                    continue;

                synchronized (callbacks) {
                    if (callbacks.containsKey(msg.type))
                        dispatch(msg.type, msg);
                    if (callbacks.containsKey(null))
                        dispatch(null, msg);
                }
            }
        }

        void finish() {
            stopFlag = true;
        }
    }

    private void dispatch(Integer type, SBPMessage msg) {
        List<Reference<SBPCallback>> cblist = callbacks.get(type);
        for (Reference<SBPCallback> wr : cblist) {
            SBPCallback cb = wr.get();
            if (cb != null) {
                cb.receiveCallback(msg);
            } else {
                cblist.remove(wr);
            }
        }
    }

    class SBPQueueIterator extends SBPIterable implements SBPCallback {
        private BlockingQueue<SBPMessage> queue;

        private SBPQueueIterator(int queue_size) {
            if (queue_size <= 0) {
                queue = new LinkedBlockingQueue<>();
            } else {
                queue = new ArrayBlockingQueue<>(queue_size);
            }
        }

        @Override
        public void receiveCallback(SBPMessage msg) {
            queue.add(msg);
        }

        @Override
        protected SBPMessage getNext() {
            try {
                return queue.take();
            } catch (InterruptedException e) {
                throw new NoSuchElementException();
            }
        }
    }
}
