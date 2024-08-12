/* Copyright (C) 2015-2022 Swift Navigation Inc.
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


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPStruct;
import com.swiftnav.sbp.gnss.*;
import org.json.JSONObject;

/**
 * SBP class for message MSG_SSR_STEC_CORRECTION_DEP_A (0x05EB).
 *
 * <p>You can have MSG_SSR_STEC_CORRECTION_DEP_A inherent its fields directly from an inherited SBP
 * object, or construct it inline using a dict of its fields.
 *
 * <p>Deprecated.
 */
public class MsgSsrStecCorrectionDepA extends SBPMessage {
    public static final int TYPE = 0x05EB;

    /** Header of a STEC message */
    public STECHeaderDepA header;

    /** Array of STEC information for each space vehicle */
    public STECSatElement[] stec_sat_list;

    public MsgSsrStecCorrectionDepA(int sender) {
        super(sender, TYPE);
    }

    public MsgSsrStecCorrectionDepA() {
        super(TYPE);
    }

    public MsgSsrStecCorrectionDepA(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        if (msg.type != TYPE)
            throw new SBPBinaryException(
                    "Type mismatch for MsgSsrStecCorrectionDepA, expected 1515, actual "
                            + msg.type);
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        header = new STECHeaderDepA().parse(parser);
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

    @Override
    public String getFriendlyName() {
        return "SSR STEC CORRECTION DEP A";
    }
}
