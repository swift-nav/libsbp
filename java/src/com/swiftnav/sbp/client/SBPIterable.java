package com.swiftnav.sbp.client;

import com.swiftnav.sbp.SBPMessage;

import java.util.Iterator;
import java.util.NoSuchElementException;

abstract class SBPIterable
        implements Iterable<SBPMessage>, Iterator<SBPMessage> {

    @Override
    public Iterator<SBPMessage> iterator() {
        return this;
    }

    private SBPMessage next_msg;

    abstract protected SBPMessage getNext();

    @Override
    public boolean hasNext() {
        while (next_msg == null) {
            try {
                next_msg = getNext();
            } catch (NoSuchElementException e) {
                return false;
            }
        }
        return true;
    }

    @Override
    public SBPMessage next() {
        while (next_msg == null) {
            next_msg = getNext();
        }
        SBPMessage ret = next_msg;
        next_msg = null;
        return ret;
    }

    @Override
    public void remove() {
        throw new UnsupportedOperationException();
    }
}
