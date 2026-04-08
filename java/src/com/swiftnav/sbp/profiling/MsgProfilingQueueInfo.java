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
import com.swiftnav.sbp.SBPStruct;
import org.json.JSONObject;

/**
 * SBP class for message MSG_PROFILING_QUEUE_INFO (0xCF04).
 *
 * <p>You can have MSG_PROFILING_QUEUE_INFO inherent its fields directly from an inherited SBP
 * object, or construct it inline using a dict of its fields.
 *
 * <p>Contains profiling information for swiftlet internal message queues. Refer to product
 * documentation to understand the meaning and values in this message.
 */
public class MsgProfilingQueueInfo extends SBPMessage {
    public static final int TYPE = 0xCF04;

    /** Message number in complete sequence */
    public int seq_no;

    /** Length of message sequence */
    public int seq_len;

    /** List of queue stats */
    public QueueInfo[] queues;

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
        seq_no = parser.getU8();
        seq_len = parser.getU8();
        queues = parser.getArray(QueueInfo.class);
    }

    @Override
    protected void build(Builder builder) {
        builder.putU8(seq_no);
        builder.putU8(seq_len);
        builder.putArray(queues);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("seq_no", seq_no);
        obj.put("seq_len", seq_len);
        obj.put("queues", SBPStruct.toJSONArray(queues));
        return obj;
    }

    @Override
    public String getFriendlyName() {
        return "PROFILING QUEUE INFO";
    }
}
