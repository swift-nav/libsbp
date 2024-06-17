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
import com.swiftnav.sbp.SBPStruct;
import org.json.JSONObject;

public class ResourceBucket extends SBPStruct {

    /** Bucket name */
    public String name;

    /** Number of threads */
    public int thread;

    /** Number of mutexes */
    public int mutex;

    /** Number of condition variables */
    public int cv;

    /** Number of IO handles */
    public int io;

    /** Number of bytes allocated on the heap */
    public long heap_bytes_alloc;

    /** Number of bytes freed on the heap */
    public long heap_bytes_free;

    /** Number of bytes written to IO handles */
    public long io_write;

    /** Number of bytes read from IO handles */
    public long io_read;

    public ResourceBucket() {}

    @Override
    public ResourceBucket parse(SBPMessage.Parser parser) throws SBPBinaryException {
        /* Parse fields from binary */
        name = parser.getString(21);
        thread = parser.getU8();
        mutex = parser.getU8();
        cv = parser.getU8();
        io = parser.getU8();
        heap_bytes_alloc = parser.getU32();
        heap_bytes_free = parser.getU32();
        io_write = parser.getU32();
        io_read = parser.getU32();
        return this;
    }

    @Override
    public void build(SBPMessage.Builder builder) {
        /* Build fields into binary */
        builder.putString(name, 21);
        builder.putU8(thread);
        builder.putU8(mutex);
        builder.putU8(cv);
        builder.putU8(io);
        builder.putU32(heap_bytes_alloc);
        builder.putU32(heap_bytes_free);
        builder.putU32(io_write);
        builder.putU32(io_read);
    }

    @Override
    public JSONObject toJSON() {
        JSONObject obj = new JSONObject();
        obj.put("name", name);
        obj.put("thread", thread);
        obj.put("mutex", mutex);
        obj.put("cv", cv);
        obj.put("io", io);
        obj.put("heap_bytes_alloc", heap_bytes_alloc);
        obj.put("heap_bytes_free", heap_bytes_free);
        obj.put("io_write", io_write);
        obj.put("io_read", io_read);
        return obj;
    }
}
