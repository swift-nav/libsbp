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
// spec/tests/yaml/swiftnav/sbp/orientation/test_MsgOrientQuatCov.yaml by generate.py. Do not modify
// by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.orientation.MsgOrientQuatCov;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_orientation_MsgOrientQuatCovTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_orientation_MsgOrientQuatCovTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 3,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 7,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 8,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 4,
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
                    (byte) 63,
                    (byte) 0,
                    (byte) 0,
                    (byte) 128,
                    (byte) 62,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 64,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 62,
                    (byte) 0,
                    (byte) 0,
                    (byte) 128,
                    (byte) 64,
                    (byte) 1,
                };
        SBPMessage sbp = new SBPMessage(0x42, 0x223, payload);
        MsgOrientQuatCov msg = new MsgOrientQuatCov(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        org.junit.Assert.assertEquals(msg.cov_x_x, 1.00000000000000000e+00, DELTA);
        org.junit.Assert.assertEquals(msg.cov_x_y, 5.00000000000000000e-01, DELTA);
        org.junit.Assert.assertEquals(msg.cov_x_z, 2.50000000000000000e-01, DELTA);
        org.junit.Assert.assertEquals(msg.cov_y_y, 2.00000000000000000e+00, DELTA);
        org.junit.Assert.assertEquals(msg.cov_y_z, 1.25000000000000000e-01, DELTA);
        org.junit.Assert.assertEquals(msg.cov_z_z, 4.00000000000000000e+00, DELTA);
        value = msg.flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.flags + "' != '" + 1 + "'", value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tow + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.w;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.w + "' != '" + 3 + "'", value.equals(BigInteger.valueOf(3L)));
        } else {
            value = value.longValue();
            expected = 3L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.x;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.x + "' != '" + 7 + "'", value.equals(BigInteger.valueOf(7L)));
        } else {
            value = value.longValue();
            expected = 7L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.y;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.y + "' != '" + 8 + "'", value.equals(BigInteger.valueOf(8L)));
        } else {
            value = value.longValue();
            expected = 8L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.z;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.z + "' != '" + 4 + "'", value.equals(BigInteger.valueOf(4L)));
        } else {
            value = value.longValue();
            expected = 4L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
