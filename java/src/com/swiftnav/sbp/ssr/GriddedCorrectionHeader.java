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

public class GriddedCorrectionHeader extends SBPStruct {
    
    /** GNSS time of the STEC data */
    public GPSTime time;
    
    /** Number of messages in the dataset */
    public int num_msgs;
    
    /** Position of this message in the dataset */
    public int seq_num;
    
    /** update interval in seconds */
    public int ssr_update_interval;
    
    /** range 0 - 15 */
    public int iod_ssr;
    
    /** troposphere quality indicator */
    public int tropo_quality;
    

    public GriddedCorrectionHeader () {}

    @Override
    public GriddedCorrectionHeader parse(SBPMessage.Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        time = new GPSTime().parse(parser);
        num_msgs = parser.getU16();
        seq_num = parser.getU16();
        ssr_update_interval = parser.getU16();
        iod_ssr = parser.getU8();
        tropo_quality = parser.getU8();
        return this;
    }

    @Override
    public void build(SBPMessage.Builder builder) {
        /* Build fields into binary */
        time.build(builder);
        builder.putU16(num_msgs);
        builder.putU16(seq_num);
        builder.putU16(ssr_update_interval);
        builder.putU8(iod_ssr);
        builder.putU8(tropo_quality);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = new JSONObject();
        obj.put("time", time.toJSON());
        obj.put("num_msgs", num_msgs);
        obj.put("seq_num", seq_num);
        obj.put("ssr_update_interval", ssr_update_interval);
        obj.put("iod_ssr", iod_ssr);
        obj.put("tropo_quality", tropo_quality);
        return obj;
    }
}