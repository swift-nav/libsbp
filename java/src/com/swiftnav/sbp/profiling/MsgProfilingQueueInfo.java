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
package com.swiftnav.sbp.profiling;

// This file was auto-generated from yaml/swiftnav/sbp/profiling.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import org.json.JSONObject;

/**
 * SBP class for message MSG_PROFILING_QUEUE_INFO (0xCF04).
 *
 * <p>You can have MSG_PROFILING_QUEUE_INFO inherent its fields directly from an inherited SBP
 * object, or construct it inline using a dict of its fields.
 *
 * <p>Contains profiling information for a single swiftlet internal message queue type. Refer to
 * product documentation to understand the meaning and values in this message.
 */
public class MsgProfilingQueueInfo extends SBPMessage {
    public static final int TYPE = 0xCF04;

    /** Total number of slots in the queue */
    public int size;

    /** Number of slots currently in use */
    public int current_fill;

    /** Peak number of slots used since init */
    public int peak_fill;

    /** Number of messages dropped since init */
    public int drop_count;

    /** Queue type name */
    public String name;

    public MsgProfilingQueueInfo(int sender) {
        super(sender, TYPE);
    }

    public MsgProfilingQueueInfo() {
        super(TYPE);
    }

    public MsgProfilingQueueInfo(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        if (msg.type != TYPE)
            throw new SBPBinaryException(
                    "Type mismatch for MsgProfilingQueueInfo, expected 52996, actual " + msg.type);
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        size = parser.getU16();
        current_fill = parser.getU16();
        peak_fill = parser.getU16();
        drop_count = parser.getU16();
        name = parser.getString();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU16(size);
        builder.putU16(current_fill);
        builder.putU16(peak_fill);
        builder.putU16(drop_count);
        builder.putString(name);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("size", size);
        obj.put("current_fill", current_fill);
        obj.put("peak_fill", peak_fill);
        obj.put("drop_count", drop_count);
        obj.put("name", name);
        return obj;
    }

    @Override
    public String getFriendlyName() {
        return "PROFILING QUEUE INFO";
    }
}
