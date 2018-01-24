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


/** SBP class for message MSG_DEVICE_MONITOR (0x00B5).
 *
 * You can have MSG_DEVICE_MONITOR inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
 * This message contains temperature and voltage level measurements from the
 * processor's monitoring system and the RF frontend die temperature if
 * available. */

public class MsgDeviceMonitor extends SBPMessage {
    public static final int TYPE = 0x00B5;

    
    /** Device V_in */
    public int dev_vin;
    
    /** Processor V_int */
    public int cpu_vint;
    
    /** Processor V_aux */
    public int cpu_vaux;
    
    /** Processor temperature */
    public int cpu_temperature;
    
    /** Frontend temperature (if available) */
    public int fe_temperature;
    

    public MsgDeviceMonitor (int sender) { super(sender, TYPE); }
    public MsgDeviceMonitor () { super(TYPE); }
    public MsgDeviceMonitor (SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type != TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        dev_vin = parser.getS16();
        cpu_vint = parser.getS16();
        cpu_vaux = parser.getS16();
        cpu_temperature = parser.getS16();
        fe_temperature = parser.getS16();
    }

    @Override
    protected void build(Builder builder) {
        builder.putS16(dev_vin);
        builder.putS16(cpu_vint);
        builder.putS16(cpu_vaux);
        builder.putS16(cpu_temperature);
        builder.putS16(fe_temperature);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("dev_vin", dev_vin);
        obj.put("cpu_vint", cpu_vint);
        obj.put("cpu_vaux", cpu_vaux);
        obj.put("cpu_temperature", cpu_temperature);
        obj.put("fe_temperature", fe_temperature);
        return obj;
    }
}