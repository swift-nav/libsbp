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

package com.swiftnav.sbp.gnss_signal;

import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPStruct;

import org.json.JSONObject;
import org.json.JSONArray;
import com.swiftnav.sbp.SBPStruct;

public class GnssSignal extends SBPStruct {
    
    /** Constellation-specific satellite identifier */
    public int sat;
    
    /** Signal constellation, band and code */
    public int code;
    
    /** Reserved */
    public int reserved;
    

    public GnssSignal () {}

    @Override
    public GnssSignal parse(SBPMessage.Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        sat = parser.getU16();
        code = parser.getU8();
        reserved = parser.getU8();
        return this;
    }

    @Override
    public void build(SBPMessage.Builder builder) {
        /* Build fields into binary */
        builder.putU16(sat);
        builder.putU8(code);
        builder.putU8(reserved);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = new JSONObject();
        obj.put("sat", sat);
        obj.put("code", code);
        obj.put("reserved", reserved);
        return obj;
    }
}