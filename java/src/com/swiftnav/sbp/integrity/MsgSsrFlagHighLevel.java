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

/**
 * SBP class for message MSG_SSR_FLAG_HIGH_LEVEL (0x0BB9).
 *
 * <p>You can have MSG_SSR_FLAG_HIGH_LEVEL inherent its fields directly from an inherited SBP
 * object, or construct it inline using a dict of its fields.
 *
 * <p>Integrity monitoring flags for multiple aggregated elements. An element could be a satellite,
 * SSR grid point, or SSR tile. A group of aggregated elements being monitored for integrity could
 * refer to:
 *
 * <p>- Satellites in a particular {GPS, GAL, BDS} constellation.
 *
 * <p>- Satellites in the line-of-sight of a particular SSR tile.
 *
 * <p>- Satellites in the line-of-sight of a particular SSR grid point.
 *
 * <p>The integrity usage for a group of aggregated elements varies according to the integrity flag
 * of the satellites comprising that group.
 *
 * <p>SSR_INTEGRITY_USAGE_NOMINAL: All satellites received passed the integrity check and have flag
 * INTEGRITY_FLAG_OK.
 *
 * <p>SSR_INTEGRITY_USAGE_WARNING: A limited number of elements in the group failed the integrity
 * check. Refer to more granular integrity messages for details on the specific failing elements.
 *
 * <p>SSR_INTEGRITY_USAGE_ALERT: Most elements in the group failed the integrity check, do not use
 * for positioning.
 *
 * <p>SSR_INTEGRITY_USAGE_NOT_MONITORED: Unable to verify the integrity flag of elements in the
 * group.
 */
public class MsgSsrFlagHighLevel extends SBPMessage {
    public static final int TYPE = 0x0BB9;

    /** GNSS reference time of the observation used to generate the flag. */
    public GPSTimeSec obs_time;

    /** GNSS reference time of the correction associated to the flag. */
    public GPSTimeSec corr_time;

    /** SSR Solution ID. */
    public int ssr_sol_id;

    /** Unique identifier of the set this tile belongs to. */
    public int tile_set_id;

    /** Unique identifier of this tile in the tile set. */
    public int tile_id;

    /** Chain and type of flag. */
    public int chain_id;

    /** Use GPS satellites. */
    public int use_gps_sat;

    /** Use GAL satellites. */
    public int use_gal_sat;

    /** Use BDS satellites. */
    public int use_bds_sat;

    /** Reserved */
    public int[] reserved;

    /** Use tropo grid points. */
    public int use_tropo_grid_points;

    /** Use iono grid points. */
    public int use_iono_grid_points;

    /** Use iono tile satellite LoS. */
    public int use_iono_tile_sat_los;

    /** Use iono grid point satellite LoS. */
    public int use_iono_grid_point_sat_los;

    public MsgSsrFlagHighLevel(int sender) {
        super(sender, TYPE);
    }

    public MsgSsrFlagHighLevel() {
        super(TYPE);
    }

    public MsgSsrFlagHighLevel(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type == TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        obs_time = new GPSTimeSec().parse(parser);
        corr_time = new GPSTimeSec().parse(parser);
        ssr_sol_id = parser.getU8();
        tile_set_id = parser.getU16();
        tile_id = parser.getU16();
        chain_id = parser.getU8();
        use_gps_sat = parser.getU8();
        use_gal_sat = parser.getU8();
        use_bds_sat = parser.getU8();
        reserved = parser.getArrayofU8(6);
        use_tropo_grid_points = parser.getU8();
        use_iono_grid_points = parser.getU8();
        use_iono_tile_sat_los = parser.getU8();
        use_iono_grid_point_sat_los = parser.getU8();
    }

    @Override
    protected void build(Builder builder) {
        obs_time.build(builder);
        corr_time.build(builder);
        builder.putU8(ssr_sol_id);
        builder.putU16(tile_set_id);
        builder.putU16(tile_id);
        builder.putU8(chain_id);
        builder.putU8(use_gps_sat);
        builder.putU8(use_gal_sat);
        builder.putU8(use_bds_sat);
        builder.putArrayofU8(reserved, 6);
        builder.putU8(use_tropo_grid_points);
        builder.putU8(use_iono_grid_points);
        builder.putU8(use_iono_tile_sat_los);
        builder.putU8(use_iono_grid_point_sat_los);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("obs_time", obs_time.toJSON());
        obj.put("corr_time", corr_time.toJSON());
        obj.put("ssr_sol_id", ssr_sol_id);
        obj.put("tile_set_id", tile_set_id);
        obj.put("tile_id", tile_id);
        obj.put("chain_id", chain_id);
        obj.put("use_gps_sat", use_gps_sat);
        obj.put("use_gal_sat", use_gal_sat);
        obj.put("use_bds_sat", use_bds_sat);
        obj.put("reserved", new JSONArray(reserved));
        obj.put("use_tropo_grid_points", use_tropo_grid_points);
        obj.put("use_iono_grid_points", use_iono_grid_points);
        obj.put("use_iono_tile_sat_los", use_iono_tile_sat_los);
        obj.put("use_iono_grid_point_sat_los", use_iono_grid_point_sat_los);
        return obj;
    }
}
