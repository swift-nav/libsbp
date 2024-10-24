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
package com.swiftnav.sbp.piksi;

// This file was auto-generated from yaml/swiftnav/sbp/piksi.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.gnss.*;
import org.json.JSONObject;

/**
 * SBP class for message MSG_RESET_FILTERS (0x0022).
 *
 * <p>You can have MSG_RESET_FILTERS inherent its fields directly from an inherited SBP object, or
 * construct it inline using a dict of its fields.
 *
 * <p>This message resets either the DGNSS Kalman filters or Integer Ambiguity Resolution (IAR)
 * process.
 */
public class MsgResetFilters extends SBPMessage {
    public static final int TYPE = 0x0022;

    /** Filter flags */
    public int filter;

    public MsgResetFilters(int sender) {
        super(sender, TYPE);
    }

    public MsgResetFilters() {
        super(TYPE);
    }

    public MsgResetFilters(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        if (msg.type != TYPE)
            throw new SBPBinaryException(
                    "Type mismatch for MsgResetFilters, expected 34, actual " + msg.type);
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        filter = parser.getU8();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU8(filter);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("filter", filter);
        return obj;
    }

    @Override
    public String getFriendlyName() {
        return "RESET FILTERS";
    }
}
