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
package com.swiftnav.sbp.orientation;

// This file was auto-generated from yaml/swiftnav/sbp/orientation.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import org.json.JSONObject;

/**
 * SBP class for message MSG_ORIENT_QUAT_COV (0x0223).
 *
 * <p>You can have MSG_ORIENT_QUAT_COV inherent its fields directly from an inherited SBP object, or
 * construct it inline using a dict of its fields.
 *
 * <p>This message reports the orientation as a unit quaternion together with the upper triangle of
 * the symmetric 3x3 attitude covariance matrix and a GPS time-of-week time-tag. The reference frame
 * of the quaternion and the parameterization of the covariance matrix are both encoded in the flags
 * field, allowing additional frames or parameterizations to be added later without introducing a
 * new message. By default the quaternion describes the orientation of the vehicle body frame with
 * respect to a local-level NED frame (matching MSG_ORIENT_QUAT) and the covariance is expressed as
 * small- angle rotation errors about the axes of that NED frame; in this default case the cov_x_x,
 * cov_y_y, cov_z_z diagonal entries correspond to the variance of the rotation error about North,
 * East, and Down respectively. The components of the quaternion sum to a unit vector assuming that
 * the LSB of each component has a value of 2^-31.
 */
public class MsgOrientQuatCov extends SBPMessage {
    public static final int TYPE = 0x0223;

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

    /** Estimated variance of the rotation error about the 1st axis of the covariance frame */
    public float cov_x_x;

    /**
     * Estimated covariance of the rotation errors about the 1st and 2nd axes of the covariance
     * frame
     */
    public float cov_x_y;

    /**
     * Estimated covariance of the rotation errors about the 1st and 3rd axes of the covariance
     * frame
     */
    public float cov_x_z;

    /** Estimated variance of the rotation error about the 2nd axis of the covariance frame */
    public float cov_y_y;

    /**
     * Estimated covariance of the rotation errors about the 2nd and 3rd axes of the covariance
     * frame
     */
    public float cov_y_z;

    /** Estimated variance of the rotation error about the 3rd axis of the covariance frame */
    public float cov_z_z;

    /** Status flags */
    public int flags;

    public MsgOrientQuatCov(int sender) {
        super(sender, TYPE);
    }

    public MsgOrientQuatCov() {
        super(TYPE);
    }

    public MsgOrientQuatCov(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        if (msg.type != TYPE)
            throw new SBPBinaryException(
                    "Type mismatch for MsgOrientQuatCov, expected 547, actual " + msg.type);
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        tow = parser.getU32();
        w = parser.getS32();
        x = parser.getS32();
        y = parser.getS32();
        z = parser.getS32();
        cov_x_x = parser.getFloat();
        cov_x_y = parser.getFloat();
        cov_x_z = parser.getFloat();
        cov_y_y = parser.getFloat();
        cov_y_z = parser.getFloat();
        cov_z_z = parser.getFloat();
        flags = parser.getU8();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU32(tow);
        builder.putS32(w);
        builder.putS32(x);
        builder.putS32(y);
        builder.putS32(z);
        builder.putFloat(cov_x_x);
        builder.putFloat(cov_x_y);
        builder.putFloat(cov_x_z);
        builder.putFloat(cov_y_y);
        builder.putFloat(cov_y_z);
        builder.putFloat(cov_z_z);
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
        obj.put("cov_x_x", cov_x_x);
        obj.put("cov_x_y", cov_x_y);
        obj.put("cov_x_z", cov_x_z);
        obj.put("cov_y_y", cov_y_y);
        obj.put("cov_y_z", cov_y_z);
        obj.put("cov_z_z", cov_z_z);
        obj.put("flags", flags);
        return obj;
    }

    @Override
    public String getFriendlyName() {
        return "ORIENT QUAT COV";
    }
}
