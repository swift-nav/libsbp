/* Copyright (C) 2015-2021 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
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
import org.json.JSONObject;

/**
 * SBP class for message MSG_LINUX_SYS_STATE (0x7F0A).
 *
 * <p>You can have MSG_LINUX_SYS_STATE inherent its fields directly from an inherited SBP object, or
 * construct it inline using a dict of its fields.
 *
 * <p>This presents a summary of CPU and memory utilization, including a timestamp.
 */
public class MsgLinuxSysState extends SBPMessage {
    public static final int TYPE = 0x7F0A;

    /** total system memory, in MiB */
    public int mem_total;

    /** percent of CPU used, expressed as a fraction of 256 */
    public int pcpu;

    /** percent of memory used, expressed as a fraction of 256 */
    public int pmem;

    /** number of processes that started during collection phase */
    public int procs_starting;

    /** number of processes that stopped during collection phase */
    public int procs_stopping;

    /** the count of processes on the system */
    public int pid_count;

    /** timestamp of message, refer to flags field for how to interpret */
    public long time;

    /** flags */
    public int flags;

    public MsgLinuxSysState(int sender) {
        super(sender, TYPE);
    }

    public MsgLinuxSysState() {
        super(TYPE);
    }

    public MsgLinuxSysState(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type == TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        mem_total = parser.getU16();
        pcpu = parser.getU8();
        pmem = parser.getU8();
        procs_starting = parser.getU16();
        procs_stopping = parser.getU16();
        pid_count = parser.getU16();
        time = parser.getU32();
        flags = parser.getU8();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU16(mem_total);
        builder.putU8(pcpu);
        builder.putU8(pmem);
        builder.putU16(procs_starting);
        builder.putU16(procs_stopping);
        builder.putU16(pid_count);
        builder.putU32(time);
        builder.putU8(flags);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("mem_total", mem_total);
        obj.put("pcpu", pcpu);
        obj.put("pmem", pmem);
        obj.put("procs_starting", procs_starting);
        obj.put("procs_stopping", procs_stopping);
        obj.put("pid_count", pid_count);
        obj.put("time", time);
        obj.put("flags", flags);
        return obj;
    }
}
