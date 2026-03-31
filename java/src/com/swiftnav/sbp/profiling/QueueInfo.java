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
package com.swiftnav.sbp.profiling;

// This file was auto-generated from yaml/swiftnav/sbp/profiling.yaml by generate.py.
// Do not modify by hand!


import com.swiftnav.sbp.SBPBinaryException;
import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.SBPStruct;
import java.math.BigInteger;
import org.json.JSONObject;

public class QueueInfo extends SBPStruct {

    /** Timestamp in milliseconds */
    public BigInteger timestamp;

    /** Queue type name */
    public String name;

    /** Total number of slots in the queue */
    public int size;

    /** Number of slots currently in use */
    public int current_fill;

    /** Peak number of slots used since init */
    public int peak_fill;

    /** Number of messages dropped since init */
    public int drop_count;

    public QueueInfo() {}

    @Override
    public QueueInfo parse(SBPMessage.Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        timestamp = parser.getU64();
        name = parser.getString(40);
        size = parser.getU16();
        current_fill = parser.getU16();
        peak_fill = parser.getU16();
        drop_count = parser.getU16();
        return this;
    }

    @Override
    public void build(SBPMessage.Builder builder) {
        /* Build fields into binary */
        builder.putU64(timestamp);
        builder.putString(name, 40);
        builder.putU16(size);
        builder.putU16(current_fill);
        builder.putU16(peak_fill);
        builder.putU16(drop_count);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = new JSONObject();
        obj.put("timestamp", timestamp);
        obj.put("name", name);
        obj.put("size", size);
        obj.put("current_fill", current_fill);
        obj.put("peak_fill", peak_fill);
        obj.put("drop_count", drop_count);
        return obj;
    }
}
