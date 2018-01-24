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

package com.swiftnav.sbp.mag;

import java.math.BigInteger;

import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPStruct;

import org.json.JSONObject;
import org.json.JSONArray;


/** SBP class for message MSG_MAG_RAW (0x0902).
 *
 * You can have MSG_MAG_RAW inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
 * Raw data from the magnetometer. */

public class MsgMagRaw extends SBPMessage {
    public static final int TYPE = 0x0902;

    
    /** Milliseconds since start of GPS week. If the high bit is set, the
time is unknown or invalid.
 */
    public long tow;
    
    /** Milliseconds since start of GPS week, fractional part
 */
    public int tow_f;
    
    /** Magnetic field in the body frame X axis */
    public int mag_x;
    
    /** Magnetic field in the body frame Y axis */
    public int mag_y;
    
    /** Magnetic field in the body frame Z axis */
    public int mag_z;
    

    public MsgMagRaw (int sender) { super(sender, TYPE); }
    public MsgMagRaw () { super(TYPE); }
    public MsgMagRaw (SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type != TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        tow = parser.getU32();
        tow_f = parser.getU8();
        mag_x = parser.getS16();
        mag_y = parser.getS16();
        mag_z = parser.getS16();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU32(tow);
        builder.putU8(tow_f);
        builder.putS16(mag_x);
        builder.putS16(mag_y);
        builder.putS16(mag_z);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("tow", tow);
        obj.put("tow_f", tow_f);
        obj.put("mag_x", mag_x);
        obj.put("mag_y", mag_y);
        obj.put("mag_z", mag_z);
        return obj;
    }
}