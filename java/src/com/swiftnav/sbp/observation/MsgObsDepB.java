/* Copyright (C) 2015-2021 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
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
import com.swiftnav.sbp.SBPStruct;
import com.swiftnav.sbp.gnss.*;
import org.json.JSONObject;

/**
 * SBP class for message MSG_OBS_DEP_B (0x0043).
 *
 * <p>You can have MSG_OBS_DEP_B inherent its fields directly from an inherited SBP object, or
 * construct it inline using a dict of its fields.
 *
 * <p>This observation message has been deprecated in favor of observations that are more
 * interoperable. This message should be used for observations referenced to a nominal pseudorange
 * which are not interoperable with most 3rd party GNSS receivers or typical RTCMv3 observations.
 */
public class MsgObsDepB extends SBPMessage {
    public static final int TYPE = 0x0043;

    /** Header of a GPS observation message */
    public ObservationHeaderDep header;

    /** Pseudorange and carrier phase observation for a satellite being tracked. */
    public PackedObsContentDepB[] obs;

    public MsgObsDepB(int sender) {
        super(sender, TYPE);
    }

    public MsgObsDepB() {
        super(TYPE);
    }

    public MsgObsDepB(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type == TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        header = new ObservationHeaderDep().parse(parser);
        obs = parser.getArray(PackedObsContentDepB.class);
    }

    @Override
    protected void build(Builder builder) {
        header.build(builder);
        builder.putArray(obs);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("header", header.toJSON());
        obj.put("obs", SBPStruct.toJSONArray(obs));
        return obj;
    }
}
