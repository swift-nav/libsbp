/*
 * Copyright (C) 2015-2018 Swift Navigation Inc.
 * Contact: Swift Navigation <dev@swiftnav.com>
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

package com.swiftnav.sbp.gnss;

import java.math.BigInteger;

import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPStruct;

import org.json.JSONObject;
import org.json.JSONArray;
import com.swiftnav.sbp.SBPStruct;

public class SvId extends SBPStruct {
    
    /** ID of the space vehicle within its constellation */
    public int satId;
    
    /** Constellation ID to which the SV belongs */
    public int constellation;
    

    public SvId () {}

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