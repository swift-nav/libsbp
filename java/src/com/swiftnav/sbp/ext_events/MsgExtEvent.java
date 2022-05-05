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
package com.swiftnav.sbp.ext_events;

// This file was auto-generated from yaml/swiftnav/sbp/ext_events.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import org.json.JSONObject;

/**
 * SBP class for message MSG_EXT_EVENT (0x0101).
 *
 * <p>You can have MSG_EXT_EVENT inherent its fields directly from an inherited SBP object, or
 * construct it inline using a dict of its fields.
 *
 * <p>Reports detection of an external event, the GPS time it occurred, which pin it was and whether
 * it was rising or falling.
 */
public class MsgExtEvent extends SBPMessage {
    public static final int TYPE = 0x0101;

    /** GPS week number */
    public int wn;

    /** GPS time of week rounded to the nearest millisecond */
    public long tow;

    /** Nanosecond residual of millisecond-rounded TOW (ranges from -500000 to 500000) */
    public int ns_residual;

    /** Flags */
    public int flags;

    /** Pin number. 0..9 = DEBUG0..9. */
    public int pin;

    public MsgExtEvent(int sender) {
        super(sender, TYPE);
    }

    public MsgExtEvent() {
        super(TYPE);
    }

    public MsgExtEvent(SBPMessage msg) throws SBPBinaryException {
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
        pin = parser.getU8();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU16(wn);
        builder.putU32(tow);
        builder.putS32(ns_residual);
        builder.putU8(flags);
        builder.putU8(pin);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("wn", wn);
        obj.put("tow", tow);
        obj.put("ns_residual", ns_residual);
        obj.put("flags", flags);
        obj.put("pin", pin);
        return obj;
    }
}
