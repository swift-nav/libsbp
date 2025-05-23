/* Copyright (C) 2015-2022 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */
package com.swiftnav.sbp.gnss;

// This file was auto-generated from yaml/swiftnav/sbp/gnss.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPStruct;
import org.json.JSONObject;

public class GPSTime extends SBPStruct {

    /** Milliseconds since start of GPS week */
    public long tow;

    /** Nanosecond residual of millisecond-rounded TOW (ranges from -500000 to 500000) */
    public int ns_residual;

    /** GPS week number */
    public int wn;

    public GPSTime() {}

    @Override
    public GPSTime parse(SBPMessage.Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        tow = parser.getU32();
        ns_residual = parser.getS32();
        wn = parser.getU16();
        return this;
    }

    @Override
    public void build(SBPMessage.Builder builder) {
        /* Build fields into binary */
        builder.putU32(tow);
        builder.putS32(ns_residual);
        builder.putU16(wn);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = new JSONObject();
        obj.put("tow", tow);
        obj.put("ns_residual", ns_residual);
        obj.put("wn", wn);
        return obj;
    }
}
