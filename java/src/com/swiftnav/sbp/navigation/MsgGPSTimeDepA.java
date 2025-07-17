/*
 * Copyright (C) 2015-2022 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

package com.swiftnav.sbp.navigation;

// This file was auto-generated from yaml/swiftnav/sbp/navigation.yaml by generate.py.
// Do not modify by hand!

import java.math.BigInteger;

import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPStruct;

import org.json.JSONObject;
import org.json.JSONArray;


/** SBP class for message MSG_GPS_TIME_DEP_A (0x0100).
 *
 * You can have MSG_GPS_TIME_DEP_A inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
 * Deprecated. */

public class MsgGPSTimeDepA extends SBPMessage {
    public static final int TYPE = 0x0100;

    
    /** GPS week number */
    public int wn;
    
    /** GPS time of week rounded to the nearest millisecond */
    public long tow;
    
    /** Nanosecond residual of millisecond-rounded TOW (ranges from -500000 to
      * 500000) */
    public int ns_residual;
    
    /** Status flags (reserved) */
    public int flags;
    

    public MsgGPSTimeDepA (int sender) { super(sender, TYPE); }
    public MsgGPSTimeDepA () { super(TYPE); }
    public MsgGPSTimeDepA (SBPMessage msg) throws SBPBinaryException {
        super(msg);
        if (msg.type != TYPE)
            throw new SBPBinaryException("Type mismatch for MsgGPSTimeDepA, expected 256, actual " + msg.type);
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        wn = parser.getU16();
        tow = parser.getU32();
        ns_residual = parser.getS32();
        flags = parser.getU8(); 
    }

    @Override
    protected void build(Builder builder) {
        builder.putU16(wn);
        builder.putU32(tow);
        builder.putS32(ns_residual);
        builder.putU8(flags); 
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("wn", wn);
        obj.put("tow", tow);
        obj.put("ns_residual", ns_residual);
        obj.put("flags", flags);
        return obj;
    }

    @Override
    public String getFriendlyName() {
        return "GPS TIME DEP A";
    }
}
