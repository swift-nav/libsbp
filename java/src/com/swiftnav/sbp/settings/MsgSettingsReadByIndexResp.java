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


/** SBP class for message MSG_SETTINGS_READ_BY_INDEX_RESP (0x00A7).
 *
 * You can have MSG_SETTINGS_READ_BY_INDEX_RESP inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
 * The settings message that reports the value of a setting at an index.
 * 
 * In the string field, it reports NULL-terminated and delimited string
 * with contents "SECTION_SETTING\0SETTING\0VALUE\0FORMAT_TYPE\0". where
 * the '\0' escape sequence denotes the NULL character and where quotation
 * marks are omitted. The FORMAT_TYPE field is optional and denotes
 * possible string values of the setting as a hint to the user. If
 * included, the format type portion of the string has the format
 * "enum:value1,value2,value3". An example string that could be sent from
 * the device is "simulator\0enabled\0True\0enum:True,False\0" */

public class MsgSettingsReadByIndexResp extends SBPMessage {
    public static final int TYPE = 0x00A7;

    
    /** An index into the device settings, with values ranging from
0 to length(settings)
 */
    public int index;
    
    /** A NULL-terminated and delimited string with contents
"SECTION_SETTING\0SETTING\0VALUE\0FORMAT_TYPE\0"
 */
    public String setting;
    

    public MsgSettingsReadByIndexResp (int sender) { super(sender, TYPE); }
    public MsgSettingsReadByIndexResp () { super(TYPE); }
    public MsgSettingsReadByIndexResp (SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type != TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        index = parser.getU16();
        setting = parser.getString();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU16(index);
        builder.putString(setting);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("index", index);
        obj.put("setting", setting);
        return obj;
    }
}