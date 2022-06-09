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
package com.swiftnav.sbp.navigation;

// This file was auto-generated from yaml/swiftnav/sbp/navigation.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import org.json.JSONArray;
import org.json.JSONObject;

/**
 * SBP class for message MSG_UTC_LEAP_SECOND (0x023A).
 *
 * <p>You can have MSG_UTC_LEAP_SECOND inherent its fields directly from an inherited SBP object, or
 * construct it inline using a dict of its fields.
 *
 * <p>Emulates the GPS CNAV message, reserving bytes for future broadcast of the drift model
 * parameters.
 */
public class MsgUtcLeapSecond extends SBPMessage {
    public static final int TYPE = 0x023A;

    public int[] stub;

    public MsgUtcLeapSecond(int sender) {
        super(sender, TYPE);
    }

    public MsgUtcLeapSecond() {
        super(TYPE);
    }

    public MsgUtcLeapSecond(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type == TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        stub = parser.getArrayofU8();
    }

    @Override
    protected void build(Builder builder) {
        builder.putArrayofU8(stub);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("stub", new JSONArray(stub));
        return obj;
    }
}
