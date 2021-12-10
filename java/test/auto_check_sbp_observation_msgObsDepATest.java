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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/observation/test_msgObsDepA.yaml
// by generate.py. Do not modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.observation.MsgObsDepA;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_observation_msgObsDepATest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_observation_msgObsDepATest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 56,
                    (byte) 158,
                    (byte) 67,
                    (byte) 24,
                    (byte) 46,
                    (byte) 7,
                    (byte) 32,
                    (byte) 56,
                    (byte) 235,
                    (byte) 249,
                    (byte) 121,
                    (byte) 244,
                    (byte) 114,
                    (byte) 255,
                    (byte) 255,
                    (byte) 33,
                    (byte) 46,
                    (byte) 67,
                    (byte) 218,
                    (byte) 0,
                    (byte) 238,
                    (byte) 203,
                    (byte) 70,
                    (byte) 124,
                    (byte) 22,
                    (byte) 25,
                    (byte) 3,
                    (byte) 0,
                    (byte) 98,
                    (byte) 43,
                    (byte) 184,
                    (byte) 157,
                    (byte) 2,
                    (byte) 176,
                    (byte) 133,
                    (byte) 197,
                    (byte) 125,
                    (byte) 126,
                    (byte) 71,
                    (byte) 253,
                    (byte) 255,
                    (byte) 185,
                    (byte) 39,
                    (byte) 68,
                    (byte) 55,
                    (byte) 3,
                    (byte) 60,
                    (byte) 173,
                    (byte) 162,
                    (byte) 131,
                    (byte) 98,
                    (byte) 231,
                    (byte) 253,
                    (byte) 255,
                    (byte) 139,
                    (byte) 30,
                    (byte) 33,
                    (byte) 16,
                    (byte) 10,
                    (byte) 128,
                    (byte) 178,
                    (byte) 248,
                    (byte) 136,
                    (byte) 42,
                    (byte) 113,
                    (byte) 253,
                    (byte) 255,
                    (byte) 40,
                    (byte) 20,
                    (byte) 42,
                    (byte) 71,
                    (byte) 13,
                    (byte) 246,
                    (byte) 246,
                    (byte) 17,
                    (byte) 135,
                    (byte) 255,
                    (byte) 51,
                    (byte) 3,
                    (byte) 0,
                    (byte) 64,
                    (byte) 27,
                    (byte) 108,
                    (byte) 249,
                    (byte) 22,
                    (byte) 210,
                    (byte) 41,
                    (byte) 114,
                    (byte) 118,
                    (byte) 131,
                    (byte) 48,
                    (byte) 255,
                    (byte) 255,
                    (byte) 31,
                    (byte) 52,
                    (byte) 226,
                    (byte) 58,
                    (byte) 30,
                };
        SBPMessage sbp = new SBPMessage(0x4c3, 0x45, payload);
        MsgObsDepA msg = new MsgObsDepA(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.header.n_obs;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.header.n_obs + "' != '" + 32 + "'",
                    value.equals(BigInteger.valueOf(32L)));
        } else {
            value = value.longValue();
            expected = 32L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.header.t.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.header.t.tow + "' != '" + 407084600 + "'",
                    value.equals(BigInteger.valueOf(407084600L)));
        } else {
            value = value.longValue();
            expected = 407084600L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.header.t.wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.header.t.wn + "' != '" + 1838 + "'",
                    value.equals(BigInteger.valueOf(1838L)));
        } else {
            value = value.longValue();
            expected = 1838L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].L.f + "' != '" + 33 + "'",
                    value.equals(BigInteger.valueOf(33L)));
        } else {
            value = value.longValue();
            expected = 33L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].L.i + "' != '" + -36108 + "'",
                    value.equals(BigInteger.valueOf(-36108L)));
        } else {
            value = value.longValue();
            expected = -36108L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].P + "' != '" + 2046421816 + "'",
                    value.equals(BigInteger.valueOf(2046421816L)));
        } else {
            value = value.longValue();
            expected = 2046421816L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].cn0 + "' != '" + 46 + "'",
                    value.equals(BigInteger.valueOf(46L)));
        } else {
            value = value.longValue();
            expected = 46L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].lock + "' != '" + 55875 + "'",
                    value.equals(BigInteger.valueOf(55875L)));
        } else {
            value = value.longValue();
            expected = 55875L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].prn + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].L.f + "' != '" + 98 + "'",
                    value.equals(BigInteger.valueOf(98L)));
        } else {
            value = value.longValue();
            expected = 98L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].L.i + "' != '" + 203030 + "'",
                    value.equals(BigInteger.valueOf(203030L)));
        } else {
            value = value.longValue();
            expected = 203030L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].P + "' != '" + 2085014510 + "'",
                    value.equals(BigInteger.valueOf(2085014510L)));
        } else {
            value = value.longValue();
            expected = 2085014510L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].cn0 + "' != '" + 43 + "'",
                    value.equals(BigInteger.valueOf(43L)));
        } else {
            value = value.longValue();
            expected = 43L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].lock + "' != '" + 40376 + "'",
                    value.equals(BigInteger.valueOf(40376L)));
        } else {
            value = value.longValue();
            expected = 40376L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].prn + "' != '" + 2 + "'",
                    value.equals(BigInteger.valueOf(2L)));
        } else {
            value = value.longValue();
            expected = 2L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].L.f + "' != '" + 185 + "'",
                    value.equals(BigInteger.valueOf(185L)));
        } else {
            value = value.longValue();
            expected = 185L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].L.i + "' != '" + -178306 + "'",
                    value.equals(BigInteger.valueOf(-178306L)));
        } else {
            value = value.longValue();
            expected = -178306L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].P + "' != '" + 2110096816 + "'",
                    value.equals(BigInteger.valueOf(2110096816L)));
        } else {
            value = value.longValue();
            expected = 2110096816L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].cn0 + "' != '" + 39 + "'",
                    value.equals(BigInteger.valueOf(39L)));
        } else {
            value = value.longValue();
            expected = 39L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].lock + "' != '" + 14148 + "'",
                    value.equals(BigInteger.valueOf(14148L)));
        } else {
            value = value.longValue();
            expected = 14148L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].prn + "' != '" + 3 + "'",
                    value.equals(BigInteger.valueOf(3L)));
        } else {
            value = value.longValue();
            expected = 3L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].L.f + "' != '" + 139 + "'",
                    value.equals(BigInteger.valueOf(139L)));
        } else {
            value = value.longValue();
            expected = 139L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].L.i + "' != '" + -137374 + "'",
                    value.equals(BigInteger.valueOf(-137374L)));
        } else {
            value = value.longValue();
            expected = -137374L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].P + "' != '" + 2208476476L + "'",
                    value.equals(new BigInteger("2208476476")));
        } else {
            value = value.longValue();
            expected = 2208476476L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].cn0 + "' != '" + 30 + "'",
                    value.equals(BigInteger.valueOf(30L)));
        } else {
            value = value.longValue();
            expected = 30L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].lock + "' != '" + 4129 + "'",
                    value.equals(BigInteger.valueOf(4129L)));
        } else {
            value = value.longValue();
            expected = 4129L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].prn + "' != '" + 10 + "'",
                    value.equals(BigInteger.valueOf(10L)));
        } else {
            value = value.longValue();
            expected = 10L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].L.f + "' != '" + 40 + "'",
                    value.equals(BigInteger.valueOf(40L)));
        } else {
            value = value.longValue();
            expected = 40L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].L.i + "' != '" + -167638 + "'",
                    value.equals(BigInteger.valueOf(-167638L)));
        } else {
            value = value.longValue();
            expected = -167638L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].P + "' != '" + 2298000000L + "'",
                    value.equals(new BigInteger("2298000000")));
        } else {
            value = value.longValue();
            expected = 2298000000L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].cn0 + "' != '" + 20 + "'",
                    value.equals(BigInteger.valueOf(20L)));
        } else {
            value = value.longValue();
            expected = 20L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].lock + "' != '" + 18218 + "'",
                    value.equals(BigInteger.valueOf(18218L)));
        } else {
            value = value.longValue();
            expected = 18218L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].prn + "' != '" + 13 + "'",
                    value.equals(BigInteger.valueOf(13L)));
        } else {
            value = value.longValue();
            expected = 13L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[5].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[5].L.f + "' != '" + 64 + "'",
                    value.equals(BigInteger.valueOf(64L)));
        } else {
            value = value.longValue();
            expected = 64L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[5].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[5].L.i + "' != '" + 209919 + "'",
                    value.equals(BigInteger.valueOf(209919L)));
        } else {
            value = value.longValue();
            expected = 209919L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[5].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[5].P + "' != '" + 2266101494L + "'",
                    value.equals(new BigInteger("2266101494")));
        } else {
            value = value.longValue();
            expected = 2266101494L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[5].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[5].cn0 + "' != '" + 27 + "'",
                    value.equals(BigInteger.valueOf(27L)));
        } else {
            value = value.longValue();
            expected = 27L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[5].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[5].lock + "' != '" + 63852 + "'",
                    value.equals(BigInteger.valueOf(63852L)));
        } else {
            value = value.longValue();
            expected = 63852L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[5].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[5].prn + "' != '" + 22 + "'",
                    value.equals(BigInteger.valueOf(22L)));
        } else {
            value = value.longValue();
            expected = 22L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[6].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[6].L.f + "' != '" + 31 + "'",
                    value.equals(BigInteger.valueOf(31L)));
        } else {
            value = value.longValue();
            expected = 31L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[6].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[6].L.i + "' != '" + -53117 + "'",
                    value.equals(BigInteger.valueOf(-53117L)));
        } else {
            value = value.longValue();
            expected = -53117L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[6].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[6].P + "' != '" + 1987193298 + "'",
                    value.equals(BigInteger.valueOf(1987193298L)));
        } else {
            value = value.longValue();
            expected = 1987193298L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[6].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[6].cn0 + "' != '" + 52 + "'",
                    value.equals(BigInteger.valueOf(52L)));
        } else {
            value = value.longValue();
            expected = 52L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[6].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[6].lock + "' != '" + 15074 + "'",
                    value.equals(BigInteger.valueOf(15074L)));
        } else {
            value = value.longValue();
            expected = 15074L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[6].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[6].prn + "' != '" + 30 + "'",
                    value.equals(BigInteger.valueOf(30L)));
        } else {
            value = value.longValue();
            expected = 30L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test2() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_observation_msgObsDepATest.test2");
        byte[] payload =
                new byte[] {
                    (byte) 56, (byte) 158, (byte) 67, (byte) 24, (byte) 46, (byte) 7, (byte) 33,
                    (byte) 84, (byte) 52, (byte) 164, (byte) 117, (byte) 102, (byte) 32, (byte) 0,
                    (byte) 0, (byte) 147, (byte) 62, (byte) 62, (byte) 250, (byte) 31,
                };
        SBPMessage sbp = new SBPMessage(0x4c3, 0x45, payload);
        MsgObsDepA msg = new MsgObsDepA(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.header.n_obs;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.header.n_obs + "' != '" + 33 + "'",
                    value.equals(BigInteger.valueOf(33L)));
        } else {
            value = value.longValue();
            expected = 33L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.header.t.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.header.t.tow + "' != '" + 407084600 + "'",
                    value.equals(BigInteger.valueOf(407084600L)));
        } else {
            value = value.longValue();
            expected = 407084600L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.header.t.wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.header.t.wn + "' != '" + 1838 + "'",
                    value.equals(BigInteger.valueOf(1838L)));
        } else {
            value = value.longValue();
            expected = 1838L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].L.f + "' != '" + 147 + "'",
                    value.equals(BigInteger.valueOf(147L)));
        } else {
            value = value.longValue();
            expected = 147L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].L.i + "' != '" + 8294 + "'",
                    value.equals(BigInteger.valueOf(8294L)));
        } else {
            value = value.longValue();
            expected = 8294L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].P + "' != '" + 1973695572 + "'",
                    value.equals(BigInteger.valueOf(1973695572L)));
        } else {
            value = value.longValue();
            expected = 1973695572L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].cn0 + "' != '" + 62 + "'",
                    value.equals(BigInteger.valueOf(62L)));
        } else {
            value = value.longValue();
            expected = 62L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].lock + "' != '" + 64062 + "'",
                    value.equals(BigInteger.valueOf(64062L)));
        } else {
            value = value.longValue();
            expected = 64062L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].prn + "' != '" + 31 + "'",
                    value.equals(BigInteger.valueOf(31L)));
        } else {
            value = value.longValue();
            expected = 31L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test3() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_observation_msgObsDepATest.test3");
        byte[] payload =
                new byte[] {
                    (byte) 0,
                    (byte) 159,
                    (byte) 67,
                    (byte) 24,
                    (byte) 46,
                    (byte) 7,
                    (byte) 32,
                    (byte) 32,
                    (byte) 209,
                    (byte) 249,
                    (byte) 121,
                    (byte) 145,
                    (byte) 114,
                    (byte) 255,
                    (byte) 255,
                    (byte) 141,
                    (byte) 45,
                    (byte) 67,
                    (byte) 218,
                    (byte) 0,
                    (byte) 177,
                    (byte) 128,
                    (byte) 70,
                    (byte) 124,
                    (byte) 79,
                    (byte) 27,
                    (byte) 3,
                    (byte) 0,
                    (byte) 159,
                    (byte) 44,
                    (byte) 184,
                    (byte) 157,
                    (byte) 2,
                    (byte) 59,
                    (byte) 135,
                    (byte) 197,
                    (byte) 125,
                    (byte) 175,
                    (byte) 69,
                    (byte) 253,
                    (byte) 255,
                    (byte) 77,
                    (byte) 40,
                    (byte) 68,
                    (byte) 55,
                    (byte) 3,
                    (byte) 211,
                    (byte) 172,
                    (byte) 162,
                    (byte) 131,
                    (byte) 177,
                    (byte) 229,
                    (byte) 253,
                    (byte) 255,
                    (byte) 20,
                    (byte) 31,
                    (byte) 33,
                    (byte) 16,
                    (byte) 10,
                    (byte) 128,
                    (byte) 178,
                    (byte) 248,
                    (byte) 136,
                    (byte) 116,
                    (byte) 111,
                    (byte) 253,
                    (byte) 255,
                    (byte) 94,
                    (byte) 21,
                    (byte) 42,
                    (byte) 71,
                    (byte) 13,
                    (byte) 182,
                    (byte) 173,
                    (byte) 17,
                    (byte) 135,
                    (byte) 37,
                    (byte) 54,
                    (byte) 3,
                    (byte) 0,
                    (byte) 214,
                    (byte) 27,
                    (byte) 108,
                    (byte) 249,
                    (byte) 22,
                    (byte) 91,
                    (byte) 20,
                    (byte) 114,
                    (byte) 118,
                    (byte) 240,
                    (byte) 47,
                    (byte) 255,
                    (byte) 255,
                    (byte) 129,
                    (byte) 52,
                    (byte) 226,
                    (byte) 58,
                    (byte) 30,
                };
        SBPMessage sbp = new SBPMessage(0x4c3, 0x45, payload);
        MsgObsDepA msg = new MsgObsDepA(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.header.n_obs;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.header.n_obs + "' != '" + 32 + "'",
                    value.equals(BigInteger.valueOf(32L)));
        } else {
            value = value.longValue();
            expected = 32L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.header.t.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.header.t.tow + "' != '" + 407084800 + "'",
                    value.equals(BigInteger.valueOf(407084800L)));
        } else {
            value = value.longValue();
            expected = 407084800L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.header.t.wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.header.t.wn + "' != '" + 1838 + "'",
                    value.equals(BigInteger.valueOf(1838L)));
        } else {
            value = value.longValue();
            expected = 1838L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].L.f + "' != '" + 141 + "'",
                    value.equals(BigInteger.valueOf(141L)));
        } else {
            value = value.longValue();
            expected = 141L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].L.i + "' != '" + -36207 + "'",
                    value.equals(BigInteger.valueOf(-36207L)));
        } else {
            value = value.longValue();
            expected = -36207L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].P + "' != '" + 2046415136 + "'",
                    value.equals(BigInteger.valueOf(2046415136L)));
        } else {
            value = value.longValue();
            expected = 2046415136L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].cn0 + "' != '" + 45 + "'",
                    value.equals(BigInteger.valueOf(45L)));
        } else {
            value = value.longValue();
            expected = 45L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].lock + "' != '" + 55875 + "'",
                    value.equals(BigInteger.valueOf(55875L)));
        } else {
            value = value.longValue();
            expected = 55875L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].prn + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].L.f + "' != '" + 159 + "'",
                    value.equals(BigInteger.valueOf(159L)));
        } else {
            value = value.longValue();
            expected = 159L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].L.i + "' != '" + 203599 + "'",
                    value.equals(BigInteger.valueOf(203599L)));
        } else {
            value = value.longValue();
            expected = 203599L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].P + "' != '" + 2084995249 + "'",
                    value.equals(BigInteger.valueOf(2084995249L)));
        } else {
            value = value.longValue();
            expected = 2084995249L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].cn0 + "' != '" + 44 + "'",
                    value.equals(BigInteger.valueOf(44L)));
        } else {
            value = value.longValue();
            expected = 44L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].lock + "' != '" + 40376 + "'",
                    value.equals(BigInteger.valueOf(40376L)));
        } else {
            value = value.longValue();
            expected = 40376L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].prn + "' != '" + 2 + "'",
                    value.equals(BigInteger.valueOf(2L)));
        } else {
            value = value.longValue();
            expected = 2L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].L.f + "' != '" + 77 + "'",
                    value.equals(BigInteger.valueOf(77L)));
        } else {
            value = value.longValue();
            expected = 77L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].L.i + "' != '" + -178769 + "'",
                    value.equals(BigInteger.valueOf(-178769L)));
        } else {
            value = value.longValue();
            expected = -178769L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].P + "' != '" + 2110097211 + "'",
                    value.equals(BigInteger.valueOf(2110097211L)));
        } else {
            value = value.longValue();
            expected = 2110097211L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].cn0 + "' != '" + 40 + "'",
                    value.equals(BigInteger.valueOf(40L)));
        } else {
            value = value.longValue();
            expected = 40L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].lock + "' != '" + 14148 + "'",
                    value.equals(BigInteger.valueOf(14148L)));
        } else {
            value = value.longValue();
            expected = 14148L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].prn + "' != '" + 3 + "'",
                    value.equals(BigInteger.valueOf(3L)));
        } else {
            value = value.longValue();
            expected = 3L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].L.f + "' != '" + 20 + "'",
                    value.equals(BigInteger.valueOf(20L)));
        } else {
            value = value.longValue();
            expected = 20L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].L.i + "' != '" + -137807 + "'",
                    value.equals(BigInteger.valueOf(-137807L)));
        } else {
            value = value.longValue();
            expected = -137807L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].P + "' != '" + 2208476371L + "'",
                    value.equals(new BigInteger("2208476371")));
        } else {
            value = value.longValue();
            expected = 2208476371L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].cn0 + "' != '" + 31 + "'",
                    value.equals(BigInteger.valueOf(31L)));
        } else {
            value = value.longValue();
            expected = 31L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].lock + "' != '" + 4129 + "'",
                    value.equals(BigInteger.valueOf(4129L)));
        } else {
            value = value.longValue();
            expected = 4129L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].prn + "' != '" + 10 + "'",
                    value.equals(BigInteger.valueOf(10L)));
        } else {
            value = value.longValue();
            expected = 10L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].L.f + "' != '" + 94 + "'",
                    value.equals(BigInteger.valueOf(94L)));
        } else {
            value = value.longValue();
            expected = 94L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].L.i + "' != '" + -168076 + "'",
                    value.equals(BigInteger.valueOf(-168076L)));
        } else {
            value = value.longValue();
            expected = -168076L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].P + "' != '" + 2298000000L + "'",
                    value.equals(new BigInteger("2298000000")));
        } else {
            value = value.longValue();
            expected = 2298000000L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].cn0 + "' != '" + 21 + "'",
                    value.equals(BigInteger.valueOf(21L)));
        } else {
            value = value.longValue();
            expected = 21L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].lock + "' != '" + 18218 + "'",
                    value.equals(BigInteger.valueOf(18218L)));
        } else {
            value = value.longValue();
            expected = 18218L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].prn + "' != '" + 13 + "'",
                    value.equals(BigInteger.valueOf(13L)));
        } else {
            value = value.longValue();
            expected = 13L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[5].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[5].L.f + "' != '" + 214 + "'",
                    value.equals(BigInteger.valueOf(214L)));
        } else {
            value = value.longValue();
            expected = 214L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[5].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[5].L.i + "' != '" + 210469 + "'",
                    value.equals(BigInteger.valueOf(210469L)));
        } else {
            value = value.longValue();
            expected = 210469L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[5].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[5].P + "' != '" + 2266082742L + "'",
                    value.equals(new BigInteger("2266082742")));
        } else {
            value = value.longValue();
            expected = 2266082742L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[5].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[5].cn0 + "' != '" + 27 + "'",
                    value.equals(BigInteger.valueOf(27L)));
        } else {
            value = value.longValue();
            expected = 27L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[5].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[5].lock + "' != '" + 63852 + "'",
                    value.equals(BigInteger.valueOf(63852L)));
        } else {
            value = value.longValue();
            expected = 63852L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[5].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[5].prn + "' != '" + 22 + "'",
                    value.equals(BigInteger.valueOf(22L)));
        } else {
            value = value.longValue();
            expected = 22L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[6].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[6].L.f + "' != '" + 129 + "'",
                    value.equals(BigInteger.valueOf(129L)));
        } else {
            value = value.longValue();
            expected = 129L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[6].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[6].L.i + "' != '" + -53264 + "'",
                    value.equals(BigInteger.valueOf(-53264L)));
        } else {
            value = value.longValue();
            expected = -53264L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[6].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[6].P + "' != '" + 1987187803 + "'",
                    value.equals(BigInteger.valueOf(1987187803L)));
        } else {
            value = value.longValue();
            expected = 1987187803L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[6].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[6].cn0 + "' != '" + 52 + "'",
                    value.equals(BigInteger.valueOf(52L)));
        } else {
            value = value.longValue();
            expected = 52L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[6].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[6].lock + "' != '" + 15074 + "'",
                    value.equals(BigInteger.valueOf(15074L)));
        } else {
            value = value.longValue();
            expected = 15074L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[6].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[6].prn + "' != '" + 30 + "'",
                    value.equals(BigInteger.valueOf(30L)));
        } else {
            value = value.longValue();
            expected = 30L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test4() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_observation_msgObsDepATest.test4");
        byte[] payload =
                new byte[] {
                    (byte) 0, (byte) 159, (byte) 67, (byte) 24, (byte) 46, (byte) 7, (byte) 33,
                    (byte) 49, (byte) 19, (byte) 164, (byte) 117, (byte) 120, (byte) 32, (byte) 0,
                    (byte) 0, (byte) 222, (byte) 63, (byte) 62, (byte) 250, (byte) 31,
                };
        SBPMessage sbp = new SBPMessage(0x4c3, 0x45, payload);
        MsgObsDepA msg = new MsgObsDepA(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.header.n_obs;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.header.n_obs + "' != '" + 33 + "'",
                    value.equals(BigInteger.valueOf(33L)));
        } else {
            value = value.longValue();
            expected = 33L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.header.t.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.header.t.tow + "' != '" + 407084800 + "'",
                    value.equals(BigInteger.valueOf(407084800L)));
        } else {
            value = value.longValue();
            expected = 407084800L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.header.t.wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.header.t.wn + "' != '" + 1838 + "'",
                    value.equals(BigInteger.valueOf(1838L)));
        } else {
            value = value.longValue();
            expected = 1838L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].L.f + "' != '" + 222 + "'",
                    value.equals(BigInteger.valueOf(222L)));
        } else {
            value = value.longValue();
            expected = 222L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].L.i + "' != '" + 8312 + "'",
                    value.equals(BigInteger.valueOf(8312L)));
        } else {
            value = value.longValue();
            expected = 8312L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].P + "' != '" + 1973687089 + "'",
                    value.equals(BigInteger.valueOf(1973687089L)));
        } else {
            value = value.longValue();
            expected = 1973687089L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].cn0 + "' != '" + 63 + "'",
                    value.equals(BigInteger.valueOf(63L)));
        } else {
            value = value.longValue();
            expected = 63L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].lock + "' != '" + 64062 + "'",
                    value.equals(BigInteger.valueOf(64062L)));
        } else {
            value = value.longValue();
            expected = 64062L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].prn + "' != '" + 31 + "'",
                    value.equals(BigInteger.valueOf(31L)));
        } else {
            value = value.longValue();
            expected = 31L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test5() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_observation_msgObsDepATest.test5");
        byte[] payload =
                new byte[] {
                    (byte) 96,
                    (byte) 162,
                    (byte) 68,
                    (byte) 24,
                    (byte) 46,
                    (byte) 7,
                    (byte) 16,
                    (byte) 87,
                    (byte) 132,
                    (byte) 217,
                    (byte) 121,
                    (byte) 121,
                    (byte) 148,
                    (byte) 255,
                    (byte) 255,
                    (byte) 189,
                    (byte) 43,
                    (byte) 175,
                    (byte) 147,
                    (byte) 0,
                    (byte) 132,
                    (byte) 64,
                    (byte) 200,
                    (byte) 125,
                    (byte) 106,
                    (byte) 31,
                    (byte) 254,
                    (byte) 255,
                    (byte) 1,
                    (byte) 41,
                    (byte) 14,
                    (byte) 177,
                    (byte) 3,
                    (byte) 128,
                    (byte) 178,
                    (byte) 248,
                    (byte) 136,
                    (byte) 70,
                    (byte) 68,
                    (byte) 254,
                    (byte) 255,
                    (byte) 166,
                    (byte) 18,
                    (byte) 184,
                    (byte) 133,
                    (byte) 13,
                    (byte) 24,
                    (byte) 127,
                    (byte) 178,
                    (byte) 134,
                    (byte) 6,
                    (byte) 25,
                    (byte) 2,
                    (byte) 0,
                    (byte) 249,
                    (byte) 28,
                    (byte) 33,
                    (byte) 96,
                    (byte) 22,
                    (byte) 170,
                    (byte) 104,
                    (byte) 86,
                    (byte) 118,
                    (byte) 67,
                    (byte) 112,
                    (byte) 255,
                    (byte) 255,
                    (byte) 203,
                    (byte) 56,
                    (byte) 208,
                    (byte) 88,
                    (byte) 30,
                };
        SBPMessage sbp = new SBPMessage(0x4c3, 0x45, payload);
        MsgObsDepA msg = new MsgObsDepA(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.header.n_obs;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.header.n_obs + "' != '" + 16 + "'",
                    value.equals(BigInteger.valueOf(16L)));
        } else {
            value = value.longValue();
            expected = 16L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.header.t.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.header.t.tow + "' != '" + 407151200 + "'",
                    value.equals(BigInteger.valueOf(407151200L)));
        } else {
            value = value.longValue();
            expected = 407151200L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.header.t.wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.header.t.wn + "' != '" + 1838 + "'",
                    value.equals(BigInteger.valueOf(1838L)));
        } else {
            value = value.longValue();
            expected = 1838L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].L.f + "' != '" + 189 + "'",
                    value.equals(BigInteger.valueOf(189L)));
        } else {
            value = value.longValue();
            expected = 189L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].L.i + "' != '" + -27527 + "'",
                    value.equals(BigInteger.valueOf(-27527L)));
        } else {
            value = value.longValue();
            expected = -27527L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].P + "' != '" + 2044298327 + "'",
                    value.equals(BigInteger.valueOf(2044298327L)));
        } else {
            value = value.longValue();
            expected = 2044298327L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].cn0 + "' != '" + 43 + "'",
                    value.equals(BigInteger.valueOf(43L)));
        } else {
            value = value.longValue();
            expected = 43L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].lock + "' != '" + 37807 + "'",
                    value.equals(BigInteger.valueOf(37807L)));
        } else {
            value = value.longValue();
            expected = 37807L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].prn + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].L.f + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].L.i + "' != '" + -123030 + "'",
                    value.equals(BigInteger.valueOf(-123030L)));
        } else {
            value = value.longValue();
            expected = -123030L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].P + "' != '" + 2110275716 + "'",
                    value.equals(BigInteger.valueOf(2110275716L)));
        } else {
            value = value.longValue();
            expected = 2110275716L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].cn0 + "' != '" + 41 + "'",
                    value.equals(BigInteger.valueOf(41L)));
        } else {
            value = value.longValue();
            expected = 41L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].lock + "' != '" + 45326 + "'",
                    value.equals(BigInteger.valueOf(45326L)));
        } else {
            value = value.longValue();
            expected = 45326L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].prn + "' != '" + 3 + "'",
                    value.equals(BigInteger.valueOf(3L)));
        } else {
            value = value.longValue();
            expected = 3L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].L.f + "' != '" + 166 + "'",
                    value.equals(BigInteger.valueOf(166L)));
        } else {
            value = value.longValue();
            expected = 166L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].L.i + "' != '" + -113594 + "'",
                    value.equals(BigInteger.valueOf(-113594L)));
        } else {
            value = value.longValue();
            expected = -113594L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].P + "' != '" + 2298000000L + "'",
                    value.equals(new BigInteger("2298000000")));
        } else {
            value = value.longValue();
            expected = 2298000000L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].cn0 + "' != '" + 18 + "'",
                    value.equals(BigInteger.valueOf(18L)));
        } else {
            value = value.longValue();
            expected = 18L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].lock + "' != '" + 34232 + "'",
                    value.equals(BigInteger.valueOf(34232L)));
        } else {
            value = value.longValue();
            expected = 34232L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].prn + "' != '" + 13 + "'",
                    value.equals(BigInteger.valueOf(13L)));
        } else {
            value = value.longValue();
            expected = 13L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].L.f + "' != '" + 249 + "'",
                    value.equals(BigInteger.valueOf(249L)));
        } else {
            value = value.longValue();
            expected = 249L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].L.i + "' != '" + 137478 + "'",
                    value.equals(BigInteger.valueOf(137478L)));
        } else {
            value = value.longValue();
            expected = 137478L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].P + "' != '" + 2259844888L + "'",
                    value.equals(new BigInteger("2259844888")));
        } else {
            value = value.longValue();
            expected = 2259844888L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].cn0 + "' != '" + 28 + "'",
                    value.equals(BigInteger.valueOf(28L)));
        } else {
            value = value.longValue();
            expected = 28L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].lock + "' != '" + 24609 + "'",
                    value.equals(BigInteger.valueOf(24609L)));
        } else {
            value = value.longValue();
            expected = 24609L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].prn + "' != '" + 22 + "'",
                    value.equals(BigInteger.valueOf(22L)));
        } else {
            value = value.longValue();
            expected = 22L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].L.f + "' != '" + 203 + "'",
                    value.equals(BigInteger.valueOf(203L)));
        } else {
            value = value.longValue();
            expected = 203L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].L.i + "' != '" + -36797 + "'",
                    value.equals(BigInteger.valueOf(-36797L)));
        } else {
            value = value.longValue();
            expected = -36797L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].P + "' != '" + 1985374378 + "'",
                    value.equals(BigInteger.valueOf(1985374378L)));
        } else {
            value = value.longValue();
            expected = 1985374378L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].cn0 + "' != '" + 56 + "'",
                    value.equals(BigInteger.valueOf(56L)));
        } else {
            value = value.longValue();
            expected = 56L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].lock + "' != '" + 22736 + "'",
                    value.equals(BigInteger.valueOf(22736L)));
        } else {
            value = value.longValue();
            expected = 22736L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].prn + "' != '" + 30 + "'",
                    value.equals(BigInteger.valueOf(30L)));
        } else {
            value = value.longValue();
            expected = 30L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test6() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_observation_msgObsDepATest.test6");
        byte[] payload =
                new byte[] {
                    (byte) 40,
                    (byte) 163,
                    (byte) 68,
                    (byte) 24,
                    (byte) 46,
                    (byte) 7,
                    (byte) 16,
                    (byte) 132,
                    (byte) 107,
                    (byte) 217,
                    (byte) 121,
                    (byte) 14,
                    (byte) 148,
                    (byte) 255,
                    (byte) 255,
                    (byte) 1,
                    (byte) 44,
                    (byte) 175,
                    (byte) 147,
                    (byte) 0,
                    (byte) 129,
                    (byte) 66,
                    (byte) 200,
                    (byte) 125,
                    (byte) 148,
                    (byte) 29,
                    (byte) 254,
                    (byte) 255,
                    (byte) 153,
                    (byte) 41,
                    (byte) 14,
                    (byte) 177,
                    (byte) 3,
                    (byte) 128,
                    (byte) 178,
                    (byte) 248,
                    (byte) 136,
                    (byte) 143,
                    (byte) 66,
                    (byte) 254,
                    (byte) 255,
                    (byte) 222,
                    (byte) 18,
                    (byte) 184,
                    (byte) 133,
                    (byte) 13,
                    (byte) 158,
                    (byte) 53,
                    (byte) 178,
                    (byte) 134,
                    (byte) 42,
                    (byte) 27,
                    (byte) 2,
                    (byte) 0,
                    (byte) 237,
                    (byte) 30,
                    (byte) 33,
                    (byte) 96,
                    (byte) 22,
                    (byte) 38,
                    (byte) 83,
                    (byte) 86,
                    (byte) 118,
                    (byte) 168,
                    (byte) 111,
                    (byte) 255,
                    (byte) 255,
                    (byte) 45,
                    (byte) 56,
                    (byte) 208,
                    (byte) 88,
                    (byte) 30,
                };
        SBPMessage sbp = new SBPMessage(0x4c3, 0x45, payload);
        MsgObsDepA msg = new MsgObsDepA(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.header.n_obs;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.header.n_obs + "' != '" + 16 + "'",
                    value.equals(BigInteger.valueOf(16L)));
        } else {
            value = value.longValue();
            expected = 16L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.header.t.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.header.t.tow + "' != '" + 407151400 + "'",
                    value.equals(BigInteger.valueOf(407151400L)));
        } else {
            value = value.longValue();
            expected = 407151400L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.header.t.wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.header.t.wn + "' != '" + 1838 + "'",
                    value.equals(BigInteger.valueOf(1838L)));
        } else {
            value = value.longValue();
            expected = 1838L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].L.f + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].L.i + "' != '" + -27634 + "'",
                    value.equals(BigInteger.valueOf(-27634L)));
        } else {
            value = value.longValue();
            expected = -27634L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].P + "' != '" + 2044291972 + "'",
                    value.equals(BigInteger.valueOf(2044291972L)));
        } else {
            value = value.longValue();
            expected = 2044291972L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].cn0 + "' != '" + 44 + "'",
                    value.equals(BigInteger.valueOf(44L)));
        } else {
            value = value.longValue();
            expected = 44L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].lock + "' != '" + 37807 + "'",
                    value.equals(BigInteger.valueOf(37807L)));
        } else {
            value = value.longValue();
            expected = 37807L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].prn + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].L.f + "' != '" + 153 + "'",
                    value.equals(BigInteger.valueOf(153L)));
        } else {
            value = value.longValue();
            expected = 153L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].L.i + "' != '" + -123500 + "'",
                    value.equals(BigInteger.valueOf(-123500L)));
        } else {
            value = value.longValue();
            expected = -123500L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].P + "' != '" + 2110276225 + "'",
                    value.equals(BigInteger.valueOf(2110276225L)));
        } else {
            value = value.longValue();
            expected = 2110276225L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].cn0 + "' != '" + 41 + "'",
                    value.equals(BigInteger.valueOf(41L)));
        } else {
            value = value.longValue();
            expected = 41L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].lock + "' != '" + 45326 + "'",
                    value.equals(BigInteger.valueOf(45326L)));
        } else {
            value = value.longValue();
            expected = 45326L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].prn + "' != '" + 3 + "'",
                    value.equals(BigInteger.valueOf(3L)));
        } else {
            value = value.longValue();
            expected = 3L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].L.f + "' != '" + 222 + "'",
                    value.equals(BigInteger.valueOf(222L)));
        } else {
            value = value.longValue();
            expected = 222L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].L.i + "' != '" + -114033 + "'",
                    value.equals(BigInteger.valueOf(-114033L)));
        } else {
            value = value.longValue();
            expected = -114033L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].P + "' != '" + 2298000000L + "'",
                    value.equals(new BigInteger("2298000000")));
        } else {
            value = value.longValue();
            expected = 2298000000L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].cn0 + "' != '" + 18 + "'",
                    value.equals(BigInteger.valueOf(18L)));
        } else {
            value = value.longValue();
            expected = 18L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].lock + "' != '" + 34232 + "'",
                    value.equals(BigInteger.valueOf(34232L)));
        } else {
            value = value.longValue();
            expected = 34232L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].prn + "' != '" + 13 + "'",
                    value.equals(BigInteger.valueOf(13L)));
        } else {
            value = value.longValue();
            expected = 13L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].L.f + "' != '" + 237 + "'",
                    value.equals(BigInteger.valueOf(237L)));
        } else {
            value = value.longValue();
            expected = 237L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].L.i + "' != '" + 138026 + "'",
                    value.equals(BigInteger.valueOf(138026L)));
        } else {
            value = value.longValue();
            expected = 138026L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].P + "' != '" + 2259826078L + "'",
                    value.equals(new BigInteger("2259826078")));
        } else {
            value = value.longValue();
            expected = 2259826078L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].cn0 + "' != '" + 30 + "'",
                    value.equals(BigInteger.valueOf(30L)));
        } else {
            value = value.longValue();
            expected = 30L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].lock + "' != '" + 24609 + "'",
                    value.equals(BigInteger.valueOf(24609L)));
        } else {
            value = value.longValue();
            expected = 24609L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].prn + "' != '" + 22 + "'",
                    value.equals(BigInteger.valueOf(22L)));
        } else {
            value = value.longValue();
            expected = 22L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].L.f + "' != '" + 45 + "'",
                    value.equals(BigInteger.valueOf(45L)));
        } else {
            value = value.longValue();
            expected = 45L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].L.i + "' != '" + -36952 + "'",
                    value.equals(BigInteger.valueOf(-36952L)));
        } else {
            value = value.longValue();
            expected = -36952L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].P + "' != '" + 1985368870 + "'",
                    value.equals(BigInteger.valueOf(1985368870L)));
        } else {
            value = value.longValue();
            expected = 1985368870L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].cn0 + "' != '" + 56 + "'",
                    value.equals(BigInteger.valueOf(56L)));
        } else {
            value = value.longValue();
            expected = 56L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].lock + "' != '" + 22736 + "'",
                    value.equals(BigInteger.valueOf(22736L)));
        } else {
            value = value.longValue();
            expected = 22736L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].prn + "' != '" + 30 + "'",
                    value.equals(BigInteger.valueOf(30L)));
        } else {
            value = value.longValue();
            expected = 30L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }
}
