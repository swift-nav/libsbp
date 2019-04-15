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


/** SBP class for message MSG_OSR (0x0640).
 *
 * You can have MSG_OSR inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
 * The OSR message contains network corrections in an observation-like format */

public class MsgOsr extends SBPMessage {
    public static final int TYPE = 0x0640;

    
    /** Header of a GPS observation message */
    public ObservationHeader header;
    
    /** Network correction for a
satellite signal.
 */
    public PackedOsrContent[] obs;
    

    public MsgOsr (int sender) { super(sender, TYPE); }
    public MsgOsr () { super(TYPE); }
    public MsgOsr (SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type != TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        header = new ObservationHeader().parse(parser);
        obs = parser.getArray(PackedOsrContent.class);
    }

    @Override
    protected void build(Builder builder) {
        header.build(builder);
        builder.putArray(obs);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("header", header.toJSON());
        obj.put("obs", SBPStruct.toJSONArray(obs));
        return obj;
    }
}