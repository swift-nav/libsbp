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
package com.swiftnav.sbp.signing;

// This file was auto-generated from yaml/swiftnav/sbp/signing.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import org.json.JSONArray;
import org.json.JSONObject;

/**
 * SBP class for message MSG_ECDSA_SIGNATURE (0x0C07).
 *
 * <p>You can have MSG_ECDSA_SIGNATURE inherent its fields directly from an inherited SBP object, or
 * construct it inline using a dict of its fields.
 *
 * <p>An ECDSA-256 signature using SHA-256 as the message digest algorithm.
 */
public class MsgEcdsaSignature extends SBPMessage {
    public static final int TYPE = 0x0C07;

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

    /**
     * Number of bytes to use of the signature field. The DER encoded signature has a maximum size
     * of 72 bytes but can vary between 70 and 72 bytes in length.
     */
    public int n_signature_bytes;

    /** DER encoded ECDSA signature for the messages using SHA-256 as the digest algorithm. */
    public int[] signature;

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
                    "Type mismatch for MsgEcdsaSignature, expected 3079, actual " + msg.type);
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        flags = parser.getU8();
        stream_counter = parser.getU8();
        on_demand_counter = parser.getU8();
        certificate_id = parser.getArrayofU8(4);
        n_signature_bytes = parser.getU8();
        signature = parser.getArrayofU8(72);
        signed_messages = parser.getArrayofU8();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU8(flags);
        builder.putU8(stream_counter);
        builder.putU8(on_demand_counter);
        builder.putArrayofU8(certificate_id, 4);
        builder.putU8(n_signature_bytes);
        builder.putArrayofU8(signature, 72);
        builder.putArrayofU8(signed_messages);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("flags", flags);
        obj.put("stream_counter", stream_counter);
        obj.put("on_demand_counter", on_demand_counter);
        obj.put("certificate_id", new JSONArray(certificate_id));
        obj.put("n_signature_bytes", n_signature_bytes);
        obj.put("signature", new JSONArray(signature));
        obj.put("signed_messages", new JSONArray(signed_messages));
        return obj;
    }

    @Override
    public String getFriendlyName() {
        return "ECDSA SIGNATURE";
    }
}
