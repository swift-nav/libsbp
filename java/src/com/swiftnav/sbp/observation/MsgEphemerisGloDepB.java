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
package com.swiftnav.sbp.observation;

// This file was auto-generated from yaml/swiftnav/sbp/observation.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.gnss.*;
import org.json.JSONArray;
import org.json.JSONObject;

/**
 * SBP class for message MSG_EPHEMERIS_GLO_DEP_B (0x0085).
 *
 * <p>You can have MSG_EPHEMERIS_GLO_DEP_B inherent its fields directly from an inherited SBP
 * object, or construct it inline using a dict of its fields.
 *
 * <p>Deprecated.
 */
public class MsgEphemerisGloDepB extends SBPMessage {
    public static final int TYPE = 0x0085;

    /** Values common for all ephemeris types */
    public EphemerisCommonContentDepB common;

    /** Relative deviation of predicted carrier frequency from nominal */
    public double gamma;

    /** Correction to the SV time */
    public double tau;

    /** Position of the SV at tb in PZ-90.02 coordinates system */
    public double[] pos;

    /** Velocity vector of the SV at tb in PZ-90.02 coordinates system */
    public double[] vel;

    /** Acceleration vector of the SV at tb in PZ-90.02 coordinates sys */
    public double[] acc;

    public MsgEphemerisGloDepB(int sender) {
        super(sender, TYPE);
    }

    public MsgEphemerisGloDepB() {
        super(TYPE);
    }

    public MsgEphemerisGloDepB(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        if (msg.type != TYPE)
            throw new SBPBinaryException(
                    "Type mismatch for MsgEphemerisGloDepB, expected 133, actual " + msg.type);
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        common = new EphemerisCommonContentDepB().parse(parser);
        gamma = parser.getDouble();
        tau = parser.getDouble();
        pos = parser.getArrayofDouble(3);
        vel = parser.getArrayofDouble(3);
        acc = parser.getArrayofDouble(3);
    }

    @Override
    protected void build(Builder builder) {
        common.build(builder);
        builder.putDouble(gamma);
        builder.putDouble(tau);
        builder.putArrayofDouble(pos, 3);
        builder.putArrayofDouble(vel, 3);
        builder.putArrayofDouble(acc, 3);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("common", common.toJSON());
        obj.put("gamma", gamma);
        obj.put("tau", tau);
        obj.put("pos", new JSONArray(pos));
        obj.put("vel", new JSONArray(vel));
        obj.put("acc", new JSONArray(acc));
        return obj;
    }

    @Override
    public String getFriendlyName() {
        return "EPH GLO DEP B";
    }
}
