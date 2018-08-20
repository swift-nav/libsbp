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
import com.swiftnav.sbp.SBPStruct;

public class NetworkUsage extends SBPStruct {
    
    /** Duration over which the measurement was collected */
    public BigInteger duration;
    
    /** Number of bytes handled in total within period */
    public BigInteger total_bytes;
    
    /** Number of bytes transmitted within period */
    public long rx_bytes;
    
    /** Number of bytes received within period */
    public long tx_bytes;
    
    /** Interface Name */
    public String interface_name;
    

    public NetworkUsage () {}

    @Override
    public NetworkUsage parse(SBPMessage.Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        duration = parser.getU64();
        total_bytes = parser.getU64();
        rx_bytes = parser.getU32();
        tx_bytes = parser.getU32();
        interface_name = parser.getString(16);
        return this;
    }

    @Override
    public void build(SBPMessage.Builder builder) {
        /* Build fields into binary */
        builder.putU64(duration);
        builder.putU64(total_bytes);
        builder.putU32(rx_bytes);
        builder.putU32(tx_bytes);
        builder.putString(interface_name, 16);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = new JSONObject();
        obj.put("duration", duration);
        obj.put("total_bytes", total_bytes);
        obj.put("rx_bytes", rx_bytes);
        obj.put("tx_bytes", tx_bytes);
        obj.put("interface_name", interface_name);
        return obj;
    }
}