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
// spec/tests/yaml/swiftnav/sbp/tracking/test_MsgTrackingStateDepB.yaml by generate.py. Do not
// modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.tracking.MsgTrackingStateDepB;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_tracking_MsgTrackingStateDepBTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_tracking_MsgTrackingStateDepBTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 115,
                    (byte) 183,
                    (byte) 227,
                    (byte) 63,
                    (byte) 68,
                    (byte) 154,
                    (byte) 1,
                    (byte) 183,
                    (byte) 69,
                    (byte) 255,
                    (byte) 175,
                    (byte) 121,
                    (byte) 43,
                    (byte) 222,
                    (byte) 51,
                    (byte) 67,
                    (byte) 35,
                    (byte) 69,
                    (byte) 78,
                    (byte) 240,
                    (byte) 5,
                    (byte) 53,
                    (byte) 20,
                    (byte) 51,
                    (byte) 211,
                    (byte) 54,
                    (byte) 69,
                    (byte) 153,
                    (byte) 130,
                    (byte) 237,
                    (byte) 66,
                    (byte) 155,
                    (byte) 51,
                    (byte) 227,
                    (byte) 71,
                    (byte) 69,
                    (byte) 53,
                    (byte) 242,
                    (byte) 136,
                    (byte) 161,
                    (byte) 190,
                    (byte) 205,
                    (byte) 188,
                    (byte) 6,
                    (byte) 70,
                    (byte) 153,
                    (byte) 125,
                    (byte) 255,
                    (byte) 142,
                    (byte) 149,
                    (byte) 154,
                    (byte) 217,
                    (byte) 184,
                    (byte) 69,
                    (byte) 248,
                    (byte) 102,
                    (byte) 95,
                    (byte) 31,
                    (byte) 76,
                    (byte) 154,
                    (byte) 33,
                    (byte) 169,
                    (byte) 69,
                    (byte) 131,
                    (byte) 115,
                    (byte) 141,
                    (byte) 27,
                    (byte) 12,
                    (byte) 154,
                    (byte) 225,
                    (byte) 200,
                    (byte) 69,
                    (byte) 208,
                    (byte) 44,
                    (byte) 147,
                    (byte) 39,
                    (byte) 23,
                    (byte) 51,
                    (byte) 3,
                    (byte) 66,
                    (byte) 69,
                    (byte) 237,
                    (byte) 159,
                    (byte) 251,
                    (byte) 49,
                    (byte) 203,
                    (byte) 51,
                    (byte) 99,
                    (byte) 102,
                    (byte) 69,
                    (byte) 70,
                    (byte) 214,
                    (byte) 87,
                    (byte) 128,
                    (byte) 206,
                    (byte) 154,
                    (byte) 121,
                    (byte) 186,
                    (byte) 69,
                    (byte) 14,
                    (byte) 206,
                    (byte) 111,
                    (byte) 218,
                    (byte) 19,
                    (byte) 154,
                    (byte) 121,
                    (byte) 169,
                    (byte) 69,
                    (byte) 216,
                    (byte) 98,
                    (byte) 209,
                    (byte) 54,
                    (byte) 2,
                    (byte) 154,
                    (byte) 25,
                    (byte) 219,
                    (byte) 67,
                    (byte) 200,
                    (byte) 133,
                    (byte) 99,
                    (byte) 7,
                    (byte) 34,
                    (byte) 102,
                    (byte) 198,
                    (byte) 232,
                    (byte) 68,
                    (byte) 155,
                    (byte) 43,
                    (byte) 85,
                    (byte) 135,
                    (byte) 46,
                    (byte) 154,
                    (byte) 177,
                    (byte) 170,
                    (byte) 69,
                    (byte) 155,
                    (byte) 3,
                    (byte) 83,
                    (byte) 171,
                    (byte) 201,
                    (byte) 154,
                    (byte) 241,
                    (byte) 232,
                    (byte) 69,
                    (byte) 121,
                    (byte) 43,
                    (byte) 197,
                    (byte) 16,
                    (byte) 19,
                    (byte) 154,
                    (byte) 241,
                    (byte) 222,
                    (byte) 69,
                    (byte) 128,
                    (byte) 245,
                    (byte) 53,
                    (byte) 63,
                    (byte) 176,
                    (byte) 51,
                    (byte) 115,
                    (byte) 66,
                    (byte) 69,
                    (byte) 36,
                    (byte) 20,
                    (byte) 61,
                    (byte) 153,
                    (byte) 51,
                    (byte) 154,
                    (byte) 73,
                    (byte) 134,
                    (byte) 69,
                    (byte) 46,
                    (byte) 82,
                    (byte) 116,
                    (byte) 140,
                    (byte) 22,
                    (byte) 51,
                    (byte) 147,
                    (byte) 37,
                    (byte) 69,
                    (byte) 177,
                    (byte) 67,
                    (byte) 146,
                    (byte) 96,
                    (byte) 143,
                    (byte) 205,
                    (byte) 76,
                    (byte) 107,
                    (byte) 68,
                    (byte) 220,
                    (byte) 51,
                    (byte) 160,
                    (byte) 201,
                    (byte) 251,
                    (byte) 102,
                    (byte) 102,
                    (byte) 192,
                    (byte) 68,
                    (byte) 168,
                    (byte) 194,
                    (byte) 2,
                    (byte) 161,
                    (byte) 220,
                    (byte) 102,
                    (byte) 102,
                    (byte) 180,
                    (byte) 68,
                    (byte) 69,
                    (byte) 8,
                    (byte) 9,
                    (byte) 125,
                    (byte) 178,
                    (byte) 102,
                    (byte) 70,
                    (byte) 134,
                    (byte) 68,
                    (byte) 185,
                    (byte) 20,
                    (byte) 135,
                    (byte) 186,
                    (byte) 171,
                    (byte) 51,
                    (byte) 163,
                    (byte) 4,
                    (byte) 69,
                    (byte) 18,
                    (byte) 124,
                    (byte) 155,
                    (byte) 85,
                    (byte) 170,
                    (byte) 205,
                    (byte) 208,
                    (byte) 13,
                    (byte) 70,
                    (byte) 57,
                    (byte) 244,
                    (byte) 206,
                    (byte) 255,
                    (byte) 186,
                    (byte) 154,
                    (byte) 105,
                    (byte) 149,
                    (byte) 69,
                    (byte) 165,
                    (byte) 199,
                    (byte) 93,
                    (byte) 181,
                    (byte) 175,
                    (byte) 51,
                    (byte) 67,
                    (byte) 64,
                    (byte) 69,
                };
        SBPMessage sbp = new SBPMessage(0xf1f2, 0x13, payload);
        MsgTrackingStateDepB msg = new MsgTrackingStateDepB(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        org.junit.Assert.assertEquals(msg.states[0].cn0, 5.85620019531250000e+03, DELTA);
        value = msg.states[0].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[0].sid.code + "' != '" + 63 + "'",
                    value.equals(BigInteger.valueOf(63L)));
        } else {
            value = value.longValue();
            expected = 63L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[0].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[0].sid.reserved + "' != '" + 68 + "'",
                    value.equals(BigInteger.valueOf(68L)));
        } else {
            value = value.longValue();
            expected = 68L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[0].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[0].sid.sat + "' != '" + 58295 + "'",
                    value.equals(BigInteger.valueOf(58295L)));
        } else {
            value = value.longValue();
            expected = 58295L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[0].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[0].state + "' != '" + 115 + "'",
                    value.equals(BigInteger.valueOf(115L)));
        } else {
            value = value.longValue();
            expected = 115L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[1].cn0, 2.61219995117187500e+03, DELTA);
        value = msg.states[1].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[1].sid.code + "' != '" + 43 + "'",
                    value.equals(BigInteger.valueOf(43L)));
        } else {
            value = value.longValue();
            expected = 43L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[1].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[1].sid.reserved + "' != '" + 222 + "'",
                    value.equals(BigInteger.valueOf(222L)));
        } else {
            value = value.longValue();
            expected = 222L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[1].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[1].sid.sat + "' != '" + 31151 + "'",
                    value.equals(BigInteger.valueOf(31151L)));
        } else {
            value = value.longValue();
            expected = 31151L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[1].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[1].state + "' != '" + 255 + "'",
                    value.equals(BigInteger.valueOf(255L)));
        } else {
            value = value.longValue();
            expected = 255L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[2].cn0, 2.92519995117187500e+03, DELTA);
        value = msg.states[2].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[2].sid.code + "' != '" + 53 + "'",
                    value.equals(BigInteger.valueOf(53L)));
        } else {
            value = value.longValue();
            expected = 53L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[2].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[2].sid.reserved + "' != '" + 20 + "'",
                    value.equals(BigInteger.valueOf(20L)));
        } else {
            value = value.longValue();
            expected = 20L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[2].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[2].sid.sat + "' != '" + 1520 + "'",
                    value.equals(BigInteger.valueOf(1520L)));
        } else {
            value = value.longValue();
            expected = 1520L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[2].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[2].state + "' != '" + 78 + "'",
                    value.equals(BigInteger.valueOf(78L)));
        } else {
            value = value.longValue();
            expected = 78L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[3].cn0, 3.19819995117187500e+03, DELTA);
        value = msg.states[3].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[3].sid.code + "' != '" + 66 + "'",
                    value.equals(BigInteger.valueOf(66L)));
        } else {
            value = value.longValue();
            expected = 66L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[3].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[3].sid.reserved + "' != '" + 155 + "'",
                    value.equals(BigInteger.valueOf(155L)));
        } else {
            value = value.longValue();
            expected = 155L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[3].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[3].sid.sat + "' != '" + 60802 + "'",
                    value.equals(BigInteger.valueOf(60802L)));
        } else {
            value = value.longValue();
            expected = 60802L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[3].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[3].state + "' != '" + 153 + "'",
                    value.equals(BigInteger.valueOf(153L)));
        } else {
            value = value.longValue();
            expected = 153L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[4].cn0, 8.62320019531250000e+03, DELTA);
        value = msg.states[4].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[4].sid.code + "' != '" + 161 + "'",
                    value.equals(BigInteger.valueOf(161L)));
        } else {
            value = value.longValue();
            expected = 161L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[4].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[4].sid.reserved + "' != '" + 190 + "'",
                    value.equals(BigInteger.valueOf(190L)));
        } else {
            value = value.longValue();
            expected = 190L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[4].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[4].sid.sat + "' != '" + 35058 + "'",
                    value.equals(BigInteger.valueOf(35058L)));
        } else {
            value = value.longValue();
            expected = 35058L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[4].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[4].state + "' != '" + 53 + "'",
                    value.equals(BigInteger.valueOf(53L)));
        } else {
            value = value.longValue();
            expected = 53L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[5].cn0, 5.91520019531250000e+03, DELTA);
        value = msg.states[5].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[5].sid.code + "' != '" + 142 + "'",
                    value.equals(BigInteger.valueOf(142L)));
        } else {
            value = value.longValue();
            expected = 142L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[5].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[5].sid.reserved + "' != '" + 149 + "'",
                    value.equals(BigInteger.valueOf(149L)));
        } else {
            value = value.longValue();
            expected = 149L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[5].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[5].sid.sat + "' != '" + 65405 + "'",
                    value.equals(BigInteger.valueOf(65405L)));
        } else {
            value = value.longValue();
            expected = 65405L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[5].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[5].state + "' != '" + 153 + "'",
                    value.equals(BigInteger.valueOf(153L)));
        } else {
            value = value.longValue();
            expected = 153L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[6].cn0, 5.41220019531250000e+03, DELTA);
        value = msg.states[6].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[6].sid.code + "' != '" + 31 + "'",
                    value.equals(BigInteger.valueOf(31L)));
        } else {
            value = value.longValue();
            expected = 31L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[6].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[6].sid.reserved + "' != '" + 76 + "'",
                    value.equals(BigInteger.valueOf(76L)));
        } else {
            value = value.longValue();
            expected = 76L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[6].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[6].sid.sat + "' != '" + 24422 + "'",
                    value.equals(BigInteger.valueOf(24422L)));
        } else {
            value = value.longValue();
            expected = 24422L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[6].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[6].state + "' != '" + 248 + "'",
                    value.equals(BigInteger.valueOf(248L)));
        } else {
            value = value.longValue();
            expected = 248L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[7].cn0, 6.42820019531250000e+03, DELTA);
        value = msg.states[7].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[7].sid.code + "' != '" + 27 + "'",
                    value.equals(BigInteger.valueOf(27L)));
        } else {
            value = value.longValue();
            expected = 27L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[7].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[7].sid.reserved + "' != '" + 12 + "'",
                    value.equals(BigInteger.valueOf(12L)));
        } else {
            value = value.longValue();
            expected = 12L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[7].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[7].sid.sat + "' != '" + 36211 + "'",
                    value.equals(BigInteger.valueOf(36211L)));
        } else {
            value = value.longValue();
            expected = 36211L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[7].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[7].state + "' != '" + 131 + "'",
                    value.equals(BigInteger.valueOf(131L)));
        } else {
            value = value.longValue();
            expected = 131L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[8].cn0, 3.10419995117187500e+03, DELTA);
        value = msg.states[8].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[8].sid.code + "' != '" + 39 + "'",
                    value.equals(BigInteger.valueOf(39L)));
        } else {
            value = value.longValue();
            expected = 39L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[8].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[8].sid.reserved + "' != '" + 23 + "'",
                    value.equals(BigInteger.valueOf(23L)));
        } else {
            value = value.longValue();
            expected = 23L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[8].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[8].sid.sat + "' != '" + 37676 + "'",
                    value.equals(BigInteger.valueOf(37676L)));
        } else {
            value = value.longValue();
            expected = 37676L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[8].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[8].state + "' != '" + 208 + "'",
                    value.equals(BigInteger.valueOf(208L)));
        } else {
            value = value.longValue();
            expected = 208L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[9].cn0, 3.68619995117187500e+03, DELTA);
        value = msg.states[9].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[9].sid.code + "' != '" + 49 + "'",
                    value.equals(BigInteger.valueOf(49L)));
        } else {
            value = value.longValue();
            expected = 49L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[9].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[9].sid.reserved + "' != '" + 203 + "'",
                    value.equals(BigInteger.valueOf(203L)));
        } else {
            value = value.longValue();
            expected = 203L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[9].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[9].sid.sat + "' != '" + 64415 + "'",
                    value.equals(BigInteger.valueOf(64415L)));
        } else {
            value = value.longValue();
            expected = 64415L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[9].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[9].state + "' != '" + 237 + "'",
                    value.equals(BigInteger.valueOf(237L)));
        } else {
            value = value.longValue();
            expected = 237L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[10].cn0, 5.96720019531250000e+03, DELTA);
        value = msg.states[10].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[10].sid.code + "' != '" + 128 + "'",
                    value.equals(BigInteger.valueOf(128L)));
        } else {
            value = value.longValue();
            expected = 128L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[10].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[10].sid.reserved + "' != '" + 206 + "'",
                    value.equals(BigInteger.valueOf(206L)));
        } else {
            value = value.longValue();
            expected = 206L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[10].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[10].sid.sat + "' != '" + 22486 + "'",
                    value.equals(BigInteger.valueOf(22486L)));
        } else {
            value = value.longValue();
            expected = 22486L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[10].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[10].state + "' != '" + 70 + "'",
                    value.equals(BigInteger.valueOf(70L)));
        } else {
            value = value.longValue();
            expected = 70L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[11].cn0, 5.42320019531250000e+03, DELTA);
        value = msg.states[11].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[11].sid.code + "' != '" + 218 + "'",
                    value.equals(BigInteger.valueOf(218L)));
        } else {
            value = value.longValue();
            expected = 218L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[11].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[11].sid.reserved + "' != '" + 19 + "'",
                    value.equals(BigInteger.valueOf(19L)));
        } else {
            value = value.longValue();
            expected = 19L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[11].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[11].sid.sat + "' != '" + 28622 + "'",
                    value.equals(BigInteger.valueOf(28622L)));
        } else {
            value = value.longValue();
            expected = 28622L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[11].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[11].state + "' != '" + 14 + "'",
                    value.equals(BigInteger.valueOf(14L)));
        } else {
            value = value.longValue();
            expected = 14L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[12].cn0, 4.38200012207031250e+02, DELTA);
        value = msg.states[12].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[12].sid.code + "' != '" + 54 + "'",
                    value.equals(BigInteger.valueOf(54L)));
        } else {
            value = value.longValue();
            expected = 54L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[12].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[12].sid.reserved + "' != '" + 2 + "'",
                    value.equals(BigInteger.valueOf(2L)));
        } else {
            value = value.longValue();
            expected = 2L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[12].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[12].sid.sat + "' != '" + 53602 + "'",
                    value.equals(BigInteger.valueOf(53602L)));
        } else {
            value = value.longValue();
            expected = 53602L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[12].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[12].state + "' != '" + 216 + "'",
                    value.equals(BigInteger.valueOf(216L)));
        } else {
            value = value.longValue();
            expected = 216L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[13].cn0, 1.86219995117187500e+03, DELTA);
        value = msg.states[13].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[13].sid.code + "' != '" + 7 + "'",
                    value.equals(BigInteger.valueOf(7L)));
        } else {
            value = value.longValue();
            expected = 7L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[13].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[13].sid.reserved + "' != '" + 34 + "'",
                    value.equals(BigInteger.valueOf(34L)));
        } else {
            value = value.longValue();
            expected = 34L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[13].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[13].sid.sat + "' != '" + 25477 + "'",
                    value.equals(BigInteger.valueOf(25477L)));
        } else {
            value = value.longValue();
            expected = 25477L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[13].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[13].state + "' != '" + 200 + "'",
                    value.equals(BigInteger.valueOf(200L)));
        } else {
            value = value.longValue();
            expected = 200L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[14].cn0, 5.46220019531250000e+03, DELTA);
        value = msg.states[14].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[14].sid.code + "' != '" + 135 + "'",
                    value.equals(BigInteger.valueOf(135L)));
        } else {
            value = value.longValue();
            expected = 135L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[14].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[14].sid.reserved + "' != '" + 46 + "'",
                    value.equals(BigInteger.valueOf(46L)));
        } else {
            value = value.longValue();
            expected = 46L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[14].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[14].sid.sat + "' != '" + 21803 + "'",
                    value.equals(BigInteger.valueOf(21803L)));
        } else {
            value = value.longValue();
            expected = 21803L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[14].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[14].state + "' != '" + 155 + "'",
                    value.equals(BigInteger.valueOf(155L)));
        } else {
            value = value.longValue();
            expected = 155L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[15].cn0, 7.45420019531250000e+03, DELTA);
        value = msg.states[15].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[15].sid.code + "' != '" + 171 + "'",
                    value.equals(BigInteger.valueOf(171L)));
        } else {
            value = value.longValue();
            expected = 171L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[15].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[15].sid.reserved + "' != '" + 201 + "'",
                    value.equals(BigInteger.valueOf(201L)));
        } else {
            value = value.longValue();
            expected = 201L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[15].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[15].sid.sat + "' != '" + 21251 + "'",
                    value.equals(BigInteger.valueOf(21251L)));
        } else {
            value = value.longValue();
            expected = 21251L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[15].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[15].state + "' != '" + 155 + "'",
                    value.equals(BigInteger.valueOf(155L)));
        } else {
            value = value.longValue();
            expected = 155L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[16].cn0, 7.13420019531250000e+03, DELTA);
        value = msg.states[16].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[16].sid.code + "' != '" + 16 + "'",
                    value.equals(BigInteger.valueOf(16L)));
        } else {
            value = value.longValue();
            expected = 16L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[16].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[16].sid.reserved + "' != '" + 19 + "'",
                    value.equals(BigInteger.valueOf(19L)));
        } else {
            value = value.longValue();
            expected = 19L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[16].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[16].sid.sat + "' != '" + 50475 + "'",
                    value.equals(BigInteger.valueOf(50475L)));
        } else {
            value = value.longValue();
            expected = 50475L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[16].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[16].state + "' != '" + 121 + "'",
                    value.equals(BigInteger.valueOf(121L)));
        } else {
            value = value.longValue();
            expected = 121L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[17].cn0, 3.11119995117187500e+03, DELTA);
        value = msg.states[17].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[17].sid.code + "' != '" + 63 + "'",
                    value.equals(BigInteger.valueOf(63L)));
        } else {
            value = value.longValue();
            expected = 63L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[17].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[17].sid.reserved + "' != '" + 176 + "'",
                    value.equals(BigInteger.valueOf(176L)));
        } else {
            value = value.longValue();
            expected = 176L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[17].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[17].sid.sat + "' != '" + 13813 + "'",
                    value.equals(BigInteger.valueOf(13813L)));
        } else {
            value = value.longValue();
            expected = 13813L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[17].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[17].state + "' != '" + 128 + "'",
                    value.equals(BigInteger.valueOf(128L)));
        } else {
            value = value.longValue();
            expected = 128L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[18].cn0, 4.29720019531250000e+03, DELTA);
        value = msg.states[18].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[18].sid.code + "' != '" + 153 + "'",
                    value.equals(BigInteger.valueOf(153L)));
        } else {
            value = value.longValue();
            expected = 153L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[18].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[18].sid.reserved + "' != '" + 51 + "'",
                    value.equals(BigInteger.valueOf(51L)));
        } else {
            value = value.longValue();
            expected = 51L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[18].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[18].sid.sat + "' != '" + 15636 + "'",
                    value.equals(BigInteger.valueOf(15636L)));
        } else {
            value = value.longValue();
            expected = 15636L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[18].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[18].state + "' != '" + 36 + "'",
                    value.equals(BigInteger.valueOf(36L)));
        } else {
            value = value.longValue();
            expected = 36L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[19].cn0, 2.64919995117187500e+03, DELTA);
        value = msg.states[19].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[19].sid.code + "' != '" + 140 + "'",
                    value.equals(BigInteger.valueOf(140L)));
        } else {
            value = value.longValue();
            expected = 140L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[19].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[19].sid.reserved + "' != '" + 22 + "'",
                    value.equals(BigInteger.valueOf(22L)));
        } else {
            value = value.longValue();
            expected = 22L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[19].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[19].sid.sat + "' != '" + 29778 + "'",
                    value.equals(BigInteger.valueOf(29778L)));
        } else {
            value = value.longValue();
            expected = 29778L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[19].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[19].state + "' != '" + 46 + "'",
                    value.equals(BigInteger.valueOf(46L)));
        } else {
            value = value.longValue();
            expected = 46L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[20].cn0, 9.41200012207031250e+02, DELTA);
        value = msg.states[20].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[20].sid.code + "' != '" + 96 + "'",
                    value.equals(BigInteger.valueOf(96L)));
        } else {
            value = value.longValue();
            expected = 96L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[20].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[20].sid.reserved + "' != '" + 143 + "'",
                    value.equals(BigInteger.valueOf(143L)));
        } else {
            value = value.longValue();
            expected = 143L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[20].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[20].sid.sat + "' != '" + 37443 + "'",
                    value.equals(BigInteger.valueOf(37443L)));
        } else {
            value = value.longValue();
            expected = 37443L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[20].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[20].state + "' != '" + 177 + "'",
                    value.equals(BigInteger.valueOf(177L)));
        } else {
            value = value.longValue();
            expected = 177L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[21].cn0, 1.53919995117187500e+03, DELTA);
        value = msg.states[21].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[21].sid.code + "' != '" + 201 + "'",
                    value.equals(BigInteger.valueOf(201L)));
        } else {
            value = value.longValue();
            expected = 201L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[21].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[21].sid.reserved + "' != '" + 251 + "'",
                    value.equals(BigInteger.valueOf(251L)));
        } else {
            value = value.longValue();
            expected = 251L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[21].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[21].sid.sat + "' != '" + 41011 + "'",
                    value.equals(BigInteger.valueOf(41011L)));
        } else {
            value = value.longValue();
            expected = 41011L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[21].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[21].state + "' != '" + 220 + "'",
                    value.equals(BigInteger.valueOf(220L)));
        } else {
            value = value.longValue();
            expected = 220L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[22].cn0, 1.44319995117187500e+03, DELTA);
        value = msg.states[22].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[22].sid.code + "' != '" + 161 + "'",
                    value.equals(BigInteger.valueOf(161L)));
        } else {
            value = value.longValue();
            expected = 161L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[22].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[22].sid.reserved + "' != '" + 220 + "'",
                    value.equals(BigInteger.valueOf(220L)));
        } else {
            value = value.longValue();
            expected = 220L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[22].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[22].sid.sat + "' != '" + 706 + "'",
                    value.equals(BigInteger.valueOf(706L)));
        } else {
            value = value.longValue();
            expected = 706L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[22].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[22].state + "' != '" + 168 + "'",
                    value.equals(BigInteger.valueOf(168L)));
        } else {
            value = value.longValue();
            expected = 168L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[23].cn0, 1.07419995117187500e+03, DELTA);
        value = msg.states[23].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[23].sid.code + "' != '" + 125 + "'",
                    value.equals(BigInteger.valueOf(125L)));
        } else {
            value = value.longValue();
            expected = 125L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[23].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[23].sid.reserved + "' != '" + 178 + "'",
                    value.equals(BigInteger.valueOf(178L)));
        } else {
            value = value.longValue();
            expected = 178L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[23].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[23].sid.sat + "' != '" + 2312 + "'",
                    value.equals(BigInteger.valueOf(2312L)));
        } else {
            value = value.longValue();
            expected = 2312L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[23].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[23].state + "' != '" + 69 + "'",
                    value.equals(BigInteger.valueOf(69L)));
        } else {
            value = value.longValue();
            expected = 69L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[24].cn0, 2.12219995117187500e+03, DELTA);
        value = msg.states[24].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[24].sid.code + "' != '" + 186 + "'",
                    value.equals(BigInteger.valueOf(186L)));
        } else {
            value = value.longValue();
            expected = 186L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[24].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[24].sid.reserved + "' != '" + 171 + "'",
                    value.equals(BigInteger.valueOf(171L)));
        } else {
            value = value.longValue();
            expected = 171L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[24].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[24].sid.sat + "' != '" + 34580 + "'",
                    value.equals(BigInteger.valueOf(34580L)));
        } else {
            value = value.longValue();
            expected = 34580L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[24].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[24].state + "' != '" + 185 + "'",
                    value.equals(BigInteger.valueOf(185L)));
        } else {
            value = value.longValue();
            expected = 185L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[25].cn0, 9.07620019531250000e+03, DELTA);
        value = msg.states[25].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[25].sid.code + "' != '" + 85 + "'",
                    value.equals(BigInteger.valueOf(85L)));
        } else {
            value = value.longValue();
            expected = 85L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[25].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[25].sid.reserved + "' != '" + 170 + "'",
                    value.equals(BigInteger.valueOf(170L)));
        } else {
            value = value.longValue();
            expected = 170L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[25].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[25].sid.sat + "' != '" + 39804 + "'",
                    value.equals(BigInteger.valueOf(39804L)));
        } else {
            value = value.longValue();
            expected = 39804L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[25].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[25].state + "' != '" + 18 + "'",
                    value.equals(BigInteger.valueOf(18L)));
        } else {
            value = value.longValue();
            expected = 18L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[26].cn0, 4.78120019531250000e+03, DELTA);
        value = msg.states[26].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[26].sid.code + "' != '" + 255 + "'",
                    value.equals(BigInteger.valueOf(255L)));
        } else {
            value = value.longValue();
            expected = 255L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[26].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[26].sid.reserved + "' != '" + 186 + "'",
                    value.equals(BigInteger.valueOf(186L)));
        } else {
            value = value.longValue();
            expected = 186L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[26].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[26].sid.sat + "' != '" + 52980 + "'",
                    value.equals(BigInteger.valueOf(52980L)));
        } else {
            value = value.longValue();
            expected = 52980L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[26].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[26].state + "' != '" + 57 + "'",
                    value.equals(BigInteger.valueOf(57L)));
        } else {
            value = value.longValue();
            expected = 57L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[27].cn0, 3.07619995117187500e+03, DELTA);
        value = msg.states[27].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[27].sid.code + "' != '" + 181 + "'",
                    value.equals(BigInteger.valueOf(181L)));
        } else {
            value = value.longValue();
            expected = 181L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[27].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[27].sid.reserved + "' != '" + 175 + "'",
                    value.equals(BigInteger.valueOf(175L)));
        } else {
            value = value.longValue();
            expected = 175L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[27].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[27].sid.sat + "' != '" + 24007 + "'",
                    value.equals(BigInteger.valueOf(24007L)));
        } else {
            value = value.longValue();
            expected = 24007L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[27].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[27].state + "' != '" + 165 + "'",
                    value.equals(BigInteger.valueOf(165L)));
        } else {
            value = value.longValue();
            expected = 165L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
