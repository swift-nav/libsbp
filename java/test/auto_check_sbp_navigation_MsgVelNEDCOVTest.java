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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgVelNEDCOV.yaml
// by generate.py. Do not modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.navigation.MsgVelNEDCov;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_navigation_MsgVelNEDCOVTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgVelNEDCOVTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 100,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 1,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 1,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 1,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 128,
                    (byte) 63,
                    (byte) 0,
                    (byte) 0,
                    (byte) 128,
                    (byte) 63,
                    (byte) 0,
                    (byte) 0,
                    (byte) 128,
                    (byte) 63,
                    (byte) 0,
                    (byte) 0,
                    (byte) 128,
                    (byte) 63,
                    (byte) 0,
                    (byte) 0,
                    (byte) 128,
                    (byte) 63,
                    (byte) 0,
                    (byte) 0,
                    (byte) 128,
                    (byte) 63,
                    (byte) 10,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x42, 0x212, payload);
        MsgVelNEDCov msg = new MsgVelNEDCov(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        org.junit.Assert.assertEquals(msg.cov_d_d, 1.00000000000000000e+00, DELTA);
        org.junit.Assert.assertEquals(msg.cov_e_d, 1.00000000000000000e+00, DELTA);
        org.junit.Assert.assertEquals(msg.cov_e_e, 1.00000000000000000e+00, DELTA);
        org.junit.Assert.assertEquals(msg.cov_n_d, 1.00000000000000000e+00, DELTA);
        org.junit.Assert.assertEquals(msg.cov_n_e, 1.00000000000000000e+00, DELTA);
        org.junit.Assert.assertEquals(msg.cov_n_n, 1.00000000000000000e+00, DELTA);
        value = msg.d;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.d + "' != '" + 1 + "'", value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.e;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.e + "' != '" + 1 + "'", value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.flags + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.n;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.n + "' != '" + 1 + "'", value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.n_sats;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.n_sats + "' != '" + 10 + "'", value.equals(BigInteger.valueOf(10L)));
        } else {
            value = value.longValue();
            expected = 10L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tow + "' != '" + 100 + "'", value.equals(BigInteger.valueOf(100L)));
        } else {
            value = value.longValue();
            expected = 100L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }
}
