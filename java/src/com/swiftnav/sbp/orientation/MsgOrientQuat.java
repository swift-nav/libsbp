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

package com.swiftnav.sbp.orientation;

import java.math.BigInteger;

import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPStruct;

import org.json.JSONObject;
import org.json.JSONArray;


/** SBP class for message MSG_ORIENT_QUAT (0x0220).
 *
 * You can have MSG_ORIENT_QUAT inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
 * This message reports the quaternion vector describing the vehicle body frame's orientation
 * with respect to a local-level NED frame. The components of the vector should sum to a unit
 * vector assuming that the LSB of each component as a value of 2^-31. This message will only
 * be available in future INS versions of Swift Products and is not produced by Piksi Multi 
 * or Duro. */

public class MsgOrientQuat extends SBPMessage {
    public static final int TYPE = 0x0220;

    
    /** GPS Time of Week */
    public long tow;
    
    /** Real component */
    public int w;
    
    /** 1st imaginary component */
    public int x;
    
    /** 2nd imaginary component */
    public int y;
    
    /** 3rd imaginary component */
    public int z;
    
    /** Estimated standard deviation of w */
    public float w_accuracy;
    
    /** Estimated standard deviation of x */
    public float x_accuracy;
    
    /** Estimated standard deviation of y */
    public float y_accuracy;
    
    /** Estimated standard deviation of z */
    public float z_accuracy;
    
    /** Status flags */
    public int flags;
    

    public MsgOrientQuat (int sender) { super(sender, TYPE); }
    public MsgOrientQuat () { super(TYPE); }
    public MsgOrientQuat (SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type != TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        tow = parser.getU32();
        w = parser.getS32();
        x = parser.getS32();
        y = parser.getS32();
        z = parser.getS32();
        w_accuracy = parser.getFloat();
        x_accuracy = parser.getFloat();
        y_accuracy = parser.getFloat();
        z_accuracy = parser.getFloat();
        flags = parser.getU8();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU32(tow);
        builder.putS32(w);
        builder.putS32(x);
        builder.putS32(y);
        builder.putS32(z);
        builder.putFloat(w_accuracy);
        builder.putFloat(x_accuracy);
        builder.putFloat(y_accuracy);
        builder.putFloat(z_accuracy);
        builder.putU8(flags);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("tow", tow);
        obj.put("w", w);
        obj.put("x", x);
        obj.put("y", y);
        obj.put("z", z);
        obj.put("w_accuracy", w_accuracy);
        obj.put("x_accuracy", x_accuracy);
        obj.put("y_accuracy", y_accuracy);
        obj.put("z_accuracy", z_accuracy);
        obj.put("flags", flags);
        return obj;
    }
}