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


/** SBP class for message MSG_STM_UNIQUE_ID_REQ (0x00E8).
 *
 * You can have MSG_STM_UNIQUE_ID_REQ inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
 * This message reads the device's hardcoded unique ID. The host
 * requests the ID by sending a MSG_STM_UNIQUE_ID_REQ. The device
 * responds with a MSG_STM_UNIQUE_ID_RESP with the 12-byte unique
 * ID in the payload. */

public class MsgStmUniqueIdReq extends SBPMessage {
    public static final int TYPE = 0x00E8;

    

    public MsgStmUniqueIdReq (int sender) { super(sender, TYPE); }
    public MsgStmUniqueIdReq () { super(TYPE); }
    public MsgStmUniqueIdReq (SBPMessage msg) throws SBPBinaryException {
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