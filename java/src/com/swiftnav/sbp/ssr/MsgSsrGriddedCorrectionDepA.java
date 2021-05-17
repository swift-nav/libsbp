/*
 * Copyright (C) 2015-2018 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
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



public class MsgSsrGriddedCorrectionDepA extends SBPMessage {
    public static final int TYPE = 0x05FA;

    
    /** Header of a Gridded Correction message */
    public GriddedCorrectionHeaderDepA header;
    
    /** Tropo and STEC residuals for the given grid point (mean
and standard deviation)
 */
    public GridElement element;
    

    public MsgSsrGriddedCorrectionDepA (int sender) { super(sender, TYPE); }
    public MsgSsrGriddedCorrectionDepA () { super(TYPE); }
    public MsgSsrGriddedCorrectionDepA (SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type == TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        header = new GriddedCorrectionHeaderDepA().parse(parser);
        element = new GridElement().parse(parser);
    }

    @Override
    protected void build(Builder builder) {
        header.build(builder);
        element.build(builder);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("header", header.toJSON());
        obj.put("element", element.toJSON());
        return obj;
    }
}