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


/** SBP class for message MSG_CSAC_TELEMETRY (0xFF04).
 *
 * You can have MSG_CSAC_TELEMETRY inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
 * The CSAC telemetry message has an implementation defined telemetry string
 * from a device. It is not produced or available on general Swift Products.
 * It is intended to be a low rate message for status purposes. */

public class MsgCsacTelemetry extends SBPMessage {
    public static final int TYPE = 0xFF04;

    
    /** Index representing the type of telemetry in use.  It is implemention defined. */
    public int id;
    
    /** Comma separated list of values as defined by the index */
    public String telemetry;
    

    public MsgCsacTelemetry (int sender) { super(sender, TYPE); }
    public MsgCsacTelemetry () { super(TYPE); }
    public MsgCsacTelemetry (SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type != TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        id = parser.getU8();
        telemetry = parser.getString();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU8(id);
        builder.putString(telemetry);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("id", id);
        obj.put("telemetry", telemetry);
        return obj;
    }
}