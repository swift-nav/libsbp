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


/** SBP class for message MSG_SETTINGS_REGISTER_RESP (0x01AF).
 *
 * You can have MSG_SETTINGS_REGISTER_RESP inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
 * This message responds to setting registration with the effective value.
 * The effective value shall differ from the given default value if setting
 * was already registered or is available in the permanent setting storage
 * and had a different value. */

public class MsgSettingsRegisterResp extends SBPMessage {
    public static final int TYPE = 0x01AF;

    
    /** Register status */
    public int status;
    
    /** A NULL-terminated and delimited string with contents
"SECTION_SETTING\0SETTING\0VALUE". The meaning of value is defined
according to the status field.
 */
    public String setting;
    

    public MsgSettingsRegisterResp (int sender) { super(sender, TYPE); }
    public MsgSettingsRegisterResp () { super(TYPE); }
    public MsgSettingsRegisterResp (SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type != TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        status = parser.getU8();
        setting = parser.getString();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU8(status);
        builder.putString(setting);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("status", status);
        obj.put("setting", setting);
        return obj;
    }
}