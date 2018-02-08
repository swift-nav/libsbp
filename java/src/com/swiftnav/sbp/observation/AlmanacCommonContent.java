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

public class AlmanacCommonContent extends SBPStruct {
    
    /** GNSS signal identifier */
    public GnssSignal sid;
    
    /** Reference time of almanac */
    public GPSTimeSec toa;
    
    /** User Range Accuracy */
    public double ura;
    
    /** Curve fit interval */
    public long fit_interval;
    
    /** Status of almanac, 1 = valid, 0 = invalid */
    public int valid;
    
    /** Satellite health status for GPS:
  - bits 5-7: NAV data health status. See IS-GPS-200H
    Table 20-VII: NAV Data Health Indications.
  - bits 0-4: Signal health status. See IS-GPS-200H
    Table 20-VIII. Codes for Health of SV Signal
    Components.
Satellite health status for GLO:
  See GLO ICD 5.1 table 5.1 for details
  - bit 0: C(n), "unhealthy" flag that is transmitted within
    non-immediate data and indicates overall constellation status
    at the moment of almanac uploading.
    '0' indicates malfunction of n-satellite.
    '1' indicates that n-satellite is operational.
  - bit 1: Bn(ln), '0' indicates the satellite is operational
    and suitable for navigation.
 */
    public int health_bits;
    

    public AlmanacCommonContent () {}

    @Override
    public AlmanacCommonContent parse(SBPMessage.Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        sid = new GnssSignal().parse(parser);
        toa = new GPSTimeSec().parse(parser);
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
        toa.build(builder);
        builder.putDouble(ura);
        builder.putU32(fit_interval);
        builder.putU8(valid);
        builder.putU8(health_bits);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = new JSONObject();
        obj.put("sid", sid.toJSON());
        obj.put("toa", toa.toJSON());
        obj.put("ura", ura);
        obj.put("fit_interval", fit_interval);
        obj.put("valid", valid);
        obj.put("health_bits", health_bits);
        return obj;
    }
}