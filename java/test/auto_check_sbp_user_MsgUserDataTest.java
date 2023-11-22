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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/user/test_MsgUserData.yaml by
// generate.py. Do not modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.user.MsgUserData;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_user_MsgUserDataTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_user_MsgUserDataTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 53,
                    (byte) 5,
                    (byte) 172,
                    (byte) 138,
                    (byte) 50,
                    (byte) 49,
                    (byte) 206,
                    (byte) 234,
                    (byte) 149,
                    (byte) 204,
                    (byte) 113,
                    (byte) 31,
                    (byte) 108,
                    (byte) 188,
                    (byte) 179,
                    (byte) 154,
                    (byte) 156,
                    (byte) 167,
                    (byte) 145,
                    (byte) 139,
                    (byte) 42,
                    (byte) 207,
                    (byte) 126,
                    (byte) 242,
                    (byte) 193,
                    (byte) 9,
                    (byte) 58,
                    (byte) 75,
                    (byte) 8,
                    (byte) 135,
                    (byte) 11,
                    (byte) 92,
                    (byte) 131,
                    (byte) 245,
                    (byte) 24,
                    (byte) 90,
                    (byte) 255,
                    (byte) 30,
                    (byte) 58,
                    (byte) 31,
                    (byte) 109,
                    (byte) 148,
                    (byte) 56,
                    (byte) 178,
                    (byte) 140,
                    (byte) 30,
                    (byte) 159,
                    (byte) 70,
                    (byte) 17,
                    (byte) 170,
                    (byte) 50,
                    (byte) 148,
                    (byte) 1,
                    (byte) 99,
                    (byte) 112,
                    (byte) 88,
                    (byte) 217,
                    (byte) 36,
                    (byte) 84,
                    (byte) 34,
                    (byte) 234,
                    (byte) 82,
                    (byte) 144,
                    (byte) 144,
                    (byte) 97,
                    (byte) 96,
                    (byte) 75,
                    (byte) 174,
                    (byte) 58,
                    (byte) 219,
                    (byte) 180,
                    (byte) 148,
                    (byte) 247,
                    (byte) 59,
                    (byte) 2,
                    (byte) 116,
                    (byte) 214,
                    (byte) 114,
                    (byte) 55,
                    (byte) 134,
                    (byte) 54,
                    (byte) 119,
                    (byte) 108,
                    (byte) 128,
                    (byte) 73,
                    (byte) 181,
                    (byte) 20,
                    (byte) 233,
                    (byte) 23,
                    (byte) 23,
                    (byte) 73,
                    (byte) 119,
                    (byte) 136,
                    (byte) 231,
                    (byte) 189,
                    (byte) 26,
                    (byte) 174,
                    (byte) 128,
                    (byte) 93,
                    (byte) 30,
                    (byte) 76,
                    (byte) 45,
                    (byte) 109,
                    (byte) 134,
                    (byte) 81,
                    (byte) 0,
                    (byte) 116,
                    (byte) 158,
                    (byte) 127,
                    (byte) 40,
                    (byte) 133,
                    (byte) 208,
                    (byte) 134,
                    (byte) 127,
                    (byte) 140,
                    (byte) 232,
                    (byte) 183,
                    (byte) 184,
                    (byte) 108,
                    (byte) 6,
                    (byte) 228,
                    (byte) 54,
                    (byte) 238,
                    (byte) 59,
                    (byte) 220,
                    (byte) 30,
                    (byte) 228,
                    (byte) 212,
                    (byte) 50,
                    (byte) 182,
                    (byte) 97,
                    (byte) 20,
                    (byte) 41,
                    (byte) 76,
                    (byte) 227,
                    (byte) 88,
                    (byte) 12,
                    (byte) 95,
                    (byte) 112,
                    (byte) 209,
                    (byte) 183,
                    (byte) 127,
                    (byte) 4,
                    (byte) 165,
                    (byte) 189,
                    (byte) 44,
                    (byte) 239,
                    (byte) 232,
                    (byte) 132,
                    (byte) 9,
                    (byte) 114,
                    (byte) 184,
                    (byte) 249,
                    (byte) 208,
                    (byte) 246,
                    (byte) 194,
                    (byte) 250,
                    (byte) 2,
                    (byte) 97,
                    (byte) 173,
                    (byte) 157,
                    (byte) 202,
                    (byte) 172,
                    (byte) 180,
                    (byte) 150,
                    (byte) 213,
                    (byte) 193,
                    (byte) 177,
                    (byte) 209,
                    (byte) 156,
                    (byte) 20,
                    (byte) 174,
                    (byte) 18,
                    (byte) 73,
                    (byte) 132,
                    (byte) 215,
                    (byte) 115,
                    (byte) 128,
                    (byte) 175,
                    (byte) 169,
                    (byte) 116,
                    (byte) 132,
                    (byte) 100,
                    (byte) 72,
                    (byte) 45,
                    (byte) 25,
                    (byte) 14,
                    (byte) 205,
                    (byte) 213,
                    (byte) 145,
                    (byte) 68,
                    (byte) 137,
                    (byte) 249,
                    (byte) 54,
                    (byte) 40,
                    (byte) 174,
                    (byte) 215,
                    (byte) 148,
                    (byte) 166,
                    (byte) 190,
                    (byte) 63,
                    (byte) 118,
                    (byte) 6,
                    (byte) 165,
                    (byte) 212,
                    (byte) 74,
                    (byte) 68,
                    (byte) 200,
                    (byte) 38,
                    (byte) 139,
                    (byte) 212,
                    (byte) 112,
                    (byte) 45,
                    (byte) 167,
                    (byte) 236,
                    (byte) 255,
                    (byte) 106,
                    (byte) 92,
                    (byte) 132,
                    (byte) 59,
                    (byte) 61,
                    (byte) 233,
                    (byte) 3,
                    (byte) 246,
                    (byte) 158,
                    (byte) 83,
                    (byte) 134,
                    (byte) 246,
                    (byte) 154,
                    (byte) 17,
                    (byte) 0,
                    (byte) 6,
                    (byte) 56,
                    (byte) 216,
                    (byte) 19,
                    (byte) 216,
                    (byte) 70,
                    (byte) 71,
                    (byte) 161,
                    (byte) 184,
                    (byte) 5,
                    (byte) 177,
                    (byte) 45,
                    (byte) 37,
                    (byte) 98,
                    (byte) 56,
                    (byte) 149,
                    (byte) 0,
                    (byte) 73,
                    (byte) 221,
                    (byte) 105,
                    (byte) 239,
                    (byte) 168,
                    (byte) 205,
                    (byte) 85,
                };
        SBPMessage sbp = new SBPMessage(0x217e, 0x800, payload);
        MsgUserData msg = new MsgUserData(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.contents[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[0] + "' != '" + 53 + "'",
                    value.equals(BigInteger.valueOf(53L)));
        } else {
            value = value.longValue();
            expected = 53L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[1] + "' != '" + 5 + "'",
                    value.equals(BigInteger.valueOf(5L)));
        } else {
            value = value.longValue();
            expected = 5L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[2] + "' != '" + 172 + "'",
                    value.equals(BigInteger.valueOf(172L)));
        } else {
            value = value.longValue();
            expected = 172L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[3] + "' != '" + 138 + "'",
                    value.equals(BigInteger.valueOf(138L)));
        } else {
            value = value.longValue();
            expected = 138L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[4];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[4] + "' != '" + 50 + "'",
                    value.equals(BigInteger.valueOf(50L)));
        } else {
            value = value.longValue();
            expected = 50L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[5];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[5] + "' != '" + 49 + "'",
                    value.equals(BigInteger.valueOf(49L)));
        } else {
            value = value.longValue();
            expected = 49L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[6];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[6] + "' != '" + 206 + "'",
                    value.equals(BigInteger.valueOf(206L)));
        } else {
            value = value.longValue();
            expected = 206L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[7];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[7] + "' != '" + 234 + "'",
                    value.equals(BigInteger.valueOf(234L)));
        } else {
            value = value.longValue();
            expected = 234L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[8];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[8] + "' != '" + 149 + "'",
                    value.equals(BigInteger.valueOf(149L)));
        } else {
            value = value.longValue();
            expected = 149L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[9];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[9] + "' != '" + 204 + "'",
                    value.equals(BigInteger.valueOf(204L)));
        } else {
            value = value.longValue();
            expected = 204L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[10];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[10] + "' != '" + 113 + "'",
                    value.equals(BigInteger.valueOf(113L)));
        } else {
            value = value.longValue();
            expected = 113L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[11];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[11] + "' != '" + 31 + "'",
                    value.equals(BigInteger.valueOf(31L)));
        } else {
            value = value.longValue();
            expected = 31L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[12];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[12] + "' != '" + 108 + "'",
                    value.equals(BigInteger.valueOf(108L)));
        } else {
            value = value.longValue();
            expected = 108L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[13];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[13] + "' != '" + 188 + "'",
                    value.equals(BigInteger.valueOf(188L)));
        } else {
            value = value.longValue();
            expected = 188L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[14];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[14] + "' != '" + 179 + "'",
                    value.equals(BigInteger.valueOf(179L)));
        } else {
            value = value.longValue();
            expected = 179L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[15];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[15] + "' != '" + 154 + "'",
                    value.equals(BigInteger.valueOf(154L)));
        } else {
            value = value.longValue();
            expected = 154L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[16];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[16] + "' != '" + 156 + "'",
                    value.equals(BigInteger.valueOf(156L)));
        } else {
            value = value.longValue();
            expected = 156L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[17];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[17] + "' != '" + 167 + "'",
                    value.equals(BigInteger.valueOf(167L)));
        } else {
            value = value.longValue();
            expected = 167L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[18];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[18] + "' != '" + 145 + "'",
                    value.equals(BigInteger.valueOf(145L)));
        } else {
            value = value.longValue();
            expected = 145L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[19];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[19] + "' != '" + 139 + "'",
                    value.equals(BigInteger.valueOf(139L)));
        } else {
            value = value.longValue();
            expected = 139L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[20];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[20] + "' != '" + 42 + "'",
                    value.equals(BigInteger.valueOf(42L)));
        } else {
            value = value.longValue();
            expected = 42L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[21];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[21] + "' != '" + 207 + "'",
                    value.equals(BigInteger.valueOf(207L)));
        } else {
            value = value.longValue();
            expected = 207L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[22];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[22] + "' != '" + 126 + "'",
                    value.equals(BigInteger.valueOf(126L)));
        } else {
            value = value.longValue();
            expected = 126L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[23];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[23] + "' != '" + 242 + "'",
                    value.equals(BigInteger.valueOf(242L)));
        } else {
            value = value.longValue();
            expected = 242L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[24];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[24] + "' != '" + 193 + "'",
                    value.equals(BigInteger.valueOf(193L)));
        } else {
            value = value.longValue();
            expected = 193L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[25];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[25] + "' != '" + 9 + "'",
                    value.equals(BigInteger.valueOf(9L)));
        } else {
            value = value.longValue();
            expected = 9L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[26];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[26] + "' != '" + 58 + "'",
                    value.equals(BigInteger.valueOf(58L)));
        } else {
            value = value.longValue();
            expected = 58L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[27];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[27] + "' != '" + 75 + "'",
                    value.equals(BigInteger.valueOf(75L)));
        } else {
            value = value.longValue();
            expected = 75L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[28];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[28] + "' != '" + 8 + "'",
                    value.equals(BigInteger.valueOf(8L)));
        } else {
            value = value.longValue();
            expected = 8L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[29];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[29] + "' != '" + 135 + "'",
                    value.equals(BigInteger.valueOf(135L)));
        } else {
            value = value.longValue();
            expected = 135L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[30];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[30] + "' != '" + 11 + "'",
                    value.equals(BigInteger.valueOf(11L)));
        } else {
            value = value.longValue();
            expected = 11L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[31];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[31] + "' != '" + 92 + "'",
                    value.equals(BigInteger.valueOf(92L)));
        } else {
            value = value.longValue();
            expected = 92L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[32];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[32] + "' != '" + 131 + "'",
                    value.equals(BigInteger.valueOf(131L)));
        } else {
            value = value.longValue();
            expected = 131L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[33];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[33] + "' != '" + 245 + "'",
                    value.equals(BigInteger.valueOf(245L)));
        } else {
            value = value.longValue();
            expected = 245L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[34];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[34] + "' != '" + 24 + "'",
                    value.equals(BigInteger.valueOf(24L)));
        } else {
            value = value.longValue();
            expected = 24L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[35];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[35] + "' != '" + 90 + "'",
                    value.equals(BigInteger.valueOf(90L)));
        } else {
            value = value.longValue();
            expected = 90L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[36];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[36] + "' != '" + 255 + "'",
                    value.equals(BigInteger.valueOf(255L)));
        } else {
            value = value.longValue();
            expected = 255L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[37];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[37] + "' != '" + 30 + "'",
                    value.equals(BigInteger.valueOf(30L)));
        } else {
            value = value.longValue();
            expected = 30L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[38];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[38] + "' != '" + 58 + "'",
                    value.equals(BigInteger.valueOf(58L)));
        } else {
            value = value.longValue();
            expected = 58L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[39];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[39] + "' != '" + 31 + "'",
                    value.equals(BigInteger.valueOf(31L)));
        } else {
            value = value.longValue();
            expected = 31L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[40];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[40] + "' != '" + 109 + "'",
                    value.equals(BigInteger.valueOf(109L)));
        } else {
            value = value.longValue();
            expected = 109L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[41];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[41] + "' != '" + 148 + "'",
                    value.equals(BigInteger.valueOf(148L)));
        } else {
            value = value.longValue();
            expected = 148L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[42];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[42] + "' != '" + 56 + "'",
                    value.equals(BigInteger.valueOf(56L)));
        } else {
            value = value.longValue();
            expected = 56L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[43];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[43] + "' != '" + 178 + "'",
                    value.equals(BigInteger.valueOf(178L)));
        } else {
            value = value.longValue();
            expected = 178L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[44];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[44] + "' != '" + 140 + "'",
                    value.equals(BigInteger.valueOf(140L)));
        } else {
            value = value.longValue();
            expected = 140L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[45];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[45] + "' != '" + 30 + "'",
                    value.equals(BigInteger.valueOf(30L)));
        } else {
            value = value.longValue();
            expected = 30L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[46];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[46] + "' != '" + 159 + "'",
                    value.equals(BigInteger.valueOf(159L)));
        } else {
            value = value.longValue();
            expected = 159L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[47];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[47] + "' != '" + 70 + "'",
                    value.equals(BigInteger.valueOf(70L)));
        } else {
            value = value.longValue();
            expected = 70L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[48];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[48] + "' != '" + 17 + "'",
                    value.equals(BigInteger.valueOf(17L)));
        } else {
            value = value.longValue();
            expected = 17L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[49];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[49] + "' != '" + 170 + "'",
                    value.equals(BigInteger.valueOf(170L)));
        } else {
            value = value.longValue();
            expected = 170L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[50];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[50] + "' != '" + 50 + "'",
                    value.equals(BigInteger.valueOf(50L)));
        } else {
            value = value.longValue();
            expected = 50L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[51];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[51] + "' != '" + 148 + "'",
                    value.equals(BigInteger.valueOf(148L)));
        } else {
            value = value.longValue();
            expected = 148L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[52];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[52] + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[53];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[53] + "' != '" + 99 + "'",
                    value.equals(BigInteger.valueOf(99L)));
        } else {
            value = value.longValue();
            expected = 99L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[54];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[54] + "' != '" + 112 + "'",
                    value.equals(BigInteger.valueOf(112L)));
        } else {
            value = value.longValue();
            expected = 112L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[55];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[55] + "' != '" + 88 + "'",
                    value.equals(BigInteger.valueOf(88L)));
        } else {
            value = value.longValue();
            expected = 88L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[56];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[56] + "' != '" + 217 + "'",
                    value.equals(BigInteger.valueOf(217L)));
        } else {
            value = value.longValue();
            expected = 217L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[57];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[57] + "' != '" + 36 + "'",
                    value.equals(BigInteger.valueOf(36L)));
        } else {
            value = value.longValue();
            expected = 36L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[58];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[58] + "' != '" + 84 + "'",
                    value.equals(BigInteger.valueOf(84L)));
        } else {
            value = value.longValue();
            expected = 84L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[59];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[59] + "' != '" + 34 + "'",
                    value.equals(BigInteger.valueOf(34L)));
        } else {
            value = value.longValue();
            expected = 34L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[60];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[60] + "' != '" + 234 + "'",
                    value.equals(BigInteger.valueOf(234L)));
        } else {
            value = value.longValue();
            expected = 234L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[61];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[61] + "' != '" + 82 + "'",
                    value.equals(BigInteger.valueOf(82L)));
        } else {
            value = value.longValue();
            expected = 82L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[62];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[62] + "' != '" + 144 + "'",
                    value.equals(BigInteger.valueOf(144L)));
        } else {
            value = value.longValue();
            expected = 144L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[63];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[63] + "' != '" + 144 + "'",
                    value.equals(BigInteger.valueOf(144L)));
        } else {
            value = value.longValue();
            expected = 144L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[64];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[64] + "' != '" + 97 + "'",
                    value.equals(BigInteger.valueOf(97L)));
        } else {
            value = value.longValue();
            expected = 97L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[65];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[65] + "' != '" + 96 + "'",
                    value.equals(BigInteger.valueOf(96L)));
        } else {
            value = value.longValue();
            expected = 96L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[66];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[66] + "' != '" + 75 + "'",
                    value.equals(BigInteger.valueOf(75L)));
        } else {
            value = value.longValue();
            expected = 75L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[67];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[67] + "' != '" + 174 + "'",
                    value.equals(BigInteger.valueOf(174L)));
        } else {
            value = value.longValue();
            expected = 174L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[68];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[68] + "' != '" + 58 + "'",
                    value.equals(BigInteger.valueOf(58L)));
        } else {
            value = value.longValue();
            expected = 58L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[69];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[69] + "' != '" + 219 + "'",
                    value.equals(BigInteger.valueOf(219L)));
        } else {
            value = value.longValue();
            expected = 219L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[70];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[70] + "' != '" + 180 + "'",
                    value.equals(BigInteger.valueOf(180L)));
        } else {
            value = value.longValue();
            expected = 180L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[71];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[71] + "' != '" + 148 + "'",
                    value.equals(BigInteger.valueOf(148L)));
        } else {
            value = value.longValue();
            expected = 148L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[72];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[72] + "' != '" + 247 + "'",
                    value.equals(BigInteger.valueOf(247L)));
        } else {
            value = value.longValue();
            expected = 247L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[73];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[73] + "' != '" + 59 + "'",
                    value.equals(BigInteger.valueOf(59L)));
        } else {
            value = value.longValue();
            expected = 59L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[74];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[74] + "' != '" + 2 + "'",
                    value.equals(BigInteger.valueOf(2L)));
        } else {
            value = value.longValue();
            expected = 2L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[75];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[75] + "' != '" + 116 + "'",
                    value.equals(BigInteger.valueOf(116L)));
        } else {
            value = value.longValue();
            expected = 116L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[76];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[76] + "' != '" + 214 + "'",
                    value.equals(BigInteger.valueOf(214L)));
        } else {
            value = value.longValue();
            expected = 214L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[77];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[77] + "' != '" + 114 + "'",
                    value.equals(BigInteger.valueOf(114L)));
        } else {
            value = value.longValue();
            expected = 114L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[78];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[78] + "' != '" + 55 + "'",
                    value.equals(BigInteger.valueOf(55L)));
        } else {
            value = value.longValue();
            expected = 55L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[79];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[79] + "' != '" + 134 + "'",
                    value.equals(BigInteger.valueOf(134L)));
        } else {
            value = value.longValue();
            expected = 134L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[80];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[80] + "' != '" + 54 + "'",
                    value.equals(BigInteger.valueOf(54L)));
        } else {
            value = value.longValue();
            expected = 54L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[81];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[81] + "' != '" + 119 + "'",
                    value.equals(BigInteger.valueOf(119L)));
        } else {
            value = value.longValue();
            expected = 119L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[82];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[82] + "' != '" + 108 + "'",
                    value.equals(BigInteger.valueOf(108L)));
        } else {
            value = value.longValue();
            expected = 108L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[83];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[83] + "' != '" + 128 + "'",
                    value.equals(BigInteger.valueOf(128L)));
        } else {
            value = value.longValue();
            expected = 128L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[84];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[84] + "' != '" + 73 + "'",
                    value.equals(BigInteger.valueOf(73L)));
        } else {
            value = value.longValue();
            expected = 73L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[85];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[85] + "' != '" + 181 + "'",
                    value.equals(BigInteger.valueOf(181L)));
        } else {
            value = value.longValue();
            expected = 181L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[86];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[86] + "' != '" + 20 + "'",
                    value.equals(BigInteger.valueOf(20L)));
        } else {
            value = value.longValue();
            expected = 20L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[87];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[87] + "' != '" + 233 + "'",
                    value.equals(BigInteger.valueOf(233L)));
        } else {
            value = value.longValue();
            expected = 233L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[88];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[88] + "' != '" + 23 + "'",
                    value.equals(BigInteger.valueOf(23L)));
        } else {
            value = value.longValue();
            expected = 23L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[89];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[89] + "' != '" + 23 + "'",
                    value.equals(BigInteger.valueOf(23L)));
        } else {
            value = value.longValue();
            expected = 23L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[90];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[90] + "' != '" + 73 + "'",
                    value.equals(BigInteger.valueOf(73L)));
        } else {
            value = value.longValue();
            expected = 73L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[91];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[91] + "' != '" + 119 + "'",
                    value.equals(BigInteger.valueOf(119L)));
        } else {
            value = value.longValue();
            expected = 119L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[92];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[92] + "' != '" + 136 + "'",
                    value.equals(BigInteger.valueOf(136L)));
        } else {
            value = value.longValue();
            expected = 136L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[93];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[93] + "' != '" + 231 + "'",
                    value.equals(BigInteger.valueOf(231L)));
        } else {
            value = value.longValue();
            expected = 231L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[94];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[94] + "' != '" + 189 + "'",
                    value.equals(BigInteger.valueOf(189L)));
        } else {
            value = value.longValue();
            expected = 189L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[95];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[95] + "' != '" + 26 + "'",
                    value.equals(BigInteger.valueOf(26L)));
        } else {
            value = value.longValue();
            expected = 26L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[96];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[96] + "' != '" + 174 + "'",
                    value.equals(BigInteger.valueOf(174L)));
        } else {
            value = value.longValue();
            expected = 174L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[97];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[97] + "' != '" + 128 + "'",
                    value.equals(BigInteger.valueOf(128L)));
        } else {
            value = value.longValue();
            expected = 128L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[98];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[98] + "' != '" + 93 + "'",
                    value.equals(BigInteger.valueOf(93L)));
        } else {
            value = value.longValue();
            expected = 93L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[99];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[99] + "' != '" + 30 + "'",
                    value.equals(BigInteger.valueOf(30L)));
        } else {
            value = value.longValue();
            expected = 30L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[100];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[100] + "' != '" + 76 + "'",
                    value.equals(BigInteger.valueOf(76L)));
        } else {
            value = value.longValue();
            expected = 76L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[101];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[101] + "' != '" + 45 + "'",
                    value.equals(BigInteger.valueOf(45L)));
        } else {
            value = value.longValue();
            expected = 45L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[102];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[102] + "' != '" + 109 + "'",
                    value.equals(BigInteger.valueOf(109L)));
        } else {
            value = value.longValue();
            expected = 109L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[103];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[103] + "' != '" + 134 + "'",
                    value.equals(BigInteger.valueOf(134L)));
        } else {
            value = value.longValue();
            expected = 134L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[104];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[104] + "' != '" + 81 + "'",
                    value.equals(BigInteger.valueOf(81L)));
        } else {
            value = value.longValue();
            expected = 81L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[105];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[105] + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[106];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[106] + "' != '" + 116 + "'",
                    value.equals(BigInteger.valueOf(116L)));
        } else {
            value = value.longValue();
            expected = 116L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[107];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[107] + "' != '" + 158 + "'",
                    value.equals(BigInteger.valueOf(158L)));
        } else {
            value = value.longValue();
            expected = 158L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[108];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[108] + "' != '" + 127 + "'",
                    value.equals(BigInteger.valueOf(127L)));
        } else {
            value = value.longValue();
            expected = 127L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[109];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[109] + "' != '" + 40 + "'",
                    value.equals(BigInteger.valueOf(40L)));
        } else {
            value = value.longValue();
            expected = 40L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[110];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[110] + "' != '" + 133 + "'",
                    value.equals(BigInteger.valueOf(133L)));
        } else {
            value = value.longValue();
            expected = 133L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[111];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[111] + "' != '" + 208 + "'",
                    value.equals(BigInteger.valueOf(208L)));
        } else {
            value = value.longValue();
            expected = 208L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[112];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[112] + "' != '" + 134 + "'",
                    value.equals(BigInteger.valueOf(134L)));
        } else {
            value = value.longValue();
            expected = 134L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[113];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[113] + "' != '" + 127 + "'",
                    value.equals(BigInteger.valueOf(127L)));
        } else {
            value = value.longValue();
            expected = 127L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[114];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[114] + "' != '" + 140 + "'",
                    value.equals(BigInteger.valueOf(140L)));
        } else {
            value = value.longValue();
            expected = 140L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[115];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[115] + "' != '" + 232 + "'",
                    value.equals(BigInteger.valueOf(232L)));
        } else {
            value = value.longValue();
            expected = 232L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[116];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[116] + "' != '" + 183 + "'",
                    value.equals(BigInteger.valueOf(183L)));
        } else {
            value = value.longValue();
            expected = 183L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[117];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[117] + "' != '" + 184 + "'",
                    value.equals(BigInteger.valueOf(184L)));
        } else {
            value = value.longValue();
            expected = 184L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[118];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[118] + "' != '" + 108 + "'",
                    value.equals(BigInteger.valueOf(108L)));
        } else {
            value = value.longValue();
            expected = 108L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[119];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[119] + "' != '" + 6 + "'",
                    value.equals(BigInteger.valueOf(6L)));
        } else {
            value = value.longValue();
            expected = 6L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[120];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[120] + "' != '" + 228 + "'",
                    value.equals(BigInteger.valueOf(228L)));
        } else {
            value = value.longValue();
            expected = 228L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[121];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[121] + "' != '" + 54 + "'",
                    value.equals(BigInteger.valueOf(54L)));
        } else {
            value = value.longValue();
            expected = 54L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[122];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[122] + "' != '" + 238 + "'",
                    value.equals(BigInteger.valueOf(238L)));
        } else {
            value = value.longValue();
            expected = 238L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[123];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[123] + "' != '" + 59 + "'",
                    value.equals(BigInteger.valueOf(59L)));
        } else {
            value = value.longValue();
            expected = 59L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[124];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[124] + "' != '" + 220 + "'",
                    value.equals(BigInteger.valueOf(220L)));
        } else {
            value = value.longValue();
            expected = 220L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[125];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[125] + "' != '" + 30 + "'",
                    value.equals(BigInteger.valueOf(30L)));
        } else {
            value = value.longValue();
            expected = 30L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[126];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[126] + "' != '" + 228 + "'",
                    value.equals(BigInteger.valueOf(228L)));
        } else {
            value = value.longValue();
            expected = 228L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[127];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[127] + "' != '" + 212 + "'",
                    value.equals(BigInteger.valueOf(212L)));
        } else {
            value = value.longValue();
            expected = 212L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[128];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[128] + "' != '" + 50 + "'",
                    value.equals(BigInteger.valueOf(50L)));
        } else {
            value = value.longValue();
            expected = 50L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[129];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[129] + "' != '" + 182 + "'",
                    value.equals(BigInteger.valueOf(182L)));
        } else {
            value = value.longValue();
            expected = 182L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[130];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[130] + "' != '" + 97 + "'",
                    value.equals(BigInteger.valueOf(97L)));
        } else {
            value = value.longValue();
            expected = 97L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[131];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[131] + "' != '" + 20 + "'",
                    value.equals(BigInteger.valueOf(20L)));
        } else {
            value = value.longValue();
            expected = 20L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[132];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[132] + "' != '" + 41 + "'",
                    value.equals(BigInteger.valueOf(41L)));
        } else {
            value = value.longValue();
            expected = 41L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[133];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[133] + "' != '" + 76 + "'",
                    value.equals(BigInteger.valueOf(76L)));
        } else {
            value = value.longValue();
            expected = 76L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[134];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[134] + "' != '" + 227 + "'",
                    value.equals(BigInteger.valueOf(227L)));
        } else {
            value = value.longValue();
            expected = 227L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[135];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[135] + "' != '" + 88 + "'",
                    value.equals(BigInteger.valueOf(88L)));
        } else {
            value = value.longValue();
            expected = 88L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[136];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[136] + "' != '" + 12 + "'",
                    value.equals(BigInteger.valueOf(12L)));
        } else {
            value = value.longValue();
            expected = 12L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[137];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[137] + "' != '" + 95 + "'",
                    value.equals(BigInteger.valueOf(95L)));
        } else {
            value = value.longValue();
            expected = 95L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[138];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[138] + "' != '" + 112 + "'",
                    value.equals(BigInteger.valueOf(112L)));
        } else {
            value = value.longValue();
            expected = 112L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[139];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[139] + "' != '" + 209 + "'",
                    value.equals(BigInteger.valueOf(209L)));
        } else {
            value = value.longValue();
            expected = 209L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[140];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[140] + "' != '" + 183 + "'",
                    value.equals(BigInteger.valueOf(183L)));
        } else {
            value = value.longValue();
            expected = 183L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[141];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[141] + "' != '" + 127 + "'",
                    value.equals(BigInteger.valueOf(127L)));
        } else {
            value = value.longValue();
            expected = 127L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[142];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[142] + "' != '" + 4 + "'",
                    value.equals(BigInteger.valueOf(4L)));
        } else {
            value = value.longValue();
            expected = 4L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[143];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[143] + "' != '" + 165 + "'",
                    value.equals(BigInteger.valueOf(165L)));
        } else {
            value = value.longValue();
            expected = 165L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[144];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[144] + "' != '" + 189 + "'",
                    value.equals(BigInteger.valueOf(189L)));
        } else {
            value = value.longValue();
            expected = 189L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[145];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[145] + "' != '" + 44 + "'",
                    value.equals(BigInteger.valueOf(44L)));
        } else {
            value = value.longValue();
            expected = 44L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[146];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[146] + "' != '" + 239 + "'",
                    value.equals(BigInteger.valueOf(239L)));
        } else {
            value = value.longValue();
            expected = 239L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[147];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[147] + "' != '" + 232 + "'",
                    value.equals(BigInteger.valueOf(232L)));
        } else {
            value = value.longValue();
            expected = 232L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[148];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[148] + "' != '" + 132 + "'",
                    value.equals(BigInteger.valueOf(132L)));
        } else {
            value = value.longValue();
            expected = 132L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[149];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[149] + "' != '" + 9 + "'",
                    value.equals(BigInteger.valueOf(9L)));
        } else {
            value = value.longValue();
            expected = 9L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[150];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[150] + "' != '" + 114 + "'",
                    value.equals(BigInteger.valueOf(114L)));
        } else {
            value = value.longValue();
            expected = 114L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[151];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[151] + "' != '" + 184 + "'",
                    value.equals(BigInteger.valueOf(184L)));
        } else {
            value = value.longValue();
            expected = 184L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[152];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[152] + "' != '" + 249 + "'",
                    value.equals(BigInteger.valueOf(249L)));
        } else {
            value = value.longValue();
            expected = 249L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[153];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[153] + "' != '" + 208 + "'",
                    value.equals(BigInteger.valueOf(208L)));
        } else {
            value = value.longValue();
            expected = 208L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[154];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[154] + "' != '" + 246 + "'",
                    value.equals(BigInteger.valueOf(246L)));
        } else {
            value = value.longValue();
            expected = 246L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[155];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[155] + "' != '" + 194 + "'",
                    value.equals(BigInteger.valueOf(194L)));
        } else {
            value = value.longValue();
            expected = 194L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[156];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[156] + "' != '" + 250 + "'",
                    value.equals(BigInteger.valueOf(250L)));
        } else {
            value = value.longValue();
            expected = 250L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[157];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[157] + "' != '" + 2 + "'",
                    value.equals(BigInteger.valueOf(2L)));
        } else {
            value = value.longValue();
            expected = 2L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[158];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[158] + "' != '" + 97 + "'",
                    value.equals(BigInteger.valueOf(97L)));
        } else {
            value = value.longValue();
            expected = 97L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[159];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[159] + "' != '" + 173 + "'",
                    value.equals(BigInteger.valueOf(173L)));
        } else {
            value = value.longValue();
            expected = 173L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[160];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[160] + "' != '" + 157 + "'",
                    value.equals(BigInteger.valueOf(157L)));
        } else {
            value = value.longValue();
            expected = 157L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[161];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[161] + "' != '" + 202 + "'",
                    value.equals(BigInteger.valueOf(202L)));
        } else {
            value = value.longValue();
            expected = 202L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[162];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[162] + "' != '" + 172 + "'",
                    value.equals(BigInteger.valueOf(172L)));
        } else {
            value = value.longValue();
            expected = 172L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[163];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[163] + "' != '" + 180 + "'",
                    value.equals(BigInteger.valueOf(180L)));
        } else {
            value = value.longValue();
            expected = 180L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[164];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[164] + "' != '" + 150 + "'",
                    value.equals(BigInteger.valueOf(150L)));
        } else {
            value = value.longValue();
            expected = 150L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[165];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[165] + "' != '" + 213 + "'",
                    value.equals(BigInteger.valueOf(213L)));
        } else {
            value = value.longValue();
            expected = 213L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[166];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[166] + "' != '" + 193 + "'",
                    value.equals(BigInteger.valueOf(193L)));
        } else {
            value = value.longValue();
            expected = 193L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[167];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[167] + "' != '" + 177 + "'",
                    value.equals(BigInteger.valueOf(177L)));
        } else {
            value = value.longValue();
            expected = 177L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[168];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[168] + "' != '" + 209 + "'",
                    value.equals(BigInteger.valueOf(209L)));
        } else {
            value = value.longValue();
            expected = 209L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[169];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[169] + "' != '" + 156 + "'",
                    value.equals(BigInteger.valueOf(156L)));
        } else {
            value = value.longValue();
            expected = 156L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[170];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[170] + "' != '" + 20 + "'",
                    value.equals(BigInteger.valueOf(20L)));
        } else {
            value = value.longValue();
            expected = 20L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[171];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[171] + "' != '" + 174 + "'",
                    value.equals(BigInteger.valueOf(174L)));
        } else {
            value = value.longValue();
            expected = 174L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[172];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[172] + "' != '" + 18 + "'",
                    value.equals(BigInteger.valueOf(18L)));
        } else {
            value = value.longValue();
            expected = 18L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[173];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[173] + "' != '" + 73 + "'",
                    value.equals(BigInteger.valueOf(73L)));
        } else {
            value = value.longValue();
            expected = 73L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[174];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[174] + "' != '" + 132 + "'",
                    value.equals(BigInteger.valueOf(132L)));
        } else {
            value = value.longValue();
            expected = 132L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[175];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[175] + "' != '" + 215 + "'",
                    value.equals(BigInteger.valueOf(215L)));
        } else {
            value = value.longValue();
            expected = 215L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[176];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[176] + "' != '" + 115 + "'",
                    value.equals(BigInteger.valueOf(115L)));
        } else {
            value = value.longValue();
            expected = 115L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[177];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[177] + "' != '" + 128 + "'",
                    value.equals(BigInteger.valueOf(128L)));
        } else {
            value = value.longValue();
            expected = 128L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[178];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[178] + "' != '" + 175 + "'",
                    value.equals(BigInteger.valueOf(175L)));
        } else {
            value = value.longValue();
            expected = 175L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[179];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[179] + "' != '" + 169 + "'",
                    value.equals(BigInteger.valueOf(169L)));
        } else {
            value = value.longValue();
            expected = 169L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[180];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[180] + "' != '" + 116 + "'",
                    value.equals(BigInteger.valueOf(116L)));
        } else {
            value = value.longValue();
            expected = 116L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[181];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[181] + "' != '" + 132 + "'",
                    value.equals(BigInteger.valueOf(132L)));
        } else {
            value = value.longValue();
            expected = 132L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[182];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[182] + "' != '" + 100 + "'",
                    value.equals(BigInteger.valueOf(100L)));
        } else {
            value = value.longValue();
            expected = 100L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[183];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[183] + "' != '" + 72 + "'",
                    value.equals(BigInteger.valueOf(72L)));
        } else {
            value = value.longValue();
            expected = 72L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[184];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[184] + "' != '" + 45 + "'",
                    value.equals(BigInteger.valueOf(45L)));
        } else {
            value = value.longValue();
            expected = 45L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[185];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[185] + "' != '" + 25 + "'",
                    value.equals(BigInteger.valueOf(25L)));
        } else {
            value = value.longValue();
            expected = 25L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[186];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[186] + "' != '" + 14 + "'",
                    value.equals(BigInteger.valueOf(14L)));
        } else {
            value = value.longValue();
            expected = 14L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[187];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[187] + "' != '" + 205 + "'",
                    value.equals(BigInteger.valueOf(205L)));
        } else {
            value = value.longValue();
            expected = 205L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[188];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[188] + "' != '" + 213 + "'",
                    value.equals(BigInteger.valueOf(213L)));
        } else {
            value = value.longValue();
            expected = 213L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[189];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[189] + "' != '" + 145 + "'",
                    value.equals(BigInteger.valueOf(145L)));
        } else {
            value = value.longValue();
            expected = 145L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[190];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[190] + "' != '" + 68 + "'",
                    value.equals(BigInteger.valueOf(68L)));
        } else {
            value = value.longValue();
            expected = 68L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[191];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[191] + "' != '" + 137 + "'",
                    value.equals(BigInteger.valueOf(137L)));
        } else {
            value = value.longValue();
            expected = 137L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[192];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[192] + "' != '" + 249 + "'",
                    value.equals(BigInteger.valueOf(249L)));
        } else {
            value = value.longValue();
            expected = 249L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[193];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[193] + "' != '" + 54 + "'",
                    value.equals(BigInteger.valueOf(54L)));
        } else {
            value = value.longValue();
            expected = 54L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[194];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[194] + "' != '" + 40 + "'",
                    value.equals(BigInteger.valueOf(40L)));
        } else {
            value = value.longValue();
            expected = 40L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[195];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[195] + "' != '" + 174 + "'",
                    value.equals(BigInteger.valueOf(174L)));
        } else {
            value = value.longValue();
            expected = 174L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[196];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[196] + "' != '" + 215 + "'",
                    value.equals(BigInteger.valueOf(215L)));
        } else {
            value = value.longValue();
            expected = 215L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[197];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[197] + "' != '" + 148 + "'",
                    value.equals(BigInteger.valueOf(148L)));
        } else {
            value = value.longValue();
            expected = 148L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[198];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[198] + "' != '" + 166 + "'",
                    value.equals(BigInteger.valueOf(166L)));
        } else {
            value = value.longValue();
            expected = 166L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[199];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[199] + "' != '" + 190 + "'",
                    value.equals(BigInteger.valueOf(190L)));
        } else {
            value = value.longValue();
            expected = 190L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[200];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[200] + "' != '" + 63 + "'",
                    value.equals(BigInteger.valueOf(63L)));
        } else {
            value = value.longValue();
            expected = 63L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[201];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[201] + "' != '" + 118 + "'",
                    value.equals(BigInteger.valueOf(118L)));
        } else {
            value = value.longValue();
            expected = 118L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[202];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[202] + "' != '" + 6 + "'",
                    value.equals(BigInteger.valueOf(6L)));
        } else {
            value = value.longValue();
            expected = 6L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[203];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[203] + "' != '" + 165 + "'",
                    value.equals(BigInteger.valueOf(165L)));
        } else {
            value = value.longValue();
            expected = 165L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[204];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[204] + "' != '" + 212 + "'",
                    value.equals(BigInteger.valueOf(212L)));
        } else {
            value = value.longValue();
            expected = 212L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[205];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[205] + "' != '" + 74 + "'",
                    value.equals(BigInteger.valueOf(74L)));
        } else {
            value = value.longValue();
            expected = 74L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[206];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[206] + "' != '" + 68 + "'",
                    value.equals(BigInteger.valueOf(68L)));
        } else {
            value = value.longValue();
            expected = 68L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[207];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[207] + "' != '" + 200 + "'",
                    value.equals(BigInteger.valueOf(200L)));
        } else {
            value = value.longValue();
            expected = 200L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[208];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[208] + "' != '" + 38 + "'",
                    value.equals(BigInteger.valueOf(38L)));
        } else {
            value = value.longValue();
            expected = 38L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[209];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[209] + "' != '" + 139 + "'",
                    value.equals(BigInteger.valueOf(139L)));
        } else {
            value = value.longValue();
            expected = 139L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[210];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[210] + "' != '" + 212 + "'",
                    value.equals(BigInteger.valueOf(212L)));
        } else {
            value = value.longValue();
            expected = 212L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[211];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[211] + "' != '" + 112 + "'",
                    value.equals(BigInteger.valueOf(112L)));
        } else {
            value = value.longValue();
            expected = 112L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[212];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[212] + "' != '" + 45 + "'",
                    value.equals(BigInteger.valueOf(45L)));
        } else {
            value = value.longValue();
            expected = 45L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[213];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[213] + "' != '" + 167 + "'",
                    value.equals(BigInteger.valueOf(167L)));
        } else {
            value = value.longValue();
            expected = 167L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[214];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[214] + "' != '" + 236 + "'",
                    value.equals(BigInteger.valueOf(236L)));
        } else {
            value = value.longValue();
            expected = 236L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[215];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[215] + "' != '" + 255 + "'",
                    value.equals(BigInteger.valueOf(255L)));
        } else {
            value = value.longValue();
            expected = 255L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[216];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[216] + "' != '" + 106 + "'",
                    value.equals(BigInteger.valueOf(106L)));
        } else {
            value = value.longValue();
            expected = 106L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[217];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[217] + "' != '" + 92 + "'",
                    value.equals(BigInteger.valueOf(92L)));
        } else {
            value = value.longValue();
            expected = 92L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[218];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[218] + "' != '" + 132 + "'",
                    value.equals(BigInteger.valueOf(132L)));
        } else {
            value = value.longValue();
            expected = 132L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[219];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[219] + "' != '" + 59 + "'",
                    value.equals(BigInteger.valueOf(59L)));
        } else {
            value = value.longValue();
            expected = 59L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[220];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[220] + "' != '" + 61 + "'",
                    value.equals(BigInteger.valueOf(61L)));
        } else {
            value = value.longValue();
            expected = 61L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[221];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[221] + "' != '" + 233 + "'",
                    value.equals(BigInteger.valueOf(233L)));
        } else {
            value = value.longValue();
            expected = 233L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[222];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[222] + "' != '" + 3 + "'",
                    value.equals(BigInteger.valueOf(3L)));
        } else {
            value = value.longValue();
            expected = 3L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[223];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[223] + "' != '" + 246 + "'",
                    value.equals(BigInteger.valueOf(246L)));
        } else {
            value = value.longValue();
            expected = 246L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[224];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[224] + "' != '" + 158 + "'",
                    value.equals(BigInteger.valueOf(158L)));
        } else {
            value = value.longValue();
            expected = 158L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[225];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[225] + "' != '" + 83 + "'",
                    value.equals(BigInteger.valueOf(83L)));
        } else {
            value = value.longValue();
            expected = 83L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[226];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[226] + "' != '" + 134 + "'",
                    value.equals(BigInteger.valueOf(134L)));
        } else {
            value = value.longValue();
            expected = 134L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[227];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[227] + "' != '" + 246 + "'",
                    value.equals(BigInteger.valueOf(246L)));
        } else {
            value = value.longValue();
            expected = 246L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[228];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[228] + "' != '" + 154 + "'",
                    value.equals(BigInteger.valueOf(154L)));
        } else {
            value = value.longValue();
            expected = 154L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[229];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[229] + "' != '" + 17 + "'",
                    value.equals(BigInteger.valueOf(17L)));
        } else {
            value = value.longValue();
            expected = 17L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[230];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[230] + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[231];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[231] + "' != '" + 6 + "'",
                    value.equals(BigInteger.valueOf(6L)));
        } else {
            value = value.longValue();
            expected = 6L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[232];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[232] + "' != '" + 56 + "'",
                    value.equals(BigInteger.valueOf(56L)));
        } else {
            value = value.longValue();
            expected = 56L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[233];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[233] + "' != '" + 216 + "'",
                    value.equals(BigInteger.valueOf(216L)));
        } else {
            value = value.longValue();
            expected = 216L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[234];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[234] + "' != '" + 19 + "'",
                    value.equals(BigInteger.valueOf(19L)));
        } else {
            value = value.longValue();
            expected = 19L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[235];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[235] + "' != '" + 216 + "'",
                    value.equals(BigInteger.valueOf(216L)));
        } else {
            value = value.longValue();
            expected = 216L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[236];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[236] + "' != '" + 70 + "'",
                    value.equals(BigInteger.valueOf(70L)));
        } else {
            value = value.longValue();
            expected = 70L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[237];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[237] + "' != '" + 71 + "'",
                    value.equals(BigInteger.valueOf(71L)));
        } else {
            value = value.longValue();
            expected = 71L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[238];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[238] + "' != '" + 161 + "'",
                    value.equals(BigInteger.valueOf(161L)));
        } else {
            value = value.longValue();
            expected = 161L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[239];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[239] + "' != '" + 184 + "'",
                    value.equals(BigInteger.valueOf(184L)));
        } else {
            value = value.longValue();
            expected = 184L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[240];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[240] + "' != '" + 5 + "'",
                    value.equals(BigInteger.valueOf(5L)));
        } else {
            value = value.longValue();
            expected = 5L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[241];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[241] + "' != '" + 177 + "'",
                    value.equals(BigInteger.valueOf(177L)));
        } else {
            value = value.longValue();
            expected = 177L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[242];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[242] + "' != '" + 45 + "'",
                    value.equals(BigInteger.valueOf(45L)));
        } else {
            value = value.longValue();
            expected = 45L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[243];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[243] + "' != '" + 37 + "'",
                    value.equals(BigInteger.valueOf(37L)));
        } else {
            value = value.longValue();
            expected = 37L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[244];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[244] + "' != '" + 98 + "'",
                    value.equals(BigInteger.valueOf(98L)));
        } else {
            value = value.longValue();
            expected = 98L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[245];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[245] + "' != '" + 56 + "'",
                    value.equals(BigInteger.valueOf(56L)));
        } else {
            value = value.longValue();
            expected = 56L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[246];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[246] + "' != '" + 149 + "'",
                    value.equals(BigInteger.valueOf(149L)));
        } else {
            value = value.longValue();
            expected = 149L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[247];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[247] + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[248];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[248] + "' != '" + 73 + "'",
                    value.equals(BigInteger.valueOf(73L)));
        } else {
            value = value.longValue();
            expected = 73L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[249];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[249] + "' != '" + 221 + "'",
                    value.equals(BigInteger.valueOf(221L)));
        } else {
            value = value.longValue();
            expected = 221L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[250];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[250] + "' != '" + 105 + "'",
                    value.equals(BigInteger.valueOf(105L)));
        } else {
            value = value.longValue();
            expected = 105L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[251];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[251] + "' != '" + 239 + "'",
                    value.equals(BigInteger.valueOf(239L)));
        } else {
            value = value.longValue();
            expected = 239L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[252];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[252] + "' != '" + 168 + "'",
                    value.equals(BigInteger.valueOf(168L)));
        } else {
            value = value.longValue();
            expected = 168L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[253];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[253] + "' != '" + 205 + "'",
                    value.equals(BigInteger.valueOf(205L)));
        } else {
            value = value.longValue();
            expected = 205L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.contents[254];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.contents[254] + "' != '" + 85 + "'",
                    value.equals(BigInteger.valueOf(85L)));
        } else {
            value = value.longValue();
            expected = 85L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
