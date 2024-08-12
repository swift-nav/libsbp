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
package com.swiftnav.sbp.test;

// This file was auto-generated from
// spec/tests/yaml/swiftnav/sbp/profiling/test_MsgProfilingSystemInfo.yaml by generate.py. Do not
// modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.profiling.MsgProfilingSystemInfo;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_profiling_MsgProfilingSystemInfoTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format(
                    "%n%s%n", "auto_check_sbp_profiling_MsgProfilingSystemInfoTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 98, (byte) 40, (byte) 52, (byte) 0, (byte) 0, (byte) 0, (byte) 0,
                    (byte) 0, (byte) 114, (byte) 12, (byte) 157, (byte) 0, (byte) 0, (byte) 0,
                    (byte) 0, (byte) 0, (byte) 27, (byte) 72, (byte) 195, (byte) 226, (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x1000, 0xcf01, payload);
        MsgProfilingSystemInfo msg = new MsgProfilingSystemInfo(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.age;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.age + "' != '" + 10292338 + "'",
                    value.equals(BigInteger.valueOf(10292338L)));
        } else {
            value = value.longValue();
            expected = 10292338L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.heap_usage;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.heap_usage + "' != '" + 14861128 + "'",
                    value.equals(BigInteger.valueOf(14861128L)));
        } else {
            value = value.longValue();
            expected = 14861128L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.n_threads;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.n_threads + "' != '" + 27 + "'",
                    value.equals(BigInteger.valueOf(27L)));
        } else {
            value = value.longValue();
            expected = 27L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.total_cpu_time;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.total_cpu_time + "' != '" + 3418210 + "'",
                    value.equals(BigInteger.valueOf(3418210L)));
        } else {
            value = value.longValue();
            expected = 3418210L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
