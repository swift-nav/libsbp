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

package com.swiftnav.sbp.tracking;

import java.math.BigInteger;

import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPStruct;
import com.swiftnav.sbp.gnss.*;

import org.json.JSONObject;
import org.json.JSONArray;


/** SBP class for message MSG_TRACKING_STATE_DETAILED (0x0021).
 *
 * You can have MSG_TRACKING_STATE_DETAILED inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
 * The tracking message returns a set tracking channel parameters for a
 * single tracking channel useful for debugging issues. */

public class MsgTrackingStateDetailed extends SBPMessage {
    public static final int TYPE = 0x0021;

    
    /** Receiver clock time. */
    public BigInteger recv_time;
    
    /** Time of transmission of signal from satellite. TOW only valid when
TOW status is decoded or propagated. WN only valid when week
number valid flag is set.
 */
    public GPSTime tot;
    
    /** Pseudorange observation. Valid only when pseudorange valid flag is
set.
 */
    public long P;
    
    /** Pseudorange observation standard deviation. Valid only when
pseudorange valid flag is set.
 */
    public int P_std;
    
    /** Carrier phase observation with typical sign convention. Valid only
when PLL pessimistic lock is achieved.
 */
    public CarrierPhase L;
    
    /** Carrier-to-Noise density */
    public int cn0;
    
    /** Lock time. It is encoded according to DF402 from the RTCM 10403.2
Amendment 2 specification. Valid values range from 0 to 15.
 */
    public int lock;
    
    /** GNSS signal identifier. */
    public GnssSignal sid;
    
    /** Carrier Doppler frequency. */
    public int doppler;
    
    /** Carrier Doppler frequency standard deviation. */
    public int doppler_std;
    
    /** Number of seconds of continuous tracking. Specifies how much time
signal is in continuous track.
 */
    public long uptime;
    
    /** TCXO clock offset. Valid only when valid clock valid flag is set.
 */
    public int clock_offset;
    
    /** TCXO clock drift. Valid only when valid clock valid flag is set.
 */
    public int clock_drift;
    
    /** Early-Prompt (EP) and Prompt-Late (PL) correlators spacing. */
    public int corr_spacing;
    
    /** Acceleration. Valid only when acceleration valid flag is set. */
    public int acceleration;
    
    /** Synchronization status flags. */
    public int sync_flags;
    
    /** TOW status flags. */
    public int tow_flags;
    
    /** Tracking loop status flags. */
    public int track_flags;
    
    /** Navigation data status flags. */
    public int nav_flags;
    
    /** Parameters sets flags. */
    public int pset_flags;
    
    /** Miscellaneous flags. */
    public int misc_flags;
    

    public MsgTrackingStateDetailed (int sender) { super(sender, TYPE); }
    public MsgTrackingStateDetailed () { super(TYPE); }
    public MsgTrackingStateDetailed (SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type != TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        recv_time = parser.getU64();
        tot = new GPSTime().parse(parser);
        P = parser.getU32();
        P_std = parser.getU16();
        L = new CarrierPhase().parse(parser);
        cn0 = parser.getU8();
        lock = parser.getU16();
        sid = new GnssSignal().parse(parser);
        doppler = parser.getS32();
        doppler_std = parser.getU16();
        uptime = parser.getU32();
        clock_offset = parser.getS16();
        clock_drift = parser.getS16();
        corr_spacing = parser.getU16();
        acceleration = parser.getS8();
        sync_flags = parser.getU8();
        tow_flags = parser.getU8();
        track_flags = parser.getU8();
        nav_flags = parser.getU8();
        pset_flags = parser.getU8();
        misc_flags = parser.getU8();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU64(recv_time);
        tot.build(builder);
        builder.putU32(P);
        builder.putU16(P_std);
        L.build(builder);
        builder.putU8(cn0);
        builder.putU16(lock);
        sid.build(builder);
        builder.putS32(doppler);
        builder.putU16(doppler_std);
        builder.putU32(uptime);
        builder.putS16(clock_offset);
        builder.putS16(clock_drift);
        builder.putU16(corr_spacing);
        builder.putS8(acceleration);
        builder.putU8(sync_flags);
        builder.putU8(tow_flags);
        builder.putU8(track_flags);
        builder.putU8(nav_flags);
        builder.putU8(pset_flags);
        builder.putU8(misc_flags);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("recv_time", recv_time);
        obj.put("tot", tot.toJSON());
        obj.put("P", P);
        obj.put("P_std", P_std);
        obj.put("L", L.toJSON());
        obj.put("cn0", cn0);
        obj.put("lock", lock);
        obj.put("sid", sid.toJSON());
        obj.put("doppler", doppler);
        obj.put("doppler_std", doppler_std);
        obj.put("uptime", uptime);
        obj.put("clock_offset", clock_offset);
        obj.put("clock_drift", clock_drift);
        obj.put("corr_spacing", corr_spacing);
        obj.put("acceleration", acceleration);
        obj.put("sync_flags", sync_flags);
        obj.put("tow_flags", tow_flags);
        obj.put("track_flags", track_flags);
        obj.put("nav_flags", nav_flags);
        obj.put("pset_flags", pset_flags);
        obj.put("misc_flags", misc_flags);
        return obj;
    }
}