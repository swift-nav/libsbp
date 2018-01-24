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

package com.swiftnav.sbp.logging;

import java.math.BigInteger;

import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPStruct;

import org.json.JSONObject;
import org.json.JSONArray;


/** SBP class for message MSG_FWD (0x0402).
 *
 * You can have MSG_FWD inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
 * This message provides the ability to forward messages over SBP.  This may take the form
 * of wrapping up SBP messages received by Piksi for logging purposes or wrapping 
 * another protocol with SBP.
 * 
 * The source identifier indicates from what interface a forwarded stream derived.
 * The protocol identifier identifies what the expected protocol the forwarded msg contains.
 * Protocol 0 represents SBP and the remaining values are implementation defined. */

public class MsgFwd extends SBPMessage {
    public static final int TYPE = 0x0402;

    
    /** source identifier */
    public int source;
    
    /** protocol identifier */
    public int protocol;
    
    /** variable length wrapped binary message */
    public String fwd_payload;
    

    public MsgFwd (int sender) { super(sender, TYPE); }
    public MsgFwd () { super(TYPE); }
    public MsgFwd (SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type != TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        source = parser.getU8();
        protocol = parser.getU8();
        fwd_payload = parser.getString();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU8(source);
        builder.putU8(protocol);
        builder.putString(fwd_payload);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("source", source);
        obj.put("protocol", protocol);
        obj.put("fwd_payload", fwd_payload);
        return obj;
    }
}