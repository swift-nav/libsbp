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

public class STECResidualNoStd extends SBPStruct {
    
    /** space vehicle identifier */
    public SvId sv_id;
    
    /** STEC residual */
    public int residual;
    

    public STECResidualNoStd () {}

    @Override
    public STECResidualNoStd parse(SBPMessage.Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        sv_id = new SvId().parse(parser);
        residual = parser.getS16();
        return this;
    }

    @Override
    public void build(SBPMessage.Builder builder) {
        /* Build fields into binary */
        sv_id.build(builder);
        builder.putS16(residual);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = new JSONObject();
        obj.put("sv_id", sv_id.toJSON());
        obj.put("residual", residual);
        return obj;
    }
}