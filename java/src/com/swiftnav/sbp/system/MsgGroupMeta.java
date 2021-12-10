/* Copyright (C) 2015-2021 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */
package com.swiftnav.sbp.system;

// This file was auto-generated from yaml/swiftnav/sbp/system.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import org.json.JSONArray;
import org.json.JSONObject;

/**
 * SBP class for message MSG_GROUP_META (0xFF0A).
 *
 * <p>You can have MSG_GROUP_META inherent its fields directly from an inherited SBP object, or
 * construct it inline using a dict of its fields.
 *
 * <p>This leading message lists the time metadata of the Solution Group. It also lists the atomic
 * contents (i.e. types of messages included) of the Solution Group.
 */
public class MsgGroupMeta extends SBPMessage {
    public static final int TYPE = 0xFF0A;

    /** Id of the Msgs Group, 0 is Unknown, 1 is Bestpos, 2 is Gnss */
    public int group_id;

    /** Status flags (reserved) */
    public int flags;

    /** Size of list group_msgs */
    public int n_group_msgs;

    /**
     * An in-order list of message types included in the Solution Group, including GROUP_META itself
     */
    public int[] group_msgs;

    public MsgGroupMeta(int sender) {
        super(sender, TYPE);
    }

    public MsgGroupMeta() {
        super(TYPE);
    }

    public MsgGroupMeta(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type == TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        group_id = parser.getU8();
        flags = parser.getU8();
        n_group_msgs = parser.getU8();
        group_msgs = parser.getArrayofU16();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU8(group_id);
        builder.putU8(flags);
        builder.putU8(n_group_msgs);
        builder.putArrayofU16(group_msgs);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("group_id", group_id);
        obj.put("flags", flags);
        obj.put("n_group_msgs", n_group_msgs);
        obj.put("group_msgs", new JSONArray(group_msgs));
        return obj;
    }
}
