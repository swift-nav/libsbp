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
package com.swiftnav.sbp.bootload;

// This file was auto-generated from yaml/swiftnav/sbp/bootload.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import org.json.JSONObject;

/**
 * SBP class for message MSG_BOOTLOADER_JUMP_TO_APP (0x00B1).
 *
 * <p>You can have MSG_BOOTLOADER_JUMP_TO_APP inherent its fields directly from an inherited SBP
 * object, or construct it inline using a dict of its fields.
 *
 * <p>The host initiates the bootloader to jump to the application.
 */
public class MsgBootloaderJumpToApp extends SBPMessage {
    public static final int TYPE = 0x00B1;

    /** Ignored by the device */
    public int jump;

    public MsgBootloaderJumpToApp(int sender) {
        super(sender, TYPE);
    }

    public MsgBootloaderJumpToApp() {
        super(TYPE);
    }

    public MsgBootloaderJumpToApp(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        if (msg.type != TYPE)
            throw new SBPBinaryException(
                    "Type mismatch for MsgBootloaderJumpToApp, expected 177, actual " + msg.type);
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        jump = parser.getU8();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU8(jump);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("jump", jump);
        return obj;
    }

    @Override
    public String getFriendlyName() {
        return "BOOTLOADER JUMP TO APP";
    }
}
