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


/** SBP class for message MSG_UART_STATE_DEPA (0x0018).
 *
 * You can have MSG_UART_STATE_DEPA inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
* Deprecated */

public class MsgUartStateDepa extends SBPMessage {
    public static final int TYPE = 0x0018;

    
    /** State of UART A */
    public UARTChannel uart_a;
    
    /** State of UART B */
    public UARTChannel uart_b;
    
    /** State of UART FTDI (USB logger) */
    public UARTChannel uart_ftdi;
    
    /** UART communication latency */
    public Latency latency;
    

    public MsgUartStateDepa (int sender) { super(sender, TYPE); }
    public MsgUartStateDepa () { super(TYPE); }
    public MsgUartStateDepa (SBPMessage msg) throws SBPBinaryException {
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
    }

    @Override
    protected void build(Builder builder) {
        uart_a.build(builder);
        uart_b.build(builder);
        uart_ftdi.build(builder);
        latency.build(builder);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("uart_a", uart_a.toJSON());
        obj.put("uart_b", uart_b.toJSON());
        obj.put("uart_ftdi", uart_ftdi.toJSON());
        obj.put("latency", latency.toJSON());
        return obj;
    }
}