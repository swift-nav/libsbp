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
import org.json.JSONObject;

/**
 * SBP class for message MSG_LINUX_SYS_STATE_DEP_A (0x7F02).
 *
 * <p>You can have MSG_LINUX_SYS_STATE_DEP_A inherent its fields directly from an inherited SBP
 * object, or construct it inline using a dict of its fields.
 *
 * <p>Deprecated.
 */
public class MsgLinuxSysStateDepA extends SBPMessage {
    public static final int TYPE = 0x7F02;

    /** total system memory */
    public int mem_total;

    /** percent of total cpu currently utilized */
    public int pcpu;

    /** percent of total memory currently utilized */
    public int pmem;

    /** number of processes that started during collection phase */
    public int procs_starting;

    /** number of processes that stopped during collection phase */
    public int procs_stopping;

    /** the count of processes on the system */
    public int pid_count;

    public MsgLinuxSysStateDepA(int sender) {
        super(sender, TYPE);
    }

    public MsgLinuxSysStateDepA() {
        super(TYPE);
    }

    public MsgLinuxSysStateDepA(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        if (msg.type != TYPE)
            throw new SBPBinaryException(
                    "Type mismatch for MsgLinuxSysStateDepA, expected 32514, actual " + msg.type);
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
    }

    @Override
    protected void build(Builder builder) {
        builder.putU16(mem_total);
        builder.putU8(pcpu);
        builder.putU8(pmem);
        builder.putU16(procs_starting);
        builder.putU16(procs_stopping);
        builder.putU16(pid_count);
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
        return obj;
    }

    @Override
    public String getFriendlyName() {
        return "LINUX SYS STATE DEP A";
    }
}
