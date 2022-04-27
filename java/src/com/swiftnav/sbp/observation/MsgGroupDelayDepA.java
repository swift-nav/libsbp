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
package com.swiftnav.sbp.observation;

// This file was auto-generated from yaml/swiftnav/sbp/observation.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.gnss.*;
import org.json.JSONObject;

/**
 * SBP class for message MSG_GROUP_DELAY_DEP_A (0x0092).
 *
 * <p>You can have MSG_GROUP_DELAY_DEP_A inherent its fields directly from an inherited SBP object,
 * or construct it inline using a dict of its fields.
 *
 * <p>Please see ICD-GPS-200 (30.3.3.3.1.1) for more details.
 */
public class MsgGroupDelayDepA extends SBPMessage {
    public static final int TYPE = 0x0092;

    /** Data Predict Time of Week */
    public GPSTimeDep t_op;

    /** Satellite number */
    public int prn;

    /**
     * bit-field indicating validity of the values, LSB indicating tgd validity etc. 1 = value is
     * valid, 0 = value is not valid.
     */
    public int valid;

    public int tgd;

    public int isc_l1ca;

    public int isc_l2c;

    public MsgGroupDelayDepA(int sender) {
        super(sender, TYPE);
    }

    public MsgGroupDelayDepA() {
        super(TYPE);
    }

    public MsgGroupDelayDepA(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type == TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        t_op = new GPSTimeDep().parse(parser);
        prn = parser.getU8();
        valid = parser.getU8();
        tgd = parser.getS16();
        isc_l1ca = parser.getS16();
        isc_l2c = parser.getS16();
    }

    @Override
    protected void build(Builder builder) {
        t_op.build(builder);
        builder.putU8(prn);
        builder.putU8(valid);
        builder.putS16(tgd);
        builder.putS16(isc_l1ca);
        builder.putS16(isc_l2c);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("t_op", t_op.toJSON());
        obj.put("prn", prn);
        obj.put("valid", valid);
        obj.put("tgd", tgd);
        obj.put("isc_l1ca", isc_l1ca);
        obj.put("isc_l2c", isc_l2c);
        return obj;
    }
}
