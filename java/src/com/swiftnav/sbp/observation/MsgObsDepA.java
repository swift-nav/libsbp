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


/** SBP class for message MSG_OBS_DEP_A (0x0045).
 *
 * You can have MSG_OBS_DEP_A inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
* Deprecated. */

public class MsgObsDepA extends SBPMessage {
    public static final int TYPE = 0x0045;

    
    /** Header of a GPS observation message */
    public ObservationHeader header;
    
    /** Pseudorange and carrier phase observation for a
satellite being tracked.
 */
    public PackedObsContentDepA[] obs;
    

    public MsgObsDepA (int sender) { super(sender, TYPE); }
    public MsgObsDepA () { super(TYPE); }
    public MsgObsDepA (SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type != TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        header = new ObservationHeader().parse(parser);
        obs = parser.getArray(PackedObsContentDepA.class);
    }

    @Override
    protected void build(Builder builder) {
        header.build(builder);
        builder.putArray(obs);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("header", header.toJSON());
        obj.put("obs", SBPStruct.toJSONArray(obs));
        return obj;
    }
}