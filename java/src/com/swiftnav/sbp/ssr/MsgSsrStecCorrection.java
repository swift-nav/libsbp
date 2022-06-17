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

public class MsgSsrStecCorrection extends SBPMessage {
    public static final int TYPE = 0x05FD;

    /** Header of a STEC correction with bounds message. */
    public BoundsHeader header;

    /** IOD of the SSR atmospheric correction */
    public int ssr_iod_atmo;

    /** Tile set ID */
    public int tile_set_id;

    /** Tile ID */
    public int tile_id;

    /** Number of satellites. */
    public int n_sats;

    /** Array of STEC polynomial coefficients for each space vehicle. */
    public STECSatElement[] stec_sat_list;

    public MsgSsrStecCorrection(int sender) {
        super(sender, TYPE);
    }

    public MsgSsrStecCorrection() {
        super(TYPE);
    }

    public MsgSsrStecCorrection(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type == TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        header = new BoundsHeader().parse(parser);
        ssr_iod_atmo = parser.getU8();
        tile_set_id = parser.getU16();
        tile_id = parser.getU16();
        n_sats = parser.getU8();
        stec_sat_list = parser.getArray(STECSatElement.class);
    }

    @Override
    protected void build(Builder builder) {
        header.build(builder);
        builder.putU8(ssr_iod_atmo);
        builder.putU16(tile_set_id);
        builder.putU16(tile_id);
        builder.putU8(n_sats);
        builder.putArray(stec_sat_list);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("header", header.toJSON());
        obj.put("ssr_iod_atmo", ssr_iod_atmo);
        obj.put("tile_set_id", tile_set_id);
        obj.put("tile_id", tile_id);
        obj.put("n_sats", n_sats);
        obj.put("stec_sat_list", SBPStruct.toJSONArray(stec_sat_list));
        return obj;
    }
}
