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

package com.swiftnav.sbp.acquisition;

import java.math.BigInteger;

import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPStruct;
import com.swiftnav.sbp.gnss.*;

import org.json.JSONObject;
import org.json.JSONArray;
import com.swiftnav.sbp.SBPStruct;

public class AcqSvProfileDep extends SBPStruct {
    
    /** SV search job type (deep, fallback, etc) */
    public int job_type;
    
    /** Acquisition status 1 is Success, 0 is Failure */
    public int status;
    
    /** CN0 value. Only valid if status is '1' */
    public int cn0;
    
    /** Acquisition integration time */
    public int int_time;
    
    /** GNSS signal for which acquisition was attempted */
    public GnssSignalDep sid;
    
    /** Acq frequency bin width */
    public int bin_width;
    
    /** Timestamp of the job complete event */
    public long timestamp;
    
    /** Time spent to search for sid.code */
    public long time_spent;
    
    /** Doppler range lowest frequency */
    public int cf_min;
    
    /** Doppler range highest frequency */
    public int cf_max;
    
    /** Doppler value of detected peak. Only valid if status is '1' */
    public int cf;
    
    /** Codephase of detected peak. Only valid if status is '1' */
    public long cp;
    

    public AcqSvProfileDep () {}

    @Override
    public AcqSvProfileDep parse(SBPMessage.Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        job_type = parser.getU8();
        status = parser.getU8();
        cn0 = parser.getU16();
        int_time = parser.getU8();
        sid = new GnssSignalDep().parse(parser);
        bin_width = parser.getU16();
        timestamp = parser.getU32();
        time_spent = parser.getU32();
        cf_min = parser.getS32();
        cf_max = parser.getS32();
        cf = parser.getS32();
        cp = parser.getU32();
        return this;
    }

    @Override
    public void build(SBPMessage.Builder builder) {
        /* Build fields into binary */
        builder.putU8(job_type);
        builder.putU8(status);
        builder.putU16(cn0);
        builder.putU8(int_time);
        sid.build(builder);
        builder.putU16(bin_width);
        builder.putU32(timestamp);
        builder.putU32(time_spent);
        builder.putS32(cf_min);
        builder.putS32(cf_max);
        builder.putS32(cf);
        builder.putU32(cp);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = new JSONObject();
        obj.put("job_type", job_type);
        obj.put("status", status);
        obj.put("cn0", cn0);
        obj.put("int_time", int_time);
        obj.put("sid", sid.toJSON());
        obj.put("bin_width", bin_width);
        obj.put("timestamp", timestamp);
        obj.put("time_spent", time_spent);
        obj.put("cf_min", cf_min);
        obj.put("cf_max", cf_max);
        obj.put("cf", cf);
        obj.put("cp", cp);
        return obj;
    }
}