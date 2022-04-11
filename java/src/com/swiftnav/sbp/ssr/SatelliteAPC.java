/* Copyright (C) 2015-2022 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */
package com.swiftnav.sbp.ssr;

// This file was auto-generated from yaml/swiftnav/sbp/ssr.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPStruct;
import com.swiftnav.sbp.gnss.*;
import org.json.JSONArray;
import org.json.JSONObject;

public class SatelliteAPC extends SBPStruct {

    /** GNSS signal identifier (16 bit) */
    public GnssSignal sid;

    /** Additional satellite information */
    public int sat_info;

    /** Satellite Code, as defined by IGS. Typically the space vehicle number. */
    public int svn;

    /**
     * Mean phase center offset, X Y and Z axes. See IGS ANTEX file format description for
     * coordinate system definition.
     */
    public int[] pco;

    /**
     * Elevation dependent phase center variations. First element is 0 degrees separation from the Z
     * axis, subsequent elements represent elevation variations in 1 degree increments.
     */
    public int[] pcv;

    public SatelliteAPC() {}

    @Override
    public SatelliteAPC parse(SBPMessage.Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        sid = new GnssSignal().parse(parser);
        sat_info = parser.getU8();
        svn = parser.getU16();
        pco = parser.getArrayofS16(3);
        pcv = parser.getArrayofS8(21);
        return this;
    }

    @Override
    public void build(SBPMessage.Builder builder) {
        /* Build fields into binary */
        sid.build(builder);
        builder.putU8(sat_info);
        builder.putU16(svn);
        builder.putArrayofS16(pco, 3);
        builder.putArrayofS8(pcv, 21);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = new JSONObject();
        obj.put("sid", sid.toJSON());
        obj.put("sat_info", sat_info);
        obj.put("svn", svn);
        obj.put("pco", new JSONArray(pco));
        obj.put("pcv", new JSONArray(pcv));
        return obj;
    }
}
