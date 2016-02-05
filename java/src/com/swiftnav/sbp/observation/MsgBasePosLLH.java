/*
 * Copyright (C) 2015 Swift Navigation Inc.
 * Contact: Gareth McMullin <gareth@swiftnav.com>
 * Contact: Bhaskar Mookerji <mookerji@swiftnav.com>
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

package com.swiftnav.sbp.observation;

import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPStruct;
import com.swiftnav.sbp.gnss_signal.*;

import org.json.JSONObject;
import org.json.JSONArray;


/** SBP class for message MSG_BASE_POS_LLH (0x0044).
 *
 * You can have MSG_BASE_POS_LLH inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
 * The base station position message is the position reported by
 * the base station itself. It is used for pseudo-absolute RTK
 * positioning, and is required to be a high-accuracy surveyed
 * location of the base station. Any error here will result in an
 * error in the pseudo-absolute position output. */

public class MsgBasePosLLH extends SBPMessage {
    public static final int TYPE = 0x0044;

    
    /** Latitude */
    public double lat;
    
    /** Longitude */
    public double lon;
    
    /** Height */
    public double height;
    

    public MsgBasePosLLH (int sender) { super(sender, TYPE); }
    public MsgBasePosLLH () { super(TYPE); }
    public MsgBasePosLLH (SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type != TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        lat = parser.getDouble();
        lon = parser.getDouble();
        height = parser.getDouble();
    }

    @Override
    protected void build(Builder builder) {
        builder.putDouble(lat);
        builder.putDouble(lon);
        builder.putDouble(height);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("lat", lat);
        obj.put("lon", lon);
        obj.put("height", height);
        return obj;
    }
}