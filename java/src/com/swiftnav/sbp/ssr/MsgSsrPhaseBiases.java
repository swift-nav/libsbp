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


/** SBP class for message MSG_SSR_PHASE_BIASES (0x05E6).
 *
 * You can have MSG_SSR_PHASE_BIASES inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
 * The precise phase biases message contains the biases
 * to be added to the carrier phase of the corresponding
 * signal to get corrected carrier phase measurement, as
 * well as the satellite yaw angle to be applied to compute
 * the phase wind-up correction.
 * It is typically an equivalent to the 1265 RTCM message types */

public class MsgSsrPhaseBiases extends SBPMessage {
    public static final int TYPE = 0x05E6;

    
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
    
    /** Indicator for the dispersive phase biases property.
 */
    public int dispersive_bias;
    
    /** Consistency indicator for Melbourne-Wubbena linear combinations
 */
    public int mw_consistency;
    
    /** Satellite yaw angle */
    public int yaw;
    
    /** Satellite yaw angle rate */
    public int yaw_rate;
    
    /** Phase biases corrections for a
satellite being tracked.
 */
    public PhaseBiasesContent[] biases;
    

    public MsgSsrPhaseBiases (int sender) { super(sender, TYPE); }
    public MsgSsrPhaseBiases () { super(TYPE); }
    public MsgSsrPhaseBiases (SBPMessage msg) throws SBPBinaryException {
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
        dispersive_bias = parser.getU8();
        mw_consistency = parser.getU8();
        yaw = parser.getU16();
        yaw_rate = parser.getS8();
        biases = parser.getArray(PhaseBiasesContent.class);
    }

    @Override
    protected void build(Builder builder) {
        time.build(builder);
        sid.build(builder);
        builder.putU8(update_interval);
        builder.putU8(iod_ssr);
        builder.putU8(dispersive_bias);
        builder.putU8(mw_consistency);
        builder.putU16(yaw);
        builder.putS8(yaw_rate);
        builder.putArray(biases);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("time", time.toJSON());
        obj.put("sid", sid.toJSON());
        obj.put("update_interval", update_interval);
        obj.put("iod_ssr", iod_ssr);
        obj.put("dispersive_bias", dispersive_bias);
        obj.put("mw_consistency", mw_consistency);
        obj.put("yaw", yaw);
        obj.put("yaw_rate", yaw_rate);
        obj.put("biases", SBPStruct.toJSONArray(biases));
        return obj;
    }
}