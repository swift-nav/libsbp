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
 * SBP class for message MSG_POS_LLH_GNSS (0x022A).
 *
 * <p>You can have MSG_POS_LLH_GNSS inherent its fields directly from an inherited SBP object, or
 * construct it inline using a dict of its fields.
 *
 * <p>This position solution message reports the absolute geodetic coordinates and the status
 * (single point vs pseudo-absolute RTK) of the position solution. If the rover receiver knows the
 * surveyed position of the base station and has an RTK solution, this reports a pseudo-absolute
 * position solution using the base station position and the rover's RTK baseline vector. The full
 * GPS time is given by the preceding MSG_GPS_TIME_GNSS with the matching time-of-week (tow).
 *
 * <p>This values in this message are from GNSS measurements only. To get values fused with inertial
 * measurements use MSG_POS_LLH.
 */
public class MsgPosLLHGnss extends SBPMessage {
    public static final int TYPE = 0x022A;

    /** GPS Time of Week */
    public long tow;

    /** Latitude */
    public double lat;

    /** Longitude */
    public double lon;

    /** Height above WGS84 ellipsoid */
    public double height;

    /** Horizontal position estimated standard deviation */
    public int h_accuracy;

    /** Vertical position estimated standard deviation */
    public int v_accuracy;

    /** Number of satellites used in solution. */
    public int n_sats;

    /** Status flags */
    public int flags;

    public MsgPosLLHGnss(int sender) {
        super(sender, TYPE);
    }

    public MsgPosLLHGnss() {
        super(TYPE);
    }

    public MsgPosLLHGnss(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        if (msg.type != TYPE)
            throw new SBPBinaryException(
                    "Type mismatch for MsgPosLLHGnss, expected 554, actual " + msg.type);
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        tow = parser.getU32();
        lat = parser.getDouble();
        lon = parser.getDouble();
        height = parser.getDouble();
        h_accuracy = parser.getU16();
        v_accuracy = parser.getU16();
        n_sats = parser.getU8();
        flags = parser.getU8();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU32(tow);
        builder.putDouble(lat);
        builder.putDouble(lon);
        builder.putDouble(height);
        builder.putU16(h_accuracy);
        builder.putU16(v_accuracy);
        builder.putU8(n_sats);
        builder.putU8(flags);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("tow", tow);
        obj.put("lat", lat);
        obj.put("lon", lon);
        obj.put("height", height);
        obj.put("h_accuracy", h_accuracy);
        obj.put("v_accuracy", v_accuracy);
        obj.put("n_sats", n_sats);
        obj.put("flags", flags);
        return obj;
    }

    @Override
    public String getFriendlyName() {
        return "POS LLH GNSS-only";
    }
}
