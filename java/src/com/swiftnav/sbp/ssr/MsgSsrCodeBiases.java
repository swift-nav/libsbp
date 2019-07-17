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

package com.swiftnav.sbp.ssr;

import java.math.BigInteger;

import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPStruct;
import com.swiftnav.sbp.gnss.*;

import org.json.JSONObject;
import org.json.JSONArray;


/** SBP class for message MSG_SSR_CODE_BIASES (0x05E1).
 *
 * You can have MSG_SSR_CODE_BIASES inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
 * The precise code biases message is to be added
 * to the pseudorange of the corresponding signal
 * to get corrected pseudorange. It is typically
 * an equivalent to the 1059 and 1065 RTCM message types */

public class MsgSsrCodeBiases extends SBPMessage {
    public static final int TYPE = 0x05E1;

    
    /** GNSS reference time of the correction */
    public GPSTimeSec time;
    
    /** GNSS signal identifier (16 bit) */
    public GnssSignal sid;
    
    /** Update interval between consecutive corrections. Encoded
following RTCM DF391 specification.
 */
    public int update_interval;
    
    /** IOD of the SSR correction. A change of Issue Of Data
SSR is used to indicate a change in the SSR
generating configuration
 */
    public int iod_ssr;
    
    /** Code biases for the different satellite signals */
    public CodeBiasesContent[] biases;
    

    public MsgSsrCodeBiases (int sender) { super(sender, TYPE); }
    public MsgSsrCodeBiases () { super(TYPE); }
    public MsgSsrCodeBiases (SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type != TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        time = new GPSTimeSec().parse(parser);
        sid = new GnssSignal().parse(parser);
        update_interval = parser.getU8();
        iod_ssr = parser.getU8();
        biases = parser.getArray(CodeBiasesContent.class);
    }

    @Override
    protected void build(Builder builder) {
        time.build(builder);
        sid.build(builder);
        builder.putU8(update_interval);
        builder.putU8(iod_ssr);
        builder.putArray(biases);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("time", time.toJSON());
        obj.put("sid", sid.toJSON());
        obj.put("update_interval", update_interval);
        obj.put("iod_ssr", iod_ssr);
        obj.put("biases", SBPStruct.toJSONArray(biases));
        return obj;
    }
}