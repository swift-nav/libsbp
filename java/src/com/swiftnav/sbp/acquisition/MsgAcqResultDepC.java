/*
 * Copyright (C) 2015-2022 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

package com.swiftnav.sbp.acquisition;

// This file was auto-generated from yaml/swiftnav/sbp/acquisition.yaml by generate.py.
// Do not modify by hand!

import java.math.BigInteger;

import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPStruct;
import com.swiftnav.sbp.gnss.*;

import org.json.JSONObject;
import org.json.JSONArray;


/** SBP class for message MSG_ACQ_RESULT_DEP_C (0x001F).
 *
 * You can have MSG_ACQ_RESULT_DEP_C inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
 * Deprecated. */

public class MsgAcqResultDepC extends SBPMessage {
    public static final int TYPE = 0x001F;

    
    /** CN/0 of best point */
    public float cn0;
    
    /** Code phase of best point */
    public float cp;
    
    /** Carrier frequency of best point */
    public float cf;
    
    /** GNSS signal for which acquisition was attempted */
    public GnssSignalDep sid;
    

    public MsgAcqResultDepC (int sender) { super(sender, TYPE); }
    public MsgAcqResultDepC () { super(TYPE); }
    public MsgAcqResultDepC (SBPMessage msg) throws SBPBinaryException {
        super(msg);
        if (msg.type != TYPE)
            throw new SBPBinaryException("Type mismatch for MsgAcqResultDepC, expected 31, actual " + msg.type);
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        cn0 = parser.getFloat();
        cp = parser.getFloat();
        cf = parser.getFloat();
        sid = new GnssSignalDep().parse(parser); 
    }

    @Override
    protected void build(Builder builder) {
        builder.putFloat(cn0);
        builder.putFloat(cp);
        builder.putFloat(cf);
        sid.build(builder); 
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("cn0", cn0);
        obj.put("cp", cp);
        obj.put("cf", cf);
        obj.put("sid", sid.toJSON());
        return obj;
    }

    @Override
    public String getFriendlyName() {
        return "ACQ RESULT DEP C";
    }
}
