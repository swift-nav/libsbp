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

public class MsgSsrOrbitClockBounds extends SBPMessage {
    public static final int TYPE = 0x05DE;

    /** Header of a bounds message. */
    public BoundsHeader header;

    /** IOD of the SSR bound. */
    public int ssr_iod;

    /** Constellation ID to which the SVs belong. */
    public int const_id;

    /** Number of satellites. */
    public int n_sats;

    /** Orbit and Clock Bounds per Satellite */
    public OrbitClockBound[] orbit_clock_bounds;

    public MsgSsrOrbitClockBounds(int sender) {
        super(sender, TYPE);
    }

    public MsgSsrOrbitClockBounds() {
        super(TYPE);
    }

    public MsgSsrOrbitClockBounds(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type == TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        header = new BoundsHeader().parse(parser);
        ssr_iod = parser.getU8();
        const_id = parser.getU8();
        n_sats = parser.getU8();
        orbit_clock_bounds = parser.getArray(OrbitClockBound.class);
    }

    @Override
    protected void build(Builder builder) {
        header.build(builder);
        builder.putU8(ssr_iod);
        builder.putU8(const_id);
        builder.putU8(n_sats);
        builder.putArray(orbit_clock_bounds);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("header", header.toJSON());
        obj.put("ssr_iod", ssr_iod);
        obj.put("const_id", const_id);
        obj.put("n_sats", n_sats);
        obj.put("orbit_clock_bounds", SBPStruct.toJSONArray(orbit_clock_bounds));
        return obj;
    }
}
