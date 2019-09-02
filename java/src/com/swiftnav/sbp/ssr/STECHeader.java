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

public class STECHeader extends SBPStruct {
    
    /** GNSS reference time of the correction */
    public GPSTimeSec time;
    
    /** Number of messages in the dataset */
    public int num_msgs;
    
    /** Position of this message in the dataset */
    public int seq_num;
    
    /** Update interval between consecutive corrections. Encoded
following RTCM DF391 specification.
 */
    public int update_interval;
    
    /** IOD of the SSR atmospheric correction
 */
    public int iod_atmo;
    

    public STECHeader () {}

    @Override
    public STECHeader parse(SBPMessage.Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        time = new GPSTimeSec().parse(parser);
        num_msgs = parser.getU8();
        seq_num = parser.getU8();
        update_interval = parser.getU8();
        iod_atmo = parser.getU8();
        return this;
    }

    @Override
    public void build(SBPMessage.Builder builder) {
        /* Build fields into binary */
        time.build(builder);
        builder.putU8(num_msgs);
        builder.putU8(seq_num);
        builder.putU8(update_interval);
        builder.putU8(iod_atmo);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = new JSONObject();
        obj.put("time", time.toJSON());
        obj.put("num_msgs", num_msgs);
        obj.put("seq_num", seq_num);
        obj.put("update_interval", update_interval);
        obj.put("iod_atmo", iod_atmo);
        return obj;
    }
}