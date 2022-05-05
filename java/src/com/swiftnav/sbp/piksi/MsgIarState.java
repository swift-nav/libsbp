/* Copyright (C) 2015-2022 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */
package com.swiftnav.sbp.piksi;

// This file was auto-generated from yaml/swiftnav/sbp/piksi.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.gnss.*;
import org.json.JSONObject;

/**
 * SBP class for message MSG_IAR_STATE (0x0019).
 *
 * <p>You can have MSG_IAR_STATE inherent its fields directly from an inherited SBP object, or
 * construct it inline using a dict of its fields.
 *
 * <p>This message reports the state of the Integer Ambiguity Resolution (IAR) process, which
 * resolves unknown integer ambiguities from double-differenced carrier-phase measurements from
 * satellite observations.
 */
public class MsgIarState extends SBPMessage {
    public static final int TYPE = 0x0019;

    /** Number of integer ambiguity hypotheses remaining */
    public long num_hyps;

    public MsgIarState(int sender) {
        super(sender, TYPE);
    }

    public MsgIarState() {
        super(TYPE);
    }

    public MsgIarState(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type == TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        num_hyps = parser.getU32();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU32(num_hyps);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("num_hyps", num_hyps);
        return obj;
    }
}
