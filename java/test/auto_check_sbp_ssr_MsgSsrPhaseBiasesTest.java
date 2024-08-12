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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrPhaseBiases.yaml by
// generate.py. Do not modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.ssr.MsgSsrPhaseBiases;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_ssr_MsgSsrPhaseBiasesTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_ssr_MsgSsrPhaseBiasesTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 209,
                    (byte) 154,
                    (byte) 144,
                    (byte) 12,
                    (byte) 213,
                    (byte) 164,
                    (byte) 169,
                    (byte) 82,
                    (byte) 177,
                    (byte) 230,
                    (byte) 98,
                    (byte) 209,
                    (byte) 249,
                    (byte) 22,
                    (byte) 17,
                    (byte) 29,
                    (byte) 250,
                    (byte) 245,
                    (byte) 193,
                    (byte) 219,
                    (byte) 30,
                    (byte) 212,
                    (byte) 177,
                    (byte) 207,
                    (byte) 187,
                    (byte) 33,
                    (byte) 146,
                    (byte) 58,
                    (byte) 204,
                    (byte) 164,
                    (byte) 65,
                    (byte) 114,
                    (byte) 49,
                    (byte) 248,
                    (byte) 52,
                    (byte) 8,
                    (byte) 161,
                    (byte) 44,
                    (byte) 252,
                    (byte) 166,
                    (byte) 168,
                    (byte) 232,
                    (byte) 124,
                    (byte) 134,
                    (byte) 86,
                    (byte) 173,
                    (byte) 241,
                    (byte) 174,
                    (byte) 44,
                    (byte) 142,
                    (byte) 155,
                    (byte) 129,
                    (byte) 143,
                    (byte) 184,
                    (byte) 161,
                    (byte) 211,
                    (byte) 15,
                    (byte) 36,
                    (byte) 189,
                    (byte) 208,
                    (byte) 194,
                    (byte) 221,
                    (byte) 152,
                    (byte) 16,
                    (byte) 203,
                    (byte) 87,
                    (byte) 34,
                    (byte) 188,
                    (byte) 141,
                    (byte) 104,
                    (byte) 189,
                    (byte) 102,
                    (byte) 156,
                    (byte) 252,
                    (byte) 22,
                    (byte) 251,
                    (byte) 136,
                    (byte) 49,
                    (byte) 188,
                    (byte) 157,
                    (byte) 222,
                    (byte) 245,
                    (byte) 49,
                    (byte) 132,
                    (byte) 16,
                    (byte) 34,
                    (byte) 142,
                    (byte) 228,
                    (byte) 85,
                    (byte) 139,
                    (byte) 221,
                    (byte) 197,
                    (byte) 235,
                    (byte) 98,
                    (byte) 74,
                    (byte) 107,
                    (byte) 70,
                    (byte) 36,
                    (byte) 38,
                    (byte) 239,
                    (byte) 251,
                    (byte) 112,
                    (byte) 188,
                    (byte) 124,
                    (byte) 246,
                    (byte) 141,
                    (byte) 164,
                    (byte) 150,
                    (byte) 104,
                    (byte) 7,
                    (byte) 213,
                    (byte) 44,
                    (byte) 21,
                    (byte) 244,
                    (byte) 192,
                    (byte) 4,
                    (byte) 143,
                    (byte) 24,
                    (byte) 42,
                    (byte) 21,
                    (byte) 84,
                    (byte) 136,
                    (byte) 7,
                    (byte) 42,
                    (byte) 118,
                    (byte) 45,
                    (byte) 23,
                    (byte) 174,
                    (byte) 175,
                    (byte) 129,
                    (byte) 54,
                    (byte) 169,
                    (byte) 14,
                    (byte) 213,
                    (byte) 2,
                    (byte) 197,
                    (byte) 98,
                    (byte) 60,
                    (byte) 13,
                    (byte) 207,
                    (byte) 105,
                    (byte) 100,
                    (byte) 129,
                    (byte) 72,
                    (byte) 136,
                    (byte) 240,
                    (byte) 140,
                    (byte) 129,
                    (byte) 9,
                    (byte) 114,
                    (byte) 172,
                    (byte) 151,
                    (byte) 150,
                    (byte) 17,
                    (byte) 210,
                    (byte) 127,
                    (byte) 115,
                    (byte) 151,
                    (byte) 3,
                    (byte) 242,
                    (byte) 254,
                    (byte) 215,
                    (byte) 14,
                    (byte) 5,
                    (byte) 34,
                    (byte) 126,
                    (byte) 2,
                    (byte) 215,
                    (byte) 65,
                    (byte) 38,
                    (byte) 176,
                    (byte) 23,
                    (byte) 210,
                    (byte) 201,
                    (byte) 97,
                    (byte) 36,
                    (byte) 207,
                    (byte) 92,
                    (byte) 224,
                    (byte) 26,
                    (byte) 116,
                    (byte) 155,
                    (byte) 211,
                    (byte) 165,
                    (byte) 47,
                    (byte) 102,
                    (byte) 38,
                    (byte) 67,
                    (byte) 199,
                    (byte) 55,
                    (byte) 117,
                    (byte) 36,
                    (byte) 169,
                    (byte) 33,
                    (byte) 1,
                    (byte) 230,
                    (byte) 201,
                    (byte) 183,
                    (byte) 21,
                    (byte) 42,
                    (byte) 62,
                    (byte) 147,
                    (byte) 173,
                    (byte) 173,
                    (byte) 155,
                    (byte) 98,
                    (byte) 146,
                    (byte) 231,
                    (byte) 167,
                    (byte) 138,
                    (byte) 82,
                    (byte) 167,
                    (byte) 127,
                    (byte) 229,
                    (byte) 1,
                    (byte) 2,
                    (byte) 127,
                    (byte) 237,
                    (byte) 207,
                    (byte) 116,
                    (byte) 90,
                    (byte) 115,
                    (byte) 159,
                    (byte) 3,
                    (byte) 42,
                    (byte) 66,
                    (byte) 145,
                    (byte) 250,
                    (byte) 201,
                    (byte) 7,
                    (byte) 251,
                    (byte) 2,
                    (byte) 75,
                    (byte) 230,
                    (byte) 26,
                    (byte) 213,
                    (byte) 181,
                    (byte) 56,
                    (byte) 64,
                    (byte) 97,
                    (byte) 88,
                    (byte) 255,
                    (byte) 6,
                    (byte) 147,
                    (byte) 16,
                    (byte) 89,
                    (byte) 203,
                    (byte) 27,
                    (byte) 68,
                    (byte) 243,
                    (byte) 230,
                    (byte) 55,
                    (byte) 242,
                    (byte) 167,
                    (byte) 169,
                };
        SBPMessage sbp = new SBPMessage(0xcedb, 0x5e6, payload);
        MsgSsrPhaseBiases msg = new MsgSsrPhaseBiases(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.biases[0].bias;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[0].bias + "' != '" + -1311498533 + "'",
                    value.equals(BigInteger.valueOf(-1311498533L)));
        } else {
            value = value.longValue();
            expected = -1311498533L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[0].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[0].code + "' != '" + 29 + "'",
                    value.equals(BigInteger.valueOf(29L)));
        } else {
            value = value.longValue();
            expected = 29L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[0].discontinuity_counter;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[0].discontinuity_counter + "' != '" + 193 + "'",
                    value.equals(BigInteger.valueOf(193L)));
        } else {
            value = value.longValue();
            expected = 193L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[0].integer_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[0].integer_indicator + "' != '" + 250 + "'",
                    value.equals(BigInteger.valueOf(250L)));
        } else {
            value = value.longValue();
            expected = 250L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[0].widelane_integer_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[0].widelane_integer_indicator + "' != '" + 245 + "'",
                    value.equals(BigInteger.valueOf(245L)));
        } else {
            value = value.longValue();
            expected = 245L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[1].bias;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[1].bias + "' != '" + 1101319226 + "'",
                    value.equals(BigInteger.valueOf(1101319226L)));
        } else {
            value = value.longValue();
            expected = 1101319226L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[1].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[1].code + "' != '" + 207 + "'",
                    value.equals(BigInteger.valueOf(207L)));
        } else {
            value = value.longValue();
            expected = 207L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[1].discontinuity_counter;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[1].discontinuity_counter + "' != '" + 146 + "'",
                    value.equals(BigInteger.valueOf(146L)));
        } else {
            value = value.longValue();
            expected = 146L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[1].integer_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[1].integer_indicator + "' != '" + 187 + "'",
                    value.equals(BigInteger.valueOf(187L)));
        } else {
            value = value.longValue();
            expected = 187L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[1].widelane_integer_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[1].widelane_integer_indicator + "' != '" + 33 + "'",
                    value.equals(BigInteger.valueOf(33L)));
        } else {
            value = value.longValue();
            expected = 33L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[2].bias;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[2].bias + "' != '" + -64184056 + "'",
                    value.equals(BigInteger.valueOf(-64184056L)));
        } else {
            value = value.longValue();
            expected = -64184056L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[2].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[2].code + "' != '" + 114 + "'",
                    value.equals(BigInteger.valueOf(114L)));
        } else {
            value = value.longValue();
            expected = 114L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[2].discontinuity_counter;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[2].discontinuity_counter + "' != '" + 52 + "'",
                    value.equals(BigInteger.valueOf(52L)));
        } else {
            value = value.longValue();
            expected = 52L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[2].integer_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[2].integer_indicator + "' != '" + 49 + "'",
                    value.equals(BigInteger.valueOf(49L)));
        } else {
            value = value.longValue();
            expected = 49L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[2].widelane_integer_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[2].widelane_integer_indicator + "' != '" + 248 + "'",
                    value.equals(BigInteger.valueOf(248L)));
        } else {
            value = value.longValue();
            expected = 248L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[3].bias;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[3].bias + "' != '" + -240298362 + "'",
                    value.equals(BigInteger.valueOf(-240298362L)));
        } else {
            value = value.longValue();
            expected = -240298362L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[3].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[3].code + "' != '" + 166 + "'",
                    value.equals(BigInteger.valueOf(166L)));
        } else {
            value = value.longValue();
            expected = 166L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[3].discontinuity_counter;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[3].discontinuity_counter + "' != '" + 124 + "'",
                    value.equals(BigInteger.valueOf(124L)));
        } else {
            value = value.longValue();
            expected = 124L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[3].integer_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[3].integer_indicator + "' != '" + 168 + "'",
                    value.equals(BigInteger.valueOf(168L)));
        } else {
            value = value.longValue();
            expected = 168L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[3].widelane_integer_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[3].widelane_integer_indicator + "' != '" + 232 + "'",
                    value.equals(BigInteger.valueOf(232L)));
        } else {
            value = value.longValue();
            expected = 232L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[4].bias;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[4].bias + "' != '" + -1581740159 + "'",
                    value.equals(BigInteger.valueOf(-1581740159L)));
        } else {
            value = value.longValue();
            expected = -1581740159L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[4].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[4].code + "' != '" + 174 + "'",
                    value.equals(BigInteger.valueOf(174L)));
        } else {
            value = value.longValue();
            expected = 174L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[4].discontinuity_counter;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[4].discontinuity_counter + "' != '" + 155 + "'",
                    value.equals(BigInteger.valueOf(155L)));
        } else {
            value = value.longValue();
            expected = 155L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[4].integer_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[4].integer_indicator + "' != '" + 44 + "'",
                    value.equals(BigInteger.valueOf(44L)));
        } else {
            value = value.longValue();
            expected = 44L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[4].widelane_integer_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[4].widelane_integer_indicator + "' != '" + 142 + "'",
                    value.equals(BigInteger.valueOf(142L)));
        } else {
            value = value.longValue();
            expected = 142L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[5].bias;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[5].bias + "' != '" + -1730297136 + "'",
                    value.equals(BigInteger.valueOf(-1730297136L)));
        } else {
            value = value.longValue();
            expected = -1730297136L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[5].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[5].code + "' != '" + 211 + "'",
                    value.equals(BigInteger.valueOf(211L)));
        } else {
            value = value.longValue();
            expected = 211L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[5].discontinuity_counter;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[5].discontinuity_counter + "' != '" + 189 + "'",
                    value.equals(BigInteger.valueOf(189L)));
        } else {
            value = value.longValue();
            expected = 189L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[5].integer_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[5].integer_indicator + "' != '" + 15 + "'",
                    value.equals(BigInteger.valueOf(15L)));
        } else {
            value = value.longValue();
            expected = 15L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[5].widelane_integer_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[5].widelane_integer_indicator + "' != '" + 36 + "'",
                    value.equals(BigInteger.valueOf(36L)));
        } else {
            value = value.longValue();
            expected = 36L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[6].bias;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[6].bias + "' != '" + -1117221444 + "'",
                    value.equals(BigInteger.valueOf(-1117221444L)));
        } else {
            value = value.longValue();
            expected = -1117221444L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[6].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[6].code + "' != '" + 16 + "'",
                    value.equals(BigInteger.valueOf(16L)));
        } else {
            value = value.longValue();
            expected = 16L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[6].discontinuity_counter;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[6].discontinuity_counter + "' != '" + 34 + "'",
                    value.equals(BigInteger.valueOf(34L)));
        } else {
            value = value.longValue();
            expected = 34L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[6].integer_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[6].integer_indicator + "' != '" + 203 + "'",
                    value.equals(BigInteger.valueOf(203L)));
        } else {
            value = value.longValue();
            expected = 203L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[6].widelane_integer_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[6].widelane_integer_indicator + "' != '" + 87 + "'",
                    value.equals(BigInteger.valueOf(87L)));
        } else {
            value = value.longValue();
            expected = 87L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[7].bias;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[7].bias + "' != '" + -1137604357 + "'",
                    value.equals(BigInteger.valueOf(-1137604357L)));
        } else {
            value = value.longValue();
            expected = -1137604357L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[7].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[7].code + "' != '" + 102 + "'",
                    value.equals(BigInteger.valueOf(102L)));
        } else {
            value = value.longValue();
            expected = 102L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[7].discontinuity_counter;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[7].discontinuity_counter + "' != '" + 22 + "'",
                    value.equals(BigInteger.valueOf(22L)));
        } else {
            value = value.longValue();
            expected = 22L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[7].integer_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[7].integer_indicator + "' != '" + 156 + "'",
                    value.equals(BigInteger.valueOf(156L)));
        } else {
            value = value.longValue();
            expected = 156L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[7].widelane_integer_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[7].widelane_integer_indicator + "' != '" + 252 + "'",
                    value.equals(BigInteger.valueOf(252L)));
        } else {
            value = value.longValue();
            expected = 252L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[8].bias;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[8].bias + "' != '" + -1910370172 + "'",
                    value.equals(BigInteger.valueOf(-1910370172L)));
        } else {
            value = value.longValue();
            expected = -1910370172L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[8].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[8].code + "' != '" + 157 + "'",
                    value.equals(BigInteger.valueOf(157L)));
        } else {
            value = value.longValue();
            expected = 157L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[8].discontinuity_counter;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[8].discontinuity_counter + "' != '" + 49 + "'",
                    value.equals(BigInteger.valueOf(49L)));
        } else {
            value = value.longValue();
            expected = 49L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[8].integer_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[8].integer_indicator + "' != '" + 222 + "'",
                    value.equals(BigInteger.valueOf(222L)));
        } else {
            value = value.longValue();
            expected = 222L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[8].widelane_integer_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[8].widelane_integer_indicator + "' != '" + 245 + "'",
                    value.equals(BigInteger.valueOf(245L)));
        } else {
            value = value.longValue();
            expected = 245L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[9].bias;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[9].bias + "' != '" + 1247996869 + "'",
                    value.equals(BigInteger.valueOf(1247996869L)));
        } else {
            value = value.longValue();
            expected = 1247996869L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[9].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[9].code + "' != '" + 228 + "'",
                    value.equals(BigInteger.valueOf(228L)));
        } else {
            value = value.longValue();
            expected = 228L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[9].discontinuity_counter;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[9].discontinuity_counter + "' != '" + 221 + "'",
                    value.equals(BigInteger.valueOf(221L)));
        } else {
            value = value.longValue();
            expected = 221L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[9].integer_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[9].integer_indicator + "' != '" + 85 + "'",
                    value.equals(BigInteger.valueOf(85L)));
        } else {
            value = value.longValue();
            expected = 85L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[9].widelane_integer_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[9].widelane_integer_indicator + "' != '" + 139 + "'",
                    value.equals(BigInteger.valueOf(139L)));
        } else {
            value = value.longValue();
            expected = 139L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[10].bias;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[10].bias + "' != '" + -1133446161 + "'",
                    value.equals(BigInteger.valueOf(-1133446161L)));
        } else {
            value = value.longValue();
            expected = -1133446161L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[10].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[10].code + "' != '" + 107 + "'",
                    value.equals(BigInteger.valueOf(107L)));
        } else {
            value = value.longValue();
            expected = 107L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[10].discontinuity_counter;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[10].discontinuity_counter + "' != '" + 38 + "'",
                    value.equals(BigInteger.valueOf(38L)));
        } else {
            value = value.longValue();
            expected = 38L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[10].integer_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[10].integer_indicator + "' != '" + 70 + "'",
                    value.equals(BigInteger.valueOf(70L)));
        } else {
            value = value.longValue();
            expected = 70L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[10].widelane_integer_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[10].widelane_integer_indicator + "' != '" + 36 + "'",
                    value.equals(BigInteger.valueOf(36L)));
        } else {
            value = value.longValue();
            expected = 36L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[11].bias;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[11].bias + "' != '" + -720934762 + "'",
                    value.equals(BigInteger.valueOf(-720934762L)));
        } else {
            value = value.longValue();
            expected = -720934762L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[11].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[11].code + "' != '" + 124 + "'",
                    value.equals(BigInteger.valueOf(124L)));
        } else {
            value = value.longValue();
            expected = 124L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[11].discontinuity_counter;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[11].discontinuity_counter + "' != '" + 164 + "'",
                    value.equals(BigInteger.valueOf(164L)));
        } else {
            value = value.longValue();
            expected = 164L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[11].integer_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[11].integer_indicator + "' != '" + 246 + "'",
                    value.equals(BigInteger.valueOf(246L)));
        } else {
            value = value.longValue();
            expected = 246L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[11].widelane_integer_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[11].widelane_integer_indicator + "' != '" + 141 + "'",
                    value.equals(BigInteger.valueOf(141L)));
        } else {
            value = value.longValue();
            expected = 141L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[12].bias;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[12].bias + "' != '" + 706252548 + "'",
                    value.equals(BigInteger.valueOf(706252548L)));
        } else {
            value = value.longValue();
            expected = 706252548L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[12].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[12].code + "' != '" + 44 + "'",
                    value.equals(BigInteger.valueOf(44L)));
        } else {
            value = value.longValue();
            expected = 44L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[12].discontinuity_counter;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[12].discontinuity_counter + "' != '" + 192 + "'",
                    value.equals(BigInteger.valueOf(192L)));
        } else {
            value = value.longValue();
            expected = 192L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[12].integer_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[12].integer_indicator + "' != '" + 21 + "'",
                    value.equals(BigInteger.valueOf(21L)));
        } else {
            value = value.longValue();
            expected = 21L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[12].widelane_integer_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[12].widelane_integer_indicator + "' != '" + 244 + "'",
                    value.equals(BigInteger.valueOf(244L)));
        } else {
            value = value.longValue();
            expected = 244L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[13].bias;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[13].bias + "' != '" + 388855338 + "'",
                    value.equals(BigInteger.valueOf(388855338L)));
        } else {
            value = value.longValue();
            expected = 388855338L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[13].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[13].code + "' != '" + 21 + "'",
                    value.equals(BigInteger.valueOf(21L)));
        } else {
            value = value.longValue();
            expected = 21L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[13].discontinuity_counter;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[13].discontinuity_counter + "' != '" + 7 + "'",
                    value.equals(BigInteger.valueOf(7L)));
        } else {
            value = value.longValue();
            expected = 7L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[13].integer_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[13].integer_indicator + "' != '" + 84 + "'",
                    value.equals(BigInteger.valueOf(84L)));
        } else {
            value = value.longValue();
            expected = 84L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[13].widelane_integer_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[13].widelane_integer_indicator + "' != '" + 136 + "'",
                    value.equals(BigInteger.valueOf(136L)));
        } else {
            value = value.longValue();
            expected = 136L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[14].bias;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[14].bias + "' != '" + 47517353 + "'",
                    value.equals(BigInteger.valueOf(47517353L)));
        } else {
            value = value.longValue();
            expected = 47517353L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[14].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[14].code + "' != '" + 174 + "'",
                    value.equals(BigInteger.valueOf(174L)));
        } else {
            value = value.longValue();
            expected = 174L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[14].discontinuity_counter;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[14].discontinuity_counter + "' != '" + 54 + "'",
                    value.equals(BigInteger.valueOf(54L)));
        } else {
            value = value.longValue();
            expected = 54L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[14].integer_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[14].integer_indicator + "' != '" + 175 + "'",
                    value.equals(BigInteger.valueOf(175L)));
        } else {
            value = value.longValue();
            expected = 175L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[14].widelane_integer_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[14].widelane_integer_indicator + "' != '" + 129 + "'",
                    value.equals(BigInteger.valueOf(129L)));
        } else {
            value = value.longValue();
            expected = 129L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[15].bias;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[15].bias + "' != '" + -2124125745 + "'",
                    value.equals(BigInteger.valueOf(-2124125745L)));
        } else {
            value = value.longValue();
            expected = -2124125745L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[15].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[15].code + "' != '" + 197 + "'",
                    value.equals(BigInteger.valueOf(197L)));
        } else {
            value = value.longValue();
            expected = 197L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[15].discontinuity_counter;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[15].discontinuity_counter + "' != '" + 13 + "'",
                    value.equals(BigInteger.valueOf(13L)));
        } else {
            value = value.longValue();
            expected = 13L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[15].integer_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[15].integer_indicator + "' != '" + 98 + "'",
                    value.equals(BigInteger.valueOf(98L)));
        } else {
            value = value.longValue();
            expected = 98L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[15].widelane_integer_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[15].widelane_integer_indicator + "' != '" + 60 + "'",
                    value.equals(BigInteger.valueOf(60L)));
        } else {
            value = value.longValue();
            expected = 60L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[16].bias;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[16].bias + "' != '" + -1401812607 + "'",
                    value.equals(BigInteger.valueOf(-1401812607L)));
        } else {
            value = value.longValue();
            expected = -1401812607L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[16].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[16].code + "' != '" + 72 + "'",
                    value.equals(BigInteger.valueOf(72L)));
        } else {
            value = value.longValue();
            expected = 72L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[16].discontinuity_counter;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[16].discontinuity_counter + "' != '" + 140 + "'",
                    value.equals(BigInteger.valueOf(140L)));
        } else {
            value = value.longValue();
            expected = 140L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[16].integer_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[16].integer_indicator + "' != '" + 136 + "'",
                    value.equals(BigInteger.valueOf(136L)));
        } else {
            value = value.longValue();
            expected = 136L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[16].widelane_integer_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[16].widelane_integer_indicator + "' != '" + 240 + "'",
                    value.equals(BigInteger.valueOf(240L)));
        } else {
            value = value.longValue();
            expected = 240L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[17].bias;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[17].bias + "' != '" + 60257151 + "'",
                    value.equals(BigInteger.valueOf(60257151L)));
        } else {
            value = value.longValue();
            expected = 60257151L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[17].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[17].code + "' != '" + 151 + "'",
                    value.equals(BigInteger.valueOf(151L)));
        } else {
            value = value.longValue();
            expected = 151L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[17].discontinuity_counter;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[17].discontinuity_counter + "' != '" + 210 + "'",
                    value.equals(BigInteger.valueOf(210L)));
        } else {
            value = value.longValue();
            expected = 210L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[17].integer_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[17].integer_indicator + "' != '" + 150 + "'",
                    value.equals(BigInteger.valueOf(150L)));
        } else {
            value = value.longValue();
            expected = 150L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[17].widelane_integer_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[17].widelane_integer_indicator + "' != '" + 17 + "'",
                    value.equals(BigInteger.valueOf(17L)));
        } else {
            value = value.longValue();
            expected = 17L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[18].bias;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[18].bias + "' != '" + 41820677 + "'",
                    value.equals(BigInteger.valueOf(41820677L)));
        } else {
            value = value.longValue();
            expected = 41820677L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[18].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[18].code + "' != '" + 242 + "'",
                    value.equals(BigInteger.valueOf(242L)));
        } else {
            value = value.longValue();
            expected = 242L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[18].discontinuity_counter;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[18].discontinuity_counter + "' != '" + 14 + "'",
                    value.equals(BigInteger.valueOf(14L)));
        } else {
            value = value.longValue();
            expected = 14L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[18].integer_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[18].integer_indicator + "' != '" + 254 + "'",
                    value.equals(BigInteger.valueOf(254L)));
        } else {
            value = value.longValue();
            expected = 254L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[18].widelane_integer_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[18].widelane_integer_indicator + "' != '" + 215 + "'",
                    value.equals(BigInteger.valueOf(215L)));
        } else {
            value = value.longValue();
            expected = 215L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[19].bias;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[19].bias + "' != '" + 1640616471 + "'",
                    value.equals(BigInteger.valueOf(1640616471L)));
        } else {
            value = value.longValue();
            expected = 1640616471L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[19].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[19].code + "' != '" + 215 + "'",
                    value.equals(BigInteger.valueOf(215L)));
        } else {
            value = value.longValue();
            expected = 215L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[19].discontinuity_counter;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[19].discontinuity_counter + "' != '" + 176 + "'",
                    value.equals(BigInteger.valueOf(176L)));
        } else {
            value = value.longValue();
            expected = 176L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[19].integer_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[19].integer_indicator + "' != '" + 65 + "'",
                    value.equals(BigInteger.valueOf(65L)));
        } else {
            value = value.longValue();
            expected = 65L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[19].widelane_integer_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[19].widelane_integer_indicator + "' != '" + 38 + "'",
                    value.equals(BigInteger.valueOf(38L)));
        } else {
            value = value.longValue();
            expected = 38L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[20].bias;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[20].bias + "' != '" + -744786918 + "'",
                    value.equals(BigInteger.valueOf(-744786918L)));
        } else {
            value = value.longValue();
            expected = -744786918L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[20].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[20].code + "' != '" + 36 + "'",
                    value.equals(BigInteger.valueOf(36L)));
        } else {
            value = value.longValue();
            expected = 36L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[20].discontinuity_counter;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[20].discontinuity_counter + "' != '" + 224 + "'",
                    value.equals(BigInteger.valueOf(224L)));
        } else {
            value = value.longValue();
            expected = 224L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[20].integer_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[20].integer_indicator + "' != '" + 207 + "'",
                    value.equals(BigInteger.valueOf(207L)));
        } else {
            value = value.longValue();
            expected = 207L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[20].widelane_integer_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[20].widelane_integer_indicator + "' != '" + 92 + "'",
                    value.equals(BigInteger.valueOf(92L)));
        } else {
            value = value.longValue();
            expected = 92L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[21].bias;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[21].bias + "' != '" + 1966589763 + "'",
                    value.equals(BigInteger.valueOf(1966589763L)));
        } else {
            value = value.longValue();
            expected = 1966589763L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[21].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[21].code + "' != '" + 165 + "'",
                    value.equals(BigInteger.valueOf(165L)));
        } else {
            value = value.longValue();
            expected = 165L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[21].discontinuity_counter;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[21].discontinuity_counter + "' != '" + 38 + "'",
                    value.equals(BigInteger.valueOf(38L)));
        } else {
            value = value.longValue();
            expected = 38L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[21].integer_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[21].integer_indicator + "' != '" + 47 + "'",
                    value.equals(BigInteger.valueOf(47L)));
        } else {
            value = value.longValue();
            expected = 47L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[21].widelane_integer_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[21].widelane_integer_indicator + "' != '" + 102 + "'",
                    value.equals(BigInteger.valueOf(102L)));
        } else {
            value = value.longValue();
            expected = 102L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[22].bias;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[22].bias + "' != '" + 364366310 + "'",
                    value.equals(BigInteger.valueOf(364366310L)));
        } else {
            value = value.longValue();
            expected = 364366310L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[22].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[22].code + "' != '" + 36 + "'",
                    value.equals(BigInteger.valueOf(36L)));
        } else {
            value = value.longValue();
            expected = 36L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[22].discontinuity_counter;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[22].discontinuity_counter + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[22].integer_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[22].integer_indicator + "' != '" + 169 + "'",
                    value.equals(BigInteger.valueOf(169L)));
        } else {
            value = value.longValue();
            expected = 169L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[22].widelane_integer_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[22].widelane_integer_indicator + "' != '" + 33 + "'",
                    value.equals(BigInteger.valueOf(33L)));
        } else {
            value = value.longValue();
            expected = 33L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[23].bias;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[23].bias + "' != '" + -1839031379 + "'",
                    value.equals(BigInteger.valueOf(-1839031379L)));
        } else {
            value = value.longValue();
            expected = -1839031379L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[23].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[23].code + "' != '" + 42 + "'",
                    value.equals(BigInteger.valueOf(42L)));
        } else {
            value = value.longValue();
            expected = 42L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[23].discontinuity_counter;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[23].discontinuity_counter + "' != '" + 173 + "'",
                    value.equals(BigInteger.valueOf(173L)));
        } else {
            value = value.longValue();
            expected = 173L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[23].integer_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[23].integer_indicator + "' != '" + 62 + "'",
                    value.equals(BigInteger.valueOf(62L)));
        } else {
            value = value.longValue();
            expected = 62L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[23].widelane_integer_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[23].widelane_integer_indicator + "' != '" + 147 + "'",
                    value.equals(BigInteger.valueOf(147L)));
        } else {
            value = value.longValue();
            expected = 147L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[24].bias;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[24].bias + "' != '" + 31817639 + "'",
                    value.equals(BigInteger.valueOf(31817639L)));
        } else {
            value = value.longValue();
            expected = 31817639L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[24].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[24].code + "' != '" + 231 + "'",
                    value.equals(BigInteger.valueOf(231L)));
        } else {
            value = value.longValue();
            expected = 231L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[24].discontinuity_counter;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[24].discontinuity_counter + "' != '" + 82 + "'",
                    value.equals(BigInteger.valueOf(82L)));
        } else {
            value = value.longValue();
            expected = 82L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[24].integer_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[24].integer_indicator + "' != '" + 167 + "'",
                    value.equals(BigInteger.valueOf(167L)));
        } else {
            value = value.longValue();
            expected = 167L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[24].widelane_integer_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[24].widelane_integer_indicator + "' != '" + 138 + "'",
                    value.equals(BigInteger.valueOf(138L)));
        } else {
            value = value.longValue();
            expected = 138L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[25].bias;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[25].bias + "' != '" + -1619830156 + "'",
                    value.equals(BigInteger.valueOf(-1619830156L)));
        } else {
            value = value.longValue();
            expected = -1619830156L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[25].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[25].code + "' != '" + 2 + "'",
                    value.equals(BigInteger.valueOf(2L)));
        } else {
            value = value.longValue();
            expected = 2L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[25].discontinuity_counter;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[25].discontinuity_counter + "' != '" + 207 + "'",
                    value.equals(BigInteger.valueOf(207L)));
        } else {
            value = value.longValue();
            expected = 207L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[25].integer_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[25].integer_indicator + "' != '" + 127 + "'",
                    value.equals(BigInteger.valueOf(127L)));
        } else {
            value = value.longValue();
            expected = 127L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[25].widelane_integer_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[25].widelane_integer_indicator + "' != '" + 237 + "'",
                    value.equals(BigInteger.valueOf(237L)));
        } else {
            value = value.longValue();
            expected = 237L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[26].bias;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[26].bias + "' != '" + -83375622 + "'",
                    value.equals(BigInteger.valueOf(-83375622L)));
        } else {
            value = value.longValue();
            expected = -83375622L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[26].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[26].code + "' != '" + 3 + "'",
                    value.equals(BigInteger.valueOf(3L)));
        } else {
            value = value.longValue();
            expected = 3L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[26].discontinuity_counter;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[26].discontinuity_counter + "' != '" + 145 + "'",
                    value.equals(BigInteger.valueOf(145L)));
        } else {
            value = value.longValue();
            expected = 145L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[26].integer_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[26].integer_indicator + "' != '" + 42 + "'",
                    value.equals(BigInteger.valueOf(42L)));
        } else {
            value = value.longValue();
            expected = 42L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[26].widelane_integer_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[26].widelane_integer_indicator + "' != '" + 66 + "'",
                    value.equals(BigInteger.valueOf(66L)));
        } else {
            value = value.longValue();
            expected = 66L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[27].bias;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[27].bias + "' != '" + 1077458389 + "'",
                    value.equals(BigInteger.valueOf(1077458389L)));
        } else {
            value = value.longValue();
            expected = 1077458389L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[27].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[27].code + "' != '" + 2 + "'",
                    value.equals(BigInteger.valueOf(2L)));
        } else {
            value = value.longValue();
            expected = 2L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[27].discontinuity_counter;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[27].discontinuity_counter + "' != '" + 26 + "'",
                    value.equals(BigInteger.valueOf(26L)));
        } else {
            value = value.longValue();
            expected = 26L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[27].integer_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[27].integer_indicator + "' != '" + 75 + "'",
                    value.equals(BigInteger.valueOf(75L)));
        } else {
            value = value.longValue();
            expected = 75L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[27].widelane_integer_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[27].widelane_integer_indicator + "' != '" + 230 + "'",
                    value.equals(BigInteger.valueOf(230L)));
        } else {
            value = value.longValue();
            expected = 230L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[28].bias;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[28].bias + "' != '" + -883355501 + "'",
                    value.equals(BigInteger.valueOf(-883355501L)));
        } else {
            value = value.longValue();
            expected = -883355501L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[28].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[28].code + "' != '" + 97 + "'",
                    value.equals(BigInteger.valueOf(97L)));
        } else {
            value = value.longValue();
            expected = 97L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[28].discontinuity_counter;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[28].discontinuity_counter + "' != '" + 6 + "'",
                    value.equals(BigInteger.valueOf(6L)));
        } else {
            value = value.longValue();
            expected = 6L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[28].integer_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[28].integer_indicator + "' != '" + 88 + "'",
                    value.equals(BigInteger.valueOf(88L)));
        } else {
            value = value.longValue();
            expected = 88L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[28].widelane_integer_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[28].widelane_integer_indicator + "' != '" + 255 + "'",
                    value.equals(BigInteger.valueOf(255L)));
        } else {
            value = value.longValue();
            expected = 255L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[29].bias;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[29].bias + "' != '" + -1448611273 + "'",
                    value.equals(BigInteger.valueOf(-1448611273L)));
        } else {
            value = value.longValue();
            expected = -1448611273L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[29].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[29].code + "' != '" + 27 + "'",
                    value.equals(BigInteger.valueOf(27L)));
        } else {
            value = value.longValue();
            expected = 27L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[29].discontinuity_counter;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[29].discontinuity_counter + "' != '" + 230 + "'",
                    value.equals(BigInteger.valueOf(230L)));
        } else {
            value = value.longValue();
            expected = 230L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[29].integer_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[29].integer_indicator + "' != '" + 68 + "'",
                    value.equals(BigInteger.valueOf(68L)));
        } else {
            value = value.longValue();
            expected = 68L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[29].widelane_integer_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[29].widelane_integer_indicator + "' != '" + 243 + "'",
                    value.equals(BigInteger.valueOf(243L)));
        } else {
            value = value.longValue();
            expected = 243L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.dispersive_bias;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.dispersive_bias + "' != '" + 98 + "'",
                    value.equals(BigInteger.valueOf(98L)));
        } else {
            value = value.longValue();
            expected = 98L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.iod_ssr;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.iod_ssr + "' != '" + 230 + "'",
                    value.equals(BigInteger.valueOf(230L)));
        } else {
            value = value.longValue();
            expected = 230L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.mw_consistency;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.mw_consistency + "' != '" + 209 + "'",
                    value.equals(BigInteger.valueOf(209L)));
        } else {
            value = value.longValue();
            expected = 209L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sid.code + "' != '" + 82 + "'",
                    value.equals(BigInteger.valueOf(82L)));
        } else {
            value = value.longValue();
            expected = 82L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sid.sat + "' != '" + 169 + "'",
                    value.equals(BigInteger.valueOf(169L)));
        } else {
            value = value.longValue();
            expected = 169L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.time.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.time.tow + "' != '" + 210803409 + "'",
                    value.equals(BigInteger.valueOf(210803409L)));
        } else {
            value = value.longValue();
            expected = 210803409L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.time.wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.time.wn + "' != '" + 42197 + "'",
                    value.equals(BigInteger.valueOf(42197L)));
        } else {
            value = value.longValue();
            expected = 42197L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.update_interval;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.update_interval + "' != '" + 177 + "'",
                    value.equals(BigInteger.valueOf(177L)));
        } else {
            value = value.longValue();
            expected = 177L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.yaw;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.yaw + "' != '" + 5881 + "'", value.equals(BigInteger.valueOf(5881L)));
        } else {
            value = value.longValue();
            expected = 5881L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.yaw_rate;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.yaw_rate + "' != '" + 17 + "'",
                    value.equals(BigInteger.valueOf(17L)));
        } else {
            value = value.longValue();
            expected = 17L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
