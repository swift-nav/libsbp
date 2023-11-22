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

// This file was auto-generated from
// spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrSatelliteApcDepA.yaml by generate.py. Do not modify
// by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.ssr.MsgSsrSatelliteApcDep;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_ssr_MsgSsrSatelliteApcDepATest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_ssr_MsgSsrSatelliteApcDepATest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 203,
                    (byte) 169,
                    (byte) 240,
                    (byte) 78,
                    (byte) 4,
                    (byte) 213,
                    (byte) 171,
                    (byte) 254,
                    (byte) 214,
                    (byte) 212,
                    (byte) 4,
                    (byte) 8,
                    (byte) 33,
                    (byte) 31,
                    (byte) 80,
                    (byte) 21,
                    (byte) 4,
                    (byte) 105,
                    (byte) 225,
                    (byte) 39,
                    (byte) 139,
                    (byte) 124,
                    (byte) 149,
                    (byte) 48,
                    (byte) 15,
                    (byte) 214,
                    (byte) 197,
                    (byte) 141,
                    (byte) 32,
                    (byte) 33,
                    (byte) 135,
                    (byte) 150,
                    (byte) 148,
                    (byte) 123,
                    (byte) 49,
                    (byte) 135,
                    (byte) 97,
                    (byte) 39,
                    (byte) 90,
                    (byte) 20,
                    (byte) 169,
                    (byte) 239,
                    (byte) 47,
                    (byte) 153,
                    (byte) 175,
                    (byte) 35,
                    (byte) 145,
                    (byte) 145,
                    (byte) 123,
                    (byte) 194,
                    (byte) 2,
                    (byte) 102,
                    (byte) 74,
                    (byte) 149,
                    (byte) 95,
                    (byte) 171,
                    (byte) 238,
                    (byte) 249,
                    (byte) 7,
                    (byte) 237,
                    (byte) 170,
                    (byte) 125,
                    (byte) 106,
                    (byte) 158,
                    (byte) 83,
                    (byte) 188,
                    (byte) 181,
                    (byte) 194,
                    (byte) 27,
                    (byte) 84,
                    (byte) 226,
                    (byte) 142,
                    (byte) 123,
                    (byte) 77,
                    (byte) 217,
                    (byte) 248,
                    (byte) 67,
                    (byte) 215,
                    (byte) 129,
                    (byte) 114,
                    (byte) 138,
                    (byte) 25,
                    (byte) 240,
                    (byte) 10,
                    (byte) 56,
                    (byte) 76,
                    (byte) 61,
                    (byte) 161,
                    (byte) 216,
                    (byte) 22,
                    (byte) 181,
                    (byte) 174,
                    (byte) 33,
                    (byte) 13,
                    (byte) 252,
                    (byte) 236,
                    (byte) 230,
                    (byte) 196,
                    (byte) 128,
                    (byte) 215,
                    (byte) 239,
                    (byte) 234,
                    (byte) 179,
                    (byte) 220,
                    (byte) 44,
                    (byte) 212,
                    (byte) 57,
                    (byte) 44,
                    (byte) 173,
                    (byte) 49,
                    (byte) 36,
                    (byte) 137,
                    (byte) 248,
                    (byte) 235,
                    (byte) 97,
                    (byte) 112,
                    (byte) 157,
                    (byte) 139,
                    (byte) 26,
                    (byte) 115,
                    (byte) 192,
                    (byte) 31,
                    (byte) 85,
                    (byte) 127,
                    (byte) 228,
                    (byte) 81,
                    (byte) 252,
                    (byte) 219,
                    (byte) 249,
                    (byte) 110,
                    (byte) 147,
                    (byte) 8,
                    (byte) 161,
                    (byte) 215,
                    (byte) 212,
                    (byte) 180,
                    (byte) 25,
                    (byte) 83,
                    (byte) 144,
                    (byte) 247,
                    (byte) 12,
                    (byte) 27,
                    (byte) 199,
                    (byte) 173,
                    (byte) 74,
                    (byte) 23,
                    (byte) 4,
                    (byte) 239,
                    (byte) 103,
                    (byte) 223,
                    (byte) 220,
                    (byte) 139,
                    (byte) 91,
                    (byte) 127,
                    (byte) 214,
                    (byte) 86,
                    (byte) 48,
                    (byte) 203,
                    (byte) 228,
                    (byte) 99,
                    (byte) 45,
                    (byte) 83,
                    (byte) 159,
                    (byte) 11,
                    (byte) 250,
                    (byte) 135,
                    (byte) 170,
                    (byte) 42,
                    (byte) 217,
                    (byte) 199,
                    (byte) 233,
                    (byte) 42,
                    (byte) 170,
                    (byte) 78,
                    (byte) 206,
                    (byte) 41,
                    (byte) 43,
                    (byte) 81,
                    (byte) 247,
                    (byte) 99,
                    (byte) 198,
                    (byte) 144,
                    (byte) 2,
                    (byte) 132,
                    (byte) 2,
                    (byte) 224,
                    (byte) 220,
                    (byte) 148,
                    (byte) 58,
                    (byte) 85,
                    (byte) 138,
                    (byte) 210,
                    (byte) 200,
                    (byte) 158,
                    (byte) 7,
                    (byte) 158,
                    (byte) 67,
                    (byte) 46,
                    (byte) 200,
                    (byte) 132,
                    (byte) 118,
                    (byte) 241,
                    (byte) 13,
                    (byte) 37,
                    (byte) 62,
                    (byte) 107,
                    (byte) 253,
                    (byte) 190,
                    (byte) 136,
                    (byte) 66,
                    (byte) 9,
                    (byte) 84,
                    (byte) 155,
                    (byte) 86,
                    (byte) 180,
                    (byte) 41,
                    (byte) 196,
                    (byte) 40,
                    (byte) 119,
                    (byte) 101,
                    (byte) 252,
                    (byte) 223,
                    (byte) 144,
                    (byte) 153,
                };
        SBPMessage sbp = new SBPMessage(0x1338, 0x604, payload);
        MsgSsrSatelliteApcDep msg = new MsgSsrSatelliteApcDep(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.apc[0].pco[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[0].pco[0] + "' != '" + -21547 + "'",
                    value.equals(BigInteger.valueOf(-21547L)));
        } else {
            value = value.longValue();
            expected = -21547L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[0].pco[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[0].pco[1] + "' != '" + -10498 + "'",
                    value.equals(BigInteger.valueOf(-10498L)));
        } else {
            value = value.longValue();
            expected = -10498L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[0].pco[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[0].pco[2] + "' != '" + 1236 + "'",
                    value.equals(BigInteger.valueOf(1236L)));
        } else {
            value = value.longValue();
            expected = 1236L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[0].pcv[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[0].pcv[0] + "' != '" + 8 + "'",
                    value.equals(BigInteger.valueOf(8L)));
        } else {
            value = value.longValue();
            expected = 8L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[0].pcv[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[0].pcv[1] + "' != '" + 33 + "'",
                    value.equals(BigInteger.valueOf(33L)));
        } else {
            value = value.longValue();
            expected = 33L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[0].pcv[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[0].pcv[2] + "' != '" + 31 + "'",
                    value.equals(BigInteger.valueOf(31L)));
        } else {
            value = value.longValue();
            expected = 31L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[0].pcv[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[0].pcv[3] + "' != '" + 80 + "'",
                    value.equals(BigInteger.valueOf(80L)));
        } else {
            value = value.longValue();
            expected = 80L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[0].pcv[4];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[0].pcv[4] + "' != '" + 21 + "'",
                    value.equals(BigInteger.valueOf(21L)));
        } else {
            value = value.longValue();
            expected = 21L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[0].pcv[5];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[0].pcv[5] + "' != '" + 4 + "'",
                    value.equals(BigInteger.valueOf(4L)));
        } else {
            value = value.longValue();
            expected = 4L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[0].pcv[6];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[0].pcv[6] + "' != '" + 105 + "'",
                    value.equals(BigInteger.valueOf(105L)));
        } else {
            value = value.longValue();
            expected = 105L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[0].pcv[7];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[0].pcv[7] + "' != '" + -31 + "'",
                    value.equals(BigInteger.valueOf(-31L)));
        } else {
            value = value.longValue();
            expected = -31L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[0].pcv[8];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[0].pcv[8] + "' != '" + 39 + "'",
                    value.equals(BigInteger.valueOf(39L)));
        } else {
            value = value.longValue();
            expected = 39L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[0].pcv[9];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[0].pcv[9] + "' != '" + -117 + "'",
                    value.equals(BigInteger.valueOf(-117L)));
        } else {
            value = value.longValue();
            expected = -117L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[0].pcv[10];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[0].pcv[10] + "' != '" + 124 + "'",
                    value.equals(BigInteger.valueOf(124L)));
        } else {
            value = value.longValue();
            expected = 124L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[0].pcv[11];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[0].pcv[11] + "' != '" + -107 + "'",
                    value.equals(BigInteger.valueOf(-107L)));
        } else {
            value = value.longValue();
            expected = -107L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[0].pcv[12];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[0].pcv[12] + "' != '" + 48 + "'",
                    value.equals(BigInteger.valueOf(48L)));
        } else {
            value = value.longValue();
            expected = 48L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[0].pcv[13];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[0].pcv[13] + "' != '" + 15 + "'",
                    value.equals(BigInteger.valueOf(15L)));
        } else {
            value = value.longValue();
            expected = 15L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[0].pcv[14];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[0].pcv[14] + "' != '" + -42 + "'",
                    value.equals(BigInteger.valueOf(-42L)));
        } else {
            value = value.longValue();
            expected = -42L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[0].pcv[15];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[0].pcv[15] + "' != '" + -59 + "'",
                    value.equals(BigInteger.valueOf(-59L)));
        } else {
            value = value.longValue();
            expected = -59L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[0].pcv[16];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[0].pcv[16] + "' != '" + -115 + "'",
                    value.equals(BigInteger.valueOf(-115L)));
        } else {
            value = value.longValue();
            expected = -115L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[0].pcv[17];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[0].pcv[17] + "' != '" + 32 + "'",
                    value.equals(BigInteger.valueOf(32L)));
        } else {
            value = value.longValue();
            expected = 32L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[0].pcv[18];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[0].pcv[18] + "' != '" + 33 + "'",
                    value.equals(BigInteger.valueOf(33L)));
        } else {
            value = value.longValue();
            expected = 33L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[0].pcv[19];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[0].pcv[19] + "' != '" + -121 + "'",
                    value.equals(BigInteger.valueOf(-121L)));
        } else {
            value = value.longValue();
            expected = -121L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[0].pcv[20];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[0].pcv[20] + "' != '" + -106 + "'",
                    value.equals(BigInteger.valueOf(-106L)));
        } else {
            value = value.longValue();
            expected = -106L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[0].sat_info;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[0].sat_info + "' != '" + 240 + "'",
                    value.equals(BigInteger.valueOf(240L)));
        } else {
            value = value.longValue();
            expected = 240L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[0].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[0].sid.code + "' != '" + 169 + "'",
                    value.equals(BigInteger.valueOf(169L)));
        } else {
            value = value.longValue();
            expected = 169L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[0].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[0].sid.sat + "' != '" + 203 + "'",
                    value.equals(BigInteger.valueOf(203L)));
        } else {
            value = value.longValue();
            expected = 203L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[0].svn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[0].svn + "' != '" + 1102 + "'",
                    value.equals(BigInteger.valueOf(1102L)));
        } else {
            value = value.longValue();
            expected = 1102L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[1].pco[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[1].pco[0] + "' != '" + 23079 + "'",
                    value.equals(BigInteger.valueOf(23079L)));
        } else {
            value = value.longValue();
            expected = 23079L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[1].pco[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[1].pco[1] + "' != '" + -22252 + "'",
                    value.equals(BigInteger.valueOf(-22252L)));
        } else {
            value = value.longValue();
            expected = -22252L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[1].pco[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[1].pco[2] + "' != '" + 12271 + "'",
                    value.equals(BigInteger.valueOf(12271L)));
        } else {
            value = value.longValue();
            expected = 12271L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[1].pcv[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[1].pcv[0] + "' != '" + -103 + "'",
                    value.equals(BigInteger.valueOf(-103L)));
        } else {
            value = value.longValue();
            expected = -103L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[1].pcv[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[1].pcv[1] + "' != '" + -81 + "'",
                    value.equals(BigInteger.valueOf(-81L)));
        } else {
            value = value.longValue();
            expected = -81L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[1].pcv[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[1].pcv[2] + "' != '" + 35 + "'",
                    value.equals(BigInteger.valueOf(35L)));
        } else {
            value = value.longValue();
            expected = 35L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[1].pcv[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[1].pcv[3] + "' != '" + -111 + "'",
                    value.equals(BigInteger.valueOf(-111L)));
        } else {
            value = value.longValue();
            expected = -111L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[1].pcv[4];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[1].pcv[4] + "' != '" + -111 + "'",
                    value.equals(BigInteger.valueOf(-111L)));
        } else {
            value = value.longValue();
            expected = -111L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[1].pcv[5];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[1].pcv[5] + "' != '" + 123 + "'",
                    value.equals(BigInteger.valueOf(123L)));
        } else {
            value = value.longValue();
            expected = 123L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[1].pcv[6];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[1].pcv[6] + "' != '" + -62 + "'",
                    value.equals(BigInteger.valueOf(-62L)));
        } else {
            value = value.longValue();
            expected = -62L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[1].pcv[7];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[1].pcv[7] + "' != '" + 2 + "'",
                    value.equals(BigInteger.valueOf(2L)));
        } else {
            value = value.longValue();
            expected = 2L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[1].pcv[8];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[1].pcv[8] + "' != '" + 102 + "'",
                    value.equals(BigInteger.valueOf(102L)));
        } else {
            value = value.longValue();
            expected = 102L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[1].pcv[9];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[1].pcv[9] + "' != '" + 74 + "'",
                    value.equals(BigInteger.valueOf(74L)));
        } else {
            value = value.longValue();
            expected = 74L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[1].pcv[10];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[1].pcv[10] + "' != '" + -107 + "'",
                    value.equals(BigInteger.valueOf(-107L)));
        } else {
            value = value.longValue();
            expected = -107L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[1].pcv[11];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[1].pcv[11] + "' != '" + 95 + "'",
                    value.equals(BigInteger.valueOf(95L)));
        } else {
            value = value.longValue();
            expected = 95L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[1].pcv[12];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[1].pcv[12] + "' != '" + -85 + "'",
                    value.equals(BigInteger.valueOf(-85L)));
        } else {
            value = value.longValue();
            expected = -85L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[1].pcv[13];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[1].pcv[13] + "' != '" + -18 + "'",
                    value.equals(BigInteger.valueOf(-18L)));
        } else {
            value = value.longValue();
            expected = -18L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[1].pcv[14];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[1].pcv[14] + "' != '" + -7 + "'",
                    value.equals(BigInteger.valueOf(-7L)));
        } else {
            value = value.longValue();
            expected = -7L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[1].pcv[15];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[1].pcv[15] + "' != '" + 7 + "'",
                    value.equals(BigInteger.valueOf(7L)));
        } else {
            value = value.longValue();
            expected = 7L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[1].pcv[16];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[1].pcv[16] + "' != '" + -19 + "'",
                    value.equals(BigInteger.valueOf(-19L)));
        } else {
            value = value.longValue();
            expected = -19L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[1].pcv[17];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[1].pcv[17] + "' != '" + -86 + "'",
                    value.equals(BigInteger.valueOf(-86L)));
        } else {
            value = value.longValue();
            expected = -86L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[1].pcv[18];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[1].pcv[18] + "' != '" + 125 + "'",
                    value.equals(BigInteger.valueOf(125L)));
        } else {
            value = value.longValue();
            expected = 125L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[1].pcv[19];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[1].pcv[19] + "' != '" + 106 + "'",
                    value.equals(BigInteger.valueOf(106L)));
        } else {
            value = value.longValue();
            expected = 106L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[1].pcv[20];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[1].pcv[20] + "' != '" + -98 + "'",
                    value.equals(BigInteger.valueOf(-98L)));
        } else {
            value = value.longValue();
            expected = -98L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[1].sat_info;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[1].sat_info + "' != '" + 49 + "'",
                    value.equals(BigInteger.valueOf(49L)));
        } else {
            value = value.longValue();
            expected = 49L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[1].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[1].sid.code + "' != '" + 123 + "'",
                    value.equals(BigInteger.valueOf(123L)));
        } else {
            value = value.longValue();
            expected = 123L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[1].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[1].sid.sat + "' != '" + 148 + "'",
                    value.equals(BigInteger.valueOf(148L)));
        } else {
            value = value.longValue();
            expected = 148L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[1].svn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[1].svn + "' != '" + 24967 + "'",
                    value.equals(BigInteger.valueOf(24967L)));
        } else {
            value = value.longValue();
            expected = 24967L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[2].pco[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[2].pco[0] + "' != '" + -7596 + "'",
                    value.equals(BigInteger.valueOf(-7596L)));
        } else {
            value = value.longValue();
            expected = -7596L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[2].pco[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[2].pco[1] + "' != '" + 31630 + "'",
                    value.equals(BigInteger.valueOf(31630L)));
        } else {
            value = value.longValue();
            expected = 31630L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[2].pco[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[2].pco[2] + "' != '" + -9907 + "'",
                    value.equals(BigInteger.valueOf(-9907L)));
        } else {
            value = value.longValue();
            expected = -9907L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[2].pcv[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[2].pcv[0] + "' != '" + -8 + "'",
                    value.equals(BigInteger.valueOf(-8L)));
        } else {
            value = value.longValue();
            expected = -8L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[2].pcv[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[2].pcv[1] + "' != '" + 67 + "'",
                    value.equals(BigInteger.valueOf(67L)));
        } else {
            value = value.longValue();
            expected = 67L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[2].pcv[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[2].pcv[2] + "' != '" + -41 + "'",
                    value.equals(BigInteger.valueOf(-41L)));
        } else {
            value = value.longValue();
            expected = -41L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[2].pcv[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[2].pcv[3] + "' != '" + -127 + "'",
                    value.equals(BigInteger.valueOf(-127L)));
        } else {
            value = value.longValue();
            expected = -127L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[2].pcv[4];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[2].pcv[4] + "' != '" + 114 + "'",
                    value.equals(BigInteger.valueOf(114L)));
        } else {
            value = value.longValue();
            expected = 114L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[2].pcv[5];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[2].pcv[5] + "' != '" + -118 + "'",
                    value.equals(BigInteger.valueOf(-118L)));
        } else {
            value = value.longValue();
            expected = -118L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[2].pcv[6];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[2].pcv[6] + "' != '" + 25 + "'",
                    value.equals(BigInteger.valueOf(25L)));
        } else {
            value = value.longValue();
            expected = 25L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[2].pcv[7];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[2].pcv[7] + "' != '" + -16 + "'",
                    value.equals(BigInteger.valueOf(-16L)));
        } else {
            value = value.longValue();
            expected = -16L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[2].pcv[8];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[2].pcv[8] + "' != '" + 10 + "'",
                    value.equals(BigInteger.valueOf(10L)));
        } else {
            value = value.longValue();
            expected = 10L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[2].pcv[9];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[2].pcv[9] + "' != '" + 56 + "'",
                    value.equals(BigInteger.valueOf(56L)));
        } else {
            value = value.longValue();
            expected = 56L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[2].pcv[10];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[2].pcv[10] + "' != '" + 76 + "'",
                    value.equals(BigInteger.valueOf(76L)));
        } else {
            value = value.longValue();
            expected = 76L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[2].pcv[11];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[2].pcv[11] + "' != '" + 61 + "'",
                    value.equals(BigInteger.valueOf(61L)));
        } else {
            value = value.longValue();
            expected = 61L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[2].pcv[12];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[2].pcv[12] + "' != '" + -95 + "'",
                    value.equals(BigInteger.valueOf(-95L)));
        } else {
            value = value.longValue();
            expected = -95L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[2].pcv[13];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[2].pcv[13] + "' != '" + -40 + "'",
                    value.equals(BigInteger.valueOf(-40L)));
        } else {
            value = value.longValue();
            expected = -40L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[2].pcv[14];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[2].pcv[14] + "' != '" + 22 + "'",
                    value.equals(BigInteger.valueOf(22L)));
        } else {
            value = value.longValue();
            expected = 22L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[2].pcv[15];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[2].pcv[15] + "' != '" + -75 + "'",
                    value.equals(BigInteger.valueOf(-75L)));
        } else {
            value = value.longValue();
            expected = -75L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[2].pcv[16];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[2].pcv[16] + "' != '" + -82 + "'",
                    value.equals(BigInteger.valueOf(-82L)));
        } else {
            value = value.longValue();
            expected = -82L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[2].pcv[17];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[2].pcv[17] + "' != '" + 33 + "'",
                    value.equals(BigInteger.valueOf(33L)));
        } else {
            value = value.longValue();
            expected = 33L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[2].pcv[18];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[2].pcv[18] + "' != '" + 13 + "'",
                    value.equals(BigInteger.valueOf(13L)));
        } else {
            value = value.longValue();
            expected = 13L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[2].pcv[19];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[2].pcv[19] + "' != '" + -4 + "'",
                    value.equals(BigInteger.valueOf(-4L)));
        } else {
            value = value.longValue();
            expected = -4L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[2].pcv[20];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[2].pcv[20] + "' != '" + -20 + "'",
                    value.equals(BigInteger.valueOf(-20L)));
        } else {
            value = value.longValue();
            expected = -20L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[2].sat_info;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[2].sat_info + "' != '" + 181 + "'",
                    value.equals(BigInteger.valueOf(181L)));
        } else {
            value = value.longValue();
            expected = 181L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[2].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[2].sid.code + "' != '" + 188 + "'",
                    value.equals(BigInteger.valueOf(188L)));
        } else {
            value = value.longValue();
            expected = 188L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[2].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[2].sid.sat + "' != '" + 83 + "'",
                    value.equals(BigInteger.valueOf(83L)));
        } else {
            value = value.longValue();
            expected = 83L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[2].svn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[2].svn + "' != '" + 7106 + "'",
                    value.equals(BigInteger.valueOf(7106L)));
        } else {
            value = value.longValue();
            expected = 7106L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[3].pco[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[3].pco[0] + "' != '" + -19478 + "'",
                    value.equals(BigInteger.valueOf(-19478L)));
        } else {
            value = value.longValue();
            expected = -19478L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[3].pco[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[3].pco[1] + "' != '" + 11484 + "'",
                    value.equals(BigInteger.valueOf(11484L)));
        } else {
            value = value.longValue();
            expected = 11484L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[3].pco[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[3].pco[2] + "' != '" + 14804 + "'",
                    value.equals(BigInteger.valueOf(14804L)));
        } else {
            value = value.longValue();
            expected = 14804L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[3].pcv[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[3].pcv[0] + "' != '" + 44 + "'",
                    value.equals(BigInteger.valueOf(44L)));
        } else {
            value = value.longValue();
            expected = 44L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[3].pcv[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[3].pcv[1] + "' != '" + -83 + "'",
                    value.equals(BigInteger.valueOf(-83L)));
        } else {
            value = value.longValue();
            expected = -83L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[3].pcv[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[3].pcv[2] + "' != '" + 49 + "'",
                    value.equals(BigInteger.valueOf(49L)));
        } else {
            value = value.longValue();
            expected = 49L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[3].pcv[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[3].pcv[3] + "' != '" + 36 + "'",
                    value.equals(BigInteger.valueOf(36L)));
        } else {
            value = value.longValue();
            expected = 36L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[3].pcv[4];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[3].pcv[4] + "' != '" + -119 + "'",
                    value.equals(BigInteger.valueOf(-119L)));
        } else {
            value = value.longValue();
            expected = -119L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[3].pcv[5];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[3].pcv[5] + "' != '" + -8 + "'",
                    value.equals(BigInteger.valueOf(-8L)));
        } else {
            value = value.longValue();
            expected = -8L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[3].pcv[6];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[3].pcv[6] + "' != '" + -21 + "'",
                    value.equals(BigInteger.valueOf(-21L)));
        } else {
            value = value.longValue();
            expected = -21L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[3].pcv[7];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[3].pcv[7] + "' != '" + 97 + "'",
                    value.equals(BigInteger.valueOf(97L)));
        } else {
            value = value.longValue();
            expected = 97L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[3].pcv[8];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[3].pcv[8] + "' != '" + 112 + "'",
                    value.equals(BigInteger.valueOf(112L)));
        } else {
            value = value.longValue();
            expected = 112L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[3].pcv[9];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[3].pcv[9] + "' != '" + -99 + "'",
                    value.equals(BigInteger.valueOf(-99L)));
        } else {
            value = value.longValue();
            expected = -99L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[3].pcv[10];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[3].pcv[10] + "' != '" + -117 + "'",
                    value.equals(BigInteger.valueOf(-117L)));
        } else {
            value = value.longValue();
            expected = -117L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[3].pcv[11];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[3].pcv[11] + "' != '" + 26 + "'",
                    value.equals(BigInteger.valueOf(26L)));
        } else {
            value = value.longValue();
            expected = 26L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[3].pcv[12];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[3].pcv[12] + "' != '" + 115 + "'",
                    value.equals(BigInteger.valueOf(115L)));
        } else {
            value = value.longValue();
            expected = 115L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[3].pcv[13];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[3].pcv[13] + "' != '" + -64 + "'",
                    value.equals(BigInteger.valueOf(-64L)));
        } else {
            value = value.longValue();
            expected = -64L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[3].pcv[14];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[3].pcv[14] + "' != '" + 31 + "'",
                    value.equals(BigInteger.valueOf(31L)));
        } else {
            value = value.longValue();
            expected = 31L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[3].pcv[15];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[3].pcv[15] + "' != '" + 85 + "'",
                    value.equals(BigInteger.valueOf(85L)));
        } else {
            value = value.longValue();
            expected = 85L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[3].pcv[16];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[3].pcv[16] + "' != '" + 127 + "'",
                    value.equals(BigInteger.valueOf(127L)));
        } else {
            value = value.longValue();
            expected = 127L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[3].pcv[17];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[3].pcv[17] + "' != '" + -28 + "'",
                    value.equals(BigInteger.valueOf(-28L)));
        } else {
            value = value.longValue();
            expected = -28L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[3].pcv[18];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[3].pcv[18] + "' != '" + 81 + "'",
                    value.equals(BigInteger.valueOf(81L)));
        } else {
            value = value.longValue();
            expected = 81L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[3].pcv[19];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[3].pcv[19] + "' != '" + -4 + "'",
                    value.equals(BigInteger.valueOf(-4L)));
        } else {
            value = value.longValue();
            expected = -4L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[3].pcv[20];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[3].pcv[20] + "' != '" + -37 + "'",
                    value.equals(BigInteger.valueOf(-37L)));
        } else {
            value = value.longValue();
            expected = -37L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[3].sat_info;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[3].sat_info + "' != '" + 128 + "'",
                    value.equals(BigInteger.valueOf(128L)));
        } else {
            value = value.longValue();
            expected = 128L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[3].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[3].sid.code + "' != '" + 196 + "'",
                    value.equals(BigInteger.valueOf(196L)));
        } else {
            value = value.longValue();
            expected = 196L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[3].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[3].sid.sat + "' != '" + 230 + "'",
                    value.equals(BigInteger.valueOf(230L)));
        } else {
            value = value.longValue();
            expected = 230L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[3].svn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[3].svn + "' != '" + 61399 + "'",
                    value.equals(BigInteger.valueOf(61399L)));
        } else {
            value = value.longValue();
            expected = 61399L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[4].pco[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[4].pco[0] + "' != '" + -11049 + "'",
                    value.equals(BigInteger.valueOf(-11049L)));
        } else {
            value = value.longValue();
            expected = -11049L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[4].pco[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[4].pco[1] + "' != '" + 6580 + "'",
                    value.equals(BigInteger.valueOf(6580L)));
        } else {
            value = value.longValue();
            expected = 6580L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[4].pco[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[4].pco[2] + "' != '" + -28589 + "'",
                    value.equals(BigInteger.valueOf(-28589L)));
        } else {
            value = value.longValue();
            expected = -28589L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[4].pcv[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[4].pcv[0] + "' != '" + -9 + "'",
                    value.equals(BigInteger.valueOf(-9L)));
        } else {
            value = value.longValue();
            expected = -9L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[4].pcv[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[4].pcv[1] + "' != '" + 12 + "'",
                    value.equals(BigInteger.valueOf(12L)));
        } else {
            value = value.longValue();
            expected = 12L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[4].pcv[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[4].pcv[2] + "' != '" + 27 + "'",
                    value.equals(BigInteger.valueOf(27L)));
        } else {
            value = value.longValue();
            expected = 27L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[4].pcv[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[4].pcv[3] + "' != '" + -57 + "'",
                    value.equals(BigInteger.valueOf(-57L)));
        } else {
            value = value.longValue();
            expected = -57L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[4].pcv[4];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[4].pcv[4] + "' != '" + -83 + "'",
                    value.equals(BigInteger.valueOf(-83L)));
        } else {
            value = value.longValue();
            expected = -83L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[4].pcv[5];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[4].pcv[5] + "' != '" + 74 + "'",
                    value.equals(BigInteger.valueOf(74L)));
        } else {
            value = value.longValue();
            expected = 74L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[4].pcv[6];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[4].pcv[6] + "' != '" + 23 + "'",
                    value.equals(BigInteger.valueOf(23L)));
        } else {
            value = value.longValue();
            expected = 23L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[4].pcv[7];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[4].pcv[7] + "' != '" + 4 + "'",
                    value.equals(BigInteger.valueOf(4L)));
        } else {
            value = value.longValue();
            expected = 4L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[4].pcv[8];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[4].pcv[8] + "' != '" + -17 + "'",
                    value.equals(BigInteger.valueOf(-17L)));
        } else {
            value = value.longValue();
            expected = -17L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[4].pcv[9];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[4].pcv[9] + "' != '" + 103 + "'",
                    value.equals(BigInteger.valueOf(103L)));
        } else {
            value = value.longValue();
            expected = 103L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[4].pcv[10];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[4].pcv[10] + "' != '" + -33 + "'",
                    value.equals(BigInteger.valueOf(-33L)));
        } else {
            value = value.longValue();
            expected = -33L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[4].pcv[11];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[4].pcv[11] + "' != '" + -36 + "'",
                    value.equals(BigInteger.valueOf(-36L)));
        } else {
            value = value.longValue();
            expected = -36L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[4].pcv[12];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[4].pcv[12] + "' != '" + -117 + "'",
                    value.equals(BigInteger.valueOf(-117L)));
        } else {
            value = value.longValue();
            expected = -117L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[4].pcv[13];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[4].pcv[13] + "' != '" + 91 + "'",
                    value.equals(BigInteger.valueOf(91L)));
        } else {
            value = value.longValue();
            expected = 91L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[4].pcv[14];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[4].pcv[14] + "' != '" + 127 + "'",
                    value.equals(BigInteger.valueOf(127L)));
        } else {
            value = value.longValue();
            expected = 127L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[4].pcv[15];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[4].pcv[15] + "' != '" + -42 + "'",
                    value.equals(BigInteger.valueOf(-42L)));
        } else {
            value = value.longValue();
            expected = -42L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[4].pcv[16];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[4].pcv[16] + "' != '" + 86 + "'",
                    value.equals(BigInteger.valueOf(86L)));
        } else {
            value = value.longValue();
            expected = 86L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[4].pcv[17];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[4].pcv[17] + "' != '" + 48 + "'",
                    value.equals(BigInteger.valueOf(48L)));
        } else {
            value = value.longValue();
            expected = 48L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[4].pcv[18];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[4].pcv[18] + "' != '" + -53 + "'",
                    value.equals(BigInteger.valueOf(-53L)));
        } else {
            value = value.longValue();
            expected = -53L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[4].pcv[19];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[4].pcv[19] + "' != '" + -28 + "'",
                    value.equals(BigInteger.valueOf(-28L)));
        } else {
            value = value.longValue();
            expected = -28L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[4].pcv[20];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[4].pcv[20] + "' != '" + 99 + "'",
                    value.equals(BigInteger.valueOf(99L)));
        } else {
            value = value.longValue();
            expected = 99L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[4].sat_info;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[4].sat_info + "' != '" + 147 + "'",
                    value.equals(BigInteger.valueOf(147L)));
        } else {
            value = value.longValue();
            expected = 147L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[4].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[4].sid.code + "' != '" + 110 + "'",
                    value.equals(BigInteger.valueOf(110L)));
        } else {
            value = value.longValue();
            expected = 110L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[4].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[4].sid.sat + "' != '" + 249 + "'",
                    value.equals(BigInteger.valueOf(249L)));
        } else {
            value = value.longValue();
            expected = 249L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[4].svn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[4].svn + "' != '" + 41224 + "'",
                    value.equals(BigInteger.valueOf(41224L)));
        } else {
            value = value.longValue();
            expected = 41224L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[5].pco[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[5].pco[0] + "' != '" + -21881 + "'",
                    value.equals(BigInteger.valueOf(-21881L)));
        } else {
            value = value.longValue();
            expected = -21881L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[5].pco[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[5].pco[1] + "' != '" + -9942 + "'",
                    value.equals(BigInteger.valueOf(-9942L)));
        } else {
            value = value.longValue();
            expected = -9942L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[5].pco[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[5].pco[2] + "' != '" + -5689 + "'",
                    value.equals(BigInteger.valueOf(-5689L)));
        } else {
            value = value.longValue();
            expected = -5689L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[5].pcv[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[5].pcv[0] + "' != '" + 42 + "'",
                    value.equals(BigInteger.valueOf(42L)));
        } else {
            value = value.longValue();
            expected = 42L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[5].pcv[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[5].pcv[1] + "' != '" + -86 + "'",
                    value.equals(BigInteger.valueOf(-86L)));
        } else {
            value = value.longValue();
            expected = -86L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[5].pcv[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[5].pcv[2] + "' != '" + 78 + "'",
                    value.equals(BigInteger.valueOf(78L)));
        } else {
            value = value.longValue();
            expected = 78L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[5].pcv[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[5].pcv[3] + "' != '" + -50 + "'",
                    value.equals(BigInteger.valueOf(-50L)));
        } else {
            value = value.longValue();
            expected = -50L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[5].pcv[4];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[5].pcv[4] + "' != '" + 41 + "'",
                    value.equals(BigInteger.valueOf(41L)));
        } else {
            value = value.longValue();
            expected = 41L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[5].pcv[5];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[5].pcv[5] + "' != '" + 43 + "'",
                    value.equals(BigInteger.valueOf(43L)));
        } else {
            value = value.longValue();
            expected = 43L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[5].pcv[6];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[5].pcv[6] + "' != '" + 81 + "'",
                    value.equals(BigInteger.valueOf(81L)));
        } else {
            value = value.longValue();
            expected = 81L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[5].pcv[7];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[5].pcv[7] + "' != '" + -9 + "'",
                    value.equals(BigInteger.valueOf(-9L)));
        } else {
            value = value.longValue();
            expected = -9L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[5].pcv[8];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[5].pcv[8] + "' != '" + 99 + "'",
                    value.equals(BigInteger.valueOf(99L)));
        } else {
            value = value.longValue();
            expected = 99L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[5].pcv[9];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[5].pcv[9] + "' != '" + -58 + "'",
                    value.equals(BigInteger.valueOf(-58L)));
        } else {
            value = value.longValue();
            expected = -58L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[5].pcv[10];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[5].pcv[10] + "' != '" + -112 + "'",
                    value.equals(BigInteger.valueOf(-112L)));
        } else {
            value = value.longValue();
            expected = -112L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[5].pcv[11];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[5].pcv[11] + "' != '" + 2 + "'",
                    value.equals(BigInteger.valueOf(2L)));
        } else {
            value = value.longValue();
            expected = 2L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[5].pcv[12];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[5].pcv[12] + "' != '" + -124 + "'",
                    value.equals(BigInteger.valueOf(-124L)));
        } else {
            value = value.longValue();
            expected = -124L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[5].pcv[13];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[5].pcv[13] + "' != '" + 2 + "'",
                    value.equals(BigInteger.valueOf(2L)));
        } else {
            value = value.longValue();
            expected = 2L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[5].pcv[14];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[5].pcv[14] + "' != '" + -32 + "'",
                    value.equals(BigInteger.valueOf(-32L)));
        } else {
            value = value.longValue();
            expected = -32L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[5].pcv[15];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[5].pcv[15] + "' != '" + -36 + "'",
                    value.equals(BigInteger.valueOf(-36L)));
        } else {
            value = value.longValue();
            expected = -36L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[5].pcv[16];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[5].pcv[16] + "' != '" + -108 + "'",
                    value.equals(BigInteger.valueOf(-108L)));
        } else {
            value = value.longValue();
            expected = -108L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[5].pcv[17];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[5].pcv[17] + "' != '" + 58 + "'",
                    value.equals(BigInteger.valueOf(58L)));
        } else {
            value = value.longValue();
            expected = 58L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[5].pcv[18];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[5].pcv[18] + "' != '" + 85 + "'",
                    value.equals(BigInteger.valueOf(85L)));
        } else {
            value = value.longValue();
            expected = 85L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[5].pcv[19];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[5].pcv[19] + "' != '" + -118 + "'",
                    value.equals(BigInteger.valueOf(-118L)));
        } else {
            value = value.longValue();
            expected = -118L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[5].pcv[20];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[5].pcv[20] + "' != '" + -46 + "'",
                    value.equals(BigInteger.valueOf(-46L)));
        } else {
            value = value.longValue();
            expected = -46L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[5].sat_info;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[5].sat_info + "' != '" + 159 + "'",
                    value.equals(BigInteger.valueOf(159L)));
        } else {
            value = value.longValue();
            expected = 159L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[5].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[5].sid.code + "' != '" + 83 + "'",
                    value.equals(BigInteger.valueOf(83L)));
        } else {
            value = value.longValue();
            expected = 83L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[5].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[5].sid.sat + "' != '" + 45 + "'",
                    value.equals(BigInteger.valueOf(45L)));
        } else {
            value = value.longValue();
            expected = 45L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[5].svn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[5].svn + "' != '" + 64011 + "'",
                    value.equals(BigInteger.valueOf(64011L)));
        } else {
            value = value.longValue();
            expected = 64011L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[6].pco[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[6].pco[0] + "' != '" + -14290 + "'",
                    value.equals(BigInteger.valueOf(-14290L)));
        } else {
            value = value.longValue();
            expected = -14290L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[6].pco[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[6].pco[1] + "' != '" + 30340 + "'",
                    value.equals(BigInteger.valueOf(30340L)));
        } else {
            value = value.longValue();
            expected = 30340L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[6].pco[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[6].pco[2] + "' != '" + 3569 + "'",
                    value.equals(BigInteger.valueOf(3569L)));
        } else {
            value = value.longValue();
            expected = 3569L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[6].pcv[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[6].pcv[0] + "' != '" + 37 + "'",
                    value.equals(BigInteger.valueOf(37L)));
        } else {
            value = value.longValue();
            expected = 37L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[6].pcv[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[6].pcv[1] + "' != '" + 62 + "'",
                    value.equals(BigInteger.valueOf(62L)));
        } else {
            value = value.longValue();
            expected = 62L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[6].pcv[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[6].pcv[2] + "' != '" + 107 + "'",
                    value.equals(BigInteger.valueOf(107L)));
        } else {
            value = value.longValue();
            expected = 107L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[6].pcv[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[6].pcv[3] + "' != '" + -3 + "'",
                    value.equals(BigInteger.valueOf(-3L)));
        } else {
            value = value.longValue();
            expected = -3L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[6].pcv[4];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[6].pcv[4] + "' != '" + -66 + "'",
                    value.equals(BigInteger.valueOf(-66L)));
        } else {
            value = value.longValue();
            expected = -66L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[6].pcv[5];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[6].pcv[5] + "' != '" + -120 + "'",
                    value.equals(BigInteger.valueOf(-120L)));
        } else {
            value = value.longValue();
            expected = -120L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[6].pcv[6];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[6].pcv[6] + "' != '" + 66 + "'",
                    value.equals(BigInteger.valueOf(66L)));
        } else {
            value = value.longValue();
            expected = 66L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[6].pcv[7];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[6].pcv[7] + "' != '" + 9 + "'",
                    value.equals(BigInteger.valueOf(9L)));
        } else {
            value = value.longValue();
            expected = 9L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[6].pcv[8];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[6].pcv[8] + "' != '" + 84 + "'",
                    value.equals(BigInteger.valueOf(84L)));
        } else {
            value = value.longValue();
            expected = 84L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[6].pcv[9];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[6].pcv[9] + "' != '" + -101 + "'",
                    value.equals(BigInteger.valueOf(-101L)));
        } else {
            value = value.longValue();
            expected = -101L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[6].pcv[10];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[6].pcv[10] + "' != '" + 86 + "'",
                    value.equals(BigInteger.valueOf(86L)));
        } else {
            value = value.longValue();
            expected = 86L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[6].pcv[11];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[6].pcv[11] + "' != '" + -76 + "'",
                    value.equals(BigInteger.valueOf(-76L)));
        } else {
            value = value.longValue();
            expected = -76L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[6].pcv[12];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[6].pcv[12] + "' != '" + 41 + "'",
                    value.equals(BigInteger.valueOf(41L)));
        } else {
            value = value.longValue();
            expected = 41L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[6].pcv[13];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[6].pcv[13] + "' != '" + -60 + "'",
                    value.equals(BigInteger.valueOf(-60L)));
        } else {
            value = value.longValue();
            expected = -60L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[6].pcv[14];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[6].pcv[14] + "' != '" + 40 + "'",
                    value.equals(BigInteger.valueOf(40L)));
        } else {
            value = value.longValue();
            expected = 40L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[6].pcv[15];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[6].pcv[15] + "' != '" + 119 + "'",
                    value.equals(BigInteger.valueOf(119L)));
        } else {
            value = value.longValue();
            expected = 119L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[6].pcv[16];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[6].pcv[16] + "' != '" + 101 + "'",
                    value.equals(BigInteger.valueOf(101L)));
        } else {
            value = value.longValue();
            expected = 101L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[6].pcv[17];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[6].pcv[17] + "' != '" + -4 + "'",
                    value.equals(BigInteger.valueOf(-4L)));
        } else {
            value = value.longValue();
            expected = -4L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[6].pcv[18];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[6].pcv[18] + "' != '" + -33 + "'",
                    value.equals(BigInteger.valueOf(-33L)));
        } else {
            value = value.longValue();
            expected = -33L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[6].pcv[19];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[6].pcv[19] + "' != '" + -112 + "'",
                    value.equals(BigInteger.valueOf(-112L)));
        } else {
            value = value.longValue();
            expected = -112L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[6].pcv[20];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[6].pcv[20] + "' != '" + -103 + "'",
                    value.equals(BigInteger.valueOf(-103L)));
        } else {
            value = value.longValue();
            expected = -103L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[6].sat_info;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[6].sat_info + "' != '" + 7 + "'",
                    value.equals(BigInteger.valueOf(7L)));
        } else {
            value = value.longValue();
            expected = 7L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[6].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[6].sid.code + "' != '" + 158 + "'",
                    value.equals(BigInteger.valueOf(158L)));
        } else {
            value = value.longValue();
            expected = 158L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[6].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[6].sid.sat + "' != '" + 200 + "'",
                    value.equals(BigInteger.valueOf(200L)));
        } else {
            value = value.longValue();
            expected = 200L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[6].svn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.apc[6].svn + "' != '" + 17310 + "'",
                    value.equals(BigInteger.valueOf(17310L)));
        } else {
            value = value.longValue();
            expected = 17310L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
