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

package com.swiftnav.sbp.navigation;

import java.math.BigInteger;

import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPStruct;

import org.json.JSONObject;
import org.json.JSONArray;


/** SBP class for message MSG_VEL_NED_COV (0x0212).
 *
 * You can have MSG_VEL_NED_COV inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
 * This message reports the velocity in local North East Down (NED)
 * coordinates. The NED coordinate system is defined as the local WGS84
 * tangent plane centered at the current position. The full GPS time is
 * given by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
 * This message is similar to the MSG_VEL_NED, but it includes the upper triangular
 * portion of the 3x3 covariance matrix. */

public class MsgVelNEDCov extends SBPMessage {
    public static final int TYPE = 0x0212;

    
    /** GPS Time of Week */
    public long tow;
    
    /** Velocity North coordinate */
    public int n;
    
    /** Velocity East coordinate */
    public int e;
    
    /** Velocity Down coordinate */
    public int d;
    
    /** Estimated variance of northward measurement */
    public float cov_n_n;
    
    /** Covariance of northward and eastward measurement */
    public float cov_n_e;
    
    /** Covariance of northward and downward measurement */
    public float cov_n_d;
    
    /** Estimated variance of eastward measurement */
    public float cov_e_e;
    
    /** Covariance of eastward and downward measurement */
    public float cov_e_d;
    
    /** Estimated variance of downward measurement */
    public float cov_d_d;
    
    /** Number of satellites used in solution */
    public int n_sats;
    
    /** Status flags */
    public int flags;
    

    public MsgVelNEDCov (int sender) { super(sender, TYPE); }
    public MsgVelNEDCov () { super(TYPE); }
    public MsgVelNEDCov (SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type != TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        tow = parser.getU32();
        n = parser.getS32();
        e = parser.getS32();
        d = parser.getS32();
        cov_n_n = parser.getFloat();
        cov_n_e = parser.getFloat();
        cov_n_d = parser.getFloat();
        cov_e_e = parser.getFloat();
        cov_e_d = parser.getFloat();
        cov_d_d = parser.getFloat();
        n_sats = parser.getU8();
        flags = parser.getU8();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU32(tow);
        builder.putS32(n);
        builder.putS32(e);
        builder.putS32(d);
        builder.putFloat(cov_n_n);
        builder.putFloat(cov_n_e);
        builder.putFloat(cov_n_d);
        builder.putFloat(cov_e_e);
        builder.putFloat(cov_e_d);
        builder.putFloat(cov_d_d);
        builder.putU8(n_sats);
        builder.putU8(flags);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("tow", tow);
        obj.put("n", n);
        obj.put("e", e);
        obj.put("d", d);
        obj.put("cov_n_n", cov_n_n);
        obj.put("cov_n_e", cov_n_e);
        obj.put("cov_n_d", cov_n_d);
        obj.put("cov_e_e", cov_e_e);
        obj.put("cov_e_d", cov_e_d);
        obj.put("cov_d_d", cov_d_d);
        obj.put("n_sats", n_sats);
        obj.put("flags", flags);
        return obj;
    }
}