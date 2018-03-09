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


/** SBP class for message MSG_SETTINGS_WRITE_RESP (0x00AF).
 *
 * You can have MSG_SETTINGS_WRITE_RESP inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
 * Return the status of a write request with the new value of the
 * setting.  If the requested value is rejected, the current value
 * will be returned. The string field is a NULL-terminated and NULL-delimited
 * string with contents "SECTION_SETTING\0SETTING\0VALUE\0" where the '\0'
 * escape sequence denotes the NULL character and where quotation marks
 * are omitted. An example string that could be sent from device is
 * "solution\0soln_freq\010\0". */

public class MsgSettingsWriteResp extends SBPMessage {
    public static final int TYPE = 0x00AF;

    
    /** Write status */
    public int status;
    
    /** A NULL-terminated and delimited string with contents
"SECTION_SETTING\0SETTING\0VALUE\0" 
 */
    public String setting;
    

    public MsgSettingsWriteResp (int sender) { super(sender, TYPE); }
    public MsgSettingsWriteResp () { super(TYPE); }
    public MsgSettingsWriteResp (SBPMessage msg) throws SBPBinaryException {
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