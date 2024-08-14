/* Copyright (C) 2015-2022 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */
package com.swiftnav.sbp.signing;

// This file was auto-generated from yaml/swiftnav/sbp/signing.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import org.json.JSONArray;
import org.json.JSONObject;

/**
 * SBP class for message MSG_AES_CMAC_SIGNATURE (0x0C10).
 *
 * <p>You can have MSG_AES_CMAC_SIGNATURE inherent its fields directly from an inherited SBP object,
 * or construct it inline using a dict of its fields.
 *
 * <p>Digital signature using AES-CMAC 128 algorithm used for data integrity.
 */
public class MsgAesCmacSignature extends SBPMessage {
    public static final int TYPE = 0x0C10;

    /**
     * Signature message counter. Zero indexed and incremented with each signature message. The
     * counter will not increment if this message was in response to an on demand request. The
     * counter will roll over after 256 messages. Upon connection, the value of the counter may not
     * initially be zero.
     */
    public int stream_counter;

    /**
     * On demand message counter. Zero indexed and incremented with each signature message sent in
     * response to an on demand message. The counter will roll over after 256 messages. Upon
     * connection, the value of the counter may not initially be zero.
     */
    public int on_demand_counter;

    /** The last 4 bytes of the certificate's SHA-1 fingerprint */
    public int[] certificate_id;

    /** Signature */
    public int[] signature;

    /** Describes the format of the 'signed messages' field below. */
    public int flags;

    /**
     * CRCs of the messages covered by this signature. For Skylark, which delivers SBP messages
     * wrapped in Swift's proprietary RTCM message, these are the 24-bit CRCs from the RTCM message
     * framing. For SBP only streams, this will be 16-bit CRCs from the SBP framing. See the `flags`
     * field to determine the type of CRCs covered.
     */
    public int[] signed_messages;

    public MsgAesCmacSignature(int sender) {
        super(sender, TYPE);
    }

    public MsgAesCmacSignature() {
        super(TYPE);
    }

    public MsgAesCmacSignature(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        if (msg.type != TYPE)
            throw new SBPBinaryException(
                    "Type mismatch for MsgAesCmacSignature, expected 3088, actual " + msg.type);
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        stream_counter = parser.getU8();
        on_demand_counter = parser.getU8();
        certificate_id = parser.getArrayofU8(4);
        signature = parser.getArrayofU8(16);
        flags = parser.getU8();
        signed_messages = parser.getArrayofU8();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU8(stream_counter);
        builder.putU8(on_demand_counter);
        builder.putArrayofU8(certificate_id, 4);
        builder.putArrayofU8(signature, 16);
        builder.putU8(flags);
        builder.putArrayofU8(signed_messages);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("stream_counter", stream_counter);
        obj.put("on_demand_counter", on_demand_counter);
        obj.put("certificate_id", new JSONArray(certificate_id));
        obj.put("signature", new JSONArray(signature));
        obj.put("flags", flags);
        obj.put("signed_messages", new JSONArray(signed_messages));
        return obj;
    }

    @Override
    public String getFriendlyName() {
        return "AES CMAC SIGNATURE";
    }
}
