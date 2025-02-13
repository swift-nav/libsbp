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
 * SBP class for message MSG_MASK_SATELLITE_DEP (0x001B).
 *
 * <p>You can have MSG_MASK_SATELLITE_DEP inherent its fields directly from an inherited SBP object,
 * or construct it inline using a dict of its fields.
 *
 * <p>Deprecated.
 */
public class MsgMaskSatelliteDep extends SBPMessage {
    public static final int TYPE = 0x001B;

    /** Mask of systems that should ignore this satellite. */
    public int mask;

    /** GNSS signal for which the mask is applied */
    public GnssSignalDep sid;

    public MsgMaskSatelliteDep(int sender) {
        super(sender, TYPE);
    }

    public MsgMaskSatelliteDep() {
        super(TYPE);
    }

    public MsgMaskSatelliteDep(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        if (msg.type != TYPE)
            throw new SBPBinaryException(
                    "Type mismatch for MsgMaskSatelliteDep, expected 27, actual " + msg.type);
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        mask = parser.getU8();
        sid = new GnssSignalDep().parse(parser);
    }

    @Override
    protected void build(Builder builder) {
        builder.putU8(mask);
        sid.build(builder);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("mask", mask);
        obj.put("sid", sid.toJSON());
        return obj;
    }

    @Override
    public String getFriendlyName() {
        return "MASK SATELLITE DEP";
    }
}
