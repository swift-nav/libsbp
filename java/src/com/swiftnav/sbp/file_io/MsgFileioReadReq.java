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

package com.swiftnav.sbp.file_io;

import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPStruct;

import org.json.JSONObject;
import org.json.JSONArray;


/** SBP class for message MSG_FILEIO_READ_REQ (0x00A8).
 *
 * You can have MSG_FILEIO_READ_REQ inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
 * The file read message reads a certain length (up to 255 bytes)
 * from a given offset into a file, and returns the data in a
 * MSG_FILEIO_READ_RESP message where the message length field
 * indicates how many bytes were succesfully read.The sequence
 * number in the request will be returned in the response.
 * If the message is invalid, a followup MSG_PRINT message will
 * print "Invalid fileio read message". A device will only respond
 * to this message when it is received from sender ID 0x42. */

public class MsgFileioReadReq extends SBPMessage {
    public static final int TYPE = 0x00A8;

    
    /** Read sequence number */
    public long sequence;
    
    /** File offset */
    public long offset;
    
    /** Chunk size to read */
    public int chunk_size;
    
    /** Name of the file to read from */
    public String filename;
    

    public MsgFileioReadReq (int sender) { super(sender, TYPE); }
    public MsgFileioReadReq () { super(TYPE); }
    public MsgFileioReadReq (SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type != TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        sequence = parser.getU32();
        offset = parser.getU32();
        chunk_size = parser.getU8();
        filename = parser.getString();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU32(sequence);
        builder.putU32(offset);
        builder.putU8(chunk_size);
        builder.putString(filename);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("sequence", sequence);
        obj.put("offset", offset);
        obj.put("chunk_size", chunk_size);
        obj.put("filename", filename);
        return obj;
    }
}