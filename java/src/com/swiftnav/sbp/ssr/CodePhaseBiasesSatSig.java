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

public class CodePhaseBiasesSatSig extends SBPStruct {

    /**
     * Satellite ID. Similar to either RTCM DF068 (GPS), DF252 (Galileo), or DF488 (BDS) depending
     * on the constellation.
     */
    public int sat_id;

    /**
     * Signal and Tracking Mode Identifier. Similar to either RTCM DF380 (GPS), DF382 (Galileo) or
     * DF467 (BDS) depending on the constellation.
     */
    public int signal_id;

    /** Code Bias Mean. Range: 0-1.275 m */
    public int code_bias_bound_mu;

    /** Code Bias Standard Deviation. Range: 0-1.275 m */
    public int code_bias_bound_sig;

    /** Phase Bias Mean. Range: 0-1.275 m */
    public int phase_bias_bound_mu;

    /** Phase Bias Standard Deviation. Range: 0-1.275 m */
    public int phase_bias_bound_sig;

    public CodePhaseBiasesSatSig() {}

    @Override
    public CodePhaseBiasesSatSig parse(SBPMessage.Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        sat_id = parser.getU8();
        signal_id = parser.getU8();
        code_bias_bound_mu = parser.getU8();
        code_bias_bound_sig = parser.getU8();
        phase_bias_bound_mu = parser.getU8();
        phase_bias_bound_sig = parser.getU8();
        return this;
    }

    @Override
    public void build(SBPMessage.Builder builder) {
        /* Build fields into binary */
        builder.putU8(sat_id);
        builder.putU8(signal_id);
        builder.putU8(code_bias_bound_mu);
        builder.putU8(code_bias_bound_sig);
        builder.putU8(phase_bias_bound_mu);
        builder.putU8(phase_bias_bound_sig);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = new JSONObject();
        obj.put("sat_id", sat_id);
        obj.put("signal_id", signal_id);
        obj.put("code_bias_bound_mu", code_bias_bound_mu);
        obj.put("code_bias_bound_sig", code_bias_bound_sig);
        obj.put("phase_bias_bound_mu", phase_bias_bound_mu);
        obj.put("phase_bias_bound_sig", phase_bias_bound_sig);
        return obj;
    }
}
