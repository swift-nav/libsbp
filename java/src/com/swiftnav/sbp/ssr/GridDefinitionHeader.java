/*
 * Copyright (C) 2015-2018 Swift Navigation Inc.
 * Contact: Swift Navigation <dev@swiftnav.com>
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

package com.swiftnav.sbp.ssr;

import java.math.BigInteger;

import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPStruct;
import com.swiftnav.sbp.gnss.*;

import org.json.JSONObject;
import org.json.JSONArray;
import com.swiftnav.sbp.SBPStruct;

public class GridDefinitionHeader extends SBPStruct {
    
    /** number of rows of points (lattitude) */
    public int rows;
    
    /** number of columns of points (longitude) */
    public int cols;
    
    /** spacing between lat corrction points */
    public int spacing_lat;
    
    /** spacing between lon correction points */
    public int spacing_lon;
    
    /** northwest corner lattidue */
    public int corner_nw_lat;
    
    /** northwest corner longtitude */
    public int corner_nw_lon;
    
    /** Indicates grid IDs are part of the same generation set */
    public int tile_set_id;
    
    /** Unique (within a network) identifer for the tile/grid */
    public int tile_id;
    
    /** Number of messages in the dataset */
    public int num_msgs;
    
    /** Postion of this message in the dataset */
    public int seq_num;
    

    public GridDefinitionHeader () {}

    @Override
    public GridDefinitionHeader parse(SBPMessage.Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        rows = parser.getU16();
        cols = parser.getU16();
        spacing_lat = parser.getS32();
        spacing_lon = parser.getS32();
        corner_nw_lat = parser.getS32();
        corner_nw_lon = parser.getS32();
        tile_set_id = parser.getU8();
        tile_id = parser.getU16();
        num_msgs = parser.getU8();
        seq_num = parser.getU8();
        return this;
    }

    @Override
    public void build(SBPMessage.Builder builder) {
        /* Build fields into binary */
        builder.putU16(rows);
        builder.putU16(cols);
        builder.putS32(spacing_lat);
        builder.putS32(spacing_lon);
        builder.putS32(corner_nw_lat);
        builder.putS32(corner_nw_lon);
        builder.putU8(tile_set_id);
        builder.putU16(tile_id);
        builder.putU8(num_msgs);
        builder.putU8(seq_num);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = new JSONObject();
        obj.put("rows", rows);
        obj.put("cols", cols);
        obj.put("spacing_lat", spacing_lat);
        obj.put("spacing_lon", spacing_lon);
        obj.put("corner_nw_lat", corner_nw_lat);
        obj.put("corner_nw_lon", corner_nw_lon);
        obj.put("tile_set_id", tile_set_id);
        obj.put("tile_id", tile_id);
        obj.put("num_msgs", num_msgs);
        obj.put("seq_num", seq_num);
        return obj;
    }
}