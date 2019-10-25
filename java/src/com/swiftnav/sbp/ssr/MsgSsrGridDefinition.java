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


/** SBP class for message MSG_SSR_GRID_DEFINITION (0x05F5).
 *
 * You can have MSG_SSR_GRID_DEFINITION inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
 * Based on the 3GPP proposal R2-1906781 which is in turn based on
 * OMA-LPPe-ValidityArea from OMA-TS-LPPe-V2_0-20141202-C */

public class MsgSsrGridDefinition extends SBPMessage {
    public static final int TYPE = 0x05F5;

    
    /** Header of a Gridded Correction message */
    public GridDefinitionHeader header;
    
    /** Run Length Encode list of quadrants that contain valid data.
The spec describes the encoding scheme in detail, but
essentially the index of the quadrants that contain transitions between
valid and invalid (and vice versa) are encoded as u8 integers.
 */
    public int[] rle_list;
    

    public MsgSsrGridDefinition (int sender) { super(sender, TYPE); }
    public MsgSsrGridDefinition () { super(TYPE); }
    public MsgSsrGridDefinition (SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type != TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        header = new GridDefinitionHeader().parse(parser);
        rle_list = parser.getArrayofU8();
    }

    @Override
    protected void build(Builder builder) {
        header.build(builder);
        builder.putArrayofU8(rle_list);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("header", header.toJSON());
        obj.put("rle_list", new JSONArray(rle_list));
        return obj;
    }
}