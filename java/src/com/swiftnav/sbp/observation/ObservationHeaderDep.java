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

public class ObservationHeaderDep extends SBPStruct {

    /** GPS time of this observation */
    public GPSTimeDep t;

    /**
     * Total number of observations. First nibble is the size of the sequence (n), second nibble is
     * the zero-indexed counter (ith packet of n)
     */
    public int n_obs;

    public ObservationHeaderDep() {}

    @Override
    public ObservationHeaderDep parse(SBPMessage.Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        t = new GPSTimeDep().parse(parser);
        n_obs = parser.getU8();
        return this;
    }

    @Override
    public void build(SBPMessage.Builder builder) {
        /* Build fields into binary */
        t.build(builder);
        builder.putU8(n_obs);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = new JSONObject();
        obj.put("t", t.toJSON());
        obj.put("n_obs", n_obs);
        return obj;
    }
}
