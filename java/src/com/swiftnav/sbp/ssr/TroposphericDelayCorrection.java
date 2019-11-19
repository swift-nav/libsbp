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

package com.swiftnav.sbp.ssr;

import java.math.BigInteger;

import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPStruct;
import com.swiftnav.sbp.gnss.*;

import org.json.JSONObject;
import org.json.JSONArray;
import com.swiftnav.sbp.SBPStruct;

public class TroposphericDelayCorrection extends SBPStruct {
    
    /** Hydrostatic vertical delay */
    public int hydro;
    
    /** Wet vertical delay */
    public int wet;
    
    /** stddev */
    public int stddev;
    

    public TroposphericDelayCorrection () {}

    @Override
    public TroposphericDelayCorrection parse(SBPMessage.Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        hydro = parser.getS16();
        wet = parser.getS8();
        stddev = parser.getU8();
        return this;
    }

    @Override
    public void build(SBPMessage.Builder builder) {
        /* Build fields into binary */
        builder.putS16(hydro);
        builder.putS8(wet);
        builder.putU8(stddev);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = new JSONObject();
        obj.put("hydro", hydro);
        obj.put("wet", wet);
        obj.put("stddev", stddev);
        return obj;
    }
}