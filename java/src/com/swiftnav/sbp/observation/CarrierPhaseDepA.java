/*
 * Copyright (C) 2015 Swift Navigation Inc.
 * Contact: Gareth McMullin <gareth@swiftnav.com>
 * Contact: Bhaskar Mookerji <mookerji@swiftnav.com>
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

package com.swiftnav.sbp.observation;

import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPStruct;
import com.swiftnav.sbp.gnss_signal.*;

import org.json.JSONObject;
import org.json.JSONArray;
import com.swiftnav.sbp.SBPStruct;

public class CarrierPhaseDepA extends SBPStruct {
    
    /** Carrier phase whole cycles */
    public int i;
    
    /** Carrier phase fractional part */
    public int f;
    

    public CarrierPhaseDepA () {}

    @Override
    public CarrierPhaseDepA parse(SBPMessage.Parser parser) throws SBPBinaryException {
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