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

public class MsgEd25519CertificateDep extends SBPMessage {
    public static final int TYPE = 0x0C02;

    /**
     * Total number messages that make up the certificate. First nibble is the size of the sequence
     * (n), second nibble is the zero-indexed counter (ith packet of n)
     */
    public int n_msg;

    /** SHA-1 fingerprint of the associated certificate. */
    public int[] fingerprint;

    /** ED25519 certificate bytes. */
    public int[] certificate_bytes;

    public MsgEd25519CertificateDep(int sender) {
        super(sender, TYPE);
    }

    public MsgEd25519CertificateDep() {
        super(TYPE);
    }

    public MsgEd25519CertificateDep(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        if (msg.type != TYPE)
            throw new SBPBinaryException(
                    "Type mismatch for MsgEd25519CertificateDep, expected 3074, actual "
                            + msg.type);
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        n_msg = parser.getU8();
        fingerprint = parser.getArrayofU8(20);
        certificate_bytes = parser.getArrayofU8();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU8(n_msg);
        builder.putArrayofU8(fingerprint, 20);
        builder.putArrayofU8(certificate_bytes);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("n_msg", n_msg);
        obj.put("fingerprint", new JSONArray(fingerprint));
        obj.put("certificate_bytes", new JSONArray(certificate_bytes));
        return obj;
    }

    @Override
    public String getFriendlyName() {
        return "ED25519 CERTIFICATE DEP";
    }
}
