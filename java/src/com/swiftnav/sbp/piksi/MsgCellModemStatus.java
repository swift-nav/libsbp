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


/** SBP class for message MSG_CELL_MODEM_STATUS (0x00BE).
 *
 * You can have MSG_CELL_MODEM_STATUS inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
 * If a cell modem is present on a piksi device, this message
 * will be send periodically to update the host on the status
 * of the modem and its various parameters. */

public class MsgCellModemStatus extends SBPMessage {
    public static final int TYPE = 0x00BE;

    
    /** Received cell signal strength in dBm, zero translates to unknown */
    public int signal_strength;
    
    /** BER as reported by the modem, zero translates to unknown */
    public float signal_error_rate;
    
    /** Unspecified data TBD for this schema */
    public int[] reserved;
    

    public MsgCellModemStatus (int sender) { super(sender, TYPE); }
    public MsgCellModemStatus () { super(TYPE); }
    public MsgCellModemStatus (SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type != TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        signal_strength = parser.getS8();
        signal_error_rate = parser.getFloat();
        reserved = parser.getArrayofU8();
    }

    @Override
    protected void build(Builder builder) {
        builder.putS8(signal_strength);
        builder.putFloat(signal_error_rate);
        builder.putArrayofU8(reserved);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("signal_strength", signal_strength);
        obj.put("signal_error_rate", signal_error_rate);
        obj.put("reserved", new JSONArray(reserved));
        return obj;
    }
}