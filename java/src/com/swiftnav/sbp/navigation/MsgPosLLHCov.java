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


/** SBP class for message MSG_POS_LLH_COV (0x0211).
 *
 * You can have MSG_POS_LLH_COV inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
 * This position solution message reports the absolute geodetic
 * coordinates and the status (single point vs pseudo-absolute RTK)
 * of the position solution as well as the upper triangle of the 3x3
 * covariance matrix.  The position information and Fix Mode flags should
 * follow the MSG_POS_LLH message.  Since the covariance matrix is computed
 * in the local-level North, East, Down frame, the covariance terms follow
 * with that convention. Thus, covariances are reported against the "downward"
 * measurement and care should be taken with the sign convention. */

public class MsgPosLLHCov extends SBPMessage {
    public static final int TYPE = 0x0211;

    
    /** GPS Time of Week */
    public long tow;
    
    /** Latitude */
    public double lat;
    
    /** Longitude */
    public double lon;
    
    /** Height above WGS84 ellipsoid */
    public double height;
    
    /** Estimated variance of northing */
    public float cov_n_n;
    
    /** Covariance of northing and easting */
    public float cov_n_e;
    
    /** Covariance of northing and downward measurement */
    public float cov_n_d;
    
    /** Estimated variance of easting */
    public float cov_e_e;
    
    /** Covariance of easting and downward measurement */
    public float cov_e_d;
    
    /** Estimated variance of downward measurement */
    public float cov_d_d;
    
    /** Number of satellites used in solution. */
    public int n_sats;
    
    /** Status flags */
    public int flags;
    

    public MsgPosLLHCov (int sender) { super(sender, TYPE); }
    public MsgPosLLHCov () { super(TYPE); }
    public MsgPosLLHCov (SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type != TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        tow = parser.getU32();
        lat = parser.getDouble();
        lon = parser.getDouble();
        height = parser.getDouble();
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
        builder.putDouble(lat);
        builder.putDouble(lon);
        builder.putDouble(height);
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
        obj.put("lat", lat);
        obj.put("lon", lon);
        obj.put("height", height);
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