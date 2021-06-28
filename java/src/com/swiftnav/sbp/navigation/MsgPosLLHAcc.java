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
 * SBP class for message MSG_POS_LLH_ACC (0x0218).
 *
 * <p>You can have MSG_POS_LLH_ACC inherent its fields directly from an inherited SBP object, or
 * construct it inline using a dict of its fields.
 *
 * <p>This position solution message reports the absolute geodetic coordinates and the status
 * (single point vs pseudo-absolute RTK) of the position solution as well as the estimated
 * horizontal, vertical, cross-track and along-track errors. The estimated errors are reported at a
 * user-configurable confidence level. The user-configured percentile is encoded in the percentile
 * field. The position information and Fix Mode flags should follow the MSG_POS_LLH message. Since
 * the covariance matrix is computed in the local-level North, East, Down frame, the estimated error
 * terms follow with that convention.
 */
public class MsgPosLLHAcc extends SBPMessage {
    public static final int TYPE = 0x0218;

    /** GPS Time of Week */
    public long tow;

    /** Latitude */
    public double lat;

    /** Longitude */
    public double lon;

    /** Height above WGS84 ellipsoid */
    public double height;

    /** Estimated horizontal error at the user-configured confidence level; zero implies invalid. */
    public float horizontal_accuracy;

    /** Estimated vertical error at the user-configured confidence level; zero implies invalid. */
    public float vertical_accuracy;

    /**
     * Estimated cross-track error at the user-configured confidence level; zero implies invalid.
     */
    public float crosstrack_accuracy;

    /**
     * Estimated along-track error at the user-configured confidence level; zero implies invalid.
     */
    public float alongtrack_accuracy;

    /**
     * The semi major axis of the horizontal error ellipse at the user- configured confidence level;
     * zero implies invalid.
     */
    public float hor_ell_semi_major;

    /**
     * The semi minor axis of the horizontal error ellipse at the user- configured confidence level;
     * zero implies invalid.
     */
    public float hor_ell_semi_minor;

    /** The orientation of semi major axis of the horizontal error ellipse with respect to North. */
    public float hor_ell_orientation;

    /** Configured percentile for the estimated position error */
    public int percentile;

    /** Number of satellites used in solution. */
    public int n_sats;

    /** Status flags */
    public int flags;

    public MsgPosLLHAcc(int sender) {
        super(sender, TYPE);
    }

    public MsgPosLLHAcc() {
        super(TYPE);
    }

    public MsgPosLLHAcc(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type == TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        tow = parser.getU32();
        lat = parser.getDouble();
        lon = parser.getDouble();
        height = parser.getDouble();
        horizontal_accuracy = parser.getFloat();
        vertical_accuracy = parser.getFloat();
        crosstrack_accuracy = parser.getFloat();
        alongtrack_accuracy = parser.getFloat();
        hor_ell_semi_major = parser.getFloat();
        hor_ell_semi_minor = parser.getFloat();
        hor_ell_orientation = parser.getFloat();
        percentile = parser.getU8();
        n_sats = parser.getU8();
        flags = parser.getU8();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU32(tow);
        builder.putDouble(lat);
        builder.putDouble(lon);
        builder.putDouble(height);
        builder.putFloat(horizontal_accuracy);
        builder.putFloat(vertical_accuracy);
        builder.putFloat(crosstrack_accuracy);
        builder.putFloat(alongtrack_accuracy);
        builder.putFloat(hor_ell_semi_major);
        builder.putFloat(hor_ell_semi_minor);
        builder.putFloat(hor_ell_orientation);
        builder.putU8(percentile);
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
        obj.put("horizontal_accuracy", horizontal_accuracy);
        obj.put("vertical_accuracy", vertical_accuracy);
        obj.put("crosstrack_accuracy", crosstrack_accuracy);
        obj.put("alongtrack_accuracy", alongtrack_accuracy);
        obj.put("hor_ell_semi_major", hor_ell_semi_major);
        obj.put("hor_ell_semi_minor", hor_ell_semi_minor);
        obj.put("hor_ell_orientation", hor_ell_orientation);
        obj.put("percentile", percentile);
        obj.put("n_sats", n_sats);
        obj.put("flags", flags);
        return obj;
    }
}
