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
 * SBP class for message MSG_ORIENT_EULER (0x0221).
 *
 * <p>You can have MSG_ORIENT_EULER inherent its fields directly from an inherited SBP object, or
 * construct it inline using a dict of its fields.
 *
 * <p>This message reports the yaw, pitch, and roll angles of the vehicle body frame. The rotations
 * should applied intrinsically in the order yaw, pitch, and roll in order to rotate the from a
 * frame aligned with the local-level NED frame to the vehicle body frame. This message will only be
 * available in future INS versions of Swift Products and is not produced by Piksi Multi or Duro.
 */
public class MsgOrientEuler extends SBPMessage {
    public static final int TYPE = 0x0221;

    /** GPS Time of Week */
    public long tow;

    /** rotation about the forward axis of the vehicle */
    public int roll;

    /** rotation about the rightward axis of the vehicle */
    public int pitch;

    /** rotation about the downward axis of the vehicle */
    public int yaw;

    /** Estimated standard deviation of roll */
    public float roll_accuracy;

    /** Estimated standard deviation of pitch */
    public float pitch_accuracy;

    /** Estimated standard deviation of yaw */
    public float yaw_accuracy;

    /** Status flags */
    public int flags;

    public MsgOrientEuler(int sender) {
        super(sender, TYPE);
    }

    public MsgOrientEuler() {
        super(TYPE);
    }

    public MsgOrientEuler(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        if (msg.type != TYPE)
            throw new SBPBinaryException(
                    "Type mismatch for MsgOrientEuler, expected 545, actual " + msg.type);
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        tow = parser.getU32();
        roll = parser.getS32();
        pitch = parser.getS32();
        yaw = parser.getS32();
        roll_accuracy = parser.getFloat();
        pitch_accuracy = parser.getFloat();
        yaw_accuracy = parser.getFloat();
        flags = parser.getU8();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU32(tow);
        builder.putS32(roll);
        builder.putS32(pitch);
        builder.putS32(yaw);
        builder.putFloat(roll_accuracy);
        builder.putFloat(pitch_accuracy);
        builder.putFloat(yaw_accuracy);
        builder.putU8(flags);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("tow", tow);
        obj.put("roll", roll);
        obj.put("pitch", pitch);
        obj.put("yaw", yaw);
        obj.put("roll_accuracy", roll_accuracy);
        obj.put("pitch_accuracy", pitch_accuracy);
        obj.put("yaw_accuracy", yaw_accuracy);
        obj.put("flags", flags);
        return obj;
    }

    @Override
    public String getFriendlyName() {
        return "ORIENT EULER";
    }
}
