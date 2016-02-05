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

package com.swiftnav.sbp.piksi;

import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPStruct;
import com.swiftnav.sbp.gnss_signal.*;

import org.json.JSONObject;
import org.json.JSONArray;


/** SBP class for message MSG_MASK_SATELLITE (0x001B).
 *
 * You can have MSG_MASK_SATELLITE inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
 * This message allows setting a mask to prevent a particular satellite
 * from being used in various Piksi subsystems. */

public class MsgMaskSatellite extends SBPMessage {
    public static final int TYPE = 0x001B;

    
    /** Mask of systems that should ignore this satellite. */
    public int mask;
    
    /** GNSS signal for which the mask is applied */
    public GnssSignal sid;
    

    public MsgMaskSatellite (int sender) { super(sender, TYPE); }
    public MsgMaskSatellite () { super(TYPE); }
    public MsgMaskSatellite (SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type != TYPE;
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