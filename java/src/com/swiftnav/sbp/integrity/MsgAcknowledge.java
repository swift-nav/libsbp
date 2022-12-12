/* Copyright (C) 2015-2022 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */
package com.swiftnav.sbp.integrity;

// This file was auto-generated from yaml/swiftnav/sbp/integrity.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.gnss.*;
import org.json.JSONObject;

public class MsgAcknowledge extends SBPMessage {
    public static final int TYPE = 0x0BD2;

    /**
     * Echo of the request ID field from the corresponding CRA message, or 255 if no request ID was
     * provided.
     */
    public int request_id;

    /** Echo of the Area ID field from the corresponding CRA message. */
    public long area_id;

    /** Reported status of the request. */
    public int response_code;

    /**
     * Contains the message group(s) that will be sent in response from the corresponding CRA
     * correction mask. An echo of the correction mask field from the corresponding CRA message.
     */
    public int correction_mask_on_demand;

    /** For future expansion. Always set to 0. */
    public int correction_mask_stream;

    /** The solution ID of the instance providing the corrections. */
    public int solution_id;

    public MsgAcknowledge(int sender) {
        super(sender, TYPE);
    }

    public MsgAcknowledge() {
        super(TYPE);
    }

    public MsgAcknowledge(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        if (msg.type != TYPE)
            throw new SBPBinaryException(
                    "Type mismatch for MsgAcknowledge, expected 3026, actual " + msg.type);
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        request_id = parser.getU8();
        area_id = parser.getU32();
        response_code = parser.getU8();
        correction_mask_on_demand = parser.getU16();
        correction_mask_stream = parser.getU16();
        solution_id = parser.getU8();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU8(request_id);
        builder.putU32(area_id);
        builder.putU8(response_code);
        builder.putU16(correction_mask_on_demand);
        builder.putU16(correction_mask_stream);
        builder.putU8(solution_id);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("request_id", request_id);
        obj.put("area_id", area_id);
        obj.put("response_code", response_code);
        obj.put("correction_mask_on_demand", correction_mask_on_demand);
        obj.put("correction_mask_stream", correction_mask_stream);
        obj.put("solution_id", solution_id);
        return obj;
    }

    @Override
    public String getFriendlyName() {
        return "ACKNOWLEDGE";
    }
}
