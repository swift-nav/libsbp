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

public class PackedObsContent extends SBPStruct {
    
    /** Pseudorange observation */
    public long P;
    
    /** Carrier phase observation with typical sign convention. */
    public CarrierPhase L;
    
    /** Doppler observation with typical sign convention. */
    public Doppler D;
    
    /** Carrier-to-Noise density.  Zero implies invalid cn0. */
    public int cn0;
    
    /** Lock timer. This value gives an indication of the time
for which a signal has maintained continuous phase lock.
Whenever a signal has lost and regained lock, this
value is reset to zero. It is encoded according to DF402 from
the RTCM 10403.2 Amendment 2 specification.  Valid values range
from 0 to 15 and the most significant nibble is reserved for future use.
 */
    public int lock;
    
    /** Measurement status flags. A bit field of flags providing the
status of this observation.  If this field is 0 it means only the Cn0
estimate for the signal is valid.
 */
    public int flags;
    
    /** GNSS signal identifier (16 bit) */
    public GnssSignal sid;
    

    public PackedObsContent () {}

    @Override
    public PackedObsContent parse(SBPMessage.Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        P = parser.getU32();
        L = new CarrierPhase().parse(parser);
        D = new Doppler().parse(parser);
        cn0 = parser.getU8();
        lock = parser.getU8();
        flags = parser.getU8();
        sid = new GnssSignal().parse(parser);
        return this;
    }

    @Override
    public void build(SBPMessage.Builder builder) {
        /* Build fields into binary */
        builder.putU32(P);
        L.build(builder);
        D.build(builder);
        builder.putU8(cn0);
        builder.putU8(lock);
        builder.putU8(flags);
        sid.build(builder);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = new JSONObject();
        obj.put("P", P);
        obj.put("L", L.toJSON());
        obj.put("D", D.toJSON());
        obj.put("cn0", cn0);
        obj.put("lock", lock);
        obj.put("flags", flags);
        obj.put("sid", sid.toJSON());
        return obj;
    }
}