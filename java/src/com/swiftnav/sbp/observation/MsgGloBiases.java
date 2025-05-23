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
package com.swiftnav.sbp.observation;

// This file was auto-generated from yaml/swiftnav/sbp/observation.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.gnss.*;
import org.json.JSONObject;

/**
 * SBP class for message MSG_GLO_BIASES (0x0075).
 *
 * <p>You can have MSG_GLO_BIASES inherent its fields directly from an inherited SBP object, or
 * construct it inline using a dict of its fields.
 *
 * <p>The GLONASS L1/L2 Code-Phase biases allows to perform GPS+GLONASS integer ambiguity resolution
 * for baselines with mixed receiver types (e.g. receiver of different manufacturers).
 */
public class MsgGloBiases extends SBPMessage {
    public static final int TYPE = 0x0075;

    /** GLONASS FDMA signals mask */
    public int mask;

    /** GLONASS L1 C/A Code-Phase Bias */
    public int l1ca_bias;

    /** GLONASS L1 P Code-Phase Bias */
    public int l1p_bias;

    /** GLONASS L2 C/A Code-Phase Bias */
    public int l2ca_bias;

    /** GLONASS L2 P Code-Phase Bias */
    public int l2p_bias;

    public MsgGloBiases(int sender) {
        super(sender, TYPE);
    }

    public MsgGloBiases() {
        super(TYPE);
    }

    public MsgGloBiases(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        if (msg.type != TYPE)
            throw new SBPBinaryException(
                    "Type mismatch for MsgGloBiases, expected 117, actual " + msg.type);
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        mask = parser.getU8();
        l1ca_bias = parser.getS16();
        l1p_bias = parser.getS16();
        l2ca_bias = parser.getS16();
        l2p_bias = parser.getS16();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU8(mask);
        builder.putS16(l1ca_bias);
        builder.putS16(l1p_bias);
        builder.putS16(l2ca_bias);
        builder.putS16(l2p_bias);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("mask", mask);
        obj.put("l1ca_bias", l1ca_bias);
        obj.put("l1p_bias", l1p_bias);
        obj.put("l2ca_bias", l2ca_bias);
        obj.put("l2p_bias", l2p_bias);
        return obj;
    }

    @Override
    public String getFriendlyName() {
        return "GLO BIASES";
    }
}
