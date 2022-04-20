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
 * SBP class for message MSG_COMMAND_OUTPUT (0x00BC).
 *
 * <p>You can have MSG_COMMAND_OUTPUT inherent its fields directly from an inherited SBP object, or
 * construct it inline using a dict of its fields.
 *
 * <p>Returns the standard output and standard error of the command requested by MSG_COMMAND_REQ.
 * The sequence number can be used to filter for filtering the correct command.
 */
public class MsgCommandOutput extends SBPMessage {
    public static final int TYPE = 0x00BC;

    /** Sequence number */
    public long sequence;

    /** Line of standard output or standard error */
    public String line;

    public MsgCommandOutput(int sender) {
        super(sender, TYPE);
    }

    public MsgCommandOutput() {
        super(TYPE);
    }

    public MsgCommandOutput(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type == TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        sequence = parser.getU32();
        line = parser.getString();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU32(sequence);
        builder.putString(line);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("sequence", sequence);
        obj.put("line", line);
        return obj;
    }
}
