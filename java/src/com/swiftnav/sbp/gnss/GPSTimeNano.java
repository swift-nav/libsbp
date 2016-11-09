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

package com.swiftnav.sbp.gnss;

import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPStruct;

import org.json.JSONObject;
import org.json.JSONArray;
import com.swiftnav.sbp.SBPStruct;

public class GPSTimeNano extends SBPStruct {
    
    /** Milliseconds since start of GPS week */
    public long tow;
    
    /** Nanosecond residual of millisecond-rounded TOW (ranges
from -500000 to 500000)
 */
    public int ns;
    
    /** GPS week number */
    public int wn;
    

    public GPSTimeNano () {}

    @Override
    public GPSTimeNano parse(SBPMessage.Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        tow = parser.getU32();
        ns = parser.getS32();
        wn = parser.getU16();
        return this;
    }

    @Override
    public void build(SBPMessage.Builder builder) {
        /* Build fields into binary */
        builder.putU32(tow);
        builder.putS32(ns);
        builder.putU16(wn);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = new JSONObject();
        obj.put("tow", tow);
        obj.put("ns", ns);
        obj.put("wn", wn);
        return obj;
    }
}