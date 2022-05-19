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
import org.json.JSONArray;
import org.json.JSONObject;

public class STECSatElement extends SBPStruct {

    /** Unique space vehicle identifier */
    public SvId sv_id;

    /**
     * Quality of the STEC data. Encoded following RTCM DF389 specification but in units of TECU
     * instead of m.
     */
    public int stec_quality_indicator;

    /**
     * Coefficients of the STEC polynomial in the order of C00, C01, C10, C11. C00 = 0.05 TECU,
     * C01/C10 = 0.02 TECU/deg, C11 0.02 TECU/deg^2
     */
    public int[] stec_coeff;

    public STECSatElement() {}

    @Override
    public STECSatElement parse(SBPMessage.Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        sv_id = new SvId().parse(parser);
        stec_quality_indicator = parser.getU8();
        stec_coeff = parser.getArrayofS16(4);
        return this;
    }

    @Override
    public void build(SBPMessage.Builder builder) {
        /* Build fields into binary */
        sv_id.build(builder);
        builder.putU8(stec_quality_indicator);
        builder.putArrayofS16(stec_coeff, 4);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = new JSONObject();
        obj.put("sv_id", sv_id.toJSON());
        obj.put("stec_quality_indicator", stec_quality_indicator);
        obj.put("stec_coeff", new JSONArray(stec_coeff));
        return obj;
    }
}
