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
import com.swiftnav.sbp.SBPStruct;
import org.json.JSONArray;
import org.json.JSONObject;

public class ECDSASignature extends SBPStruct {

    /**
     * Number of bytes to use of the signature field. The DER encoded signature has a maximum size
     * of 72 bytes but can vary between 70 and 72 bytes in length.
     */
    public int len;

    /** DER encoded ECDSA signature for the messages using SHA-256 as the digest algorithm. */
    public int[] data;

    public ECDSASignature() {}

    @Override
    public ECDSASignature parse(SBPMessage.Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        len = parser.getU8();
        data = parser.getArrayofU8(72);
        return this;
    }

    @Override
    public void build(SBPMessage.Builder builder) {
        /* Build fields into binary */
        builder.putU8(len);
        builder.putArrayofU8(data, 72);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = new JSONObject();
        obj.put("len", len);
        obj.put("data", new JSONArray(data));
        return obj;
    }
}
