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

package com.swiftnav.sbp.tracking;

import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPStruct;
import com.swiftnav.sbp.gnss_signal.*;

import org.json.JSONObject;
import org.json.JSONArray;
import com.swiftnav.sbp.SBPStruct;

public class TrackingChannelState extends SBPStruct {
    
    /** Status of tracking channel */
    public int state;
    
    /** GNSS signal being tracked */
    public GnssSignal sid;
    
    /** Carrier-to-noise density */
    public float cn0;
    

    public TrackingChannelState () {}

    @Override
    public TrackingChannelState parse(SBPMessage.Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        state = parser.getU8();
        sid = new GnssSignal().parse(parser);
        cn0 = parser.getFloat();
        return this;
    }

    @Override
    public void build(SBPMessage.Builder builder) {
        /* Build fields into binary */
        builder.putU8(state);
        sid.build(builder);
        builder.putFloat(cn0);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = new JSONObject();
        obj.put("state", state);
        obj.put("sid", sid.toJSON());
        obj.put("cn0", cn0);
        return obj;
    }
}