/*
 * Copyright (C) 2015-2018 Swift Navigation Inc.
 * Contact: Swift Navigation <dev@swiftnav.com>
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

package com.swiftnav.sbp.linux;

import java.math.BigInteger;

import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPStruct;

import org.json.JSONObject;
import org.json.JSONArray;


/** SBP class for message MSG_LINUX_PROCESS_SOCKET_COUNTS (0x7F03).
 *
 * You can have MSG_LINUX_PROCESS_SOCKET_COUNTS inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
 * Top 10 list of processes with high socket counts. */

public class MsgLinuxProcessSocketCounts extends SBPMessage {
    public static final int TYPE = 0x7F03;

    
    /** sequence of this status message, values from 0-9 */
    public int index;
    
    /** the PID of the process in question */
    public int pid;
    
    /** the number of sockets the process is using */
    public int socket_count;
    
    /** A bitfield indicating the socket types used:
  0x1 (tcp), 0x2 (udp), 0x4 (unix stream), 0x8 (unix dgram), 0x10 (netlink),
  and 0x8000 (unknown)
 */
    public int socket_types;
    
    /** A bitfield indicating the socket states:
  0x1 (established), 0x2 (syn-sent), 0x4 (syn-recv), 0x8 (fin-wait-1),
  0x10 (fin-wait-2), 0x20 (time-wait), 0x40 (closed), 0x80 (close-wait),
  0x100 (last-ack), 0x200 (listen), 0x400 (closing), 0x800 (unconnected),
  and 0x8000 (unknown)
 */
    public int socket_states;
    
    /** the command line of the process in question */
    public String cmdline;
    

    public MsgLinuxProcessSocketCounts (int sender) { super(sender, TYPE); }
    public MsgLinuxProcessSocketCounts () { super(TYPE); }
    public MsgLinuxProcessSocketCounts (SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type != TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        index = parser.getU8();
        pid = parser.getU16();
        socket_count = parser.getU16();
        socket_types = parser.getU16();
        socket_states = parser.getU16();
        cmdline = parser.getString();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU8(index);
        builder.putU16(pid);
        builder.putU16(socket_count);
        builder.putU16(socket_types);
        builder.putU16(socket_states);
        builder.putString(cmdline);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("index", index);
        obj.put("pid", pid);
        obj.put("socket_count", socket_count);
        obj.put("socket_types", socket_types);
        obj.put("socket_states", socket_states);
        obj.put("cmdline", cmdline);
        return obj;
    }
}