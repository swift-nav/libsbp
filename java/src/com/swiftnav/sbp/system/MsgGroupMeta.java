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

package com.swiftnav.sbp.system;

import java.math.BigInteger;

import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPStruct;

import org.json.JSONObject;
import org.json.JSONArray;


/** SBP class for message MSG_GROUP_META (0xFF0A).
 *
 * You can have MSG_GROUP_META inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
 * This leading message lists the time metadata of the Solution Group.
 * It also lists the atomic contents (i.e. types of messages included) of the Solution Group. */

public class MsgGroupMeta extends SBPMessage {
    public static final int TYPE = 0xFF0A;

    
    /** GPS Week Number */
    public int wn;
    
    /** GPS time of week rounded to the nearest millisecond */
    public long tow;
    
    /** Status flags (reserved) */
    public int flags;
    
    /** An inorder list of message types included in the Solution Group */
    public int[] group_msgs;
    

    public MsgGroupMeta (int sender) { super(sender, TYPE); }
    public MsgGroupMeta () { super(TYPE); }
    public MsgGroupMeta (SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type != TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        wn = parser.getU16();
        tow = parser.getU32();
        flags = parser.getU8();
        group_msgs = parser.getArrayofU16();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU16(wn);
        builder.putU32(tow);
        builder.putU8(flags);
        builder.putArrayofU16(group_msgs);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("wn", wn);
        obj.put("tow", tow);
        obj.put("flags", flags);
        obj.put("group_msgs", new JSONArray(group_msgs));
        return obj;
    }
}