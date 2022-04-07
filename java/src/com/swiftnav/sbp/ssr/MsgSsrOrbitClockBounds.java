/* Copyright (C) 2015-2021 Swift Navigation Inc.
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
    public static final int TYPE = 0x04D2;

    /** GNSS reference time of the bound */
    public GPSTimeSec time;

    /** Number of messages in the dataset */
    public int nb_msg_dataset;

    /** Position of this message in the dataset */
    public int id_msg_dataset;

    /** Update interval between consecutive bounds. Encoded following RTCM DF391 specification. */
    public int ssr_update_interval;

    /** IOD of the SSR bound. Encoded following RTCM DF413 specification. */
    public int ssr_iod;

    /** SSR Solution ID. Encoded following RTCM DF415 specification. */
    public int ssr_sol_id;

    /** Constellation ID to which the SVs belong. */
    public int const_id;

    /** Number of satellites. Encoded following RTCM DF387 specification. */
    public int nb_sat;

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
        time = new GPSTimeSec().parse(parser);
        nb_msg_dataset = parser.getU8();
        id_msg_dataset = parser.getU8();
        ssr_update_interval = parser.getU8();
        ssr_iod = parser.getU8();
        ssr_sol_id = parser.getU8();
        const_id = parser.getU8();
        nb_sat = parser.getU8();
        orbit_clock_bounds = parser.getArray(OrbitClockBound.class);
    }

    @Override
    protected void build(Builder builder) {
        time.build(builder);
        builder.putU8(nb_msg_dataset);
        builder.putU8(id_msg_dataset);
        builder.putU8(ssr_update_interval);
        builder.putU8(ssr_iod);
        builder.putU8(ssr_sol_id);
        builder.putU8(const_id);
        builder.putU8(nb_sat);
        builder.putArray(orbit_clock_bounds);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("time", time.toJSON());
        obj.put("nb_msg_dataset", nb_msg_dataset);
        obj.put("id_msg_dataset", id_msg_dataset);
        obj.put("ssr_update_interval", ssr_update_interval);
        obj.put("ssr_iod", ssr_iod);
        obj.put("ssr_sol_id", ssr_sol_id);
        obj.put("const_id", const_id);
        obj.put("nb_sat", nb_sat);
        obj.put("orbit_clock_bounds", SBPStruct.toJSONArray(orbit_clock_bounds));
        return obj;
    }
}
