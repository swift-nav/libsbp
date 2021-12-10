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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgVelNedCovGnss.yaml by generate.py. Do not modify
// by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.navigation.MsgVelNEDCovGnss;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_navigation_MsgVelNedCovGnssTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgVelNedCovGnssTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 168,
                    (byte) 230,
                    (byte) 233,
                    (byte) 29,
                    (byte) 251,
                    (byte) 255,
                    (byte) 255,
                    (byte) 255,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 246,
                    (byte) 255,
                    (byte) 255,
                    (byte) 255,
                    (byte) 15,
                    (byte) 58,
                    (byte) 207,
                    (byte) 58,
                    (byte) 248,
                    (byte) 139,
                    (byte) 116,
                    (byte) 55,
                    (byte) 103,
                    (byte) 197,
                    (byte) 57,
                    (byte) 57,
                    (byte) 203,
                    (byte) 186,
                    (byte) 129,
                    (byte) 58,
                    (byte) 109,
                    (byte) 171,
                    (byte) 44,
                    (byte) 57,
                    (byte) 135,
                    (byte) 39,
                    (byte) 1,
                    (byte) 60,
                    (byte) 21,
                    (byte) 2,
                };
        SBPMessage sbp = new SBPMessage(0x1000, 0x232, payload);
        MsgVelNEDCovGnss msg = new MsgVelNEDCovGnss(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        org.junit.Assert.assertEquals(msg.cov_d_d, 7.88295920938253403e-03, DELTA);
        org.junit.Assert.assertEquals(msg.cov_e_d, 1.64670593221671879e-04, DELTA);
        org.junit.Assert.assertEquals(msg.cov_e_e, 9.89758758805692196e-04, DELTA);
        org.junit.Assert.assertEquals(msg.cov_n_d, 1.77165129571221769e-04, DELTA);
        org.junit.Assert.assertEquals(msg.cov_n_e, 1.45761223393492401e-05, DELTA);
        org.junit.Assert.assertEquals(msg.cov_n_n, 1.58101494889706373e-03, DELTA);
        value = msg.d;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.d + "' != '" + -10 + "'", value.equals(BigInteger.valueOf(-10L)));
        } else {
            value = value.longValue();
            expected = -10L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.e;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.e + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.flags + "' != '" + 2 + "'", value.equals(BigInteger.valueOf(2L)));
        } else {
            value = value.longValue();
            expected = 2L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.n;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.n + "' != '" + -5 + "'", value.equals(BigInteger.valueOf(-5L)));
        } else {
            value = value.longValue();
            expected = -5L;
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
                    "'" + msg.tow + "' != '" + 501868200 + "'",
                    value.equals(BigInteger.valueOf(501868200L)));
        } else {
            value = value.longValue();
            expected = 501868200L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }
}
