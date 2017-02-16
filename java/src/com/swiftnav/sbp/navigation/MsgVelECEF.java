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


/** SBP class for message MSG_VEL_ECEF (0x020D).
 *
 * You can have MSG_VEL_ECEF inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
 * This message reports the velocity in Earth Centered Earth Fixed
 * (ECEF) coordinates. The full GPS time is given by the preceding
 * MSG_GPS_TIME with the matching time-of-week (tow). */

public class MsgVelECEF extends SBPMessage {
    public static final int TYPE = 0x020D;

    
    /** GPS Time of Week */
    public long tow;
    
    /** Velocity ECEF X coordinate */
    public int x;
    
    /** Velocity ECEF Y coordinate */
    public int y;
    
    /** Velocity ECEF Z coordinate */
    public int z;
    
    /** Velocity accuracy estimate (not implemented). Defaults
to 0.
 */
    public int accuracy;
    
    /** Number of satellites used in solution */
    public int n_sats;
    
    /** Status flags */
    public int flags;
    

    public MsgVelECEF (int sender) { super(sender, TYPE); }
    public MsgVelECEF () { super(TYPE); }
    public MsgVelECEF (SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type != TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        tow = parser.getU32();
        x = parser.getS32();
        y = parser.getS32();
        z = parser.getS32();
        accuracy = parser.getU16();
        n_sats = parser.getU8();
        flags = parser.getU8();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU32(tow);
        builder.putS32(x);
        builder.putS32(y);
        builder.putS32(z);
        builder.putU16(accuracy);
        builder.putU8(n_sats);
        builder.putU8(flags);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("tow", tow);
        obj.put("x", x);
        obj.put("y", y);
        obj.put("z", z);
        obj.put("accuracy", accuracy);
        obj.put("n_sats", n_sats);
        obj.put("flags", flags);
        return obj;
    }
}