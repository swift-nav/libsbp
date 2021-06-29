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
package com.swiftnav.sbp.system;

// This file was auto-generated from yaml/swiftnav/sbp/system.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import org.json.JSONObject;

/**
 * SBP class for message MSG_GNSS_TIME_OFFSET (0xFF07).
 *
 * <p>You can have MSG_GNSS_TIME_OFFSET inherent its fields directly from an inherited SBP object,
 * or construct it inline using a dict of its fields.
 *
 * <p>The GNSS time offset message contains the information that is needed to translate messages
 * tagged with a local timestamp (e.g. IMU or wheeltick messages) to GNSS time for the sender
 * producing this message.
 */
public class MsgGnssTimeOffset extends SBPMessage {
    public static final int TYPE = 0xFF07;

    /** Weeks portion of the time offset */
    public int weeks;

    /** Milliseconds portion of the time offset */
    public int milliseconds;

    /** Microseconds portion of the time offset */
    public int microseconds;

    /** Status flags (reserved) */
    public int flags;

    public MsgGnssTimeOffset(int sender) {
        super(sender, TYPE);
    }

    public MsgGnssTimeOffset() {
        super(TYPE);
    }

    public MsgGnssTimeOffset(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type == TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        weeks = parser.getS16();
        milliseconds = parser.getS32();
        microseconds = parser.getS16();
        flags = parser.getU8();
    }

    @Override
    protected void build(Builder builder) {
        builder.putS16(weeks);
        builder.putS32(milliseconds);
        builder.putS16(microseconds);
        builder.putU8(flags);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("weeks", weeks);
        obj.put("milliseconds", milliseconds);
        obj.put("microseconds", microseconds);
        obj.put("flags", flags);
        return obj;
    }
}
