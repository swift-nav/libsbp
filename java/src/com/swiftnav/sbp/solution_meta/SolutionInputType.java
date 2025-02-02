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
package com.swiftnav.sbp.solution_meta;

// This file was auto-generated from yaml/swiftnav/sbp/solution_meta.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPStruct;
import org.json.JSONObject;

public class SolutionInputType extends SBPStruct {

    /** The type of sensor */
    public int sensor_type;

    /** Refer to each InputType description */
    public int flags;

    public SolutionInputType() {}

    @Override
    public SolutionInputType parse(SBPMessage.Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        sensor_type = parser.getU8();
        flags = parser.getU8();
        return this;
    }

    @Override
    public void build(SBPMessage.Builder builder) {
        /* Build fields into binary */
        builder.putU8(sensor_type);
        builder.putU8(flags);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = new JSONObject();
        obj.put("sensor_type", sensor_type);
        obj.put("flags", flags);
        return obj;
    }
}
