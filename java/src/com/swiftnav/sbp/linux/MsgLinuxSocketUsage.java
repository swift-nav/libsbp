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
package com.swiftnav.sbp.linux;

// This file was auto-generated from yaml/swiftnav/sbp/linux.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import org.json.JSONArray;
import org.json.JSONObject;

/**
 * SBP class for message MSG_LINUX_SOCKET_USAGE (0x7F05).
 *
 * <p>You can have MSG_LINUX_SOCKET_USAGE inherent its fields directly from an inherited SBP object,
 * or construct it inline using a dict of its fields.
 *
 * <p>Summaries the socket usage across the system.
 */
public class MsgLinuxSocketUsage extends SBPMessage {
    public static final int TYPE = 0x7F05;

    /** average socket queue depths across all sockets on the system */
    public long avg_queue_depth;

    /** the max queue depth seen within the reporting period */
    public long max_queue_depth;

    /**
     * A count for each socket type reported in the `socket_types_reported` field, the first entry
     * corresponds to the first enabled bit in `types_reported`.
     */
    public int[] socket_state_counts;

    /**
     * A count for each socket type reported in the `socket_types_reported` field, the first entry
     * corresponds to the first enabled bit in `types_reported`.
     */
    public int[] socket_type_counts;

    public MsgLinuxSocketUsage(int sender) {
        super(sender, TYPE);
    }

    public MsgLinuxSocketUsage() {
        super(TYPE);
    }

    public MsgLinuxSocketUsage(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        if (msg.type != TYPE)
            throw new SBPBinaryException(
                    "Type mismatch for MsgLinuxSocketUsage, expected 32517, actual " + msg.type);
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        avg_queue_depth = parser.getU32();
        max_queue_depth = parser.getU32();
        socket_state_counts = parser.getArrayofU16(16);
        socket_type_counts = parser.getArrayofU16(16);
    }

    @Override
    protected void build(Builder builder) {
        builder.putU32(avg_queue_depth);
        builder.putU32(max_queue_depth);
        builder.putArrayofU16(socket_state_counts, 16);
        builder.putArrayofU16(socket_type_counts, 16);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("avg_queue_depth", avg_queue_depth);
        obj.put("max_queue_depth", max_queue_depth);
        obj.put("socket_state_counts", new JSONArray(socket_state_counts));
        obj.put("socket_type_counts", new JSONArray(socket_type_counts));
        return obj;
    }

    @Override
    public String getFriendlyName() {
        return "LINUX SOCKET USAGE";
    }
}
