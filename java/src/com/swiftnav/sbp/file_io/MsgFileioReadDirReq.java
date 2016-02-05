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


/** SBP class for message MSG_FILEIO_READ_DIR_REQ (0x00A9).
 *
 * You can have MSG_FILEIO_READ_DIR_REQ inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
 * The read directory message lists the files in a directory on the
 * device's onboard flash file system.  The offset parameter can be
 * used to skip the first n elements of the file list. Returns a
 * MSG_FILEIO_READ_DIR_RESP message containing the directory
 * listings as a NULL delimited list. The listing is chunked over
 * multiple SBP packets. The sequence number in the request will be
 * returned in the response.  If message is invalid, a followup
 * MSG_PRINT message will print "Invalid fileio read message".
 * A device will only respond to this message when it is received
 * from sender ID 0x42. */

public class MsgFileioReadDirReq extends SBPMessage {
    public static final int TYPE = 0x00A9;

    
    /** Read sequence number */
    public long sequence;
    
    /** The offset to skip the first n elements of the file list
 */
    public long offset;
    
    /** Name of the directory to list */
    public String dirname;
    

    public MsgFileioReadDirReq (int sender) { super(sender, TYPE); }
    public MsgFileioReadDirReq () { super(TYPE); }
    public MsgFileioReadDirReq (SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type != TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        sequence = parser.getU32();
        offset = parser.getU32();
        dirname = parser.getString();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU32(sequence);
        builder.putU32(offset);
        builder.putString(dirname);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("sequence", sequence);
        obj.put("offset", offset);
        obj.put("dirname", dirname);
        return obj;
    }
}