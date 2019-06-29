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


/** SBP class for message MSG_SSR_ORBIT_CLOCK (0x05DD).
 *
 * You can have MSG_SSR_ORBIT_CLOCK inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
 * The precise orbit and clock correction message is
 * to be applied as a delta correction to broadcast
 * ephemeris and is typically an equivalent to the 1060
 * and 1066 RTCM message types */

public class MsgSsrOrbitClock extends SBPMessage {
    public static final int TYPE = 0x05DD;

    
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
    
    /** C0 polynomial coefficient for correction of broadcast satellite clock */
    public int c0;
    
    /** C1 polynomial coefficient for correction of broadcast satellite clock */
    public int c1;
    
    /** C2 polynomial coefficient for correction of broadcast satellite clock */
    public int c2;
    

    public MsgSsrOrbitClock (int sender) { super(sender, TYPE); }
    public MsgSsrOrbitClock () { super(TYPE); }
    public MsgSsrOrbitClock (SBPMessage msg) throws SBPBinaryException {
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
        c0 = parser.getS32();
        c1 = parser.getS32();
        c2 = parser.getS32();
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
        builder.putS32(c0);
        builder.putS32(c1);
        builder.putS32(c2);
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
        obj.put("c0", c0);
        obj.put("c1", c1);
        obj.put("c2", c2);
        return obj;
    }
}