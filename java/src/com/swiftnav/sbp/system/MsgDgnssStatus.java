/*
 * Copyright (C) 2015-2018 Swift Navigation Inc.
 * Contact: Swift Navigation <dev@swiftnav.com>
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

package com.swiftnav.sbp.system;

import java.math.BigInteger;

import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPStruct;

import org.json.JSONObject;
import org.json.JSONArray;


/** SBP class for message MSG_DGNSS_STATUS (0xFF02).
 *
 * You can have MSG_DGNSS_STATUS inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
 * This message provides information about the receipt of Differential
 * corrections.  It is expected to be sent with each receipt of a complete
 * corrections packet. */

public class MsgDgnssStatus extends SBPMessage {
    public static final int TYPE = 0xFF02;

    
    /** Status flags */
    public int flags;
    
    /** Latency of observation receipt */
    public int latency;
    
    /** Number of signals from base station */
    public int num_signals;
    
    /** Corrections source string */
    public String source;
    

    public MsgDgnssStatus (int sender) { super(sender, TYPE); }
    public MsgDgnssStatus () { super(TYPE); }
    public MsgDgnssStatus (SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type != TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        flags = parser.getU8();
        latency = parser.getU16();
        num_signals = parser.getU8();
        source = parser.getString();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU8(flags);
        builder.putU16(latency);
        builder.putU8(num_signals);
        builder.putString(source);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("flags", flags);
        obj.put("latency", latency);
        obj.put("num_signals", num_signals);
        obj.put("source", source);
        return obj;
    }
}