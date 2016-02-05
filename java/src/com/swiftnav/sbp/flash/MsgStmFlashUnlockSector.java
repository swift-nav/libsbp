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

package com.swiftnav.sbp.flash;

import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPStruct;

import org.json.JSONObject;
import org.json.JSONArray;


/** SBP class for message MSG_STM_FLASH_UNLOCK_SECTOR (0x00E4).
 *
 * You can have MSG_STM_FLASH_UNLOCK_SECTOR inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
 * The flash unlock message unlocks a sector of the STM flash
 * memory. The device replies with a MSG_FLASH_DONE message. */

public class MsgStmFlashUnlockSector extends SBPMessage {
    public static final int TYPE = 0x00E4;

    
    /** Flash sector number to unlock */
    public long sector;
    

    public MsgStmFlashUnlockSector (int sender) { super(sender, TYPE); }
    public MsgStmFlashUnlockSector () { super(TYPE); }
    public MsgStmFlashUnlockSector (SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type != TYPE;
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