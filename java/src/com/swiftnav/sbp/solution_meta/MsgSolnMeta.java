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
package com.swiftnav.sbp.solution_meta;

// This file was auto-generated from yaml/swiftnav/sbp/solution_meta.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPStruct;
import org.json.JSONObject;

/**
 * SBP class for message MSG_SOLN_META (0xFF0E).
 *
 * <p>You can have MSG_SOLN_META inherent its fields directly from an inherited SBP object, or
 * construct it inline using a dict of its fields.
 *
 * <p>This message contains all metadata about the sensors received and/or used in computing the
 * sensorfusion solution. It focuses primarily, but not only, on GNSS metadata. Regarding the age of
 * the last received valid GNSS solution, the highest two bits are time status, indicating whether
 * age gnss can or can not be used to retrieve time of measurement (noted TOM, also known as time of
 * validity) If it can, subtract 'age gnss' from 'tow' in navigation messages to get TOM. Can be
 * used before alignment is complete in the Fusion Engine, when output solution is the last received
 * valid GNSS solution and its tow is not a TOM.
 */
public class MsgSolnMeta extends SBPMessage {
    public static final int TYPE = 0xFF0E;

    /** GPS time of week rounded to the nearest millisecond */
    public long tow;

    /**
     * Position Dilution of Precision as per last available DOPS from PVT engine (0xFFFF indicates
     * invalid)
     */
    public int pdop;

    /**
     * Horizontal Dilution of Precision as per last available DOPS from PVT engine (0xFFFF indicates
     * invalid)
     */
    public int hdop;

    /**
     * Vertical Dilution of Precision as per last available DOPS from PVT engine (0xFFFF indicates
     * invalid)
     */
    public int vdop;

    /**
     * Age of corrections as per last available AGE_CORRECTIONS from PVT engine (0xFFFF indicates
     * invalid)
     */
    public int age_corrections;

    /** Age and Time Status of the last received valid GNSS solution. */
    public long age_gnss;

    /**
     * Array of Metadata describing the sensors potentially involved in the solution. Each element
     * in the array represents a single sensor type and consists of flags containing (meta)data
     * pertaining to that specific single sensor. Refer to each (XX)InputType descriptor in the
     * present doc.
     */
    public SolutionInputType[] sol_in;

    public MsgSolnMeta(int sender) {
        super(sender, TYPE);
    }

    public MsgSolnMeta() {
        super(TYPE);
    }

    public MsgSolnMeta(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type == TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        tow = parser.getU32();
        pdop = parser.getU16();
        hdop = parser.getU16();
        vdop = parser.getU16();
        age_corrections = parser.getU16();
        age_gnss = parser.getU32();
        sol_in = parser.getArray(SolutionInputType.class);
    }

    @Override
    protected void build(Builder builder) {
        builder.putU32(tow);
        builder.putU16(pdop);
        builder.putU16(hdop);
        builder.putU16(vdop);
        builder.putU16(age_corrections);
        builder.putU32(age_gnss);
        builder.putArray(sol_in);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("tow", tow);
        obj.put("pdop", pdop);
        obj.put("hdop", hdop);
        obj.put("vdop", vdop);
        obj.put("age_corrections", age_corrections);
        obj.put("age_gnss", age_gnss);
        obj.put("sol_in", SBPStruct.toJSONArray(sol_in));
        return obj;
    }
}
