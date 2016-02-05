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

package com.swiftnav.sbp.bootload;

import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPStruct;

import org.json.JSONObject;
import org.json.JSONArray;


/** SBP class for message MSG_BOOTLOADER_HANDSHAKE_DEP_A (0x00B0).
 *
 * You can have MSG_BOOTLOADER_HANDSHAKE_DEP_A inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
* Deprecated. */

public class MsgBootloaderHandshakeDepA extends SBPMessage {
    public static final int TYPE = 0x00B0;

    
    /** Version number string (not NULL terminated) */
    public int[] handshake;
    

    public MsgBootloaderHandshakeDepA (int sender) { super(sender, TYPE); }
    public MsgBootloaderHandshakeDepA () { super(TYPE); }
    public MsgBootloaderHandshakeDepA (SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type != TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        handshake = parser.getArrayofU8();
    }

    @Override
    protected void build(Builder builder) {
        builder.putArrayofU8(handshake);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("handshake", new JSONArray(handshake));
        return obj;
    }
}