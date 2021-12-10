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
 * SBP class for message MSG_LINUX_CPU_STATE_DEP_A (0x7F00).
 *
 * <p>You can have MSG_LINUX_CPU_STATE_DEP_A inherent its fields directly from an inherited SBP
 * object, or construct it inline using a dict of its fields.
 *
 * <p>This message indicates the process state of the top 10 heaviest consumers of CPU on the
 * system.
 */
public class MsgLinuxCpuStateDepA extends SBPMessage {
    public static final int TYPE = 0x7F00;

    /** sequence of this status message, values from 0-9 */
    public int index;

    /** the PID of the process */
    public int pid;

    /** percent of cpu used, expressed as a fraction of 256 */
    public int pcpu;

    /** fixed length string representing the thread name */
    public String tname;

    /** the command line (as much as it fits in the remaining packet) */
    public String cmdline;

    public MsgLinuxCpuStateDepA(int sender) {
        super(sender, TYPE);
    }

    public MsgLinuxCpuStateDepA() {
        super(TYPE);
    }

    public MsgLinuxCpuStateDepA(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type == TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        index = parser.getU8();
        pid = parser.getU16();
        pcpu = parser.getU8();
        tname = parser.getString(15);
        cmdline = parser.getString();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU8(index);
        builder.putU16(pid);
        builder.putU8(pcpu);
        builder.putString(tname, 15);
        builder.putString(cmdline);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("index", index);
        obj.put("pid", pid);
        obj.put("pcpu", pcpu);
        obj.put("tname", tname);
        obj.put("cmdline", cmdline);
        return obj;
    }
}
