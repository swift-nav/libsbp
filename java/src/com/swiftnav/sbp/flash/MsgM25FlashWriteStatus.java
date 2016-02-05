/*
 * Copyright (C) 2015 Swift Navigation Inc.
 * Contact: Gareth McMullin <gareth@swiftnav.com>
 * Contact: Bhaskar Mookerji <mookerji@swiftnav.com>
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

package com.swiftnav.sbp.flash;

import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPStruct;

import org.json.JSONObject;
import org.json.JSONArray;


/** SBP class for message MSG_M25_FLASH_WRITE_STATUS (0x00F3).
 *
 * You can have MSG_M25_FLASH_WRITE_STATUS inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
 * The flash status message writes to the 8-bit M25 flash status
 * register. The device replies with a MSG_FLASH_DONE message. */

public class MsgM25FlashWriteStatus extends SBPMessage {
    public static final int TYPE = 0x00F3;

    
    /** Byte to write to the M25 flash status register */
    public int[] status;
    

    public MsgM25FlashWriteStatus (int sender) { super(sender, TYPE); }
    public MsgM25FlashWriteStatus () { super(TYPE); }
    public MsgM25FlashWriteStatus (SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type != TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        status = parser.getArrayofU8(1);
    }

    @Override
    protected void build(Builder builder) {
        builder.putArrayofU8(status, 1);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("status", new JSONArray(status));
        return obj;
    }
}