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
 * SBP class for message MSG_LINUX_PROCESS_FD_COUNT (0x7F06).
 *
 * <p>You can have MSG_LINUX_PROCESS_FD_COUNT inherent its fields directly from an inherited SBP
 * object, or construct it inline using a dict of its fields.
 *
 * <p>Top 10 list of processes with a large number of open file descriptors.
 */
public class MsgLinuxProcessFdCount extends SBPMessage {
    public static final int TYPE = 0x7F06;

    /** sequence of this status message, values from 0-9 */
    public int index;

    /** the PID of the process in question */
    public int pid;

    /** a count of the number of file descriptors opened by the process */
    public int fd_count;

    /** the command line of the process in question */
    public String cmdline;

    public MsgLinuxProcessFdCount(int sender) {
        super(sender, TYPE);
    }

    public MsgLinuxProcessFdCount() {
        super(TYPE);
    }

    public MsgLinuxProcessFdCount(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        if (msg.type != TYPE)
            throw new SBPBinaryException(
                    "Type mismatch for MsgLinuxProcessFdCount, expected 32518, actual " + msg.type);
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        index = parser.getU8();
        pid = parser.getU16();
        fd_count = parser.getU16();
        cmdline = parser.getString();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU8(index);
        builder.putU16(pid);
        builder.putU16(fd_count);
        builder.putString(cmdline);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("index", index);
        obj.put("pid", pid);
        obj.put("fd_count", fd_count);
        obj.put("cmdline", cmdline);
        return obj;
    }

    @Override
    public String getFriendlyName() {
        return "LINUX PROCESS FD COUNT";
    }
}
