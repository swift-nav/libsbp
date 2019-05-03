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


/** SBP class for message MSG_SSR_ORBIT (0x05DB).
 *
 * You can have MSG_SSR_ORBIT inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
 * The precise orbit correction message is to be applied 
 * as a delta correction to broadcast ephemeris and is 
 * typically an equivalent to the 1057 RTCM message types */

public class MsgSsrOrbit extends SBPMessage {
    public static final int TYPE = 0x05DB;

    
    /** GNSS reference time of the correction */
    public GPSTimeSec time;
    
    /** GNSS signal identifier (16 bit) */
    public GnssSignal sid;
    
    /** Update interval between consecutive corrections */
    public int update_interval;
    
    /** IOD of the SSR correction. A change of Issue Of Data
SSR is used to indicate a change in the SSR 
generating configuration
 */
    public int iod_ssr;
    
    /** Issue of broadcast ephemeris data or IODCRC (Beidou) */
    public long iod;
    
    /** Orbit radial delta correction */
    public int radial;
    
    /** Orbit along delta correction */
    public int along;
    
    /** Orbit along delta correction */
    public int cross;
    
    /** Velocity of orbit radial delta correction */
    public int dot_radial;
    
    /** Velocity of orbit along delta correction */
    public int dot_along;
    
    /** Velocity of orbit cross delta correction */
    public int dot_cross;
    

    public MsgSsrOrbit (int sender) { super(sender, TYPE); }
    public MsgSsrOrbit () { super(TYPE); }
    public MsgSsrOrbit (SBPMessage msg) throws SBPBinaryException {
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
        iod = parser.getU32();
        radial = parser.getS32();
        along = parser.getS32();
        cross = parser.getS32();
        dot_radial = parser.getS32();
        dot_along = parser.getS32();
        dot_cross = parser.getS32();
    }

    @Override
    protected void build(Builder builder) {
        time.build(builder);
        sid.build(builder);
        builder.putU8(update_interval);
        builder.putU8(iod_ssr);
        builder.putU32(iod);
        builder.putS32(radial);
        builder.putS32(along);
        builder.putS32(cross);
        builder.putS32(dot_radial);
        builder.putS32(dot_along);
        builder.putS32(dot_cross);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("time", time.toJSON());
        obj.put("sid", sid.toJSON());
        obj.put("update_interval", update_interval);
        obj.put("iod_ssr", iod_ssr);
        obj.put("iod", iod);
        obj.put("radial", radial);
        obj.put("along", along);
        obj.put("cross", cross);
        obj.put("dot_radial", dot_radial);
        obj.put("dot_along", dot_along);
        obj.put("dot_cross", dot_cross);
        return obj;
    }
}