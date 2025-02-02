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
// spec/tests/yaml/swiftnav/sbp/profiling/test_MsgProfilingThreadInfo.yaml by generate.py. Do not
// modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.profiling.MsgProfilingThreadInfo;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_profiling_MsgProfilingThreadInfoTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format(
                    "%n%s%n", "auto_check_sbp_profiling_MsgProfilingThreadInfoTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 119,
                    (byte) 91,
                    (byte) 10,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 110,
                    (byte) 5,
                    (byte) 155,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 1,
                    (byte) 0,
                    (byte) 0,
                    (byte) 128,
                    (byte) 0,
                    (byte) 208,
                    (byte) 53,
                    (byte) 4,
                    (byte) 0,
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
                };
        SBPMessage sbp = new SBPMessage(0x1000, 0xcf02, payload);
        MsgProfilingThreadInfo msg = new MsgProfilingThreadInfo(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.age;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.age + "' != '" + 10159470 + "'",
                    value.equals(BigInteger.valueOf(10159470L)));
        } else {
            value = value.longValue();
            expected = 10159470L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.name, "Fusion engine ");
        value = msg.stack_size;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stack_size + "' != '" + 8388608 + "'",
                    value.equals(BigInteger.valueOf(8388608L)));
        } else {
            value = value.longValue();
            expected = 8388608L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stack_usage;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stack_usage + "' != '" + 275920 + "'",
                    value.equals(BigInteger.valueOf(275920L)));
        } else {
            value = value.longValue();
            expected = 275920L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.state + "' != '" + 1 + "'", value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.total_cpu_time;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.total_cpu_time + "' != '" + 678775 + "'",
                    value.equals(BigInteger.valueOf(678775L)));
        } else {
            value = value.longValue();
            expected = 678775L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
