/*
 * Copyright (C) 2015 Swift Navigation Inc.
 * Contact: Gareth McMullin <gareth@swiftnav.com>
 * Contact: Bhaskar Mookerji <mookerji@swiftnav.com>
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */

package com.swiftnav.sbp.acquisition;

import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPStruct;
import com.swiftnav.sbp.gnss_signal.*;

import org.json.JSONObject;
import org.json.JSONArray;


/** SBP class for message MSG_ACQ_RESULT_DEP_A (0x0015).
 *
 * You can have MSG_ACQ_RESULT_DEP_A inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
* Deprecated. */

public class MsgAcqResultDepA extends SBPMessage {
    public static final int TYPE = 0x0015;

    
    /** SNR of best point. Currently dimensonless, but will have
units of dB Hz in the revision of this message.
 */
    public float snr;
    
    /** Code phase of best point */
    public float cp;
    
    /** Carrier frequency of best point */
    public float cf;
    
    /** PRN-1 identifier of the satellite signal for which
acquisition was attempted
 */
    public int prn;
    

    public MsgAcqResultDepA (int sender) { super(sender, TYPE); }
    public MsgAcqResultDepA () { super(TYPE); }
    public MsgAcqResultDepA (SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type != TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        snr = parser.getFloat();
        cp = parser.getFloat();
        cf = parser.getFloat();
        prn = parser.getU8();
    }

    @Override
    protected void build(Builder builder) {
        builder.putFloat(snr);
        builder.putFloat(cp);
        builder.putFloat(cf);
        builder.putU8(prn);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("snr", snr);
        obj.put("cp", cp);
        obj.put("cf", cf);
        obj.put("prn", prn);
        return obj;
    }
}