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

package com.swiftnav.sbp.vehicle;

import java.math.BigInteger;

import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPStruct;

import org.json.JSONObject;
import org.json.JSONArray;


/** SBP class for message MSG_WHEELTICK (0x0904).
 *
 * You can have MSG_WHEELTICK inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
 * Message containing the accumulated distance travelled by a wheel located at an odometry
 * reference point defined by the user. The offset for the odometry reference point and the
 * definition and origin of the user frame are defined through the device settings interface.
 * The source of this message is identified by the source field, which is an integer ranging
 * from 0 to 255.
 * The timestamp associated with this message should represent the time when the accumulated
 * tick count reached the value given by the contents of this message as accurately as possible. */

public class MsgWheeltick extends SBPMessage {
    public static final int TYPE = 0x0904;

    
    /** Time field representing either microseconds since the last PPS, microseconds in the GPS
Week or local CPU time from the producing system in microseconds. See the synch_type
field for the exact meaning of this timestamp.
 */
    public BigInteger time;
    
    /** Field indicating the type of timestamp contained in the time field.
 */
    public int flags;
    
    /** ID of the sensor producing this message
 */
    public int source;
    
    /** Free-running counter of the accumulated distance for this sensor. The counter should be
incrementing if travelling into one direction and decrementing when travelling in the
opposite direction.
 */
    public int ticks;
    

    public MsgWheeltick (int sender) { super(sender, TYPE); }
    public MsgWheeltick () { super(TYPE); }
    public MsgWheeltick (SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type != TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        time = parser.getU64();
        flags = parser.getU8();
        source = parser.getU8();
        ticks = parser.getS32();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU64(time);
        builder.putU8(flags);
        builder.putU8(source);
        builder.putS32(ticks);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("time", time);
        obj.put("flags", flags);
        obj.put("source", source);
        obj.put("ticks", ticks);
        return obj;
    }
}