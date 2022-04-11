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
package com.swiftnav.sbp.file_io;

// This file was auto-generated from yaml/swiftnav/sbp/file_io.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import org.json.JSONObject;

/**
 * SBP class for message MSG_FILEIO_WRITE_RESP (0x00AB).
 *
 * <p>You can have MSG_FILEIO_WRITE_RESP inherent its fields directly from an inherited SBP object,
 * or construct it inline using a dict of its fields.
 *
 * <p>The file write message writes a certain length (up to 255 bytes) of data to a file at a given
 * offset. The message is a copy of the original MSG_FILEIO_WRITE_REQ message to check integrity of
 * the write. The sequence number in the response is preserved from the request.
 */
public class MsgFileioWriteResp extends SBPMessage {
    public static final int TYPE = 0x00AB;

    /** Write sequence number */
    public long sequence;

    public MsgFileioWriteResp(int sender) {
        super(sender, TYPE);
    }

    public MsgFileioWriteResp() {
        super(TYPE);
    }

    public MsgFileioWriteResp(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type == TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        sequence = parser.getU32();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU32(sequence);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("sequence", sequence);
        return obj;
    }
}
