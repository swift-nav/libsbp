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
 * SBP class for message MSG_ED25519_SIGNATURE_DEP_A (0x0C01).
 *
 * <p>You can have MSG_ED25519_SIGNATURE_DEP_A inherent its fields directly from an inherited SBP
 * object, or construct it inline using a dict of its fields.
 *
 * <p>Deprecated.
 */
public class MsgEd25519SignatureDepA extends SBPMessage {
    public static final int TYPE = 0x0C01;

    /** ED25519 signature for messages. */
    public int[] signature;

    /** SHA-1 fingerprint of the associated certificate. */
    public int[] fingerprint;

    /** CRCs of signed messages. */
    public long[] signed_messages;

    public MsgEd25519SignatureDepA(int sender) {
        super(sender, TYPE);
    }

    public MsgEd25519SignatureDepA() {
        super(TYPE);
    }

    public MsgEd25519SignatureDepA(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        if (msg.type != TYPE)
            throw new SBPBinaryException(
                    "Type mismatch for MsgEd25519SignatureDepA, expected 3073, actual " + msg.type);
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        signature = parser.getArrayofU8(64);
        fingerprint = parser.getArrayofU8(20);
        signed_messages = parser.getArrayofU32();
    }

    @Override
    protected void build(Builder builder) {
        builder.putArrayofU8(signature, 64);
        builder.putArrayofU8(fingerprint, 20);
        builder.putArrayofU32(signed_messages);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("signature", new JSONArray(signature));
        obj.put("fingerprint", new JSONArray(fingerprint));
        obj.put("signed_messages", new JSONArray(signed_messages));
        return obj;
    }

    @Override
    public String getFriendlyName() {
        return "ED25519 SIGNATURE DEP A";
    }
}
