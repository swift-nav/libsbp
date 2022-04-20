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
package com.swiftnav.sbp.observation;

// This file was auto-generated from yaml/swiftnav/sbp/observation.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.gnss.*;
import org.json.JSONArray;
import org.json.JSONObject;

/**
 * SBP class for message MSG_EPHEMERIS_GLO (0x008B).
 *
 * <p>You can have MSG_EPHEMERIS_GLO inherent its fields directly from an inherited SBP object, or
 * construct it inline using a dict of its fields.
 *
 * <p>The ephemeris message returns a set of satellite orbit parameters that is used to calculate
 * GLO satellite position, velocity, and clock offset. Please see the GLO ICD 5.1 "Table 4.5
 * Characteristics of words of immediate information (ephemeris parameters)" for more details.
 */
public class MsgEphemerisGlo extends SBPMessage {
    public static final int TYPE = 0x008B;

    /** Values common for all ephemeris types */
    public EphemerisCommonContent common;

    /** Relative deviation of predicted carrier frequency from nominal */
    public float gamma;

    /** Correction to the SV time */
    public float tau;

    /** Equipment delay between L1 and L2 */
    public float d_tau;

    /** Position of the SV at tb in PZ-90.02 coordinates system */
    public double[] pos;

    /** Velocity vector of the SV at tb in PZ-90.02 coordinates system */
    public double[] vel;

    /** Acceleration vector of the SV at tb in PZ-90.02 coordinates sys */
    public float[] acc;

    /** Frequency slot. FCN+8 (that is [1..14]). 0 or 0xFF for invalid */
    public int fcn;

    /** Issue of data. Equal to the 7 bits of the immediate data word t_b */
    public int iod;

    public MsgEphemerisGlo(int sender) {
        super(sender, TYPE);
    }

    public MsgEphemerisGlo() {
        super(TYPE);
    }

    public MsgEphemerisGlo(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type == TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        common = new EphemerisCommonContent().parse(parser);
        gamma = parser.getFloat();
        tau = parser.getFloat();
        d_tau = parser.getFloat();
        pos = parser.getArrayofDouble(3);
        vel = parser.getArrayofDouble(3);
        acc = parser.getArrayofFloat(3);
        fcn = parser.getU8();
        iod = parser.getU8();
    }

    @Override
    protected void build(Builder builder) {
        common.build(builder);
        builder.putFloat(gamma);
        builder.putFloat(tau);
        builder.putFloat(d_tau);
        builder.putArrayofDouble(pos, 3);
        builder.putArrayofDouble(vel, 3);
        builder.putArrayofFloat(acc, 3);
        builder.putU8(fcn);
        builder.putU8(iod);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("common", common.toJSON());
        obj.put("gamma", gamma);
        obj.put("tau", tau);
        obj.put("d_tau", d_tau);
        obj.put("pos", new JSONArray(pos));
        obj.put("vel", new JSONArray(vel));
        obj.put("acc", new JSONArray(acc));
        obj.put("fcn", fcn);
        obj.put("iod", iod);
        return obj;
    }
}
