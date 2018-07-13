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



public class MsgGnssCapb extends SBPMessage {
    public static final int TYPE = 0x0096;

    
    /** Navigation Message Correction Table Validity Time */
    public GPSTimeSec t_nmct;
    
    /** GNSS capabilities masks */
    public GnssCapb gc;
    

    public MsgGnssCapb (int sender) { super(sender, TYPE); }
    public MsgGnssCapb () { super(TYPE); }
    public MsgGnssCapb (SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type != TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        t_nmct = new GPSTimeSec().parse(parser);
        gc = new GnssCapb().parse(parser);
    }

    @Override
    protected void build(Builder builder) {
        t_nmct.build(builder);
        gc.build(builder);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("t_nmct", t_nmct.toJSON());
        obj.put("gc", gc.toJSON());
        return obj;
    }
}