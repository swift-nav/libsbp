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
    
    /** region_size (deg) = 10 / region_size_inverse
0 is an invalid value.
 */
    public int region_size_inverse;
    
    /** grid height (deg) = grid idth (deg) = area_width / region_size
0 is an invalid value.
 */
    public int area_width;
    
    /** North-West corner latitdue (deg) = region_size * lat_nw_corner_enc - 90 */
    public int lat_nw_corner_enc;
    
    /** North-West corner longtitude (deg) = region_size * lon_nw_corner_enc - 180 */
    public int lon_nw_corner_enc;
    
    /** Number of messages in the dataset */
    public int num_msgs;
    
    /** Postion of this message in the dataset */
    public int seq_num;
    

    public GridDefinitionHeader () {}

    @Override
    public GridDefinitionHeader parse(SBPMessage.Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        region_size_inverse = parser.getU8();
        area_width = parser.getU16();
        lat_nw_corner_enc = parser.getU16();
        lon_nw_corner_enc = parser.getU16();
        num_msgs = parser.getU8();
        seq_num = parser.getU8();
        return this;
    }

    @Override
    public void build(SBPMessage.Builder builder) {
        /* Build fields into binary */
        builder.putU8(region_size_inverse);
        builder.putU16(area_width);
        builder.putU16(lat_nw_corner_enc);
        builder.putU16(lon_nw_corner_enc);
        builder.putU8(num_msgs);
        builder.putU8(seq_num);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = new JSONObject();
        obj.put("region_size_inverse", region_size_inverse);
        obj.put("area_width", area_width);
        obj.put("lat_nw_corner_enc", lat_nw_corner_enc);
        obj.put("lon_nw_corner_enc", lon_nw_corner_enc);
        obj.put("num_msgs", num_msgs);
        obj.put("seq_num", seq_num);
        return obj;
    }
}