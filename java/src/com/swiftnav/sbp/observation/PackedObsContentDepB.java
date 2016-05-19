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
import com.swiftnav.sbp.SBPStruct;

public class PackedObsContentDepB extends SBPStruct {
    
    /** Pseudorange observation */
    public long P;
    
    /** Carrier phase observation with opposite sign from typical convention. */
    public CarrierPhaseDepA L;
    
    /** Carrier-to-Noise density */
    public int cn0;
    
    /** Lock indicator. This value changes whenever a satellite
signal has lost and regained lock, indicating that the
carrier phase ambiguity may have changed.
 */
    public int lock;
    
    /** GNSS signal identifier */
    public GnssSignal sid;
    

    public PackedObsContentDepB () {}

    @Override
    public PackedObsContentDepB parse(SBPMessage.Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        P = parser.getU32();
        L = new CarrierPhaseDepA().parse(parser);
        cn0 = parser.getU8();
        lock = parser.getU16();
        sid = new GnssSignal().parse(parser);
        return this;
    }

    @Override
    public void build(SBPMessage.Builder builder) {
        /* Build fields into binary */
        builder.putU32(P);
        L.build(builder);
        builder.putU8(cn0);
        builder.putU16(lock);
        sid.build(builder);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = new JSONObject();
        obj.put("P", P);
        obj.put("L", L.toJSON());
        obj.put("cn0", cn0);
        obj.put("lock", lock);
        obj.put("sid", sid.toJSON());
        return obj;
    }
}