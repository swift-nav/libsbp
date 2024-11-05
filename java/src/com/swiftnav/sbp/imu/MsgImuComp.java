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
import java.math.BigInteger;
import org.json.JSONObject;

/**
 * SBP class for message MSG_IMU_COMP (0x0905).
 *
 * <p>You can have MSG_IMU_COMP inherent its fields directly from an inherited SBP object, or
 * construct it inline using a dict of its fields.
 *
 * <p>Data from the Inertial Measurement Unit, containing accelerometer and gyroscope readings
 * compensated for estimated errors and constant physical effects. The output is valid for
 * inertially referenced center of navigation (IMU body frame) represented in vehicle body frame.
 */
public class MsgImuComp extends SBPMessage {
    public static final int TYPE = 0x0905;

    /** Microseconds since reference epoch */
    public BigInteger time;

    /** Contains the applied compensation parameters and time synchronization mode */
    public int flags;

    /** Compensated acceleration X axis */
    public int acc_comp_x;

    /** Compensated acceleration Y axis */
    public int acc_comp_y;

    /** Compensated acceleration Z axis */
    public int acc_comp_z;

    /** Compensated angular rate X axis */
    public int gyr_comp_x;

    /** Compensated angular rate Y axis */
    public int gyr_comp_y;

    /** Compensated angular rate Z axis */
    public int gyr_comp_z;

    public MsgImuComp(int sender) {
        super(sender, TYPE);
    }

    public MsgImuComp() {
        super(TYPE);
    }

    public MsgImuComp(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        if (msg.type != TYPE)
            throw new SBPBinaryException(
                    "Type mismatch for MsgImuComp, expected 2309, actual " + msg.type);
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        time = parser.getU64();
        flags = parser.getU16();
        acc_comp_x = parser.getS32();
        acc_comp_y = parser.getS32();
        acc_comp_z = parser.getS32();
        gyr_comp_x = parser.getS32();
        gyr_comp_y = parser.getS32();
        gyr_comp_z = parser.getS32();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU64(time);
        builder.putU16(flags);
        builder.putS32(acc_comp_x);
        builder.putS32(acc_comp_y);
        builder.putS32(acc_comp_z);
        builder.putS32(gyr_comp_x);
        builder.putS32(gyr_comp_y);
        builder.putS32(gyr_comp_z);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("time", time);
        obj.put("flags", flags);
        obj.put("acc_comp_x", acc_comp_x);
        obj.put("acc_comp_y", acc_comp_y);
        obj.put("acc_comp_z", acc_comp_z);
        obj.put("gyr_comp_x", gyr_comp_x);
        obj.put("gyr_comp_y", gyr_comp_y);
        obj.put("gyr_comp_z", gyr_comp_z);
        return obj;
    }

    @Override
    public String getFriendlyName() {
        return "IMU COMP";
    }
}
