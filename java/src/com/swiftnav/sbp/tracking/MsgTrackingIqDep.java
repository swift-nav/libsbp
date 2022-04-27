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


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPStruct;
import com.swiftnav.sbp.gnss.*;
import org.json.JSONObject;

/**
 * SBP class for message MSG_TRACKING_IQ_DEP (0x001C).
 *
 * <p>You can have MSG_TRACKING_IQ_DEP inherent its fields directly from an inherited SBP object, or
 * construct it inline using a dict of its fields.
 *
 * <p>Deprecated.
 */
public class MsgTrackingIqDep extends SBPMessage {
    public static final int TYPE = 0x001C;

    /** Tracking channel of origin */
    public int channel;

    /** GNSS signal identifier */
    public GnssSignalDep sid;

    /** Early, Prompt and Late correlations */
    public TrackingChannelCorrelation[] corrs;

    public MsgTrackingIqDep(int sender) {
        super(sender, TYPE);
    }

    public MsgTrackingIqDep() {
        super(TYPE);
    }

    public MsgTrackingIqDep(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type != TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        channel = parser.getU8();
        sid = new GnssSignalDep().parse(parser);
        corrs = parser.getArray(TrackingChannelCorrelation.class, 3);
    }

    @Override
    protected void build(Builder builder) {
        builder.putU8(channel);
        sid.build(builder);
        builder.putArray(corrs, 3);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("channel", channel);
        obj.put("sid", sid.toJSON());
        obj.put("corrs", SBPStruct.toJSONArray(corrs));
        return obj;
    }
}
