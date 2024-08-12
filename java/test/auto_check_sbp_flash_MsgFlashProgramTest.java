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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/flash/test_MsgFlashProgram.yaml by
// generate.py. Do not modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.flash.MsgFlashProgram;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_flash_MsgFlashProgramTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_flash_MsgFlashProgramTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 212,
                    (byte) 87,
                    (byte) 52,
                    (byte) 244,
                    (byte) 250,
                    (byte) 176,
                    (byte) 222,
                    (byte) 235,
                    (byte) 106,
                    (byte) 144,
                    (byte) 29,
                    (byte) 141,
                    (byte) 255,
                    (byte) 3,
                    (byte) 16,
                    (byte) 192,
                    (byte) 237,
                    (byte) 172,
                    (byte) 254,
                    (byte) 213,
                    (byte) 4,
                    (byte) 220,
                    (byte) 98,
                    (byte) 34,
                    (byte) 222,
                    (byte) 230,
                    (byte) 214,
                    (byte) 6,
                    (byte) 217,
                    (byte) 172,
                    (byte) 122,
                    (byte) 46,
                    (byte) 13,
                    (byte) 38,
                    (byte) 240,
                    (byte) 236,
                    (byte) 60,
                    (byte) 121,
                    (byte) 47,
                    (byte) 252,
                    (byte) 163,
                    (byte) 141,
                    (byte) 222,
                    (byte) 29,
                    (byte) 168,
                    (byte) 214,
                    (byte) 118,
                    (byte) 55,
                    (byte) 201,
                    (byte) 233,
                    (byte) 21,
                    (byte) 214,
                    (byte) 57,
                    (byte) 245,
                    (byte) 246,
                    (byte) 19,
                    (byte) 3,
                    (byte) 121,
                    (byte) 49,
                    (byte) 231,
                    (byte) 37,
                    (byte) 186,
                    (byte) 58,
                    (byte) 238,
                    (byte) 98,
                    (byte) 39,
                    (byte) 70,
                    (byte) 232,
                    (byte) 133,
                    (byte) 25,
                    (byte) 10,
                    (byte) 134,
                    (byte) 129,
                    (byte) 69,
                    (byte) 228,
                    (byte) 134,
                    (byte) 9,
                    (byte) 88,
                    (byte) 183,
                    (byte) 133,
                    (byte) 171,
                    (byte) 255,
                    (byte) 166,
                    (byte) 100,
                    (byte) 152,
                    (byte) 231,
                    (byte) 92,
                    (byte) 9,
                    (byte) 196,
                    (byte) 106,
                    (byte) 246,
                    (byte) 29,
                    (byte) 145,
                    (byte) 156,
                    (byte) 151,
                    (byte) 32,
                    (byte) 67,
                    (byte) 188,
                    (byte) 63,
                    (byte) 233,
                    (byte) 142,
                    (byte) 174,
                    (byte) 139,
                    (byte) 154,
                    (byte) 127,
                    (byte) 35,
                    (byte) 60,
                    (byte) 56,
                    (byte) 187,
                    (byte) 121,
                    (byte) 103,
                    (byte) 135,
                    (byte) 152,
                    (byte) 182,
                    (byte) 88,
                    (byte) 160,
                    (byte) 255,
                    (byte) 227,
                    (byte) 240,
                    (byte) 54,
                    (byte) 100,
                    (byte) 91,
                    (byte) 31,
                    (byte) 141,
                    (byte) 102,
                    (byte) 130,
                    (byte) 254,
                    (byte) 54,
                    (byte) 227,
                    (byte) 229,
                    (byte) 62,
                    (byte) 53,
                    (byte) 225,
                    (byte) 143,
                    (byte) 88,
                    (byte) 139,
                    (byte) 126,
                    (byte) 235,
                    (byte) 235,
                    (byte) 35,
                    (byte) 54,
                    (byte) 134,
                    (byte) 163,
                    (byte) 92,
                    (byte) 57,
                    (byte) 87,
                    (byte) 130,
                    (byte) 178,
                    (byte) 22,
                    (byte) 158,
                    (byte) 18,
                    (byte) 237,
                    (byte) 209,
                    (byte) 187,
                    (byte) 226,
                    (byte) 1,
                    (byte) 46,
                    (byte) 64,
                    (byte) 226,
                    (byte) 235,
                    (byte) 213,
                    (byte) 186,
                    (byte) 159,
                    (byte) 221,
                    (byte) 186,
                    (byte) 25,
                    (byte) 115,
                    (byte) 84,
                    (byte) 131,
                    (byte) 167,
                    (byte) 201,
                    (byte) 104,
                    (byte) 1,
                    (byte) 200,
                    (byte) 13,
                    (byte) 50,
                    (byte) 71,
                    (byte) 73,
                    (byte) 193,
                    (byte) 201,
                    (byte) 250,
                    (byte) 172,
                    (byte) 193,
                    (byte) 13,
                    (byte) 20,
                    (byte) 238,
                    (byte) 130,
                    (byte) 243,
                    (byte) 68,
                    (byte) 4,
                    (byte) 72,
                    (byte) 46,
                    (byte) 194,
                    (byte) 113,
                    (byte) 255,
                    (byte) 238,
                    (byte) 15,
                    (byte) 230,
                    (byte) 64,
                    (byte) 178,
                    (byte) 127,
                    (byte) 217,
                    (byte) 92,
                    (byte) 160,
                    (byte) 201,
                    (byte) 118,
                    (byte) 163,
                    (byte) 144,
                    (byte) 58,
                    (byte) 28,
                    (byte) 174,
                    (byte) 65,
                    (byte) 73,
                    (byte) 45,
                    (byte) 123,
                    (byte) 118,
                    (byte) 83,
                    (byte) 107,
                    (byte) 239,
                    (byte) 168,
                    (byte) 32,
                    (byte) 212,
                    (byte) 191,
                    (byte) 81,
                    (byte) 93,
                    (byte) 186,
                    (byte) 223,
                    (byte) 32,
                    (byte) 19,
                    (byte) 58,
                    (byte) 137,
                    (byte) 72,
                    (byte) 217,
                    (byte) 151,
                    (byte) 251,
                    (byte) 83,
                    (byte) 20,
                    (byte) 113,
                    (byte) 37,
                    (byte) 151,
                    (byte) 34,
                    (byte) 37,
                    (byte) 71,
                    (byte) 95,
                    (byte) 105,
                    (byte) 235,
                    (byte) 144,
                    (byte) 164,
                    (byte) 83,
                    (byte) 197,
                    (byte) 254,
                    (byte) 183,
                    (byte) 223,
                    (byte) 91,
                    (byte) 19,
                };
        SBPMessage sbp = new SBPMessage(0x04c3, 0xe6, payload);
        MsgFlashProgram msg = new MsgFlashProgram(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.addr_len;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.addr_len + "' != '" + 250 + "'",
                    value.equals(BigInteger.valueOf(250L)));
        } else {
            value = value.longValue();
            expected = 250L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.addr_start[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.addr_start[0] + "' != '" + 87 + "'",
                    value.equals(BigInteger.valueOf(87L)));
        } else {
            value = value.longValue();
            expected = 87L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.addr_start[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.addr_start[1] + "' != '" + 52 + "'",
                    value.equals(BigInteger.valueOf(52L)));
        } else {
            value = value.longValue();
            expected = 52L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.addr_start[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.addr_start[2] + "' != '" + 244 + "'",
                    value.equals(BigInteger.valueOf(244L)));
        } else {
            value = value.longValue();
            expected = 244L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[0] + "' != '" + 176 + "'",
                    value.equals(BigInteger.valueOf(176L)));
        } else {
            value = value.longValue();
            expected = 176L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[1] + "' != '" + 222 + "'",
                    value.equals(BigInteger.valueOf(222L)));
        } else {
            value = value.longValue();
            expected = 222L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[2] + "' != '" + 235 + "'",
                    value.equals(BigInteger.valueOf(235L)));
        } else {
            value = value.longValue();
            expected = 235L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[3] + "' != '" + 106 + "'",
                    value.equals(BigInteger.valueOf(106L)));
        } else {
            value = value.longValue();
            expected = 106L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[4];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[4] + "' != '" + 144 + "'",
                    value.equals(BigInteger.valueOf(144L)));
        } else {
            value = value.longValue();
            expected = 144L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[5];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[5] + "' != '" + 29 + "'", value.equals(BigInteger.valueOf(29L)));
        } else {
            value = value.longValue();
            expected = 29L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[6];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[6] + "' != '" + 141 + "'",
                    value.equals(BigInteger.valueOf(141L)));
        } else {
            value = value.longValue();
            expected = 141L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[7];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[7] + "' != '" + 255 + "'",
                    value.equals(BigInteger.valueOf(255L)));
        } else {
            value = value.longValue();
            expected = 255L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[8];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[8] + "' != '" + 3 + "'", value.equals(BigInteger.valueOf(3L)));
        } else {
            value = value.longValue();
            expected = 3L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[9];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[9] + "' != '" + 16 + "'", value.equals(BigInteger.valueOf(16L)));
        } else {
            value = value.longValue();
            expected = 16L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[10];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[10] + "' != '" + 192 + "'",
                    value.equals(BigInteger.valueOf(192L)));
        } else {
            value = value.longValue();
            expected = 192L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[11];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[11] + "' != '" + 237 + "'",
                    value.equals(BigInteger.valueOf(237L)));
        } else {
            value = value.longValue();
            expected = 237L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[12];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[12] + "' != '" + 172 + "'",
                    value.equals(BigInteger.valueOf(172L)));
        } else {
            value = value.longValue();
            expected = 172L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[13];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[13] + "' != '" + 254 + "'",
                    value.equals(BigInteger.valueOf(254L)));
        } else {
            value = value.longValue();
            expected = 254L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[14];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[14] + "' != '" + 213 + "'",
                    value.equals(BigInteger.valueOf(213L)));
        } else {
            value = value.longValue();
            expected = 213L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[15];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[15] + "' != '" + 4 + "'", value.equals(BigInteger.valueOf(4L)));
        } else {
            value = value.longValue();
            expected = 4L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[16];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[16] + "' != '" + 220 + "'",
                    value.equals(BigInteger.valueOf(220L)));
        } else {
            value = value.longValue();
            expected = 220L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[17];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[17] + "' != '" + 98 + "'",
                    value.equals(BigInteger.valueOf(98L)));
        } else {
            value = value.longValue();
            expected = 98L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[18];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[18] + "' != '" + 34 + "'",
                    value.equals(BigInteger.valueOf(34L)));
        } else {
            value = value.longValue();
            expected = 34L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[19];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[19] + "' != '" + 222 + "'",
                    value.equals(BigInteger.valueOf(222L)));
        } else {
            value = value.longValue();
            expected = 222L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[20];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[20] + "' != '" + 230 + "'",
                    value.equals(BigInteger.valueOf(230L)));
        } else {
            value = value.longValue();
            expected = 230L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[21];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[21] + "' != '" + 214 + "'",
                    value.equals(BigInteger.valueOf(214L)));
        } else {
            value = value.longValue();
            expected = 214L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[22];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[22] + "' != '" + 6 + "'", value.equals(BigInteger.valueOf(6L)));
        } else {
            value = value.longValue();
            expected = 6L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[23];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[23] + "' != '" + 217 + "'",
                    value.equals(BigInteger.valueOf(217L)));
        } else {
            value = value.longValue();
            expected = 217L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[24];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[24] + "' != '" + 172 + "'",
                    value.equals(BigInteger.valueOf(172L)));
        } else {
            value = value.longValue();
            expected = 172L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[25];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[25] + "' != '" + 122 + "'",
                    value.equals(BigInteger.valueOf(122L)));
        } else {
            value = value.longValue();
            expected = 122L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[26];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[26] + "' != '" + 46 + "'",
                    value.equals(BigInteger.valueOf(46L)));
        } else {
            value = value.longValue();
            expected = 46L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[27];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[27] + "' != '" + 13 + "'",
                    value.equals(BigInteger.valueOf(13L)));
        } else {
            value = value.longValue();
            expected = 13L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[28];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[28] + "' != '" + 38 + "'",
                    value.equals(BigInteger.valueOf(38L)));
        } else {
            value = value.longValue();
            expected = 38L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[29];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[29] + "' != '" + 240 + "'",
                    value.equals(BigInteger.valueOf(240L)));
        } else {
            value = value.longValue();
            expected = 240L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[30];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[30] + "' != '" + 236 + "'",
                    value.equals(BigInteger.valueOf(236L)));
        } else {
            value = value.longValue();
            expected = 236L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[31];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[31] + "' != '" + 60 + "'",
                    value.equals(BigInteger.valueOf(60L)));
        } else {
            value = value.longValue();
            expected = 60L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[32];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[32] + "' != '" + 121 + "'",
                    value.equals(BigInteger.valueOf(121L)));
        } else {
            value = value.longValue();
            expected = 121L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[33];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[33] + "' != '" + 47 + "'",
                    value.equals(BigInteger.valueOf(47L)));
        } else {
            value = value.longValue();
            expected = 47L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[34];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[34] + "' != '" + 252 + "'",
                    value.equals(BigInteger.valueOf(252L)));
        } else {
            value = value.longValue();
            expected = 252L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[35];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[35] + "' != '" + 163 + "'",
                    value.equals(BigInteger.valueOf(163L)));
        } else {
            value = value.longValue();
            expected = 163L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[36];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[36] + "' != '" + 141 + "'",
                    value.equals(BigInteger.valueOf(141L)));
        } else {
            value = value.longValue();
            expected = 141L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[37];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[37] + "' != '" + 222 + "'",
                    value.equals(BigInteger.valueOf(222L)));
        } else {
            value = value.longValue();
            expected = 222L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[38];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[38] + "' != '" + 29 + "'",
                    value.equals(BigInteger.valueOf(29L)));
        } else {
            value = value.longValue();
            expected = 29L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[39];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[39] + "' != '" + 168 + "'",
                    value.equals(BigInteger.valueOf(168L)));
        } else {
            value = value.longValue();
            expected = 168L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[40];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[40] + "' != '" + 214 + "'",
                    value.equals(BigInteger.valueOf(214L)));
        } else {
            value = value.longValue();
            expected = 214L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[41];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[41] + "' != '" + 118 + "'",
                    value.equals(BigInteger.valueOf(118L)));
        } else {
            value = value.longValue();
            expected = 118L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[42];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[42] + "' != '" + 55 + "'",
                    value.equals(BigInteger.valueOf(55L)));
        } else {
            value = value.longValue();
            expected = 55L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[43];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[43] + "' != '" + 201 + "'",
                    value.equals(BigInteger.valueOf(201L)));
        } else {
            value = value.longValue();
            expected = 201L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[44];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[44] + "' != '" + 233 + "'",
                    value.equals(BigInteger.valueOf(233L)));
        } else {
            value = value.longValue();
            expected = 233L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[45];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[45] + "' != '" + 21 + "'",
                    value.equals(BigInteger.valueOf(21L)));
        } else {
            value = value.longValue();
            expected = 21L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[46];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[46] + "' != '" + 214 + "'",
                    value.equals(BigInteger.valueOf(214L)));
        } else {
            value = value.longValue();
            expected = 214L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[47];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[47] + "' != '" + 57 + "'",
                    value.equals(BigInteger.valueOf(57L)));
        } else {
            value = value.longValue();
            expected = 57L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[48];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[48] + "' != '" + 245 + "'",
                    value.equals(BigInteger.valueOf(245L)));
        } else {
            value = value.longValue();
            expected = 245L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[49];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[49] + "' != '" + 246 + "'",
                    value.equals(BigInteger.valueOf(246L)));
        } else {
            value = value.longValue();
            expected = 246L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[50];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[50] + "' != '" + 19 + "'",
                    value.equals(BigInteger.valueOf(19L)));
        } else {
            value = value.longValue();
            expected = 19L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[51];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[51] + "' != '" + 3 + "'", value.equals(BigInteger.valueOf(3L)));
        } else {
            value = value.longValue();
            expected = 3L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[52];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[52] + "' != '" + 121 + "'",
                    value.equals(BigInteger.valueOf(121L)));
        } else {
            value = value.longValue();
            expected = 121L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[53];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[53] + "' != '" + 49 + "'",
                    value.equals(BigInteger.valueOf(49L)));
        } else {
            value = value.longValue();
            expected = 49L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[54];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[54] + "' != '" + 231 + "'",
                    value.equals(BigInteger.valueOf(231L)));
        } else {
            value = value.longValue();
            expected = 231L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[55];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[55] + "' != '" + 37 + "'",
                    value.equals(BigInteger.valueOf(37L)));
        } else {
            value = value.longValue();
            expected = 37L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[56];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[56] + "' != '" + 186 + "'",
                    value.equals(BigInteger.valueOf(186L)));
        } else {
            value = value.longValue();
            expected = 186L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[57];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[57] + "' != '" + 58 + "'",
                    value.equals(BigInteger.valueOf(58L)));
        } else {
            value = value.longValue();
            expected = 58L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[58];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[58] + "' != '" + 238 + "'",
                    value.equals(BigInteger.valueOf(238L)));
        } else {
            value = value.longValue();
            expected = 238L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[59];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[59] + "' != '" + 98 + "'",
                    value.equals(BigInteger.valueOf(98L)));
        } else {
            value = value.longValue();
            expected = 98L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[60];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[60] + "' != '" + 39 + "'",
                    value.equals(BigInteger.valueOf(39L)));
        } else {
            value = value.longValue();
            expected = 39L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[61];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[61] + "' != '" + 70 + "'",
                    value.equals(BigInteger.valueOf(70L)));
        } else {
            value = value.longValue();
            expected = 70L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[62];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[62] + "' != '" + 232 + "'",
                    value.equals(BigInteger.valueOf(232L)));
        } else {
            value = value.longValue();
            expected = 232L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[63];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[63] + "' != '" + 133 + "'",
                    value.equals(BigInteger.valueOf(133L)));
        } else {
            value = value.longValue();
            expected = 133L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[64];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[64] + "' != '" + 25 + "'",
                    value.equals(BigInteger.valueOf(25L)));
        } else {
            value = value.longValue();
            expected = 25L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[65];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[65] + "' != '" + 10 + "'",
                    value.equals(BigInteger.valueOf(10L)));
        } else {
            value = value.longValue();
            expected = 10L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[66];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[66] + "' != '" + 134 + "'",
                    value.equals(BigInteger.valueOf(134L)));
        } else {
            value = value.longValue();
            expected = 134L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[67];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[67] + "' != '" + 129 + "'",
                    value.equals(BigInteger.valueOf(129L)));
        } else {
            value = value.longValue();
            expected = 129L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[68];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[68] + "' != '" + 69 + "'",
                    value.equals(BigInteger.valueOf(69L)));
        } else {
            value = value.longValue();
            expected = 69L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[69];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[69] + "' != '" + 228 + "'",
                    value.equals(BigInteger.valueOf(228L)));
        } else {
            value = value.longValue();
            expected = 228L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[70];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[70] + "' != '" + 134 + "'",
                    value.equals(BigInteger.valueOf(134L)));
        } else {
            value = value.longValue();
            expected = 134L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[71];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[71] + "' != '" + 9 + "'", value.equals(BigInteger.valueOf(9L)));
        } else {
            value = value.longValue();
            expected = 9L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[72];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[72] + "' != '" + 88 + "'",
                    value.equals(BigInteger.valueOf(88L)));
        } else {
            value = value.longValue();
            expected = 88L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[73];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[73] + "' != '" + 183 + "'",
                    value.equals(BigInteger.valueOf(183L)));
        } else {
            value = value.longValue();
            expected = 183L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[74];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[74] + "' != '" + 133 + "'",
                    value.equals(BigInteger.valueOf(133L)));
        } else {
            value = value.longValue();
            expected = 133L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[75];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[75] + "' != '" + 171 + "'",
                    value.equals(BigInteger.valueOf(171L)));
        } else {
            value = value.longValue();
            expected = 171L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[76];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[76] + "' != '" + 255 + "'",
                    value.equals(BigInteger.valueOf(255L)));
        } else {
            value = value.longValue();
            expected = 255L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[77];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[77] + "' != '" + 166 + "'",
                    value.equals(BigInteger.valueOf(166L)));
        } else {
            value = value.longValue();
            expected = 166L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[78];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[78] + "' != '" + 100 + "'",
                    value.equals(BigInteger.valueOf(100L)));
        } else {
            value = value.longValue();
            expected = 100L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[79];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[79] + "' != '" + 152 + "'",
                    value.equals(BigInteger.valueOf(152L)));
        } else {
            value = value.longValue();
            expected = 152L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[80];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[80] + "' != '" + 231 + "'",
                    value.equals(BigInteger.valueOf(231L)));
        } else {
            value = value.longValue();
            expected = 231L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[81];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[81] + "' != '" + 92 + "'",
                    value.equals(BigInteger.valueOf(92L)));
        } else {
            value = value.longValue();
            expected = 92L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[82];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[82] + "' != '" + 9 + "'", value.equals(BigInteger.valueOf(9L)));
        } else {
            value = value.longValue();
            expected = 9L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[83];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[83] + "' != '" + 196 + "'",
                    value.equals(BigInteger.valueOf(196L)));
        } else {
            value = value.longValue();
            expected = 196L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[84];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[84] + "' != '" + 106 + "'",
                    value.equals(BigInteger.valueOf(106L)));
        } else {
            value = value.longValue();
            expected = 106L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[85];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[85] + "' != '" + 246 + "'",
                    value.equals(BigInteger.valueOf(246L)));
        } else {
            value = value.longValue();
            expected = 246L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[86];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[86] + "' != '" + 29 + "'",
                    value.equals(BigInteger.valueOf(29L)));
        } else {
            value = value.longValue();
            expected = 29L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[87];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[87] + "' != '" + 145 + "'",
                    value.equals(BigInteger.valueOf(145L)));
        } else {
            value = value.longValue();
            expected = 145L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[88];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[88] + "' != '" + 156 + "'",
                    value.equals(BigInteger.valueOf(156L)));
        } else {
            value = value.longValue();
            expected = 156L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[89];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[89] + "' != '" + 151 + "'",
                    value.equals(BigInteger.valueOf(151L)));
        } else {
            value = value.longValue();
            expected = 151L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[90];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[90] + "' != '" + 32 + "'",
                    value.equals(BigInteger.valueOf(32L)));
        } else {
            value = value.longValue();
            expected = 32L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[91];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[91] + "' != '" + 67 + "'",
                    value.equals(BigInteger.valueOf(67L)));
        } else {
            value = value.longValue();
            expected = 67L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[92];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[92] + "' != '" + 188 + "'",
                    value.equals(BigInteger.valueOf(188L)));
        } else {
            value = value.longValue();
            expected = 188L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[93];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[93] + "' != '" + 63 + "'",
                    value.equals(BigInteger.valueOf(63L)));
        } else {
            value = value.longValue();
            expected = 63L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[94];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[94] + "' != '" + 233 + "'",
                    value.equals(BigInteger.valueOf(233L)));
        } else {
            value = value.longValue();
            expected = 233L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[95];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[95] + "' != '" + 142 + "'",
                    value.equals(BigInteger.valueOf(142L)));
        } else {
            value = value.longValue();
            expected = 142L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[96];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[96] + "' != '" + 174 + "'",
                    value.equals(BigInteger.valueOf(174L)));
        } else {
            value = value.longValue();
            expected = 174L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[97];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[97] + "' != '" + 139 + "'",
                    value.equals(BigInteger.valueOf(139L)));
        } else {
            value = value.longValue();
            expected = 139L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[98];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[98] + "' != '" + 154 + "'",
                    value.equals(BigInteger.valueOf(154L)));
        } else {
            value = value.longValue();
            expected = 154L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[99];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[99] + "' != '" + 127 + "'",
                    value.equals(BigInteger.valueOf(127L)));
        } else {
            value = value.longValue();
            expected = 127L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[100];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[100] + "' != '" + 35 + "'",
                    value.equals(BigInteger.valueOf(35L)));
        } else {
            value = value.longValue();
            expected = 35L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[101];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[101] + "' != '" + 60 + "'",
                    value.equals(BigInteger.valueOf(60L)));
        } else {
            value = value.longValue();
            expected = 60L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[102];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[102] + "' != '" + 56 + "'",
                    value.equals(BigInteger.valueOf(56L)));
        } else {
            value = value.longValue();
            expected = 56L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[103];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[103] + "' != '" + 187 + "'",
                    value.equals(BigInteger.valueOf(187L)));
        } else {
            value = value.longValue();
            expected = 187L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[104];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[104] + "' != '" + 121 + "'",
                    value.equals(BigInteger.valueOf(121L)));
        } else {
            value = value.longValue();
            expected = 121L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[105];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[105] + "' != '" + 103 + "'",
                    value.equals(BigInteger.valueOf(103L)));
        } else {
            value = value.longValue();
            expected = 103L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[106];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[106] + "' != '" + 135 + "'",
                    value.equals(BigInteger.valueOf(135L)));
        } else {
            value = value.longValue();
            expected = 135L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[107];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[107] + "' != '" + 152 + "'",
                    value.equals(BigInteger.valueOf(152L)));
        } else {
            value = value.longValue();
            expected = 152L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[108];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[108] + "' != '" + 182 + "'",
                    value.equals(BigInteger.valueOf(182L)));
        } else {
            value = value.longValue();
            expected = 182L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[109];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[109] + "' != '" + 88 + "'",
                    value.equals(BigInteger.valueOf(88L)));
        } else {
            value = value.longValue();
            expected = 88L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[110];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[110] + "' != '" + 160 + "'",
                    value.equals(BigInteger.valueOf(160L)));
        } else {
            value = value.longValue();
            expected = 160L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[111];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[111] + "' != '" + 255 + "'",
                    value.equals(BigInteger.valueOf(255L)));
        } else {
            value = value.longValue();
            expected = 255L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[112];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[112] + "' != '" + 227 + "'",
                    value.equals(BigInteger.valueOf(227L)));
        } else {
            value = value.longValue();
            expected = 227L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[113];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[113] + "' != '" + 240 + "'",
                    value.equals(BigInteger.valueOf(240L)));
        } else {
            value = value.longValue();
            expected = 240L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[114];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[114] + "' != '" + 54 + "'",
                    value.equals(BigInteger.valueOf(54L)));
        } else {
            value = value.longValue();
            expected = 54L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[115];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[115] + "' != '" + 100 + "'",
                    value.equals(BigInteger.valueOf(100L)));
        } else {
            value = value.longValue();
            expected = 100L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[116];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[116] + "' != '" + 91 + "'",
                    value.equals(BigInteger.valueOf(91L)));
        } else {
            value = value.longValue();
            expected = 91L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[117];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[117] + "' != '" + 31 + "'",
                    value.equals(BigInteger.valueOf(31L)));
        } else {
            value = value.longValue();
            expected = 31L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[118];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[118] + "' != '" + 141 + "'",
                    value.equals(BigInteger.valueOf(141L)));
        } else {
            value = value.longValue();
            expected = 141L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[119];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[119] + "' != '" + 102 + "'",
                    value.equals(BigInteger.valueOf(102L)));
        } else {
            value = value.longValue();
            expected = 102L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[120];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[120] + "' != '" + 130 + "'",
                    value.equals(BigInteger.valueOf(130L)));
        } else {
            value = value.longValue();
            expected = 130L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[121];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[121] + "' != '" + 254 + "'",
                    value.equals(BigInteger.valueOf(254L)));
        } else {
            value = value.longValue();
            expected = 254L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[122];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[122] + "' != '" + 54 + "'",
                    value.equals(BigInteger.valueOf(54L)));
        } else {
            value = value.longValue();
            expected = 54L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[123];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[123] + "' != '" + 227 + "'",
                    value.equals(BigInteger.valueOf(227L)));
        } else {
            value = value.longValue();
            expected = 227L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[124];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[124] + "' != '" + 229 + "'",
                    value.equals(BigInteger.valueOf(229L)));
        } else {
            value = value.longValue();
            expected = 229L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[125];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[125] + "' != '" + 62 + "'",
                    value.equals(BigInteger.valueOf(62L)));
        } else {
            value = value.longValue();
            expected = 62L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[126];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[126] + "' != '" + 53 + "'",
                    value.equals(BigInteger.valueOf(53L)));
        } else {
            value = value.longValue();
            expected = 53L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[127];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[127] + "' != '" + 225 + "'",
                    value.equals(BigInteger.valueOf(225L)));
        } else {
            value = value.longValue();
            expected = 225L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[128];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[128] + "' != '" + 143 + "'",
                    value.equals(BigInteger.valueOf(143L)));
        } else {
            value = value.longValue();
            expected = 143L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[129];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[129] + "' != '" + 88 + "'",
                    value.equals(BigInteger.valueOf(88L)));
        } else {
            value = value.longValue();
            expected = 88L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[130];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[130] + "' != '" + 139 + "'",
                    value.equals(BigInteger.valueOf(139L)));
        } else {
            value = value.longValue();
            expected = 139L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[131];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[131] + "' != '" + 126 + "'",
                    value.equals(BigInteger.valueOf(126L)));
        } else {
            value = value.longValue();
            expected = 126L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[132];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[132] + "' != '" + 235 + "'",
                    value.equals(BigInteger.valueOf(235L)));
        } else {
            value = value.longValue();
            expected = 235L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[133];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[133] + "' != '" + 235 + "'",
                    value.equals(BigInteger.valueOf(235L)));
        } else {
            value = value.longValue();
            expected = 235L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[134];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[134] + "' != '" + 35 + "'",
                    value.equals(BigInteger.valueOf(35L)));
        } else {
            value = value.longValue();
            expected = 35L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[135];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[135] + "' != '" + 54 + "'",
                    value.equals(BigInteger.valueOf(54L)));
        } else {
            value = value.longValue();
            expected = 54L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[136];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[136] + "' != '" + 134 + "'",
                    value.equals(BigInteger.valueOf(134L)));
        } else {
            value = value.longValue();
            expected = 134L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[137];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[137] + "' != '" + 163 + "'",
                    value.equals(BigInteger.valueOf(163L)));
        } else {
            value = value.longValue();
            expected = 163L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[138];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[138] + "' != '" + 92 + "'",
                    value.equals(BigInteger.valueOf(92L)));
        } else {
            value = value.longValue();
            expected = 92L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[139];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[139] + "' != '" + 57 + "'",
                    value.equals(BigInteger.valueOf(57L)));
        } else {
            value = value.longValue();
            expected = 57L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[140];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[140] + "' != '" + 87 + "'",
                    value.equals(BigInteger.valueOf(87L)));
        } else {
            value = value.longValue();
            expected = 87L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[141];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[141] + "' != '" + 130 + "'",
                    value.equals(BigInteger.valueOf(130L)));
        } else {
            value = value.longValue();
            expected = 130L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[142];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[142] + "' != '" + 178 + "'",
                    value.equals(BigInteger.valueOf(178L)));
        } else {
            value = value.longValue();
            expected = 178L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[143];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[143] + "' != '" + 22 + "'",
                    value.equals(BigInteger.valueOf(22L)));
        } else {
            value = value.longValue();
            expected = 22L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[144];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[144] + "' != '" + 158 + "'",
                    value.equals(BigInteger.valueOf(158L)));
        } else {
            value = value.longValue();
            expected = 158L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[145];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[145] + "' != '" + 18 + "'",
                    value.equals(BigInteger.valueOf(18L)));
        } else {
            value = value.longValue();
            expected = 18L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[146];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[146] + "' != '" + 237 + "'",
                    value.equals(BigInteger.valueOf(237L)));
        } else {
            value = value.longValue();
            expected = 237L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[147];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[147] + "' != '" + 209 + "'",
                    value.equals(BigInteger.valueOf(209L)));
        } else {
            value = value.longValue();
            expected = 209L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[148];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[148] + "' != '" + 187 + "'",
                    value.equals(BigInteger.valueOf(187L)));
        } else {
            value = value.longValue();
            expected = 187L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[149];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[149] + "' != '" + 226 + "'",
                    value.equals(BigInteger.valueOf(226L)));
        } else {
            value = value.longValue();
            expected = 226L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[150];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[150] + "' != '" + 1 + "'", value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[151];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[151] + "' != '" + 46 + "'",
                    value.equals(BigInteger.valueOf(46L)));
        } else {
            value = value.longValue();
            expected = 46L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[152];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[152] + "' != '" + 64 + "'",
                    value.equals(BigInteger.valueOf(64L)));
        } else {
            value = value.longValue();
            expected = 64L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[153];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[153] + "' != '" + 226 + "'",
                    value.equals(BigInteger.valueOf(226L)));
        } else {
            value = value.longValue();
            expected = 226L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[154];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[154] + "' != '" + 235 + "'",
                    value.equals(BigInteger.valueOf(235L)));
        } else {
            value = value.longValue();
            expected = 235L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[155];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[155] + "' != '" + 213 + "'",
                    value.equals(BigInteger.valueOf(213L)));
        } else {
            value = value.longValue();
            expected = 213L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[156];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[156] + "' != '" + 186 + "'",
                    value.equals(BigInteger.valueOf(186L)));
        } else {
            value = value.longValue();
            expected = 186L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[157];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[157] + "' != '" + 159 + "'",
                    value.equals(BigInteger.valueOf(159L)));
        } else {
            value = value.longValue();
            expected = 159L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[158];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[158] + "' != '" + 221 + "'",
                    value.equals(BigInteger.valueOf(221L)));
        } else {
            value = value.longValue();
            expected = 221L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[159];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[159] + "' != '" + 186 + "'",
                    value.equals(BigInteger.valueOf(186L)));
        } else {
            value = value.longValue();
            expected = 186L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[160];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[160] + "' != '" + 25 + "'",
                    value.equals(BigInteger.valueOf(25L)));
        } else {
            value = value.longValue();
            expected = 25L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[161];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[161] + "' != '" + 115 + "'",
                    value.equals(BigInteger.valueOf(115L)));
        } else {
            value = value.longValue();
            expected = 115L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[162];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[162] + "' != '" + 84 + "'",
                    value.equals(BigInteger.valueOf(84L)));
        } else {
            value = value.longValue();
            expected = 84L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[163];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[163] + "' != '" + 131 + "'",
                    value.equals(BigInteger.valueOf(131L)));
        } else {
            value = value.longValue();
            expected = 131L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[164];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[164] + "' != '" + 167 + "'",
                    value.equals(BigInteger.valueOf(167L)));
        } else {
            value = value.longValue();
            expected = 167L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[165];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[165] + "' != '" + 201 + "'",
                    value.equals(BigInteger.valueOf(201L)));
        } else {
            value = value.longValue();
            expected = 201L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[166];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[166] + "' != '" + 104 + "'",
                    value.equals(BigInteger.valueOf(104L)));
        } else {
            value = value.longValue();
            expected = 104L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[167];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[167] + "' != '" + 1 + "'", value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[168];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[168] + "' != '" + 200 + "'",
                    value.equals(BigInteger.valueOf(200L)));
        } else {
            value = value.longValue();
            expected = 200L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[169];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[169] + "' != '" + 13 + "'",
                    value.equals(BigInteger.valueOf(13L)));
        } else {
            value = value.longValue();
            expected = 13L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[170];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[170] + "' != '" + 50 + "'",
                    value.equals(BigInteger.valueOf(50L)));
        } else {
            value = value.longValue();
            expected = 50L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[171];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[171] + "' != '" + 71 + "'",
                    value.equals(BigInteger.valueOf(71L)));
        } else {
            value = value.longValue();
            expected = 71L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[172];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[172] + "' != '" + 73 + "'",
                    value.equals(BigInteger.valueOf(73L)));
        } else {
            value = value.longValue();
            expected = 73L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[173];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[173] + "' != '" + 193 + "'",
                    value.equals(BigInteger.valueOf(193L)));
        } else {
            value = value.longValue();
            expected = 193L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[174];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[174] + "' != '" + 201 + "'",
                    value.equals(BigInteger.valueOf(201L)));
        } else {
            value = value.longValue();
            expected = 201L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[175];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[175] + "' != '" + 250 + "'",
                    value.equals(BigInteger.valueOf(250L)));
        } else {
            value = value.longValue();
            expected = 250L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[176];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[176] + "' != '" + 172 + "'",
                    value.equals(BigInteger.valueOf(172L)));
        } else {
            value = value.longValue();
            expected = 172L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[177];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[177] + "' != '" + 193 + "'",
                    value.equals(BigInteger.valueOf(193L)));
        } else {
            value = value.longValue();
            expected = 193L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[178];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[178] + "' != '" + 13 + "'",
                    value.equals(BigInteger.valueOf(13L)));
        } else {
            value = value.longValue();
            expected = 13L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[179];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[179] + "' != '" + 20 + "'",
                    value.equals(BigInteger.valueOf(20L)));
        } else {
            value = value.longValue();
            expected = 20L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[180];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[180] + "' != '" + 238 + "'",
                    value.equals(BigInteger.valueOf(238L)));
        } else {
            value = value.longValue();
            expected = 238L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[181];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[181] + "' != '" + 130 + "'",
                    value.equals(BigInteger.valueOf(130L)));
        } else {
            value = value.longValue();
            expected = 130L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[182];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[182] + "' != '" + 243 + "'",
                    value.equals(BigInteger.valueOf(243L)));
        } else {
            value = value.longValue();
            expected = 243L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[183];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[183] + "' != '" + 68 + "'",
                    value.equals(BigInteger.valueOf(68L)));
        } else {
            value = value.longValue();
            expected = 68L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[184];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[184] + "' != '" + 4 + "'", value.equals(BigInteger.valueOf(4L)));
        } else {
            value = value.longValue();
            expected = 4L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[185];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[185] + "' != '" + 72 + "'",
                    value.equals(BigInteger.valueOf(72L)));
        } else {
            value = value.longValue();
            expected = 72L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[186];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[186] + "' != '" + 46 + "'",
                    value.equals(BigInteger.valueOf(46L)));
        } else {
            value = value.longValue();
            expected = 46L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[187];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[187] + "' != '" + 194 + "'",
                    value.equals(BigInteger.valueOf(194L)));
        } else {
            value = value.longValue();
            expected = 194L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[188];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[188] + "' != '" + 113 + "'",
                    value.equals(BigInteger.valueOf(113L)));
        } else {
            value = value.longValue();
            expected = 113L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[189];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[189] + "' != '" + 255 + "'",
                    value.equals(BigInteger.valueOf(255L)));
        } else {
            value = value.longValue();
            expected = 255L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[190];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[190] + "' != '" + 238 + "'",
                    value.equals(BigInteger.valueOf(238L)));
        } else {
            value = value.longValue();
            expected = 238L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[191];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[191] + "' != '" + 15 + "'",
                    value.equals(BigInteger.valueOf(15L)));
        } else {
            value = value.longValue();
            expected = 15L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[192];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[192] + "' != '" + 230 + "'",
                    value.equals(BigInteger.valueOf(230L)));
        } else {
            value = value.longValue();
            expected = 230L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[193];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[193] + "' != '" + 64 + "'",
                    value.equals(BigInteger.valueOf(64L)));
        } else {
            value = value.longValue();
            expected = 64L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[194];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[194] + "' != '" + 178 + "'",
                    value.equals(BigInteger.valueOf(178L)));
        } else {
            value = value.longValue();
            expected = 178L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[195];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[195] + "' != '" + 127 + "'",
                    value.equals(BigInteger.valueOf(127L)));
        } else {
            value = value.longValue();
            expected = 127L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[196];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[196] + "' != '" + 217 + "'",
                    value.equals(BigInteger.valueOf(217L)));
        } else {
            value = value.longValue();
            expected = 217L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[197];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[197] + "' != '" + 92 + "'",
                    value.equals(BigInteger.valueOf(92L)));
        } else {
            value = value.longValue();
            expected = 92L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[198];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[198] + "' != '" + 160 + "'",
                    value.equals(BigInteger.valueOf(160L)));
        } else {
            value = value.longValue();
            expected = 160L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[199];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[199] + "' != '" + 201 + "'",
                    value.equals(BigInteger.valueOf(201L)));
        } else {
            value = value.longValue();
            expected = 201L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[200];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[200] + "' != '" + 118 + "'",
                    value.equals(BigInteger.valueOf(118L)));
        } else {
            value = value.longValue();
            expected = 118L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[201];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[201] + "' != '" + 163 + "'",
                    value.equals(BigInteger.valueOf(163L)));
        } else {
            value = value.longValue();
            expected = 163L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[202];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[202] + "' != '" + 144 + "'",
                    value.equals(BigInteger.valueOf(144L)));
        } else {
            value = value.longValue();
            expected = 144L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[203];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[203] + "' != '" + 58 + "'",
                    value.equals(BigInteger.valueOf(58L)));
        } else {
            value = value.longValue();
            expected = 58L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[204];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[204] + "' != '" + 28 + "'",
                    value.equals(BigInteger.valueOf(28L)));
        } else {
            value = value.longValue();
            expected = 28L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[205];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[205] + "' != '" + 174 + "'",
                    value.equals(BigInteger.valueOf(174L)));
        } else {
            value = value.longValue();
            expected = 174L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[206];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[206] + "' != '" + 65 + "'",
                    value.equals(BigInteger.valueOf(65L)));
        } else {
            value = value.longValue();
            expected = 65L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[207];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[207] + "' != '" + 73 + "'",
                    value.equals(BigInteger.valueOf(73L)));
        } else {
            value = value.longValue();
            expected = 73L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[208];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[208] + "' != '" + 45 + "'",
                    value.equals(BigInteger.valueOf(45L)));
        } else {
            value = value.longValue();
            expected = 45L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[209];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[209] + "' != '" + 123 + "'",
                    value.equals(BigInteger.valueOf(123L)));
        } else {
            value = value.longValue();
            expected = 123L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[210];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[210] + "' != '" + 118 + "'",
                    value.equals(BigInteger.valueOf(118L)));
        } else {
            value = value.longValue();
            expected = 118L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[211];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[211] + "' != '" + 83 + "'",
                    value.equals(BigInteger.valueOf(83L)));
        } else {
            value = value.longValue();
            expected = 83L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[212];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[212] + "' != '" + 107 + "'",
                    value.equals(BigInteger.valueOf(107L)));
        } else {
            value = value.longValue();
            expected = 107L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[213];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[213] + "' != '" + 239 + "'",
                    value.equals(BigInteger.valueOf(239L)));
        } else {
            value = value.longValue();
            expected = 239L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[214];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[214] + "' != '" + 168 + "'",
                    value.equals(BigInteger.valueOf(168L)));
        } else {
            value = value.longValue();
            expected = 168L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[215];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[215] + "' != '" + 32 + "'",
                    value.equals(BigInteger.valueOf(32L)));
        } else {
            value = value.longValue();
            expected = 32L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[216];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[216] + "' != '" + 212 + "'",
                    value.equals(BigInteger.valueOf(212L)));
        } else {
            value = value.longValue();
            expected = 212L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[217];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[217] + "' != '" + 191 + "'",
                    value.equals(BigInteger.valueOf(191L)));
        } else {
            value = value.longValue();
            expected = 191L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[218];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[218] + "' != '" + 81 + "'",
                    value.equals(BigInteger.valueOf(81L)));
        } else {
            value = value.longValue();
            expected = 81L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[219];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[219] + "' != '" + 93 + "'",
                    value.equals(BigInteger.valueOf(93L)));
        } else {
            value = value.longValue();
            expected = 93L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[220];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[220] + "' != '" + 186 + "'",
                    value.equals(BigInteger.valueOf(186L)));
        } else {
            value = value.longValue();
            expected = 186L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[221];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[221] + "' != '" + 223 + "'",
                    value.equals(BigInteger.valueOf(223L)));
        } else {
            value = value.longValue();
            expected = 223L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[222];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[222] + "' != '" + 32 + "'",
                    value.equals(BigInteger.valueOf(32L)));
        } else {
            value = value.longValue();
            expected = 32L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[223];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[223] + "' != '" + 19 + "'",
                    value.equals(BigInteger.valueOf(19L)));
        } else {
            value = value.longValue();
            expected = 19L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[224];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[224] + "' != '" + 58 + "'",
                    value.equals(BigInteger.valueOf(58L)));
        } else {
            value = value.longValue();
            expected = 58L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[225];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[225] + "' != '" + 137 + "'",
                    value.equals(BigInteger.valueOf(137L)));
        } else {
            value = value.longValue();
            expected = 137L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[226];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[226] + "' != '" + 72 + "'",
                    value.equals(BigInteger.valueOf(72L)));
        } else {
            value = value.longValue();
            expected = 72L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[227];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[227] + "' != '" + 217 + "'",
                    value.equals(BigInteger.valueOf(217L)));
        } else {
            value = value.longValue();
            expected = 217L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[228];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[228] + "' != '" + 151 + "'",
                    value.equals(BigInteger.valueOf(151L)));
        } else {
            value = value.longValue();
            expected = 151L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[229];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[229] + "' != '" + 251 + "'",
                    value.equals(BigInteger.valueOf(251L)));
        } else {
            value = value.longValue();
            expected = 251L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[230];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[230] + "' != '" + 83 + "'",
                    value.equals(BigInteger.valueOf(83L)));
        } else {
            value = value.longValue();
            expected = 83L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[231];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[231] + "' != '" + 20 + "'",
                    value.equals(BigInteger.valueOf(20L)));
        } else {
            value = value.longValue();
            expected = 20L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[232];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[232] + "' != '" + 113 + "'",
                    value.equals(BigInteger.valueOf(113L)));
        } else {
            value = value.longValue();
            expected = 113L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[233];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[233] + "' != '" + 37 + "'",
                    value.equals(BigInteger.valueOf(37L)));
        } else {
            value = value.longValue();
            expected = 37L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[234];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[234] + "' != '" + 151 + "'",
                    value.equals(BigInteger.valueOf(151L)));
        } else {
            value = value.longValue();
            expected = 151L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[235];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[235] + "' != '" + 34 + "'",
                    value.equals(BigInteger.valueOf(34L)));
        } else {
            value = value.longValue();
            expected = 34L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[236];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[236] + "' != '" + 37 + "'",
                    value.equals(BigInteger.valueOf(37L)));
        } else {
            value = value.longValue();
            expected = 37L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[237];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[237] + "' != '" + 71 + "'",
                    value.equals(BigInteger.valueOf(71L)));
        } else {
            value = value.longValue();
            expected = 71L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[238];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[238] + "' != '" + 95 + "'",
                    value.equals(BigInteger.valueOf(95L)));
        } else {
            value = value.longValue();
            expected = 95L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[239];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[239] + "' != '" + 105 + "'",
                    value.equals(BigInteger.valueOf(105L)));
        } else {
            value = value.longValue();
            expected = 105L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[240];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[240] + "' != '" + 235 + "'",
                    value.equals(BigInteger.valueOf(235L)));
        } else {
            value = value.longValue();
            expected = 235L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[241];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[241] + "' != '" + 144 + "'",
                    value.equals(BigInteger.valueOf(144L)));
        } else {
            value = value.longValue();
            expected = 144L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[242];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[242] + "' != '" + 164 + "'",
                    value.equals(BigInteger.valueOf(164L)));
        } else {
            value = value.longValue();
            expected = 164L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[243];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[243] + "' != '" + 83 + "'",
                    value.equals(BigInteger.valueOf(83L)));
        } else {
            value = value.longValue();
            expected = 83L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[244];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[244] + "' != '" + 197 + "'",
                    value.equals(BigInteger.valueOf(197L)));
        } else {
            value = value.longValue();
            expected = 197L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[245];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[245] + "' != '" + 254 + "'",
                    value.equals(BigInteger.valueOf(254L)));
        } else {
            value = value.longValue();
            expected = 254L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[246];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[246] + "' != '" + 183 + "'",
                    value.equals(BigInteger.valueOf(183L)));
        } else {
            value = value.longValue();
            expected = 183L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[247];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[247] + "' != '" + 223 + "'",
                    value.equals(BigInteger.valueOf(223L)));
        } else {
            value = value.longValue();
            expected = 223L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[248];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[248] + "' != '" + 91 + "'",
                    value.equals(BigInteger.valueOf(91L)));
        } else {
            value = value.longValue();
            expected = 91L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.data[249];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.data[249] + "' != '" + 19 + "'",
                    value.equals(BigInteger.valueOf(19L)));
        } else {
            value = value.longValue();
            expected = 19L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.target;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.target + "' != '" + 212 + "'",
                    value.equals(BigInteger.valueOf(212L)));
        } else {
            value = value.longValue();
            expected = 212L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
