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
package com.swiftnav.sbp.observation;

// This file was auto-generated from yaml/swiftnav/sbp/observation.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.gnss.*;
import org.json.JSONArray;
import org.json.JSONObject;

/**
 * SBP class for message MSG_EPHEMERIS_GLO_DEP_D (0x0088).
 *
 * <p>You can have MSG_EPHEMERIS_GLO_DEP_D inherent its fields directly from an inherited SBP
 * object, or construct it inline using a dict of its fields.
 *
 * <p>This observation message has been deprecated in favor of ephemeris message using floats for
 * size reduction.
 */
public class MsgEphemerisGloDepD extends SBPMessage {
    public static final int TYPE = 0x0088;

    /** Values common for all ephemeris types */
    public EphemerisCommonContentDepB common;

    /** Relative deviation of predicted carrier frequency from nominal */
    public double gamma;

    /** Correction to the SV time */
    public double tau;

    /** Equipment delay between L1 and L2 */
    public double d_tau;

    /** Position of the SV at tb in PZ-90.02 coordinates system */
    public double[] pos;

    /** Velocity vector of the SV at tb in PZ-90.02 coordinates system */
    public double[] vel;

    /** Acceleration vector of the SV at tb in PZ-90.02 coordinates sys */
    public double[] acc;

    /** Frequency slot. FCN+8 (that is [1..14]). 0 or 0xFF for invalid */
    public int fcn;

    /** Issue of data. Equal to the 7 bits of the immediate data word t_b */
    public int iod;

    public MsgEphemerisGloDepD(int sender) {
        super(sender, TYPE);
    }

    public MsgEphemerisGloDepD() {
        super(TYPE);
    }

    public MsgEphemerisGloDepD(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type == TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        common = new EphemerisCommonContentDepB().parse(parser);
        gamma = parser.getDouble();
        tau = parser.getDouble();
        d_tau = parser.getDouble();
        pos = parser.getArrayofDouble(3);
        vel = parser.getArrayofDouble(3);
        acc = parser.getArrayofDouble(3);
        fcn = parser.getU8();
        iod = parser.getU8();
    }

    @Override
    protected void build(Builder builder) {
        common.build(builder);
        builder.putDouble(gamma);
        builder.putDouble(tau);
        builder.putDouble(d_tau);
        builder.putArrayofDouble(pos, 3);
        builder.putArrayofDouble(vel, 3);
        builder.putArrayofDouble(acc, 3);
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
