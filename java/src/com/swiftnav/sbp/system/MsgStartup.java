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

package com.swiftnav.sbp.system;

import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPStruct;
import java.math.BigInteger;

import org.json.JSONObject;
import org.json.JSONArray;


/** SBP class for message MSG_STARTUP (0xFF00).
 *
 * You can have MSG_STARTUP inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
 * The system start-up message is sent once on system
 * start-up. It notifies the host or other attached devices that
 * the system has started and is now ready to respond to commands
 * or configuration requests. */

public class MsgStartup extends SBPMessage {
    public static final int TYPE = 0xFF00;

    
    /** Cause of startup */
    public int cause;
    
    /** Startup type */
    public int startup_type;
    
    /** Reserved */
    public int reserved;
    

    public MsgStartup (int sender) { super(sender, TYPE); }
    public MsgStartup () { super(TYPE); }
    public MsgStartup (SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type != TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        cause = parser.getU8();
        startup_type = parser.getU8();
        reserved = parser.getU16();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU8(cause);
        builder.putU8(startup_type);
        builder.putU16(reserved);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("cause", cause);
        obj.put("startup_type", startup_type);
        obj.put("reserved", reserved);
        return obj;
    }
}