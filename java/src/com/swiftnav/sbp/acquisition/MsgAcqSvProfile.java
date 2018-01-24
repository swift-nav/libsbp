/*
 * Copyright (C) 2015-2018 Swift Navigation Inc.
 * Contact: Swift Navigation <dev@swiftnav.com>
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

package com.swiftnav.sbp.acquisition;

import java.math.BigInteger;

import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPStruct;
import com.swiftnav.sbp.gnss.*;

import org.json.JSONObject;
import org.json.JSONArray;


/** SBP class for message MSG_ACQ_SV_PROFILE (0x002E).
 *
 * You can have MSG_ACQ_SV_PROFILE inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
 * The message describes all SV profiles during acquisition time.
 * The message is used to debug and measure the performance. */

public class MsgAcqSvProfile extends SBPMessage {
    public static final int TYPE = 0x002E;

    
    /** SV profiles during acquisition time */
    public AcqSvProfile[] acq_sv_profile;
    

    public MsgAcqSvProfile (int sender) { super(sender, TYPE); }
    public MsgAcqSvProfile () { super(TYPE); }
    public MsgAcqSvProfile (SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type != TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        acq_sv_profile = parser.getArray(AcqSvProfile.class);
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