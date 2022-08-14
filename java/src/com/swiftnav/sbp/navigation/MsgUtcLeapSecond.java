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
 * SBP class for message MSG_UTC_LEAP_SECOND (0x023A).
 *
 * <p>You can have MSG_UTC_LEAP_SECOND inherent its fields directly from an inherited SBP object, or
 * construct it inline using a dict of its fields.
 *
 * <p>UTC-GPST leap seconds before and after the most recent (past, or future, for announced
 * insertions) UTC leap second insertion.
 */
public class MsgUtcLeapSecond extends SBPMessage {
    public static final int TYPE = 0x023A;

    /** Reserved. */
    public int reserved_0;

    /** Reserved. */
    public int reserved_1;

    /** Reserved. */
    public int reserved_2;

    /** Leap second count before insertion. */
    public int count_before;

    /** Reserved. */
    public int reserved_3;

    /** Reserved. */
    public int reserved_4;

    /** Leap second reference GPS week number. */
    public int ref_wn;

    /** Leap second reference day number. */
    public int ref_dn;

    /** Leap second count after insertion. */
    public int count_after;

    public MsgUtcLeapSecond(int sender) {
        super(sender, TYPE);
    }

    public MsgUtcLeapSecond() {
        super(TYPE);
    }

    public MsgUtcLeapSecond(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type == TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        reserved_0 = parser.getS16();
        reserved_1 = parser.getS16();
        reserved_2 = parser.getS8();
        count_before = parser.getS8();
        reserved_3 = parser.getU16();
        reserved_4 = parser.getU16();
        ref_wn = parser.getU16();
        ref_dn = parser.getU8();
        count_after = parser.getS8();
    }

    @Override
    protected void build(Builder builder) {
        builder.putS16(reserved_0);
        builder.putS16(reserved_1);
        builder.putS8(reserved_2);
        builder.putS8(count_before);
        builder.putU16(reserved_3);
        builder.putU16(reserved_4);
        builder.putU16(ref_wn);
        builder.putU8(ref_dn);
        builder.putS8(count_after);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("reserved_0", reserved_0);
        obj.put("reserved_1", reserved_1);
        obj.put("reserved_2", reserved_2);
        obj.put("count_before", count_before);
        obj.put("reserved_3", reserved_3);
        obj.put("reserved_4", reserved_4);
        obj.put("ref_wn", ref_wn);
        obj.put("ref_dn", ref_dn);
        obj.put("count_after", count_after);
        return obj;
    }
}
