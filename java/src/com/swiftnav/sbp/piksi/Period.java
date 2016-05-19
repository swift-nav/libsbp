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

package com.swiftnav.sbp.piksi;

import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPStruct;
import com.swiftnav.sbp.gnss_signal.*;

import org.json.JSONObject;
import org.json.JSONArray;
import com.swiftnav.sbp.SBPStruct;

public class Period extends SBPStruct {
    
    /** Average period */
    public int avg;
    
    /** Minimum period */
    public int pmin;
    
    /** Maximum period */
    public int pmax;
    
    /** Smoothed estimate of the current period */
    public int current;
    

    public Period () {}

    @Override
    public Period parse(SBPMessage.Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        avg = parser.getS32();
        pmin = parser.getS32();
        pmax = parser.getS32();
        current = parser.getS32();
        return this;
    }

    @Override
    public void build(SBPMessage.Builder builder) {
        /* Build fields into binary */
        builder.putS32(avg);
        builder.putS32(pmin);
        builder.putS32(pmax);
        builder.putS32(current);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = new JSONObject();
        obj.put("avg", avg);
        obj.put("pmin", pmin);
        obj.put("pmax", pmax);
        obj.put("current", current);
        return obj;
    }
}