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

package com.swiftnav.sbp.observation;

import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPStruct;
import com.swiftnav.sbp.gnss.*;

import org.json.JSONObject;
import org.json.JSONArray;


/** SBP class for message MSG_FCNS_GLO (0x0072).
 *
 * You can have MSG_FCNS_GLO inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
 * The message reports mapping information regarding GLONASS SV orbital and
 * frequency slots.
 * Mapped as follow:
 * index (SV orbital slot)  fcns[index]
 * 0                        0xFF
 * 1                        FCN for SV orbital slot 1
 * ...                      ...
 * 28                       FCN for SV orbital slot 28
 * 29                       0xFF
 * 30                       0xFF
 * 31                       0xFF */

public class MsgFcnsGlo extends SBPMessage {
    public static final int TYPE = 0x0072;

    
    /** GPS Week number */
    public int wn;
    
    /** GPS Time of week */
    public long tow_ms;
    
    /** GLONASS fequency number per orbital slot */
    public int[] fcns;
    

    public MsgFcnsGlo (int sender) { super(sender, TYPE); }
    public MsgFcnsGlo () { super(TYPE); }
    public MsgFcnsGlo (SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type != TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        wn = parser.getU16();
        tow_ms = parser.getU32();
        fcns = parser.getArrayofU8(32);
    }

    @Override
    protected void build(Builder builder) {
        builder.putU16(wn);
        builder.putU32(tow_ms);
        builder.putArrayofU8(fcns, 32);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("wn", wn);
        obj.put("tow_ms", tow_ms);
        obj.put("fcns", new JSONArray(fcns));
        return obj;
    }
}