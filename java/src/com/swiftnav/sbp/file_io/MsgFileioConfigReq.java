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
import org.json.JSONObject;

/**
 * SBP class for message MSG_FILEIO_CONFIG_REQ (0x1001).
 *
 * <p>You can have MSG_FILEIO_CONFIG_REQ inherent its fields directly from an inherited SBP object,
 * or construct it inline using a dict of its fields.
 *
 * <p>Requests advice on the optimal configuration for a FileIO transfer. Newer version of FileIO
 * can support greater throughput by supporting a large window of FileIO data that can be in-flight
 * during read or write operations.
 */
public class MsgFileioConfigReq extends SBPMessage {
    public static final int TYPE = 0x1001;

    /** Advice sequence number */
    public long sequence;

    public MsgFileioConfigReq(int sender) {
        super(sender, TYPE);
    }

    public MsgFileioConfigReq() {
        super(TYPE);
    }

    public MsgFileioConfigReq(SBPMessage msg) throws SBPBinaryException {
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
