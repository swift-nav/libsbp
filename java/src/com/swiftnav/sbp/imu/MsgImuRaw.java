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

package com.swiftnav.sbp.imu;

import java.math.BigInteger;

import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPStruct;

import org.json.JSONObject;
import org.json.JSONArray;


/** SBP class for message MSG_IMU_RAW (0x0900).
 *
 * You can have MSG_IMU_RAW inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
 * Raw data from the Inertial Measurement Unit, containing accelerometer and
 * gyroscope readings. The sense of the measurements are to be aligned with 
 * the indications on the device itself. Measurement units, which are specific to the
 * device hardware and settings, are communicated via the MSG_IMU_AUX message. */

public class MsgImuRaw extends SBPMessage {
    public static final int TYPE = 0x0900;

    
    /** Milliseconds since start of GPS week. If the high bit is set, the
time is unknown or invalid.
 */
    public long tow;
    
    /** Milliseconds since start of GPS week, fractional part
 */
    public int tow_f;
    
    /** Acceleration in the IMU frame X axis */
    public int acc_x;
    
    /** Acceleration in the IMU frame Y axis */
    public int acc_y;
    
    /** Acceleration in the IMU frame Z axis */
    public int acc_z;
    
    /** Angular rate around IMU frame X axis */
    public int gyr_x;
    
    /** Angular rate around IMU frame Y axis */
    public int gyr_y;
    
    /** Angular rate around IMU frame Z axis */
    public int gyr_z;
    

    public MsgImuRaw (int sender) { super(sender, TYPE); }
    public MsgImuRaw () { super(TYPE); }
    public MsgImuRaw (SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type != TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        tow = parser.getU32();
        tow_f = parser.getU8();
        acc_x = parser.getS16();
        acc_y = parser.getS16();
        acc_z = parser.getS16();
        gyr_x = parser.getS16();
        gyr_y = parser.getS16();
        gyr_z = parser.getS16();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU32(tow);
        builder.putU8(tow_f);
        builder.putS16(acc_x);
        builder.putS16(acc_y);
        builder.putS16(acc_z);
        builder.putS16(gyr_x);
        builder.putS16(gyr_y);
        builder.putS16(gyr_z);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("tow", tow);
        obj.put("tow_f", tow_f);
        obj.put("acc_x", acc_x);
        obj.put("acc_y", acc_y);
        obj.put("acc_z", acc_z);
        obj.put("gyr_x", gyr_x);
        obj.put("gyr_y", gyr_y);
        obj.put("gyr_z", gyr_z);
        return obj;
    }
}