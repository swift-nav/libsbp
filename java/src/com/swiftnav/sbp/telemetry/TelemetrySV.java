/* Copyright (C) 2015-2022 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */
package com.swiftnav.sbp.telemetry;

// This file was auto-generated from yaml/swiftnav/sbp/telemetry.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPStruct;
import com.swiftnav.sbp.gnss.*;
import org.json.JSONObject;

public class TelemetrySV extends SBPStruct {

    /** Azimuth angle (range 0..179) */
    public int az;

    /** Elevation angle (range -90..90) */
    public int el;

    /** Observation availability at filter update */
    public int availability_flags;

    /** Pseudorange observation residual */
    public int pseudorange_residual;

    /** Carrier-phase or carrier-phase-derived observation residual */
    public int phase_residual;

    /** Reports if observation is marked as an outlier and is excluded from the update */
    public int outlier_flags;

    /** Ephemeris metadata */
    public int ephemeris_flags;

    /** Reserved */
    public int correction_flags;

    /** GNSS signal identifier (16 bit) */
    public GnssSignal sid;

    public TelemetrySV() {}

    @Override
    public TelemetrySV parse(SBPMessage.Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        az = parser.getU8();
        el = parser.getS8();
        availability_flags = parser.getU8();
        pseudorange_residual = parser.getS16();
        phase_residual = parser.getS16();
        outlier_flags = parser.getU8();
        ephemeris_flags = parser.getU8();
        correction_flags = parser.getU8();
        sid = new GnssSignal().parse(parser);
        return this;
    }

    @Override
    public void build(SBPMessage.Builder builder) {
        /* Build fields into binary */
        builder.putU8(az);
        builder.putS8(el);
        builder.putU8(availability_flags);
        builder.putS16(pseudorange_residual);
        builder.putS16(phase_residual);
        builder.putU8(outlier_flags);
        builder.putU8(ephemeris_flags);
        builder.putU8(correction_flags);
        sid.build(builder);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = new JSONObject();
        obj.put("az", az);
        obj.put("el", el);
        obj.put("availability_flags", availability_flags);
        obj.put("pseudorange_residual", pseudorange_residual);
        obj.put("phase_residual", phase_residual);
        obj.put("outlier_flags", outlier_flags);
        obj.put("ephemeris_flags", ephemeris_flags);
        obj.put("correction_flags", correction_flags);
        obj.put("sid", sid.toJSON());
        return obj;
    }
}
