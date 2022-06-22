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
 * <p>Emulates the GPS CNAV message, reserving bytes for future broadcast of the drift model
 * parameters.
 */
public class MsgUtcLeapSecond extends SBPMessage {
    public static final int TYPE = 0x023A;

    /** Reserved. Bias coefficient of GPS time scale with respect to UTC drift model. */
    public int bias_coeff;

    /** Reserved. Drift coefficient of GPS time scale with respect to UTC drift model. */
    public int drift_coeff;

    /**
     * Reserved. Drift rate correction coefficient of GPS time scale with respect to UTC drift
     * model.
     */
    public int drift_rate_coeff;

    /** Leap second count before insertion. */
    public int count_before;

    /** Reserved. Drift model reference week second. */
    public int tow_s;

    /** Reserved. Drift model reference week number. */
    public int wn;

    /** Leap second reference week number. */
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
        bias_coeff = parser.getS16();
        drift_coeff = parser.getS16();
        drift_rate_coeff = parser.getS8();
        count_before = parser.getS8();
        tow_s = parser.getU16();
        wn = parser.getU16();
        ref_wn = parser.getU16();
        ref_dn = parser.getU8();
        count_after = parser.getS8();
    }

    @Override
    protected void build(Builder builder) {
        builder.putS16(bias_coeff);
        builder.putS16(drift_coeff);
        builder.putS8(drift_rate_coeff);
        builder.putS8(count_before);
        builder.putU16(tow_s);
        builder.putU16(wn);
        builder.putU16(ref_wn);
        builder.putU8(ref_dn);
        builder.putS8(count_after);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("bias_coeff", bias_coeff);
        obj.put("drift_coeff", drift_coeff);
        obj.put("drift_rate_coeff", drift_rate_coeff);
        obj.put("count_before", count_before);
        obj.put("tow_s", tow_s);
        obj.put("wn", wn);
        obj.put("ref_wn", ref_wn);
        obj.put("ref_dn", ref_dn);
        obj.put("count_after", count_after);
        return obj;
    }
}
