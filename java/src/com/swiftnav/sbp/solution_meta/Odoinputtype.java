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

package com.swiftnav.sbp.solution_meta;

import java.math.BigInteger;

import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPStruct;

import org.json.JSONObject;
import org.json.JSONArray;


/** SBP class for message OdoInputType (0xFFE9).
 *
 * You can have OdoInputType inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
 * Metadata around the Odometry sensors involved in the fuzed solution.
 * Note: Just to build descriptive tables in documentation and not actually used. */

public class Odoinputtype extends SBPMessage {
    public static final int TYPE = 0xFFE9;

    
    /** flags that store all relevant info specific to this sensor type. */
    public int flags;
    

    public Odoinputtype (int sender) { super(sender, TYPE); }
    public Odoinputtype () { super(TYPE); }
    public Odoinputtype (SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type != TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        flags = parser.getU8();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU8(flags);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("flags", flags);
        return obj;
    }
}