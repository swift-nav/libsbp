/* Copyright (C) 2015-2022 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */
package com.swiftnav.sbp.imu;

// This file was auto-generated from yaml/swiftnav/sbp/imu.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import org.json.JSONObject;

/**
 * SBP class for message MSG_IMU_RAW (0x0900).
 *
 * <p>You can have MSG_IMU_RAW inherent its fields directly from an inherited SBP object, or
 * construct it inline using a dict of its fields.
 *
 * <p>Raw data from the Inertial Measurement Unit, containing accelerometer and gyroscope readings.
 * The sense of the measurements are to be aligned with the indications on the device itself.
 * Measurement units, which are specific to the device hardware and settings, are communicated via
 * the MSG_IMU_AUX message. If using "time since startup" local time tags, the receiving end will
 * expect either a MSG_GNSS_TIME_OFFSET or MSG_PPS_TIME to establish the relationship between IMU
 * time and GNSS time. Regardless of the timestamping mode, the timestamp is required to roll over
 * to zero when reaching one week (604800 seconds, or 604800000 milliseconds). The time-tagging mode
 * should not change throughout a run.
 */
public class MsgImuRaw extends SBPMessage {
    public static final int TYPE = 0x0900;

    /** Milliseconds since reference epoch and time status. */
    public long tow;

    /** Milliseconds since reference epoch, fractional part */
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

    public MsgImuRaw(int sender) {
        super(sender, TYPE);
    }

    public MsgImuRaw() {
        super(TYPE);
    }

    public MsgImuRaw(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        if (msg.type != TYPE)
            throw new SBPBinaryException(
                    "Type mismatch for MsgImuRaw, expected 2304, actual " + msg.type);
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

    @Override
    public String getFriendlyName() {
        return "IMU RAW";
    }
}
