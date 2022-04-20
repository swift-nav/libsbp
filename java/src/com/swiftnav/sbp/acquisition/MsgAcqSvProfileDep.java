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
package com.swiftnav.sbp.acquisition;

// This file was auto-generated from yaml/swiftnav/sbp/acquisition.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPStruct;
import com.swiftnav.sbp.gnss.*;
import org.json.JSONObject;

/**
 * SBP class for message MSG_ACQ_SV_PROFILE_DEP (0x001E).
 *
 * <p>You can have MSG_ACQ_SV_PROFILE_DEP inherent its fields directly from an inherited SBP object,
 * or construct it inline using a dict of its fields.
 *
 * <p>Deprecated.
 */
public class MsgAcqSvProfileDep extends SBPMessage {
    public static final int TYPE = 0x001E;

    /** SV profiles during acquisition time */
    public AcqSvProfileDep[] acq_sv_profile;

    public MsgAcqSvProfileDep(int sender) {
        super(sender, TYPE);
    }

    public MsgAcqSvProfileDep() {
        super(TYPE);
    }

    public MsgAcqSvProfileDep(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type == TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        acq_sv_profile = parser.getArray(AcqSvProfileDep.class);
    }

    @Override
    protected void build(Builder builder) {
        builder.putArray(acq_sv_profile);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("acq_sv_profile", SBPStruct.toJSONArray(acq_sv_profile));
        return obj;
    }
}
