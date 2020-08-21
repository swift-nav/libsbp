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

    
    /** Id of the Msgs Group, 0 is Unknown, 1 is Bestpos, 2 is Gnss */
    public int group_id;
    
    /** GPS Week Number or zero if Reference epoch is not GPS */
    public int wn;
    
    /** Time of Measurement in Milliseconds since reference epoch */
    public long tom;
    
    /** Nanosecond residual of millisecond-rounded TOM (ranges
from -500000 to 500000)
 */
    public int ns_residual;
    
    /** Status flags (reserved) */
    public int flags;
    
    /** Size of list group_msgs */
    public int n_group_msgs;
    
    /** An inorder list of message types included in the Solution Group,
including GROUP_META itself
 */
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
        group_id = parser.getU8();
        wn = parser.getU16();
        tom = parser.getU32();
        ns_residual = parser.getS32();
        flags = parser.getU8();
        n_group_msgs = parser.getU8();
        group_msgs = parser.getArrayofU16();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU8(group_id);
        builder.putU16(wn);
        builder.putU32(tom);
        builder.putS32(ns_residual);
        builder.putU8(flags);
        builder.putU8(n_group_msgs);
        builder.putArrayofU16(group_msgs);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("group_id", group_id);
        obj.put("wn", wn);
        obj.put("tom", tom);
        obj.put("ns_residual", ns_residual);
        obj.put("flags", flags);
        obj.put("n_group_msgs", n_group_msgs);
        obj.put("group_msgs", new JSONArray(group_msgs));
        return obj;
    }
}