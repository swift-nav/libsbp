/*
 * Copyright (C) 2015 Swift Navigation Inc.
 * Contact: Gareth McMullin <gareth@swiftnav.com>
 * Contact: Bhaskar Mookerji <mookerji@swiftnav.com>
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

package com.swiftnav.sbp.piksi;

import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPStruct;
import com.swiftnav.sbp.gnss_signal.*;

import org.json.JSONObject;
import org.json.JSONArray;


/** SBP class for message MSG_THREAD_STATE (0x0017).
 *
 * You can have MSG_THREAD_STATE inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
 * The thread usage message from the device reports real-time
 * operating system (RTOS) thread usage statistics for the named
 * thread. The reported percentage values must be normalized. */

public class MsgThreadState extends SBPMessage {
    public static final int TYPE = 0x0017;

    
    /** Thread name (NULL terminated) */
    public String name;
    
    /** Percentage cpu use for this thread. Values range from 0
- 1000 and needs to be renormalized to 100
 */
    public int cpu;
    
    /** Free stack space for this thread */
    public long stack_free;
    

    public MsgThreadState (int sender) { super(sender, TYPE); }
    public MsgThreadState () { super(TYPE); }
    public MsgThreadState (SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type != TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        name = parser.getString(20);
        cpu = parser.getU16();
        stack_free = parser.getU32();
    }

    @Override
    protected void build(Builder builder) {
        builder.putString(name, 20);
        builder.putU16(cpu);
        builder.putU32(stack_free);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("name", name);
        obj.put("cpu", cpu);
        obj.put("stack_free", stack_free);
        return obj;
    }
}