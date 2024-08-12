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
// spec/tests/yaml/swiftnav/sbp/signing/test_MsgEcdsaCertificate.yaml by generate.py. Do not modify
// by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.signing.MsgEcdsaCertificate;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_signing_MsgEcdsaCertificateTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_signing_MsgEcdsaCertificateTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 48,
                    (byte) 10,
                    (byte) 11,
                    (byte) 12,
                    (byte) 13,
                    (byte) 2,
                    (byte) 180,
                    (byte) 160,
                    (byte) 116,
                    (byte) 77,
                    (byte) 243,
                    (byte) 28,
                    (byte) 173,
                    (byte) 36,
                    (byte) 86,
                    (byte) 33,
                    (byte) 8,
                    (byte) 31,
                    (byte) 120,
                    (byte) 73,
                    (byte) 64,
                    (byte) 169,
                    (byte) 148,
                    (byte) 224,
                    (byte) 57,
                    (byte) 95,
                    (byte) 17,
                    (byte) 40,
                    (byte) 213,
                    (byte) 92,
                    (byte) 195,
                    (byte) 146,
                    (byte) 235,
                    (byte) 228,
                    (byte) 177,
                    (byte) 101,
                    (byte) 82,
                    (byte) 182,
                    (byte) 25,
                    (byte) 172,
                    (byte) 170,
                    (byte) 250,
                    (byte) 236,
                    (byte) 7,
                    (byte) 119,
                    (byte) 4,
                    (byte) 201,
                    (byte) 10,
                    (byte) 14,
                    (byte) 208,
                    (byte) 47,
                    (byte) 126,
                    (byte) 49,
                    (byte) 210,
                    (byte) 174,
                    (byte) 75,
                    (byte) 221,
                    (byte) 203,
                    (byte) 24,
                    (byte) 66,
                    (byte) 52,
                    (byte) 35,
                    (byte) 26,
                    (byte) 30,
                    (byte) 140,
                    (byte) 111,
                    (byte) 246,
                    (byte) 39,
                    (byte) 226,
                    (byte) 205,
                    (byte) 198,
                    (byte) 178,
                    (byte) 196,
                    (byte) 5,
                    (byte) 81,
                    (byte) 9,
                    (byte) 44,
                    (byte) 164,
                    (byte) 163,
                    (byte) 214,
                    (byte) 138,
                    (byte) 123,
                    (byte) 76,
                    (byte) 74,
                    (byte) 237,
                    (byte) 121,
                    (byte) 13,
                    (byte) 137,
                    (byte) 186,
                    (byte) 97,
                    (byte) 193,
                    (byte) 189,
                    (byte) 200,
                    (byte) 124,
                    (byte) 69,
                    (byte) 115,
                    (byte) 230,
                    (byte) 159,
                    (byte) 185,
                    (byte) 158,
                    (byte) 51,
                    (byte) 12,
                    (byte) 225,
                    (byte) 65,
                    (byte) 192,
                    (byte) 105,
                    (byte) 56,
                    (byte) 41,
                    (byte) 85,
                    (byte) 133,
                    (byte) 19,
                    (byte) 217,
                    (byte) 166,
                    (byte) 48,
                    (byte) 139,
                    (byte) 131,
                    (byte) 96,
                    (byte) 216,
                    (byte) 98,
                    (byte) 147,
                    (byte) 132,
                    (byte) 234,
                    (byte) 167,
                    (byte) 248,
                    (byte) 247,
                    (byte) 32,
                    (byte) 239,
                    (byte) 194,
                    (byte) 188,
                    (byte) 254,
                    (byte) 114,
                    (byte) 117,
                    (byte) 83,
                    (byte) 25,
                    (byte) 251,
                    (byte) 191,
                    (byte) 104,
                    (byte) 240,
                    (byte) 118,
                    (byte) 68,
                    (byte) 42,
                    (byte) 93,
                    (byte) 18,
                    (byte) 16,
                    (byte) 37,
                    (byte) 232,
                    (byte) 99,
                    (byte) 179,
                    (byte) 23,
                    (byte) 90,
                    (byte) 94,
                    (byte) 136,
                    (byte) 6,
                    (byte) 125,
                    (byte) 91,
                    (byte) 255,
                    (byte) 15,
                    (byte) 71,
                    (byte) 43,
                    (byte) 46,
                    (byte) 25,
                    (byte) 252,
                    (byte) 229,
                    (byte) 80,
                    (byte) 143,
                    (byte) 58,
                    (byte) 241,
                    (byte) 11,
                    (byte) 62,
                    (byte) 181,
                    (byte) 155,
                    (byte) 53,
                    (byte) 153,
                    (byte) 149,
                    (byte) 152,
                    (byte) 227,
                    (byte) 150,
                    (byte) 87,
                    (byte) 112,
                    (byte) 165,
                    (byte) 2,
                    (byte) 128,
                    (byte) 231,
                    (byte) 25,
                    (byte) 157,
                    (byte) 244,
                    (byte) 204,
                    (byte) 108,
                    (byte) 253,
                    (byte) 127,
                    (byte) 122,
                    (byte) 145,
                    (byte) 113,
                    (byte) 162,
                    (byte) 197,
                    (byte) 171,
                    (byte) 199,
                    (byte) 54,
                    (byte) 184,
                    (byte) 222,
                    (byte) 206,
                    (byte) 67,
                    (byte) 144,
                    (byte) 78,
                    (byte) 187,
                    (byte) 207,
                    (byte) 60,
                    (byte) 211,
                    (byte) 141,
                    (byte) 135,
                    (byte) 106,
                    (byte) 220,
                    (byte) 79,
                    (byte) 183,
                    (byte) 245,
                    (byte) 21,
                    (byte) 161,
                    (byte) 168,
                    (byte) 34,
                    (byte) 129,
                    (byte) 50,
                    (byte) 176,
                    (byte) 1,
                    (byte) 218,
                    (byte) 20,
                    (byte) 130,
                    (byte) 59,
                    (byte) 249,
                    (byte) 109,
                    (byte) 219,
                    (byte) 0,
                    (byte) 100,
                    (byte) 103,
                    (byte) 55,
                    (byte) 29,
                    (byte) 242,
                    (byte) 110,
                    (byte) 154,
                    (byte) 190,
                    (byte) 233,
                    (byte) 142,
                    (byte) 45,
                    (byte) 61,
                    (byte) 215,
                    (byte) 202,
                    (byte) 238,
                    (byte) 88,
                    (byte) 209,
                    (byte) 70,
                    (byte) 63,
                    (byte) 151,
                    (byte) 27,
                    (byte) 102,
                };
        SBPMessage sbp = new SBPMessage(0x42, 0xC04, payload);
        MsgEcdsaCertificate msg = new MsgEcdsaCertificate(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.certificate_bytes[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[0] + "' != '" + 180 + "'",
                    value.equals(BigInteger.valueOf(180L)));
        } else {
            value = value.longValue();
            expected = 180L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[1] + "' != '" + 160 + "'",
                    value.equals(BigInteger.valueOf(160L)));
        } else {
            value = value.longValue();
            expected = 160L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[2] + "' != '" + 116 + "'",
                    value.equals(BigInteger.valueOf(116L)));
        } else {
            value = value.longValue();
            expected = 116L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[3] + "' != '" + 77 + "'",
                    value.equals(BigInteger.valueOf(77L)));
        } else {
            value = value.longValue();
            expected = 77L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[4];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[4] + "' != '" + 243 + "'",
                    value.equals(BigInteger.valueOf(243L)));
        } else {
            value = value.longValue();
            expected = 243L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[5];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[5] + "' != '" + 28 + "'",
                    value.equals(BigInteger.valueOf(28L)));
        } else {
            value = value.longValue();
            expected = 28L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[6];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[6] + "' != '" + 173 + "'",
                    value.equals(BigInteger.valueOf(173L)));
        } else {
            value = value.longValue();
            expected = 173L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[7];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[7] + "' != '" + 36 + "'",
                    value.equals(BigInteger.valueOf(36L)));
        } else {
            value = value.longValue();
            expected = 36L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[8];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[8] + "' != '" + 86 + "'",
                    value.equals(BigInteger.valueOf(86L)));
        } else {
            value = value.longValue();
            expected = 86L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[9];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[9] + "' != '" + 33 + "'",
                    value.equals(BigInteger.valueOf(33L)));
        } else {
            value = value.longValue();
            expected = 33L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[10];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[10] + "' != '" + 8 + "'",
                    value.equals(BigInteger.valueOf(8L)));
        } else {
            value = value.longValue();
            expected = 8L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[11];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[11] + "' != '" + 31 + "'",
                    value.equals(BigInteger.valueOf(31L)));
        } else {
            value = value.longValue();
            expected = 31L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[12];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[12] + "' != '" + 120 + "'",
                    value.equals(BigInteger.valueOf(120L)));
        } else {
            value = value.longValue();
            expected = 120L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[13];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[13] + "' != '" + 73 + "'",
                    value.equals(BigInteger.valueOf(73L)));
        } else {
            value = value.longValue();
            expected = 73L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[14];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[14] + "' != '" + 64 + "'",
                    value.equals(BigInteger.valueOf(64L)));
        } else {
            value = value.longValue();
            expected = 64L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[15];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[15] + "' != '" + 169 + "'",
                    value.equals(BigInteger.valueOf(169L)));
        } else {
            value = value.longValue();
            expected = 169L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[16];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[16] + "' != '" + 148 + "'",
                    value.equals(BigInteger.valueOf(148L)));
        } else {
            value = value.longValue();
            expected = 148L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[17];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[17] + "' != '" + 224 + "'",
                    value.equals(BigInteger.valueOf(224L)));
        } else {
            value = value.longValue();
            expected = 224L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[18];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[18] + "' != '" + 57 + "'",
                    value.equals(BigInteger.valueOf(57L)));
        } else {
            value = value.longValue();
            expected = 57L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[19];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[19] + "' != '" + 95 + "'",
                    value.equals(BigInteger.valueOf(95L)));
        } else {
            value = value.longValue();
            expected = 95L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[20];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[20] + "' != '" + 17 + "'",
                    value.equals(BigInteger.valueOf(17L)));
        } else {
            value = value.longValue();
            expected = 17L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[21];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[21] + "' != '" + 40 + "'",
                    value.equals(BigInteger.valueOf(40L)));
        } else {
            value = value.longValue();
            expected = 40L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[22];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[22] + "' != '" + 213 + "'",
                    value.equals(BigInteger.valueOf(213L)));
        } else {
            value = value.longValue();
            expected = 213L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[23];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[23] + "' != '" + 92 + "'",
                    value.equals(BigInteger.valueOf(92L)));
        } else {
            value = value.longValue();
            expected = 92L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[24];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[24] + "' != '" + 195 + "'",
                    value.equals(BigInteger.valueOf(195L)));
        } else {
            value = value.longValue();
            expected = 195L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[25];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[25] + "' != '" + 146 + "'",
                    value.equals(BigInteger.valueOf(146L)));
        } else {
            value = value.longValue();
            expected = 146L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[26];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[26] + "' != '" + 235 + "'",
                    value.equals(BigInteger.valueOf(235L)));
        } else {
            value = value.longValue();
            expected = 235L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[27];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[27] + "' != '" + 228 + "'",
                    value.equals(BigInteger.valueOf(228L)));
        } else {
            value = value.longValue();
            expected = 228L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[28];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[28] + "' != '" + 177 + "'",
                    value.equals(BigInteger.valueOf(177L)));
        } else {
            value = value.longValue();
            expected = 177L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[29];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[29] + "' != '" + 101 + "'",
                    value.equals(BigInteger.valueOf(101L)));
        } else {
            value = value.longValue();
            expected = 101L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[30];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[30] + "' != '" + 82 + "'",
                    value.equals(BigInteger.valueOf(82L)));
        } else {
            value = value.longValue();
            expected = 82L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[31];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[31] + "' != '" + 182 + "'",
                    value.equals(BigInteger.valueOf(182L)));
        } else {
            value = value.longValue();
            expected = 182L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[32];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[32] + "' != '" + 25 + "'",
                    value.equals(BigInteger.valueOf(25L)));
        } else {
            value = value.longValue();
            expected = 25L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[33];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[33] + "' != '" + 172 + "'",
                    value.equals(BigInteger.valueOf(172L)));
        } else {
            value = value.longValue();
            expected = 172L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[34];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[34] + "' != '" + 170 + "'",
                    value.equals(BigInteger.valueOf(170L)));
        } else {
            value = value.longValue();
            expected = 170L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[35];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[35] + "' != '" + 250 + "'",
                    value.equals(BigInteger.valueOf(250L)));
        } else {
            value = value.longValue();
            expected = 250L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[36];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[36] + "' != '" + 236 + "'",
                    value.equals(BigInteger.valueOf(236L)));
        } else {
            value = value.longValue();
            expected = 236L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[37];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[37] + "' != '" + 7 + "'",
                    value.equals(BigInteger.valueOf(7L)));
        } else {
            value = value.longValue();
            expected = 7L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[38];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[38] + "' != '" + 119 + "'",
                    value.equals(BigInteger.valueOf(119L)));
        } else {
            value = value.longValue();
            expected = 119L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[39];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[39] + "' != '" + 4 + "'",
                    value.equals(BigInteger.valueOf(4L)));
        } else {
            value = value.longValue();
            expected = 4L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[40];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[40] + "' != '" + 201 + "'",
                    value.equals(BigInteger.valueOf(201L)));
        } else {
            value = value.longValue();
            expected = 201L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[41];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[41] + "' != '" + 10 + "'",
                    value.equals(BigInteger.valueOf(10L)));
        } else {
            value = value.longValue();
            expected = 10L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[42];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[42] + "' != '" + 14 + "'",
                    value.equals(BigInteger.valueOf(14L)));
        } else {
            value = value.longValue();
            expected = 14L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[43];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[43] + "' != '" + 208 + "'",
                    value.equals(BigInteger.valueOf(208L)));
        } else {
            value = value.longValue();
            expected = 208L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[44];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[44] + "' != '" + 47 + "'",
                    value.equals(BigInteger.valueOf(47L)));
        } else {
            value = value.longValue();
            expected = 47L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[45];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[45] + "' != '" + 126 + "'",
                    value.equals(BigInteger.valueOf(126L)));
        } else {
            value = value.longValue();
            expected = 126L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[46];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[46] + "' != '" + 49 + "'",
                    value.equals(BigInteger.valueOf(49L)));
        } else {
            value = value.longValue();
            expected = 49L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[47];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[47] + "' != '" + 210 + "'",
                    value.equals(BigInteger.valueOf(210L)));
        } else {
            value = value.longValue();
            expected = 210L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[48];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[48] + "' != '" + 174 + "'",
                    value.equals(BigInteger.valueOf(174L)));
        } else {
            value = value.longValue();
            expected = 174L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[49];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[49] + "' != '" + 75 + "'",
                    value.equals(BigInteger.valueOf(75L)));
        } else {
            value = value.longValue();
            expected = 75L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[50];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[50] + "' != '" + 221 + "'",
                    value.equals(BigInteger.valueOf(221L)));
        } else {
            value = value.longValue();
            expected = 221L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[51];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[51] + "' != '" + 203 + "'",
                    value.equals(BigInteger.valueOf(203L)));
        } else {
            value = value.longValue();
            expected = 203L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[52];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[52] + "' != '" + 24 + "'",
                    value.equals(BigInteger.valueOf(24L)));
        } else {
            value = value.longValue();
            expected = 24L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[53];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[53] + "' != '" + 66 + "'",
                    value.equals(BigInteger.valueOf(66L)));
        } else {
            value = value.longValue();
            expected = 66L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[54];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[54] + "' != '" + 52 + "'",
                    value.equals(BigInteger.valueOf(52L)));
        } else {
            value = value.longValue();
            expected = 52L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[55];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[55] + "' != '" + 35 + "'",
                    value.equals(BigInteger.valueOf(35L)));
        } else {
            value = value.longValue();
            expected = 35L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[56];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[56] + "' != '" + 26 + "'",
                    value.equals(BigInteger.valueOf(26L)));
        } else {
            value = value.longValue();
            expected = 26L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[57];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[57] + "' != '" + 30 + "'",
                    value.equals(BigInteger.valueOf(30L)));
        } else {
            value = value.longValue();
            expected = 30L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[58];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[58] + "' != '" + 140 + "'",
                    value.equals(BigInteger.valueOf(140L)));
        } else {
            value = value.longValue();
            expected = 140L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[59];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[59] + "' != '" + 111 + "'",
                    value.equals(BigInteger.valueOf(111L)));
        } else {
            value = value.longValue();
            expected = 111L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[60];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[60] + "' != '" + 246 + "'",
                    value.equals(BigInteger.valueOf(246L)));
        } else {
            value = value.longValue();
            expected = 246L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[61];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[61] + "' != '" + 39 + "'",
                    value.equals(BigInteger.valueOf(39L)));
        } else {
            value = value.longValue();
            expected = 39L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[62];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[62] + "' != '" + 226 + "'",
                    value.equals(BigInteger.valueOf(226L)));
        } else {
            value = value.longValue();
            expected = 226L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[63];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[63] + "' != '" + 205 + "'",
                    value.equals(BigInteger.valueOf(205L)));
        } else {
            value = value.longValue();
            expected = 205L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[64];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[64] + "' != '" + 198 + "'",
                    value.equals(BigInteger.valueOf(198L)));
        } else {
            value = value.longValue();
            expected = 198L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[65];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[65] + "' != '" + 178 + "'",
                    value.equals(BigInteger.valueOf(178L)));
        } else {
            value = value.longValue();
            expected = 178L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[66];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[66] + "' != '" + 196 + "'",
                    value.equals(BigInteger.valueOf(196L)));
        } else {
            value = value.longValue();
            expected = 196L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[67];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[67] + "' != '" + 5 + "'",
                    value.equals(BigInteger.valueOf(5L)));
        } else {
            value = value.longValue();
            expected = 5L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[68];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[68] + "' != '" + 81 + "'",
                    value.equals(BigInteger.valueOf(81L)));
        } else {
            value = value.longValue();
            expected = 81L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[69];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[69] + "' != '" + 9 + "'",
                    value.equals(BigInteger.valueOf(9L)));
        } else {
            value = value.longValue();
            expected = 9L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[70];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[70] + "' != '" + 44 + "'",
                    value.equals(BigInteger.valueOf(44L)));
        } else {
            value = value.longValue();
            expected = 44L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[71];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[71] + "' != '" + 164 + "'",
                    value.equals(BigInteger.valueOf(164L)));
        } else {
            value = value.longValue();
            expected = 164L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[72];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[72] + "' != '" + 163 + "'",
                    value.equals(BigInteger.valueOf(163L)));
        } else {
            value = value.longValue();
            expected = 163L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[73];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[73] + "' != '" + 214 + "'",
                    value.equals(BigInteger.valueOf(214L)));
        } else {
            value = value.longValue();
            expected = 214L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[74];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[74] + "' != '" + 138 + "'",
                    value.equals(BigInteger.valueOf(138L)));
        } else {
            value = value.longValue();
            expected = 138L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[75];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[75] + "' != '" + 123 + "'",
                    value.equals(BigInteger.valueOf(123L)));
        } else {
            value = value.longValue();
            expected = 123L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[76];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[76] + "' != '" + 76 + "'",
                    value.equals(BigInteger.valueOf(76L)));
        } else {
            value = value.longValue();
            expected = 76L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[77];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[77] + "' != '" + 74 + "'",
                    value.equals(BigInteger.valueOf(74L)));
        } else {
            value = value.longValue();
            expected = 74L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[78];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[78] + "' != '" + 237 + "'",
                    value.equals(BigInteger.valueOf(237L)));
        } else {
            value = value.longValue();
            expected = 237L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[79];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[79] + "' != '" + 121 + "'",
                    value.equals(BigInteger.valueOf(121L)));
        } else {
            value = value.longValue();
            expected = 121L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[80];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[80] + "' != '" + 13 + "'",
                    value.equals(BigInteger.valueOf(13L)));
        } else {
            value = value.longValue();
            expected = 13L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[81];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[81] + "' != '" + 137 + "'",
                    value.equals(BigInteger.valueOf(137L)));
        } else {
            value = value.longValue();
            expected = 137L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[82];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[82] + "' != '" + 186 + "'",
                    value.equals(BigInteger.valueOf(186L)));
        } else {
            value = value.longValue();
            expected = 186L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[83];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[83] + "' != '" + 97 + "'",
                    value.equals(BigInteger.valueOf(97L)));
        } else {
            value = value.longValue();
            expected = 97L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[84];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[84] + "' != '" + 193 + "'",
                    value.equals(BigInteger.valueOf(193L)));
        } else {
            value = value.longValue();
            expected = 193L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[85];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[85] + "' != '" + 189 + "'",
                    value.equals(BigInteger.valueOf(189L)));
        } else {
            value = value.longValue();
            expected = 189L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[86];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[86] + "' != '" + 200 + "'",
                    value.equals(BigInteger.valueOf(200L)));
        } else {
            value = value.longValue();
            expected = 200L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[87];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[87] + "' != '" + 124 + "'",
                    value.equals(BigInteger.valueOf(124L)));
        } else {
            value = value.longValue();
            expected = 124L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[88];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[88] + "' != '" + 69 + "'",
                    value.equals(BigInteger.valueOf(69L)));
        } else {
            value = value.longValue();
            expected = 69L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[89];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[89] + "' != '" + 115 + "'",
                    value.equals(BigInteger.valueOf(115L)));
        } else {
            value = value.longValue();
            expected = 115L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[90];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[90] + "' != '" + 230 + "'",
                    value.equals(BigInteger.valueOf(230L)));
        } else {
            value = value.longValue();
            expected = 230L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[91];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[91] + "' != '" + 159 + "'",
                    value.equals(BigInteger.valueOf(159L)));
        } else {
            value = value.longValue();
            expected = 159L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[92];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[92] + "' != '" + 185 + "'",
                    value.equals(BigInteger.valueOf(185L)));
        } else {
            value = value.longValue();
            expected = 185L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[93];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[93] + "' != '" + 158 + "'",
                    value.equals(BigInteger.valueOf(158L)));
        } else {
            value = value.longValue();
            expected = 158L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[94];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[94] + "' != '" + 51 + "'",
                    value.equals(BigInteger.valueOf(51L)));
        } else {
            value = value.longValue();
            expected = 51L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[95];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[95] + "' != '" + 12 + "'",
                    value.equals(BigInteger.valueOf(12L)));
        } else {
            value = value.longValue();
            expected = 12L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[96];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[96] + "' != '" + 225 + "'",
                    value.equals(BigInteger.valueOf(225L)));
        } else {
            value = value.longValue();
            expected = 225L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[97];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[97] + "' != '" + 65 + "'",
                    value.equals(BigInteger.valueOf(65L)));
        } else {
            value = value.longValue();
            expected = 65L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[98];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[98] + "' != '" + 192 + "'",
                    value.equals(BigInteger.valueOf(192L)));
        } else {
            value = value.longValue();
            expected = 192L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[99];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[99] + "' != '" + 105 + "'",
                    value.equals(BigInteger.valueOf(105L)));
        } else {
            value = value.longValue();
            expected = 105L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[100];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[100] + "' != '" + 56 + "'",
                    value.equals(BigInteger.valueOf(56L)));
        } else {
            value = value.longValue();
            expected = 56L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[101];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[101] + "' != '" + 41 + "'",
                    value.equals(BigInteger.valueOf(41L)));
        } else {
            value = value.longValue();
            expected = 41L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[102];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[102] + "' != '" + 85 + "'",
                    value.equals(BigInteger.valueOf(85L)));
        } else {
            value = value.longValue();
            expected = 85L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[103];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[103] + "' != '" + 133 + "'",
                    value.equals(BigInteger.valueOf(133L)));
        } else {
            value = value.longValue();
            expected = 133L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[104];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[104] + "' != '" + 19 + "'",
                    value.equals(BigInteger.valueOf(19L)));
        } else {
            value = value.longValue();
            expected = 19L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[105];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[105] + "' != '" + 217 + "'",
                    value.equals(BigInteger.valueOf(217L)));
        } else {
            value = value.longValue();
            expected = 217L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[106];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[106] + "' != '" + 166 + "'",
                    value.equals(BigInteger.valueOf(166L)));
        } else {
            value = value.longValue();
            expected = 166L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[107];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[107] + "' != '" + 48 + "'",
                    value.equals(BigInteger.valueOf(48L)));
        } else {
            value = value.longValue();
            expected = 48L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[108];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[108] + "' != '" + 139 + "'",
                    value.equals(BigInteger.valueOf(139L)));
        } else {
            value = value.longValue();
            expected = 139L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[109];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[109] + "' != '" + 131 + "'",
                    value.equals(BigInteger.valueOf(131L)));
        } else {
            value = value.longValue();
            expected = 131L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[110];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[110] + "' != '" + 96 + "'",
                    value.equals(BigInteger.valueOf(96L)));
        } else {
            value = value.longValue();
            expected = 96L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[111];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[111] + "' != '" + 216 + "'",
                    value.equals(BigInteger.valueOf(216L)));
        } else {
            value = value.longValue();
            expected = 216L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[112];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[112] + "' != '" + 98 + "'",
                    value.equals(BigInteger.valueOf(98L)));
        } else {
            value = value.longValue();
            expected = 98L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[113];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[113] + "' != '" + 147 + "'",
                    value.equals(BigInteger.valueOf(147L)));
        } else {
            value = value.longValue();
            expected = 147L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[114];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[114] + "' != '" + 132 + "'",
                    value.equals(BigInteger.valueOf(132L)));
        } else {
            value = value.longValue();
            expected = 132L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[115];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[115] + "' != '" + 234 + "'",
                    value.equals(BigInteger.valueOf(234L)));
        } else {
            value = value.longValue();
            expected = 234L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[116];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[116] + "' != '" + 167 + "'",
                    value.equals(BigInteger.valueOf(167L)));
        } else {
            value = value.longValue();
            expected = 167L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[117];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[117] + "' != '" + 248 + "'",
                    value.equals(BigInteger.valueOf(248L)));
        } else {
            value = value.longValue();
            expected = 248L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[118];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[118] + "' != '" + 247 + "'",
                    value.equals(BigInteger.valueOf(247L)));
        } else {
            value = value.longValue();
            expected = 247L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[119];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[119] + "' != '" + 32 + "'",
                    value.equals(BigInteger.valueOf(32L)));
        } else {
            value = value.longValue();
            expected = 32L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[120];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[120] + "' != '" + 239 + "'",
                    value.equals(BigInteger.valueOf(239L)));
        } else {
            value = value.longValue();
            expected = 239L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[121];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[121] + "' != '" + 194 + "'",
                    value.equals(BigInteger.valueOf(194L)));
        } else {
            value = value.longValue();
            expected = 194L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[122];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[122] + "' != '" + 188 + "'",
                    value.equals(BigInteger.valueOf(188L)));
        } else {
            value = value.longValue();
            expected = 188L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[123];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[123] + "' != '" + 254 + "'",
                    value.equals(BigInteger.valueOf(254L)));
        } else {
            value = value.longValue();
            expected = 254L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[124];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[124] + "' != '" + 114 + "'",
                    value.equals(BigInteger.valueOf(114L)));
        } else {
            value = value.longValue();
            expected = 114L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[125];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[125] + "' != '" + 117 + "'",
                    value.equals(BigInteger.valueOf(117L)));
        } else {
            value = value.longValue();
            expected = 117L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[126];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[126] + "' != '" + 83 + "'",
                    value.equals(BigInteger.valueOf(83L)));
        } else {
            value = value.longValue();
            expected = 83L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[127];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[127] + "' != '" + 25 + "'",
                    value.equals(BigInteger.valueOf(25L)));
        } else {
            value = value.longValue();
            expected = 25L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[128];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[128] + "' != '" + 251 + "'",
                    value.equals(BigInteger.valueOf(251L)));
        } else {
            value = value.longValue();
            expected = 251L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[129];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[129] + "' != '" + 191 + "'",
                    value.equals(BigInteger.valueOf(191L)));
        } else {
            value = value.longValue();
            expected = 191L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[130];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[130] + "' != '" + 104 + "'",
                    value.equals(BigInteger.valueOf(104L)));
        } else {
            value = value.longValue();
            expected = 104L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[131];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[131] + "' != '" + 240 + "'",
                    value.equals(BigInteger.valueOf(240L)));
        } else {
            value = value.longValue();
            expected = 240L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[132];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[132] + "' != '" + 118 + "'",
                    value.equals(BigInteger.valueOf(118L)));
        } else {
            value = value.longValue();
            expected = 118L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[133];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[133] + "' != '" + 68 + "'",
                    value.equals(BigInteger.valueOf(68L)));
        } else {
            value = value.longValue();
            expected = 68L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[134];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[134] + "' != '" + 42 + "'",
                    value.equals(BigInteger.valueOf(42L)));
        } else {
            value = value.longValue();
            expected = 42L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[135];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[135] + "' != '" + 93 + "'",
                    value.equals(BigInteger.valueOf(93L)));
        } else {
            value = value.longValue();
            expected = 93L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[136];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[136] + "' != '" + 18 + "'",
                    value.equals(BigInteger.valueOf(18L)));
        } else {
            value = value.longValue();
            expected = 18L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[137];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[137] + "' != '" + 16 + "'",
                    value.equals(BigInteger.valueOf(16L)));
        } else {
            value = value.longValue();
            expected = 16L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[138];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[138] + "' != '" + 37 + "'",
                    value.equals(BigInteger.valueOf(37L)));
        } else {
            value = value.longValue();
            expected = 37L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[139];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[139] + "' != '" + 232 + "'",
                    value.equals(BigInteger.valueOf(232L)));
        } else {
            value = value.longValue();
            expected = 232L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[140];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[140] + "' != '" + 99 + "'",
                    value.equals(BigInteger.valueOf(99L)));
        } else {
            value = value.longValue();
            expected = 99L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[141];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[141] + "' != '" + 179 + "'",
                    value.equals(BigInteger.valueOf(179L)));
        } else {
            value = value.longValue();
            expected = 179L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[142];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[142] + "' != '" + 23 + "'",
                    value.equals(BigInteger.valueOf(23L)));
        } else {
            value = value.longValue();
            expected = 23L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[143];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[143] + "' != '" + 90 + "'",
                    value.equals(BigInteger.valueOf(90L)));
        } else {
            value = value.longValue();
            expected = 90L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[144];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[144] + "' != '" + 94 + "'",
                    value.equals(BigInteger.valueOf(94L)));
        } else {
            value = value.longValue();
            expected = 94L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[145];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[145] + "' != '" + 136 + "'",
                    value.equals(BigInteger.valueOf(136L)));
        } else {
            value = value.longValue();
            expected = 136L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[146];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[146] + "' != '" + 6 + "'",
                    value.equals(BigInteger.valueOf(6L)));
        } else {
            value = value.longValue();
            expected = 6L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[147];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[147] + "' != '" + 125 + "'",
                    value.equals(BigInteger.valueOf(125L)));
        } else {
            value = value.longValue();
            expected = 125L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[148];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[148] + "' != '" + 91 + "'",
                    value.equals(BigInteger.valueOf(91L)));
        } else {
            value = value.longValue();
            expected = 91L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[149];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[149] + "' != '" + 255 + "'",
                    value.equals(BigInteger.valueOf(255L)));
        } else {
            value = value.longValue();
            expected = 255L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[150];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[150] + "' != '" + 15 + "'",
                    value.equals(BigInteger.valueOf(15L)));
        } else {
            value = value.longValue();
            expected = 15L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[151];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[151] + "' != '" + 71 + "'",
                    value.equals(BigInteger.valueOf(71L)));
        } else {
            value = value.longValue();
            expected = 71L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[152];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[152] + "' != '" + 43 + "'",
                    value.equals(BigInteger.valueOf(43L)));
        } else {
            value = value.longValue();
            expected = 43L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[153];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[153] + "' != '" + 46 + "'",
                    value.equals(BigInteger.valueOf(46L)));
        } else {
            value = value.longValue();
            expected = 46L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[154];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[154] + "' != '" + 25 + "'",
                    value.equals(BigInteger.valueOf(25L)));
        } else {
            value = value.longValue();
            expected = 25L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[155];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[155] + "' != '" + 252 + "'",
                    value.equals(BigInteger.valueOf(252L)));
        } else {
            value = value.longValue();
            expected = 252L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[156];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[156] + "' != '" + 229 + "'",
                    value.equals(BigInteger.valueOf(229L)));
        } else {
            value = value.longValue();
            expected = 229L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[157];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[157] + "' != '" + 80 + "'",
                    value.equals(BigInteger.valueOf(80L)));
        } else {
            value = value.longValue();
            expected = 80L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[158];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[158] + "' != '" + 143 + "'",
                    value.equals(BigInteger.valueOf(143L)));
        } else {
            value = value.longValue();
            expected = 143L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[159];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[159] + "' != '" + 58 + "'",
                    value.equals(BigInteger.valueOf(58L)));
        } else {
            value = value.longValue();
            expected = 58L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[160];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[160] + "' != '" + 241 + "'",
                    value.equals(BigInteger.valueOf(241L)));
        } else {
            value = value.longValue();
            expected = 241L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[161];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[161] + "' != '" + 11 + "'",
                    value.equals(BigInteger.valueOf(11L)));
        } else {
            value = value.longValue();
            expected = 11L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[162];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[162] + "' != '" + 62 + "'",
                    value.equals(BigInteger.valueOf(62L)));
        } else {
            value = value.longValue();
            expected = 62L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[163];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[163] + "' != '" + 181 + "'",
                    value.equals(BigInteger.valueOf(181L)));
        } else {
            value = value.longValue();
            expected = 181L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[164];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[164] + "' != '" + 155 + "'",
                    value.equals(BigInteger.valueOf(155L)));
        } else {
            value = value.longValue();
            expected = 155L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[165];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[165] + "' != '" + 53 + "'",
                    value.equals(BigInteger.valueOf(53L)));
        } else {
            value = value.longValue();
            expected = 53L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[166];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[166] + "' != '" + 153 + "'",
                    value.equals(BigInteger.valueOf(153L)));
        } else {
            value = value.longValue();
            expected = 153L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[167];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[167] + "' != '" + 149 + "'",
                    value.equals(BigInteger.valueOf(149L)));
        } else {
            value = value.longValue();
            expected = 149L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[168];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[168] + "' != '" + 152 + "'",
                    value.equals(BigInteger.valueOf(152L)));
        } else {
            value = value.longValue();
            expected = 152L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[169];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[169] + "' != '" + 227 + "'",
                    value.equals(BigInteger.valueOf(227L)));
        } else {
            value = value.longValue();
            expected = 227L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[170];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[170] + "' != '" + 150 + "'",
                    value.equals(BigInteger.valueOf(150L)));
        } else {
            value = value.longValue();
            expected = 150L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[171];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[171] + "' != '" + 87 + "'",
                    value.equals(BigInteger.valueOf(87L)));
        } else {
            value = value.longValue();
            expected = 87L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[172];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[172] + "' != '" + 112 + "'",
                    value.equals(BigInteger.valueOf(112L)));
        } else {
            value = value.longValue();
            expected = 112L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[173];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[173] + "' != '" + 165 + "'",
                    value.equals(BigInteger.valueOf(165L)));
        } else {
            value = value.longValue();
            expected = 165L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[174];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[174] + "' != '" + 2 + "'",
                    value.equals(BigInteger.valueOf(2L)));
        } else {
            value = value.longValue();
            expected = 2L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[175];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[175] + "' != '" + 128 + "'",
                    value.equals(BigInteger.valueOf(128L)));
        } else {
            value = value.longValue();
            expected = 128L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[176];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[176] + "' != '" + 231 + "'",
                    value.equals(BigInteger.valueOf(231L)));
        } else {
            value = value.longValue();
            expected = 231L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[177];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[177] + "' != '" + 25 + "'",
                    value.equals(BigInteger.valueOf(25L)));
        } else {
            value = value.longValue();
            expected = 25L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[178];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[178] + "' != '" + 157 + "'",
                    value.equals(BigInteger.valueOf(157L)));
        } else {
            value = value.longValue();
            expected = 157L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[179];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[179] + "' != '" + 244 + "'",
                    value.equals(BigInteger.valueOf(244L)));
        } else {
            value = value.longValue();
            expected = 244L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[180];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[180] + "' != '" + 204 + "'",
                    value.equals(BigInteger.valueOf(204L)));
        } else {
            value = value.longValue();
            expected = 204L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[181];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[181] + "' != '" + 108 + "'",
                    value.equals(BigInteger.valueOf(108L)));
        } else {
            value = value.longValue();
            expected = 108L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[182];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[182] + "' != '" + 253 + "'",
                    value.equals(BigInteger.valueOf(253L)));
        } else {
            value = value.longValue();
            expected = 253L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[183];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[183] + "' != '" + 127 + "'",
                    value.equals(BigInteger.valueOf(127L)));
        } else {
            value = value.longValue();
            expected = 127L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[184];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[184] + "' != '" + 122 + "'",
                    value.equals(BigInteger.valueOf(122L)));
        } else {
            value = value.longValue();
            expected = 122L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[185];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[185] + "' != '" + 145 + "'",
                    value.equals(BigInteger.valueOf(145L)));
        } else {
            value = value.longValue();
            expected = 145L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[186];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[186] + "' != '" + 113 + "'",
                    value.equals(BigInteger.valueOf(113L)));
        } else {
            value = value.longValue();
            expected = 113L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[187];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[187] + "' != '" + 162 + "'",
                    value.equals(BigInteger.valueOf(162L)));
        } else {
            value = value.longValue();
            expected = 162L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[188];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[188] + "' != '" + 197 + "'",
                    value.equals(BigInteger.valueOf(197L)));
        } else {
            value = value.longValue();
            expected = 197L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[189];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[189] + "' != '" + 171 + "'",
                    value.equals(BigInteger.valueOf(171L)));
        } else {
            value = value.longValue();
            expected = 171L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[190];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[190] + "' != '" + 199 + "'",
                    value.equals(BigInteger.valueOf(199L)));
        } else {
            value = value.longValue();
            expected = 199L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[191];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[191] + "' != '" + 54 + "'",
                    value.equals(BigInteger.valueOf(54L)));
        } else {
            value = value.longValue();
            expected = 54L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[192];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[192] + "' != '" + 184 + "'",
                    value.equals(BigInteger.valueOf(184L)));
        } else {
            value = value.longValue();
            expected = 184L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[193];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[193] + "' != '" + 222 + "'",
                    value.equals(BigInteger.valueOf(222L)));
        } else {
            value = value.longValue();
            expected = 222L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[194];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[194] + "' != '" + 206 + "'",
                    value.equals(BigInteger.valueOf(206L)));
        } else {
            value = value.longValue();
            expected = 206L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[195];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[195] + "' != '" + 67 + "'",
                    value.equals(BigInteger.valueOf(67L)));
        } else {
            value = value.longValue();
            expected = 67L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[196];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[196] + "' != '" + 144 + "'",
                    value.equals(BigInteger.valueOf(144L)));
        } else {
            value = value.longValue();
            expected = 144L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[197];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[197] + "' != '" + 78 + "'",
                    value.equals(BigInteger.valueOf(78L)));
        } else {
            value = value.longValue();
            expected = 78L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[198];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[198] + "' != '" + 187 + "'",
                    value.equals(BigInteger.valueOf(187L)));
        } else {
            value = value.longValue();
            expected = 187L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[199];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[199] + "' != '" + 207 + "'",
                    value.equals(BigInteger.valueOf(207L)));
        } else {
            value = value.longValue();
            expected = 207L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[200];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[200] + "' != '" + 60 + "'",
                    value.equals(BigInteger.valueOf(60L)));
        } else {
            value = value.longValue();
            expected = 60L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[201];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[201] + "' != '" + 211 + "'",
                    value.equals(BigInteger.valueOf(211L)));
        } else {
            value = value.longValue();
            expected = 211L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[202];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[202] + "' != '" + 141 + "'",
                    value.equals(BigInteger.valueOf(141L)));
        } else {
            value = value.longValue();
            expected = 141L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[203];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[203] + "' != '" + 135 + "'",
                    value.equals(BigInteger.valueOf(135L)));
        } else {
            value = value.longValue();
            expected = 135L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[204];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[204] + "' != '" + 106 + "'",
                    value.equals(BigInteger.valueOf(106L)));
        } else {
            value = value.longValue();
            expected = 106L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[205];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[205] + "' != '" + 220 + "'",
                    value.equals(BigInteger.valueOf(220L)));
        } else {
            value = value.longValue();
            expected = 220L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[206];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[206] + "' != '" + 79 + "'",
                    value.equals(BigInteger.valueOf(79L)));
        } else {
            value = value.longValue();
            expected = 79L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[207];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[207] + "' != '" + 183 + "'",
                    value.equals(BigInteger.valueOf(183L)));
        } else {
            value = value.longValue();
            expected = 183L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[208];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[208] + "' != '" + 245 + "'",
                    value.equals(BigInteger.valueOf(245L)));
        } else {
            value = value.longValue();
            expected = 245L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[209];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[209] + "' != '" + 21 + "'",
                    value.equals(BigInteger.valueOf(21L)));
        } else {
            value = value.longValue();
            expected = 21L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[210];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[210] + "' != '" + 161 + "'",
                    value.equals(BigInteger.valueOf(161L)));
        } else {
            value = value.longValue();
            expected = 161L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[211];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[211] + "' != '" + 168 + "'",
                    value.equals(BigInteger.valueOf(168L)));
        } else {
            value = value.longValue();
            expected = 168L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[212];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[212] + "' != '" + 34 + "'",
                    value.equals(BigInteger.valueOf(34L)));
        } else {
            value = value.longValue();
            expected = 34L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[213];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[213] + "' != '" + 129 + "'",
                    value.equals(BigInteger.valueOf(129L)));
        } else {
            value = value.longValue();
            expected = 129L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[214];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[214] + "' != '" + 50 + "'",
                    value.equals(BigInteger.valueOf(50L)));
        } else {
            value = value.longValue();
            expected = 50L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[215];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[215] + "' != '" + 176 + "'",
                    value.equals(BigInteger.valueOf(176L)));
        } else {
            value = value.longValue();
            expected = 176L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[216];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[216] + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[217];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[217] + "' != '" + 218 + "'",
                    value.equals(BigInteger.valueOf(218L)));
        } else {
            value = value.longValue();
            expected = 218L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[218];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[218] + "' != '" + 20 + "'",
                    value.equals(BigInteger.valueOf(20L)));
        } else {
            value = value.longValue();
            expected = 20L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[219];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[219] + "' != '" + 130 + "'",
                    value.equals(BigInteger.valueOf(130L)));
        } else {
            value = value.longValue();
            expected = 130L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[220];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[220] + "' != '" + 59 + "'",
                    value.equals(BigInteger.valueOf(59L)));
        } else {
            value = value.longValue();
            expected = 59L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[221];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[221] + "' != '" + 249 + "'",
                    value.equals(BigInteger.valueOf(249L)));
        } else {
            value = value.longValue();
            expected = 249L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[222];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[222] + "' != '" + 109 + "'",
                    value.equals(BigInteger.valueOf(109L)));
        } else {
            value = value.longValue();
            expected = 109L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[223];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[223] + "' != '" + 219 + "'",
                    value.equals(BigInteger.valueOf(219L)));
        } else {
            value = value.longValue();
            expected = 219L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[224];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[224] + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[225];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[225] + "' != '" + 100 + "'",
                    value.equals(BigInteger.valueOf(100L)));
        } else {
            value = value.longValue();
            expected = 100L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[226];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[226] + "' != '" + 103 + "'",
                    value.equals(BigInteger.valueOf(103L)));
        } else {
            value = value.longValue();
            expected = 103L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[227];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[227] + "' != '" + 55 + "'",
                    value.equals(BigInteger.valueOf(55L)));
        } else {
            value = value.longValue();
            expected = 55L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[228];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[228] + "' != '" + 29 + "'",
                    value.equals(BigInteger.valueOf(29L)));
        } else {
            value = value.longValue();
            expected = 29L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[229];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[229] + "' != '" + 242 + "'",
                    value.equals(BigInteger.valueOf(242L)));
        } else {
            value = value.longValue();
            expected = 242L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[230];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[230] + "' != '" + 110 + "'",
                    value.equals(BigInteger.valueOf(110L)));
        } else {
            value = value.longValue();
            expected = 110L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[231];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[231] + "' != '" + 154 + "'",
                    value.equals(BigInteger.valueOf(154L)));
        } else {
            value = value.longValue();
            expected = 154L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[232];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[232] + "' != '" + 190 + "'",
                    value.equals(BigInteger.valueOf(190L)));
        } else {
            value = value.longValue();
            expected = 190L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[233];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[233] + "' != '" + 233 + "'",
                    value.equals(BigInteger.valueOf(233L)));
        } else {
            value = value.longValue();
            expected = 233L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[234];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[234] + "' != '" + 142 + "'",
                    value.equals(BigInteger.valueOf(142L)));
        } else {
            value = value.longValue();
            expected = 142L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[235];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[235] + "' != '" + 45 + "'",
                    value.equals(BigInteger.valueOf(45L)));
        } else {
            value = value.longValue();
            expected = 45L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[236];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[236] + "' != '" + 61 + "'",
                    value.equals(BigInteger.valueOf(61L)));
        } else {
            value = value.longValue();
            expected = 61L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[237];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[237] + "' != '" + 215 + "'",
                    value.equals(BigInteger.valueOf(215L)));
        } else {
            value = value.longValue();
            expected = 215L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[238];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[238] + "' != '" + 202 + "'",
                    value.equals(BigInteger.valueOf(202L)));
        } else {
            value = value.longValue();
            expected = 202L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[239];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[239] + "' != '" + 238 + "'",
                    value.equals(BigInteger.valueOf(238L)));
        } else {
            value = value.longValue();
            expected = 238L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[240];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[240] + "' != '" + 88 + "'",
                    value.equals(BigInteger.valueOf(88L)));
        } else {
            value = value.longValue();
            expected = 88L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[241];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[241] + "' != '" + 209 + "'",
                    value.equals(BigInteger.valueOf(209L)));
        } else {
            value = value.longValue();
            expected = 209L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[242];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[242] + "' != '" + 70 + "'",
                    value.equals(BigInteger.valueOf(70L)));
        } else {
            value = value.longValue();
            expected = 70L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[243];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[243] + "' != '" + 63 + "'",
                    value.equals(BigInteger.valueOf(63L)));
        } else {
            value = value.longValue();
            expected = 63L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[244];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[244] + "' != '" + 151 + "'",
                    value.equals(BigInteger.valueOf(151L)));
        } else {
            value = value.longValue();
            expected = 151L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[245];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[245] + "' != '" + 27 + "'",
                    value.equals(BigInteger.valueOf(27L)));
        } else {
            value = value.longValue();
            expected = 27L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_bytes[246];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_bytes[246] + "' != '" + 102 + "'",
                    value.equals(BigInteger.valueOf(102L)));
        } else {
            value = value.longValue();
            expected = 102L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_id[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_id[0] + "' != '" + 10 + "'",
                    value.equals(BigInteger.valueOf(10L)));
        } else {
            value = value.longValue();
            expected = 10L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_id[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_id[1] + "' != '" + 11 + "'",
                    value.equals(BigInteger.valueOf(11L)));
        } else {
            value = value.longValue();
            expected = 11L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_id[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_id[2] + "' != '" + 12 + "'",
                    value.equals(BigInteger.valueOf(12L)));
        } else {
            value = value.longValue();
            expected = 12L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.certificate_id[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.certificate_id[3] + "' != '" + 13 + "'",
                    value.equals(BigInteger.valueOf(13L)));
        } else {
            value = value.longValue();
            expected = 13L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.flags + "' != '" + 2 + "'", value.equals(BigInteger.valueOf(2L)));
        } else {
            value = value.longValue();
            expected = 2L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.n_msg;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.n_msg + "' != '" + 48 + "'", value.equals(BigInteger.valueOf(48L)));
        } else {
            value = value.longValue();
            expected = 48L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
