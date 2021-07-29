/* Copyright (C) 2015-2021 Swift Navigation Inc.
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
 * SBP class for message MSG_STM_UNIQUE_ID_REQ (0x00E8).
 *
 * <p>You can have MSG_STM_UNIQUE_ID_REQ inherent its fields directly from an inherited SBP object,
 * or construct it inline using a dict of its fields.
 *
 * <p>This message reads the device's hard-coded unique ID. The host requests the ID by sending a
 * MSG_STM_UNIQUE_ID_REQ. The device responds with a MSG_STM_UNIQUE_ID_RESP with the 12-byte unique
 * ID in the payload.
 */
public class MsgStmUniqueIdReq extends SBPMessage {
    public static final int TYPE = 0x00E8;

    public MsgStmUniqueIdReq(int sender) {
        super(sender, TYPE);
    }

    public MsgStmUniqueIdReq() {
        super(TYPE);
    }

    public MsgStmUniqueIdReq(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type == TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        // No additional fields
    }

    @Override
    protected void build(Builder builder) {
        // No additional fields
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        return obj;
    }
}
