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
package com.swiftnav.sbp.navigation;

// This file was auto-generated from yaml/swiftnav/sbp/navigation.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import org.json.JSONObject;

/**
 * SBP class for message MSG_POS_ECEF_DEP_A (0x0200).
 *
 * <p>You can have MSG_POS_ECEF_DEP_A inherent its fields directly from an inherited SBP object, or
 * construct it inline using a dict of its fields.
 *
 * <p>Deprecated.
 */
public class MsgPosECEFDepA extends SBPMessage {
    public static final int TYPE = 0x0200;

    /** GPS Time of Week */
    public long tow;

    /** ECEF X coordinate */
    public double x;

    /** ECEF Y coordinate */
    public double y;

    /** ECEF Z coordinate */
    public double z;

    /** Position accuracy estimate (not implemented). Defaults to 0. */
    public int accuracy;

    /** Number of satellites used in solution */
    public int n_sats;

    /** Status flags */
    public int flags;

    public MsgPosECEFDepA(int sender) {
        super(sender, TYPE);
    }

    public MsgPosECEFDepA() {
        super(TYPE);
    }

    public MsgPosECEFDepA(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        if (msg.type != TYPE)
            throw new SBPBinaryException(
                    "Type mismatch for MsgPosECEFDepA, expected 512, actual " + msg.type);
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        tow = parser.getU32();
        x = parser.getDouble();
        y = parser.getDouble();
        z = parser.getDouble();
        accuracy = parser.getU16();
        n_sats = parser.getU8();
        flags = parser.getU8();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU32(tow);
        builder.putDouble(x);
        builder.putDouble(y);
        builder.putDouble(z);
        builder.putU16(accuracy);
        builder.putU8(n_sats);
        builder.putU8(flags);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("tow", tow);
        obj.put("x", x);
        obj.put("y", y);
        obj.put("z", z);
        obj.put("accuracy", accuracy);
        obj.put("n_sats", n_sats);
        obj.put("flags", flags);
        return obj;
    }

    @Override
    public String getFriendlyName() {
        return "POS ECEF DEP A";
    }
}
