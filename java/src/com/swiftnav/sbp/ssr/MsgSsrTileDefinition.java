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
package com.swiftnav.sbp.ssr;

// This file was auto-generated from yaml/swiftnav/sbp/ssr.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.gnss.*;
import org.json.JSONArray;
import org.json.JSONObject;

/**
 * SBP class for message MSG_SSR_TILE_DEFINITION (0x05F7).
 *
 * <p>You can have MSG_SSR_TILE_DEFINITION inherent its fields directly from an inherited SBP
 * object, or construct it inline using a dict of its fields.
 *
 * <p>Provides the correction point coordinates for the atmospheric correction values in the
 * MSG_SSR_STEC_CORRECTION and MSG_SSR_GRIDDED_CORRECTION messages.
 *
 * <p>Based on ETSI TS 137 355 V16.1.0 (LTE Positioning Protocol) information element
 * GNSS-SSR-CorrectionPoints. SBP only supports gridded arrays of correction points, not lists of
 * points.
 */
public class MsgSsrTileDefinition extends SBPMessage {
    public static final int TYPE = 0x05F7;

    public int[] stub;

    public MsgSsrTileDefinition(int sender) {
        super(sender, TYPE);
    }

    public MsgSsrTileDefinition() {
        super(TYPE);
    }

    public MsgSsrTileDefinition(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type == TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        stub = parser.getArrayofU8();
    }

    @Override
    protected void build(Builder builder) {
        builder.putArrayofU8(stub);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("stub", new JSONArray(stub));
        return obj;
    }
}
