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

package com.swiftnav.sbp.observation;

import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPStruct;
import com.swiftnav.sbp.gnss_signal.*;

import org.json.JSONObject;
import org.json.JSONArray;
import com.swiftnav.sbp.SBPStruct;

public class PackedObsContent extends SBPStruct {
    
    /** Pseudorange observation */
    public long P;
    
    /** Phase Range minus pseudorange. Phaserange can be reconstructed
by adding pseudorange to this value. This follows the convention
from DF0012 or the DF042 field from the RTCM 10403.2 Ammendment 2
specification.  Importantly, this assumes the phaserange has the 
same sign as the pseudorange.
 */
    public int L;
    
    /** Carrier-to-Noise density */
    public int cn0;
    
    /** Lock indicator. This value gives an indication of the time
for which a satellite has maintained continuous phase lock.
Whenever a satellite signal has lost and regained lock, this 
value is reset to zero. It is encoded according to DF402 from
the RTCM 10403.2 Amendment 2 specification.  Given a lock time (t)
in milliseconds, the field value (n) is given by floor(log_2(t) - 4) 
when t is greater than 32 ms or 0 if (t) is less than 32 ms. 
Conversely, given the field, n,  the lower range of possible  lock times
is given by 2 ^ (n + 4) ms and the upper range is given by 2 ^ (n + 5) ms
provided n is not 0.  If n is 0 the lower range is given to be 0 ms.
 */
    public int lock;
    
    /** GNSS signal identifier */
    public GnssSignal sid;
    

    public PackedObsContent () {}

    @Override
    public PackedObsContent parse(SBPMessage.Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        P = parser.getU32();
        L = parser.getS32();
        cn0 = parser.getU8();
        lock = parser.getU8();
        sid = new GnssSignal().parse(parser);
        return this;
    }

    @Override
    public void build(SBPMessage.Builder builder) {
        /* Build fields into binary */
        builder.putU32(P);
        builder.putS32(L);
        builder.putU8(cn0);
        builder.putU8(lock);
        sid.build(builder);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = new JSONObject();
        obj.put("P", P);
        obj.put("L", L);
        obj.put("cn0", cn0);
        obj.put("lock", lock);
        obj.put("sid", sid.toJSON());
        return obj;
    }
}