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
package com.swiftnav.sbp.navigation;

// This file was auto-generated from yaml/swiftnav/sbp/navigation.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import org.json.JSONObject;

public class MsgReferenceFrameParam extends SBPMessage {
    public static final int TYPE = 0x0244;

    /** SSR IOD parameter. */
    public int ssr_iod;

    /** Name of source coordinate-system. */
    public String sn;

    /** Name of target coordinate-system. */
    public String tn;

    /** System Identification Number. */
    public int sin;

    /** Utilized Transformation Message. */
    public int utn;

    /**
     * Reference Epoch t0 for transformation parameter set given as Modified Julian Day (MJD) Number
     * minus 44244 days.
     */
    public int re_t0;

    /** Translation in X for Reference Epoch t0. */
    public int delta_X0;

    /** Translation in Y for Reference Epoch t0. */
    public int delta_Y0;

    /** Translation in Z for Reference Epoch t0. */
    public int delta_Z0;

    /** Rotation around the X-axis for Reference Epoch t0. */
    public int theta_01;

    /** Rotation around the Y-axis for Reference Epoch t0. */
    public int theta_02;

    /** Rotation around the Z-axis for Reference Epoch t0. */
    public int theta_03;

    /** Scale correction for Reference Epoch t0. */
    public int scale;

    /** Rate of change of translation in X. */
    public int dot_delta_X0;

    /** Rate of change of translation in Y. */
    public int dot_delta_Y0;

    /** Rate of change of translation in Z. */
    public int dot_delta_Z0;

    /** Rate of change of rotation around the X-axis. */
    public int dot_theta_01;

    /** Rate of change of rotation around the Y-axis. */
    public int dot_theta_02;

    /** Rate of change of rotation around the Z-axis. */
    public int dot_theta_03;

    /** Rate of change of scale correction. */
    public int dot_scale;

    public MsgReferenceFrameParam(int sender) {
        super(sender, TYPE);
    }

    public MsgReferenceFrameParam() {
        super(TYPE);
    }

    public MsgReferenceFrameParam(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type == TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        ssr_iod = parser.getU8();
        sn = parser.getString(32);
        tn = parser.getString(32);
        sin = parser.getU8();
        utn = parser.getU16();
        re_t0 = parser.getU16();
        delta_X0 = parser.getS32();
        delta_Y0 = parser.getS32();
        delta_Z0 = parser.getS32();
        theta_01 = parser.getS32();
        theta_02 = parser.getS32();
        theta_03 = parser.getS32();
        scale = parser.getS32();
        dot_delta_X0 = parser.getS32();
        dot_delta_Y0 = parser.getS32();
        dot_delta_Z0 = parser.getS32();
        dot_theta_01 = parser.getS32();
        dot_theta_02 = parser.getS32();
        dot_theta_03 = parser.getS32();
        dot_scale = parser.getS16();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU8(ssr_iod);
        builder.putString(sn, 32);
        builder.putString(tn, 32);
        builder.putU8(sin);
        builder.putU16(utn);
        builder.putU16(re_t0);
        builder.putS32(delta_X0);
        builder.putS32(delta_Y0);
        builder.putS32(delta_Z0);
        builder.putS32(theta_01);
        builder.putS32(theta_02);
        builder.putS32(theta_03);
        builder.putS32(scale);
        builder.putS32(dot_delta_X0);
        builder.putS32(dot_delta_Y0);
        builder.putS32(dot_delta_Z0);
        builder.putS32(dot_theta_01);
        builder.putS32(dot_theta_02);
        builder.putS32(dot_theta_03);
        builder.putS16(dot_scale);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("ssr_iod", ssr_iod);
        obj.put("sn", sn);
        obj.put("tn", tn);
        obj.put("sin", sin);
        obj.put("utn", utn);
        obj.put("re_t0", re_t0);
        obj.put("delta_X0", delta_X0);
        obj.put("delta_Y0", delta_Y0);
        obj.put("delta_Z0", delta_Z0);
        obj.put("theta_01", theta_01);
        obj.put("theta_02", theta_02);
        obj.put("theta_03", theta_03);
        obj.put("scale", scale);
        obj.put("dot_delta_X0", dot_delta_X0);
        obj.put("dot_delta_Y0", dot_delta_Y0);
        obj.put("dot_delta_Z0", dot_delta_Z0);
        obj.put("dot_theta_01", dot_theta_01);
        obj.put("dot_theta_02", dot_theta_02);
        obj.put("dot_theta_03", dot_theta_03);
        obj.put("dot_scale", dot_scale);
        return obj;
    }
}
