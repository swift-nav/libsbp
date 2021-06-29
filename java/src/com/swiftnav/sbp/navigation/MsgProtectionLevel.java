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
 * SBP class for message MSG_PROTECTION_LEVEL (0x0217).
 *
 * <p>You can have MSG_PROTECTION_LEVEL inherent its fields directly from an inherited SBP object,
 * or construct it inline using a dict of its fields.
 *
 * <p>This message reports the protection levels associated to the given state estimate. The full
 * GPS time is given by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
 */
public class MsgProtectionLevel extends SBPMessage {
    public static final int TYPE = 0x0217;

    /** GPS Time of Week */
    public long tow;

    /** GPS week number */
    public int wn;

    /** Horizontal protection level */
    public int hpl;

    /** Vertical protection level */
    public int vpl;

    /** Along-track position error protection level */
    public int atpl;

    /** Cross-track position error protection level */
    public int ctpl;

    /**
     * Protection level for the error vector between estimated and true along/cross track velocity
     * vector
     */
    public int hvpl;

    /**
     * Protection level for the velocity in vehicle upright direction (different from vertical
     * direction if on a slope)
     */
    public int vvpl;

    /** Heading orientation protection level */
    public int hopl;

    /** Pitch orientation protection level */
    public int popl;

    /** Roll orientation protection level */
    public int ropl;

    /** Latitude */
    public double lat;

    /** Longitude */
    public double lon;

    /** Height */
    public double height;

    /** Velocity in vehicle x direction */
    public int v_x;

    /** Velocity in vehicle y direction */
    public int v_y;

    /** Velocity in vehicle z direction */
    public int v_z;

    /** Roll angle */
    public int roll;

    /** Pitch angle */
    public int pitch;

    /** Heading angle */
    public int heading;

    /** Status flags */
    public long flags;

    public MsgProtectionLevel(int sender) {
        super(sender, TYPE);
    }

    public MsgProtectionLevel() {
        super(TYPE);
    }

    public MsgProtectionLevel(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type == TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        tow = parser.getU32();
        wn = parser.getS16();
        hpl = parser.getU16();
        vpl = parser.getU16();
        atpl = parser.getU16();
        ctpl = parser.getU16();
        hvpl = parser.getU16();
        vvpl = parser.getU16();
        hopl = parser.getU16();
        popl = parser.getU16();
        ropl = parser.getU16();
        lat = parser.getDouble();
        lon = parser.getDouble();
        height = parser.getDouble();
        v_x = parser.getS32();
        v_y = parser.getS32();
        v_z = parser.getS32();
        roll = parser.getS32();
        pitch = parser.getS32();
        heading = parser.getS32();
        flags = parser.getU32();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU32(tow);
        builder.putS16(wn);
        builder.putU16(hpl);
        builder.putU16(vpl);
        builder.putU16(atpl);
        builder.putU16(ctpl);
        builder.putU16(hvpl);
        builder.putU16(vvpl);
        builder.putU16(hopl);
        builder.putU16(popl);
        builder.putU16(ropl);
        builder.putDouble(lat);
        builder.putDouble(lon);
        builder.putDouble(height);
        builder.putS32(v_x);
        builder.putS32(v_y);
        builder.putS32(v_z);
        builder.putS32(roll);
        builder.putS32(pitch);
        builder.putS32(heading);
        builder.putU32(flags);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("tow", tow);
        obj.put("wn", wn);
        obj.put("hpl", hpl);
        obj.put("vpl", vpl);
        obj.put("atpl", atpl);
        obj.put("ctpl", ctpl);
        obj.put("hvpl", hvpl);
        obj.put("vvpl", vvpl);
        obj.put("hopl", hopl);
        obj.put("popl", popl);
        obj.put("ropl", ropl);
        obj.put("lat", lat);
        obj.put("lon", lon);
        obj.put("height", height);
        obj.put("v_x", v_x);
        obj.put("v_y", v_y);
        obj.put("v_z", v_z);
        obj.put("roll", roll);
        obj.put("pitch", pitch);
        obj.put("heading", heading);
        obj.put("flags", flags);
        return obj;
    }
}
