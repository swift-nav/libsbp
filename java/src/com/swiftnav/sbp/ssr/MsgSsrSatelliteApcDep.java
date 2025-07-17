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

package com.swiftnav.sbp.ssr;

// This file was auto-generated from yaml/swiftnav/sbp/ssr.yaml by generate.py.
// Do not modify by hand!

import java.math.BigInteger;

import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPStruct;
import com.swiftnav.sbp.gnss.*;

import org.json.JSONObject;
import org.json.JSONArray;


/** SBP class for message MSG_SSR_SATELLITE_APC_DEP (0x0604).
 *
 * You can have MSG_SSR_SATELLITE_APC_DEP inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
 * Deprecated. */

public class MsgSsrSatelliteApcDep extends SBPMessage {
    public static final int TYPE = 0x0604;

    
    /** Satellite antenna phase center corrections */
    public SatelliteAPC[] apc;
    

    public MsgSsrSatelliteApcDep (int sender) { super(sender, TYPE); }
    public MsgSsrSatelliteApcDep () { super(TYPE); }
    public MsgSsrSatelliteApcDep (SBPMessage msg) throws SBPBinaryException {
        super(msg);
        if (msg.type != TYPE)
            throw new SBPBinaryException("Type mismatch for MsgSsrSatelliteApcDep, expected 1540, actual " + msg.type);
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        apc = parser.getArray(SatelliteAPC.class); 
    }

    @Override
    protected void build(Builder builder) {
        builder.putArray(apc); 
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("apc", SBPStruct.toJSONArray(apc));
        return obj;
    }

    @Override
    public String getFriendlyName() {
        return "SSR SATELLITE APC DEP";
    }
}
