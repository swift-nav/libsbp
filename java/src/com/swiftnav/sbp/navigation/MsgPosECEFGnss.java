/* Copyright (C) 2015-2021 Swift Navigation Inc.
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
 * SBP class for message MSG_POS_ECEF_GNSS (0x0229).
 *
 * <p>You can have MSG_POS_ECEF_GNSS inherent its fields directly from an inherited SBP object, or
 * construct it inline using a dict of its fields.
 *
 * <p>The position solution message reports absolute Earth Centered Earth Fixed (ECEF) coordinates
 * and the status (single point vs pseudo-absolute RTK) of the position solution. If the rover
 * receiver knows the surveyed position of the base station and has an RTK solution, this reports a
 * pseudo-absolute position solution using the base station position and the rover's RTK baseline
 * vector. The full GPS time is given by the preceding MSG_GPS_TIME with the matching time-of-week
 * (tow).
 */
public class MsgPosECEFGnss extends SBPMessage {
    public static final int TYPE = 0x0229;

    /** GPS Time of Week */
    public long tow;

    /** ECEF X coordinate */
    public double x;

    /** ECEF Y coordinate */
    public double y;

    /** ECEF Z coordinate */
    public double z;

    /** Position estimated standard deviation */
    public int accuracy;

    /** Number of satellites used in solution */
    public int n_sats;

    /** Status flags */
    public int flags;

    public MsgPosECEFGnss(int sender) {
        super(sender, TYPE);
    }

    public MsgPosECEFGnss() {
        super(TYPE);
    }

    public MsgPosECEFGnss(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type == TYPE;
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
}
