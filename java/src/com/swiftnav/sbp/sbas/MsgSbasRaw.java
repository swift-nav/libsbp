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

package com.swiftnav.sbp.sbas;

import java.math.BigInteger;

import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPStruct;
import com.swiftnav.sbp.gnss.*;

import org.json.JSONObject;
import org.json.JSONArray;


/** SBP class for message MSG_SBAS_RAW (0x7777).
 *
 * You can have MSG_SBAS_RAW inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
 * This message is sent once per second per SBAS satellite. ME checks the
 * parity of the data block and sends only blocks that pass the check. */

public class MsgSbasRaw extends SBPMessage {
    public static final int TYPE = 0x7777;

    
    /** GNSS signal identifier. */
    public GnssSignal sid;
    
    /** GPS time-of-week at the start of the data block. */
    public long tow;
    
    /** SBAS message type (0-63) */
    public int message_type;
    
    /** Raw SBAS data field of 212 bits (last byte padded with zeros). */
    public int[] data;
    

    public MsgSbasRaw (int sender) { super(sender, TYPE); }
    public MsgSbasRaw () { super(TYPE); }
    public MsgSbasRaw (SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type != TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        sid = new GnssSignal().parse(parser);
        tow = parser.getU32();
        message_type = parser.getU8();
        data = parser.getArrayofU8(27);
    }

    @Override
    protected void build(Builder builder) {
        sid.build(builder);
        builder.putU32(tow);
        builder.putU8(message_type);
        builder.putArrayofU8(data, 27);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("sid", sid.toJSON());
        obj.put("tow", tow);
        obj.put("message_type", message_type);
        obj.put("data", new JSONArray(data));
        return obj;
    }
}