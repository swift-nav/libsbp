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
package com.swiftnav.sbp.observation;

// This file was auto-generated from yaml/swiftnav/sbp/observation.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPStruct;
import com.swiftnav.sbp.gnss.*;
import org.json.JSONObject;

public class PackedObsContentDepB extends SBPStruct {

    /** Pseudorange observation */
    public long P;

    /** Carrier phase observation with opposite sign from typical convention. */
    public CarrierPhaseDepA L;

    /** Carrier-to-Noise density */
    public int cn0;

    /**
     * Lock indicator. This value changes whenever a satellite signal has lost and regained lock,
     * indicating that the carrier phase ambiguity may have changed.
     */
    public int lock;

    /** GNSS signal identifier */
    public GnssSignalDep sid;

    public PackedObsContentDepB() {}

    @Override
    public PackedObsContentDepB parse(SBPMessage.Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        P = parser.getU32();
        L = new CarrierPhaseDepA().parse(parser);
        cn0 = parser.getU8();
        lock = parser.getU16();
        sid = new GnssSignalDep().parse(parser);
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
