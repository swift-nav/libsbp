/*
 * Copyright (C) 2015 Swift Navigation Inc.
 * Contact: Gareth McMullin <gareth@swiftnav.com>
 * Contact: Bhaskar Mookerji <mookerji@swiftnav.com>
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

package com.swiftnav.sbp.settings;

import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPStruct;

import org.json.JSONObject;
import org.json.JSONArray;


/** SBP class for message MSG_SETTINGS_WRITE (0x00A0).
 *
 * You can have MSG_SETTINGS_WRITE inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
* The setting message writes the device configuration. */

public class MsgSettingsWrite extends SBPMessage {
    public static final int TYPE = 0x00A0;

    
    /** A NULL-terminated and delimited string with contents
[SECTION_SETTING, SETTING, VALUE]. A device will only
process to this message when it is received from sender ID
0x42.
 */
    public String setting;
    

    public MsgSettingsWrite (int sender) { super(sender, TYPE); }
    public MsgSettingsWrite () { super(TYPE); }
    public MsgSettingsWrite (SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type != TYPE;
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