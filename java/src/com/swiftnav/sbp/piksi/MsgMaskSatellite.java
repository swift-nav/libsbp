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
package com.swiftnav.sbp.piksi;

// This file was auto-generated from yaml/swiftnav/sbp/piksi.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.gnss.*;
import org.json.JSONObject;

/**
 * SBP class for message MSG_MASK_SATELLITE (0x002B).
 *
 * <p>You can have MSG_MASK_SATELLITE inherent its fields directly from an inherited SBP object, or
 * construct it inline using a dict of its fields.
 *
 * <p>This message allows setting a mask to prevent a particular satellite from being used in
 * various Piksi subsystems.
 */
public class MsgMaskSatellite extends SBPMessage {
    public static final int TYPE = 0x002B;

    /** Mask of systems that should ignore this satellite. */
    public int mask;

    /** GNSS signal for which the mask is applied */
    public GnssSignal sid;

    public MsgMaskSatellite(int sender) {
        super(sender, TYPE);
    }

    public MsgMaskSatellite() {
        super(TYPE);
    }

    public MsgMaskSatellite(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type == TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        mask = parser.getU8();
        sid = new GnssSignal().parse(parser);
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
}
