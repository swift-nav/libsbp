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
package com.swiftnav.sbp.ssr;

// This file was auto-generated from yaml/swiftnav/sbp/ssr.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPStruct;
import com.swiftnav.sbp.gnss.*;
import org.json.JSONObject;

public class STECResidual extends SBPStruct {

    /** space vehicle identifier */
    public SvId sv_id;

    /** STEC residual */
    public int residual;

    /**
     * Standard deviation encoded using a similar method as RTCM DF389. The upper 3 bit are the
     * class, the lower 5 bits are the value. Standard deviation [TECU] = (3^class * (1 + value/16)
     * - 1) * 0.1
     */
    public int stddev;

    public STECResidual() {}

    @Override
    public STECResidual parse(SBPMessage.Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        sv_id = new SvId().parse(parser);
        residual = parser.getS16();
        stddev = parser.getU8();
        return this;
    }

    @Override
    public void build(SBPMessage.Builder builder) {
        /* Build fields into binary */
        sv_id.build(builder);
        builder.putS16(residual);
        builder.putU8(stddev);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = new JSONObject();
        obj.put("sv_id", sv_id.toJSON());
        obj.put("residual", residual);
        obj.put("stddev", stddev);
        return obj;
    }
}
