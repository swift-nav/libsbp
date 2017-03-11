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
import com.swiftnav.sbp.gnss.*;

import org.json.JSONObject;
import org.json.JSONArray;


/** SBP class for message MSG_NETWORK_STATE_RESP (0x00BB).
 *
 * You can have MSG_NETWORK_STATE_RESP inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
 * The state of a network interface on the Piksi */

public class MsgNetworkStateResp extends SBPMessage {
    public static final int TYPE = 0x00BB;

    
    /** IPv4 address */
    public long ip_address;
    
    /** IPv4 netmask */
    public long ip_mask;
    
    /** Number of Rx bytes */
    public long rx_bytes;
    
    /** Number of Tx bytes */
    public long tx_bytes;
    
    /** Interface Name */
    public String interface_name;
    
    /** Interface flags from SIOCGIFFLAGS */
    public long flags;
    

    public MsgNetworkStateResp (int sender) { super(sender, TYPE); }
    public MsgNetworkStateResp () { super(TYPE); }
    public MsgNetworkStateResp (SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type != TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        ip_address = parser.getU32();
        ip_mask = parser.getU32();
        rx_bytes = parser.getU32();
        tx_bytes = parser.getU32();
        interface_name = parser.getString(16);
        flags = parser.getU32();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU32(ip_address);
        builder.putU32(ip_mask);
        builder.putU32(rx_bytes);
        builder.putU32(tx_bytes);
        builder.putString(interface_name, 16);
        builder.putU32(flags);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("ip_address", ip_address);
        obj.put("ip_mask", ip_mask);
        obj.put("rx_bytes", rx_bytes);
        obj.put("tx_bytes", tx_bytes);
        obj.put("interface_name", interface_name);
        obj.put("flags", flags);
        return obj;
    }
}