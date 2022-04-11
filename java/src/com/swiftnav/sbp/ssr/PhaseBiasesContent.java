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
package com.swiftnav.sbp.ssr;

// This file was auto-generated from yaml/swiftnav/sbp/ssr.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPStruct;
import com.swiftnav.sbp.gnss.*;
import org.json.JSONObject;

public class PhaseBiasesContent extends SBPStruct {

    /** Signal encoded following RTCM specifications (DF380, DF381, DF382 and DF467) */
    public int code;

    /** Indicator for integer property */
    public int integer_indicator;

    /** Indicator for two groups of Wide-Lane(s) integer property */
    public int widelane_integer_indicator;

    /** Signal phase discontinuity counter. Increased for every discontinuity in phase. */
    public int discontinuity_counter;

    /** Phase bias for specified signal */
    public int bias;

    public PhaseBiasesContent() {}

    @Override
    public PhaseBiasesContent parse(SBPMessage.Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        code = parser.getU8();
        integer_indicator = parser.getU8();
        widelane_integer_indicator = parser.getU8();
        discontinuity_counter = parser.getU8();
        bias = parser.getS32();
        return this;
    }

    @Override
    public void build(SBPMessage.Builder builder) {
        /* Build fields into binary */
        builder.putU8(code);
        builder.putU8(integer_indicator);
        builder.putU8(widelane_integer_indicator);
        builder.putU8(discontinuity_counter);
        builder.putS32(bias);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = new JSONObject();
        obj.put("code", code);
        obj.put("integer_indicator", integer_indicator);
        obj.put("widelane_integer_indicator", widelane_integer_indicator);
        obj.put("discontinuity_counter", discontinuity_counter);
        obj.put("bias", bias);
        return obj;
    }
}
