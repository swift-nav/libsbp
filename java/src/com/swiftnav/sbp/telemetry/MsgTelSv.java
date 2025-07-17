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

package com.swiftnav.sbp.telemetry;

// This file was auto-generated from yaml/swiftnav/sbp/telemetry.yaml by generate.py.
// Do not modify by hand!

import java.math.BigInteger;

import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPStruct;
import com.swiftnav.sbp.gnss.*;

import org.json.JSONObject;
import org.json.JSONArray;


/** SBP class for message MSG_TEL_SV (0x0120).
 *
 * You can have MSG_TEL_SV inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
 * This message includes telemetry pertinent to satellite signals available to
 * Starling. */

public class MsgTelSv extends SBPMessage {
    public static final int TYPE = 0x0120;

    
    /** GPS week number */
    public int wn;
    
    /** GPS Time of Week */
    public long tow;
    
    /** Total number of observations. First nibble is the size of the sequence
      * (n), second nibble is the zero-indexed counter (ith packet of n) */
    public int n_obs;
    
    /** Flags to identify the filter type from which the telemetry is reported
      * from */
    public int origin_flags;
    
    /** Array of per-signal telemetry entries */
    public TelemetrySV[] sv_tel;
    

    public MsgTelSv (int sender) { super(sender, TYPE); }
    public MsgTelSv () { super(TYPE); }
    public MsgTelSv (SBPMessage msg) throws SBPBinaryException {
        super(msg);
        if (msg.type != TYPE)
            throw new SBPBinaryException("Type mismatch for MsgTelSv, expected 288, actual " + msg.type);
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        wn = parser.getU16();
        tow = parser.getU32();
        n_obs = parser.getU8();
        origin_flags = parser.getU8();
        sv_tel = parser.getArray(TelemetrySV.class); 
    }

    @Override
    protected void build(Builder builder) {
        builder.putU16(wn);
        builder.putU32(tow);
        builder.putU8(n_obs);
        builder.putU8(origin_flags);
        builder.putArray(sv_tel); 
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("wn", wn);
        obj.put("tow", tow);
        obj.put("n_obs", n_obs);
        obj.put("origin_flags", origin_flags);
        obj.put("sv_tel", SBPStruct.toJSONArray(sv_tel));
        return obj;
    }

    @Override
    public String getFriendlyName() {
        return "TEL SV";
    }
}
