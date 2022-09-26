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
package com.swiftnav.sbp.gnss;

// This file was auto-generated from yaml/swiftnav/sbp/gnss.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPStruct;
import org.json.JSONObject;

public class SvId extends SBPStruct {

    /**
     * Constellation-specific satellite id. For GLO can either be (100+FCN) where FCN is in [-7,+6]
     * or the Slot ID in [1,28].
     */
    public int satId;

    /** Constellation ID to which the SV belongs */
    public int constellation;

    public SvId() {}

    @Override
    public SvId parse(SBPMessage.Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        satId = parser.getU8();
        constellation = parser.getU8();
        return this;
    }

    @Override
    public void build(SBPMessage.Builder builder) {
        /* Build fields into binary */
        builder.putU8(satId);
        builder.putU8(constellation);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = new JSONObject();
        obj.put("satId", satId);
        obj.put("constellation", constellation);
        return obj;
    }
}
