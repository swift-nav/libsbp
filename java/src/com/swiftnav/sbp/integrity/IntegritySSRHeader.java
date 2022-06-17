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
import com.swiftnav.sbp.SBPStruct;
import com.swiftnav.sbp.gnss.*;
import org.json.JSONObject;

public class IntegritySSRHeader extends SBPStruct {

    /** GNSS reference time of the observation used to generate the flag. */
    public GPSTimeSec obs_time;

    /** Number of messages in the dataset */
    public int num_msgs;

    /** Position of this message in the dataset */
    public int seq_num;

    /** SSR Solution ID. */
    public int ssr_sol_id;

    /** Unique identifier of the set this tile belongs to. */
    public int tile_set_id;

    /** Unique identifier of this tile in the tile set. */
    public int tile_id;

    /** Chain and type of flag. */
    public int chain_id;

    public IntegritySSRHeader() {}

    @Override
    public IntegritySSRHeader parse(SBPMessage.Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        obs_time = new GPSTimeSec().parse(parser);
        num_msgs = parser.getU8();
        seq_num = parser.getU8();
        ssr_sol_id = parser.getU8();
        tile_set_id = parser.getU16();
        tile_id = parser.getU16();
        chain_id = parser.getU8();
        return this;
    }

    @Override
    public void build(SBPMessage.Builder builder) {
        /* Build fields into binary */
        obs_time.build(builder);
        builder.putU8(num_msgs);
        builder.putU8(seq_num);
        builder.putU8(ssr_sol_id);
        builder.putU16(tile_set_id);
        builder.putU16(tile_id);
        builder.putU8(chain_id);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = new JSONObject();
        obj.put("obs_time", obs_time.toJSON());
        obj.put("num_msgs", num_msgs);
        obj.put("seq_num", seq_num);
        obj.put("ssr_sol_id", ssr_sol_id);
        obj.put("tile_set_id", tile_set_id);
        obj.put("tile_id", tile_id);
        obj.put("chain_id", chain_id);
        return obj;
    }
}
