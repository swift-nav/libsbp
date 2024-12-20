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
package com.swiftnav.sbp.logging;

// This file was auto-generated from yaml/swiftnav/sbp/logging.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import org.json.JSONObject;

/**
 * SBP class for message MSG_PRINT_DEP (0x0010).
 *
 * <p>You can have MSG_PRINT_DEP inherent its fields directly from an inherited SBP object, or
 * construct it inline using a dict of its fields.
 *
 * <p>Deprecated.
 */
public class MsgPrintDep extends SBPMessage {
    public static final int TYPE = 0x0010;

    /** Human-readable string */
    public String text;

    public MsgPrintDep(int sender) {
        super(sender, TYPE);
    }

    public MsgPrintDep() {
        super(TYPE);
    }

    public MsgPrintDep(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        if (msg.type != TYPE)
            throw new SBPBinaryException(
                    "Type mismatch for MsgPrintDep, expected 16, actual " + msg.type);
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        text = parser.getString();
    }

    @Override
    protected void build(Builder builder) {
        builder.putString(text);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("text", text);
        return obj;
    }

    @Override
    public String getFriendlyName() {
        return "PRINT DEP";
    }
}
