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


/** SBP class for message MSG_IONO (0x0090).
 *
 * You can have MSG_IONO inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
 * The ionospheric parameters which allow the "L1 only" or "L2 only" user to
 * utilize the ionospheric model for computation of the ionospheric delay.
 * Please see ICD-GPS-200 (Chapter 20.3.3.5.1.7) for more details. */

public class MsgIono extends SBPMessage {
    public static final int TYPE = 0x0090;

    
    /** Navigation Message Correction Table Valitidy Time */
    public GPSTimeSec t_nmct;
    
    public double a0;
    
    public double a1;
    
    public double a2;
    
    public double a3;
    
    public double b0;
    
    public double b1;
    
    public double b2;
    
    public double b3;
    

    public MsgIono (int sender) { super(sender, TYPE); }
    public MsgIono () { super(TYPE); }
    public MsgIono (SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type != TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        t_nmct = new GPSTimeSec().parse(parser);
        a0 = parser.getDouble();
        a1 = parser.getDouble();
        a2 = parser.getDouble();
        a3 = parser.getDouble();
        b0 = parser.getDouble();
        b1 = parser.getDouble();
        b2 = parser.getDouble();
        b3 = parser.getDouble();
    }

    @Override
    protected void build(Builder builder) {
        t_nmct.build(builder);
        builder.putDouble(a0);
        builder.putDouble(a1);
        builder.putDouble(a2);
        builder.putDouble(a3);
        builder.putDouble(b0);
        builder.putDouble(b1);
        builder.putDouble(b2);
        builder.putDouble(b3);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("t_nmct", t_nmct.toJSON());
        obj.put("a0", a0);
        obj.put("a1", a1);
        obj.put("a2", a2);
        obj.put("a3", a3);
        obj.put("b0", b0);
        obj.put("b1", b1);
        obj.put("b2", b2);
        obj.put("b3", b3);
        return obj;
    }
}