/* Copyright (C) 2015-2022 Swift Navigation Inc.
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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrCodeBiases.yaml by
// generate.py. Do not modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.ssr.MsgSsrCodeBiases;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_ssr_MsgSsrCodeBiasesTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_ssr_MsgSsrCodeBiasesTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 208,
                    (byte) 90,
                    (byte) 19,
                    (byte) 23,
                    (byte) 9,
                    (byte) 66,
                    (byte) 133,
                    (byte) 241,
                    (byte) 254,
                    (byte) 132,
                    (byte) 51,
                    (byte) 4,
                    (byte) 131,
                    (byte) 240,
                    (byte) 120,
                    (byte) 83,
                    (byte) 148,
                    (byte) 209,
                    (byte) 213,
                    (byte) 62,
                    (byte) 228,
                    (byte) 232,
                    (byte) 71,
                    (byte) 66,
                    (byte) 188,
                    (byte) 210,
                    (byte) 128,
                    (byte) 54,
                    (byte) 131,
                    (byte) 152,
                    (byte) 129,
                    (byte) 111,
                    (byte) 139,
                    (byte) 242,
                    (byte) 177,
                    (byte) 145,
                    (byte) 44,
                    (byte) 9,
                    (byte) 245,
                    (byte) 207,
                    (byte) 241,
                    (byte) 202,
                    (byte) 150,
                    (byte) 141,
                    (byte) 50,
                    (byte) 159,
                    (byte) 220,
                    (byte) 139,
                    (byte) 37,
                    (byte) 187,
                    (byte) 98,
                    (byte) 191,
                    (byte) 23,
                    (byte) 128,
                    (byte) 136,
                    (byte) 167,
                    (byte) 200,
                    (byte) 6,
                    (byte) 211,
                    (byte) 90,
                    (byte) 23,
                    (byte) 244,
                    (byte) 138,
                    (byte) 215,
                    (byte) 209,
                    (byte) 139,
                    (byte) 13,
                    (byte) 101,
                    (byte) 32,
                    (byte) 7,
                    (byte) 18,
                    (byte) 29,
                    (byte) 70,
                    (byte) 250,
                    (byte) 109,
                    (byte) 73,
                    (byte) 202,
                    (byte) 79,
                    (byte) 144,
                    (byte) 9,
                    (byte) 146,
                    (byte) 69,
                    (byte) 241,
                    (byte) 52,
                    (byte) 22,
                    (byte) 99,
                    (byte) 98,
                    (byte) 204,
                    (byte) 3,
                    (byte) 171,
                    (byte) 230,
                    (byte) 180,
                    (byte) 75,
                    (byte) 62,
                    (byte) 145,
                    (byte) 86,
                    (byte) 130,
                    (byte) 31,
                    (byte) 30,
                    (byte) 155,
                    (byte) 37,
                    (byte) 18,
                    (byte) 55,
                    (byte) 210,
                    (byte) 39,
                    (byte) 127,
                    (byte) 242,
                    (byte) 66,
                    (byte) 13,
                    (byte) 237,
                    (byte) 152,
                    (byte) 170,
                    (byte) 212,
                    (byte) 15,
                    (byte) 246,
                    (byte) 59,
                    (byte) 94,
                    (byte) 180,
                    (byte) 195,
                    (byte) 157,
                    (byte) 69,
                    (byte) 100,
                    (byte) 119,
                    (byte) 16,
                    (byte) 68,
                    (byte) 179,
                    (byte) 175,
                    (byte) 144,
                    (byte) 113,
                    (byte) 81,
                    (byte) 82,
                    (byte) 30,
                    (byte) 151,
                    (byte) 21,
                    (byte) 109,
                    (byte) 41,
                    (byte) 225,
                    (byte) 8,
                    (byte) 77,
                    (byte) 164,
                    (byte) 157,
                    (byte) 0,
                    (byte) 73,
                    (byte) 30,
                    (byte) 6,
                    (byte) 78,
                    (byte) 81,
                    (byte) 143,
                    (byte) 116,
                    (byte) 240,
                    (byte) 151,
                    (byte) 55,
                    (byte) 185,
                    (byte) 169,
                    (byte) 254,
                    (byte) 51,
                    (byte) 39,
                    (byte) 74,
                    (byte) 175,
                    (byte) 247,
                    (byte) 34,
                    (byte) 97,
                    (byte) 74,
                    (byte) 97,
                    (byte) 176,
                    (byte) 48,
                    (byte) 236,
                    (byte) 173,
                    (byte) 12,
                    (byte) 174,
                    (byte) 101,
                    (byte) 130,
                    (byte) 30,
                    (byte) 169,
                    (byte) 193,
                    (byte) 190,
                    (byte) 204,
                    (byte) 196,
                    (byte) 123,
                    (byte) 107,
                    (byte) 25,
                    (byte) 225,
                    (byte) 74,
                    (byte) 9,
                    (byte) 10,
                    (byte) 55,
                    (byte) 3,
                    (byte) 131,
                    (byte) 246,
                    (byte) 99,
                    (byte) 133,
                    (byte) 34,
                    (byte) 227,
                    (byte) 203,
                    (byte) 68,
                    (byte) 18,
                    (byte) 97,
                    (byte) 223,
                    (byte) 89,
                    (byte) 192,
                    (byte) 246,
                    (byte) 50,
                    (byte) 69,
                    (byte) 91,
                    (byte) 10,
                    (byte) 151,
                    (byte) 74,
                    (byte) 118,
                    (byte) 110,
                    (byte) 36,
                    (byte) 168,
                    (byte) 247,
                    (byte) 160,
                    (byte) 77,
                    (byte) 179,
                    (byte) 141,
                    (byte) 178,
                    (byte) 99,
                    (byte) 191,
                    (byte) 120,
                    (byte) 77,
                    (byte) 192,
                    (byte) 91,
                    (byte) 224,
                    (byte) 1,
                    (byte) 226,
                    (byte) 50,
                    (byte) 87,
                    (byte) 146,
                    (byte) 148,
                    (byte) 238,
                    (byte) 100,
                    (byte) 179,
                    (byte) 125,
                    (byte) 227,
                    (byte) 215,
                    (byte) 104,
                    (byte) 184,
                    (byte) 31,
                    (byte) 57,
                    (byte) 90,
                    (byte) 79,
                    (byte) 21,
                    (byte) 156,
                    (byte) 245,
                    (byte) 81,
                    (byte) 60,
                    (byte) 93,
                    (byte) 170,
                    (byte) 60,
                    (byte) 200,
                    (byte) 167,
                    (byte) 13,
                };
        SBPMessage sbp = new SBPMessage(0x5727, 0x5e1, payload);
        MsgSsrCodeBiases msg = new MsgSsrCodeBiases(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.biases[0].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[0].code + "' != '" + 51 + "'",
                    value.equals(BigInteger.valueOf(51L)));
        } else {
            value = value.longValue();
            expected = 51L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[0].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[0].value + "' != '" + -31996 + "'",
                    value.equals(BigInteger.valueOf(-31996L)));
        } else {
            value = value.longValue();
            expected = -31996L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[1].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[1].code + "' != '" + 240 + "'",
                    value.equals(BigInteger.valueOf(240L)));
        } else {
            value = value.longValue();
            expected = 240L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[1].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[1].value + "' != '" + 21368 + "'",
                    value.equals(BigInteger.valueOf(21368L)));
        } else {
            value = value.longValue();
            expected = 21368L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[2].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[2].code + "' != '" + 148 + "'",
                    value.equals(BigInteger.valueOf(148L)));
        } else {
            value = value.longValue();
            expected = 148L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[2].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[2].value + "' != '" + -10799 + "'",
                    value.equals(BigInteger.valueOf(-10799L)));
        } else {
            value = value.longValue();
            expected = -10799L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[3].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[3].code + "' != '" + 62 + "'",
                    value.equals(BigInteger.valueOf(62L)));
        } else {
            value = value.longValue();
            expected = 62L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[3].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[3].value + "' != '" + -5916 + "'",
                    value.equals(BigInteger.valueOf(-5916L)));
        } else {
            value = value.longValue();
            expected = -5916L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[4].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[4].code + "' != '" + 71 + "'",
                    value.equals(BigInteger.valueOf(71L)));
        } else {
            value = value.longValue();
            expected = 71L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[4].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[4].value + "' != '" + -17342 + "'",
                    value.equals(BigInteger.valueOf(-17342L)));
        } else {
            value = value.longValue();
            expected = -17342L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[5].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[5].code + "' != '" + 210 + "'",
                    value.equals(BigInteger.valueOf(210L)));
        } else {
            value = value.longValue();
            expected = 210L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[5].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[5].value + "' != '" + 13952 + "'",
                    value.equals(BigInteger.valueOf(13952L)));
        } else {
            value = value.longValue();
            expected = 13952L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[6].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[6].code + "' != '" + 131 + "'",
                    value.equals(BigInteger.valueOf(131L)));
        } else {
            value = value.longValue();
            expected = 131L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[6].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[6].value + "' != '" + -32360 + "'",
                    value.equals(BigInteger.valueOf(-32360L)));
        } else {
            value = value.longValue();
            expected = -32360L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[7].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[7].code + "' != '" + 111 + "'",
                    value.equals(BigInteger.valueOf(111L)));
        } else {
            value = value.longValue();
            expected = 111L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[7].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[7].value + "' != '" + -3445 + "'",
                    value.equals(BigInteger.valueOf(-3445L)));
        } else {
            value = value.longValue();
            expected = -3445L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[8].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[8].code + "' != '" + 177 + "'",
                    value.equals(BigInteger.valueOf(177L)));
        } else {
            value = value.longValue();
            expected = 177L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[8].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[8].value + "' != '" + 11409 + "'",
                    value.equals(BigInteger.valueOf(11409L)));
        } else {
            value = value.longValue();
            expected = 11409L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[9].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[9].code + "' != '" + 9 + "'",
                    value.equals(BigInteger.valueOf(9L)));
        } else {
            value = value.longValue();
            expected = 9L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[9].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[9].value + "' != '" + -12299 + "'",
                    value.equals(BigInteger.valueOf(-12299L)));
        } else {
            value = value.longValue();
            expected = -12299L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[10].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[10].code + "' != '" + 241 + "'",
                    value.equals(BigInteger.valueOf(241L)));
        } else {
            value = value.longValue();
            expected = 241L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[10].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[10].value + "' != '" + -26934 + "'",
                    value.equals(BigInteger.valueOf(-26934L)));
        } else {
            value = value.longValue();
            expected = -26934L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[11].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[11].code + "' != '" + 141 + "'",
                    value.equals(BigInteger.valueOf(141L)));
        } else {
            value = value.longValue();
            expected = 141L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[11].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[11].value + "' != '" + -24782 + "'",
                    value.equals(BigInteger.valueOf(-24782L)));
        } else {
            value = value.longValue();
            expected = -24782L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[12].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[12].code + "' != '" + 220 + "'",
                    value.equals(BigInteger.valueOf(220L)));
        } else {
            value = value.longValue();
            expected = 220L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[12].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[12].value + "' != '" + 9611 + "'",
                    value.equals(BigInteger.valueOf(9611L)));
        } else {
            value = value.longValue();
            expected = 9611L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[13].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[13].code + "' != '" + 187 + "'",
                    value.equals(BigInteger.valueOf(187L)));
        } else {
            value = value.longValue();
            expected = 187L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[13].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[13].value + "' != '" + -16542 + "'",
                    value.equals(BigInteger.valueOf(-16542L)));
        } else {
            value = value.longValue();
            expected = -16542L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[14].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[14].code + "' != '" + 23 + "'",
                    value.equals(BigInteger.valueOf(23L)));
        } else {
            value = value.longValue();
            expected = 23L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[14].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[14].value + "' != '" + -30592 + "'",
                    value.equals(BigInteger.valueOf(-30592L)));
        } else {
            value = value.longValue();
            expected = -30592L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[15].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[15].code + "' != '" + 167 + "'",
                    value.equals(BigInteger.valueOf(167L)));
        } else {
            value = value.longValue();
            expected = 167L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[15].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[15].value + "' != '" + 1736 + "'",
                    value.equals(BigInteger.valueOf(1736L)));
        } else {
            value = value.longValue();
            expected = 1736L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[16].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[16].code + "' != '" + 211 + "'",
                    value.equals(BigInteger.valueOf(211L)));
        } else {
            value = value.longValue();
            expected = 211L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[16].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[16].value + "' != '" + 5978 + "'",
                    value.equals(BigInteger.valueOf(5978L)));
        } else {
            value = value.longValue();
            expected = 5978L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[17].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[17].code + "' != '" + 244 + "'",
                    value.equals(BigInteger.valueOf(244L)));
        } else {
            value = value.longValue();
            expected = 244L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[17].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[17].value + "' != '" + -10358 + "'",
                    value.equals(BigInteger.valueOf(-10358L)));
        } else {
            value = value.longValue();
            expected = -10358L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[18].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[18].code + "' != '" + 209 + "'",
                    value.equals(BigInteger.valueOf(209L)));
        } else {
            value = value.longValue();
            expected = 209L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[18].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[18].value + "' != '" + 3467 + "'",
                    value.equals(BigInteger.valueOf(3467L)));
        } else {
            value = value.longValue();
            expected = 3467L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[19].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[19].code + "' != '" + 101 + "'",
                    value.equals(BigInteger.valueOf(101L)));
        } else {
            value = value.longValue();
            expected = 101L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[19].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[19].value + "' != '" + 1824 + "'",
                    value.equals(BigInteger.valueOf(1824L)));
        } else {
            value = value.longValue();
            expected = 1824L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[20].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[20].code + "' != '" + 18 + "'",
                    value.equals(BigInteger.valueOf(18L)));
        } else {
            value = value.longValue();
            expected = 18L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[20].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[20].value + "' != '" + 17949 + "'",
                    value.equals(BigInteger.valueOf(17949L)));
        } else {
            value = value.longValue();
            expected = 17949L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[21].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[21].code + "' != '" + 250 + "'",
                    value.equals(BigInteger.valueOf(250L)));
        } else {
            value = value.longValue();
            expected = 250L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[21].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[21].value + "' != '" + 18797 + "'",
                    value.equals(BigInteger.valueOf(18797L)));
        } else {
            value = value.longValue();
            expected = 18797L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[22].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[22].code + "' != '" + 202 + "'",
                    value.equals(BigInteger.valueOf(202L)));
        } else {
            value = value.longValue();
            expected = 202L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[22].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[22].value + "' != '" + -28593 + "'",
                    value.equals(BigInteger.valueOf(-28593L)));
        } else {
            value = value.longValue();
            expected = -28593L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[23].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[23].code + "' != '" + 9 + "'",
                    value.equals(BigInteger.valueOf(9L)));
        } else {
            value = value.longValue();
            expected = 9L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[23].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[23].value + "' != '" + 17810 + "'",
                    value.equals(BigInteger.valueOf(17810L)));
        } else {
            value = value.longValue();
            expected = 17810L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[24].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[24].code + "' != '" + 241 + "'",
                    value.equals(BigInteger.valueOf(241L)));
        } else {
            value = value.longValue();
            expected = 241L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[24].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[24].value + "' != '" + 5684 + "'",
                    value.equals(BigInteger.valueOf(5684L)));
        } else {
            value = value.longValue();
            expected = 5684L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[25].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[25].code + "' != '" + 99 + "'",
                    value.equals(BigInteger.valueOf(99L)));
        } else {
            value = value.longValue();
            expected = 99L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[25].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[25].value + "' != '" + -13214 + "'",
                    value.equals(BigInteger.valueOf(-13214L)));
        } else {
            value = value.longValue();
            expected = -13214L;
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
        value = msg.biases[26].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[26].value + "' != '" + -6485 + "'",
                    value.equals(BigInteger.valueOf(-6485L)));
        } else {
            value = value.longValue();
            expected = -6485L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[27].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[27].code + "' != '" + 180 + "'",
                    value.equals(BigInteger.valueOf(180L)));
        } else {
            value = value.longValue();
            expected = 180L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[27].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[27].value + "' != '" + 15947 + "'",
                    value.equals(BigInteger.valueOf(15947L)));
        } else {
            value = value.longValue();
            expected = 15947L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[28].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[28].code + "' != '" + 145 + "'",
                    value.equals(BigInteger.valueOf(145L)));
        } else {
            value = value.longValue();
            expected = 145L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[28].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[28].value + "' != '" + -32170 + "'",
                    value.equals(BigInteger.valueOf(-32170L)));
        } else {
            value = value.longValue();
            expected = -32170L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[29].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[29].code + "' != '" + 31 + "'",
                    value.equals(BigInteger.valueOf(31L)));
        } else {
            value = value.longValue();
            expected = 31L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[29].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[29].value + "' != '" + -25826 + "'",
                    value.equals(BigInteger.valueOf(-25826L)));
        } else {
            value = value.longValue();
            expected = -25826L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[30].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[30].code + "' != '" + 37 + "'",
                    value.equals(BigInteger.valueOf(37L)));
        } else {
            value = value.longValue();
            expected = 37L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[30].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[30].value + "' != '" + 14098 + "'",
                    value.equals(BigInteger.valueOf(14098L)));
        } else {
            value = value.longValue();
            expected = 14098L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[31].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[31].code + "' != '" + 210 + "'",
                    value.equals(BigInteger.valueOf(210L)));
        } else {
            value = value.longValue();
            expected = 210L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[31].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[31].value + "' != '" + 32551 + "'",
                    value.equals(BigInteger.valueOf(32551L)));
        } else {
            value = value.longValue();
            expected = 32551L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[32].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[32].code + "' != '" + 242 + "'",
                    value.equals(BigInteger.valueOf(242L)));
        } else {
            value = value.longValue();
            expected = 242L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[32].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[32].value + "' != '" + 3394 + "'",
                    value.equals(BigInteger.valueOf(3394L)));
        } else {
            value = value.longValue();
            expected = 3394L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[33].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[33].code + "' != '" + 237 + "'",
                    value.equals(BigInteger.valueOf(237L)));
        } else {
            value = value.longValue();
            expected = 237L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[33].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[33].value + "' != '" + -21864 + "'",
                    value.equals(BigInteger.valueOf(-21864L)));
        } else {
            value = value.longValue();
            expected = -21864L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[34].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[34].code + "' != '" + 212 + "'",
                    value.equals(BigInteger.valueOf(212L)));
        } else {
            value = value.longValue();
            expected = 212L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[34].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[34].value + "' != '" + -2545 + "'",
                    value.equals(BigInteger.valueOf(-2545L)));
        } else {
            value = value.longValue();
            expected = -2545L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[35].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[35].code + "' != '" + 59 + "'",
                    value.equals(BigInteger.valueOf(59L)));
        } else {
            value = value.longValue();
            expected = 59L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[35].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[35].value + "' != '" + -19362 + "'",
                    value.equals(BigInteger.valueOf(-19362L)));
        } else {
            value = value.longValue();
            expected = -19362L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[36].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[36].code + "' != '" + 195 + "'",
                    value.equals(BigInteger.valueOf(195L)));
        } else {
            value = value.longValue();
            expected = 195L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[36].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[36].value + "' != '" + 17821 + "'",
                    value.equals(BigInteger.valueOf(17821L)));
        } else {
            value = value.longValue();
            expected = 17821L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[37].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[37].code + "' != '" + 100 + "'",
                    value.equals(BigInteger.valueOf(100L)));
        } else {
            value = value.longValue();
            expected = 100L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[37].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[37].value + "' != '" + 4215 + "'",
                    value.equals(BigInteger.valueOf(4215L)));
        } else {
            value = value.longValue();
            expected = 4215L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[38].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[38].code + "' != '" + 68 + "'",
                    value.equals(BigInteger.valueOf(68L)));
        } else {
            value = value.longValue();
            expected = 68L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[38].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[38].value + "' != '" + -20557 + "'",
                    value.equals(BigInteger.valueOf(-20557L)));
        } else {
            value = value.longValue();
            expected = -20557L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[39].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[39].code + "' != '" + 144 + "'",
                    value.equals(BigInteger.valueOf(144L)));
        } else {
            value = value.longValue();
            expected = 144L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[39].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[39].value + "' != '" + 20849 + "'",
                    value.equals(BigInteger.valueOf(20849L)));
        } else {
            value = value.longValue();
            expected = 20849L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[40].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[40].code + "' != '" + 82 + "'",
                    value.equals(BigInteger.valueOf(82L)));
        } else {
            value = value.longValue();
            expected = 82L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[40].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[40].value + "' != '" + -26850 + "'",
                    value.equals(BigInteger.valueOf(-26850L)));
        } else {
            value = value.longValue();
            expected = -26850L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[41].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[41].code + "' != '" + 21 + "'",
                    value.equals(BigInteger.valueOf(21L)));
        } else {
            value = value.longValue();
            expected = 21L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[41].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[41].value + "' != '" + 10605 + "'",
                    value.equals(BigInteger.valueOf(10605L)));
        } else {
            value = value.longValue();
            expected = 10605L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[42].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[42].code + "' != '" + 225 + "'",
                    value.equals(BigInteger.valueOf(225L)));
        } else {
            value = value.longValue();
            expected = 225L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[42].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[42].value + "' != '" + 19720 + "'",
                    value.equals(BigInteger.valueOf(19720L)));
        } else {
            value = value.longValue();
            expected = 19720L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[43].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[43].code + "' != '" + 164 + "'",
                    value.equals(BigInteger.valueOf(164L)));
        } else {
            value = value.longValue();
            expected = 164L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[43].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[43].value + "' != '" + 157 + "'",
                    value.equals(BigInteger.valueOf(157L)));
        } else {
            value = value.longValue();
            expected = 157L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[44].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[44].code + "' != '" + 73 + "'",
                    value.equals(BigInteger.valueOf(73L)));
        } else {
            value = value.longValue();
            expected = 73L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[44].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[44].value + "' != '" + 1566 + "'",
                    value.equals(BigInteger.valueOf(1566L)));
        } else {
            value = value.longValue();
            expected = 1566L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[45].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[45].code + "' != '" + 78 + "'",
                    value.equals(BigInteger.valueOf(78L)));
        } else {
            value = value.longValue();
            expected = 78L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[45].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[45].value + "' != '" + -28847 + "'",
                    value.equals(BigInteger.valueOf(-28847L)));
        } else {
            value = value.longValue();
            expected = -28847L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[46].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[46].code + "' != '" + 116 + "'",
                    value.equals(BigInteger.valueOf(116L)));
        } else {
            value = value.longValue();
            expected = 116L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[46].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[46].value + "' != '" + -26640 + "'",
                    value.equals(BigInteger.valueOf(-26640L)));
        } else {
            value = value.longValue();
            expected = -26640L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[47].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[47].code + "' != '" + 55 + "'",
                    value.equals(BigInteger.valueOf(55L)));
        } else {
            value = value.longValue();
            expected = 55L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[47].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[47].value + "' != '" + -22087 + "'",
                    value.equals(BigInteger.valueOf(-22087L)));
        } else {
            value = value.longValue();
            expected = -22087L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[48].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[48].code + "' != '" + 254 + "'",
                    value.equals(BigInteger.valueOf(254L)));
        } else {
            value = value.longValue();
            expected = 254L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[48].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[48].value + "' != '" + 10035 + "'",
                    value.equals(BigInteger.valueOf(10035L)));
        } else {
            value = value.longValue();
            expected = 10035L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[49].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[49].code + "' != '" + 74 + "'",
                    value.equals(BigInteger.valueOf(74L)));
        } else {
            value = value.longValue();
            expected = 74L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[49].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[49].value + "' != '" + -2129 + "'",
                    value.equals(BigInteger.valueOf(-2129L)));
        } else {
            value = value.longValue();
            expected = -2129L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[50].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[50].code + "' != '" + 34 + "'",
                    value.equals(BigInteger.valueOf(34L)));
        } else {
            value = value.longValue();
            expected = 34L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[50].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[50].value + "' != '" + 19041 + "'",
                    value.equals(BigInteger.valueOf(19041L)));
        } else {
            value = value.longValue();
            expected = 19041L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[51].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[51].code + "' != '" + 97 + "'",
                    value.equals(BigInteger.valueOf(97L)));
        } else {
            value = value.longValue();
            expected = 97L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[51].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[51].value + "' != '" + 12464 + "'",
                    value.equals(BigInteger.valueOf(12464L)));
        } else {
            value = value.longValue();
            expected = 12464L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[52].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[52].code + "' != '" + 236 + "'",
                    value.equals(BigInteger.valueOf(236L)));
        } else {
            value = value.longValue();
            expected = 236L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[52].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[52].value + "' != '" + 3245 + "'",
                    value.equals(BigInteger.valueOf(3245L)));
        } else {
            value = value.longValue();
            expected = 3245L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[53].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[53].code + "' != '" + 174 + "'",
                    value.equals(BigInteger.valueOf(174L)));
        } else {
            value = value.longValue();
            expected = 174L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[53].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[53].value + "' != '" + -32155 + "'",
                    value.equals(BigInteger.valueOf(-32155L)));
        } else {
            value = value.longValue();
            expected = -32155L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[54].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[54].code + "' != '" + 30 + "'",
                    value.equals(BigInteger.valueOf(30L)));
        } else {
            value = value.longValue();
            expected = 30L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[54].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[54].value + "' != '" + -15959 + "'",
                    value.equals(BigInteger.valueOf(-15959L)));
        } else {
            value = value.longValue();
            expected = -15959L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[55].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[55].code + "' != '" + 190 + "'",
                    value.equals(BigInteger.valueOf(190L)));
        } else {
            value = value.longValue();
            expected = 190L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[55].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[55].value + "' != '" + -15156 + "'",
                    value.equals(BigInteger.valueOf(-15156L)));
        } else {
            value = value.longValue();
            expected = -15156L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[56].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[56].code + "' != '" + 123 + "'",
                    value.equals(BigInteger.valueOf(123L)));
        } else {
            value = value.longValue();
            expected = 123L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[56].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[56].value + "' != '" + 6507 + "'",
                    value.equals(BigInteger.valueOf(6507L)));
        } else {
            value = value.longValue();
            expected = 6507L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[57].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[57].code + "' != '" + 225 + "'",
                    value.equals(BigInteger.valueOf(225L)));
        } else {
            value = value.longValue();
            expected = 225L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[57].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[57].value + "' != '" + 2378 + "'",
                    value.equals(BigInteger.valueOf(2378L)));
        } else {
            value = value.longValue();
            expected = 2378L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[58].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[58].code + "' != '" + 10 + "'",
                    value.equals(BigInteger.valueOf(10L)));
        } else {
            value = value.longValue();
            expected = 10L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[58].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[58].value + "' != '" + 823 + "'",
                    value.equals(BigInteger.valueOf(823L)));
        } else {
            value = value.longValue();
            expected = 823L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[59].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[59].code + "' != '" + 131 + "'",
                    value.equals(BigInteger.valueOf(131L)));
        } else {
            value = value.longValue();
            expected = 131L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[59].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[59].value + "' != '" + 25590 + "'",
                    value.equals(BigInteger.valueOf(25590L)));
        } else {
            value = value.longValue();
            expected = 25590L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[60].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[60].code + "' != '" + 133 + "'",
                    value.equals(BigInteger.valueOf(133L)));
        } else {
            value = value.longValue();
            expected = 133L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[60].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[60].value + "' != '" + -7390 + "'",
                    value.equals(BigInteger.valueOf(-7390L)));
        } else {
            value = value.longValue();
            expected = -7390L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[61].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[61].code + "' != '" + 203 + "'",
                    value.equals(BigInteger.valueOf(203L)));
        } else {
            value = value.longValue();
            expected = 203L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[61].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[61].value + "' != '" + 4676 + "'",
                    value.equals(BigInteger.valueOf(4676L)));
        } else {
            value = value.longValue();
            expected = 4676L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[62].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[62].code + "' != '" + 97 + "'",
                    value.equals(BigInteger.valueOf(97L)));
        } else {
            value = value.longValue();
            expected = 97L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[62].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[62].value + "' != '" + 23007 + "'",
                    value.equals(BigInteger.valueOf(23007L)));
        } else {
            value = value.longValue();
            expected = 23007L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[63].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[63].code + "' != '" + 192 + "'",
                    value.equals(BigInteger.valueOf(192L)));
        } else {
            value = value.longValue();
            expected = 192L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[63].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[63].value + "' != '" + 13046 + "'",
                    value.equals(BigInteger.valueOf(13046L)));
        } else {
            value = value.longValue();
            expected = 13046L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[64].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[64].code + "' != '" + 69 + "'",
                    value.equals(BigInteger.valueOf(69L)));
        } else {
            value = value.longValue();
            expected = 69L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[64].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[64].value + "' != '" + 2651 + "'",
                    value.equals(BigInteger.valueOf(2651L)));
        } else {
            value = value.longValue();
            expected = 2651L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[65].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[65].code + "' != '" + 151 + "'",
                    value.equals(BigInteger.valueOf(151L)));
        } else {
            value = value.longValue();
            expected = 151L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[65].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[65].value + "' != '" + 30282 + "'",
                    value.equals(BigInteger.valueOf(30282L)));
        } else {
            value = value.longValue();
            expected = 30282L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[66].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[66].code + "' != '" + 110 + "'",
                    value.equals(BigInteger.valueOf(110L)));
        } else {
            value = value.longValue();
            expected = 110L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[66].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[66].value + "' != '" + -22492 + "'",
                    value.equals(BigInteger.valueOf(-22492L)));
        } else {
            value = value.longValue();
            expected = -22492L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[67].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[67].code + "' != '" + 247 + "'",
                    value.equals(BigInteger.valueOf(247L)));
        } else {
            value = value.longValue();
            expected = 247L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[67].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[67].value + "' != '" + 19872 + "'",
                    value.equals(BigInteger.valueOf(19872L)));
        } else {
            value = value.longValue();
            expected = 19872L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[68].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[68].code + "' != '" + 179 + "'",
                    value.equals(BigInteger.valueOf(179L)));
        } else {
            value = value.longValue();
            expected = 179L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[68].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[68].value + "' != '" + -19827 + "'",
                    value.equals(BigInteger.valueOf(-19827L)));
        } else {
            value = value.longValue();
            expected = -19827L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[69].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[69].code + "' != '" + 99 + "'",
                    value.equals(BigInteger.valueOf(99L)));
        } else {
            value = value.longValue();
            expected = 99L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[69].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[69].value + "' != '" + 30911 + "'",
                    value.equals(BigInteger.valueOf(30911L)));
        } else {
            value = value.longValue();
            expected = 30911L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[70].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[70].code + "' != '" + 77 + "'",
                    value.equals(BigInteger.valueOf(77L)));
        } else {
            value = value.longValue();
            expected = 77L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[70].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[70].value + "' != '" + 23488 + "'",
                    value.equals(BigInteger.valueOf(23488L)));
        } else {
            value = value.longValue();
            expected = 23488L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[71].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[71].code + "' != '" + 224 + "'",
                    value.equals(BigInteger.valueOf(224L)));
        } else {
            value = value.longValue();
            expected = 224L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[71].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[71].value + "' != '" + -7679 + "'",
                    value.equals(BigInteger.valueOf(-7679L)));
        } else {
            value = value.longValue();
            expected = -7679L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[72].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[72].code + "' != '" + 50 + "'",
                    value.equals(BigInteger.valueOf(50L)));
        } else {
            value = value.longValue();
            expected = 50L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[72].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[72].value + "' != '" + -28073 + "'",
                    value.equals(BigInteger.valueOf(-28073L)));
        } else {
            value = value.longValue();
            expected = -28073L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[73].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[73].code + "' != '" + 148 + "'",
                    value.equals(BigInteger.valueOf(148L)));
        } else {
            value = value.longValue();
            expected = 148L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[73].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[73].value + "' != '" + 25838 + "'",
                    value.equals(BigInteger.valueOf(25838L)));
        } else {
            value = value.longValue();
            expected = 25838L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[74].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[74].code + "' != '" + 179 + "'",
                    value.equals(BigInteger.valueOf(179L)));
        } else {
            value = value.longValue();
            expected = 179L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[74].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[74].value + "' != '" + -7299 + "'",
                    value.equals(BigInteger.valueOf(-7299L)));
        } else {
            value = value.longValue();
            expected = -7299L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[75].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[75].code + "' != '" + 215 + "'",
                    value.equals(BigInteger.valueOf(215L)));
        } else {
            value = value.longValue();
            expected = 215L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[75].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[75].value + "' != '" + -18328 + "'",
                    value.equals(BigInteger.valueOf(-18328L)));
        } else {
            value = value.longValue();
            expected = -18328L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[76].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[76].code + "' != '" + 31 + "'",
                    value.equals(BigInteger.valueOf(31L)));
        } else {
            value = value.longValue();
            expected = 31L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[76].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[76].value + "' != '" + 23097 + "'",
                    value.equals(BigInteger.valueOf(23097L)));
        } else {
            value = value.longValue();
            expected = 23097L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[77].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[77].code + "' != '" + 79 + "'",
                    value.equals(BigInteger.valueOf(79L)));
        } else {
            value = value.longValue();
            expected = 79L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[77].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[77].value + "' != '" + -25579 + "'",
                    value.equals(BigInteger.valueOf(-25579L)));
        } else {
            value = value.longValue();
            expected = -25579L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[78].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[78].code + "' != '" + 245 + "'",
                    value.equals(BigInteger.valueOf(245L)));
        } else {
            value = value.longValue();
            expected = 245L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[78].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[78].value + "' != '" + 15441 + "'",
                    value.equals(BigInteger.valueOf(15441L)));
        } else {
            value = value.longValue();
            expected = 15441L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[79].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[79].code + "' != '" + 93 + "'",
                    value.equals(BigInteger.valueOf(93L)));
        } else {
            value = value.longValue();
            expected = 93L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[79].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[79].value + "' != '" + 15530 + "'",
                    value.equals(BigInteger.valueOf(15530L)));
        } else {
            value = value.longValue();
            expected = 15530L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[80].code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[80].code + "' != '" + 200 + "'",
                    value.equals(BigInteger.valueOf(200L)));
        } else {
            value = value.longValue();
            expected = 200L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.biases[80].value;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.biases[80].value + "' != '" + 3495 + "'",
                    value.equals(BigInteger.valueOf(3495L)));
        } else {
            value = value.longValue();
            expected = 3495L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.iod_ssr;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.iod_ssr + "' != '" + 132 + "'",
                    value.equals(BigInteger.valueOf(132L)));
        } else {
            value = value.longValue();
            expected = 132L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sid.code + "' != '" + 241 + "'",
                    value.equals(BigInteger.valueOf(241L)));
        } else {
            value = value.longValue();
            expected = 241L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sid.sat + "' != '" + 133 + "'",
                    value.equals(BigInteger.valueOf(133L)));
        } else {
            value = value.longValue();
            expected = 133L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.time.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.time.tow + "' != '" + 387144400 + "'",
                    value.equals(BigInteger.valueOf(387144400L)));
        } else {
            value = value.longValue();
            expected = 387144400L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.time.wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.time.wn + "' != '" + 16905 + "'",
                    value.equals(BigInteger.valueOf(16905L)));
        } else {
            value = value.longValue();
            expected = 16905L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.update_interval;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.update_interval + "' != '" + 254 + "'",
                    value.equals(BigInteger.valueOf(254L)));
        } else {
            value = value.longValue();
            expected = 254L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
