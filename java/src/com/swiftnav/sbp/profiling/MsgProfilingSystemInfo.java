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
package com.swiftnav.sbp.profiling;

// This file was auto-generated from yaml/swiftnav/sbp/profiling.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import java.math.BigInteger;
import org.json.JSONObject;

/**
 * SBP class for message MSG_PROFILING_SYSTEM_INFO (0xCF01).
 *
 * <p>You can have MSG_PROFILING_SYSTEM_INFO inherent its fields directly from an inherited SBP
 * object, or construct it inline using a dict of its fields.
 *
 * <p>Contains basic information about system resource usage. System is defined in terms of the
 * source of this message and may vary from sender to sender. Refer to product documentation to
 * understand the exact scope and meaning of this message.
 */
public class MsgProfilingSystemInfo extends SBPMessage {
    public static final int TYPE = 0xCF01;

    /** Total cpu time in microseconds consumed by this system */
    public BigInteger total_cpu_time;

    /** Age of the producing system in microseconds */
    public BigInteger age;

    /** Number of threads being tracked by this system */
    public int n_threads;

    /** Number of bytes allocated on the heap */
    public long heap_usage;

    public MsgProfilingSystemInfo(int sender) {
        super(sender, TYPE);
    }

    public MsgProfilingSystemInfo() {
        super(TYPE);
    }

    public MsgProfilingSystemInfo(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        if (msg.type != TYPE)
            throw new SBPBinaryException(
                    "Type mismatch for MsgProfilingSystemInfo, expected 52993, actual " + msg.type);
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        total_cpu_time = parser.getU64();
        age = parser.getU64();
        n_threads = parser.getU8();
        heap_usage = parser.getU32();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU64(total_cpu_time);
        builder.putU64(age);
        builder.putU8(n_threads);
        builder.putU32(heap_usage);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("total_cpu_time", total_cpu_time);
        obj.put("age", age);
        obj.put("n_threads", n_threads);
        obj.put("heap_usage", heap_usage);
        return obj;
    }

    @Override
    public String getFriendlyName() {
        return "PROFILING SYSTEM INFO";
    }
}
