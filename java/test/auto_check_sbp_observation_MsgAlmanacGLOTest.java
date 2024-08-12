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
// spec/tests/yaml/swiftnav/sbp/observation/test_MsgAlmanacGLO.yaml by generate.py. Do not modify by
// hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.observation.MsgAlmanacGlo;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_observation_MsgAlmanacGLOTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_observation_MsgAlmanacGLOTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 22,
                    (byte) 0,
                    (byte) 176,
                    (byte) 207,
                    (byte) 6,
                    (byte) 0,
                    (byte) 106,
                    (byte) 8,
                    (byte) 154,
                    (byte) 153,
                    (byte) 153,
                    (byte) 153,
                    (byte) 153,
                    (byte) 153,
                    (byte) 1,
                    (byte) 64,
                    (byte) 64,
                    (byte) 56,
                    (byte) 0,
                    (byte) 0,
                    (byte) 1,
                    (byte) 0,
                    (byte) 142,
                    (byte) 41,
                    (byte) 5,
                    (byte) 235,
                    (byte) 95,
                    (byte) 135,
                    (byte) 150,
                    (byte) 191,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 32,
                    (byte) 191,
                    (byte) 247,
                    (byte) 124,
                    (byte) 63,
                    (byte) 0,
                    (byte) 0,
                    (byte) 192,
                    (byte) 206,
                    (byte) 140,
                    (byte) 33,
                    (byte) 180,
                    (byte) 64,
                    (byte) 41,
                    (byte) 131,
                    (byte) 179,
                    (byte) 134,
                    (byte) 141,
                    (byte) 248,
                    (byte) 253,
                    (byte) 191,
                    (byte) 227,
                    (byte) 133,
                    (byte) 81,
                    (byte) 54,
                    (byte) 204,
                    (byte) 30,
                    (byte) 67,
                    (byte) 190,
                    (byte) 216,
                    (byte) 59,
                    (byte) 199,
                    (byte) 39,
                    (byte) 96,
                    (byte) 168,
                    (byte) 239,
                    (byte) 191,
                    (byte) 71,
                    (byte) 11,
                    (byte) 217,
                    (byte) 147,
                    (byte) 145,
                    (byte) 228,
                    (byte) 237,
                    (byte) 63,
                };
        SBPMessage sbp = new SBPMessage(0x04c3, 0x73, payload);
        MsgAlmanacGlo msg = new MsgAlmanacGlo(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.common.fit_interval;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.common.fit_interval + "' != '" + 14400 + "'",
                    value.equals(BigInteger.valueOf(14400L)));
        } else {
            value = value.longValue();
            expected = 14400L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.common.health_bits;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.common.health_bits + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.common.sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.common.sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.common.sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.common.sid.sat + "' != '" + 22 + "'",
                    value.equals(BigInteger.valueOf(22L)));
        } else {
            value = value.longValue();
            expected = 22L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.common.toa.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.common.toa.tow + "' != '" + 446384 + "'",
                    value.equals(BigInteger.valueOf(446384L)));
        } else {
            value = value.longValue();
            expected = 446384L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.common.toa.wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.common.toa.wn + "' != '" + 2154 + "'",
                    value.equals(BigInteger.valueOf(2154L)));
        } else {
            value = value.longValue();
            expected = 2154L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.common.ura, 2.20000000000000018e+00, DELTA);
        value = msg.common.valid;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.common.valid + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.epsilon, -9.89303662959964747e-01, DELTA);
        org.junit.Assert.assertEquals(msg.i, 5.15355002975463867e+03, DELTA);
        org.junit.Assert.assertEquals(msg.lambda_na, -2.20007884211468815e-02, DELTA);
        org.junit.Assert.assertEquals(msg.omega, 9.34151448025979714e-01, DELTA);
        org.junit.Assert.assertEquals(msg.t, -1.87318184487976169e+00, DELTA);
        org.junit.Assert.assertEquals(msg.t_dot, -8.90358515577419627e-09, DELTA);
        org.junit.Assert.assertEquals(msg.t_lambda_na, 7.07220705226063728e-03, DELTA);

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
