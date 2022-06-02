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
import com.swiftnav.sbp.gnss.*;
import java.math.BigInteger;
import org.json.JSONObject;

public class MsgSsrOrbitClockBoundsDegradation extends SBPMessage {
    public static final int TYPE = 0x05DF;

    /** Header of a bounds message. */
    public BoundsHeader header;

    /** IOD of the SSR bound degradation parameter. */
    public int ssr_iod;

    /** Constellation ID to which the SVs belong. */
    public int const_id;

    /**
     * Satellite Bit Mask. Put 1 for each satellite where the following degradation parameters are
     * applicable, 0 otherwise. Encoded following RTCM DF394 specification.
     */
    public BigInteger sat_bitmask;

    /** Orbit and Clock Bounds Degradation Parameters */
    public OrbitClockBoundDegradation orbit_clock_bounds_degradation;

    public MsgSsrOrbitClockBoundsDegradation(int sender) {
        super(sender, TYPE);
    }

    public MsgSsrOrbitClockBoundsDegradation() {
        super(TYPE);
    }

    public MsgSsrOrbitClockBoundsDegradation(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type == TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        header = new BoundsHeader().parse(parser);
        ssr_iod = parser.getU8();
        const_id = parser.getU8();
        sat_bitmask = parser.getU64();
        orbit_clock_bounds_degradation = new OrbitClockBoundDegradation().parse(parser);
    }

    @Override
    protected void build(Builder builder) {
        header.build(builder);
        builder.putU8(ssr_iod);
        builder.putU8(const_id);
        builder.putU64(sat_bitmask);
        orbit_clock_bounds_degradation.build(builder);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("header", header.toJSON());
        obj.put("ssr_iod", ssr_iod);
        obj.put("const_id", const_id);
        obj.put("sat_bitmask", sat_bitmask);
        obj.put("orbit_clock_bounds_degradation", orbit_clock_bounds_degradation.toJSON());
        return obj;
    }
}
