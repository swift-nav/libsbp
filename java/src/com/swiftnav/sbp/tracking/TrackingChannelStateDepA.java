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
package com.swiftnav.sbp.tracking;

// This file was auto-generated from yaml/swiftnav/sbp/tracking.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPStruct;
import com.swiftnav.sbp.gnss.*;
import org.json.JSONObject;

public class TrackingChannelStateDepA extends SBPStruct {

    /** Status of tracking channel */
    public int state;

    /** PRN-1 being tracked */
    public int prn;

    /** Carrier-to-noise density */
    public float cn0;

    public TrackingChannelStateDepA() {}

    @Override
    public TrackingChannelStateDepA parse(SBPMessage.Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        state = parser.getU8();
        prn = parser.getU8();
        cn0 = parser.getFloat();
        return this;
    }

    @Override
    public void build(SBPMessage.Builder builder) {
        /* Build fields into binary */
        builder.putU8(state);
        builder.putU8(prn);
        builder.putFloat(cn0);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = new JSONObject();
        obj.put("state", state);
        obj.put("prn", prn);
        obj.put("cn0", cn0);
        return obj;
    }
}
