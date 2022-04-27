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
package com.swiftnav.sbp.vehicle;

// This file was auto-generated from yaml/swiftnav/sbp/vehicle.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import org.json.JSONObject;

/**
 * SBP class for message MSG_ODOMETRY (0x0903).
 *
 * <p>You can have MSG_ODOMETRY inherent its fields directly from an inherited SBP object, or
 * construct it inline using a dict of its fields.
 *
 * <p>Message representing the x component of vehicle velocity in the user frame at the odometry
 * reference point(s) specified by the user. The offset for the odometry reference point and the
 * definition and origin of the user frame are defined through the device settings interface. There
 * are 4 possible user-defined sources of this message which are labeled arbitrarily source 0
 * through 3. If using "processor time" time tags, the receiving end will expect a
 * `MSG_GNSS_TIME_OFFSET` when a PVT fix becomes available to synchronise odometry measurements with
 * GNSS. Processor time shall roll over to zero after one week.
 */
public class MsgOdometry extends SBPMessage {
    public static final int TYPE = 0x0903;

    /**
     * Time field representing either milliseconds in the GPS Week or local CPU time from the
     * producing system in milliseconds. See the tow_source flag for the exact source of this
     * timestamp.
     */
    public long tow;

    /** The signed forward component of vehicle velocity. */
    public int velocity;

    /** Status flags */
    public int flags;

    public MsgOdometry(int sender) {
        super(sender, TYPE);
    }

    public MsgOdometry() {
        super(TYPE);
    }

    public MsgOdometry(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type == TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        tow = parser.getU32();
        velocity = parser.getS32();
        flags = parser.getU8();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU32(tow);
        builder.putS32(velocity);
        builder.putU8(flags);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("tow", tow);
        obj.put("velocity", velocity);
        obj.put("flags", flags);
        return obj;
    }
}
