/*
 * Copyright (C) 2015 Swift Navigation Inc.
 * Contact: Gareth McMullin <gareth@swiftnav.com>
 * Contact: Bhaskar Mookerji <mookerji@swiftnav.com>
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

package com.swiftnav.sbp.bootload;

import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPStruct;

import org.json.JSONObject;
import org.json.JSONArray;


/** SBP class for message MSG_NAP_DEVICE_DNA_REQ (0x00DE).
 *
 * You can have MSG_NAP_DEVICE_DNA_REQ inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
 * The device message from the host reads a unique device
 * identifier from the SwiftNAP, an FPGA. The host requests the ID
 * by sending a MSG_NAP_DEVICE_DNA_REQ message. The device
 * responds with a MSG_NAP_DEVICE_DNA_RESP message with the
 * device ID in the payload. Note that this ID is tied to the FPGA,
 * and not related to the Piksi's serial number. */

public class MsgNapDeviceDnaReq extends SBPMessage {
    public static final int TYPE = 0x00DE;

    

    public MsgNapDeviceDnaReq (int sender) { super(sender, TYPE); }
    public MsgNapDeviceDnaReq () { super(TYPE); }
    public MsgNapDeviceDnaReq (SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type != TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
    }

    @Override
    protected void build(Builder builder) {
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        return obj;
    }
}