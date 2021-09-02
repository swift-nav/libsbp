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
package com.swiftnav.sbp.ssr;

// This file was auto-generated from yaml/swiftnav/sbp/ssr.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPStruct;
import com.swiftnav.sbp.gnss.*;
import org.json.JSONObject;

/**
 * SBP class for message MSG_SSR_GRIDDED_CORRECTION (0x05FC).
 *
 * <p>You can have MSG_SSR_GRIDDED_CORRECTION inherent its fields directly from an inherited SBP
 * object, or construct it inline using a dict of its fields.
 *
 * <p>STEC residuals are per space vehicle, troposphere is not.
 *
 * <p>It is typically equivalent to the QZSS CLAS Sub Type 9 messages.
 */
public class MsgSsrGriddedCorrection extends SBPMessage {
    public static final int TYPE = 0x05FC;

    /** Header of a gridded correction message */
    public GriddedCorrectionHeader header;

    /** Index of the grid point. */
    public int index;

    /** Wet and hydrostatic vertical delays (mean, stddev). */
    public TroposphericDelayCorrection tropo_delay_correction;

    /** STEC residuals for each satellite (mean, stddev). */
    public STECResidual[] stec_residuals;

    public MsgSsrGriddedCorrection(int sender) {
        super(sender, TYPE);
    }

    public MsgSsrGriddedCorrection() {
        super(TYPE);
    }

    public MsgSsrGriddedCorrection(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type == TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        header = new GriddedCorrectionHeader().parse(parser);
        index = parser.getU16();
        tropo_delay_correction = new TroposphericDelayCorrection().parse(parser);
        stec_residuals = parser.getArray(STECResidual.class);
    }

    @Override
    protected void build(Builder builder) {
        header.build(builder);
        builder.putU16(index);
        tropo_delay_correction.build(builder);
        builder.putArray(stec_residuals);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("header", header.toJSON());
        obj.put("index", index);
        obj.put("tropo_delay_correction", tropo_delay_correction.toJSON());
        obj.put("stec_residuals", SBPStruct.toJSONArray(stec_residuals));
        return obj;
    }
}
