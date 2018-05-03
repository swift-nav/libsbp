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


/** SBP class for message MSG_GLO_L1OF_RAW (0x7779).
 *
 * You can have MSG_GLO_L1OF_RAW inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
 * This message is sent once per 2 seconds per GLONASS satellite. ME checks the
 * parity of the data block and sends only blocks that pass the check. */

public class MsgGloL1OfRaw extends SBPMessage {
    public static final int TYPE = 0x7779;

    
    /** GNSS signal identifier. */
    public GnssSignal sid;
    
    /** GPS time-of-week at the start of the subframe. */
    public long tow;
    
    /** String number (1-15). */
    public int string_number;
    
    /** Raw string data field of 85 bits (last byte padded with zeros). */
    public int[] data;
    

    public MsgGloL1OfRaw (int sender) { super(sender, TYPE); }
    public MsgGloL1OfRaw () { super(TYPE); }
    public MsgGloL1OfRaw (SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type != TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        sid = new GnssSignal().parse(parser);
        tow = parser.getU32();
        string_number = parser.getU8();
        data = parser.getArrayofU8(11);
    }

    @Override
    protected void build(Builder builder) {
        sid.build(builder);
        builder.putU32(tow);
        builder.putU8(string_number);
        builder.putArrayofU8(data, 11);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("sid", sid.toJSON());
        obj.put("tow", tow);
        obj.put("string_number", string_number);
        obj.put("data", new JSONArray(data));
        return obj;
    }
}