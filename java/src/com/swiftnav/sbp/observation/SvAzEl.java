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

package com.swiftnav.sbp.observation;

import java.math.BigInteger;

import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPStruct;
import com.swiftnav.sbp.gnss.*;

import org.json.JSONObject;
import org.json.JSONArray;
import com.swiftnav.sbp.SBPStruct;

public class SvAzEl extends SBPStruct {
    
    /** GNSS signal identifier */
    public GnssSignal sid;
    
    /** Azimuth angle (range 0..179) */
    public int az;
    
    /** Elevation angle (range -90..90) */
    public int el;
    

    public SvAzEl () {}

    @Override
    public SvAzEl parse(SBPMessage.Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        sid = new GnssSignal().parse(parser);
        az = parser.getU8();
        el = parser.getS8();
        return this;
    }

    @Override
    public void build(SBPMessage.Builder builder) {
        /* Build fields into binary */
        sid.build(builder);
        builder.putU8(az);
        builder.putS8(el);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = new JSONObject();
        obj.put("sid", sid.toJSON());
        obj.put("az", az);
        obj.put("el", el);
        return obj;
    }
}