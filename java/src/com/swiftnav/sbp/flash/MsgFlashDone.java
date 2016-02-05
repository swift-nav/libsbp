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


/** SBP class for message MSG_FLASH_DONE (0x00E0).
 *
 * You can have MSG_FLASH_DONE inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
 * This message defines success or failure codes for a variety of
 * flash memory requests from the host to the device. Flash read
 * and write messages, such as MSG_FLASH_READ_REQ, or
 * MSG_FLASH_PROGRAM, may return this message on failure. */

public class MsgFlashDone extends SBPMessage {
    public static final int TYPE = 0x00E0;

    
    /** Response flags */
    public int response;
    

    public MsgFlashDone (int sender) { super(sender, TYPE); }
    public MsgFlashDone () { super(TYPE); }
    public MsgFlashDone (SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type != TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        response = parser.getU8();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU8(response);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("response", response);
        return obj;
    }
}