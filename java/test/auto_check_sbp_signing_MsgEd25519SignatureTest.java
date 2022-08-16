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
// spec/tests/yaml/swiftnav/sbp/signing/test_MsgEd25519Signature.yaml by generate.py. Do not modify
// by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.signing.MsgEd25519Signature;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_signing_MsgEd25519SignatureTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_signing_MsgEd25519SignatureTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 0,
                    (byte) 1,
                    (byte) 2,
                    (byte) 3,
                    (byte) 4,
                    (byte) 5,
                    (byte) 6,
                    (byte) 7,
                    (byte) 8,
                    (byte) 9,
                    (byte) 10,
                    (byte) 11,
                    (byte) 12,
                    (byte) 13,
                    (byte) 14,
                    (byte) 15,
                    (byte) 16,
                    (byte) 17,
                    (byte) 18,
                    (byte) 19,
                    (byte) 20,
                    (byte) 21,
                    (byte) 22,
                    (byte) 23,
                    (byte) 24,
                    (byte) 25,
                    (byte) 26,
                    (byte) 27,
                    (byte) 28,
                    (byte) 29,
                    (byte) 30,
                    (byte) 31,
                    (byte) 32,
                    (byte) 33,
                    (byte) 34,
                    (byte) 35,
                    (byte) 36,
                    (byte) 37,
                    (byte) 38,
                    (byte) 39,
                    (byte) 40,
                    (byte) 41,
                    (byte) 42,
                    (byte) 43,
                    (byte) 44,
                    (byte) 45,
                    (byte) 46,
                    (byte) 47,
                    (byte) 48,
                    (byte) 49,
                    (byte) 50,
                    (byte) 51,
                    (byte) 52,
                    (byte) 53,
                    (byte) 54,
                    (byte) 55,
                    (byte) 56,
                    (byte) 57,
                    (byte) 58,
                    (byte) 59,
                    (byte) 60,
                    (byte) 61,
                    (byte) 62,
                    (byte) 63,
                    (byte) 100,
                    (byte) 101,
                    (byte) 102,
                    (byte) 103,
                    (byte) 104,
                    (byte) 105,
                    (byte) 106,
                    (byte) 107,
                    (byte) 108,
                    (byte) 109,
                    (byte) 110,
                    (byte) 111,
                    (byte) 112,
                    (byte) 113,
                    (byte) 114,
                    (byte) 115,
                    (byte) 116,
                    (byte) 117,
                    (byte) 118,
                    (byte) 119,
                    (byte) 136,
                    (byte) 19,
                    (byte) 0,
                    (byte) 0,
                    (byte) 114,
                    (byte) 20,
                    (byte) 0,
                    (byte) 0,
                    (byte) 92,
                    (byte) 21,
                    (byte) 0,
                    (byte) 0,
                    (byte) 70,
                    (byte) 22,
                    (byte) 0,
                    (byte) 0,
                    (byte) 48,
                    (byte) 23,
                    (byte) 0,
                    (byte) 0,
                    (byte) 26,
                    (byte) 24,
                    (byte) 0,
                    (byte) 0,
                    (byte) 4,
                    (byte) 25,
                    (byte) 0,
                    (byte) 0,
                    (byte) 238,
                    (byte) 25,
                    (byte) 0,
                    (byte) 0,
                    (byte) 216,
                    (byte) 26,
                    (byte) 0,
                    (byte) 0,
                    (byte) 194,
                    (byte) 27,
                    (byte) 0,
                    (byte) 0,
                    (byte) 172,
                    (byte) 28,
                    (byte) 0,
                    (byte) 0,
                    (byte) 150,
                    (byte) 29,
                    (byte) 0,
                    (byte) 0,
                    (byte) 128,
                    (byte) 30,
                    (byte) 0,
                    (byte) 0,
                    (byte) 106,
                    (byte) 31,
                    (byte) 0,
                    (byte) 0,
                    (byte) 84,
                    (byte) 32,
                    (byte) 0,
                    (byte) 0,
                    (byte) 62,
                    (byte) 33,
                    (byte) 0,
                    (byte) 0,
                    (byte) 40,
                    (byte) 34,
                    (byte) 0,
                    (byte) 0,
                    (byte) 18,
                    (byte) 35,
                    (byte) 0,
                    (byte) 0,
                    (byte) 252,
                    (byte) 35,
                    (byte) 0,
                    (byte) 0,
                    (byte) 230,
                    (byte) 36,
                    (byte) 0,
                    (byte) 0,
                    (byte) 208,
                    (byte) 37,
                    (byte) 0,
                    (byte) 0,
                    (byte) 186,
                    (byte) 38,
                    (byte) 0,
                    (byte) 0,
                    (byte) 164,
                    (byte) 39,
                    (byte) 0,
                    (byte) 0,
                    (byte) 142,
                    (byte) 40,
                    (byte) 0,
                    (byte) 0,
                    (byte) 120,
                    (byte) 41,
                    (byte) 0,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x2694, 0xC01, payload);
        MsgEd25519Signature msg = new MsgEd25519Signature(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.fingerprint[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.fingerprint[0] + "' != '" + 100 + "'",
                    value.equals(BigInteger.valueOf(100L)));
        } else {
            value = value.longValue();
            expected = 100L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.fingerprint[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.fingerprint[1] + "' != '" + 101 + "'",
                    value.equals(BigInteger.valueOf(101L)));
        } else {
            value = value.longValue();
            expected = 101L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.fingerprint[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.fingerprint[2] + "' != '" + 102 + "'",
                    value.equals(BigInteger.valueOf(102L)));
        } else {
            value = value.longValue();
            expected = 102L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.fingerprint[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.fingerprint[3] + "' != '" + 103 + "'",
                    value.equals(BigInteger.valueOf(103L)));
        } else {
            value = value.longValue();
            expected = 103L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.fingerprint[4];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.fingerprint[4] + "' != '" + 104 + "'",
                    value.equals(BigInteger.valueOf(104L)));
        } else {
            value = value.longValue();
            expected = 104L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.fingerprint[5];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.fingerprint[5] + "' != '" + 105 + "'",
                    value.equals(BigInteger.valueOf(105L)));
        } else {
            value = value.longValue();
            expected = 105L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.fingerprint[6];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.fingerprint[6] + "' != '" + 106 + "'",
                    value.equals(BigInteger.valueOf(106L)));
        } else {
            value = value.longValue();
            expected = 106L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.fingerprint[7];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.fingerprint[7] + "' != '" + 107 + "'",
                    value.equals(BigInteger.valueOf(107L)));
        } else {
            value = value.longValue();
            expected = 107L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.fingerprint[8];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.fingerprint[8] + "' != '" + 108 + "'",
                    value.equals(BigInteger.valueOf(108L)));
        } else {
            value = value.longValue();
            expected = 108L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.fingerprint[9];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.fingerprint[9] + "' != '" + 109 + "'",
                    value.equals(BigInteger.valueOf(109L)));
        } else {
            value = value.longValue();
            expected = 109L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.fingerprint[10];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.fingerprint[10] + "' != '" + 110 + "'",
                    value.equals(BigInteger.valueOf(110L)));
        } else {
            value = value.longValue();
            expected = 110L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.fingerprint[11];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.fingerprint[11] + "' != '" + 111 + "'",
                    value.equals(BigInteger.valueOf(111L)));
        } else {
            value = value.longValue();
            expected = 111L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.fingerprint[12];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.fingerprint[12] + "' != '" + 112 + "'",
                    value.equals(BigInteger.valueOf(112L)));
        } else {
            value = value.longValue();
            expected = 112L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.fingerprint[13];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.fingerprint[13] + "' != '" + 113 + "'",
                    value.equals(BigInteger.valueOf(113L)));
        } else {
            value = value.longValue();
            expected = 113L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.fingerprint[14];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.fingerprint[14] + "' != '" + 114 + "'",
                    value.equals(BigInteger.valueOf(114L)));
        } else {
            value = value.longValue();
            expected = 114L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.fingerprint[15];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.fingerprint[15] + "' != '" + 115 + "'",
                    value.equals(BigInteger.valueOf(115L)));
        } else {
            value = value.longValue();
            expected = 115L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.fingerprint[16];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.fingerprint[16] + "' != '" + 116 + "'",
                    value.equals(BigInteger.valueOf(116L)));
        } else {
            value = value.longValue();
            expected = 116L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.fingerprint[17];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.fingerprint[17] + "' != '" + 117 + "'",
                    value.equals(BigInteger.valueOf(117L)));
        } else {
            value = value.longValue();
            expected = 117L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.fingerprint[18];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.fingerprint[18] + "' != '" + 118 + "'",
                    value.equals(BigInteger.valueOf(118L)));
        } else {
            value = value.longValue();
            expected = 118L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.fingerprint[19];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.fingerprint[19] + "' != '" + 119 + "'",
                    value.equals(BigInteger.valueOf(119L)));
        } else {
            value = value.longValue();
            expected = 119L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[0] + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[1] + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[2] + "' != '" + 2 + "'",
                    value.equals(BigInteger.valueOf(2L)));
        } else {
            value = value.longValue();
            expected = 2L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[3] + "' != '" + 3 + "'",
                    value.equals(BigInteger.valueOf(3L)));
        } else {
            value = value.longValue();
            expected = 3L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[4];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[4] + "' != '" + 4 + "'",
                    value.equals(BigInteger.valueOf(4L)));
        } else {
            value = value.longValue();
            expected = 4L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[5];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[5] + "' != '" + 5 + "'",
                    value.equals(BigInteger.valueOf(5L)));
        } else {
            value = value.longValue();
            expected = 5L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[6];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[6] + "' != '" + 6 + "'",
                    value.equals(BigInteger.valueOf(6L)));
        } else {
            value = value.longValue();
            expected = 6L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[7];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[7] + "' != '" + 7 + "'",
                    value.equals(BigInteger.valueOf(7L)));
        } else {
            value = value.longValue();
            expected = 7L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[8];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[8] + "' != '" + 8 + "'",
                    value.equals(BigInteger.valueOf(8L)));
        } else {
            value = value.longValue();
            expected = 8L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[9];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[9] + "' != '" + 9 + "'",
                    value.equals(BigInteger.valueOf(9L)));
        } else {
            value = value.longValue();
            expected = 9L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[10];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[10] + "' != '" + 10 + "'",
                    value.equals(BigInteger.valueOf(10L)));
        } else {
            value = value.longValue();
            expected = 10L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[11];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[11] + "' != '" + 11 + "'",
                    value.equals(BigInteger.valueOf(11L)));
        } else {
            value = value.longValue();
            expected = 11L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[12];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[12] + "' != '" + 12 + "'",
                    value.equals(BigInteger.valueOf(12L)));
        } else {
            value = value.longValue();
            expected = 12L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[13];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[13] + "' != '" + 13 + "'",
                    value.equals(BigInteger.valueOf(13L)));
        } else {
            value = value.longValue();
            expected = 13L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[14];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[14] + "' != '" + 14 + "'",
                    value.equals(BigInteger.valueOf(14L)));
        } else {
            value = value.longValue();
            expected = 14L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[15];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[15] + "' != '" + 15 + "'",
                    value.equals(BigInteger.valueOf(15L)));
        } else {
            value = value.longValue();
            expected = 15L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[16];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[16] + "' != '" + 16 + "'",
                    value.equals(BigInteger.valueOf(16L)));
        } else {
            value = value.longValue();
            expected = 16L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[17];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[17] + "' != '" + 17 + "'",
                    value.equals(BigInteger.valueOf(17L)));
        } else {
            value = value.longValue();
            expected = 17L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[18];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[18] + "' != '" + 18 + "'",
                    value.equals(BigInteger.valueOf(18L)));
        } else {
            value = value.longValue();
            expected = 18L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[19];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[19] + "' != '" + 19 + "'",
                    value.equals(BigInteger.valueOf(19L)));
        } else {
            value = value.longValue();
            expected = 19L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[20];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[20] + "' != '" + 20 + "'",
                    value.equals(BigInteger.valueOf(20L)));
        } else {
            value = value.longValue();
            expected = 20L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[21];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[21] + "' != '" + 21 + "'",
                    value.equals(BigInteger.valueOf(21L)));
        } else {
            value = value.longValue();
            expected = 21L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[22];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[22] + "' != '" + 22 + "'",
                    value.equals(BigInteger.valueOf(22L)));
        } else {
            value = value.longValue();
            expected = 22L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[23];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[23] + "' != '" + 23 + "'",
                    value.equals(BigInteger.valueOf(23L)));
        } else {
            value = value.longValue();
            expected = 23L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[24];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[24] + "' != '" + 24 + "'",
                    value.equals(BigInteger.valueOf(24L)));
        } else {
            value = value.longValue();
            expected = 24L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[25];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[25] + "' != '" + 25 + "'",
                    value.equals(BigInteger.valueOf(25L)));
        } else {
            value = value.longValue();
            expected = 25L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[26];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[26] + "' != '" + 26 + "'",
                    value.equals(BigInteger.valueOf(26L)));
        } else {
            value = value.longValue();
            expected = 26L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[27];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[27] + "' != '" + 27 + "'",
                    value.equals(BigInteger.valueOf(27L)));
        } else {
            value = value.longValue();
            expected = 27L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[28];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[28] + "' != '" + 28 + "'",
                    value.equals(BigInteger.valueOf(28L)));
        } else {
            value = value.longValue();
            expected = 28L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[29];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[29] + "' != '" + 29 + "'",
                    value.equals(BigInteger.valueOf(29L)));
        } else {
            value = value.longValue();
            expected = 29L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[30];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[30] + "' != '" + 30 + "'",
                    value.equals(BigInteger.valueOf(30L)));
        } else {
            value = value.longValue();
            expected = 30L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[31];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[31] + "' != '" + 31 + "'",
                    value.equals(BigInteger.valueOf(31L)));
        } else {
            value = value.longValue();
            expected = 31L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[32];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[32] + "' != '" + 32 + "'",
                    value.equals(BigInteger.valueOf(32L)));
        } else {
            value = value.longValue();
            expected = 32L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[33];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[33] + "' != '" + 33 + "'",
                    value.equals(BigInteger.valueOf(33L)));
        } else {
            value = value.longValue();
            expected = 33L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[34];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[34] + "' != '" + 34 + "'",
                    value.equals(BigInteger.valueOf(34L)));
        } else {
            value = value.longValue();
            expected = 34L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[35];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[35] + "' != '" + 35 + "'",
                    value.equals(BigInteger.valueOf(35L)));
        } else {
            value = value.longValue();
            expected = 35L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[36];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[36] + "' != '" + 36 + "'",
                    value.equals(BigInteger.valueOf(36L)));
        } else {
            value = value.longValue();
            expected = 36L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[37];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[37] + "' != '" + 37 + "'",
                    value.equals(BigInteger.valueOf(37L)));
        } else {
            value = value.longValue();
            expected = 37L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[38];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[38] + "' != '" + 38 + "'",
                    value.equals(BigInteger.valueOf(38L)));
        } else {
            value = value.longValue();
            expected = 38L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[39];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[39] + "' != '" + 39 + "'",
                    value.equals(BigInteger.valueOf(39L)));
        } else {
            value = value.longValue();
            expected = 39L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[40];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[40] + "' != '" + 40 + "'",
                    value.equals(BigInteger.valueOf(40L)));
        } else {
            value = value.longValue();
            expected = 40L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[41];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[41] + "' != '" + 41 + "'",
                    value.equals(BigInteger.valueOf(41L)));
        } else {
            value = value.longValue();
            expected = 41L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[42];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[42] + "' != '" + 42 + "'",
                    value.equals(BigInteger.valueOf(42L)));
        } else {
            value = value.longValue();
            expected = 42L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[43];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[43] + "' != '" + 43 + "'",
                    value.equals(BigInteger.valueOf(43L)));
        } else {
            value = value.longValue();
            expected = 43L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[44];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[44] + "' != '" + 44 + "'",
                    value.equals(BigInteger.valueOf(44L)));
        } else {
            value = value.longValue();
            expected = 44L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[45];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[45] + "' != '" + 45 + "'",
                    value.equals(BigInteger.valueOf(45L)));
        } else {
            value = value.longValue();
            expected = 45L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[46];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[46] + "' != '" + 46 + "'",
                    value.equals(BigInteger.valueOf(46L)));
        } else {
            value = value.longValue();
            expected = 46L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[47];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[47] + "' != '" + 47 + "'",
                    value.equals(BigInteger.valueOf(47L)));
        } else {
            value = value.longValue();
            expected = 47L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[48];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[48] + "' != '" + 48 + "'",
                    value.equals(BigInteger.valueOf(48L)));
        } else {
            value = value.longValue();
            expected = 48L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[49];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[49] + "' != '" + 49 + "'",
                    value.equals(BigInteger.valueOf(49L)));
        } else {
            value = value.longValue();
            expected = 49L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[50];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[50] + "' != '" + 50 + "'",
                    value.equals(BigInteger.valueOf(50L)));
        } else {
            value = value.longValue();
            expected = 50L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[51];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[51] + "' != '" + 51 + "'",
                    value.equals(BigInteger.valueOf(51L)));
        } else {
            value = value.longValue();
            expected = 51L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[52];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[52] + "' != '" + 52 + "'",
                    value.equals(BigInteger.valueOf(52L)));
        } else {
            value = value.longValue();
            expected = 52L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[53];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[53] + "' != '" + 53 + "'",
                    value.equals(BigInteger.valueOf(53L)));
        } else {
            value = value.longValue();
            expected = 53L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[54];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[54] + "' != '" + 54 + "'",
                    value.equals(BigInteger.valueOf(54L)));
        } else {
            value = value.longValue();
            expected = 54L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[55];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[55] + "' != '" + 55 + "'",
                    value.equals(BigInteger.valueOf(55L)));
        } else {
            value = value.longValue();
            expected = 55L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[56];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[56] + "' != '" + 56 + "'",
                    value.equals(BigInteger.valueOf(56L)));
        } else {
            value = value.longValue();
            expected = 56L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[57];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[57] + "' != '" + 57 + "'",
                    value.equals(BigInteger.valueOf(57L)));
        } else {
            value = value.longValue();
            expected = 57L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[58];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[58] + "' != '" + 58 + "'",
                    value.equals(BigInteger.valueOf(58L)));
        } else {
            value = value.longValue();
            expected = 58L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[59];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[59] + "' != '" + 59 + "'",
                    value.equals(BigInteger.valueOf(59L)));
        } else {
            value = value.longValue();
            expected = 59L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[60];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[60] + "' != '" + 60 + "'",
                    value.equals(BigInteger.valueOf(60L)));
        } else {
            value = value.longValue();
            expected = 60L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[61];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[61] + "' != '" + 61 + "'",
                    value.equals(BigInteger.valueOf(61L)));
        } else {
            value = value.longValue();
            expected = 61L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[62];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[62] + "' != '" + 62 + "'",
                    value.equals(BigInteger.valueOf(62L)));
        } else {
            value = value.longValue();
            expected = 62L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signature[63];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signature[63] + "' != '" + 63 + "'",
                    value.equals(BigInteger.valueOf(63L)));
        } else {
            value = value.longValue();
            expected = 63L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signed_messages[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signed_messages[0] + "' != '" + 5000 + "'",
                    value.equals(BigInteger.valueOf(5000L)));
        } else {
            value = value.longValue();
            expected = 5000L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signed_messages[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signed_messages[1] + "' != '" + 5234 + "'",
                    value.equals(BigInteger.valueOf(5234L)));
        } else {
            value = value.longValue();
            expected = 5234L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signed_messages[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signed_messages[2] + "' != '" + 5468 + "'",
                    value.equals(BigInteger.valueOf(5468L)));
        } else {
            value = value.longValue();
            expected = 5468L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signed_messages[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signed_messages[3] + "' != '" + 5702 + "'",
                    value.equals(BigInteger.valueOf(5702L)));
        } else {
            value = value.longValue();
            expected = 5702L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signed_messages[4];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signed_messages[4] + "' != '" + 5936 + "'",
                    value.equals(BigInteger.valueOf(5936L)));
        } else {
            value = value.longValue();
            expected = 5936L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signed_messages[5];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signed_messages[5] + "' != '" + 6170 + "'",
                    value.equals(BigInteger.valueOf(6170L)));
        } else {
            value = value.longValue();
            expected = 6170L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signed_messages[6];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signed_messages[6] + "' != '" + 6404 + "'",
                    value.equals(BigInteger.valueOf(6404L)));
        } else {
            value = value.longValue();
            expected = 6404L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signed_messages[7];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signed_messages[7] + "' != '" + 6638 + "'",
                    value.equals(BigInteger.valueOf(6638L)));
        } else {
            value = value.longValue();
            expected = 6638L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signed_messages[8];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signed_messages[8] + "' != '" + 6872 + "'",
                    value.equals(BigInteger.valueOf(6872L)));
        } else {
            value = value.longValue();
            expected = 6872L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signed_messages[9];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signed_messages[9] + "' != '" + 7106 + "'",
                    value.equals(BigInteger.valueOf(7106L)));
        } else {
            value = value.longValue();
            expected = 7106L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signed_messages[10];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signed_messages[10] + "' != '" + 7340 + "'",
                    value.equals(BigInteger.valueOf(7340L)));
        } else {
            value = value.longValue();
            expected = 7340L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signed_messages[11];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signed_messages[11] + "' != '" + 7574 + "'",
                    value.equals(BigInteger.valueOf(7574L)));
        } else {
            value = value.longValue();
            expected = 7574L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signed_messages[12];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signed_messages[12] + "' != '" + 7808 + "'",
                    value.equals(BigInteger.valueOf(7808L)));
        } else {
            value = value.longValue();
            expected = 7808L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signed_messages[13];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signed_messages[13] + "' != '" + 8042 + "'",
                    value.equals(BigInteger.valueOf(8042L)));
        } else {
            value = value.longValue();
            expected = 8042L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signed_messages[14];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signed_messages[14] + "' != '" + 8276 + "'",
                    value.equals(BigInteger.valueOf(8276L)));
        } else {
            value = value.longValue();
            expected = 8276L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signed_messages[15];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signed_messages[15] + "' != '" + 8510 + "'",
                    value.equals(BigInteger.valueOf(8510L)));
        } else {
            value = value.longValue();
            expected = 8510L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signed_messages[16];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signed_messages[16] + "' != '" + 8744 + "'",
                    value.equals(BigInteger.valueOf(8744L)));
        } else {
            value = value.longValue();
            expected = 8744L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signed_messages[17];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signed_messages[17] + "' != '" + 8978 + "'",
                    value.equals(BigInteger.valueOf(8978L)));
        } else {
            value = value.longValue();
            expected = 8978L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signed_messages[18];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signed_messages[18] + "' != '" + 9212 + "'",
                    value.equals(BigInteger.valueOf(9212L)));
        } else {
            value = value.longValue();
            expected = 9212L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signed_messages[19];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signed_messages[19] + "' != '" + 9446 + "'",
                    value.equals(BigInteger.valueOf(9446L)));
        } else {
            value = value.longValue();
            expected = 9446L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signed_messages[20];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signed_messages[20] + "' != '" + 9680 + "'",
                    value.equals(BigInteger.valueOf(9680L)));
        } else {
            value = value.longValue();
            expected = 9680L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signed_messages[21];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signed_messages[21] + "' != '" + 9914 + "'",
                    value.equals(BigInteger.valueOf(9914L)));
        } else {
            value = value.longValue();
            expected = 9914L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signed_messages[22];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signed_messages[22] + "' != '" + 10148 + "'",
                    value.equals(BigInteger.valueOf(10148L)));
        } else {
            value = value.longValue();
            expected = 10148L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signed_messages[23];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signed_messages[23] + "' != '" + 10382 + "'",
                    value.equals(BigInteger.valueOf(10382L)));
        } else {
            value = value.longValue();
            expected = 10382L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.signed_messages[24];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.signed_messages[24] + "' != '" + 10616 + "'",
                    value.equals(BigInteger.valueOf(10616L)));
        } else {
            value = value.longValue();
            expected = 10616L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }
}
