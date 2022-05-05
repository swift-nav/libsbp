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
package com.swiftnav.sbp.system;

// This file was auto-generated from yaml/swiftnav/sbp/system.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import org.json.JSONObject;

/**
 * SBP class for message MSG_SENSOR_AID_EVENT (0xFF09).
 *
 * <p>You can have MSG_SENSOR_AID_EVENT inherent its fields directly from an inherited SBP object,
 * or construct it inline using a dict of its fields.
 *
 * <p>This diagnostic message contains state and update status information for all sensors that are
 * being used by the fusion engine. This message will be generated asynchronously to the solution
 * messages and will be emitted anytime a sensor update is being processed.
 */
public class MsgSensorAidEvent extends SBPMessage {
    public static final int TYPE = 0xFF09;

    /** Update timestamp in milliseconds. */
    public long time;

    /** Sensor type */
    public int sensor_type;

    /** Sensor identifier */
    public int sensor_id;

    /** Reserved for future use */
    public int sensor_state;

    /** Number of available measurements in this epoch */
    public int n_available_meas;

    /** Number of attempted measurements in this epoch */
    public int n_attempted_meas;

    /** Number of accepted measurements in this epoch */
    public int n_accepted_meas;

    /** Reserved for future use */
    public long flags;

    public MsgSensorAidEvent(int sender) {
        super(sender, TYPE);
    }

    public MsgSensorAidEvent() {
        super(TYPE);
    }

    public MsgSensorAidEvent(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type == TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        time = parser.getU32();
        sensor_type = parser.getU8();
        sensor_id = parser.getU16();
        sensor_state = parser.getU8();
        n_available_meas = parser.getU8();
        n_attempted_meas = parser.getU8();
        n_accepted_meas = parser.getU8();
        flags = parser.getU32();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU32(time);
        builder.putU8(sensor_type);
        builder.putU16(sensor_id);
        builder.putU8(sensor_state);
        builder.putU8(n_available_meas);
        builder.putU8(n_attempted_meas);
        builder.putU8(n_accepted_meas);
        builder.putU32(flags);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("time", time);
        obj.put("sensor_type", sensor_type);
        obj.put("sensor_id", sensor_id);
        obj.put("sensor_state", sensor_state);
        obj.put("n_available_meas", n_available_meas);
        obj.put("n_attempted_meas", n_attempted_meas);
        obj.put("n_accepted_meas", n_accepted_meas);
        obj.put("flags", flags);
        return obj;
    }
}
