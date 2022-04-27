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
 * SBP class for message MSG_HEARTBEAT (0xFFFF).
 *
 * <p>You can have MSG_HEARTBEAT inherent its fields directly from an inherited SBP object, or
 * construct it inline using a dict of its fields.
 *
 * <p>The heartbeat message is sent periodically to inform the host or other attached devices that
 * the system is running. It is used to monitor system malfunctions. It also contains status flags
 * that indicate to the host the status of the system and whether it is operating correctly.
 * Currently, the expected heartbeat interval is 1 sec.
 *
 * <p>The system error flag is used to indicate that an error has occurred in the system. To
 * determine the source of the error, the remaining error flags should be inspected.
 */
public class MsgHeartbeat extends SBPMessage {
    public static final int TYPE = 0xFFFF;

    /** Status flags */
    public long flags;

    public MsgHeartbeat(int sender) {
        super(sender, TYPE);
    }

    public MsgHeartbeat() {
        super(TYPE);
    }

    public MsgHeartbeat(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type == TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        flags = parser.getU32();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU32(flags);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("flags", flags);
        return obj;
    }
}
