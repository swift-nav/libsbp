/* Copyright (C) 2015-2021 Swift Navigation Inc.
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
import org.json.JSONObject;

/**
 * SBP class for message MSG_VEL_COG (0x021C).
 *
 * <p>You can have MSG_VEL_COG inherent its fields directly from an inherited SBP object, or
 * construct it inline using a dict of its fields.
 *
 * <p>This message reports the receiver course over ground (COG) and speed over ground (SOG) based
 * on the horizontal (N-E) components of the NED velocity vector. It also includes the vertical
 * velocity in the form of the D-component of the NED velocity vector. The NED coordinate system is
 * defined as the local WGS84 tangent plane centered at the current position. The full GPS time is
 * given by the preceding MSG_GPS_TIME with the matching time-of-week (tow). Note: course over
 * ground represents the receiver's direction of travel, but not necessarily the device heading.
 */
public class MsgVelCog extends SBPMessage {
    public static final int TYPE = 0x021C;

    /** GPS Time of Week */
    public long tow;

    /** Course over ground relative to local north */
    public long cog;

    /** Speed over ground */
    public long sog;

    /** Velocity Down coordinate */
    public int vel_d;

    /** Course over ground estimated standard deviation */
    public long cog_accuracy;

    /** Speed over ground estimated standard deviation */
    public long sog_accuracy;

    /** Vertical velocity estimated standard deviation */
    public long vel_d_accuracy;

    /** Status flags */
    public int flags;

    public MsgVelCog(int sender) {
        super(sender, TYPE);
    }

    public MsgVelCog() {
        super(TYPE);
    }

    public MsgVelCog(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type == TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        tow = parser.getU32();
        cog = parser.getU32();
        sog = parser.getU32();
        vel_d = parser.getS32();
        cog_accuracy = parser.getU32();
        sog_accuracy = parser.getU32();
        vel_d_accuracy = parser.getU32();
        flags = parser.getU8();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU32(tow);
        builder.putU32(cog);
        builder.putU32(sog);
        builder.putS32(vel_d);
        builder.putU32(cog_accuracy);
        builder.putU32(sog_accuracy);
        builder.putU32(vel_d_accuracy);
        builder.putU8(flags);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("tow", tow);
        obj.put("cog", cog);
        obj.put("sog", sog);
        obj.put("vel_d", vel_d);
        obj.put("cog_accuracy", cog_accuracy);
        obj.put("sog_accuracy", sog_accuracy);
        obj.put("vel_d_accuracy", vel_d_accuracy);
        obj.put("flags", flags);
        return obj;
    }
}
