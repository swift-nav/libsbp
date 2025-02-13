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
// spec/tests/yaml/swiftnav/sbp/profiling/test_MsgMeasurementPoint.yaml by generate.py. Do not
// modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.profiling.MsgMeasurementPoint;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_profiling_MsgMeasurementPointTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_profiling_MsgMeasurementPointTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 250, (byte) 7, (byte) 0, (byte) 0, (byte) 180, (byte) 0, (byte) 2,
                    (byte) 0, (byte) 0, (byte) 0, (byte) 40, (byte) 0, (byte) 0, (byte) 0,
                    (byte) 130, (byte) 201, (byte) 148, (byte) 141, (byte) 97, (byte) 85, (byte) 0,
                    (byte) 0, (byte) 18, (byte) 130, (byte) 201, (byte) 148, (byte) 0, (byte) 0,
                    (byte) 0, (byte) 0, (byte) 66, (byte) 64, (byte) 157, (byte) 15, (byte) 0,
                    (byte) 0, (byte) 0, (byte) 0, (byte) 18, (byte) 0, (byte) 114, (byte) 111,
                    (byte) 117, (byte) 116, (byte) 101, (byte) 40, (byte) 41, (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x1000, 0xCF00, payload);
        MsgMeasurementPoint msg = new MsgMeasurementPoint(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        org.junit.Assert.assertEquals(msg.func, "route() ");
        value = msg.id;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.id + "' != '" + 2496234002L + "'",
                    value.equals(new BigInteger("2496234002")));
        } else {
            value = value.longValue();
            expected = 2496234002L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.line;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.line + "' != '" + 18 + "'", value.equals(BigInteger.valueOf(18L)));
        } else {
            value = value.longValue();
            expected = 18L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.max;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.max + "' != '" + 40 + "'", value.equals(BigInteger.valueOf(40L)));
        } else {
            value = value.longValue();
            expected = 40L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.min;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.min + "' != '" + 2 + "'", value.equals(BigInteger.valueOf(2L)));
        } else {
            value = value.longValue();
            expected = 2L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.num_executions;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.num_executions + "' != '" + 180 + "'",
                    value.equals(BigInteger.valueOf(180L)));
        } else {
            value = value.longValue();
            expected = 180L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.return_addr;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.return_addr + "' != '" + 93877475527042L + "'",
                    value.equals(new BigInteger("93877475527042")));
        } else {
            value = value.longValue();
            expected = 93877475527042L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.slice_time;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.slice_time + "' != '" + 261963842 + "'",
                    value.equals(BigInteger.valueOf(261963842L)));
        } else {
            value = value.longValue();
            expected = 261963842L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.total_time;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.total_time + "' != '" + 2042 + "'",
                    value.equals(BigInteger.valueOf(2042L)));
        } else {
            value = value.longValue();
            expected = 2042L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
