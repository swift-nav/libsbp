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

// This file was auto-generated from
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgVelEcefCovGnss.yaml by generate.py. Do not modify
// by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.navigation.MsgVelECEFCovGnss;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_navigation_MsgVelEcefCovGnssTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgVelEcefCovGnssTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 224,
                    (byte) 229,
                    (byte) 233,
                    (byte) 29,
                    (byte) 253,
                    (byte) 255,
                    (byte) 255,
                    (byte) 255,
                    (byte) 1,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 4,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 46,
                    (byte) 224,
                    (byte) 32,
                    (byte) 59,
                    (byte) 32,
                    (byte) 214,
                    (byte) 14,
                    (byte) 59,
                    (byte) 150,
                    (byte) 147,
                    (byte) 220,
                    (byte) 186,
                    (byte) 19,
                    (byte) 63,
                    (byte) 138,
                    (byte) 59,
                    (byte) 26,
                    (byte) 150,
                    (byte) 35,
                    (byte) 187,
                    (byte) 11,
                    (byte) 193,
                    (byte) 119,
                    (byte) 59,
                    (byte) 21,
                    (byte) 2,
                };
        SBPMessage sbp = new SBPMessage(0x1000, 0x235, payload);
        MsgVelECEFCovGnss msg = new MsgVelECEFCovGnss(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        org.junit.Assert.assertEquals(msg.cov_x_x, 2.45476840063929558e-03, DELTA);
        org.junit.Assert.assertEquals(msg.cov_x_y, 2.17951089143753052e-03, DELTA);
        org.junit.Assert.assertEquals(msg.cov_x_z, -1.68286520056426525e-03, DELTA);
        org.junit.Assert.assertEquals(msg.cov_y_y, 4.21894481405615807e-03, DELTA);
        org.junit.Assert.assertEquals(msg.cov_y_z, -2.49612936750054359e-03, DELTA);
        org.junit.Assert.assertEquals(msg.cov_z_z, 3.78042715601623058e-03, DELTA);
        value = msg.flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.flags + "' != '" + 2 + "'", value.equals(BigInteger.valueOf(2L)));
        } else {
            value = value.longValue();
            expected = 2L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.n_sats;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.n_sats + "' != '" + 21 + "'", value.equals(BigInteger.valueOf(21L)));
        } else {
            value = value.longValue();
            expected = 21L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tow + "' != '" + 501868000 + "'",
                    value.equals(BigInteger.valueOf(501868000L)));
        } else {
            value = value.longValue();
            expected = 501868000L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.x;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.x + "' != '" + -3 + "'", value.equals(BigInteger.valueOf(-3L)));
        } else {
            value = value.longValue();
            expected = -3L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.y;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.y + "' != '" + 1 + "'", value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
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
    }
}
