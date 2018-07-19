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

public class GnssCapb extends SBPStruct {
    
    /** GPS SV active mask */
    public BigInteger gps_active;
    
    /** GPS L2C active mask */
    public BigInteger gps_l2c;
    
    /** GPS L5 active mask */
    public BigInteger gps_l5;
    
    /** GLO active mask */
    public long glo_active;
    
    /** GLO L2OF active mask */
    public long glo_l2of;
    
    /** GLO L3 active mask */
    public long glo_l3;
    
    /** SBAS active mask (PRNs 120..158, AN 7/62.2.2-18/18 Table B-23,
https://www.caat.or.th/wp-content/uploads/2018/03/SL-2018.18.E-1.pdf)
 */
    public BigInteger sbas_active;
    
    /** SBAS L5 active mask (PRNs 120..158, AN 7/62.2.2-18/18 Table B-23,
https://www.caat.or.th/wp-content/uploads/2018/03/SL-2018.18.E-1.pdf)
 */
    public BigInteger sbas_l5;
    
    /** BDS active mask */
    public BigInteger bds_active;
    
    /** BDS D2NAV active mask */
    public BigInteger bds_d2nav;
    
    /** BDS B2 active mask */
    public BigInteger bds_b2;
    
    /** BDS B2A active mask */
    public BigInteger bds_b2a;
    
    /** QZSS active mask */
    public long qzss_active;
    
    /** GAL active mask */
    public BigInteger gal_active;
    
    /** GAL E5 active mask */
    public BigInteger gal_e5;
    

    public GnssCapb () {}

    @Override
    public GnssCapb parse(SBPMessage.Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        gps_active = parser.getU64();
        gps_l2c = parser.getU64();
        gps_l5 = parser.getU64();
        glo_active = parser.getU32();
        glo_l2of = parser.getU32();
        glo_l3 = parser.getU32();
        sbas_active = parser.getU64();
        sbas_l5 = parser.getU64();
        bds_active = parser.getU64();
        bds_d2nav = parser.getU64();
        bds_b2 = parser.getU64();
        bds_b2a = parser.getU64();
        qzss_active = parser.getU32();
        gal_active = parser.getU64();
        gal_e5 = parser.getU64();
        return this;
    }

    @Override
    public void build(SBPMessage.Builder builder) {
        /* Build fields into binary */
        builder.putU64(gps_active);
        builder.putU64(gps_l2c);
        builder.putU64(gps_l5);
        builder.putU32(glo_active);
        builder.putU32(glo_l2of);
        builder.putU32(glo_l3);
        builder.putU64(sbas_active);
        builder.putU64(sbas_l5);
        builder.putU64(bds_active);
        builder.putU64(bds_d2nav);
        builder.putU64(bds_b2);
        builder.putU64(bds_b2a);
        builder.putU32(qzss_active);
        builder.putU64(gal_active);
        builder.putU64(gal_e5);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = new JSONObject();
        obj.put("gps_active", gps_active);
        obj.put("gps_l2c", gps_l2c);
        obj.put("gps_l5", gps_l5);
        obj.put("glo_active", glo_active);
        obj.put("glo_l2of", glo_l2of);
        obj.put("glo_l3", glo_l3);
        obj.put("sbas_active", sbas_active);
        obj.put("sbas_l5", sbas_l5);
        obj.put("bds_active", bds_active);
        obj.put("bds_d2nav", bds_d2nav);
        obj.put("bds_b2", bds_b2);
        obj.put("bds_b2a", bds_b2a);
        obj.put("qzss_active", qzss_active);
        obj.put("gal_active", gal_active);
        obj.put("gal_e5", gal_e5);
        return obj;
    }
}