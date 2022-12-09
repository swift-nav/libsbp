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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPoseRelative.yaml by generate.py. Do not modify
// by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.navigation.MsgPoseRelative;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_navigation_MsgPoseRelativeTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgPoseRelativeTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 86,
                    (byte) 4,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 86,
                    (byte) 4,
                    (byte) 0,
                    (byte) 0,
                    (byte) 172,
                    (byte) 8,
                    (byte) 0,
                    (byte) 0,
                    (byte) 76,
                    (byte) 4,
                    (byte) 0,
                    (byte) 0,
                    (byte) 38,
                    (byte) 2,
                    (byte) 0,
                    (byte) 0,
                    (byte) 100,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 100,
                    (byte) 3,
                    (byte) 200,
                    (byte) 204,
                    (byte) 252,
                    (byte) 168,
                    (byte) 157,
                    (byte) 255,
                    (byte) 115,
                    (byte) 53,
                    (byte) 186,
                    (byte) 144,
                    (byte) 190,
                    (byte) 48,
                    (byte) 34,
                    (byte) 37,
                    (byte) 0,
                    (byte) 0,
                    (byte) 128,
                    (byte) 63,
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
                    (byte) 128,
                    (byte) 63,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 128,
                    (byte) 63,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 64,
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
                    (byte) 64,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 64,
                    (byte) 5,
                };
        SBPMessage sbp = new SBPMessage(0x42, 0x245, payload);
        MsgPoseRelative msg = new MsgPoseRelative(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        org.junit.Assert.assertEquals(msg.cov_c_x_x, 2.00000000000000000e+00, DELTA);
        org.junit.Assert.assertEquals(msg.cov_c_x_y, 0.00000000000000000e+00, DELTA);
        org.junit.Assert.assertEquals(msg.cov_c_x_z, 0.00000000000000000e+00, DELTA);
        org.junit.Assert.assertEquals(msg.cov_c_y_y, 2.00000000000000000e+00, DELTA);
        org.junit.Assert.assertEquals(msg.cov_c_y_z, 0.00000000000000000e+00, DELTA);
        org.junit.Assert.assertEquals(msg.cov_c_z_z, 2.00000000000000000e+00, DELTA);
        org.junit.Assert.assertEquals(msg.cov_r_x_x, 1.00000000000000000e+00, DELTA);
        org.junit.Assert.assertEquals(msg.cov_r_x_y, 0.00000000000000000e+00, DELTA);
        org.junit.Assert.assertEquals(msg.cov_r_x_z, 0.00000000000000000e+00, DELTA);
        org.junit.Assert.assertEquals(msg.cov_r_y_y, 1.00000000000000000e+00, DELTA);
        org.junit.Assert.assertEquals(msg.cov_r_y_z, 0.00000000000000000e+00, DELTA);
        org.junit.Assert.assertEquals(msg.cov_r_z_z, 1.00000000000000000e+00, DELTA);
        value = msg.flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.flags + "' != '" + 5 + "'", value.equals(BigInteger.valueOf(5L)));
        } else {
            value = value.longValue();
            expected = 5L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sensor_id;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sensor_id + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.timestamp_1;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.timestamp_1 + "' != '" + 1110 + "'",
                    value.equals(BigInteger.valueOf(1110L)));
        } else {
            value = value.longValue();
            expected = 1110L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.timestamp_2;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.timestamp_2 + "' != '" + 2220 + "'",
                    value.equals(BigInteger.valueOf(2220L)));
        } else {
            value = value.longValue();
            expected = 2220L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tow + "' != '" + 1110 + "'", value.equals(BigInteger.valueOf(1110L)));
        } else {
            value = value.longValue();
            expected = 1110L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.trans[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.trans[0] + "' != '" + 1100 + "'",
                    value.equals(BigInteger.valueOf(1100L)));
        } else {
            value = value.longValue();
            expected = 1100L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.trans[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.trans[1] + "' != '" + 550 + "'",
                    value.equals(BigInteger.valueOf(550L)));
        } else {
            value = value.longValue();
            expected = 550L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.trans[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.trans[2] + "' != '" + 100 + "'",
                    value.equals(BigInteger.valueOf(100L)));
        } else {
            value = value.longValue();
            expected = 100L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.w;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.w + "' != '" + -859307164 + "'",
                    value.equals(BigInteger.valueOf(-859307164L)));
        } else {
            value = value.longValue();
            expected = -859307164L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.x;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.x + "' != '" + -6444804 + "'",
                    value.equals(BigInteger.valueOf(-6444804L)));
        } else {
            value = value.longValue();
            expected = -6444804L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.y;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.y + "' != '" + -1866844813 + "'",
                    value.equals(BigInteger.valueOf(-1866844813L)));
        } else {
            value = value.longValue();
            expected = -1866844813L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.z;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.z + "' != '" + 622997694 + "'",
                    value.equals(BigInteger.valueOf(622997694L)));
        } else {
            value = value.longValue();
            expected = 622997694L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotNull(msg.getFriendlyName());
        org.junit.Assert.assertFalse(msg.getFriendlyName().isEmpty());
    }
}
