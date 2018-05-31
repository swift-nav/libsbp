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


/** SBP class for message MSG_EPHEMERIS_GPS_DEP_F (0x0086).
 *
 * You can have MSG_EPHEMERIS_GPS_DEP_F inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
 * This observation message has been deprecated in favor of
 * ephemeris message using floats for size reduction. */

public class MsgEphemerisGPSDepF extends SBPMessage {
    public static final int TYPE = 0x0086;

    
    /** Values common for all ephemeris types */
    public EphemerisCommonContentDepB common;
    
    /** Group delay differential between L1 and L2 */
    public double tgd;
    
    /** Amplitude of the sine harmonic correction term to the orbit radius */
    public double c_rs;
    
    /** Amplitude of the cosine harmonic correction term to the orbit radius */
    public double c_rc;
    
    /** Amplitude of the cosine harmonic correction term to the argument of latitude */
    public double c_uc;
    
    /** Amplitude of the sine harmonic correction term to the argument of latitude */
    public double c_us;
    
    /** Amplitude of the cosine harmonic correction term to the angle of inclination */
    public double c_ic;
    
    /** Amplitude of the sine harmonic correction term to the angle of inclination */
    public double c_is;
    
    /** Mean motion difference */
    public double dn;
    
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
    
    /** Inclination first derivative */
    public double inc_dot;
    
    /** Polynomial clock correction coefficient (clock bias) */
    public double af0;
    
    /** Polynomial clock correction coefficient (clock drift) */
    public double af1;
    
    /** Polynomial clock correction coefficient (rate of clock drift) */
    public double af2;
    
    /** Clock reference */
    public GPSTimeSec toc;
    
    /** Issue of ephemeris data */
    public int iode;
    
    /** Issue of clock data */
    public int iodc;
    

    public MsgEphemerisGPSDepF (int sender) { super(sender, TYPE); }
    public MsgEphemerisGPSDepF () { super(TYPE); }
    public MsgEphemerisGPSDepF (SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type != TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        common = new EphemerisCommonContentDepB().parse(parser);
        tgd = parser.getDouble();
        c_rs = parser.getDouble();
        c_rc = parser.getDouble();
        c_uc = parser.getDouble();
        c_us = parser.getDouble();
        c_ic = parser.getDouble();
        c_is = parser.getDouble();
        dn = parser.getDouble();
        m0 = parser.getDouble();
        ecc = parser.getDouble();
        sqrta = parser.getDouble();
        omega0 = parser.getDouble();
        omegadot = parser.getDouble();
        w = parser.getDouble();
        inc = parser.getDouble();
        inc_dot = parser.getDouble();
        af0 = parser.getDouble();
        af1 = parser.getDouble();
        af2 = parser.getDouble();
        toc = new GPSTimeSec().parse(parser);
        iode = parser.getU8();
        iodc = parser.getU16();
    }

    @Override
    protected void build(Builder builder) {
        common.build(builder);
        builder.putDouble(tgd);
        builder.putDouble(c_rs);
        builder.putDouble(c_rc);
        builder.putDouble(c_uc);
        builder.putDouble(c_us);
        builder.putDouble(c_ic);
        builder.putDouble(c_is);
        builder.putDouble(dn);
        builder.putDouble(m0);
        builder.putDouble(ecc);
        builder.putDouble(sqrta);
        builder.putDouble(omega0);
        builder.putDouble(omegadot);
        builder.putDouble(w);
        builder.putDouble(inc);
        builder.putDouble(inc_dot);
        builder.putDouble(af0);
        builder.putDouble(af1);
        builder.putDouble(af2);
        toc.build(builder);
        builder.putU8(iode);
        builder.putU16(iodc);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("common", common.toJSON());
        obj.put("tgd", tgd);
        obj.put("c_rs", c_rs);
        obj.put("c_rc", c_rc);
        obj.put("c_uc", c_uc);
        obj.put("c_us", c_us);
        obj.put("c_ic", c_ic);
        obj.put("c_is", c_is);
        obj.put("dn", dn);
        obj.put("m0", m0);
        obj.put("ecc", ecc);
        obj.put("sqrta", sqrta);
        obj.put("omega0", omega0);
        obj.put("omegadot", omegadot);
        obj.put("w", w);
        obj.put("inc", inc);
        obj.put("inc_dot", inc_dot);
        obj.put("af0", af0);
        obj.put("af1", af1);
        obj.put("af2", af2);
        obj.put("toc", toc.toJSON());
        obj.put("iode", iode);
        obj.put("iodc", iodc);
        return obj;
    }
}