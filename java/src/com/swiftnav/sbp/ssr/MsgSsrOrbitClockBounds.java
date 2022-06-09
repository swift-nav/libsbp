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
package com.swiftnav.sbp.ssr;

// This file was auto-generated from yaml/swiftnav/sbp/ssr.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.gnss.*;
import org.json.JSONArray;
import org.json.JSONObject;

/**
 * SBP class for message MSG_SSR_ORBIT_CLOCK_BOUNDS (0x05DE).
 *
 * <p>You can have MSG_SSR_ORBIT_CLOCK_BOUNDS inherent its fields directly from an inherited SBP
 * object, or construct it inline using a dict of its fields.
 *
 * <p>Note 1: Range: 0-17.5 m. i<=200, mean=0.01i; 200<i<=230, mean=2+0.1(i-200); i>230,
 * mean=5+0.5(i-230).
 *
 * <p>Note 2: Range: 0-17.5 m. i<=200, std=0.01i; 200<i<=230, std=2+0.1(i-200) i>230,
 * std=5+0.5(i-230).
 */
public class MsgSsrOrbitClockBounds extends SBPMessage {
    public static final int TYPE = 0x05DE;

    public int[] stub;

    public MsgSsrOrbitClockBounds(int sender) {
        super(sender, TYPE);
    }

    public MsgSsrOrbitClockBounds() {
        super(TYPE);
    }

    public MsgSsrOrbitClockBounds(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type == TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        stub = parser.getArrayofU8();
    }

    @Override
    protected void build(Builder builder) {
        builder.putArrayofU8(stub);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("stub", new JSONArray(stub));
        return obj;
    }
}
