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

public class TroposphericDelayCorrection extends SBPStruct {

    /** Hydrostatic vertical delay. Add 2.3 m to get actual value. */
    public int hydro;

    /** Wet vertical delay. Add 0.252 m to get actual value. */
    public int wet;

    /** Modified DF389. class 3 MSB, value 5 LSB. stddev = (3^class * (1 + value/16) - 1) */
    public int stddev;

    public TroposphericDelayCorrection() {}

    @Override
    public TroposphericDelayCorrection parse(SBPMessage.Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        hydro = parser.getS16();
        wet = parser.getS8();
        stddev = parser.getU8();
        return this;
    }

    @Override
    public void build(SBPMessage.Builder builder) {
        /* Build fields into binary */
        builder.putS16(hydro);
        builder.putS8(wet);
        builder.putU8(stddev);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = new JSONObject();
        obj.put("hydro", hydro);
        obj.put("wet", wet);
        obj.put("stddev", stddev);
        return obj;
    }
}
