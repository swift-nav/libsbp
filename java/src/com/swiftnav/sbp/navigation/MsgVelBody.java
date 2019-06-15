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

package com.swiftnav.sbp.navigation;

import java.math.BigInteger;

import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPStruct;

import org.json.JSONObject;
import org.json.JSONArray;


/** SBP class for message MSG_VEL_BODY (0x0213).
 *
 * You can have MSG_VEL_BODY inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
 * This message reports the velocity in the Vehicle Body Frame. By convention,
 * the x-axis should point out the nose of the vehicle and represent the forward
 * direction, while as the y-axis should point out the right hand side of the vehicle.
 * Since this is a right handed system, z should point out the bottom of the vehicle.
 * The orientation and origin of the Vehicle Body Frame are specified via the device settings.
 * The full GPS time is given by the preceding MSG_GPS_TIME with the
 * matching time-of-week (tow). This message is only produced by inertial versions of Swift
 * products and is not available from Piksi Multi or Duro. */

public class MsgVelBody extends SBPMessage {
    public static final int TYPE = 0x0213;

    
    /** GPS Time of Week */
    public long tow;
    
    /** Velocity in x direction */
    public int x;
    
    /** Velocity in y direction */
    public int y;
    
    /** Velocity in z direction */
    public int z;
    
    /** Estimated variance of x */
    public float cov_x_x;
    
    /** Covariance of x and y */
    public float cov_x_y;
    
    /** Covariance of x and z */
    public float cov_x_z;
    
    /** Estimated variance of y */
    public float cov_y_y;
    
    /** Covariance of y and z */
    public float cov_y_z;
    
    /** Estimated variance of z */
    public float cov_z_z;
    
    /** Number of satellites used in solution */
    public int n_sats;
    
    /** Status flags */
    public int flags;
    

    public MsgVelBody (int sender) { super(sender, TYPE); }
    public MsgVelBody () { super(TYPE); }
    public MsgVelBody (SBPMessage msg) throws SBPBinaryException {
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
        cov_x_x = parser.getFloat();
        cov_x_y = parser.getFloat();
        cov_x_z = parser.getFloat();
        cov_y_y = parser.getFloat();
        cov_y_z = parser.getFloat();
        cov_z_z = parser.getFloat();
        n_sats = parser.getU8();
        flags = parser.getU8();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU32(tow);
        builder.putS32(x);
        builder.putS32(y);
        builder.putS32(z);
        builder.putFloat(cov_x_x);
        builder.putFloat(cov_x_y);
        builder.putFloat(cov_x_z);
        builder.putFloat(cov_y_y);
        builder.putFloat(cov_y_z);
        builder.putFloat(cov_z_z);
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
        obj.put("cov_x_x", cov_x_x);
        obj.put("cov_x_y", cov_x_y);
        obj.put("cov_x_z", cov_x_z);
        obj.put("cov_y_y", cov_y_y);
        obj.put("cov_y_z", cov_y_z);
        obj.put("cov_z_z", cov_z_z);
        obj.put("n_sats", n_sats);
        obj.put("flags", flags);
        return obj;
    }
}