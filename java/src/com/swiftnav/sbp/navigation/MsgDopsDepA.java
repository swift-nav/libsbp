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
package com.swiftnav.sbp.navigation;

// This file was auto-generated from yaml/swiftnav/sbp/navigation.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import org.json.JSONObject;

/**
 * SBP class for message MSG_DOPS_DEP_A (0x0206).
 *
 * <p>You can have MSG_DOPS_DEP_A inherent its fields directly from an inherited SBP object, or
 * construct it inline using a dict of its fields.
 *
 * <p>Deprecated.
 */
public class MsgDopsDepA extends SBPMessage {
    public static final int TYPE = 0x0206;

    /** GPS Time of Week */
    public long tow;

    /** Geometric Dilution of Precision */
    public int gdop;

    /** Position Dilution of Precision */
    public int pdop;

    /** Time Dilution of Precision */
    public int tdop;

    /** Horizontal Dilution of Precision */
    public int hdop;

    /** Vertical Dilution of Precision */
    public int vdop;

    public MsgDopsDepA(int sender) {
        super(sender, TYPE);
    }

    public MsgDopsDepA() {
        super(TYPE);
    }

    public MsgDopsDepA(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        if (msg.type != TYPE)
            throw new SBPBinaryException(
                    "Type mismatch for MsgDopsDepA, expected 518, actual " + msg.type);
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        tow = parser.getU32();
        gdop = parser.getU16();
        pdop = parser.getU16();
        tdop = parser.getU16();
        hdop = parser.getU16();
        vdop = parser.getU16();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU32(tow);
        builder.putU16(gdop);
        builder.putU16(pdop);
        builder.putU16(tdop);
        builder.putU16(hdop);
        builder.putU16(vdop);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("tow", tow);
        obj.put("gdop", gdop);
        obj.put("pdop", pdop);
        obj.put("tdop", tdop);
        obj.put("hdop", hdop);
        obj.put("vdop", vdop);
        return obj;
    }

    @Override
    public String getFriendlyName() {
        return "DOPS DEP A";
    }
}
