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
 * SBP class for message MSG_LINUX_PROCESS_FD_SUMMARY (0x7F07).
 *
 * <p>You can have MSG_LINUX_PROCESS_FD_SUMMARY inherent its fields directly from an inherited SBP
 * object, or construct it inline using a dict of its fields.
 *
 * <p>Summary of open file descriptors on the system.
 */
public class MsgLinuxProcessFdSummary extends SBPMessage {
    public static final int TYPE = 0x7F07;

    /** count of total FDs open on the system */
    public long sys_fd_count;

    /**
     * A null delimited list of strings which alternates between a string representation of the
     * process count and the file name whose count it being reported. That is, in C string syntax
     * "32\0/var/log/syslog\012\0/tmp/foo\0" with the end of the list being 2 NULL terminators in a
     * row.
     */
    public String most_opened;

    public MsgLinuxProcessFdSummary(int sender) {
        super(sender, TYPE);
    }

    public MsgLinuxProcessFdSummary() {
        super(TYPE);
    }

    public MsgLinuxProcessFdSummary(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type == TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        sys_fd_count = parser.getU32();
        most_opened = parser.getString();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU32(sys_fd_count);
        builder.putString(most_opened);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("sys_fd_count", sys_fd_count);
        obj.put("most_opened", most_opened);
        return obj;
    }
}
