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
package com.swiftnav.sbp.navigation;

// This file was auto-generated from yaml/swiftnav/sbp/navigation.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import org.json.JSONObject;

/**
 * SBP class for message MSG_VEL_NED_GNSS (0x022E).
 *
 * <p>You can have MSG_VEL_NED_GNSS inherent its fields directly from an inherited SBP object, or
 * construct it inline using a dict of its fields.
 *
 * <p>This message reports the velocity in local North East Down (NED) coordinates. The NED
 * coordinate system is defined as the local WGS84 tangent plane centered at the current position.
 * The full GPS time is given by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
 */
public class MsgVelNEDGnss extends SBPMessage {
    public static final int TYPE = 0x022E;

    /** GPS Time of Week */
    public long tow;

    /** Velocity North coordinate */
    public int n;

    /** Velocity East coordinate */
    public int e;

    /** Velocity Down coordinate */
    public int d;

    /** Horizontal velocity estimated standard deviation */
    public int h_accuracy;

    /** Vertical velocity estimated standard deviation */
    public int v_accuracy;

    /** Number of satellites used in solution */
    public int n_sats;

    /** Status flags */
    public int flags;

    public MsgVelNEDGnss(int sender) {
        super(sender, TYPE);
    }

    public MsgVelNEDGnss() {
        super(TYPE);
    }

    public MsgVelNEDGnss(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type == TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        tow = parser.getU32();
        n = parser.getS32();
        e = parser.getS32();
        d = parser.getS32();
        h_accuracy = parser.getU16();
        v_accuracy = parser.getU16();
        n_sats = parser.getU8();
        flags = parser.getU8();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU32(tow);
        builder.putS32(n);
        builder.putS32(e);
        builder.putS32(d);
        builder.putU16(h_accuracy);
        builder.putU16(v_accuracy);
        builder.putU8(n_sats);
        builder.putU8(flags);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("tow", tow);
        obj.put("n", n);
        obj.put("e", e);
        obj.put("d", d);
        obj.put("h_accuracy", h_accuracy);
        obj.put("v_accuracy", v_accuracy);
        obj.put("n_sats", n_sats);
        obj.put("flags", flags);
        return obj;
    }
}
