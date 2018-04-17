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

package com.swiftnav.sbp.tracking;

import java.math.BigInteger;

import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPStruct;
import com.swiftnav.sbp.gnss.*;

import org.json.JSONObject;
import org.json.JSONArray;
import com.swiftnav.sbp.SBPStruct;

public class MeasurementState extends SBPStruct {
    
    /** Measurement Engine GNSS signal being tracked (carries either Glonass FCN or SLOT) */
    public GnssSignal mesid;
    
    /** Carrier-to-Noise density.  Zero implies invalid cn0. */
    public int cn0;
    

    public MeasurementState () {}

    @Override
    public MeasurementState parse(SBPMessage.Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        mesid = new GnssSignal().parse(parser);
        cn0 = parser.getU8();
        return this;
    }

    @Override
    public void build(SBPMessage.Builder builder) {
        /* Build fields into binary */
        mesid.build(builder);
        builder.putU8(cn0);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = new JSONObject();
        obj.put("mesid", mesid.toJSON());
        obj.put("cn0", cn0);
        return obj;
    }
}