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
package com.swiftnav.sbp.logging;

// This file was auto-generated from yaml/swiftnav/sbp/logging.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import org.json.JSONObject;

/**
 * SBP class for message MSG_LOG (0x0401).
 *
 * <p>You can have MSG_LOG inherent its fields directly from an inherited SBP object, or construct
 * it inline using a dict of its fields.
 *
 * <p>This message contains a human-readable payload string from the device containing errors,
 * warnings and informational messages at ERROR, WARNING, DEBUG, INFO logging levels.
 */
public class MsgLog extends SBPMessage {
    public static final int TYPE = 0x0401;

    /** Logging level */
    public int level;

    /** Human-readable string */
    public String text;

    public MsgLog(int sender) {
        super(sender, TYPE);
    }

    public MsgLog() {
        super(TYPE);
    }

    public MsgLog(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type == TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        level = parser.getU8();
        text = parser.getString();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU8(level);
        builder.putString(text);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("level", level);
        obj.put("text", text);
        return obj;
    }
}
