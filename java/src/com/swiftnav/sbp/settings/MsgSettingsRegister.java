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
 * SBP class for message MSG_SETTINGS_REGISTER (0x00AE).
 *
 * <p>You can have MSG_SETTINGS_REGISTER inherent its fields directly from an inherited SBP object,
 * or construct it inline using a dict of its fields.
 *
 * <p>This message registers the presence and default value of a setting with a settings daemon. The
 * host should reply with MSG_SETTINGS_WRITE for this setting to set the initial value.
 */
public class MsgSettingsRegister extends SBPMessage {
    public static final int TYPE = 0x00AE;

    /** A NULL-terminated and delimited string with contents "SECTION_SETTING\0SETTING\0VALUE". */
    public String setting;

    public MsgSettingsRegister(int sender) {
        super(sender, TYPE);
    }

    public MsgSettingsRegister() {
        super(TYPE);
    }

    public MsgSettingsRegister(SBPMessage msg) throws SBPBinaryException {
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
