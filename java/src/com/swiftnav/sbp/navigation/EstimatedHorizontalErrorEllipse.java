/* Copyright (C) 2015-2021 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */
package com.swiftnav.sbp.navigation;

// This file was auto-generated from yaml/swiftnav/sbp/navigation.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPStruct;
import org.json.JSONObject;

public class EstimatedHorizontalErrorEllipse extends SBPStruct {

    /**
     * The semi major axis of the estimated horizontal error ellipse at the user- configured
     * confidence level; zero implies invalid.
     */
    public float semi_major;

    /**
     * The semi minor axis of the estimated horizontal error ellipse at the user- configured
     * confidence level; zero implies invalid.
     */
    public float semi_minor;

    /**
     * The orientation of the semi major axis of the estimated horizontal error ellipse with respect
     * to North.
     */
    public float orientation;

    public EstimatedHorizontalErrorEllipse() {}

    @Override
    public EstimatedHorizontalErrorEllipse parse(SBPMessage.Parser parser)
            throws SBPBinaryException {
        /* Parse fields from binary */
        semi_major = parser.getFloat();
        semi_minor = parser.getFloat();
        orientation = parser.getFloat();
        return this;
    }

    @Override
    public void build(SBPMessage.Builder builder) {
        /* Build fields into binary */
        builder.putFloat(semi_major);
        builder.putFloat(semi_minor);
        builder.putFloat(orientation);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = new JSONObject();
        obj.put("semi_major", semi_major);
        obj.put("semi_minor", semi_minor);
        obj.put("orientation", orientation);
        return obj;
    }
}
