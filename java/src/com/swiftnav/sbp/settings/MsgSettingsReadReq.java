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
package com.swiftnav.sbp.settings;

// This file was auto-generated from yaml/swiftnav/sbp/settings.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import org.json.JSONObject;

/**
 * SBP class for message MSG_SETTINGS_READ_REQ (0x00A4).
 *
 * <p>You can have MSG_SETTINGS_READ_REQ inherent its fields directly from an inherited SBP object,
 * or construct it inline using a dict of its fields.
 *
 * <p>The setting message that reads the device configuration. The string field is a NULL-terminated
 * and NULL-delimited string with contents "SECTION_SETTING\0SETTING\0" where the '\0' escape
 * sequence denotes the NULL character and where quotation marks are omitted. An example string that
 * could be sent to a device is "solution\0soln_freq\0". A device will only respond to this message
 * when it is received from sender ID 0x42. A device should respond with a MSG_SETTINGS_READ_RESP
 * message (msg_id 0x00A5).
 */
public class MsgSettingsReadReq extends SBPMessage {
    public static final int TYPE = 0x00A4;

    /** A NULL-terminated and NULL-delimited string with contents "SECTION_SETTING\0SETTING\0" */
    public String setting;

    public MsgSettingsReadReq(int sender) {
        super(sender, TYPE);
    }

    public MsgSettingsReadReq() {
        super(TYPE);
    }

    public MsgSettingsReadReq(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        if (msg.type != TYPE)
            throw new SBPBinaryException(
                    "Type mismatch for MsgSettingsReadReq, expected 164, actual " + msg.type);
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        setting = parser.getString();
    }

    @Override
    protected void build(Builder builder) {
        builder.putString(setting);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("setting", setting);
        return obj;
    }

    @Override
    public String getFriendlyName() {
        return "SETTINGS READ REQ";
    }
}
