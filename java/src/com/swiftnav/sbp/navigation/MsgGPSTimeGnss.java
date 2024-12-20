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
package com.swiftnav.sbp.navigation;

// This file was auto-generated from yaml/swiftnav/sbp/navigation.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import org.json.JSONObject;

/**
 * SBP class for message MSG_GPS_TIME_GNSS (0x0104).
 *
 * <p>You can have MSG_GPS_TIME_GNSS inherent its fields directly from an inherited SBP object, or
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
 *
 * <p>The values in this message are from GNSS measurements only. To get values fused with inertial
 * measurements use MSG_GPS_TIME.
 */
public class MsgGPSTimeGnss extends SBPMessage {
    public static final int TYPE = 0x0104;

    /** GPS week number */
    public int wn;

    /** GPS time of week rounded to the nearest millisecond */
    public long tow;

    /** Nanosecond residual of millisecond-rounded TOW (ranges from -500000 to 500000) */
    public int ns_residual;

    /** Status flags (reserved) */
    public int flags;

    public MsgGPSTimeGnss(int sender) {
        super(sender, TYPE);
    }

    public MsgGPSTimeGnss() {
        super(TYPE);
    }

    public MsgGPSTimeGnss(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        if (msg.type != TYPE)
            throw new SBPBinaryException(
                    "Type mismatch for MsgGPSTimeGnss, expected 260, actual " + msg.type);
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

    @Override
    public String getFriendlyName() {
        return "GPS TIME GNSS-only";
    }
}
