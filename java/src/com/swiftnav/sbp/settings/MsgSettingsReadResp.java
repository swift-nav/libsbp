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
package com.swiftnav.sbp.settings;

// This file was auto-generated from yaml/swiftnav/sbp/settings.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import org.json.JSONObject;

/**
 * SBP class for message MSG_SETTINGS_READ_RESP (0x00A5).
 *
 * <p>You can have MSG_SETTINGS_READ_RESP inherent its fields directly from an inherited SBP object,
 * or construct it inline using a dict of its fields.
 *
 * <p>The setting message with which the device responds after a MSG_SETTING_READ_REQ is sent to
 * device. The string field is a NULL- terminated and NULL-delimited string with contents
 * "SECTION_SETTING\0SETTING\0VALUE\0" where the '\0' escape sequence denotes the NULL character and
 * where quotation marks are omitted. An example string that could be sent from device is
 * "solution\0soln_freq\010\0".
 */
public class MsgSettingsReadResp extends SBPMessage {
    public static final int TYPE = 0x00A5;

    /**
     * A NULL-terminated and NULL-delimited string with contents "SECTION_SETTING\0SETTING\0VALUE\0"
     */
    public String setting;

    public MsgSettingsReadResp(int sender) {
        super(sender, TYPE);
    }

    public MsgSettingsReadResp() {
        super(TYPE);
    }

    public MsgSettingsReadResp(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type == TYPE;
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
}
