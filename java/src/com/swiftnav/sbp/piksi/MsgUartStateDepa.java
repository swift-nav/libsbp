/* Copyright (C) 2015-2022 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */
package com.swiftnav.sbp.piksi;

// This file was auto-generated from yaml/swiftnav/sbp/piksi.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.gnss.*;
import org.json.JSONObject;

/**
 * SBP class for message MSG_UART_STATE_DEPA (0x0018).
 *
 * <p>You can have MSG_UART_STATE_DEPA inherent its fields directly from an inherited SBP object, or
 * construct it inline using a dict of its fields.
 *
 * <p>Deprecated.
 */
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

    public MsgUartStateDepa(int sender) {
        super(sender, TYPE);
    }

    public MsgUartStateDepa() {
        super(TYPE);
    }

    public MsgUartStateDepa(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        if (msg.type != TYPE)
            throw new SBPBinaryException(
                    "Type mismatch for MsgUartStateDepa, expected 24, actual " + msg.type);
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

    @Override
    public String getFriendlyName() {
        return "UART STATE DEPA";
    }
}
