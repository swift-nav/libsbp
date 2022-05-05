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
package com.swiftnav.sbp.settings;

// This file was auto-generated from yaml/swiftnav/sbp/settings.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import org.json.JSONObject;

/**
 * SBP class for message MSG_SETTINGS_READ_BY_INDEX_REQ (0x00A2).
 *
 * <p>You can have MSG_SETTINGS_READ_BY_INDEX_REQ inherent its fields directly from an inherited SBP
 * object, or construct it inline using a dict of its fields.
 *
 * <p>The settings message for iterating through the settings values. A device will respond to this
 * message with a "MSG_SETTINGS_READ_BY_INDEX_RESP".
 */
public class MsgSettingsReadByIndexReq extends SBPMessage {
    public static final int TYPE = 0x00A2;

    /** An index into the device settings, with values ranging from 0 to length(settings). */
    public int index;

    public MsgSettingsReadByIndexReq(int sender) {
        super(sender, TYPE);
    }

    public MsgSettingsReadByIndexReq() {
        super(TYPE);
    }

    public MsgSettingsReadByIndexReq(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type == TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        index = parser.getU16();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU16(index);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("index", index);
        return obj;
    }
}
