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

package com.swiftnav.sbp.navigation;

import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPStruct;
import java.math.BigInteger;

import org.json.JSONObject;
import org.json.JSONArray;


/** SBP class for message MSG_POS_LLH_DEP_A (0x0201).
 *
 * You can have MSG_POS_LLH_DEP_A inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
 * This position solution message reports the absolute geodetic
 * coordinates and the status (single point vs pseudo-absolute RTK)
 * of the position solution. If the rover receiver knows the
 * surveyed position of the base station and has an RTK solution,
 * this reports a pseudo-absolute position solution using the base
 * station position and the rover's RTK baseline vector. The full
 * GPS time is given by the preceding MSG_GPS_TIME with the
 * matching time-of-week (tow). */

public class MsgPosLLHDepA extends SBPMessage {
    public static final int TYPE = 0x0201;

    
    /** GPS Time of Week */
    public long tow;
    
    /** Latitude */
    public double lat;
    
    /** Longitude */
    public double lon;
    
    /** Height */
    public double height;
    
    /** Horizontal position accuracy estimate (not
implemented). Defaults to 0.
 */
    public int h_accuracy;
    
    /** Vertical position accuracy estimate (not
implemented). Defaults to 0.
 */
    public int v_accuracy;
    
    /** Number of satellites used in solution. */
    public int n_sats;
    
    /** Status flags */
    public int flags;
    

    public MsgPosLLHDepA (int sender) { super(sender, TYPE); }
    public MsgPosLLHDepA () { super(TYPE); }
    public MsgPosLLHDepA (SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type != TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        tow = parser.getU32();
        lat = parser.getDouble();
        lon = parser.getDouble();
        height = parser.getDouble();
        h_accuracy = parser.getU16();
        v_accuracy = parser.getU16();
        n_sats = parser.getU8();
        flags = parser.getU8();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU32(tow);
        builder.putDouble(lat);
        builder.putDouble(lon);
        builder.putDouble(height);
        builder.putU16(h_accuracy);
        builder.putU16(v_accuracy);
        builder.putU8(n_sats);
        builder.putU8(flags);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("tow", tow);
        obj.put("lat", lat);
        obj.put("lon", lon);
        obj.put("height", height);
        obj.put("h_accuracy", h_accuracy);
        obj.put("v_accuracy", v_accuracy);
        obj.put("n_sats", n_sats);
        obj.put("flags", flags);
        return obj;
    }
}