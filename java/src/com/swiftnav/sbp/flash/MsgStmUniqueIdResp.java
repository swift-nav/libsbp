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


/** SBP class for message MSG_STM_UNIQUE_ID_RESP (0x00E5).
 *
 * You can have MSG_STM_UNIQUE_ID_RESP inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
 * This message reads the device's hardcoded unique ID. The host
 * requests the ID by sending a MSG_STM_UNIQUE_ID_REQ. The device
 * responds with a MSG_STM_UNIQUE_ID_RESP with the 12-byte unique
 * ID in the payload.. */

public class MsgStmUniqueIdResp extends SBPMessage {
    public static final int TYPE = 0x00E5;

    
    /** Device unique ID */
    public int[] stm_id;
    

    public MsgStmUniqueIdResp (int sender) { super(sender, TYPE); }
    public MsgStmUniqueIdResp () { super(TYPE); }
    public MsgStmUniqueIdResp (SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type != TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        stm_id = parser.getArrayofU8(12);
    }

    @Override
    protected void build(Builder builder) {
        builder.putArrayofU8(stm_id, 12);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("stm_id", new JSONArray(stm_id));
        return obj;
    }
}