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

package com.swiftnav.sbp.raw;

import java.math.BigInteger;

import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPStruct;
import com.swiftnav.sbp.gnss.*;

import org.json.JSONObject;
import org.json.JSONArray;


/** SBP class for message MSG_GPS_L1CA_RAW (0x7778).
 *
 * You can have MSG_GPS_L1CA_RAW inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
 * This message is sent once per 6 seconds per GPS satellite. ME checks the
 * parity of the data block and sends only blocks that pass the check. */

public class MsgGPSL1CaRaw extends SBPMessage {
    public static final int TYPE = 0x7778;

    
    /** GNSS signal identifier. */
    public GnssSignal sid;
    
    /** GPS time-of-week at the start of the subframe. */
    public long tow;
    
    /** Subframe ID (1-5). */
    public int subframe_id;
    
    /** Raw subframe data field of 300 bits (last byte padded with zeros). */
    public int[] data;
    

    public MsgGPSL1CaRaw (int sender) { super(sender, TYPE); }
    public MsgGPSL1CaRaw () { super(TYPE); }
    public MsgGPSL1CaRaw (SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type != TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        sid = new GnssSignal().parse(parser);
        tow = parser.getU32();
        subframe_id = parser.getU8();
        data = parser.getArrayofU8(38);
    }

    @Override
    protected void build(Builder builder) {
        sid.build(builder);
        builder.putU32(tow);
        builder.putU8(subframe_id);
        builder.putArrayofU8(data, 38);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("sid", sid.toJSON());
        obj.put("tow", tow);
        obj.put("subframe_id", subframe_id);
        obj.put("data", new JSONArray(data));
        return obj;
    }
}