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
 * SBP class for message MSG_VEL_ECEF_GNSS (0x022D).
 *
 * <p>You can have MSG_VEL_ECEF_GNSS inherent its fields directly from an inherited SBP object, or
 * construct it inline using a dict of its fields.
 *
 * <p>This message reports the velocity in Earth Centered Earth Fixed (ECEF) coordinates. The full
 * GPS time is given by the preceding MSG_GPS_TIME_GNSS with the matching time-of-week (tow).
 *
 * <p>The values in this message are from GNSS measurements only. To get values fused with inertial
 * measurements use MSG_VEL_ECEF.
 */
public class MsgVelECEFGnss extends SBPMessage {
    public static final int TYPE = 0x022D;

    /** GPS Time of Week */
    public long tow;

    /** Velocity ECEF X coordinate */
    public int x;

    /** Velocity ECEF Y coordinate */
    public int y;

    /** Velocity ECEF Z coordinate */
    public int z;

    /** Velocity estimated standard deviation */
    public int accuracy;

    /** Number of satellites used in solution */
    public int n_sats;

    /** Status flags */
    public int flags;

    public MsgVelECEFGnss(int sender) {
        super(sender, TYPE);
    }

    public MsgVelECEFGnss() {
        super(TYPE);
    }

    public MsgVelECEFGnss(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        if (msg.type != TYPE)
            throw new SBPBinaryException(
                    "Type mismatch for MsgVelECEFGnss, expected 557, actual " + msg.type);
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        tow = parser.getU32();
        x = parser.getS32();
        y = parser.getS32();
        z = parser.getS32();
        accuracy = parser.getU16();
        n_sats = parser.getU8();
        flags = parser.getU8();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU32(tow);
        builder.putS32(x);
        builder.putS32(y);
        builder.putS32(z);
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
        return "VEL ECEF GNSS-only";
    }
}
