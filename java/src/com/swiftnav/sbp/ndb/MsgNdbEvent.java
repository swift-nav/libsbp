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

package com.swiftnav.sbp.ndb;

import java.math.BigInteger;

import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPStruct;
import com.swiftnav.sbp.gnss.*;

import org.json.JSONObject;
import org.json.JSONArray;


/** SBP class for message MSG_NDB_EVENT (0x0400).
 *
 * You can have MSG_NDB_EVENT inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
 * This message is sent out when an object is stored into NDB. If needed
 * message could also be sent out when fetching an object from NDB. */

public class MsgNdbEvent extends SBPMessage {
    public static final int TYPE = 0x0400;

    
    /** HW time in milliseconds. */
    public BigInteger recv_time;
    
    /** Event type. */
    public int event;
    
    /** Event object type. */
    public int object_type;
    
    /** Event result. */
    public int result;
    
    /** Data source for STORE event, reserved for other events. */
    public int data_source;
    
    /** GNSS signal identifier,
If object_type is Ephemeris OR Almanac, sid indicates for which
signal the object belongs to. Reserved in other cases.
 */
    public GnssSignal object_sid;
    
    /** GNSS signal identifier,
If object_type is Almanac, Almanac WN, Iono OR L2C capabilities
AND data_source is NDB_DS_RECEIVER sid indicates from which SV
data was decoded. Reserved in other cases.
 */
    public GnssSignal src_sid;
    
    /** A unique identifier of the sending hardware. For v1.0,
set to the 2 least significant bytes of the device serial
number, valid only if data_source is NDB_DS_SBP. Reserved in case
of other data_source.
 */
    public int original_sender;
    

    public MsgNdbEvent (int sender) { super(sender, TYPE); }
    public MsgNdbEvent () { super(TYPE); }
    public MsgNdbEvent (SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type != TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        recv_time = parser.getU64();
        event = parser.getU8();
        object_type = parser.getU8();
        result = parser.getU8();
        data_source = parser.getU8();
        object_sid = new GnssSignal().parse(parser);
        src_sid = new GnssSignal().parse(parser);
        original_sender = parser.getU16();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU64(recv_time);
        builder.putU8(event);
        builder.putU8(object_type);
        builder.putU8(result);
        builder.putU8(data_source);
        object_sid.build(builder);
        src_sid.build(builder);
        builder.putU16(original_sender);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("recv_time", recv_time);
        obj.put("event", event);
        obj.put("object_type", object_type);
        obj.put("result", result);
        obj.put("data_source", data_source);
        obj.put("object_sid", object_sid.toJSON());
        obj.put("src_sid", src_sid.toJSON());
        obj.put("original_sender", original_sender);
        return obj;
    }
}