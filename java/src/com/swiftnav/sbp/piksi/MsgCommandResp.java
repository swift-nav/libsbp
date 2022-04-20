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
package com.swiftnav.sbp.piksi;

// This file was auto-generated from yaml/swiftnav/sbp/piksi.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.gnss.*;
import org.json.JSONObject;

/**
 * SBP class for message MSG_COMMAND_RESP (0x00B9).
 *
 * <p>You can have MSG_COMMAND_RESP inherent its fields directly from an inherited SBP object, or
 * construct it inline using a dict of its fields.
 *
 * <p>The response to MSG_COMMAND_REQ with the return code of the command. A return code of zero
 * indicates success.
 */
public class MsgCommandResp extends SBPMessage {
    public static final int TYPE = 0x00B9;

    /** Sequence number */
    public long sequence;

    /** Exit code */
    public int code;

    public MsgCommandResp(int sender) {
        super(sender, TYPE);
    }

    public MsgCommandResp() {
        super(TYPE);
    }

    public MsgCommandResp(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type == TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        sequence = parser.getU32();
        code = parser.getS32();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU32(sequence);
        builder.putS32(code);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("sequence", sequence);
        obj.put("code", code);
        return obj;
    }
}
