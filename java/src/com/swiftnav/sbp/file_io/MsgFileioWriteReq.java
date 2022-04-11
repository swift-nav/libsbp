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
import org.json.JSONArray;
import org.json.JSONObject;

/**
 * SBP class for message MSG_FILEIO_WRITE_REQ (0x00AD).
 *
 * <p>You can have MSG_FILEIO_WRITE_REQ inherent its fields directly from an inherited SBP object,
 * or construct it inline using a dict of its fields.
 *
 * <p>The file write message writes a certain length (up to 255 bytes) of data to a file at a given
 * offset. Returns a copy of the original MSG_FILEIO_WRITE_RESP message to check integrity of the
 * write. The sequence number in the request will be returned in the response. If message is
 * invalid, a followup MSG_PRINT message will print "Invalid fileio write message". A device will
 * only process this message when it is received from sender ID 0x42.
 */
public class MsgFileioWriteReq extends SBPMessage {
    public static final int TYPE = 0x00AD;

    /** Write sequence number */
    public long sequence;

    /** Offset into the file at which to start writing in bytes */
    public long offset;

    /** Name of the file to write to */
    public String filename;

    /** Variable-length array of data to write */
    public int[] data;

    public MsgFileioWriteReq(int sender) {
        super(sender, TYPE);
    }

    public MsgFileioWriteReq() {
        super(TYPE);
    }

    public MsgFileioWriteReq(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type == TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        sequence = parser.getU32();
        offset = parser.getU32();
        filename = parser.getString();
        data = parser.getArrayofU8();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU32(sequence);
        builder.putU32(offset);
        builder.putString(filename);
        builder.putArrayofU8(data);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("sequence", sequence);
        obj.put("offset", offset);
        obj.put("filename", filename);
        obj.put("data", new JSONArray(data));
        return obj;
    }
}
