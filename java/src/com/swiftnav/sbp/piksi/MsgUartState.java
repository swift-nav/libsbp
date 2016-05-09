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

package com.swiftnav.sbp.piksi;

import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPStruct;
import com.swiftnav.sbp.gnss_signal.*;

import org.json.JSONObject;
import org.json.JSONArray;


/** SBP class for message MSG_UART_STATE (0x001D).
 *
 * You can have MSG_UART_STATE inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
 * The UART message reports data latency and throughput of the UART
 * channels providing SBP I/O. On the default Piksi configuration,
 * UARTs A and B are used for telemetry radios, but can also be
 * host access ports for embedded hosts, or other interfaces in
 * future. The reported percentage values must be normalized.
 * Observations latency and period can be used to assess the 
 * health of the differential corrections link. Latency provides
 * the timeliness of received base observations while the 
 * period indicates their likelihood of transmission. */

public class MsgUartState extends SBPMessage {
    public static final int TYPE = 0x001D;

    
    /** State of UART A */
    public UARTChannel uart_a;
    
    /** State of UART B */
    public UARTChannel uart_b;
    
    /** State of UART FTDI (USB logger) */
    public UARTChannel uart_ftdi;
    
    /** UART communication latency */
    public Latency latency;
    
    /** Observation receipt period */
    public Period obs_period;
    

    public MsgUartState (int sender) { super(sender, TYPE); }
    public MsgUartState () { super(TYPE); }
    public MsgUartState (SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type != TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        uart_a = new UARTChannel().parse(parser);
        uart_b = new UARTChannel().parse(parser);
        uart_ftdi = new UARTChannel().parse(parser);
        latency = new Latency().parse(parser);
        obs_period = new Period().parse(parser);
    }

    @Override
    protected void build(Builder builder) {
        uart_a.build(builder);
        uart_b.build(builder);
        uart_ftdi.build(builder);
        latency.build(builder);
        obs_period.build(builder);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("uart_a", uart_a.toJSON());
        obj.put("uart_b", uart_b.toJSON());
        obj.put("uart_ftdi", uart_ftdi.toJSON());
        obj.put("latency", latency.toJSON());
        obj.put("obs_period", obs_period.toJSON());
        return obj;
    }
}