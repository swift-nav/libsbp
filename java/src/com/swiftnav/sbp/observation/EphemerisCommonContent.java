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

package com.swiftnav.sbp.observation;

import java.math.BigInteger;

import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPStruct;
import com.swiftnav.sbp.gnss.*;

import org.json.JSONObject;
import org.json.JSONArray;
import com.swiftnav.sbp.SBPStruct;

public class EphemerisCommonContent extends SBPStruct {
    
    /** GNSS signal identifier (16 bit) */
    public GnssSignal sid;
    
    /** Time of Ephemerides */
    public GPSTimeSec toe;
    
    /** User Range Accuracy */
    public double ura;
    
    /** Curve fit interval */
    public long fit_interval;
    
    /** Status of ephemeris, 1 = valid, 0 = invalid */
    public int valid;
    
    /** Satellite health status.
GPS: ICD-GPS-200, chapter 20.3.3.3.1.4
Others: 0 = valid, non-zero = invalid
 */
    public int health_bits;
    

    public EphemerisCommonContent () {}

    @Override
    public EphemerisCommonContent parse(SBPMessage.Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        sid = new GnssSignal().parse(parser);
        toe = new GPSTimeSec().parse(parser);
        ura = parser.getDouble();
        fit_interval = parser.getU32();
        valid = parser.getU8();
        health_bits = parser.getU8();
        return this;
    }

    @Override
    public void build(SBPMessage.Builder builder) {
        /* Build fields into binary */
        sid.build(builder);
        toe.build(builder);
        builder.putDouble(ura);
        builder.putU32(fit_interval);
        builder.putU8(valid);
        builder.putU8(health_bits);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = new JSONObject();
        obj.put("sid", sid.toJSON());
        obj.put("toe", toe.toJSON());
        obj.put("ura", ura);
        obj.put("fit_interval", fit_interval);
        obj.put("valid", valid);
        obj.put("health_bits", health_bits);
        return obj;
    }
}