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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/observation/test_MsgObsDepC.yaml
// by generate.py. Do not modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.observation.MsgObsDepC;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_observation_MsgObsDepCTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_observation_MsgObsDepCTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 8,
                    (byte) 95,
                    (byte) 183,
                    (byte) 24,
                    (byte) 106,
                    (byte) 7,
                    (byte) 32,
                    (byte) 126,
                    (byte) 250,
                    (byte) 73,
                    (byte) 80,
                    (byte) 113,
                    (byte) 94,
                    (byte) 247,
                    (byte) 255,
                    (byte) 231,
                    (byte) 163,
                    (byte) 229,
                    (byte) 229,
                    (byte) 4,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 60,
                    (byte) 220,
                    (byte) 96,
                    (byte) 70,
                    (byte) 81,
                    (byte) 147,
                    (byte) 250,
                    (byte) 255,
                    (byte) 196,
                    (byte) 208,
                    (byte) 20,
                    (byte) 28,
                    (byte) 6,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 248,
                    (byte) 61,
                    (byte) 62,
                    (byte) 77,
                    (byte) 28,
                    (byte) 60,
                    (byte) 242,
                    (byte) 255,
                    (byte) 110,
                    (byte) 171,
                    (byte) 180,
                    (byte) 178,
                    (byte) 7,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 237,
                    (byte) 84,
                    (byte) 190,
                    (byte) 77,
                    (byte) 172,
                    (byte) 37,
                    (byte) 13,
                    (byte) 0,
                    (byte) 41,
                    (byte) 170,
                    (byte) 233,
                    (byte) 164,
                    (byte) 10,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 36,
                    (byte) 85,
                    (byte) 9,
                    (byte) 75,
                    (byte) 240,
                    (byte) 188,
                    (byte) 21,
                    (byte) 0,
                    (byte) 19,
                    (byte) 182,
                    (byte) 196,
                    (byte) 209,
                    (byte) 12,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x9846, 0x49, payload);
        MsgObsDepC msg = new MsgObsDepC(sbp);
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
                    "'" + msg.header.t.tow + "' != '" + 414670600 + "'",
                    value.equals(BigInteger.valueOf(414670600L)));
        } else {
            value = value.longValue();
            expected = 414670600L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.header.t.wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.header.t.wn + "' != '" + 1898 + "'",
                    value.equals(BigInteger.valueOf(1898L)));
        } else {
            value = value.longValue();
            expected = 1898L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].L.f + "' != '" + 231 + "'",
                    value.equals(BigInteger.valueOf(231L)));
        } else {
            value = value.longValue();
            expected = 231L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].L.i + "' != '" + -565647 + "'",
                    value.equals(BigInteger.valueOf(-565647L)));
        } else {
            value = value.longValue();
            expected = -565647L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].P + "' != '" + 1347025534 + "'",
                    value.equals(BigInteger.valueOf(1347025534L)));
        } else {
            value = value.longValue();
            expected = 1347025534L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].cn0 + "' != '" + 163 + "'",
                    value.equals(BigInteger.valueOf(163L)));
        } else {
            value = value.longValue();
            expected = 163L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].lock + "' != '" + 58853 + "'",
                    value.equals(BigInteger.valueOf(58853L)));
        } else {
            value = value.longValue();
            expected = 58853L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].sid.sat + "' != '" + 4 + "'",
                    value.equals(BigInteger.valueOf(4L)));
        } else {
            value = value.longValue();
            expected = 4L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].L.f + "' != '" + 196 + "'",
                    value.equals(BigInteger.valueOf(196L)));
        } else {
            value = value.longValue();
            expected = 196L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].L.i + "' != '" + -355503 + "'",
                    value.equals(BigInteger.valueOf(-355503L)));
        } else {
            value = value.longValue();
            expected = -355503L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].P + "' != '" + 1180752956 + "'",
                    value.equals(BigInteger.valueOf(1180752956L)));
        } else {
            value = value.longValue();
            expected = 1180752956L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].cn0 + "' != '" + 208 + "'",
                    value.equals(BigInteger.valueOf(208L)));
        } else {
            value = value.longValue();
            expected = 208L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].lock + "' != '" + 7188 + "'",
                    value.equals(BigInteger.valueOf(7188L)));
        } else {
            value = value.longValue();
            expected = 7188L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].sid.sat + "' != '" + 6 + "'",
                    value.equals(BigInteger.valueOf(6L)));
        } else {
            value = value.longValue();
            expected = 6L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].L.f + "' != '" + 110 + "'",
                    value.equals(BigInteger.valueOf(110L)));
        } else {
            value = value.longValue();
            expected = 110L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].L.i + "' != '" + -902116 + "'",
                    value.equals(BigInteger.valueOf(-902116L)));
        } else {
            value = value.longValue();
            expected = -902116L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].P + "' != '" + 1295924728 + "'",
                    value.equals(BigInteger.valueOf(1295924728L)));
        } else {
            value = value.longValue();
            expected = 1295924728L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].cn0 + "' != '" + 171 + "'",
                    value.equals(BigInteger.valueOf(171L)));
        } else {
            value = value.longValue();
            expected = 171L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].lock + "' != '" + 45748 + "'",
                    value.equals(BigInteger.valueOf(45748L)));
        } else {
            value = value.longValue();
            expected = 45748L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].sid.sat + "' != '" + 7 + "'",
                    value.equals(BigInteger.valueOf(7L)));
        } else {
            value = value.longValue();
            expected = 7L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].L.f + "' != '" + 41 + "'",
                    value.equals(BigInteger.valueOf(41L)));
        } else {
            value = value.longValue();
            expected = 41L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].L.i + "' != '" + 861612 + "'",
                    value.equals(BigInteger.valueOf(861612L)));
        } else {
            value = value.longValue();
            expected = 861612L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].P + "' != '" + 1304319213 + "'",
                    value.equals(BigInteger.valueOf(1304319213L)));
        } else {
            value = value.longValue();
            expected = 1304319213L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].cn0 + "' != '" + 170 + "'",
                    value.equals(BigInteger.valueOf(170L)));
        } else {
            value = value.longValue();
            expected = 170L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].lock + "' != '" + 42217 + "'",
                    value.equals(BigInteger.valueOf(42217L)));
        } else {
            value = value.longValue();
            expected = 42217L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].sid.sat + "' != '" + 10 + "'",
                    value.equals(BigInteger.valueOf(10L)));
        } else {
            value = value.longValue();
            expected = 10L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].L.f + "' != '" + 19 + "'",
                    value.equals(BigInteger.valueOf(19L)));
        } else {
            value = value.longValue();
            expected = 19L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].L.i + "' != '" + 1424624 + "'",
                    value.equals(BigInteger.valueOf(1424624L)));
        } else {
            value = value.longValue();
            expected = 1424624L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].P + "' != '" + 1258902820 + "'",
                    value.equals(BigInteger.valueOf(1258902820L)));
        } else {
            value = value.longValue();
            expected = 1258902820L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].cn0 + "' != '" + 182 + "'",
                    value.equals(BigInteger.valueOf(182L)));
        } else {
            value = value.longValue();
            expected = 182L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].lock + "' != '" + 53700 + "'",
                    value.equals(BigInteger.valueOf(53700L)));
        } else {
            value = value.longValue();
            expected = 53700L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].sid.sat + "' != '" + 12 + "'",
                    value.equals(BigInteger.valueOf(12L)));
        } else {
            value = value.longValue();
            expected = 12L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test2() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_observation_MsgObsDepCTest.test2");
        byte[] payload =
                new byte[] {
                    (byte) 8, (byte) 95, (byte) 183, (byte) 24, (byte) 106, (byte) 7, (byte) 33,
                    (byte) 68, (byte) 166, (byte) 75, (byte) 77, (byte) 186, (byte) 230, (byte) 24,
                    (byte) 0, (byte) 101, (byte) 186, (byte) 162, (byte) 102, (byte) 16, (byte) 0,
                    (byte) 0, (byte) 0, (byte) 87, (byte) 255, (byte) 155, (byte) 69, (byte) 74,
                    (byte) 158, (byte) 5, (byte) 0, (byte) 26, (byte) 190, (byte) 206, (byte) 30,
                    (byte) 27, (byte) 0, (byte) 0, (byte) 0, (byte) 64, (byte) 89, (byte) 124,
                    (byte) 68, (byte) 26, (byte) 22, (byte) 3, (byte) 0, (byte) 114, (byte) 217,
                    (byte) 225, (byte) 73, (byte) 29, (byte) 0, (byte) 0, (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x9846, 0x49, payload);
        MsgObsDepC msg = new MsgObsDepC(sbp);
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
                    "'" + msg.header.t.tow + "' != '" + 414670600 + "'",
                    value.equals(BigInteger.valueOf(414670600L)));
        } else {
            value = value.longValue();
            expected = 414670600L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.header.t.wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.header.t.wn + "' != '" + 1898 + "'",
                    value.equals(BigInteger.valueOf(1898L)));
        } else {
            value = value.longValue();
            expected = 1898L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].L.f + "' != '" + 101 + "'",
                    value.equals(BigInteger.valueOf(101L)));
        } else {
            value = value.longValue();
            expected = 101L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].L.i + "' != '" + 1631930 + "'",
                    value.equals(BigInteger.valueOf(1631930L)));
        } else {
            value = value.longValue();
            expected = 1631930L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].P + "' != '" + 1296803396 + "'",
                    value.equals(BigInteger.valueOf(1296803396L)));
        } else {
            value = value.longValue();
            expected = 1296803396L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].cn0 + "' != '" + 186 + "'",
                    value.equals(BigInteger.valueOf(186L)));
        } else {
            value = value.longValue();
            expected = 186L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].lock + "' != '" + 26274 + "'",
                    value.equals(BigInteger.valueOf(26274L)));
        } else {
            value = value.longValue();
            expected = 26274L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].sid.sat + "' != '" + 16 + "'",
                    value.equals(BigInteger.valueOf(16L)));
        } else {
            value = value.longValue();
            expected = 16L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].L.f + "' != '" + 26 + "'",
                    value.equals(BigInteger.valueOf(26L)));
        } else {
            value = value.longValue();
            expected = 26L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].L.i + "' != '" + 368202 + "'",
                    value.equals(BigInteger.valueOf(368202L)));
        } else {
            value = value.longValue();
            expected = 368202L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].P + "' != '" + 1167851351 + "'",
                    value.equals(BigInteger.valueOf(1167851351L)));
        } else {
            value = value.longValue();
            expected = 1167851351L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].cn0 + "' != '" + 190 + "'",
                    value.equals(BigInteger.valueOf(190L)));
        } else {
            value = value.longValue();
            expected = 190L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].lock + "' != '" + 7886 + "'",
                    value.equals(BigInteger.valueOf(7886L)));
        } else {
            value = value.longValue();
            expected = 7886L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].sid.sat + "' != '" + 27 + "'",
                    value.equals(BigInteger.valueOf(27L)));
        } else {
            value = value.longValue();
            expected = 27L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].L.f + "' != '" + 114 + "'",
                    value.equals(BigInteger.valueOf(114L)));
        } else {
            value = value.longValue();
            expected = 114L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].L.i + "' != '" + 202266 + "'",
                    value.equals(BigInteger.valueOf(202266L)));
        } else {
            value = value.longValue();
            expected = 202266L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].P + "' != '" + 1149000000 + "'",
                    value.equals(BigInteger.valueOf(1149000000L)));
        } else {
            value = value.longValue();
            expected = 1149000000L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].cn0 + "' != '" + 217 + "'",
                    value.equals(BigInteger.valueOf(217L)));
        } else {
            value = value.longValue();
            expected = 217L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].lock + "' != '" + 18913 + "'",
                    value.equals(BigInteger.valueOf(18913L)));
        } else {
            value = value.longValue();
            expected = 18913L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].sid.sat + "' != '" + 29 + "'",
                    value.equals(BigInteger.valueOf(29L)));
        } else {
            value = value.longValue();
            expected = 29L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test3() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_observation_MsgObsDepCTest.test3");
        byte[] payload =
                new byte[] {
                    (byte) 8,
                    (byte) 95,
                    (byte) 183,
                    (byte) 24,
                    (byte) 106,
                    (byte) 7,
                    (byte) 32,
                    (byte) 217,
                    (byte) 251,
                    (byte) 73,
                    (byte) 80,
                    (byte) 9,
                    (byte) 72,
                    (byte) 248,
                    (byte) 255,
                    (byte) 30,
                    (byte) 168,
                    (byte) 113,
                    (byte) 81,
                    (byte) 4,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 211,
                    (byte) 220,
                    (byte) 96,
                    (byte) 70,
                    (byte) 198,
                    (byte) 107,
                    (byte) 251,
                    (byte) 255,
                    (byte) 115,
                    (byte) 195,
                    (byte) 53,
                    (byte) 144,
                    (byte) 6,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 77,
                    (byte) 61,
                    (byte) 62,
                    (byte) 77,
                    (byte) 40,
                    (byte) 161,
                    (byte) 243,
                    (byte) 255,
                    (byte) 130,
                    (byte) 176,
                    (byte) 93,
                    (byte) 142,
                    (byte) 7,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 1,
                    (byte) 86,
                    (byte) 190,
                    (byte) 77,
                    (byte) 88,
                    (byte) 77,
                    (byte) 12,
                    (byte) 0,
                    (byte) 116,
                    (byte) 199,
                    (byte) 229,
                    (byte) 213,
                    (byte) 10,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 93,
                    (byte) 85,
                    (byte) 9,
                    (byte) 75,
                    (byte) 64,
                    (byte) 139,
                    (byte) 20,
                    (byte) 0,
                    (byte) 120,
                    (byte) 177,
                    (byte) 196,
                    (byte) 194,
                    (byte) 12,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x0, 0x49, payload);
        MsgObsDepC msg = new MsgObsDepC(sbp);
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
                    "'" + msg.header.t.tow + "' != '" + 414670600 + "'",
                    value.equals(BigInteger.valueOf(414670600L)));
        } else {
            value = value.longValue();
            expected = 414670600L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.header.t.wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.header.t.wn + "' != '" + 1898 + "'",
                    value.equals(BigInteger.valueOf(1898L)));
        } else {
            value = value.longValue();
            expected = 1898L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].L.f + "' != '" + 30 + "'",
                    value.equals(BigInteger.valueOf(30L)));
        } else {
            value = value.longValue();
            expected = 30L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].L.i + "' != '" + -505847 + "'",
                    value.equals(BigInteger.valueOf(-505847L)));
        } else {
            value = value.longValue();
            expected = -505847L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].P + "' != '" + 1347025881 + "'",
                    value.equals(BigInteger.valueOf(1347025881L)));
        } else {
            value = value.longValue();
            expected = 1347025881L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].cn0 + "' != '" + 168 + "'",
                    value.equals(BigInteger.valueOf(168L)));
        } else {
            value = value.longValue();
            expected = 168L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].lock + "' != '" + 20849 + "'",
                    value.equals(BigInteger.valueOf(20849L)));
        } else {
            value = value.longValue();
            expected = 20849L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].sid.sat + "' != '" + 4 + "'",
                    value.equals(BigInteger.valueOf(4L)));
        } else {
            value = value.longValue();
            expected = 4L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].L.f + "' != '" + 115 + "'",
                    value.equals(BigInteger.valueOf(115L)));
        } else {
            value = value.longValue();
            expected = 115L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].L.i + "' != '" + -300090 + "'",
                    value.equals(BigInteger.valueOf(-300090L)));
        } else {
            value = value.longValue();
            expected = -300090L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].P + "' != '" + 1180753107 + "'",
                    value.equals(BigInteger.valueOf(1180753107L)));
        } else {
            value = value.longValue();
            expected = 1180753107L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].cn0 + "' != '" + 195 + "'",
                    value.equals(BigInteger.valueOf(195L)));
        } else {
            value = value.longValue();
            expected = 195L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].lock + "' != '" + 36917 + "'",
                    value.equals(BigInteger.valueOf(36917L)));
        } else {
            value = value.longValue();
            expected = 36917L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].sid.sat + "' != '" + 6 + "'",
                    value.equals(BigInteger.valueOf(6L)));
        } else {
            value = value.longValue();
            expected = 6L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].L.f + "' != '" + 130 + "'",
                    value.equals(BigInteger.valueOf(130L)));
        } else {
            value = value.longValue();
            expected = 130L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].L.i + "' != '" + -810712 + "'",
                    value.equals(BigInteger.valueOf(-810712L)));
        } else {
            value = value.longValue();
            expected = -810712L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].P + "' != '" + 1295924557 + "'",
                    value.equals(BigInteger.valueOf(1295924557L)));
        } else {
            value = value.longValue();
            expected = 1295924557L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].cn0 + "' != '" + 176 + "'",
                    value.equals(BigInteger.valueOf(176L)));
        } else {
            value = value.longValue();
            expected = 176L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].lock + "' != '" + 36445 + "'",
                    value.equals(BigInteger.valueOf(36445L)));
        } else {
            value = value.longValue();
            expected = 36445L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].sid.sat + "' != '" + 7 + "'",
                    value.equals(BigInteger.valueOf(7L)));
        } else {
            value = value.longValue();
            expected = 7L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].L.f + "' != '" + 116 + "'",
                    value.equals(BigInteger.valueOf(116L)));
        } else {
            value = value.longValue();
            expected = 116L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].L.i + "' != '" + 806232 + "'",
                    value.equals(BigInteger.valueOf(806232L)));
        } else {
            value = value.longValue();
            expected = 806232L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].P + "' != '" + 1304319489 + "'",
                    value.equals(BigInteger.valueOf(1304319489L)));
        } else {
            value = value.longValue();
            expected = 1304319489L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].cn0 + "' != '" + 199 + "'",
                    value.equals(BigInteger.valueOf(199L)));
        } else {
            value = value.longValue();
            expected = 199L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].lock + "' != '" + 54757 + "'",
                    value.equals(BigInteger.valueOf(54757L)));
        } else {
            value = value.longValue();
            expected = 54757L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].sid.sat + "' != '" + 10 + "'",
                    value.equals(BigInteger.valueOf(10L)));
        } else {
            value = value.longValue();
            expected = 10L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].L.f + "' != '" + 120 + "'",
                    value.equals(BigInteger.valueOf(120L)));
        } else {
            value = value.longValue();
            expected = 120L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].L.i + "' != '" + 1346368 + "'",
                    value.equals(BigInteger.valueOf(1346368L)));
        } else {
            value = value.longValue();
            expected = 1346368L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].P + "' != '" + 1258902877 + "'",
                    value.equals(BigInteger.valueOf(1258902877L)));
        } else {
            value = value.longValue();
            expected = 1258902877L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].cn0 + "' != '" + 177 + "'",
                    value.equals(BigInteger.valueOf(177L)));
        } else {
            value = value.longValue();
            expected = 177L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].lock + "' != '" + 49860 + "'",
                    value.equals(BigInteger.valueOf(49860L)));
        } else {
            value = value.longValue();
            expected = 49860L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].sid.sat + "' != '" + 12 + "'",
                    value.equals(BigInteger.valueOf(12L)));
        } else {
            value = value.longValue();
            expected = 12L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test4() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_observation_MsgObsDepCTest.test4");
        byte[] payload =
                new byte[] {
                    (byte) 8, (byte) 95, (byte) 183, (byte) 24, (byte) 106, (byte) 7, (byte) 33,
                    (byte) 70, (byte) 167, (byte) 75, (byte) 77, (byte) 140, (byte) 136, (byte) 23,
                    (byte) 0, (byte) 90, (byte) 187, (byte) 158, (byte) 129, (byte) 16, (byte) 0,
                    (byte) 0, (byte) 0, (byte) 232, (byte) 255, (byte) 155, (byte) 69, (byte) 45,
                    (byte) 175, (byte) 5, (byte) 0, (byte) 17, (byte) 208, (byte) 175, (byte) 56,
                    (byte) 27, (byte) 0, (byte) 0, (byte) 0, (byte) 64, (byte) 89, (byte) 124,
                    (byte) 68, (byte) 45, (byte) 96, (byte) 3, (byte) 0, (byte) 75, (byte) 185,
                    (byte) 73, (byte) 206, (byte) 29, (byte) 0, (byte) 0, (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x0, 0x49, payload);
        MsgObsDepC msg = new MsgObsDepC(sbp);
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
                    "'" + msg.header.t.tow + "' != '" + 414670600 + "'",
                    value.equals(BigInteger.valueOf(414670600L)));
        } else {
            value = value.longValue();
            expected = 414670600L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.header.t.wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.header.t.wn + "' != '" + 1898 + "'",
                    value.equals(BigInteger.valueOf(1898L)));
        } else {
            value = value.longValue();
            expected = 1898L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].L.f + "' != '" + 90 + "'",
                    value.equals(BigInteger.valueOf(90L)));
        } else {
            value = value.longValue();
            expected = 90L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].L.i + "' != '" + 1542284 + "'",
                    value.equals(BigInteger.valueOf(1542284L)));
        } else {
            value = value.longValue();
            expected = 1542284L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].P + "' != '" + 1296803654 + "'",
                    value.equals(BigInteger.valueOf(1296803654L)));
        } else {
            value = value.longValue();
            expected = 1296803654L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].cn0 + "' != '" + 187 + "'",
                    value.equals(BigInteger.valueOf(187L)));
        } else {
            value = value.longValue();
            expected = 187L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].lock + "' != '" + 33182 + "'",
                    value.equals(BigInteger.valueOf(33182L)));
        } else {
            value = value.longValue();
            expected = 33182L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].sid.sat + "' != '" + 16 + "'",
                    value.equals(BigInteger.valueOf(16L)));
        } else {
            value = value.longValue();
            expected = 16L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].L.f + "' != '" + 17 + "'",
                    value.equals(BigInteger.valueOf(17L)));
        } else {
            value = value.longValue();
            expected = 17L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].L.i + "' != '" + 372525 + "'",
                    value.equals(BigInteger.valueOf(372525L)));
        } else {
            value = value.longValue();
            expected = 372525L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].P + "' != '" + 1167851496 + "'",
                    value.equals(BigInteger.valueOf(1167851496L)));
        } else {
            value = value.longValue();
            expected = 1167851496L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].cn0 + "' != '" + 208 + "'",
                    value.equals(BigInteger.valueOf(208L)));
        } else {
            value = value.longValue();
            expected = 208L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].lock + "' != '" + 14511 + "'",
                    value.equals(BigInteger.valueOf(14511L)));
        } else {
            value = value.longValue();
            expected = 14511L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].sid.sat + "' != '" + 27 + "'",
                    value.equals(BigInteger.valueOf(27L)));
        } else {
            value = value.longValue();
            expected = 27L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].L.f + "' != '" + 75 + "'",
                    value.equals(BigInteger.valueOf(75L)));
        } else {
            value = value.longValue();
            expected = 75L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].L.i + "' != '" + 221229 + "'",
                    value.equals(BigInteger.valueOf(221229L)));
        } else {
            value = value.longValue();
            expected = 221229L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].P + "' != '" + 1149000000 + "'",
                    value.equals(BigInteger.valueOf(1149000000L)));
        } else {
            value = value.longValue();
            expected = 1149000000L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].cn0 + "' != '" + 185 + "'",
                    value.equals(BigInteger.valueOf(185L)));
        } else {
            value = value.longValue();
            expected = 185L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].lock + "' != '" + 52809 + "'",
                    value.equals(BigInteger.valueOf(52809L)));
        } else {
            value = value.longValue();
            expected = 52809L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].sid.sat + "' != '" + 29 + "'",
                    value.equals(BigInteger.valueOf(29L)));
        } else {
            value = value.longValue();
            expected = 29L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test5() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_observation_MsgObsDepCTest.test5");
        byte[] payload =
                new byte[] {
                    (byte) 208,
                    (byte) 95,
                    (byte) 183,
                    (byte) 24,
                    (byte) 106,
                    (byte) 7,
                    (byte) 32,
                    (byte) 44,
                    (byte) 8,
                    (byte) 74,
                    (byte) 80,
                    (byte) 86,
                    (byte) 93,
                    (byte) 247,
                    (byte) 255,
                    (byte) 57,
                    (byte) 158,
                    (byte) 229,
                    (byte) 229,
                    (byte) 4,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 224,
                    (byte) 229,
                    (byte) 96,
                    (byte) 70,
                    (byte) 156,
                    (byte) 146,
                    (byte) 250,
                    (byte) 255,
                    (byte) 221,
                    (byte) 200,
                    (byte) 20,
                    (byte) 28,
                    (byte) 6,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 60,
                    (byte) 82,
                    (byte) 62,
                    (byte) 77,
                    (byte) 93,
                    (byte) 58,
                    (byte) 242,
                    (byte) 255,
                    (byte) 39,
                    (byte) 164,
                    (byte) 180,
                    (byte) 178,
                    (byte) 7,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 222,
                    (byte) 73,
                    (byte) 190,
                    (byte) 77,
                    (byte) 46,
                    (byte) 39,
                    (byte) 13,
                    (byte) 0,
                    (byte) 202,
                    (byte) 181,
                    (byte) 233,
                    (byte) 164,
                    (byte) 10,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 149,
                    (byte) 64,
                    (byte) 9,
                    (byte) 75,
                    (byte) 114,
                    (byte) 191,
                    (byte) 21,
                    (byte) 0,
                    (byte) 249,
                    (byte) 182,
                    (byte) 196,
                    (byte) 209,
                    (byte) 12,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x9846, 0x49, payload);
        MsgObsDepC msg = new MsgObsDepC(sbp);
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
                    "'" + msg.header.t.tow + "' != '" + 414670800 + "'",
                    value.equals(BigInteger.valueOf(414670800L)));
        } else {
            value = value.longValue();
            expected = 414670800L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.header.t.wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.header.t.wn + "' != '" + 1898 + "'",
                    value.equals(BigInteger.valueOf(1898L)));
        } else {
            value = value.longValue();
            expected = 1898L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].L.f + "' != '" + 57 + "'",
                    value.equals(BigInteger.valueOf(57L)));
        } else {
            value = value.longValue();
            expected = 57L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].L.i + "' != '" + -565930 + "'",
                    value.equals(BigInteger.valueOf(-565930L)));
        } else {
            value = value.longValue();
            expected = -565930L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].P + "' != '" + 1347029036 + "'",
                    value.equals(BigInteger.valueOf(1347029036L)));
        } else {
            value = value.longValue();
            expected = 1347029036L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].cn0 + "' != '" + 158 + "'",
                    value.equals(BigInteger.valueOf(158L)));
        } else {
            value = value.longValue();
            expected = 158L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].lock + "' != '" + 58853 + "'",
                    value.equals(BigInteger.valueOf(58853L)));
        } else {
            value = value.longValue();
            expected = 58853L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].sid.sat + "' != '" + 4 + "'",
                    value.equals(BigInteger.valueOf(4L)));
        } else {
            value = value.longValue();
            expected = 4L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].L.f + "' != '" + 221 + "'",
                    value.equals(BigInteger.valueOf(221L)));
        } else {
            value = value.longValue();
            expected = 221L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].L.i + "' != '" + -355684 + "'",
                    value.equals(BigInteger.valueOf(-355684L)));
        } else {
            value = value.longValue();
            expected = -355684L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].P + "' != '" + 1180755424 + "'",
                    value.equals(BigInteger.valueOf(1180755424L)));
        } else {
            value = value.longValue();
            expected = 1180755424L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].cn0 + "' != '" + 200 + "'",
                    value.equals(BigInteger.valueOf(200L)));
        } else {
            value = value.longValue();
            expected = 200L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].lock + "' != '" + 7188 + "'",
                    value.equals(BigInteger.valueOf(7188L)));
        } else {
            value = value.longValue();
            expected = 7188L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].sid.sat + "' != '" + 6 + "'",
                    value.equals(BigInteger.valueOf(6L)));
        } else {
            value = value.longValue();
            expected = 6L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].L.f + "' != '" + 39 + "'",
                    value.equals(BigInteger.valueOf(39L)));
        } else {
            value = value.longValue();
            expected = 39L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].L.i + "' != '" + -902563 + "'",
                    value.equals(BigInteger.valueOf(-902563L)));
        } else {
            value = value.longValue();
            expected = -902563L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].P + "' != '" + 1295929916 + "'",
                    value.equals(BigInteger.valueOf(1295929916L)));
        } else {
            value = value.longValue();
            expected = 1295929916L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].cn0 + "' != '" + 164 + "'",
                    value.equals(BigInteger.valueOf(164L)));
        } else {
            value = value.longValue();
            expected = 164L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].lock + "' != '" + 45748 + "'",
                    value.equals(BigInteger.valueOf(45748L)));
        } else {
            value = value.longValue();
            expected = 45748L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].sid.sat + "' != '" + 7 + "'",
                    value.equals(BigInteger.valueOf(7L)));
        } else {
            value = value.longValue();
            expected = 7L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].L.f + "' != '" + 202 + "'",
                    value.equals(BigInteger.valueOf(202L)));
        } else {
            value = value.longValue();
            expected = 202L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].L.i + "' != '" + 861998 + "'",
                    value.equals(BigInteger.valueOf(861998L)));
        } else {
            value = value.longValue();
            expected = 861998L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].P + "' != '" + 1304316382 + "'",
                    value.equals(BigInteger.valueOf(1304316382L)));
        } else {
            value = value.longValue();
            expected = 1304316382L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].cn0 + "' != '" + 181 + "'",
                    value.equals(BigInteger.valueOf(181L)));
        } else {
            value = value.longValue();
            expected = 181L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].lock + "' != '" + 42217 + "'",
                    value.equals(BigInteger.valueOf(42217L)));
        } else {
            value = value.longValue();
            expected = 42217L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].sid.sat + "' != '" + 10 + "'",
                    value.equals(BigInteger.valueOf(10L)));
        } else {
            value = value.longValue();
            expected = 10L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].L.f + "' != '" + 249 + "'",
                    value.equals(BigInteger.valueOf(249L)));
        } else {
            value = value.longValue();
            expected = 249L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].L.i + "' != '" + 1425266 + "'",
                    value.equals(BigInteger.valueOf(1425266L)));
        } else {
            value = value.longValue();
            expected = 1425266L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].P + "' != '" + 1258897557 + "'",
                    value.equals(BigInteger.valueOf(1258897557L)));
        } else {
            value = value.longValue();
            expected = 1258897557L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].cn0 + "' != '" + 182 + "'",
                    value.equals(BigInteger.valueOf(182L)));
        } else {
            value = value.longValue();
            expected = 182L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].lock + "' != '" + 53700 + "'",
                    value.equals(BigInteger.valueOf(53700L)));
        } else {
            value = value.longValue();
            expected = 53700L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].sid.sat + "' != '" + 12 + "'",
                    value.equals(BigInteger.valueOf(12L)));
        } else {
            value = value.longValue();
            expected = 12L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }
}
