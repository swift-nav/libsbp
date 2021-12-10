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
package com.swiftnav.sbp.navigation;

// This file was auto-generated from yaml/swiftnav/sbp/navigation.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import org.json.JSONObject;

/**
 * SBP class for message MSG_UTC_TIME_GNSS (0x0105).
 *
 * <p>You can have MSG_UTC_TIME_GNSS inherent its fields directly from an inherited SBP object, or
 * construct it inline using a dict of its fields.
 *
 * <p>This message reports the Universal Coordinated Time (UTC). Note the flags which indicate the
 * source of the UTC offset value and source of the time fix.
 */
public class MsgUtcTimeGnss extends SBPMessage {
    public static final int TYPE = 0x0105;

    /** Indicates source and time validity */
    public int flags;

    /** GPS time of week rounded to the nearest millisecond */
    public long tow;

    /** Year */
    public int year;

    /** Month (range 1 .. 12) */
    public int month;

    /** days in the month (range 1-31) */
    public int day;

    /** hours of day (range 0-23) */
    public int hours;

    /** minutes of hour (range 0-59) */
    public int minutes;

    /** seconds of minute (range 0-60) rounded down */
    public int seconds;

    /** nanoseconds of second (range 0-999999999) */
    public long ns;

    public MsgUtcTimeGnss(int sender) {
        super(sender, TYPE);
    }

    public MsgUtcTimeGnss() {
        super(TYPE);
    }

    public MsgUtcTimeGnss(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type == TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        flags = parser.getU8();
        tow = parser.getU32();
        year = parser.getU16();
        month = parser.getU8();
        day = parser.getU8();
        hours = parser.getU8();
        minutes = parser.getU8();
        seconds = parser.getU8();
        ns = parser.getU32();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU8(flags);
        builder.putU32(tow);
        builder.putU16(year);
        builder.putU8(month);
        builder.putU8(day);
        builder.putU8(hours);
        builder.putU8(minutes);
        builder.putU8(seconds);
        builder.putU32(ns);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("flags", flags);
        obj.put("tow", tow);
        obj.put("year", year);
        obj.put("month", month);
        obj.put("day", day);
        obj.put("hours", hours);
        obj.put("minutes", minutes);
        obj.put("seconds", seconds);
        obj.put("ns", ns);
        return obj;
    }
}
