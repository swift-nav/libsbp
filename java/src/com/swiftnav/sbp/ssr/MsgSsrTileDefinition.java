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
import com.swiftnav.sbp.gnss.*;
import java.math.BigInteger;
import org.json.JSONObject;

/**
 * SBP class for message MSG_SSR_TILE_DEFINITION (0x05F6).
 *
 * <p>You can have MSG_SSR_TILE_DEFINITION inherent its fields directly from an inherited SBP
 * object, or construct it inline using a dict of its fields.
 *
 * <p>Provides the correction point coordinates for the atmospheric correction values in the
 * MSG_SSR_STEC_CORRECTION and MSG_SSR_GRIDDED_CORRECTION messages.
 *
 * <p>Based on ETSI TS 137 355 V16.1.0 (LTE Positioning Protocol) information element
 * GNSS-SSR-CorrectionPoints. SBP only supports gridded arrays of correction points, not lists of
 * points.
 */
public class MsgSsrTileDefinition extends SBPMessage {
    public static final int TYPE = 0x05F6;

    /** Unique identifier of the tile set this tile belongs to. */
    public int tile_set_id;

    /**
     * Unique identifier of this tile in the tile set. See GNSS-SSR-ArrayOfCorrectionPoints field
     * correctionPointSetID.
     */
    public int tile_id;

    /**
     * North-West corner correction point latitude.
     *
     * <p>The relation between the latitude X in the range [-90, 90] and the coded number N is:
     *
     * <p>N = floor((X / 90) * 2^14)
     *
     * <p>See GNSS-SSR-ArrayOfCorrectionPoints field referencePointLatitude.
     */
    public int corner_nw_lat;

    /**
     * North-West corner correction point longitude.
     *
     * <p>The relation between the longitude X in the range [-180, 180] and the coded number N is:
     *
     * <p>N = floor((X / 180) * 2^15)
     *
     * <p>See GNSS-SSR-ArrayOfCorrectionPoints field referencePointLongitude.
     */
    public int corner_nw_lon;

    /**
     * Spacing of the correction points in the latitude direction.
     *
     * <p>See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLatitude.
     */
    public int spacing_lat;

    /**
     * Spacing of the correction points in the longitude direction.
     *
     * <p>See GNSS-SSR-ArrayOfCorrectionPoints field stepOfLongitude.
     */
    public int spacing_lon;

    /**
     * Number of steps in the latitude direction.
     *
     * <p>See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLatitude.
     */
    public int rows;

    /**
     * Number of steps in the longitude direction.
     *
     * <p>See GNSS-SSR-ArrayOfCorrectionPoints field numberOfStepsLongitude.
     */
    public int cols;

    /**
     * Specifies the availability of correction data at the correction points in the array.
     *
     * <p>If a specific bit is enabled (set to 1), the correction is not available. Only the first
     * rows * cols bits are used, the remainder are set to 0. If there are more then 64 correction
     * points the remaining corrections are always available.
     *
     * <p>Starting with the northwest corner of the array (top left on a north oriented map) the
     * correction points are enumerated with row precedence - first row west to east, second row
     * west to east, until last row west to east - ending with the southeast corner of the array.
     *
     * <p>See GNSS-SSR-ArrayOfCorrectionPoints field bitmaskOfGrids but note the definition of the
     * bits is inverted.
     */
    public BigInteger bitmask;

    public MsgSsrTileDefinition(int sender) {
        super(sender, TYPE);
    }

    public MsgSsrTileDefinition() {
        super(TYPE);
    }

    public MsgSsrTileDefinition(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type == TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        tile_set_id = parser.getU16();
        tile_id = parser.getU16();
        corner_nw_lat = parser.getS16();
        corner_nw_lon = parser.getS16();
        spacing_lat = parser.getU16();
        spacing_lon = parser.getU16();
        rows = parser.getU16();
        cols = parser.getU16();
        bitmask = parser.getU64();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU16(tile_set_id);
        builder.putU16(tile_id);
        builder.putS16(corner_nw_lat);
        builder.putS16(corner_nw_lon);
        builder.putU16(spacing_lat);
        builder.putU16(spacing_lon);
        builder.putU16(rows);
        builder.putU16(cols);
        builder.putU64(bitmask);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("tile_set_id", tile_set_id);
        obj.put("tile_id", tile_id);
        obj.put("corner_nw_lat", corner_nw_lat);
        obj.put("corner_nw_lon", corner_nw_lon);
        obj.put("spacing_lat", spacing_lat);
        obj.put("spacing_lon", spacing_lon);
        obj.put("rows", rows);
        obj.put("cols", cols);
        obj.put("bitmask", bitmask);
        return obj;
    }
}
