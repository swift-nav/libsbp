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
 * horizontal, vertical, cross-track and along-track errors. The position information and Fix Mode
 * flags follow the MSG_POS_LLH message. Since the covariance matrix is computed in the local-level
 * North, East, Down frame, the estimated error terms follow that convention.
 *
 * <p>The estimated errors are reported at a user-configurable confidence level. The user-configured
 * percentile is encoded in the percentile field.
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

    /**
     * Height above the geoid (i.e. height above mean sea level). See confidence_and_geoid for geoid
     * model used.
     */
    public double orthometric_height;

    /** Estimated horizontal error at the user-configured confidence level; zero implies invalid. */
    public float h_accuracy;

    /** Estimated vertical error at the user-configured confidence level; zero implies invalid. */
    public float v_accuracy;

    /**
     * Estimated cross-track error at the user-configured confidence level; zero implies invalid.
     */
    public float ct_accuracy;

    /**
     * Estimated along-track error at the user-configured confidence level; zero implies invalid.
     */
    public float at_accuracy;

    /** The estimated horizontal error ellipse at the user-configured confidence level. */
    public EstimatedHorizontalErrorEllipse h_ellipse;

    /**
     * The lower bits describe the configured confidence level for the estimated position error. The
     * middle bits describe the geoid model used to calculate the orthometric height.
     */
    public int confidence_and_geoid;

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
        orthometric_height = parser.getDouble();
        h_accuracy = parser.getFloat();
        v_accuracy = parser.getFloat();
        ct_accuracy = parser.getFloat();
        at_accuracy = parser.getFloat();
        h_ellipse = new EstimatedHorizontalErrorEllipse().parse(parser);
        confidence_and_geoid = parser.getU8();
        n_sats = parser.getU8();
        flags = parser.getU8();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU32(tow);
        builder.putDouble(lat);
        builder.putDouble(lon);
        builder.putDouble(height);
        builder.putDouble(orthometric_height);
        builder.putFloat(h_accuracy);
        builder.putFloat(v_accuracy);
        builder.putFloat(ct_accuracy);
        builder.putFloat(at_accuracy);
        h_ellipse.build(builder);
        builder.putU8(confidence_and_geoid);
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
        obj.put("orthometric_height", orthometric_height);
        obj.put("h_accuracy", h_accuracy);
        obj.put("v_accuracy", v_accuracy);
        obj.put("ct_accuracy", ct_accuracy);
        obj.put("at_accuracy", at_accuracy);
        obj.put("h_ellipse", h_ellipse.toJSON());
        obj.put("confidence_and_geoid", confidence_and_geoid);
        obj.put("n_sats", n_sats);
        obj.put("flags", flags);
        return obj;
    }
}
