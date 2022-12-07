/* Copyright (C) 2015-2022 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */
package com.swiftnav.sbp.navigation;

// This file was auto-generated from yaml/swiftnav/sbp/navigation.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import org.json.JSONArray;
import org.json.JSONObject;

/**
 * SBP class for message MSG_POSE_RELATIVE (0x0245).
 *
 * <p>You can have MSG_POSE_RELATIVE inherent its fields directly from an inherited SBP object, or
 * construct it inline using a dict of its fields.
 *
 * <p>This solution message reports the relative pose of a sensor between two time instances. The
 * relative pose comprises of a rotation and a translation which relates the sensor (e.g. camera)
 * frame at a given time (first keyframe) to the sensor frame at another time (second keyframe). The
 * relative translations is a 3x1 vector described in the first keyframe. Relative rotation is
 * described by a quaternion from second keyframe to the first keyframe.
 */
public class MsgPoseRelative extends SBPMessage {
    public static final int TYPE = 0x0245;

    /** GPS Time of Week */
    public long tow;

    /** ID of the sensor producing this message */
    public int sensor_id;

    /** Timestamp of first keyframe */
    public long timestamp_1;

    /** Timestamp of second keyframe */
    public long timestamp_2;

    /** Relative translation [x,y,z] described in first keyframe */
    public int[] trans;

    /** Real component of quaternion to describe relative rotation (second to first keyframe) */
    public int w;

    /**
     * 1st imaginary component of quaternion to describe relative rotation (second to first
     * keyframe)
     */
    public int x;

    /**
     * 2nd imaginary component of quaternion to describe relative rotation (second to first
     * keyframe)
     */
    public int y;

    /**
     * 3rd imaginary component of quaternion to describe relative rotation (second to first
     * keyframe)
     */
    public int z;

    /** Estimated variance of x (relative translation) */
    public float cov_r_x_x;

    /** Covariance of x and y (relative translation) */
    public float cov_r_x_y;

    /** Covariance of x and z (relative translation) */
    public float cov_r_x_z;

    /** Estimated variance of y (relative translation) */
    public float cov_r_y_y;

    /** Covariance of y and z (relative translation) */
    public float cov_r_y_z;

    /** Estimated variance of z (relative translation) */
    public float cov_r_z_z;

    /** Estimated variance of x (relative rotation) */
    public float cov_c_x_x;

    /** Covariance of x and y (relative rotation) */
    public float cov_c_x_y;

    /** Covariance of x and z (relative rotation) */
    public float cov_c_x_z;

    /** Estimated variance of y (relative rotation) */
    public float cov_c_y_y;

    /** Covariance of y and z (relative rotation) */
    public float cov_c_y_z;

    /** Estimated variance of z (relative rotation) */
    public float cov_c_z_z;

    /** Status flags of relative translation and rotation */
    public int flags;

    public MsgPoseRelative(int sender) {
        super(sender, TYPE);
    }

    public MsgPoseRelative() {
        super(TYPE);
    }

    public MsgPoseRelative(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        if (msg.type != TYPE)
            throw new SBPBinaryException(
                    "Type mismatch for MsgPoseRelative, expected 581, actual " + msg.type);
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        tow = parser.getU32();
        sensor_id = parser.getU8();
        timestamp_1 = parser.getU32();
        timestamp_2 = parser.getU32();
        trans = parser.getArrayofS32(3);
        w = parser.getS32();
        x = parser.getS32();
        y = parser.getS32();
        z = parser.getS32();
        cov_r_x_x = parser.getFloat();
        cov_r_x_y = parser.getFloat();
        cov_r_x_z = parser.getFloat();
        cov_r_y_y = parser.getFloat();
        cov_r_y_z = parser.getFloat();
        cov_r_z_z = parser.getFloat();
        cov_c_x_x = parser.getFloat();
        cov_c_x_y = parser.getFloat();
        cov_c_x_z = parser.getFloat();
        cov_c_y_y = parser.getFloat();
        cov_c_y_z = parser.getFloat();
        cov_c_z_z = parser.getFloat();
        flags = parser.getU8();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU32(tow);
        builder.putU8(sensor_id);
        builder.putU32(timestamp_1);
        builder.putU32(timestamp_2);
        builder.putArrayofS32(trans, 3);
        builder.putS32(w);
        builder.putS32(x);
        builder.putS32(y);
        builder.putS32(z);
        builder.putFloat(cov_r_x_x);
        builder.putFloat(cov_r_x_y);
        builder.putFloat(cov_r_x_z);
        builder.putFloat(cov_r_y_y);
        builder.putFloat(cov_r_y_z);
        builder.putFloat(cov_r_z_z);
        builder.putFloat(cov_c_x_x);
        builder.putFloat(cov_c_x_y);
        builder.putFloat(cov_c_x_z);
        builder.putFloat(cov_c_y_y);
        builder.putFloat(cov_c_y_z);
        builder.putFloat(cov_c_z_z);
        builder.putU8(flags);
    }

    @Override
    public String getFriendlyName() {
        return "POSE RELATIVE";
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("tow", tow);
        obj.put("sensor_id", sensor_id);
        obj.put("timestamp_1", timestamp_1);
        obj.put("timestamp_2", timestamp_2);
        obj.put("trans", new JSONArray(trans));
        obj.put("w", w);
        obj.put("x", x);
        obj.put("y", y);
        obj.put("z", z);
        obj.put("cov_r_x_x", cov_r_x_x);
        obj.put("cov_r_x_y", cov_r_x_y);
        obj.put("cov_r_x_z", cov_r_x_z);
        obj.put("cov_r_y_y", cov_r_y_y);
        obj.put("cov_r_y_z", cov_r_y_z);
        obj.put("cov_r_z_z", cov_r_z_z);
        obj.put("cov_c_x_x", cov_c_x_x);
        obj.put("cov_c_x_y", cov_c_x_y);
        obj.put("cov_c_x_z", cov_c_x_z);
        obj.put("cov_c_y_y", cov_c_y_y);
        obj.put("cov_c_y_z", cov_c_y_z);
        obj.put("cov_c_z_z", cov_c_z_z);
        obj.put("flags", flags);
        return obj;
    }
}
