/* Copyright (C) 2015-2022 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */
package com.swiftnav.sbp.tracking;

// This file was auto-generated from yaml/swiftnav/sbp/tracking.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPStruct;
import com.swiftnav.sbp.gnss.*;
import org.json.JSONObject;

public class TrackingChannelCorrelation extends SBPStruct {

    /** In-phase correlation */
    public int I;

    /** Quadrature correlation */
    public int Q;

    public TrackingChannelCorrelation() {}

    @Override
    public TrackingChannelCorrelation parse(SBPMessage.Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        I = parser.getS16();
        Q = parser.getS16();
        return this;
    }

    @Override
    public void build(SBPMessage.Builder builder) {
        /* Build fields into binary */
        builder.putS16(I);
        builder.putS16(Q);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = new JSONObject();
        obj.put("I", I);
        obj.put("Q", Q);
        return obj;
    }
}
