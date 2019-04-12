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
import com.swiftnav.sbp.SBPStruct;

public class PackedOsrContent extends SBPStruct {
    
    /** Pseudorange observation */
    public long P;
    
    /** Carrier phase observation with typical sign convention. */
    public CarrierPhase L;
    
    /** Lock timer. This value gives an indication of the time
for which a signal has maintained continuous phase lock.
Whenever a signal has lost and regained lock, this
value is reset to zero. It is encoded according to DF402 from
the RTCM 10403.2 Amendment 2 specification.  Valid values range
from 0 to 15 and the most significant nibble is reserved for future use.
 */
    public int lock;
    
    /** Correction flags.
 */
    public int flags;
    
    /** GNSS signal identifier (16 bit) */
    public GnssSignal sid;
    
    /** Slant ionospheric correction standard deviation */
    public int iono_std;
    
    /** Slant tropospheric correction standard deviation */
    public int tropo_std;
    
    /** Orbit/clock/bias correction projected on range standard deviation */
    public int range_std;
    

    public PackedOsrContent () {}

    @Override
    public PackedOsrContent parse(SBPMessage.Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        P = parser.getU32();
        L = new CarrierPhase().parse(parser);
        lock = parser.getU8();
        flags = parser.getU8();
        sid = new GnssSignal().parse(parser);
        iono_std = parser.getU16();
        tropo_std = parser.getU16();
        range_std = parser.getU16();
        return this;
    }

    @Override
    public void build(SBPMessage.Builder builder) {
        /* Build fields into binary */
        builder.putU32(P);
        L.build(builder);
        builder.putU8(lock);
        builder.putU8(flags);
        sid.build(builder);
        builder.putU16(iono_std);
        builder.putU16(tropo_std);
        builder.putU16(range_std);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = new JSONObject();
        obj.put("P", P);
        obj.put("L", L.toJSON());
        obj.put("lock", lock);
        obj.put("flags", flags);
        obj.put("sid", sid.toJSON());
        obj.put("iono_std", iono_std);
        obj.put("tropo_std", tropo_std);
        obj.put("range_std", range_std);
        return obj;
    }
}