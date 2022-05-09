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
package com.swiftnav.sbp.integrity;

// This file was auto-generated from yaml/swiftnav/sbp/integrity.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPStruct;
import com.swiftnav.sbp.gnss.*;
import org.json.JSONObject;

public class MsgSsrFlagIonoGridPointSatLos extends SBPMessage {
    public static final int TYPE = 0x0BD1;

    /** Header of an integrity message. */
    public IntegritySSRHeader header;

    /** Index of the grid point. */
    public int grid_point_id;

    /** Number of faulty LOS. */
    public int n_faulty_los;

    /** List of faulty LOS */
    public SvId[] faulty_los;

    public MsgSsrFlagIonoGridPointSatLos(int sender) {
        super(sender, TYPE);
    }

    public MsgSsrFlagIonoGridPointSatLos() {
        super(TYPE);
    }

    public MsgSsrFlagIonoGridPointSatLos(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type == TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        header = new IntegritySSRHeader().parse(parser);
        grid_point_id = parser.getU16();
        n_faulty_los = parser.getU8();
        faulty_los = parser.getArray(SvId.class);
    }

    @Override
    protected void build(Builder builder) {
        header.build(builder);
        builder.putU16(grid_point_id);
        builder.putU8(n_faulty_los);
        builder.putArray(faulty_los);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("header", header.toJSON());
        obj.put("grid_point_id", grid_point_id);
        obj.put("n_faulty_los", n_faulty_los);
        obj.put("faulty_los", SBPStruct.toJSONArray(faulty_los));
        return obj;
    }
}
