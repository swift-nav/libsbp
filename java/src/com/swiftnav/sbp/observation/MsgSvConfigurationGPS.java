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

package com.swiftnav.sbp.observation;

import java.math.BigInteger;

import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPStruct;
import com.swiftnav.sbp.gnss.*;

import org.json.JSONObject;
import org.json.JSONArray;


/** SBP class for message MSG_SV_CONFIGURATION_GPS (0x0091).
 *
 * You can have MSG_SV_CONFIGURATION_GPS inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
 * Please see ICD-GPS-200 (Chapter 20.3.3.5.1.4) for more details. */

public class MsgSvConfigurationGPS extends SBPMessage {
    public static final int TYPE = 0x0091;

    
    /** Navigation Message Correction Table Valitidy Time */
    public GPSTimeSec t_nmct;
    
    /** L2C capability mask, SV32 bit being MSB, SV1 bit being LSB */
    public long l2c_mask;
    

    public MsgSvConfigurationGPS (int sender) { super(sender, TYPE); }
    public MsgSvConfigurationGPS () { super(TYPE); }
    public MsgSvConfigurationGPS (SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type != TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        t_nmct = new GPSTimeSec().parse(parser);
        l2c_mask = parser.getU32();
    }

    @Override
    protected void build(Builder builder) {
        t_nmct.build(builder);
        builder.putU32(l2c_mask);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("t_nmct", t_nmct.toJSON());
        obj.put("l2c_mask", l2c_mask);
        return obj;
    }
}