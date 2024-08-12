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
import java.math.BigInteger;
import org.json.JSONObject;

/**
 * SBP class for message MSG_PROFILING_THREAD_INFO (0xCF02).
 *
 * <p>You can have MSG_PROFILING_THREAD_INFO inherent its fields directly from an inherited SBP
 * object, or construct it inline using a dict of its fields.
 *
 * <p>Contains profiling information related to a single thread being tracked by the producing
 * system. Refer to product documentation to understand the exact scope and meaning of this message.
 */
public class MsgProfilingThreadInfo extends SBPMessage {
    public static final int TYPE = 0xCF02;

    /** Total cpu time in microseconds consumed by this thread */
    public BigInteger total_cpu_time;

    /** Age of the thread in microseconds */
    public BigInteger age;

    /** Thread state */
    public int state;

    /** Stack size in bytes */
    public long stack_size;

    /** Stack high water usage in bytes */
    public long stack_usage;

    /** Thread name */
    public String name;

    public MsgProfilingThreadInfo(int sender) {
        super(sender, TYPE);
    }

    public MsgProfilingThreadInfo() {
        super(TYPE);
    }

    public MsgProfilingThreadInfo(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        if (msg.type != TYPE)
            throw new SBPBinaryException(
                    "Type mismatch for MsgProfilingThreadInfo, expected 52994, actual " + msg.type);
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        total_cpu_time = parser.getU64();
        age = parser.getU64();
        state = parser.getU8();
        stack_size = parser.getU32();
        stack_usage = parser.getU32();
        name = parser.getString();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU64(total_cpu_time);
        builder.putU64(age);
        builder.putU8(state);
        builder.putU32(stack_size);
        builder.putU32(stack_usage);
        builder.putString(name);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("total_cpu_time", total_cpu_time);
        obj.put("age", age);
        obj.put("state", state);
        obj.put("stack_size", stack_size);
        obj.put("stack_usage", stack_usage);
        obj.put("name", name);
        return obj;
    }

    @Override
    public String getFriendlyName() {
        return "PROFILING THREAD INFO";
    }
}
