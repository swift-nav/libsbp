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

package com.swiftnav.sbp.system;

import java.math.BigInteger;

import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPStruct;

import org.json.JSONObject;
import org.json.JSONArray;


/** SBP class for message MSG_INS_UPDATES (0xFF06).
 *
 * You can have MSG_INS_UPDATES inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
 * The INS update status message contains informations about executed and rejected INS updates  */

public class MsgInsUpdates extends SBPMessage {
    public static final int TYPE = 0xFF06;

    
    /** GPS Time of Week */
    public long tow;
    
    /** GNSS position update status flags */
    public int gnsspos;
    
    /** GNSS velocity update status flags */
    public int gnssvel;
    
    /** Wheelticks update status flags */
    public int wheelticks;
    
    /** Wheelticks update status flags */
    public int speed;
    
    /** NHC update status flags */
    public int nhc;
    
    /** Zero velocity update status flags */
    public int zerovel;
    

    public MsgInsUpdates (int sender) { super(sender, TYPE); }
    public MsgInsUpdates () { super(TYPE); }
    public MsgInsUpdates (SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type != TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        tow = parser.getU32();
        gnsspos = parser.getU8();
        gnssvel = parser.getU8();
        wheelticks = parser.getU8();
        speed = parser.getU8();
        nhc = parser.getU8();
        zerovel = parser.getU8();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU32(tow);
        builder.putU8(gnsspos);
        builder.putU8(gnssvel);
        builder.putU8(wheelticks);
        builder.putU8(speed);
        builder.putU8(nhc);
        builder.putU8(zerovel);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("tow", tow);
        obj.put("gnsspos", gnsspos);
        obj.put("gnssvel", gnssvel);
        obj.put("wheelticks", wheelticks);
        obj.put("speed", speed);
        obj.put("nhc", nhc);
        obj.put("zerovel", zerovel);
        return obj;
    }
}