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
package com.swiftnav.sbp.file_io;

// This file was auto-generated from yaml/swiftnav/sbp/file_io.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import org.json.JSONArray;
import org.json.JSONObject;

/**
 * SBP class for message MSG_FILEIO_READ_RESP (0x00A3).
 *
 * <p>You can have MSG_FILEIO_READ_RESP inherent its fields directly from an inherited SBP object,
 * or construct it inline using a dict of its fields.
 *
 * <p>The file read message reads a certain length (up to 255 bytes) from a given offset into a
 * file, and returns the data in a message where the message length field indicates how many bytes
 * were successfully read. The sequence number in the response is preserved from the request.
 */
public class MsgFileioReadResp extends SBPMessage {
    public static final int TYPE = 0x00A3;

    /** Read sequence number */
    public long sequence;

    /** Contents of read file */
    public int[] contents;

    public MsgFileioReadResp(int sender) {
        super(sender, TYPE);
    }

    public MsgFileioReadResp() {
        super(TYPE);
    }

    public MsgFileioReadResp(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type == TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        sequence = parser.getU32();
        contents = parser.getArrayofU8();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU32(sequence);
        builder.putArrayofU8(contents);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("sequence", sequence);
        obj.put("contents", new JSONArray(contents));
        return obj;
    }
}
