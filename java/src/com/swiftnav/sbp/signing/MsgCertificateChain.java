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

public class MsgCertificateChain extends SBPMessage {
    public static final int TYPE = 0x0C09;

    /** SHA-1 fingerprint of the root certificate */
    public int[] root_certificate;

    /** SHA-1 fingerprint of the intermediate certificate */
    public int[] intermediate_certificate;

    /** SHA-1 fingerprint of the corrections certificate */
    public int[] corrections_certificate;

    /**
     * The time after which the signature given is no longer valid. Implementors should consult a
     * time source (such as GNSS) to check if the current time is later than the expiration time, if
     * the condition is true, signatures in the stream should not be considered valid.
     */
    public UtcTime expiration;

    /**
     * Signature (created by the root certificate) over the concatenation of the SBP payload bytes
     * preceding this field. That is, the concatenation of `root_certificate`,
     * `intermediate_certificate`, `corrections_certificate` and `expiration`. This certificate
     * chain (allow list) can also be validated by fetching it from
     * `http(s)://certs.swiftnav.com/chain`.
     */
    public ECDSASignature signature;

    public MsgCertificateChain(int sender) {
        super(sender, TYPE);
    }

    public MsgCertificateChain() {
        super(TYPE);
    }

    public MsgCertificateChain(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        if (msg.type != TYPE)
            throw new SBPBinaryException(
                    "Type mismatch for MsgCertificateChain, expected 3081, actual " + msg.type);
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        root_certificate = parser.getArrayofU8(20);
        intermediate_certificate = parser.getArrayofU8(20);
        corrections_certificate = parser.getArrayofU8(20);
        expiration = new UtcTime().parse(parser);
        signature = new ECDSASignature().parse(parser);
    }

    @Override
    protected void build(Builder builder) {
        builder.putArrayofU8(root_certificate, 20);
        builder.putArrayofU8(intermediate_certificate, 20);
        builder.putArrayofU8(corrections_certificate, 20);
        expiration.build(builder);
        signature.build(builder);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("root_certificate", new JSONArray(root_certificate));
        obj.put("intermediate_certificate", new JSONArray(intermediate_certificate));
        obj.put("corrections_certificate", new JSONArray(corrections_certificate));
        obj.put("expiration", expiration.toJSON());
        obj.put("signature", signature.toJSON());
        return obj;
    }

    @Override
    public String getFriendlyName() {
        return "CERTIFICATE CHAIN";
    }
}
