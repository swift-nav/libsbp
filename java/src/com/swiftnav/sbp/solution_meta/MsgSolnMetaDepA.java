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
 * SBP class for message MSG_SOLN_META_DEP_A (0xFF0F).
 *
 * <p>You can have MSG_SOLN_META_DEP_A inherent its fields directly from an inherited SBP object, or
 * construct it inline using a dict of its fields.
 *
 * <p>Deprecated.
 *
 * <p>This message contains all metadata about the sensors received and/or used in computing the
 * Fuzed Solution. It focuses primarily, but not only, on GNSS metadata.
 */
public class MsgSolnMetaDepA extends SBPMessage {
    public static final int TYPE = 0xFF0F;

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

    /** Number of satellites as per last available solution from PVT engine */
    public int n_sats;

    /**
     * Age of corrections as per last available AGE_CORRECTIONS from PVT engine (0xFFFF indicates
     * invalid)
     */
    public int age_corrections;

    /** State of alignment and the status and receipt of the alignment inputs */
    public int alignment_status;

    /** Tow of last-used GNSS position measurement */
    public long last_used_gnss_pos_tow;

    /** Tow of last-used GNSS velocity measurement */
    public long last_used_gnss_vel_tow;

    /**
     * Array of Metadata describing the sensors potentially involved in the solution. Each element
     * in the array represents a single sensor type and consists of flags containing (meta)data
     * pertaining to that specific single sensor. Refer to each (XX)InputType descriptor in the
     * present doc.
     */
    public SolutionInputType[] sol_in;

    public MsgSolnMetaDepA(int sender) {
        super(sender, TYPE);
    }

    public MsgSolnMetaDepA() {
        super(TYPE);
    }

    public MsgSolnMetaDepA(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type == TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        pdop = parser.getU16();
        hdop = parser.getU16();
        vdop = parser.getU16();
        n_sats = parser.getU8();
        age_corrections = parser.getU16();
        alignment_status = parser.getU8();
        last_used_gnss_pos_tow = parser.getU32();
        last_used_gnss_vel_tow = parser.getU32();
        sol_in = parser.getArray(SolutionInputType.class);
    }

    @Override
    protected void build(Builder builder) {
        builder.putU16(pdop);
        builder.putU16(hdop);
        builder.putU16(vdop);
        builder.putU8(n_sats);
        builder.putU16(age_corrections);
        builder.putU8(alignment_status);
        builder.putU32(last_used_gnss_pos_tow);
        builder.putU32(last_used_gnss_vel_tow);
        builder.putArray(sol_in);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("pdop", pdop);
        obj.put("hdop", hdop);
        obj.put("vdop", vdop);
        obj.put("n_sats", n_sats);
        obj.put("age_corrections", age_corrections);
        obj.put("alignment_status", alignment_status);
        obj.put("last_used_gnss_pos_tow", last_used_gnss_pos_tow);
        obj.put("last_used_gnss_vel_tow", last_used_gnss_vel_tow);
        obj.put("sol_in", SBPStruct.toJSONArray(sol_in));
        return obj;
    }
}
