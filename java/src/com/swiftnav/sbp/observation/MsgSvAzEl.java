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

package com.swiftnav.sbp.observation;

import java.math.BigInteger;

import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPStruct;
import com.swiftnav.sbp.gnss.*;

import org.json.JSONObject;
import org.json.JSONArray;


/** SBP class for message MSG_SV_AZ_EL (0x0097).
 *
 * You can have MSG_SV_AZ_EL inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
 * Azimuth and elevation angles of all the visible satellites
 * that the device does have ephemeris or almanac for. */

public class MsgSvAzEl extends SBPMessage {
    public static final int TYPE = 0x0097;

    
    /** Azimuth and elevation per satellite */
    public SvAzEl[] azel;
    

    public MsgSvAzEl (int sender) { super(sender, TYPE); }
    public MsgSvAzEl () { super(TYPE); }
    public MsgSvAzEl (SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type != TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        azel = parser.getArray(SvAzEl.class);
    }

    @Override
    protected void build(Builder builder) {
        builder.putArray(azel);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("azel", SBPStruct.toJSONArray(azel));
        return obj;
    }
}