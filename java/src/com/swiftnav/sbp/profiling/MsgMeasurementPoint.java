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
package com.swiftnav.sbp.profiling;

// This file was auto-generated from yaml/swiftnav/sbp/profiling.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import java.math.BigInteger;
import org.json.JSONObject;

/**
 * SBP class for message MSG_MEASUREMENT_POINT (0xCF00).
 *
 * <p>You can have MSG_MEASUREMENT_POINT inherent its fields directly from an inherited SBP object,
 * or construct it inline using a dict of its fields.
 *
 * <p>Tracks execution time of certain code paths in specially built products. This message should
 * only be expected and processed on the direction of Swift's engineering teams.
 */
public class MsgMeasurementPoint extends SBPMessage {
    public static final int TYPE = 0xCF00;

    /** Total time spent in measurement point */
    public long total_time;

    /** Number of times measurement point has executed */
    public int num_executions;

    /** Minimum execution time */
    public long min;

    /** Maximum execution time */
    public long max;

    /** Return address */
    public BigInteger return_addr;

    /** Unique ID */
    public BigInteger id;

    /** CPU slice time */
    public BigInteger slice_time;

    /** Line number */
    public int line;

    /** Function name */
    public String func;

    public MsgMeasurementPoint(int sender) {
        super(sender, TYPE);
    }

    public MsgMeasurementPoint() {
        super(TYPE);
    }

    public MsgMeasurementPoint(SBPMessage msg) throws SBPBinaryException {
        super(msg);
        if (msg.type != TYPE)
            throw new SBPBinaryException(
                    "Type mismatch for MsgMeasurementPoint, expected 52992, actual " + msg.type);
    }

    @Override
    protected void parse(Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        total_time = parser.getU32();
        num_executions = parser.getU16();
        min = parser.getU32();
        max = parser.getU32();
        return_addr = parser.getU64();
        id = parser.getU64();
        slice_time = parser.getU64();
        line = parser.getU16();
        func = parser.getString();
    }

    @Override
    protected void build(Builder builder) {
        builder.putU32(total_time);
        builder.putU16(num_executions);
        builder.putU32(min);
        builder.putU32(max);
        builder.putU64(return_addr);
        builder.putU64(id);
        builder.putU64(slice_time);
        builder.putU16(line);
        builder.putString(func);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = super.toJSON();
        obj.put("total_time", total_time);
        obj.put("num_executions", num_executions);
        obj.put("min", min);
        obj.put("max", max);
        obj.put("return_addr", return_addr);
        obj.put("id", id);
        obj.put("slice_time", slice_time);
        obj.put("line", line);
        obj.put("func", func);
        return obj;
    }

    @Override
    public String getFriendlyName() {
        return "MEAS POINT";
    }
}
