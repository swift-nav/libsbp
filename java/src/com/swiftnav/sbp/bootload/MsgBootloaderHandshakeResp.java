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


/** SBP class for message MSG_BOOTLOADER_HANDSHAKE_RESP (0x00B4).
 *
 * You can have MSG_BOOTLOADER_HANDSHAKE_RESP inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
 * The handshake message response from the device establishes a
 * handshake between the device bootloader and the host. The
 * request from the host is MSG_BOOTLOADER_HANDSHAKE_REQ.  The
 * payload contains the bootloader version number and the SBP
 * protocol version number. */

public class MsgBootloaderHandshakeResp extends SBPMessage {
    public static final int TYPE = 0x00B4;

    
    /** Bootloader flags */
    public long flags;
    
    /** Bootloader version number */
    public String version;
    

    public MsgBootloaderHandshakeResp (int sender) { super(sender, TYPE); }
    public MsgBootloaderHandshakeResp () { super(TYPE); }
    public MsgBootloaderHandshakeResp (SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type != TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        flags = parser.getU32();
        version = parser.getString();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU32(flags);
        builder.putString(version);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("flags", flags);
        obj.put("version", version);
        return obj;
    }
}