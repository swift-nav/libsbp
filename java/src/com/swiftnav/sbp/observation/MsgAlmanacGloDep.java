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


/** SBP class for message MSG_ALMANAC_GLO_DEP (0x0071).
 *
 * You can have MSG_ALMANAC_GLO_DEP inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
 * The almanac message returns a set of satellite orbit parameters. Almanac
 * data is not very precise and is considered valid for up to several months.
 * Please see the GLO ICD 5.1 "Chapter 4.5 Non-immediate information and
 * almanac" for details. */

public class MsgAlmanacGloDep extends SBPMessage {
    public static final int TYPE = 0x0071;

    
    /** Values common for all almanac types */
    public AlmanacCommonContentDep common;
    
    /** Longitude of the first ascending node of the orbit in PZ-90.02
coordinate system
 */
    public double lambda_na;
    
    /** Time of the first ascending node passage */
    public double t_lambda_na;
    
    /** Value of inclination at instant of t_lambda */
    public double i;
    
    /** Value of Draconian period at instant of t_lambda */
    public double t;
    
    /** Rate of change of the Draconian period */
    public double t_dot;
    
    /** Eccentricity at instant of t_lambda */
    public double epsilon;
    
    /** Argument of perigee at instant of t_lambda */
    public double omega;
    

    public MsgAlmanacGloDep (int sender) { super(sender, TYPE); }
    public MsgAlmanacGloDep () { super(TYPE); }
    public MsgAlmanacGloDep (SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type != TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        common = new AlmanacCommonContentDep().parse(parser);
        lambda_na = parser.getDouble();
        t_lambda_na = parser.getDouble();
        i = parser.getDouble();
        t = parser.getDouble();
        t_dot = parser.getDouble();
        epsilon = parser.getDouble();
        omega = parser.getDouble();
    }

    @Override
    protected void build(Builder builder) {
        common.build(builder);
        builder.putDouble(lambda_na);
        builder.putDouble(t_lambda_na);
        builder.putDouble(i);
        builder.putDouble(t);
        builder.putDouble(t_dot);
        builder.putDouble(epsilon);
        builder.putDouble(omega);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("common", common.toJSON());
        obj.put("lambda_na", lambda_na);
        obj.put("t_lambda_na", t_lambda_na);
        obj.put("i", i);
        obj.put("t", t);
        obj.put("t_dot", t_dot);
        obj.put("epsilon", epsilon);
        obj.put("omega", omega);
        return obj;
    }
}