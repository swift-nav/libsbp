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
import com.swiftnav.sbp.SBPStruct;

public class UARTChannel extends SBPStruct {
    
    /** UART transmit throughput */
    public float tx_throughput;
    
    /** UART receive throughput */
    public float rx_throughput;
    
    /** UART CRC error count */
    public int crc_error_count;
    
    /** UART IO error count */
    public int io_error_count;
    
    /** UART transmit buffer percentage utilization (ranges from
0 to 255)
 */
    public int tx_buffer_level;
    
    /** UART receive buffer percentage utilization (ranges from
0 to 255)
 */
    public int rx_buffer_level;
    

    public UARTChannel () {}

    @Override
    public UARTChannel parse(SBPMessage.Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        tx_throughput = parser.getFloat();
        rx_throughput = parser.getFloat();
        crc_error_count = parser.getU16();
        io_error_count = parser.getU16();
        tx_buffer_level = parser.getU8();
        rx_buffer_level = parser.getU8();
        return this;
    }

    @Override
    public void build(SBPMessage.Builder builder) {
        /* Build fields into binary */
        builder.putFloat(tx_throughput);
        builder.putFloat(rx_throughput);
        builder.putU16(crc_error_count);
        builder.putU16(io_error_count);
        builder.putU8(tx_buffer_level);
        builder.putU8(rx_buffer_level);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = new JSONObject();
        obj.put("tx_throughput", tx_throughput);
        obj.put("rx_throughput", rx_throughput);
        obj.put("crc_error_count", crc_error_count);
        obj.put("io_error_count", io_error_count);
        obj.put("tx_buffer_level", tx_buffer_level);
        obj.put("rx_buffer_level", rx_buffer_level);
        return obj;
    }
}