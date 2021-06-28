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
package com.swiftnav.sbp.ssr;

// This file was auto-generated from yaml/swiftnav/sbp/ssr.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.gnss.*;
import org.json.JSONArray;
import org.json.JSONObject;

public class MsgSsrGridDefinitionDepA extends SBPMessage {
    public static final int TYPE = 0x05F5;

    /** Header of a Gridded Correction message */
    public GridDefinitionHeaderDepA header;

    /**
     * Run Length Encode list of quadrants that contain valid data. The spec describes the encoding
     * scheme in detail, but essentially the index of the quadrants that contain transitions between
     * valid and invalid (and vice versa) are encoded as u8 integers.
     */
    public int[] rle_list;

    public MsgSsrGridDefinitionDepA(int sender) {
        super(sender, TYPE);
    }

    public MsgSsrGridDefinitionDepA() {
        super(TYPE);
    }

    public MsgSsrGridDefinitionDepA(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type == TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        header = new GridDefinitionHeaderDepA().parse(parser);
        rle_list = parser.getArrayofU8();
    }

    @Override
    protected void build(Builder builder) {
        header.build(builder);
        builder.putArrayofU8(rle_list);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("header", header.toJSON());
        obj.put("rle_list", new JSONArray(rle_list));
        return obj;
    }
}
