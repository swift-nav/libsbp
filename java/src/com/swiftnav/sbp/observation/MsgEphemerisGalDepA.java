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


/** SBP class for message MSG_EPHEMERIS_GAL_DEP_A (0x0095).
 *
 * You can have MSG_EPHEMERIS_GAL_DEP_A inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
 * This observation message has been deprecated in favor of
 * an ephemeris message with explicit source of NAV data. */

public class MsgEphemerisGalDepA extends SBPMessage {
    public static final int TYPE = 0x0095;

    
    /** Values common for all ephemeris types */
    public EphemerisCommonContent common;
    
    /** E1-E5a Broadcast Group Delay */
    public float bgd_e1e5a;
    
    /** E1-E5b Broadcast Group Delay */
    public float bgd_e1e5b;
    
    /** Amplitude of the sine harmonic correction term to the orbit radius */
    public float c_rs;
    
    /** Amplitude of the cosine harmonic correction term to the orbit radius */
    public float c_rc;
    
    /** Amplitude of the cosine harmonic correction term to the argument of latitude */
    public float c_uc;
    
    /** Amplitude of the sine harmonic correction term to the argument of latitude */
    public float c_us;
    
    /** Amplitude of the cosine harmonic correction term to the angle of inclination */
    public float c_ic;
    
    /** Amplitude of the sine harmonic correction term to the angle of inclination */
    public float c_is;
    
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
    public float af2;
    
    /** Clock reference */
    public GPSTimeSec toc;
    
    /** Issue of ephemeris data */
    public int iode;
    
    /** Issue of clock data */
    public int iodc;
    

    public MsgEphemerisGalDepA (int sender) { super(sender, TYPE); }
    public MsgEphemerisGalDepA () { super(TYPE); }
    public MsgEphemerisGalDepA (SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type != TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        common = new EphemerisCommonContent().parse(parser);
        bgd_e1e5a = parser.getFloat();
        bgd_e1e5b = parser.getFloat();
        c_rs = parser.getFloat();
        c_rc = parser.getFloat();
        c_uc = parser.getFloat();
        c_us = parser.getFloat();
        c_ic = parser.getFloat();
        c_is = parser.getFloat();
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
        af2 = parser.getFloat();
        toc = new GPSTimeSec().parse(parser);
        iode = parser.getU16();
        iodc = parser.getU16();
    }

    @Override
    protected void build(Builder builder) {
        common.build(builder);
        builder.putFloat(bgd_e1e5a);
        builder.putFloat(bgd_e1e5b);
        builder.putFloat(c_rs);
        builder.putFloat(c_rc);
        builder.putFloat(c_uc);
        builder.putFloat(c_us);
        builder.putFloat(c_ic);
        builder.putFloat(c_is);
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
        builder.putFloat(af2);
        toc.build(builder);
        builder.putU16(iode);
        builder.putU16(iodc);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("common", common.toJSON());
        obj.put("bgd_e1e5a", bgd_e1e5a);
        obj.put("bgd_e1e5b", bgd_e1e5b);
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