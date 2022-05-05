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
package com.swiftnav.sbp.bootload;

// This file was auto-generated from yaml/swiftnav/sbp/bootload.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import org.json.JSONArray;
import org.json.JSONObject;

/**
 * SBP class for message MSG_NAP_DEVICE_DNA_RESP (0x00DD).
 *
 * <p>You can have MSG_NAP_DEVICE_DNA_RESP inherent its fields directly from an inherited SBP
 * object, or construct it inline using a dict of its fields.
 *
 * <p>The device message from the host reads a unique device identifier from the SwiftNAP, an FPGA.
 * The host requests the ID by sending a MSG_NAP_DEVICE_DNA_REQ message. The device responds with a
 * MSG_NAP_DEVICE_DNA_RESP message with the device ID in the payload. Note that this ID is tied to
 * the FPGA, and not related to the Piksi's serial number.
 */
public class MsgNapDeviceDnaResp extends SBPMessage {
    public static final int TYPE = 0x00DD;

    /** 57-bit SwiftNAP FPGA Device ID. Remaining bits are padded on the right. */
    public int[] dna;

    public MsgNapDeviceDnaResp(int sender) {
        super(sender, TYPE);
    }

    public MsgNapDeviceDnaResp() {
        super(TYPE);
    }

    public MsgNapDeviceDnaResp(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type == TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        dna = parser.getArrayofU8(8);
    }

    @Override
    protected void build(Builder builder) {
        builder.putArrayofU8(dna, 8);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("dna", new JSONArray(dna));
        return obj;
    }
}
