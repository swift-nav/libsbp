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
 * SBP class for message MSG_PROTECTION_LEVEL_DEP_A (0x0216).
 *
 * <p>You can have MSG_PROTECTION_LEVEL_DEP_A inherent its fields directly from an inherited SBP
 * object, or construct it inline using a dict of its fields.
 *
 * <p>This message reports the local vertical and horizontal protection levels associated with a
 * given LLH position solution. The full GPS time is given by the preceding MSG_GPS_TIME with the
 * matching time-of-week (tow).
 */
public class MsgProtectionLevelDepA extends SBPMessage {
    public static final int TYPE = 0x0216;

    /** GPS Time of Week */
    public long tow;

    /** Vertical protection level */
    public int vpl;

    /** Horizontal protection level */
    public int hpl;

    /** Latitude */
    public double lat;

    /** Longitude */
    public double lon;

    /** Height */
    public double height;

    /** Status flags */
    public int flags;

    public MsgProtectionLevelDepA(int sender) {
        super(sender, TYPE);
    }

    public MsgProtectionLevelDepA() {
        super(TYPE);
    }

    public MsgProtectionLevelDepA(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type == TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        tow = parser.getU32();
        vpl = parser.getU16();
        hpl = parser.getU16();
        lat = parser.getDouble();
        lon = parser.getDouble();
        height = parser.getDouble();
        flags = parser.getU8();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU32(tow);
        builder.putU16(vpl);
        builder.putU16(hpl);
        builder.putDouble(lat);
        builder.putDouble(lon);
        builder.putDouble(height);
        builder.putU8(flags);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("tow", tow);
        obj.put("vpl", vpl);
        obj.put("hpl", hpl);
        obj.put("lat", lat);
        obj.put("lon", lon);
        obj.put("height", height);
        obj.put("flags", flags);
        return obj;
    }
}
