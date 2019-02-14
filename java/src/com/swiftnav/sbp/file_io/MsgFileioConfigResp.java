/*
 * Copyright (C) 2015-2018 Swift Navigation Inc.
 * Contact: Swift Navigation <dev@swiftnav.com>
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

package com.swiftnav.sbp.file_io;

import java.math.BigInteger;

import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPStruct;

import org.json.JSONObject;
import org.json.JSONArray;


/** SBP class for message MSG_FILEIO_CONFIG_RESP (0x1002).
 *
 * You can have MSG_FILEIO_CONFIG_RESP inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
 * The advice on the optimal configuration for a FileIO
 * transfer.  Newer version of FileIO can support greater
 * throughput by supporting a large window of FileIO data
 * that can be in-flight during read or write operations. */

public class MsgFileioConfigResp extends SBPMessage {
    public static final int TYPE = 0x1002;

    
    /** Advice sequence number */
    public long sequence;
    
    /** The number of SBP packets in the data in-flight window */
    public long window_size;
    
    /** The number of SBP packets sent in one PDU */
    public long batch_size;
    
    /** The version of FileIO that is supported */
    public long fileio_version;
    

    public MsgFileioConfigResp (int sender) { super(sender, TYPE); }
    public MsgFileioConfigResp () { super(TYPE); }
    public MsgFileioConfigResp (SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type != TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        sequence = parser.getU32();
        window_size = parser.getU32();
        batch_size = parser.getU32();
        fileio_version = parser.getU32();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU32(sequence);
        builder.putU32(window_size);
        builder.putU32(batch_size);
        builder.putU32(fileio_version);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("sequence", sequence);
        obj.put("window_size", window_size);
        obj.put("batch_size", batch_size);
        obj.put("fileio_version", fileio_version);
        return obj;
    }
}