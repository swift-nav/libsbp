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

package com.swiftnav.sbp.signal;

import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPStruct;

import org.json.JSONObject;
import org.json.JSONArray;
import com.swiftnav.sbp.SBPStruct;

public class SBPSignal extends SBPStruct {
    
    /** Constellation-specific satellite identifier */
    public int sat;
    
    /** Signal band */
    public int band;
    
    /** Constellation to which the satellite belongs */
    public int constellation;
    

    public SBPSignal () {}

    @Override
    public SBPSignal parse(SBPMessage.Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        sat = parser.getU16();
        band = parser.getU8();
        constellation = parser.getU8();
        return this;
    }

    @Override
    public void build(SBPMessage.Builder builder) {
        /* Build fields into binary */
        builder.putU16(sat);
        builder.putU8(band);
        builder.putU8(constellation);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = new JSONObject();
        obj.put("sat", sat);
        obj.put("band", band);
        obj.put("constellation", constellation);
        return obj;
    }
}