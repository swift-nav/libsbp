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
package com.swiftnav.sbp.user;

// This file was auto-generated from yaml/swiftnav/sbp/user.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import org.json.JSONArray;
import org.json.JSONObject;

/**
 * SBP class for message MSG_USER_DATA (0x0800).
 *
 * <p>You can have MSG_USER_DATA inherent its fields directly from an inherited SBP object, or
 * construct it inline using a dict of its fields.
 *
 * <p>This message can contain any application specific user data up to a maximum length of 255
 * bytes per message.
 */
public class MsgUserData extends SBPMessage {
    public static final int TYPE = 0x0800;

    /** User data payload */
    public int[] contents;

    public MsgUserData(int sender) {
        super(sender, TYPE);
    }

    public MsgUserData() {
        super(TYPE);
    }

    public MsgUserData(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type == TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        contents = parser.getArrayofU8();
    }

    @Override
    protected void build(Builder builder) {
        builder.putArrayofU8(contents);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("contents", new JSONArray(contents));
        return obj;
    }
}
