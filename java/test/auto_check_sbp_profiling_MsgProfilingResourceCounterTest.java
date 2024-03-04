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
package com.swiftnav.sbp.test;

// This file was auto-generated from
// spec/tests/yaml/swiftnav/sbp/profiling/test_MsgProfilingResourceCounter.yaml by generate.py. Do
// not modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.profiling.MsgProfilingResourceCounter;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_profiling_MsgProfilingResourceCounterTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format(
                    "%n%s%n", "auto_check_sbp_profiling_MsgProfilingResourceCounterTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 1,
                    (byte) 3,
                    (byte) 70,
                    (byte) 117,
                    (byte) 115,
                    (byte) 105,
                    (byte) 111,
                    (byte) 110,
                    (byte) 32,
                    (byte) 101,
                    (byte) 110,
                    (byte) 103,
                    (byte) 105,
                    (byte) 110,
                    (byte) 101,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 1,
                    (byte) 2,
                    (byte) 2,
                    (byte) 0,
                    (byte) 248,
                    (byte) 38,
                    (byte) 14,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 78,
                    (byte) 84,
                    (byte) 82,
                    (byte) 73,
                    (byte) 80,
                    (byte) 32,
                    (byte) 99,
                    (byte) 108,
                    (byte) 105,
                    (byte) 101,
                    (byte) 110,
                    (byte) 116,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 1,
                    (byte) 1,
                    (byte) 1,
                    (byte) 1,
                    (byte) 230,
                    (byte) 73,
                    (byte) 1,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 111,
                    (byte) 3,
                    (byte) 0,
                    (byte) 0,
                    (byte) 64,
                    (byte) 76,
                    (byte) 0,
                    (byte) 0,
                    (byte) 83,
                    (byte) 83,
                    (byte) 82,
                    (byte) 50,
                    (byte) 79,
                    (byte) 83,
                    (byte) 82,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 1,
                    (byte) 1,
                    (byte) 1,
                    (byte) 0,
                    (byte) 72,
                    (byte) 13,
                    (byte) 66,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 80,
                    (byte) 101,
                    (byte) 114,
                    (byte) 105,
                    (byte) 111,
                    (byte) 100,
                    (byte) 105,
                    (byte) 99,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 1,
                    (byte) 2,
                    (byte) 1,
                    (byte) 0,
                    (byte) 72,
                    (byte) 197,
                    (byte) 3,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 73,
                    (byte) 77,
                    (byte) 85,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 1,
                    (byte) 1,
                    (byte) 1,
                    (byte) 1,
                    (byte) 129,
                    (byte) 71,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 95,
                    (byte) 102,
                    (byte) 0,
                    (byte) 0,
                    (byte) 115,
                    (byte) 98,
                    (byte) 112,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 5,
                    (byte) 2,
                    (byte) 2,
                    (byte) 2,
                    (byte) 243,
                    (byte) 169,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 187,
                    (byte) 151,
                    (byte) 3,
                    (byte) 0,
                    (byte) 242,
                    (byte) 1,
                    (byte) 0,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x1000, 0xcf03, payload);
        MsgProfilingResourceCounter msg = new MsgProfilingResourceCounter(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.buckets[0].cv;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.buckets[0].cv + "' != '" + 2 + "'",
                    value.equals(BigInteger.valueOf(2L)));
        } else {
            value = value.longValue();
            expected = 2L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.buckets[0].heap_bytes_alloc;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.buckets[0].heap_bytes_alloc + "' != '" + 927480 + "'",
                    value.equals(BigInteger.valueOf(927480L)));
        } else {
            value = value.longValue();
            expected = 927480L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.buckets[0].heap_bytes_free;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.buckets[0].heap_bytes_free + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.buckets[0].io;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.buckets[0].io + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.buckets[0].io_read;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.buckets[0].io_read + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.buckets[0].io_write;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.buckets[0].io_write + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.buckets[0].mutex;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.buckets[0].mutex + "' != '" + 2 + "'",
                    value.equals(BigInteger.valueOf(2L)));
        } else {
            value = value.longValue();
            expected = 2L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.buckets[0].name, "Fusion engine        ");
        value = msg.buckets[0].thread;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.buckets[0].thread + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.buckets[1].cv;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.buckets[1].cv + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.buckets[1].heap_bytes_alloc;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.buckets[1].heap_bytes_alloc + "' != '" + 84454 + "'",
                    value.equals(BigInteger.valueOf(84454L)));
        } else {
            value = value.longValue();
            expected = 84454L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.buckets[1].heap_bytes_free;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.buckets[1].heap_bytes_free + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.buckets[1].io;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.buckets[1].io + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.buckets[1].io_read;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.buckets[1].io_read + "' != '" + 19520 + "'",
                    value.equals(BigInteger.valueOf(19520L)));
        } else {
            value = value.longValue();
            expected = 19520L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.buckets[1].io_write;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.buckets[1].io_write + "' != '" + 879 + "'",
                    value.equals(BigInteger.valueOf(879L)));
        } else {
            value = value.longValue();
            expected = 879L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.buckets[1].mutex;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.buckets[1].mutex + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.buckets[1].name, "NTRIP client         ");
        value = msg.buckets[1].thread;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.buckets[1].thread + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.buckets[2].cv;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.buckets[2].cv + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.buckets[2].heap_bytes_alloc;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.buckets[2].heap_bytes_alloc + "' != '" + 4328776 + "'",
                    value.equals(BigInteger.valueOf(4328776L)));
        } else {
            value = value.longValue();
            expected = 4328776L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.buckets[2].heap_bytes_free;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.buckets[2].heap_bytes_free + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.buckets[2].io;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.buckets[2].io + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.buckets[2].io_read;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.buckets[2].io_read + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.buckets[2].io_write;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.buckets[2].io_write + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.buckets[2].mutex;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.buckets[2].mutex + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.buckets[2].name, "SSR2OSR              ");
        value = msg.buckets[2].thread;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.buckets[2].thread + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.buckets[3].cv;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.buckets[3].cv + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.buckets[3].heap_bytes_alloc;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.buckets[3].heap_bytes_alloc + "' != '" + 247112 + "'",
                    value.equals(BigInteger.valueOf(247112L)));
        } else {
            value = value.longValue();
            expected = 247112L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.buckets[3].heap_bytes_free;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.buckets[3].heap_bytes_free + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.buckets[3].io;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.buckets[3].io + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.buckets[3].io_read;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.buckets[3].io_read + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.buckets[3].io_write;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.buckets[3].io_write + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.buckets[3].mutex;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.buckets[3].mutex + "' != '" + 2 + "'",
                    value.equals(BigInteger.valueOf(2L)));
        } else {
            value = value.longValue();
            expected = 2L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.buckets[3].name, "Periodic             ");
        value = msg.buckets[3].thread;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.buckets[3].thread + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.buckets[4].cv;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.buckets[4].cv + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.buckets[4].heap_bytes_alloc;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.buckets[4].heap_bytes_alloc + "' != '" + 18305 + "'",
                    value.equals(BigInteger.valueOf(18305L)));
        } else {
            value = value.longValue();
            expected = 18305L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.buckets[4].heap_bytes_free;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.buckets[4].heap_bytes_free + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.buckets[4].io;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.buckets[4].io + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.buckets[4].io_read;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.buckets[4].io_read + "' != '" + 26207 + "'",
                    value.equals(BigInteger.valueOf(26207L)));
        } else {
            value = value.longValue();
            expected = 26207L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.buckets[4].io_write;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.buckets[4].io_write + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.buckets[4].mutex;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.buckets[4].mutex + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.buckets[4].name, "IMU                  ");
        value = msg.buckets[4].thread;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.buckets[4].thread + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.buckets[5].cv;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.buckets[5].cv + "' != '" + 2 + "'",
                    value.equals(BigInteger.valueOf(2L)));
        } else {
            value = value.longValue();
            expected = 2L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.buckets[5].heap_bytes_alloc;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.buckets[5].heap_bytes_alloc + "' != '" + 43507 + "'",
                    value.equals(BigInteger.valueOf(43507L)));
        } else {
            value = value.longValue();
            expected = 43507L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.buckets[5].heap_bytes_free;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.buckets[5].heap_bytes_free + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.buckets[5].io;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.buckets[5].io + "' != '" + 2 + "'",
                    value.equals(BigInteger.valueOf(2L)));
        } else {
            value = value.longValue();
            expected = 2L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.buckets[5].io_read;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.buckets[5].io_read + "' != '" + 498 + "'",
                    value.equals(BigInteger.valueOf(498L)));
        } else {
            value = value.longValue();
            expected = 498L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.buckets[5].io_write;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.buckets[5].io_write + "' != '" + 235451 + "'",
                    value.equals(BigInteger.valueOf(235451L)));
        } else {
            value = value.longValue();
            expected = 235451L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.buckets[5].mutex;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.buckets[5].mutex + "' != '" + 2 + "'",
                    value.equals(BigInteger.valueOf(2L)));
        } else {
            value = value.longValue();
            expected = 2L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.buckets[5].name, "sbp                  ");
        value = msg.buckets[5].thread;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.buckets[5].thread + "' != '" + 5 + "'",
                    value.equals(BigInteger.valueOf(5L)));
        } else {
            value = value.longValue();
            expected = 5L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.seq_len;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.seq_len + "' != '" + 3 + "'", value.equals(BigInteger.valueOf(3L)));
        } else {
            value = value.longValue();
            expected = 3L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.seq_no;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.seq_no + "' != '" + 1 + "'", value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
