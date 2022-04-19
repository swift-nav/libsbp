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
package com.swiftnav.sbp.system;

// This file was auto-generated from yaml/swiftnav/sbp/system.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import org.json.JSONObject;

/**
 * SBP class for message MSG_STARTUP (0xFF00).
 *
 * <p>You can have MSG_STARTUP inherent its fields directly from an inherited SBP object, or
 * construct it inline using a dict of its fields.
 *
 * <p>The system start-up message is sent once on system start-up. It notifies the host or other
 * attached devices that the system has started and is now ready to respond to commands or
 * configuration requests.
 */
public class MsgStartup extends SBPMessage {
    public static final int TYPE = 0xFF00;

    /** Cause of startup */
    public int cause;

    /** Startup type */
    public int startup_type;

    /** Reserved */
    public int reserved;

    public MsgStartup(int sender) {
        super(sender, TYPE);
    }

    public MsgStartup() {
        super(TYPE);
    }

    public MsgStartup(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type == TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        cause = parser.getU8();
        startup_type = parser.getU8();
        reserved = parser.getU16();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU8(cause);
        builder.putU8(startup_type);
        builder.putU16(reserved);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("cause", cause);
        obj.put("startup_type", startup_type);
        obj.put("reserved", reserved);
        return obj;
    }
}
