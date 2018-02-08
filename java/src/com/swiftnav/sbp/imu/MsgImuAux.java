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

package com.swiftnav.sbp.imu;

import java.math.BigInteger;

import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPStruct;

import org.json.JSONObject;
import org.json.JSONArray;


/** SBP class for message MSG_IMU_AUX (0x0901).
 *
 * You can have MSG_IMU_AUX inherent its fields directly from
 * an inherited SBP object, or construct it inline using a dict of its
 * fields.
 *
 * Auxiliary data specific to a particular IMU. The `imu_type` field will
 * always be consistent but the rest of the payload is device specific and
 * depends on the value of `imu_type`. */

public class MsgImuAux extends SBPMessage {
    public static final int TYPE = 0x0901;

    
    /** IMU type */
    public int imu_type;
    
    /** Raw IMU temperature */
    public int temp;
    
    /** IMU configuration */
    public int imu_conf;
    

    public MsgImuAux (int sender) { super(sender, TYPE); }
    public MsgImuAux () { super(TYPE); }
    public MsgImuAux (SBPMessage msg) throws SBPBinaryException {
        super(msg);
        assert msg.type != TYPE;
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        imu_type = parser.getU8();
        temp = parser.getS16();
        imu_conf = parser.getU8();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU8(imu_type);
        builder.putS16(temp);
        builder.putU8(imu_conf);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("imu_type", imu_type);
        obj.put("temp", temp);
        obj.put("imu_conf", imu_conf);
        return obj;
    }
}