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
package com.swiftnav.sbp.observation;


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.gnss.*;
import org.json.JSONObject;

public class SbpMsgGnssCapb extends SBPMessage {
    public static final int TYPE = 0x0096;

    /** Navigation Message Correction Table Validity Time */
    public GPSTimeSec t_nmct;

    /** GNSS capabilities masks */
    public GnssCapb gc;

    public SbpMsgGnssCapb(int sender) {
        super(sender, TYPE);
    }

    public SbpMsgGnssCapb() {
        super(TYPE);
    }

    public SbpMsgGnssCapb(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type != TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        t_nmct = new GPSTimeSec().parse(parser);
        gc = new GnssCapb().parse(parser);
    }

    @Override
    protected void build(Builder builder) {
        t_nmct.build(builder);
        gc.build(builder);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("t_nmct", t_nmct.toJSON());
        obj.put("gc", gc.toJSON());
        return obj;
    }
}
