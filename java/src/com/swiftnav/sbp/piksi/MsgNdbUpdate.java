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

package com.swiftnav.sbp.piksi;

import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPStruct;
import com.swiftnav.sbp.gnss_signal.*;

import org.json.JSONObject;
import org.json.JSONArray;


/** SBP class for message MSG_NDB_UPDATE (0x0080).
 *
 * You can have MSG_NDB_UPDATE inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
 * This message from Piksi to host carries information on updated
 * data element in NDB. */

public class MsgNdbUpdate extends SBPMessage {
    public static final int TYPE = 0x0080;

    
    /** Indication of information element type */
    public long mask;
    
    /** New value of updated information element */
    public int[] data;
    

    public MsgNdbUpdate (int sender) { super(sender, TYPE); }
    public MsgNdbUpdate () { super(TYPE); }
    public MsgNdbUpdate (SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type != TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        mask = parser.getU32();
        data = parser.getArrayofU8();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU32(mask);
        builder.putArrayofU8(data);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("mask", mask);
        obj.put("data", new JSONArray(data));
        return obj;
    }
}