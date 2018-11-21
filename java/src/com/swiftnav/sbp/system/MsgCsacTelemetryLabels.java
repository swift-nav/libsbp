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


/** SBP class for message MSG_CSAC_TELEMETRY_LABELS (0xFF05).
 *
 * You can have MSG_CSAC_TELEMETRY_LABELS inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
 * The CSAC telemetry message provides labels for each member of the string
 * produced by MSG_CSAC_TELEMETRY. It should be provided by a device at a lower
 * rate than the MSG_CSAC_TELEMETRY. */

public class MsgCsacTelemetryLabels extends SBPMessage {
    public static final int TYPE = 0xFF05;

    
    /** Index representing the type of telemetry in use.  It is implemention defined. */
    public int id;
    
    /** Comma separated list of telemetry field values */
    public String telemetry_labels;
    

    public MsgCsacTelemetryLabels (int sender) { super(sender, TYPE); }
    public MsgCsacTelemetryLabels () { super(TYPE); }
    public MsgCsacTelemetryLabels (SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type != TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        id = parser.getU8();
        telemetry_labels = parser.getString();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU8(id);
        builder.putString(telemetry_labels);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("id", id);
        obj.put("telemetry_labels", telemetry_labels);
        return obj;
    }
}