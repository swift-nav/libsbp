/* Copyright (C) 2015-2022 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */
package com.swiftnav.sbp.flash;

// This file was auto-generated from yaml/swiftnav/sbp/flash.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import org.json.JSONObject;

/**
 * SBP class for message MSG_STM_FLASH_UNLOCK_SECTOR (0x00E4).
 *
 * <p>You can have MSG_STM_FLASH_UNLOCK_SECTOR inherent its fields directly from an inherited SBP
 * object, or construct it inline using a dict of its fields.
 *
 * <p>The flash unlock message unlocks a sector of the STM flash memory. The device replies with a
 * MSG_FLASH_DONE message.
 */
public class MsgStmFlashUnlockSector extends SBPMessage {
    public static final int TYPE = 0x00E4;

    /** Flash sector number to unlock */
    public long sector;

    public MsgStmFlashUnlockSector(int sender) {
        super(sender, TYPE);
    }

    public MsgStmFlashUnlockSector() {
        super(TYPE);
    }

    public MsgStmFlashUnlockSector(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type == TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        sector = parser.getU32();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU32(sector);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("sector", sector);
        return obj;
    }
}
