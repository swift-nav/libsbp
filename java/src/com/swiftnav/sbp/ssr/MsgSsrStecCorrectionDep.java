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
 * SBP class for message MSG_SSR_STEC_CORRECTION_DEP (0x05FB).
 *
 * <p>You can have MSG_SSR_STEC_CORRECTION_DEP inherent its fields directly from an inherited SBP
 * object, or construct it inline using a dict of its fields.
 *
 * <p>Deprecated.
 */
public class MsgSsrStecCorrectionDep extends SBPMessage {
    public static final int TYPE = 0x05FB;

    /** Header of a STEC polynomial coefficient message. */
    public STECHeader header;

    /** Array of STEC polynomial coefficients for each space vehicle. */
    public STECSatElement[] stec_sat_list;

    public MsgSsrStecCorrectionDep(int sender) {
        super(sender, TYPE);
    }

    public MsgSsrStecCorrectionDep() {
        super(TYPE);
    }

    public MsgSsrStecCorrectionDep(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        if (msg.type != TYPE)
            throw new SBPBinaryException(
                    "Type mismatch for MsgSsrStecCorrectionDep, expected 1531, actual " + msg.type);
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

    @Override
    public String getFriendlyName() {
        return "SSR STEC CORRECTION DEP";
    }
}
