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
package com.swiftnav.sbp.piksi;

// This file was auto-generated from yaml/swiftnav/sbp/piksi.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPStruct;
import com.swiftnav.sbp.gnss.*;
import org.json.JSONObject;

public class Latency extends SBPStruct {

    /** Average latency */
    public int avg;

    /** Minimum latency */
    public int lmin;

    /** Maximum latency */
    public int lmax;

    /** Smoothed estimate of the current latency */
    public int current;

    public Latency() {}

    @Override
    public Latency parse(SBPMessage.Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        avg = parser.getS32();
        lmin = parser.getS32();
        lmax = parser.getS32();
        current = parser.getS32();
        return this;
    }

    @Override
    public void build(SBPMessage.Builder builder) {
        /* Build fields into binary */
        builder.putS32(avg);
        builder.putS32(lmin);
        builder.putS32(lmax);
        builder.putS32(current);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = new JSONObject();
        obj.put("avg", avg);
        obj.put("lmin", lmin);
        obj.put("lmax", lmax);
        obj.put("current", current);
        return obj;
    }
}
