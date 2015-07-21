/*
 * Copyright (C) 2015 Swift Navigation Inc.
 * Contact: Gareth McMullin <gareth@swiftnav.com>
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */
package com.swiftnav.sbp;

import org.json.JSONArray;
import org.json.JSONObject;

import java.util.Arrays;

public abstract class SBPStruct {
    protected SBPStruct() {}
    protected abstract void build(SBPMessage.Builder builder);
    protected abstract <T> T parse(SBPMessage.Parser parser) throws SBPBinaryException;
    protected abstract JSONObject toJSON();

    public static JSONArray toJSONArray(SBPStruct[] structs) {
        JSONObject objs[] = new JSONObject[structs.length];
        for (int i = 0; i < structs.length; i++)
            objs[i] = structs[i].toJSON();
        return new JSONArray(Arrays.asList(objs));
    }
}
