/*
 * Copyright (C) 2015-2018 Swift Navigation Inc.
 * Contact: Swift Navigation <dev@swiftnav.com>
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

package com.swiftnav.sbp.observation;

import java.math.BigInteger;

import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPStruct;
import com.swiftnav.sbp.gnss.*;

import org.json.JSONObject;
import org.json.JSONArray;


/** SBP class for message MSG_EPHEMERIS_GLO_DEP_D (0x0088).
 *
 * You can have MSG_EPHEMERIS_GLO_DEP_D inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
 * This observation message has been deprecated in favor of
 * ephemeris message using floats for size reduction. */

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
    
    /** Issue of ephemeris data */
    public int iod;
    

    public MsgEphemerisGloDepD (int sender) { super(sender, TYPE); }
    public MsgEphemerisGloDepD () { super(TYPE); }
    public MsgEphemerisGloDepD (SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type != TYPE;
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