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

public class STECSatElementIntegrity extends SBPStruct {

    /** STEC residuals (mean, stddev) */
    public STECResidual stec_residual;

    /** Error Bound Mean. See Note 1. */
    public int stec_bound_mu;

    /** Error Bound StDev. See Note 1. */
    public int stec_bound_sig;

    /** Error Bound Mean First derivative. */
    public int stec_bound_mu_dot;

    /** Error Bound StDev First derivative. */
    public int stec_bound_sig_dot;

    public STECSatElementIntegrity() {}

    @Override
    public STECSatElementIntegrity parse(SBPMessage.Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        stec_residual = new STECResidual().parse(parser);
        stec_bound_mu = parser.getU8();
        stec_bound_sig = parser.getU8();
        stec_bound_mu_dot = parser.getU8();
        stec_bound_sig_dot = parser.getU8();
        return this;
    }

    @Override
    public void build(SBPMessage.Builder builder) {
        /* Build fields into binary */
        stec_residual.build(builder);
        builder.putU8(stec_bound_mu);
        builder.putU8(stec_bound_sig);
        builder.putU8(stec_bound_mu_dot);
        builder.putU8(stec_bound_sig_dot);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = new JSONObject();
        obj.put("stec_residual", stec_residual.toJSON());
        obj.put("stec_bound_mu", stec_bound_mu);
        obj.put("stec_bound_sig", stec_bound_sig);
        obj.put("stec_bound_mu_dot", stec_bound_mu_dot);
        obj.put("stec_bound_sig_dot", stec_bound_sig_dot);
        return obj;
    }
}
