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

package com.swiftnav.sbp.ssr;

import java.math.BigInteger;

import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPStruct;
import com.swiftnav.sbp.gnss.*;

import org.json.JSONObject;
import org.json.JSONArray;


/** SBP class for message MSG_SSR_STEC_CORRECTION (0x05EB).
 *
 * You can have MSG_SSR_STEC_CORRECTION inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
 * The STEC per space vehicle, given as polynomial approximation for
 * a given grid.  This should be combined with MSG_SSR_GRIDDED_CORRECTION
 * message to get the state space representation of the atmospheric
 * delay. It is typically equivalent to the QZSS CLAS Sub Type 8 messages */

public class MsgSsrStecCorrection extends SBPMessage {
    public static final int TYPE = 0x05EB;

    
    /** Header of a STEC message */
    public STECHeader header;
    
    /** Array of STEC information for each space vehicle */
    public STECSatElement[] stec_sat_list;
    

    public MsgSsrStecCorrection (int sender) { super(sender, TYPE); }
    public MsgSsrStecCorrection () { super(TYPE); }
    public MsgSsrStecCorrection (SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type != TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        header = new STECHeader().parse(parser);
        stec_sat_list = parser.getArray(STECSatElement.class);
    }

    @Override
    protected void build(Builder builder) {
        header.build(builder);
        builder.putArray(stec_sat_list);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("header", header.toJSON());
        obj.put("stec_sat_list", SBPStruct.toJSONArray(stec_sat_list));
        return obj;
    }
}