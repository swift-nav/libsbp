/*
 * Copyright (C) 2015-2018 Swift Navigation Inc.
 * Contact: Swift Navigation <dev@swiftnav.com>
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

package com.swiftnav.sbp.settings;

import java.math.BigInteger;

import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPStruct;

import org.json.JSONObject;
import org.json.JSONArray;


/** SBP class for message MSG_SETTINGS_READ_REQ (0x00A4).
 *
 * You can have MSG_SETTINGS_READ_REQ inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
 * The setting message that reads the device configuration. The string
 * field is a NULL-terminated and NULL-delimited string with contents
 * "SECTION_SETTING\0SETTING\0" where the '\0' escape sequence denotes the
 * NULL character and where quotation marks are omitted. An example
 * string that could be sent to a device is "solution\0soln_freq\0". A
 * device will only respond to this message when it is received from
 * sender ID 0x42. A device should respond with a MSG_SETTINGS_READ_RESP
 * message (msg_id 0x00A5). */

public class MsgSettingsReadReq extends SBPMessage {
    public static final int TYPE = 0x00A4;

    
    /** A NULL-terminated and NULL-delimited string with contents
"SECTION_SETTING\0SETTING\0"
 */
    public String setting;
    

    public MsgSettingsReadReq (int sender) { super(sender, TYPE); }
    public MsgSettingsReadReq () { super(TYPE); }
    public MsgSettingsReadReq (SBPMessage msg) throws SBPBinaryException {
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