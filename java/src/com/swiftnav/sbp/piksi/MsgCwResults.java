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
 * SBP class for message MSG_CW_RESULTS (0x00C0).
 *
 * <p>You can have MSG_CW_RESULTS inherent its fields directly from an inherited SBP object, or
 * construct it inline using a dict of its fields.
 *
 * <p>This is an unused legacy message for result reporting from the CW interference channel on the
 * SwiftNAP. This message will be removed in a future release.
 */
public class MsgCwResults extends SBPMessage {
    public static final int TYPE = 0x00C0;

    public MsgCwResults(int sender) {
        super(sender, TYPE);
    }

    public MsgCwResults() {
        super(TYPE);
    }

    public MsgCwResults(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type == TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        // No additional fields
    }

    @Override
    protected void build(Builder builder) {
        // No additional fields
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        return obj;
    }
}
