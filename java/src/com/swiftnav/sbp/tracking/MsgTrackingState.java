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
package com.swiftnav.sbp.tracking;

// This file was auto-generated from yaml/swiftnav/sbp/tracking.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPStruct;
import com.swiftnav.sbp.gnss.*;
import org.json.JSONObject;

/**
 * SBP class for message MSG_TRACKING_STATE (0x0041).
 *
 * <p>You can have MSG_TRACKING_STATE inherent its fields directly from an inherited SBP object, or
 * construct it inline using a dict of its fields.
 *
 * <p>The tracking message returns a variable-length array of tracking channel states. It reports
 * status and carrier-to-noise density measurements for all tracked satellites.
 */
public class MsgTrackingState extends SBPMessage {
    public static final int TYPE = 0x0041;

    /** Signal tracking channel state */
    public TrackingChannelState[] states;

    public MsgTrackingState(int sender) {
        super(sender, TYPE);
    }

    public MsgTrackingState() {
        super(TYPE);
    }

    public MsgTrackingState(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type == TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        states = parser.getArray(TrackingChannelState.class);
    }

    @Override
    protected void build(Builder builder) {
        builder.putArray(states);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("states", SBPStruct.toJSONArray(states));
        return obj;
    }
}
