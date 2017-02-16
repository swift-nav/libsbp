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

package com.swiftnav.sbp.navigation;

import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPStruct;
import java.math.BigInteger;

import org.json.JSONObject;
import org.json.JSONArray;


/** SBP class for message MSG_DOPS (0x0208).
 *
 * You can have MSG_DOPS inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
 * This dilution of precision (DOP) message describes the effect of
 * navigation satellite geometry on positional measurement
 * precision.  The flags field indicated whether the DOP reported
 * corresponds to differential or SPP solution. */

public class MsgDops extends SBPMessage {
    public static final int TYPE = 0x0208;

    
    /** GPS Time of Week */
    public long tow;
    
    /** Geometric Dilution of Precision */
    public int gdop;
    
    /** Position Dilution of Precision */
    public int pdop;
    
    /** Time Dilution of Precision */
    public int tdop;
    
    /** Horizontal Dilution of Precision */
    public int hdop;
    
    /** Vertical Dilution of Precision */
    public int vdop;
    
    /** Indicates the position solution with which the DOPS message corresponds */
    public int flags;
    

    public MsgDops (int sender) { super(sender, TYPE); }
    public MsgDops () { super(TYPE); }
    public MsgDops (SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type != TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        tow = parser.getU32();
        gdop = parser.getU16();
        pdop = parser.getU16();
        tdop = parser.getU16();
        hdop = parser.getU16();
        vdop = parser.getU16();
        flags = parser.getU8();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU32(tow);
        builder.putU16(gdop);
        builder.putU16(pdop);
        builder.putU16(tdop);
        builder.putU16(hdop);
        builder.putU16(vdop);
        builder.putU8(flags);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("tow", tow);
        obj.put("gdop", gdop);
        obj.put("pdop", pdop);
        obj.put("tdop", tdop);
        obj.put("hdop", hdop);
        obj.put("vdop", vdop);
        obj.put("flags", flags);
        return obj;
    }
}