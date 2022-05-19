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

public class OrbitClockBoundDegradation extends SBPStruct {

    /** Orbit Bound Mean Radial First derivative. Range: 0-0.255 m/s */
    public int orb_radial_bound_mu_dot;

    /** Orbit Bound Mean Along-Track First derivative. Range: 0-0.255 m/s */
    public int orb_along_bound_mu_dot;

    /** Orbit Bound Mean Cross-Track First derivative. Range: 0-0.255 m/s */
    public int orb_cross_bound_mu_dot;

    /** Orbit Bound Standard Deviation Radial First derivative. Range: 0-0.255 m/s */
    public int orb_radial_bound_sig_dot;

    /** Orbit Bound Standard Deviation Along-Track First derivative. Range: 0-0.255 m/s */
    public int orb_along_bound_sig_dot;

    /** Orbit Bound Standard Deviation Cross-Track First derivative. Range: 0-0.255 m/s */
    public int orb_cross_bound_sig_dot;

    /** Clock Bound Mean First derivative. Range: 0-0.255 m/s */
    public int clock_bound_mu_dot;

    /** Clock Bound Standard Deviation First derivative. Range: 0-0.255 m/s */
    public int clock_bound_sig_dot;

    public OrbitClockBoundDegradation() {}

    @Override
    public OrbitClockBoundDegradation parse(SBPMessage.Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        orb_radial_bound_mu_dot = parser.getU8();
        orb_along_bound_mu_dot = parser.getU8();
        orb_cross_bound_mu_dot = parser.getU8();
        orb_radial_bound_sig_dot = parser.getU8();
        orb_along_bound_sig_dot = parser.getU8();
        orb_cross_bound_sig_dot = parser.getU8();
        clock_bound_mu_dot = parser.getU8();
        clock_bound_sig_dot = parser.getU8();
        return this;
    }

    @Override
    public void build(SBPMessage.Builder builder) {
        /* Build fields into binary */
        builder.putU8(orb_radial_bound_mu_dot);
        builder.putU8(orb_along_bound_mu_dot);
        builder.putU8(orb_cross_bound_mu_dot);
        builder.putU8(orb_radial_bound_sig_dot);
        builder.putU8(orb_along_bound_sig_dot);
        builder.putU8(orb_cross_bound_sig_dot);
        builder.putU8(clock_bound_mu_dot);
        builder.putU8(clock_bound_sig_dot);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = new JSONObject();
        obj.put("orb_radial_bound_mu_dot", orb_radial_bound_mu_dot);
        obj.put("orb_along_bound_mu_dot", orb_along_bound_mu_dot);
        obj.put("orb_cross_bound_mu_dot", orb_cross_bound_mu_dot);
        obj.put("orb_radial_bound_sig_dot", orb_radial_bound_sig_dot);
        obj.put("orb_along_bound_sig_dot", orb_along_bound_sig_dot);
        obj.put("orb_cross_bound_sig_dot", orb_cross_bound_sig_dot);
        obj.put("clock_bound_mu_dot", clock_bound_mu_dot);
        obj.put("clock_bound_sig_dot", clock_bound_sig_dot);
        return obj;
    }
}
