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

public class OrbitClockBound extends SBPStruct {

    /**
     * Satellite ID. Similar to either RTCM DF068 (GPS), DF252 (Galileo), or DF488 (BDS) depending
     * on the constellation.
     */
    public int sat_id;

    /**
     * Mean Radial (range 0-55) i<=200, mean=0.0251i 200<i<=240, mean=5+0.5(i-200) i>240,
     * mean=25+2(i-240)
     */
    public int orb_radial_bound_mu;

    /**
     * Mean Along-Track (range 0-55) i<=200, mean=0.0251i 200<i<=240, mean=5+0.5(i-200) i>240,
     * mean=25+2(i-240)
     */
    public int orb_along_bound_mu;

    /**
     * Mean Cross-Track (range 0-55) i<=200, mean=0.0251i 200<i<=240, mean=5+0.5(i-200) i>240,
     * mean=25+2(i-240)
     */
    public int orb_cross_bound_mu;

    /**
     * Standard Deviation Radial (range 0-55) i<=200, mean=0.0251i 200<i<=240, mean=5+0.5(i-200)
     * i>240, mean=25+2(i-240)
     */
    public int orb_radial_bound_sig;

    /**
     * Standard Deviation Along-Track (range 0-55) i<=200, mean=0.0251i 200<i<=240,
     * mean=5+0.5(i-200) i>240, mean=25+2(i-240)
     */
    public int orb_along_bound_sig;

    /**
     * Standard Deviation Cross-Track (range 0-55) i<=200, mean=0.0251i 200<i<=240,
     * mean=5+0.5(i-200) i>240, mean=25+2(i-240)
     */
    public int orb_cross_bound_sig;

    /**
     * Clock Bound Mean (range 0-55) i<=200, mean=0.0251i 200<i<=240, mean=5+0.5(i-200) i>240,
     * mean=25+2(i-240)
     */
    public int clock_bound_mu;

    /**
     * Clock Bound Standard Deviation (range 0-55) i<=200, mean=0.0251i 200<i<=240,
     * mean=5+0.5(i-200) i>240, mean=25+2(i-240)
     */
    public int clock_bound_sig;

    public OrbitClockBound() {}

    @Override
    public OrbitClockBound parse(SBPMessage.Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        sat_id = parser.getU8();
        orb_radial_bound_mu = parser.getU8();
        orb_along_bound_mu = parser.getU8();
        orb_cross_bound_mu = parser.getU8();
        orb_radial_bound_sig = parser.getU8();
        orb_along_bound_sig = parser.getU8();
        orb_cross_bound_sig = parser.getU8();
        clock_bound_mu = parser.getU8();
        clock_bound_sig = parser.getU8();
        return this;
    }

    @Override
    public void build(SBPMessage.Builder builder) {
        /* Build fields into binary */
        builder.putU8(sat_id);
        builder.putU8(orb_radial_bound_mu);
        builder.putU8(orb_along_bound_mu);
        builder.putU8(orb_cross_bound_mu);
        builder.putU8(orb_radial_bound_sig);
        builder.putU8(orb_along_bound_sig);
        builder.putU8(orb_cross_bound_sig);
        builder.putU8(clock_bound_mu);
        builder.putU8(clock_bound_sig);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = new JSONObject();
        obj.put("sat_id", sat_id);
        obj.put("orb_radial_bound_mu", orb_radial_bound_mu);
        obj.put("orb_along_bound_mu", orb_along_bound_mu);
        obj.put("orb_cross_bound_mu", orb_cross_bound_mu);
        obj.put("orb_radial_bound_sig", orb_radial_bound_sig);
        obj.put("orb_along_bound_sig", orb_along_bound_sig);
        obj.put("orb_cross_bound_sig", orb_cross_bound_sig);
        obj.put("clock_bound_mu", clock_bound_mu);
        obj.put("clock_bound_sig", clock_bound_sig);
        return obj;
    }
}
