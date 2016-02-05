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


/** SBP class for message MSG_ACQ_RESULT (0x0014).
 *
 * You can have MSG_ACQ_RESULT inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
 * This message describes the results from an attempted GPS signal
 * acquisition search for a satellite PRN over a code phase/carrier
 * frequency range. It contains the parameters of the point in the
 * acquisition search space with the best signal-to-noise (SNR)
 * ratio. */

public class MsgAcqResult extends SBPMessage {
    public static final int TYPE = 0x0014;

    
    /** SNR of best point. Currently in arbitrary SNR points, but will
be in units of dB Hz in a later revision of this message.
 */
    public float snr;
    
    /** Code phase of best point */
    public float cp;
    
    /** Carrier frequency of best point */
    public float cf;
    
    /** GNSS signal for which acquisition was attempted */
    public GnssSignal sid;
    

    public MsgAcqResult (int sender) { super(sender, TYPE); }
    public MsgAcqResult () { super(TYPE); }
    public MsgAcqResult (SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type != TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        snr = parser.getFloat();
        cp = parser.getFloat();
        cf = parser.getFloat();
        sid = new GnssSignal().parse(parser);
    }

    @Override
    protected void build(Builder builder) {
        builder.putFloat(snr);
        builder.putFloat(cp);
        builder.putFloat(cf);
        sid.build(builder);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("snr", snr);
        obj.put("cp", cp);
        obj.put("cf", cf);
        obj.put("sid", sid.toJSON());
        return obj;
    }
}