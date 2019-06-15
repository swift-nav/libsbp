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

package com.swiftnav.sbp.tracking;

import java.math.BigInteger;

import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPStruct;
import com.swiftnav.sbp.gnss.*;

import org.json.JSONObject;
import org.json.JSONArray;


/** SBP class for message MSG_TRACKING_IQ_DEP_B (0x002C).
 *
 * You can have MSG_TRACKING_IQ_DEP_B inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
 * When enabled, a tracking channel can output the correlations at each
 * update interval. */

public class MsgTrackingIqDepB extends SBPMessage {
    public static final int TYPE = 0x002C;

    
    /** Tracking channel of origin */
    public int channel;
    
    /** GNSS signal identifier */
    public GnssSignal sid;
    
    /** Early, Prompt and Late correlations */
    public TrackingChannelCorrelationDep[] corrs;
    

    public MsgTrackingIqDepB (int sender) { super(sender, TYPE); }
    public MsgTrackingIqDepB () { super(TYPE); }
    public MsgTrackingIqDepB (SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type != TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        channel = parser.getU8();
        sid = new GnssSignal().parse(parser);
        corrs = parser.getArray(TrackingChannelCorrelationDep.class, 3);
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