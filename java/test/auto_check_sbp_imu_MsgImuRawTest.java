/* Copyright (C) 2015-2021 Swift Navigation Inc.
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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/imu/test_MsgImuRaw.yaml by
// generate.py. Do not modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.imu.MsgImuRaw;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_imu_MsgImuRawTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_imu_MsgImuRawTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 26, (byte) 1, (byte) 0, (byte) 192, (byte) 206, (byte) 96, (byte) 0,
                    (byte) 223, (byte) 255, (byte) 44, (byte) 16, (byte) 60, (byte) 0, (byte) 208,
                    (byte) 254, (byte) 238, (byte) 255,
                };
        SBPMessage sbp = new SBPMessage(0x1234, 0x900, payload);
        MsgImuRaw msg = new MsgImuRaw(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.acc_x;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.acc_x + "' != '" + 96 + "'", value.equals(BigInteger.valueOf(96L)));
        } else {
            value = value.longValue();
            expected = 96L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acc_y;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.acc_y + "' != '" + -33 + "'", value.equals(BigInteger.valueOf(-33L)));
        } else {
            value = value.longValue();
            expected = -33L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acc_z;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.acc_z + "' != '" + 4140 + "'",
                    value.equals(BigInteger.valueOf(4140L)));
        } else {
            value = value.longValue();
            expected = 4140L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.gyr_x;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.gyr_x + "' != '" + 60 + "'", value.equals(BigInteger.valueOf(60L)));
        } else {
            value = value.longValue();
            expected = 60L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.gyr_y;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.gyr_y + "' != '" + -304 + "'",
                    value.equals(BigInteger.valueOf(-304L)));
        } else {
            value = value.longValue();
            expected = -304L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.gyr_z;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.gyr_z + "' != '" + -18 + "'", value.equals(BigInteger.valueOf(-18L)));
        } else {
            value = value.longValue();
            expected = -18L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tow + "' != '" + 3221225754L + "'",
                    value.equals(new BigInteger("3221225754")));
        } else {
            value = value.longValue();
            expected = 3221225754L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tow_f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tow_f + "' != '" + 206 + "'", value.equals(BigInteger.valueOf(206L)));
        } else {
            value = value.longValue();
            expected = 206L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }
}
