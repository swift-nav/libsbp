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


/** SBP class for message MSG_ALMANAC_GPS_DEP (0x0070).
 *
 * You can have MSG_ALMANAC_GPS_DEP inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
 * The almanac message returns a set of satellite orbit parameters. Almanac
 * data is not very precise and is considered valid for up to several months.
 * Please see the Navstar GPS Space Segment/Navigation user interfaces
 * (ICD-GPS-200, Chapter 20.3.3.5.1.2 Almanac Data) for more details. */

public class MsgAlmanacGPSDep extends SBPMessage {
    public static final int TYPE = 0x0070;

    
    /** Values common for all almanac types */
    public AlmanacCommonContentDep common;
    
    /** Mean anomaly at reference time */
    public double m0;
    
    /** Eccentricity of satellite orbit */
    public double ecc;
    
    /** Square root of the semi-major axis of orbit */
    public double sqrta;
    
    /** Longitude of ascending node of orbit plane at weekly epoch */
    public double omega0;
    
    /** Rate of right ascension */
    public double omegadot;
    
    /** Argument of perigee */
    public double w;
    
    /** Inclination */
    public double inc;
    
    /** Polynomial clock correction coefficient (clock bias) */
    public double af0;
    
    /** Polynomial clock correction coefficient (clock drift) */
    public double af1;
    

    public MsgAlmanacGPSDep (int sender) { super(sender, TYPE); }
    public MsgAlmanacGPSDep () { super(TYPE); }
    public MsgAlmanacGPSDep (SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type != TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        common = new AlmanacCommonContentDep().parse(parser);
        m0 = parser.getDouble();
        ecc = parser.getDouble();
        sqrta = parser.getDouble();
        omega0 = parser.getDouble();
        omegadot = parser.getDouble();
        w = parser.getDouble();
        inc = parser.getDouble();
        af0 = parser.getDouble();
        af1 = parser.getDouble();
    }

    @Override
    protected void build(Builder builder) {
        common.build(builder);
        builder.putDouble(m0);
        builder.putDouble(ecc);
        builder.putDouble(sqrta);
        builder.putDouble(omega0);
        builder.putDouble(omegadot);
        builder.putDouble(w);
        builder.putDouble(inc);
        builder.putDouble(af0);
        builder.putDouble(af1);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("common", common.toJSON());
        obj.put("m0", m0);
        obj.put("ecc", ecc);
        obj.put("sqrta", sqrta);
        obj.put("omega0", omega0);
        obj.put("omegadot", omegadot);
        obj.put("w", w);
        obj.put("inc", inc);
        obj.put("af0", af0);
        obj.put("af1", af1);
        return obj;
    }
}