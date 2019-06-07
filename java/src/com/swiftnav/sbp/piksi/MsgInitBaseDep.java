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

package com.swiftnav.sbp.piksi;

import java.math.BigInteger;

import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPStruct;
import com.swiftnav.sbp.gnss.*;

import org.json.JSONObject;
import org.json.JSONArray;


/** SBP class for message MSG_INIT_BASE_DEP (0x0023).
 *
 * You can have MSG_INIT_BASE_DEP inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
* Deprecated */

public class MsgInitBaseDep extends SBPMessage {
    public static final int TYPE = 0x0023;

    

    public MsgInitBaseDep (int sender) { super(sender, TYPE); }
    public MsgInitBaseDep () { super(TYPE); }
    public MsgInitBaseDep (SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type != TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
    }

    @Override
    protected void build(Builder builder) {
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        return obj;
    }
}