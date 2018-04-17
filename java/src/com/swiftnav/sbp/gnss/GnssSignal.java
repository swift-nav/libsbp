/*
 * Copyright (C) 2015-2018 Swift Navigation Inc.
 * Contact: Swift Navigation <dev@swiftnav.com>
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

package com.swiftnav.sbp.gnss;

import java.math.BigInteger;

import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPStruct;

import org.json.JSONObject;
import org.json.JSONArray;
import com.swiftnav.sbp.SBPStruct;

public class GnssSignal extends SBPStruct {
    
    /** Constellation-specific satellite identifier. This field for Glonass can  
either be (100+FCN) where FCN is in [-7,+6] or 
the Slot ID in [1,28]
 */
    public int sat;
    
    /** Signal constellation, band and code */
    public int code;
    

    public GnssSignal () {}

    @Override
    public GnssSignal parse(SBPMessage.Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        sat = parser.getU8();
        code = parser.getU8();
        return this;
    }

    @Override
    public void build(SBPMessage.Builder builder) {
        /* Build fields into binary */
        builder.putU8(sat);
        builder.putU8(code);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = new JSONObject();
        obj.put("sat", sat);
        obj.put("code", code);
        return obj;
    }
}