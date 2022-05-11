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
package com.swiftnav.sbp.integrity;

// This file was auto-generated from yaml/swiftnav/sbp/integrity.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.gnss.*;
import org.json.JSONArray;
import org.json.JSONObject;

public class MsgSsrFlagSatellites extends SBPMessage {
    public static final int TYPE = 0x0BBD;

    /** GNSS reference time of the observation used to generate the flag. */
    public GPSTimeSec obs_time;

    /** Number of messages in the dataset */
    public int num_msgs;

    /** Position of this message in the dataset */
    public int seq_num;

    /** SSR Solution ID. */
    public int ssr_sol_id;

    /** Chain and type of flag. */
    public int chain_id;

    /** Constellation ID. */
    public int const_id;

    /** Number of faulty satellites. */
    public int n_faulty_sats;

    /** List of faulty satellites. */
    public int[] faulty_sats;

    public MsgSsrFlagSatellites(int sender) {
        super(sender, TYPE);
    }

    public MsgSsrFlagSatellites() {
        super(TYPE);
    }

    public MsgSsrFlagSatellites(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type == TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        obs_time = new GPSTimeSec().parse(parser);
        num_msgs = parser.getU8();
        seq_num = parser.getU8();
        ssr_sol_id = parser.getU8();
        chain_id = parser.getU8();
        const_id = parser.getU8();
        n_faulty_sats = parser.getU8();
        faulty_sats = parser.getArrayofU8();
    }

    @Override
    protected void build(Builder builder) {
        obs_time.build(builder);
        builder.putU8(num_msgs);
        builder.putU8(seq_num);
        builder.putU8(ssr_sol_id);
        builder.putU8(chain_id);
        builder.putU8(const_id);
        builder.putU8(n_faulty_sats);
        builder.putArrayofU8(faulty_sats);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("obs_time", obs_time.toJSON());
        obj.put("num_msgs", num_msgs);
        obj.put("seq_num", seq_num);
        obj.put("ssr_sol_id", ssr_sol_id);
        obj.put("chain_id", chain_id);
        obj.put("const_id", const_id);
        obj.put("n_faulty_sats", n_faulty_sats);
        obj.put("faulty_sats", new JSONArray(faulty_sats));
        return obj;
    }
}
