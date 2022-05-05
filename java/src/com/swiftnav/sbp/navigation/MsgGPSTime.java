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
package com.swiftnav.sbp.navigation;

// This file was auto-generated from yaml/swiftnav/sbp/navigation.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import org.json.JSONObject;

/**
 * SBP class for message MSG_GPS_TIME (0x0102).
 *
 * <p>You can have MSG_GPS_TIME inherent its fields directly from an inherited SBP object, or
 * construct it inline using a dict of its fields.
 *
 * <p>This message reports the GPS time, representing the time since the GPS epoch began on midnight
 * January 6, 1980 UTC. GPS time counts the weeks and seconds of the week. The weeks begin at the
 * Saturday/Sunday transition. GPS week 0 began at the beginning of the GPS time scale.
 *
 * <p>Within each week number, the GPS time of the week is between between 0 and 604800 seconds
 * (=60*60*24*7). Note that GPS time does not accumulate leap seconds, and as of now, has a small
 * offset from UTC. In a message stream, this message precedes a set of other navigation messages
 * referenced to the same time (but lacking the ns field) and indicates a more precise time of these
 * messages.
 */
public class MsgGPSTime extends SBPMessage {
    public static final int TYPE = 0x0102;

    /** GPS week number */
    public int wn;

    /** GPS time of week rounded to the nearest millisecond */
    public long tow;

    /** Nanosecond residual of millisecond-rounded TOW (ranges from -500000 to 500000) */
    public int ns_residual;

    /** Status flags (reserved) */
    public int flags;

    public MsgGPSTime(int sender) {
        super(sender, TYPE);
    }

    public MsgGPSTime() {
        super(TYPE);
    }

    public MsgGPSTime(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type == TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        wn = parser.getU16();
        tow = parser.getU32();
        ns_residual = parser.getS32();
        flags = parser.getU8();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU16(wn);
        builder.putU32(tow);
        builder.putS32(ns_residual);
        builder.putU8(flags);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("wn", wn);
        obj.put("tow", tow);
        obj.put("ns_residual", ns_residual);
        obj.put("flags", flags);
        return obj;
    }
}
