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
package com.swiftnav.sbp.ssr;

// This file was auto-generated from yaml/swiftnav/sbp/ssr.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPStruct;
import com.swiftnav.sbp.gnss.*;
import org.json.JSONObject;

public class MsgSsrSatelliteApc extends SBPMessage {
    public static final int TYPE = 0x0605;

    /** GNSS reference time of the correction */
    public GPSTimeSec time;

    /**
     * Update interval between consecutive corrections. Encoded following RTCM DF391 specification.
     */
    public int update_interval;

    /** SSR Solution ID. Similar to RTCM DF415. */
    public int sol_id;

    /**
     * IOD of the SSR correction. A change of Issue Of Data SSR is used to indicate a change in the
     * SSR generating configuration
     */
    public int iod_ssr;

    /** Satellite antenna phase center corrections */
    public SatelliteAPC[] apc;

    public MsgSsrSatelliteApc(int sender) {
        super(sender, TYPE);
    }

    public MsgSsrSatelliteApc() {
        super(TYPE);
    }

    public MsgSsrSatelliteApc(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        if (msg.type != TYPE)
            throw new SBPBinaryException(
                    "Type mismatch for MsgSsrSatelliteApc, expected 1541, actual " + msg.type);
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        time = new GPSTimeSec().parse(parser);
        update_interval = parser.getU8();
        sol_id = parser.getU8();
        iod_ssr = parser.getU8();
        apc = parser.getArray(SatelliteAPC.class);
    }

    @Override
    protected void build(Builder builder) {
        time.build(builder);
        builder.putU8(update_interval);
        builder.putU8(sol_id);
        builder.putU8(iod_ssr);
        builder.putArray(apc);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("time", time.toJSON());
        obj.put("update_interval", update_interval);
        obj.put("sol_id", sol_id);
        obj.put("iod_ssr", iod_ssr);
        obj.put("apc", SBPStruct.toJSONArray(apc));
        return obj;
    }

    @Override
    public String getFriendlyName() {
        return "SSR SATELLITE APC";
    }
}
