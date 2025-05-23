/* Copyright (C) 2015-2022 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be distributed together with this source. All other rights reserved.
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
import com.swiftnav.sbp.gnss.*;
import org.json.JSONArray;
import org.json.JSONObject;

public class MsgSsrFlagTropoGridPoints extends SBPMessage {
    public static final int TYPE = 0x0BC3;

    /** Header of an integrity message. */
    public IntegritySSRHeader header;

    /** Number of faulty grid points. */
    public int n_faulty_points;

    /** List of faulty grid points. */
    public int[] faulty_points;

    public MsgSsrFlagTropoGridPoints(int sender) {
        super(sender, TYPE);
    }

    public MsgSsrFlagTropoGridPoints() {
        super(TYPE);
    }

    public MsgSsrFlagTropoGridPoints(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        if (msg.type != TYPE)
            throw new SBPBinaryException(
                    "Type mismatch for MsgSsrFlagTropoGridPoints, expected 3011, actual "
                            + msg.type);
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        header = new IntegritySSRHeader().parse(parser);
        n_faulty_points = parser.getU8();
        faulty_points = parser.getArrayofU16();
    }

    @Override
    protected void build(Builder builder) {
        header.build(builder);
        builder.putU8(n_faulty_points);
        builder.putArrayofU16(faulty_points);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("header", header.toJSON());
        obj.put("n_faulty_points", n_faulty_points);
        obj.put("faulty_points", new JSONArray(faulty_points));
        return obj;
    }

    @Override
    public String getFriendlyName() {
        return "SSR FLAG TROPO GRID POINTS";
    }
}
