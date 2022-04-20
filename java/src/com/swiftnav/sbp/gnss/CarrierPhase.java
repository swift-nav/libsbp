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
package com.swiftnav.sbp.gnss;

// This file was auto-generated from yaml/swiftnav/sbp/gnss.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPStruct;
import org.json.JSONObject;

public class CarrierPhase extends SBPStruct {

    /** Carrier phase whole cycles */
    public int i;

    /** Carrier phase fractional part */
    public int f;

    public CarrierPhase() {}

    @Override
    public CarrierPhase parse(SBPMessage.Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        i = parser.getS32();
        f = parser.getU8();
        return this;
    }

    @Override
    public void build(SBPMessage.Builder builder) {
        /* Build fields into binary */
        builder.putS32(i);
        builder.putU8(f);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = new JSONObject();
        obj.put("i", i);
        obj.put("f", f);
        return obj;
    }
}
