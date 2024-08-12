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
 * SBP class for message MSG_ECDSA_SIGNATURE (0x0C08).
 *
 * <p>You can have MSG_ECDSA_SIGNATURE inherent its fields directly from an inherited SBP object, or
 * construct it inline using a dict of its fields.
 *
 * <p>An ECDSA-256 signature using SHA-256 as the message digest algorithm.
 */
public class MsgEcdsaSignature extends SBPMessage {
    public static final int TYPE = 0x0C08;

    /** Describes the format of the `signed\_messages` field below. */
    public int flags;

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

    /** Signature over the frames of this message group. */
    public ECDSASignature signature;

    /**
     * CRCs of the messages covered by this signature. For Skylark, which delivers SBP messages
     * wrapped in Swift's proprietary RTCM message, these are the 24-bit CRCs from the RTCM message
     * framing. For SBP only streams, this will be 16-bit CRCs from the SBP framing. See the `flags`
     * field to determine the type of CRCs covered.
     */
    public int[] signed_messages;

    public MsgEcdsaSignature(int sender) {
        super(sender, TYPE);
    }

    public MsgEcdsaSignature() {
        super(TYPE);
    }

    public MsgEcdsaSignature(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        if (msg.type != TYPE)
            throw new SBPBinaryException(
                    "Type mismatch for MsgEcdsaSignature, expected 3080, actual " + msg.type);
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        flags = parser.getU8();
        stream_counter = parser.getU8();
        on_demand_counter = parser.getU8();
        certificate_id = parser.getArrayofU8(4);
        signature = new ECDSASignature().parse(parser);
        signed_messages = parser.getArrayofU8();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU8(flags);
        builder.putU8(stream_counter);
        builder.putU8(on_demand_counter);
        builder.putArrayofU8(certificate_id, 4);
        signature.build(builder);
        builder.putArrayofU8(signed_messages);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("flags", flags);
        obj.put("stream_counter", stream_counter);
        obj.put("on_demand_counter", on_demand_counter);
        obj.put("certificate_id", new JSONArray(certificate_id));
        obj.put("signature", signature.toJSON());
        obj.put("signed_messages", new JSONArray(signed_messages));
        return obj;
    }

    @Override
    public String getFriendlyName() {
        return "ECDSA SIGNATURE";
    }
}
