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


/** SBP class for message MSG_BOOTLOADER_HANDSHAKE_REQ (0x00B3).
 *
 * You can have MSG_BOOTLOADER_HANDSHAKE_REQ inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
 * The handshake message request from the host establishes a
 * handshake between the device bootloader and the host. The
 * response from the device is MSG_BOOTLOADER_HANDSHAKE_RESP. */

public class MsgBootloaderHandshakeReq extends SBPMessage {
    public static final int TYPE = 0x00B3;

    

    public MsgBootloaderHandshakeReq (int sender) { super(sender, TYPE); }
    public MsgBootloaderHandshakeReq () { super(TYPE); }
    public MsgBootloaderHandshakeReq (SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type != TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
    }

    @Override
    protected void build(Builder builder) {
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        return obj;
    }
}