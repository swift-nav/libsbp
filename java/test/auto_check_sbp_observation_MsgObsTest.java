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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/observation/test_MsgObs.yaml by
// generate.py. Do not modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.observation.MsgObs;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_observation_MsgObsTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_observation_MsgObsTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 152,
                    (byte) 202,
                    (byte) 226,
                    (byte) 25,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 106,
                    (byte) 8,
                    (byte) 32,
                    (byte) 49,
                    (byte) 227,
                    (byte) 254,
                    (byte) 62,
                    (byte) 121,
                    (byte) 242,
                    (byte) 158,
                    (byte) 6,
                    (byte) 146,
                    (byte) 0,
                    (byte) 250,
                    (byte) 172,
                    (byte) 182,
                    (byte) 10,
                    (byte) 15,
                    (byte) 10,
                    (byte) 0,
                    (byte) 30,
                    (byte) 228,
                    (byte) 254,
                    (byte) 62,
                    (byte) 12,
                    (byte) 189,
                    (byte) 40,
                    (byte) 5,
                    (byte) 59,
                    (byte) 83,
                    (byte) 251,
                    (byte) 172,
                    (byte) 178,
                    (byte) 10,
                    (byte) 15,
                    (byte) 10,
                    (byte) 1,
                    (byte) 215,
                    (byte) 205,
                    (byte) 144,
                    (byte) 72,
                    (byte) 106,
                    (byte) 111,
                    (byte) 160,
                    (byte) 7,
                    (byte) 243,
                    (byte) 109,
                    (byte) 243,
                    (byte) 119,
                    (byte) 158,
                    (byte) 10,
                    (byte) 15,
                    (byte) 18,
                    (byte) 0,
                    (byte) 25,
                    (byte) 207,
                    (byte) 144,
                    (byte) 72,
                    (byte) 223,
                    (byte) 96,
                    (byte) 241,
                    (byte) 5,
                    (byte) 12,
                    (byte) 52,
                    (byte) 246,
                    (byte) 27,
                    (byte) 125,
                    (byte) 9,
                    (byte) 11,
                    (byte) 18,
                    (byte) 1,
                    (byte) 34,
                    (byte) 184,
                    (byte) 223,
                    (byte) 74,
                    (byte) 150,
                    (byte) 138,
                    (byte) 222,
                    (byte) 7,
                    (byte) 53,
                    (byte) 13,
                    (byte) 11,
                    (byte) 245,
                    (byte) 114,
                    (byte) 9,
                    (byte) 15,
                    (byte) 22,
                    (byte) 0,
                    (byte) 113,
                    (byte) 80,
                    (byte) 6,
                    (byte) 69,
                    (byte) 162,
                    (byte) 41,
                    (byte) 65,
                    (byte) 7,
                    (byte) 70,
                    (byte) 127,
                    (byte) 246,
                    (byte) 246,
                    (byte) 189,
                    (byte) 9,
                    (byte) 15,
                    (byte) 23,
                    (byte) 0,
                    (byte) 247,
                    (byte) 80,
                    (byte) 6,
                    (byte) 69,
                    (byte) 213,
                    (byte) 35,
                    (byte) 167,
                    (byte) 5,
                    (byte) 221,
                    (byte) 152,
                    (byte) 248,
                    (byte) 231,
                    (byte) 158,
                    (byte) 9,
                    (byte) 11,
                    (byte) 23,
                    (byte) 1,
                    (byte) 8,
                    (byte) 146,
                    (byte) 166,
                    (byte) 64,
                    (byte) 12,
                    (byte) 122,
                    (byte) 203,
                    (byte) 6,
                    (byte) 114,
                    (byte) 51,
                    (byte) 248,
                    (byte) 67,
                    (byte) 93,
                    (byte) 3,
                    (byte) 11,
                    (byte) 27,
                    (byte) 0,
                    (byte) 221,
                    (byte) 172,
                    (byte) 173,
                    (byte) 75,
                    (byte) 217,
                    (byte) 47,
                    (byte) 244,
                    (byte) 7,
                    (byte) 232,
                    (byte) 225,
                    (byte) 11,
                    (byte) 237,
                    (byte) 123,
                    (byte) 5,
                    (byte) 15,
                    (byte) 31,
                    (byte) 0,
                    (byte) 250,
                    (byte) 174,
                    (byte) 173,
                    (byte) 75,
                    (byte) 216,
                    (byte) 163,
                    (byte) 50,
                    (byte) 6,
                    (byte) 40,
                    (byte) 70,
                    (byte) 9,
                    (byte) 62,
                    (byte) 120,
                    (byte) 3,
                    (byte) 11,
                    (byte) 31,
                    (byte) 1,
                    (byte) 135,
                    (byte) 16,
                    (byte) 6,
                    (byte) 66,
                    (byte) 99,
                    (byte) 218,
                    (byte) 11,
                    (byte) 7,
                    (byte) 7,
                    (byte) 138,
                    (byte) 242,
                    (byte) 96,
                    (byte) 176,
                    (byte) 10,
                    (byte) 15,
                    (byte) 2,
                    (byte) 3,
                    (byte) 148,
                    (byte) 130,
                    (byte) 6,
                    (byte) 58,
                    (byte) 217,
                    (byte) 88,
                    (byte) 54,
                    (byte) 6,
                    (byte) 203,
                    (byte) 21,
                    (byte) 252,
                    (byte) 96,
                    (byte) 170,
                    (byte) 10,
                    (byte) 15,
                    (byte) 3,
                    (byte) 3,
                    (byte) 186,
                    (byte) 108,
                    (byte) 197,
                    (byte) 63,
                    (byte) 127,
                    (byte) 54,
                    (byte) 211,
                    (byte) 6,
                    (byte) 80,
                    (byte) 4,
                    (byte) 241,
                    (byte) 219,
                    (byte) 200,
                    (byte) 10,
                    (byte) 15,
                    (byte) 17,
                    (byte) 3,
                    (byte) 167,
                    (byte) 195,
                    (byte) 8,
                    (byte) 57,
                    (byte) 19,
                    (byte) 204,
                    (byte) 22,
                    (byte) 6,
                    (byte) 105,
                    (byte) 51,
                    (byte) 254,
                    (byte) 182,
                    (byte) 152,
                    (byte) 10,
                    (byte) 15,
                    (byte) 18,
                    (byte) 3,
                };
        SBPMessage sbp = new SBPMessage(0xf081, 0x4a, payload);
        MsgObs msg = new MsgObs(sbp);
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
        value = msg.header.t.ns_residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.header.t.ns_residual + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.header.t.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.header.t.tow + "' != '" + 434293400 + "'",
                    value.equals(BigInteger.valueOf(434293400L)));
        } else {
            value = value.longValue();
            expected = 434293400L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.header.t.wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.header.t.wn + "' != '" + 2154 + "'",
                    value.equals(BigInteger.valueOf(2154L)));
        } else {
            value = value.longValue();
            expected = 2154L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].D.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].D.f + "' != '" + 172 + "'",
                    value.equals(BigInteger.valueOf(172L)));
        } else {
            value = value.longValue();
            expected = 172L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].D.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].D.i + "' != '" + -1536 + "'",
                    value.equals(BigInteger.valueOf(-1536L)));
        } else {
            value = value.longValue();
            expected = -1536L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].L.f + "' != '" + 146 + "'",
                    value.equals(BigInteger.valueOf(146L)));
        } else {
            value = value.longValue();
            expected = 146L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].L.i + "' != '" + 111080057 + "'",
                    value.equals(BigInteger.valueOf(111080057L)));
        } else {
            value = value.longValue();
            expected = 111080057L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].P + "' != '" + 1056891697 + "'",
                    value.equals(BigInteger.valueOf(1056891697L)));
        } else {
            value = value.longValue();
            expected = 1056891697L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].cn0 + "' != '" + 182 + "'",
                    value.equals(BigInteger.valueOf(182L)));
        } else {
            value = value.longValue();
            expected = 182L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].flags + "' != '" + 15 + "'",
                    value.equals(BigInteger.valueOf(15L)));
        } else {
            value = value.longValue();
            expected = 15L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[0].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].lock + "' != '" + 10 + "'",
                    value.equals(BigInteger.valueOf(10L)));
        } else {
            value = value.longValue();
            expected = 10L;
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
        value = msg.obs[0].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[0].sid.sat + "' != '" + 10 + "'",
                    value.equals(BigInteger.valueOf(10L)));
        } else {
            value = value.longValue();
            expected = 10L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].D.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].D.f + "' != '" + 172 + "'",
                    value.equals(BigInteger.valueOf(172L)));
        } else {
            value = value.longValue();
            expected = 172L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].D.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].D.i + "' != '" + -1197 + "'",
                    value.equals(BigInteger.valueOf(-1197L)));
        } else {
            value = value.longValue();
            expected = -1197L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].L.f + "' != '" + 59 + "'",
                    value.equals(BigInteger.valueOf(59L)));
        } else {
            value = value.longValue();
            expected = 59L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].L.i + "' != '" + 86555916 + "'",
                    value.equals(BigInteger.valueOf(86555916L)));
        } else {
            value = value.longValue();
            expected = 86555916L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].P + "' != '" + 1056891934 + "'",
                    value.equals(BigInteger.valueOf(1056891934L)));
        } else {
            value = value.longValue();
            expected = 1056891934L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].cn0 + "' != '" + 178 + "'",
                    value.equals(BigInteger.valueOf(178L)));
        } else {
            value = value.longValue();
            expected = 178L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].flags + "' != '" + 15 + "'",
                    value.equals(BigInteger.valueOf(15L)));
        } else {
            value = value.longValue();
            expected = 15L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].lock + "' != '" + 10 + "'",
                    value.equals(BigInteger.valueOf(10L)));
        } else {
            value = value.longValue();
            expected = 10L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].sid.code + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[1].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[1].sid.sat + "' != '" + 10 + "'",
                    value.equals(BigInteger.valueOf(10L)));
        } else {
            value = value.longValue();
            expected = 10L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].D.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].D.f + "' != '" + 119 + "'",
                    value.equals(BigInteger.valueOf(119L)));
        } else {
            value = value.longValue();
            expected = 119L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].D.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].D.i + "' != '" + -3219 + "'",
                    value.equals(BigInteger.valueOf(-3219L)));
        } else {
            value = value.longValue();
            expected = -3219L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].L.f + "' != '" + 243 + "'",
                    value.equals(BigInteger.valueOf(243L)));
        } else {
            value = value.longValue();
            expected = 243L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].L.i + "' != '" + 127954794 + "'",
                    value.equals(BigInteger.valueOf(127954794L)));
        } else {
            value = value.longValue();
            expected = 127954794L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].P + "' != '" + 1217449431 + "'",
                    value.equals(BigInteger.valueOf(1217449431L)));
        } else {
            value = value.longValue();
            expected = 1217449431L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].cn0 + "' != '" + 158 + "'",
                    value.equals(BigInteger.valueOf(158L)));
        } else {
            value = value.longValue();
            expected = 158L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].flags + "' != '" + 15 + "'",
                    value.equals(BigInteger.valueOf(15L)));
        } else {
            value = value.longValue();
            expected = 15L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[2].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].lock + "' != '" + 10 + "'",
                    value.equals(BigInteger.valueOf(10L)));
        } else {
            value = value.longValue();
            expected = 10L;
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
        value = msg.obs[2].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[2].sid.sat + "' != '" + 18 + "'",
                    value.equals(BigInteger.valueOf(18L)));
        } else {
            value = value.longValue();
            expected = 18L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].D.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].D.f + "' != '" + 27 + "'",
                    value.equals(BigInteger.valueOf(27L)));
        } else {
            value = value.longValue();
            expected = 27L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].D.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].D.i + "' != '" + -2508 + "'",
                    value.equals(BigInteger.valueOf(-2508L)));
        } else {
            value = value.longValue();
            expected = -2508L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].L.f + "' != '" + 12 + "'",
                    value.equals(BigInteger.valueOf(12L)));
        } else {
            value = value.longValue();
            expected = 12L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].L.i + "' != '" + 99705055 + "'",
                    value.equals(BigInteger.valueOf(99705055L)));
        } else {
            value = value.longValue();
            expected = 99705055L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].P + "' != '" + 1217449753 + "'",
                    value.equals(BigInteger.valueOf(1217449753L)));
        } else {
            value = value.longValue();
            expected = 1217449753L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].cn0 + "' != '" + 125 + "'",
                    value.equals(BigInteger.valueOf(125L)));
        } else {
            value = value.longValue();
            expected = 125L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].flags + "' != '" + 11 + "'",
                    value.equals(BigInteger.valueOf(11L)));
        } else {
            value = value.longValue();
            expected = 11L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].lock + "' != '" + 9 + "'",
                    value.equals(BigInteger.valueOf(9L)));
        } else {
            value = value.longValue();
            expected = 9L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].sid.code + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[3].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[3].sid.sat + "' != '" + 18 + "'",
                    value.equals(BigInteger.valueOf(18L)));
        } else {
            value = value.longValue();
            expected = 18L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].D.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].D.f + "' != '" + 245 + "'",
                    value.equals(BigInteger.valueOf(245L)));
        } else {
            value = value.longValue();
            expected = 245L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].D.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].D.i + "' != '" + 2829 + "'",
                    value.equals(BigInteger.valueOf(2829L)));
        } else {
            value = value.longValue();
            expected = 2829L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].L.f + "' != '" + 53 + "'",
                    value.equals(BigInteger.valueOf(53L)));
        } else {
            value = value.longValue();
            expected = 53L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].L.i + "' != '" + 132024982 + "'",
                    value.equals(BigInteger.valueOf(132024982L)));
        } else {
            value = value.longValue();
            expected = 132024982L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].P + "' != '" + 1256175650 + "'",
                    value.equals(BigInteger.valueOf(1256175650L)));
        } else {
            value = value.longValue();
            expected = 1256175650L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].cn0 + "' != '" + 114 + "'",
                    value.equals(BigInteger.valueOf(114L)));
        } else {
            value = value.longValue();
            expected = 114L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].flags + "' != '" + 15 + "'",
                    value.equals(BigInteger.valueOf(15L)));
        } else {
            value = value.longValue();
            expected = 15L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[4].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].lock + "' != '" + 9 + "'",
                    value.equals(BigInteger.valueOf(9L)));
        } else {
            value = value.longValue();
            expected = 9L;
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
        value = msg.obs[4].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[4].sid.sat + "' != '" + 22 + "'",
                    value.equals(BigInteger.valueOf(22L)));
        } else {
            value = value.longValue();
            expected = 22L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[5].D.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[5].D.f + "' != '" + 246 + "'",
                    value.equals(BigInteger.valueOf(246L)));
        } else {
            value = value.longValue();
            expected = 246L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[5].D.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[5].D.i + "' != '" + -2433 + "'",
                    value.equals(BigInteger.valueOf(-2433L)));
        } else {
            value = value.longValue();
            expected = -2433L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[5].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[5].L.f + "' != '" + 70 + "'",
                    value.equals(BigInteger.valueOf(70L)));
        } else {
            value = value.longValue();
            expected = 70L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[5].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[5].L.i + "' != '" + 121711010 + "'",
                    value.equals(BigInteger.valueOf(121711010L)));
        } else {
            value = value.longValue();
            expected = 121711010L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[5].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[5].P + "' != '" + 1158041713 + "'",
                    value.equals(BigInteger.valueOf(1158041713L)));
        } else {
            value = value.longValue();
            expected = 1158041713L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[5].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[5].cn0 + "' != '" + 189 + "'",
                    value.equals(BigInteger.valueOf(189L)));
        } else {
            value = value.longValue();
            expected = 189L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[5].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[5].flags + "' != '" + 15 + "'",
                    value.equals(BigInteger.valueOf(15L)));
        } else {
            value = value.longValue();
            expected = 15L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[5].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[5].lock + "' != '" + 9 + "'",
                    value.equals(BigInteger.valueOf(9L)));
        } else {
            value = value.longValue();
            expected = 9L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[5].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[5].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[5].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[5].sid.sat + "' != '" + 23 + "'",
                    value.equals(BigInteger.valueOf(23L)));
        } else {
            value = value.longValue();
            expected = 23L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[6].D.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[6].D.f + "' != '" + 231 + "'",
                    value.equals(BigInteger.valueOf(231L)));
        } else {
            value = value.longValue();
            expected = 231L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[6].D.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[6].D.i + "' != '" + -1896 + "'",
                    value.equals(BigInteger.valueOf(-1896L)));
        } else {
            value = value.longValue();
            expected = -1896L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[6].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[6].L.f + "' != '" + 221 + "'",
                    value.equals(BigInteger.valueOf(221L)));
        } else {
            value = value.longValue();
            expected = 221L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[6].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[6].L.i + "' != '" + 94839765 + "'",
                    value.equals(BigInteger.valueOf(94839765L)));
        } else {
            value = value.longValue();
            expected = 94839765L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[6].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[6].P + "' != '" + 1158041847 + "'",
                    value.equals(BigInteger.valueOf(1158041847L)));
        } else {
            value = value.longValue();
            expected = 1158041847L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[6].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[6].cn0 + "' != '" + 158 + "'",
                    value.equals(BigInteger.valueOf(158L)));
        } else {
            value = value.longValue();
            expected = 158L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[6].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[6].flags + "' != '" + 11 + "'",
                    value.equals(BigInteger.valueOf(11L)));
        } else {
            value = value.longValue();
            expected = 11L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[6].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[6].lock + "' != '" + 9 + "'",
                    value.equals(BigInteger.valueOf(9L)));
        } else {
            value = value.longValue();
            expected = 9L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[6].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[6].sid.code + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[6].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[6].sid.sat + "' != '" + 23 + "'",
                    value.equals(BigInteger.valueOf(23L)));
        } else {
            value = value.longValue();
            expected = 23L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[7].D.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[7].D.f + "' != '" + 67 + "'",
                    value.equals(BigInteger.valueOf(67L)));
        } else {
            value = value.longValue();
            expected = 67L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[7].D.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[7].D.i + "' != '" + -1997 + "'",
                    value.equals(BigInteger.valueOf(-1997L)));
        } else {
            value = value.longValue();
            expected = -1997L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[7].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[7].L.f + "' != '" + 114 + "'",
                    value.equals(BigInteger.valueOf(114L)));
        } else {
            value = value.longValue();
            expected = 114L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[7].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[7].L.i + "' != '" + 113998348 + "'",
                    value.equals(BigInteger.valueOf(113998348L)));
        } else {
            value = value.longValue();
            expected = 113998348L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[7].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[7].P + "' != '" + 1084658184 + "'",
                    value.equals(BigInteger.valueOf(1084658184L)));
        } else {
            value = value.longValue();
            expected = 1084658184L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[7].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[7].cn0 + "' != '" + 93 + "'",
                    value.equals(BigInteger.valueOf(93L)));
        } else {
            value = value.longValue();
            expected = 93L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[7].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[7].flags + "' != '" + 11 + "'",
                    value.equals(BigInteger.valueOf(11L)));
        } else {
            value = value.longValue();
            expected = 11L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[7].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[7].lock + "' != '" + 3 + "'",
                    value.equals(BigInteger.valueOf(3L)));
        } else {
            value = value.longValue();
            expected = 3L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[7].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[7].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[7].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[7].sid.sat + "' != '" + 27 + "'",
                    value.equals(BigInteger.valueOf(27L)));
        } else {
            value = value.longValue();
            expected = 27L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[8].D.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[8].D.f + "' != '" + 237 + "'",
                    value.equals(BigInteger.valueOf(237L)));
        } else {
            value = value.longValue();
            expected = 237L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[8].D.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[8].D.i + "' != '" + 3041 + "'",
                    value.equals(BigInteger.valueOf(3041L)));
        } else {
            value = value.longValue();
            expected = 3041L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[8].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[8].L.f + "' != '" + 232 + "'",
                    value.equals(BigInteger.valueOf(232L)));
        } else {
            value = value.longValue();
            expected = 232L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[8].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[8].L.i + "' != '" + 133443545 + "'",
                    value.equals(BigInteger.valueOf(133443545L)));
        } else {
            value = value.longValue();
            expected = 133443545L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[8].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[8].P + "' != '" + 1269673181 + "'",
                    value.equals(BigInteger.valueOf(1269673181L)));
        } else {
            value = value.longValue();
            expected = 1269673181L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[8].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[8].cn0 + "' != '" + 123 + "'",
                    value.equals(BigInteger.valueOf(123L)));
        } else {
            value = value.longValue();
            expected = 123L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[8].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[8].flags + "' != '" + 15 + "'",
                    value.equals(BigInteger.valueOf(15L)));
        } else {
            value = value.longValue();
            expected = 15L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[8].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[8].lock + "' != '" + 5 + "'",
                    value.equals(BigInteger.valueOf(5L)));
        } else {
            value = value.longValue();
            expected = 5L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[8].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[8].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[8].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[8].sid.sat + "' != '" + 31 + "'",
                    value.equals(BigInteger.valueOf(31L)));
        } else {
            value = value.longValue();
            expected = 31L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[9].D.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[9].D.f + "' != '" + 62 + "'",
                    value.equals(BigInteger.valueOf(62L)));
        } else {
            value = value.longValue();
            expected = 62L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[9].D.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[9].D.i + "' != '" + 2374 + "'",
                    value.equals(BigInteger.valueOf(2374L)));
        } else {
            value = value.longValue();
            expected = 2374L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[9].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[9].L.f + "' != '" + 40 + "'",
                    value.equals(BigInteger.valueOf(40L)));
        } else {
            value = value.longValue();
            expected = 40L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[9].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[9].L.i + "' != '" + 103982040 + "'",
                    value.equals(BigInteger.valueOf(103982040L)));
        } else {
            value = value.longValue();
            expected = 103982040L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[9].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[9].P + "' != '" + 1269673722 + "'",
                    value.equals(BigInteger.valueOf(1269673722L)));
        } else {
            value = value.longValue();
            expected = 1269673722L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[9].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[9].cn0 + "' != '" + 120 + "'",
                    value.equals(BigInteger.valueOf(120L)));
        } else {
            value = value.longValue();
            expected = 120L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[9].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[9].flags + "' != '" + 11 + "'",
                    value.equals(BigInteger.valueOf(11L)));
        } else {
            value = value.longValue();
            expected = 11L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[9].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[9].lock + "' != '" + 3 + "'",
                    value.equals(BigInteger.valueOf(3L)));
        } else {
            value = value.longValue();
            expected = 3L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[9].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[9].sid.code + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[9].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[9].sid.sat + "' != '" + 31 + "'",
                    value.equals(BigInteger.valueOf(31L)));
        } else {
            value = value.longValue();
            expected = 31L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[10].D.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[10].D.f + "' != '" + 96 + "'",
                    value.equals(BigInteger.valueOf(96L)));
        } else {
            value = value.longValue();
            expected = 96L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[10].D.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[10].D.i + "' != '" + -3446 + "'",
                    value.equals(BigInteger.valueOf(-3446L)));
        } else {
            value = value.longValue();
            expected = -3446L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[10].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[10].L.f + "' != '" + 7 + "'",
                    value.equals(BigInteger.valueOf(7L)));
        } else {
            value = value.longValue();
            expected = 7L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[10].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[10].L.i + "' != '" + 118217315 + "'",
                    value.equals(BigInteger.valueOf(118217315L)));
        } else {
            value = value.longValue();
            expected = 118217315L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[10].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[10].P + "' != '" + 1107693703 + "'",
                    value.equals(BigInteger.valueOf(1107693703L)));
        } else {
            value = value.longValue();
            expected = 1107693703L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[10].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[10].cn0 + "' != '" + 176 + "'",
                    value.equals(BigInteger.valueOf(176L)));
        } else {
            value = value.longValue();
            expected = 176L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[10].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[10].flags + "' != '" + 15 + "'",
                    value.equals(BigInteger.valueOf(15L)));
        } else {
            value = value.longValue();
            expected = 15L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[10].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[10].lock + "' != '" + 10 + "'",
                    value.equals(BigInteger.valueOf(10L)));
        } else {
            value = value.longValue();
            expected = 10L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[10].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[10].sid.code + "' != '" + 3 + "'",
                    value.equals(BigInteger.valueOf(3L)));
        } else {
            value = value.longValue();
            expected = 3L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[10].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[10].sid.sat + "' != '" + 2 + "'",
                    value.equals(BigInteger.valueOf(2L)));
        } else {
            value = value.longValue();
            expected = 2L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[11].D.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[11].D.f + "' != '" + 96 + "'",
                    value.equals(BigInteger.valueOf(96L)));
        } else {
            value = value.longValue();
            expected = 96L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[11].D.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[11].D.i + "' != '" + -1003 + "'",
                    value.equals(BigInteger.valueOf(-1003L)));
        } else {
            value = value.longValue();
            expected = -1003L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[11].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[11].L.f + "' != '" + 203 + "'",
                    value.equals(BigInteger.valueOf(203L)));
        } else {
            value = value.longValue();
            expected = 203L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[11].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[11].L.i + "' != '" + 104224985 + "'",
                    value.equals(BigInteger.valueOf(104224985L)));
        } else {
            value = value.longValue();
            expected = 104224985L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[11].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[11].P + "' != '" + 973505172 + "'",
                    value.equals(BigInteger.valueOf(973505172L)));
        } else {
            value = value.longValue();
            expected = 973505172L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[11].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[11].cn0 + "' != '" + 170 + "'",
                    value.equals(BigInteger.valueOf(170L)));
        } else {
            value = value.longValue();
            expected = 170L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[11].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[11].flags + "' != '" + 15 + "'",
                    value.equals(BigInteger.valueOf(15L)));
        } else {
            value = value.longValue();
            expected = 15L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[11].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[11].lock + "' != '" + 10 + "'",
                    value.equals(BigInteger.valueOf(10L)));
        } else {
            value = value.longValue();
            expected = 10L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[11].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[11].sid.code + "' != '" + 3 + "'",
                    value.equals(BigInteger.valueOf(3L)));
        } else {
            value = value.longValue();
            expected = 3L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[11].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[11].sid.sat + "' != '" + 3 + "'",
                    value.equals(BigInteger.valueOf(3L)));
        } else {
            value = value.longValue();
            expected = 3L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[12].D.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[12].D.f + "' != '" + 219 + "'",
                    value.equals(BigInteger.valueOf(219L)));
        } else {
            value = value.longValue();
            expected = 219L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[12].D.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[12].D.i + "' != '" + -3836 + "'",
                    value.equals(BigInteger.valueOf(-3836L)));
        } else {
            value = value.longValue();
            expected = -3836L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[12].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[12].L.f + "' != '" + 80 + "'",
                    value.equals(BigInteger.valueOf(80L)));
        } else {
            value = value.longValue();
            expected = 80L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[12].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[12].L.i + "' != '" + 114505343 + "'",
                    value.equals(BigInteger.valueOf(114505343L)));
        } else {
            value = value.longValue();
            expected = 114505343L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[12].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[12].P + "' != '" + 1069903034 + "'",
                    value.equals(BigInteger.valueOf(1069903034L)));
        } else {
            value = value.longValue();
            expected = 1069903034L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[12].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[12].cn0 + "' != '" + 200 + "'",
                    value.equals(BigInteger.valueOf(200L)));
        } else {
            value = value.longValue();
            expected = 200L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[12].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[12].flags + "' != '" + 15 + "'",
                    value.equals(BigInteger.valueOf(15L)));
        } else {
            value = value.longValue();
            expected = 15L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[12].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[12].lock + "' != '" + 10 + "'",
                    value.equals(BigInteger.valueOf(10L)));
        } else {
            value = value.longValue();
            expected = 10L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[12].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[12].sid.code + "' != '" + 3 + "'",
                    value.equals(BigInteger.valueOf(3L)));
        } else {
            value = value.longValue();
            expected = 3L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[12].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[12].sid.sat + "' != '" + 17 + "'",
                    value.equals(BigInteger.valueOf(17L)));
        } else {
            value = value.longValue();
            expected = 17L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[13].D.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[13].D.f + "' != '" + 182 + "'",
                    value.equals(BigInteger.valueOf(182L)));
        } else {
            value = value.longValue();
            expected = 182L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[13].D.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[13].D.i + "' != '" + -461 + "'",
                    value.equals(BigInteger.valueOf(-461L)));
        } else {
            value = value.longValue();
            expected = -461L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[13].L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[13].L.f + "' != '" + 105 + "'",
                    value.equals(BigInteger.valueOf(105L)));
        } else {
            value = value.longValue();
            expected = 105L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[13].L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[13].L.i + "' != '" + 102157331 + "'",
                    value.equals(BigInteger.valueOf(102157331L)));
        } else {
            value = value.longValue();
            expected = 102157331L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[13].P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[13].P + "' != '" + 956875687 + "'",
                    value.equals(BigInteger.valueOf(956875687L)));
        } else {
            value = value.longValue();
            expected = 956875687L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[13].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[13].cn0 + "' != '" + 152 + "'",
                    value.equals(BigInteger.valueOf(152L)));
        } else {
            value = value.longValue();
            expected = 152L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[13].flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[13].flags + "' != '" + 15 + "'",
                    value.equals(BigInteger.valueOf(15L)));
        } else {
            value = value.longValue();
            expected = 15L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[13].lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[13].lock + "' != '" + 10 + "'",
                    value.equals(BigInteger.valueOf(10L)));
        } else {
            value = value.longValue();
            expected = 10L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[13].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[13].sid.code + "' != '" + 3 + "'",
                    value.equals(BigInteger.valueOf(3L)));
        } else {
            value = value.longValue();
            expected = 3L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs[13].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs[13].sid.sat + "' != '" + 18 + "'",
                    value.equals(BigInteger.valueOf(18L)));
        } else {
            value = value.longValue();
            expected = 18L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test2() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_observation_MsgObsTest.test2");
        byte[] payload =
                new byte[] {
                    (byte) 152,
                    (byte) 202,
                    (byte) 226,
                    (byte) 25,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 106,
                    (byte) 8,
                    (byte) 16,
                };
        SBPMessage sbp = new SBPMessage(0xf081, 0x4a, payload);
        MsgObs msg = new MsgObs(sbp);
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
        value = msg.header.t.ns_residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.header.t.ns_residual + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.header.t.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.header.t.tow + "' != '" + 434293400 + "'",
                    value.equals(BigInteger.valueOf(434293400L)));
        } else {
            value = value.longValue();
            expected = 434293400L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.header.t.wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.header.t.wn + "' != '" + 2154 + "'",
                    value.equals(BigInteger.valueOf(2154L)));
        } else {
            value = value.longValue();
            expected = 2154L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }
}
