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
 * SBP class for message MSG_ECDSA_CERTIFICATE (0x0C04).
 *
 * <p>You can have MSG_ECDSA_CERTIFICATE inherent its fields directly from an inherited SBP object,
 * or construct it inline using a dict of its fields.
 *
 * <p>A DER encoded x.509 ECDSA-256 certificate (using curve secp256r1).
 */
public class MsgEcdsaCertificate extends SBPMessage {
    public static final int TYPE = 0x0C04;

    /**
     * Total number messages that make up the certificate. The first nibble (mask 0xF0 or left
     * shifted by 4 bits) is the size of the sequence (n), second nibble (mask 0x0F) is the
     * zero-indexed counter (ith packet of n).
     */
    public int n_msg;

    /** The last 4 bytes of the certificate's SHA-1 fingerprint */
    public int[] certificate_id;

    public int flags;

    /** DER encoded x.509 ECDSA certificate bytes */
    public int[] certificate_bytes;

    public MsgEcdsaCertificate(int sender) {
        super(sender, TYPE);
    }

    public MsgEcdsaCertificate() {
        super(TYPE);
    }

    public MsgEcdsaCertificate(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        if (msg.type != TYPE)
            throw new SBPBinaryException(
                    "Type mismatch for MsgEcdsaCertificate, expected 3076, actual " + msg.type);
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        n_msg = parser.getU8();
        certificate_id = parser.getArrayofU8(4);
        flags = parser.getU8();
        certificate_bytes = parser.getArrayofU8();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU8(n_msg);
        builder.putArrayofU8(certificate_id, 4);
        builder.putU8(flags);
        builder.putArrayofU8(certificate_bytes);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("n_msg", n_msg);
        obj.put("certificate_id", new JSONArray(certificate_id));
        obj.put("flags", flags);
        obj.put("certificate_bytes", new JSONArray(certificate_bytes));
        return obj;
    }

    @Override
    public String getFriendlyName() {
        return "ECDSA CERTIFICATE";
    }
}
