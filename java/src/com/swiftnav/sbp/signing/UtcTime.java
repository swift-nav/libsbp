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
package com.swiftnav.sbp.signing;

// This file was auto-generated from yaml/swiftnav/sbp/signing.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPStruct;
import org.json.JSONObject;

public class UtcTime extends SBPStruct {

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

    public UtcTime() {}

    @Override
    public UtcTime parse(SBPMessage.Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        year = parser.getU16();
        month = parser.getU8();
        day = parser.getU8();
        hours = parser.getU8();
        minutes = parser.getU8();
        seconds = parser.getU8();
        ns = parser.getU32();
        return this;
    }

    @Override
    public void build(SBPMessage.Builder builder) {
        /* Build fields into binary */
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
        JSONObject obj = new JSONObject();
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
