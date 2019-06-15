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



public class MsgEphemerisSbas extends SBPMessage {
    public static final int TYPE = 0x008C;

    
    /** Values common for all ephemeris types */
    public EphemerisCommonContent common;
    
    /** Position of the GEO at time toe */
    public double[] pos;
    
    /** Velocity of the GEO at time toe */
    public float[] vel;
    
    /** Acceleration of the GEO at time toe */
    public float[] acc;
    
    /** Time offset of the GEO clock w.r.t. SBAS Network Time */
    public float a_gf0;
    
    /** Drift of the GEO clock w.r.t. SBAS Network Time */
    public float a_gf1;
    

    public MsgEphemerisSbas (int sender) { super(sender, TYPE); }
    public MsgEphemerisSbas () { super(TYPE); }
    public MsgEphemerisSbas (SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type != TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        common = new EphemerisCommonContent().parse(parser);
        pos = parser.getArrayofDouble(3);
        vel = parser.getArrayofFloat(3);
        acc = parser.getArrayofFloat(3);
        a_gf0 = parser.getFloat();
        a_gf1 = parser.getFloat();
    }

    @Override
    protected void build(Builder builder) {
        common.build(builder);
        builder.putArrayofDouble(pos, 3);
        builder.putArrayofFloat(vel, 3);
        builder.putArrayofFloat(acc, 3);
        builder.putFloat(a_gf0);
        builder.putFloat(a_gf1);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("common", common.toJSON());
        obj.put("pos", new JSONArray(pos));
        obj.put("vel", new JSONArray(vel));
        obj.put("acc", new JSONArray(acc));
        obj.put("a_gf0", a_gf0);
        obj.put("a_gf1", a_gf1);
        return obj;
    }
}