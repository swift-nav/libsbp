/* Copyright (C) 2015-2022 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
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
import java.util.Iterator;
import java.util.NoSuchElementException;

abstract class SBPIterable implements Iterable<SBPMessage>, Iterator<SBPMessage> {

    @Override
    public Iterator<SBPMessage> iterator() {
        return this;
    }

    private SBPMessage next_msg;

    protected abstract SBPMessage getNext();

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
