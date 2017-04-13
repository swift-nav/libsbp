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
 * The message reports mapping information regrding GLONASS SV orbital and
 * frequency slots. Frequency numbers -7 to 6 have been reported as 1 to 14
 * correspondingly. 0xFF for invalid. The 0th element and elements from 29th
 * to 30th of the map are always invalid. */

public class MsgFcnsGlo extends SBPMessage {
    public static final int TYPE = 0x0072;

    
    /** GPS Week number */
    public int wn;
    
    /** GPS Time of week */
    public double tow;
    
    /** GLONASS fequency number per orbital slot */
    public long[] fcns;
    

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
        tow = parser.getDouble();
        fcns = parser.getArrayofU32(32);
    }

    @Override
    protected void build(Builder builder) {
        builder.putU16(wn);
        builder.putDouble(tow);
        builder.putArrayofU32(fcns, 32);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("wn", wn);
        obj.put("tow", tow);
        obj.put("fcns", new JSONArray(fcns));
        return obj;
    }
}