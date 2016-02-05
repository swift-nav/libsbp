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


/** SBP class for message MSG_FILEIO_REMOVE (0x00AC).
 *
 * You can have MSG_FILEIO_REMOVE inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
 * The file remove message deletes a file from the file system.
 * If the message is invalid, a followup MSG_PRINT message will
 * print "Invalid fileio remove message". A device will only
 * process this message when it is received from sender ID 0x42. */

public class MsgFileioRemove extends SBPMessage {
    public static final int TYPE = 0x00AC;

    
    /** Name of the file to delete */
    public String filename;
    

    public MsgFileioRemove (int sender) { super(sender, TYPE); }
    public MsgFileioRemove () { super(TYPE); }
    public MsgFileioRemove (SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type != TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        filename = parser.getString();
    }

    @Override
    protected void build(Builder builder) {
        builder.putString(filename);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("filename", filename);
        return obj;
    }
}