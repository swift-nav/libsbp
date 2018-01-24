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

package com.swiftnav.sbp.piksi;

import java.math.BigInteger;

import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPStruct;
import com.swiftnav.sbp.gnss.*;

import org.json.JSONObject;
import org.json.JSONArray;


/** SBP class for message MSG_SPECAN (0x0051).
 *
 * You can have MSG_SPECAN inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
 * Spectrum analyzer packet. */

public class MsgSpecan extends SBPMessage {
    public static final int TYPE = 0x0051;

    
    /** Channel ID */
    public int channel_tag;
    
    /** Receiver time of this observation */
    public GPSTime t;
    
    /** Reference frequency of this packet
 */
    public float freq_ref;
    
    /** Frequency step of points in this packet
 */
    public float freq_step;
    
    /** Reference amplitude of this packet
 */
    public float amplitude_ref;
    
    /** Amplitude unit value of points in this packet
 */
    public float amplitude_unit;
    
    /** Amplitude values (in the above units) of points in this packet
 */
    public int[] amplitude_value;
    

    public MsgSpecan (int sender) { super(sender, TYPE); }
    public MsgSpecan () { super(TYPE); }
    public MsgSpecan (SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type != TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        channel_tag = parser.getU16();
        t = new GPSTime().parse(parser);
        freq_ref = parser.getFloat();
        freq_step = parser.getFloat();
        amplitude_ref = parser.getFloat();
        amplitude_unit = parser.getFloat();
        amplitude_value = parser.getArrayofU8();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU16(channel_tag);
        t.build(builder);
        builder.putFloat(freq_ref);
        builder.putFloat(freq_step);
        builder.putFloat(amplitude_ref);
        builder.putFloat(amplitude_unit);
        builder.putArrayofU8(amplitude_value);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("channel_tag", channel_tag);
        obj.put("t", t.toJSON());
        obj.put("freq_ref", freq_ref);
        obj.put("freq_step", freq_step);
        obj.put("amplitude_ref", amplitude_ref);
        obj.put("amplitude_unit", amplitude_unit);
        obj.put("amplitude_value", new JSONArray(amplitude_value));
        return obj;
    }
}