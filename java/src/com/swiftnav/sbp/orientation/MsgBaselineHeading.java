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
package com.swiftnav.sbp.orientation;

// This file was auto-generated from yaml/swiftnav/sbp/orientation.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import org.json.JSONObject;

/**
 * SBP class for message MSG_BASELINE_HEADING (0x020F).
 *
 * <p>You can have MSG_BASELINE_HEADING inherent its fields directly from an inherited SBP object,
 * or construct it inline using a dict of its fields.
 *
 * <p>This message reports the baseline heading pointing from the base station to the rover relative
 * to True North. The full GPS time is given by the preceding MSG_GPS_TIME with the matching
 * time-of-week (tow). It is intended that time-matched RTK mode is used when the base station is
 * moving.
 */
public class MsgBaselineHeading extends SBPMessage {
    public static final int TYPE = 0x020F;

    /** GPS Time of Week */
    public long tow;

    /** Heading */
    public long heading;

    /** Number of satellites used in solution */
    public int n_sats;

    /** Status flags */
    public int flags;

    public MsgBaselineHeading(int sender) {
        super(sender, TYPE);
    }

    public MsgBaselineHeading() {
        super(TYPE);
    }

    public MsgBaselineHeading(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type == TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        tow = parser.getU32();
        heading = parser.getU32();
        n_sats = parser.getU8();
        flags = parser.getU8();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU32(tow);
        builder.putU32(heading);
        builder.putU8(n_sats);
        builder.putU8(flags);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("tow", tow);
        obj.put("heading", heading);
        obj.put("n_sats", n_sats);
        obj.put("flags", flags);
        return obj;
    }
}
