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
// spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrGriddedCorrection.yaml by generate.py. Do not modify
// by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.ssr.MsgSsrGriddedCorrection;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_ssr_MsgSsrGriddedCorrectionTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_ssr_MsgSsrGriddedCorrectionTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 21,
                    (byte) 14,
                    (byte) 151,
                    (byte) 50,
                    (byte) 120,
                    (byte) 133,
                    (byte) 29,
                    (byte) 151,
                    (byte) 174,
                    (byte) 229,
                    (byte) 151,
                    (byte) 189,
                    (byte) 204,
                    (byte) 196,
                    (byte) 105,
                    (byte) 170,
                    (byte) 120,
                    (byte) 149,
                    (byte) 169,
                    (byte) 37,
                    (byte) 244,
                    (byte) 78,
                    (byte) 72,
                    (byte) 140,
                    (byte) 101,
                    (byte) 2,
                    (byte) 173,
                    (byte) 88,
                    (byte) 70,
                    (byte) 180,
                    (byte) 54,
                    (byte) 152,
                    (byte) 115,
                    (byte) 78,
                    (byte) 201,
                    (byte) 161,
                    (byte) 23,
                    (byte) 135,
                    (byte) 152,
                    (byte) 98,
                    (byte) 61,
                    (byte) 75,
                    (byte) 178,
                    (byte) 120,
                    (byte) 229,
                    (byte) 146,
                    (byte) 55,
                    (byte) 58,
                    (byte) 169,
                    (byte) 234,
                    (byte) 230,
                    (byte) 69,
                    (byte) 172,
                    (byte) 191,
                    (byte) 127,
                    (byte) 146,
                    (byte) 89,
                    (byte) 150,
                    (byte) 91,
                    (byte) 111,
                    (byte) 225,
                    (byte) 41,
                    (byte) 17,
                    (byte) 119,
                    (byte) 52,
                    (byte) 166,
                    (byte) 166,
                    (byte) 120,
                    (byte) 57,
                    (byte) 221,
                    (byte) 12,
                    (byte) 3,
                    (byte) 156,
                    (byte) 70,
                    (byte) 156,
                    (byte) 35,
                    (byte) 127,
                    (byte) 8,
                    (byte) 127,
                    (byte) 58,
                    (byte) 128,
                    (byte) 55,
                    (byte) 115,
                    (byte) 80,
                    (byte) 157,
                    (byte) 122,
                    (byte) 153,
                    (byte) 124,
                    (byte) 27,
                    (byte) 128,
                    (byte) 98,
                    (byte) 103,
                    (byte) 204,
                    (byte) 75,
                    (byte) 238,
                    (byte) 128,
                    (byte) 226,
                    (byte) 148,
                    (byte) 248,
                    (byte) 61,
                    (byte) 216,
                    (byte) 208,
                    (byte) 149,
                    (byte) 167,
                    (byte) 224,
                    (byte) 40,
                    (byte) 144,
                    (byte) 186,
                    (byte) 157,
                    (byte) 227,
                    (byte) 72,
                    (byte) 240,
                    (byte) 100,
                    (byte) 35,
                    (byte) 12,
                    (byte) 212,
                    (byte) 7,
                    (byte) 59,
                    (byte) 176,
                    (byte) 81,
                    (byte) 86,
                    (byte) 27,
                    (byte) 24,
                    (byte) 155,
                    (byte) 67,
                    (byte) 43,
                    (byte) 132,
                    (byte) 45,
                    (byte) 203,
                    (byte) 44,
                    (byte) 6,
                    (byte) 112,
                    (byte) 183,
                    (byte) 231,
                    (byte) 176,
                    (byte) 79,
                    (byte) 194,
                    (byte) 253,
                    (byte) 247,
                    (byte) 103,
                    (byte) 91,
                    (byte) 226,
                    (byte) 116,
                    (byte) 148,
                    (byte) 23,
                    (byte) 62,
                    (byte) 227,
                    (byte) 240,
                    (byte) 29,
                    (byte) 219,
                    (byte) 205,
                    (byte) 18,
                    (byte) 242,
                    (byte) 207,
                    (byte) 72,
                    (byte) 71,
                    (byte) 79,
                    (byte) 37,
                    (byte) 42,
                    (byte) 176,
                    (byte) 201,
                    (byte) 202,
                    (byte) 91,
                    (byte) 105,
                    (byte) 115,
                    (byte) 146,
                    (byte) 59,
                    (byte) 110,
                    (byte) 44,
                    (byte) 109,
                    (byte) 128,
                    (byte) 183,
                    (byte) 185,
                    (byte) 67,
                    (byte) 31,
                    (byte) 165,
                    (byte) 92,
                    (byte) 79,
                    (byte) 189,
                    (byte) 180,
                    (byte) 94,
                    (byte) 7,
                    (byte) 162,
                    (byte) 121,
                    (byte) 156,
                    (byte) 210,
                    (byte) 47,
                    (byte) 7,
                    (byte) 7,
                    (byte) 205,
                    (byte) 174,
                    (byte) 41,
                    (byte) 241,
                    (byte) 129,
                    (byte) 210,
                    (byte) 43,
                    (byte) 101,
                    (byte) 186,
                    (byte) 208,
                    (byte) 195,
                    (byte) 226,
                    (byte) 247,
                    (byte) 187,
                    (byte) 219,
                    (byte) 160,
                    (byte) 120,
                    (byte) 192,
                    (byte) 102,
                    (byte) 166,
                    (byte) 42,
                    (byte) 246,
                    (byte) 173,
                    (byte) 94,
                    (byte) 102,
                    (byte) 156,
                    (byte) 222,
                    (byte) 30,
                    (byte) 35,
                    (byte) 247,
                    (byte) 64,
                    (byte) 189,
                    (byte) 137,
                    (byte) 204,
                    (byte) 220,
                    (byte) 32,
                    (byte) 71,
                    (byte) 222,
                    (byte) 222,
                    (byte) 201,
                    (byte) 246,
                    (byte) 3,
                    (byte) 25,
                    (byte) 45,
                    (byte) 251,
                    (byte) 239,
                    (byte) 115,
                    (byte) 88,
                    (byte) 218,
                    (byte) 10,
                    (byte) 209,
                    (byte) 120,
                    (byte) 65,
                    (byte) 175,
                    (byte) 131,
                    (byte) 194,
                    (byte) 41,
                    (byte) 174,
                    (byte) 137,
                    (byte) 17,
                    (byte) 68,
                    (byte) 28,
                    (byte) 253,
                    (byte) 42,
                };
        SBPMessage sbp = new SBPMessage(0xf9c4, 0x5fc, payload);
        MsgSsrGriddedCorrection msg = new MsgSsrGriddedCorrection(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.header.iod_atmo;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.header.iod_atmo + "' != '" + 170 + "'",
                    value.equals(BigInteger.valueOf(170L)));
        } else {
            value = value.longValue();
            expected = 170L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.header.num_msgs;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.header.num_msgs + "' != '" + 48535 + "'",
                    value.equals(BigInteger.valueOf(48535L)));
        } else {
            value = value.longValue();
            expected = 48535L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.header.seq_num;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.header.seq_num + "' != '" + 50380 + "'",
                    value.equals(BigInteger.valueOf(50380L)));
        } else {
            value = value.longValue();
            expected = 50380L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.header.tile_id;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.header.tile_id + "' != '" + 12951 + "'",
                    value.equals(BigInteger.valueOf(12951L)));
        } else {
            value = value.longValue();
            expected = 12951L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.header.tile_set_id;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.header.tile_set_id + "' != '" + 3605 + "'",
                    value.equals(BigInteger.valueOf(3605L)));
        } else {
            value = value.longValue();
            expected = 3605L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.header.time.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.header.time.tow + "' != '" + 2535294328L + "'",
                    value.equals(new BigInteger("2535294328")));
        } else {
            value = value.longValue();
            expected = 2535294328L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.header.time.wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.header.time.wn + "' != '" + 58798 + "'",
                    value.equals(BigInteger.valueOf(58798L)));
        } else {
            value = value.longValue();
            expected = 58798L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.header.tropo_quality_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.header.tropo_quality_indicator + "' != '" + 120 + "'",
                    value.equals(BigInteger.valueOf(120L)));
        } else {
            value = value.longValue();
            expected = 120L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.header.update_interval;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.header.update_interval + "' != '" + 105 + "'",
                    value.equals(BigInteger.valueOf(105L)));
        } else {
            value = value.longValue();
            expected = 105L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.index;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.index + "' != '" + 43413 + "'",
                    value.equals(BigInteger.valueOf(43413L)));
        } else {
            value = value.longValue();
            expected = 43413L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[0].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[0].residual + "' != '" + -21246 + "'",
                    value.equals(BigInteger.valueOf(-21246L)));
        } else {
            value = value.longValue();
            expected = -21246L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[0].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[0].stddev + "' != '" + 88 + "'",
                    value.equals(BigInteger.valueOf(88L)));
        } else {
            value = value.longValue();
            expected = 88L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[0].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[0].sv_id.constellation + "' != '" + 101 + "'",
                    value.equals(BigInteger.valueOf(101L)));
        } else {
            value = value.longValue();
            expected = 101L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[0].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[0].sv_id.satId + "' != '" + 140 + "'",
                    value.equals(BigInteger.valueOf(140L)));
        } else {
            value = value.longValue();
            expected = 140L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[1].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[1].residual + "' != '" + -26570 + "'",
                    value.equals(BigInteger.valueOf(-26570L)));
        } else {
            value = value.longValue();
            expected = -26570L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[1].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[1].stddev + "' != '" + 115 + "'",
                    value.equals(BigInteger.valueOf(115L)));
        } else {
            value = value.longValue();
            expected = 115L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[1].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[1].sv_id.constellation + "' != '" + 180 + "'",
                    value.equals(BigInteger.valueOf(180L)));
        } else {
            value = value.longValue();
            expected = 180L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[1].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[1].sv_id.satId + "' != '" + 70 + "'",
                    value.equals(BigInteger.valueOf(70L)));
        } else {
            value = value.longValue();
            expected = 70L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[2].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[2].residual + "' != '" + 6049 + "'",
                    value.equals(BigInteger.valueOf(6049L)));
        } else {
            value = value.longValue();
            expected = 6049L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[2].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[2].stddev + "' != '" + 135 + "'",
                    value.equals(BigInteger.valueOf(135L)));
        } else {
            value = value.longValue();
            expected = 135L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[2].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[2].sv_id.constellation + "' != '" + 201 + "'",
                    value.equals(BigInteger.valueOf(201L)));
        } else {
            value = value.longValue();
            expected = 201L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[2].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[2].sv_id.satId + "' != '" + 78 + "'",
                    value.equals(BigInteger.valueOf(78L)));
        } else {
            value = value.longValue();
            expected = 78L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[3].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[3].residual + "' != '" + 19261 + "'",
                    value.equals(BigInteger.valueOf(19261L)));
        } else {
            value = value.longValue();
            expected = 19261L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[3].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[3].stddev + "' != '" + 178 + "'",
                    value.equals(BigInteger.valueOf(178L)));
        } else {
            value = value.longValue();
            expected = 178L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[3].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[3].sv_id.constellation + "' != '" + 98 + "'",
                    value.equals(BigInteger.valueOf(98L)));
        } else {
            value = value.longValue();
            expected = 98L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[3].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[3].sv_id.satId + "' != '" + 152 + "'",
                    value.equals(BigInteger.valueOf(152L)));
        } else {
            value = value.longValue();
            expected = 152L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[4].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[4].residual + "' != '" + 14226 + "'",
                    value.equals(BigInteger.valueOf(14226L)));
        } else {
            value = value.longValue();
            expected = 14226L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[4].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[4].stddev + "' != '" + 58 + "'",
                    value.equals(BigInteger.valueOf(58L)));
        } else {
            value = value.longValue();
            expected = 58L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[4].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[4].sv_id.constellation + "' != '" + 229 + "'",
                    value.equals(BigInteger.valueOf(229L)));
        } else {
            value = value.longValue();
            expected = 229L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[4].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[4].sv_id.satId + "' != '" + 120 + "'",
                    value.equals(BigInteger.valueOf(120L)));
        } else {
            value = value.longValue();
            expected = 120L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[5].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[5].residual + "' != '" + 17894 + "'",
                    value.equals(BigInteger.valueOf(17894L)));
        } else {
            value = value.longValue();
            expected = 17894L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[5].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[5].stddev + "' != '" + 172 + "'",
                    value.equals(BigInteger.valueOf(172L)));
        } else {
            value = value.longValue();
            expected = 172L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[5].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[5].sv_id.constellation + "' != '" + 234 + "'",
                    value.equals(BigInteger.valueOf(234L)));
        } else {
            value = value.longValue();
            expected = 234L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[5].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[5].sv_id.satId + "' != '" + 169 + "'",
                    value.equals(BigInteger.valueOf(169L)));
        } else {
            value = value.longValue();
            expected = 169L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[6].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[6].residual + "' != '" + 22930 + "'",
                    value.equals(BigInteger.valueOf(22930L)));
        } else {
            value = value.longValue();
            expected = 22930L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[6].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[6].stddev + "' != '" + 150 + "'",
                    value.equals(BigInteger.valueOf(150L)));
        } else {
            value = value.longValue();
            expected = 150L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[6].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[6].sv_id.constellation + "' != '" + 127 + "'",
                    value.equals(BigInteger.valueOf(127L)));
        } else {
            value = value.longValue();
            expected = 127L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[6].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[6].sv_id.satId + "' != '" + 191 + "'",
                    value.equals(BigInteger.valueOf(191L)));
        } else {
            value = value.longValue();
            expected = 191L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[7].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[7].residual + "' != '" + 10721 + "'",
                    value.equals(BigInteger.valueOf(10721L)));
        } else {
            value = value.longValue();
            expected = 10721L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[7].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[7].stddev + "' != '" + 17 + "'",
                    value.equals(BigInteger.valueOf(17L)));
        } else {
            value = value.longValue();
            expected = 17L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[7].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[7].sv_id.constellation + "' != '" + 111 + "'",
                    value.equals(BigInteger.valueOf(111L)));
        } else {
            value = value.longValue();
            expected = 111L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[7].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[7].sv_id.satId + "' != '" + 91 + "'",
                    value.equals(BigInteger.valueOf(91L)));
        } else {
            value = value.longValue();
            expected = 91L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[8].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[8].residual + "' != '" + -22874 + "'",
                    value.equals(BigInteger.valueOf(-22874L)));
        } else {
            value = value.longValue();
            expected = -22874L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[8].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[8].stddev + "' != '" + 120 + "'",
                    value.equals(BigInteger.valueOf(120L)));
        } else {
            value = value.longValue();
            expected = 120L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[8].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[8].sv_id.constellation + "' != '" + 52 + "'",
                    value.equals(BigInteger.valueOf(52L)));
        } else {
            value = value.longValue();
            expected = 52L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[8].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[8].sv_id.satId + "' != '" + 119 + "'",
                    value.equals(BigInteger.valueOf(119L)));
        } else {
            value = value.longValue();
            expected = 119L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[9].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[9].residual + "' != '" + 780 + "'",
                    value.equals(BigInteger.valueOf(780L)));
        } else {
            value = value.longValue();
            expected = 780L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[9].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[9].stddev + "' != '" + 156 + "'",
                    value.equals(BigInteger.valueOf(156L)));
        } else {
            value = value.longValue();
            expected = 156L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[9].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[9].sv_id.constellation + "' != '" + 221 + "'",
                    value.equals(BigInteger.valueOf(221L)));
        } else {
            value = value.longValue();
            expected = 221L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[9].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[9].sv_id.satId + "' != '" + 57 + "'",
                    value.equals(BigInteger.valueOf(57L)));
        } else {
            value = value.longValue();
            expected = 57L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[10].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[10].residual + "' != '" + 32547 + "'",
                    value.equals(BigInteger.valueOf(32547L)));
        } else {
            value = value.longValue();
            expected = 32547L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[10].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[10].stddev + "' != '" + 8 + "'",
                    value.equals(BigInteger.valueOf(8L)));
        } else {
            value = value.longValue();
            expected = 8L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[10].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[10].sv_id.constellation + "' != '" + 156 + "'",
                    value.equals(BigInteger.valueOf(156L)));
        } else {
            value = value.longValue();
            expected = 156L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[10].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[10].sv_id.satId + "' != '" + 70 + "'",
                    value.equals(BigInteger.valueOf(70L)));
        } else {
            value = value.longValue();
            expected = 70L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[11].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[11].residual + "' != '" + 14208 + "'",
                    value.equals(BigInteger.valueOf(14208L)));
        } else {
            value = value.longValue();
            expected = 14208L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[11].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[11].stddev + "' != '" + 115 + "'",
                    value.equals(BigInteger.valueOf(115L)));
        } else {
            value = value.longValue();
            expected = 115L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[11].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[11].sv_id.constellation + "' != '" + 58 + "'",
                    value.equals(BigInteger.valueOf(58L)));
        } else {
            value = value.longValue();
            expected = 58L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[11].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[11].sv_id.satId + "' != '" + 127 + "'",
                    value.equals(BigInteger.valueOf(127L)));
        } else {
            value = value.longValue();
            expected = 127L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[12].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[12].residual + "' != '" + -26246 + "'",
                    value.equals(BigInteger.valueOf(-26246L)));
        } else {
            value = value.longValue();
            expected = -26246L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[12].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[12].stddev + "' != '" + 124 + "'",
                    value.equals(BigInteger.valueOf(124L)));
        } else {
            value = value.longValue();
            expected = 124L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[12].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[12].sv_id.constellation + "' != '" + 157 + "'",
                    value.equals(BigInteger.valueOf(157L)));
        } else {
            value = value.longValue();
            expected = 157L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[12].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[12].sv_id.satId + "' != '" + 80 + "'",
                    value.equals(BigInteger.valueOf(80L)));
        } else {
            value = value.longValue();
            expected = 80L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[13].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[13].residual + "' != '" + 26466 + "'",
                    value.equals(BigInteger.valueOf(26466L)));
        } else {
            value = value.longValue();
            expected = 26466L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[13].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[13].stddev + "' != '" + 204 + "'",
                    value.equals(BigInteger.valueOf(204L)));
        } else {
            value = value.longValue();
            expected = 204L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[13].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[13].sv_id.constellation + "' != '" + 128 + "'",
                    value.equals(BigInteger.valueOf(128L)));
        } else {
            value = value.longValue();
            expected = 128L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[13].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[13].sv_id.satId + "' != '" + 27 + "'",
                    value.equals(BigInteger.valueOf(27L)));
        } else {
            value = value.longValue();
            expected = 27L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[14].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[14].residual + "' != '" + -7552 + "'",
                    value.equals(BigInteger.valueOf(-7552L)));
        } else {
            value = value.longValue();
            expected = -7552L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[14].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[14].stddev + "' != '" + 148 + "'",
                    value.equals(BigInteger.valueOf(148L)));
        } else {
            value = value.longValue();
            expected = 148L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[14].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[14].sv_id.constellation + "' != '" + 238 + "'",
                    value.equals(BigInteger.valueOf(238L)));
        } else {
            value = value.longValue();
            expected = 238L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[14].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[14].sv_id.satId + "' != '" + 75 + "'",
                    value.equals(BigInteger.valueOf(75L)));
        } else {
            value = value.longValue();
            expected = 75L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[15].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[15].residual + "' != '" + -12072 + "'",
                    value.equals(BigInteger.valueOf(-12072L)));
        } else {
            value = value.longValue();
            expected = -12072L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[15].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[15].stddev + "' != '" + 149 + "'",
                    value.equals(BigInteger.valueOf(149L)));
        } else {
            value = value.longValue();
            expected = 149L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[15].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[15].sv_id.constellation + "' != '" + 61 + "'",
                    value.equals(BigInteger.valueOf(61L)));
        } else {
            value = value.longValue();
            expected = 61L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[15].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[15].sv_id.satId + "' != '" + 248 + "'",
                    value.equals(BigInteger.valueOf(248L)));
        } else {
            value = value.longValue();
            expected = 248L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[16].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[16].residual + "' != '" + -28632 + "'",
                    value.equals(BigInteger.valueOf(-28632L)));
        } else {
            value = value.longValue();
            expected = -28632L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[16].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[16].stddev + "' != '" + 186 + "'",
                    value.equals(BigInteger.valueOf(186L)));
        } else {
            value = value.longValue();
            expected = 186L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[16].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[16].sv_id.constellation + "' != '" + 224 + "'",
                    value.equals(BigInteger.valueOf(224L)));
        } else {
            value = value.longValue();
            expected = 224L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[16].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[16].sv_id.satId + "' != '" + 167 + "'",
                    value.equals(BigInteger.valueOf(167L)));
        } else {
            value = value.longValue();
            expected = 167L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[17].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[17].residual + "' != '" + -4024 + "'",
                    value.equals(BigInteger.valueOf(-4024L)));
        } else {
            value = value.longValue();
            expected = -4024L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[17].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[17].stddev + "' != '" + 100 + "'",
                    value.equals(BigInteger.valueOf(100L)));
        } else {
            value = value.longValue();
            expected = 100L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[17].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[17].sv_id.constellation + "' != '" + 227 + "'",
                    value.equals(BigInteger.valueOf(227L)));
        } else {
            value = value.longValue();
            expected = 227L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[17].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[17].sv_id.satId + "' != '" + 157 + "'",
                    value.equals(BigInteger.valueOf(157L)));
        } else {
            value = value.longValue();
            expected = 157L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[18].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[18].residual + "' != '" + 2004 + "'",
                    value.equals(BigInteger.valueOf(2004L)));
        } else {
            value = value.longValue();
            expected = 2004L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[18].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[18].stddev + "' != '" + 59 + "'",
                    value.equals(BigInteger.valueOf(59L)));
        } else {
            value = value.longValue();
            expected = 59L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[18].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[18].sv_id.constellation + "' != '" + 12 + "'",
                    value.equals(BigInteger.valueOf(12L)));
        } else {
            value = value.longValue();
            expected = 12L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[18].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[18].sv_id.satId + "' != '" + 35 + "'",
                    value.equals(BigInteger.valueOf(35L)));
        } else {
            value = value.longValue();
            expected = 35L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[19].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[19].residual + "' != '" + 6998 + "'",
                    value.equals(BigInteger.valueOf(6998L)));
        } else {
            value = value.longValue();
            expected = 6998L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[19].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[19].stddev + "' != '" + 24 + "'",
                    value.equals(BigInteger.valueOf(24L)));
        } else {
            value = value.longValue();
            expected = 24L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[19].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[19].sv_id.constellation + "' != '" + 81 + "'",
                    value.equals(BigInteger.valueOf(81L)));
        } else {
            value = value.longValue();
            expected = 81L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[19].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[19].sv_id.satId + "' != '" + 176 + "'",
                    value.equals(BigInteger.valueOf(176L)));
        } else {
            value = value.longValue();
            expected = 176L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[20].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[20].residual + "' != '" + -31701 + "'",
                    value.equals(BigInteger.valueOf(-31701L)));
        } else {
            value = value.longValue();
            expected = -31701L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[20].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[20].stddev + "' != '" + 45 + "'",
                    value.equals(BigInteger.valueOf(45L)));
        } else {
            value = value.longValue();
            expected = 45L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[20].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[20].sv_id.constellation + "' != '" + 67 + "'",
                    value.equals(BigInteger.valueOf(67L)));
        } else {
            value = value.longValue();
            expected = 67L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[20].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[20].sv_id.satId + "' != '" + 155 + "'",
                    value.equals(BigInteger.valueOf(155L)));
        } else {
            value = value.longValue();
            expected = 155L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[21].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[21].residual + "' != '" + 28678 + "'",
                    value.equals(BigInteger.valueOf(28678L)));
        } else {
            value = value.longValue();
            expected = 28678L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[21].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[21].stddev + "' != '" + 183 + "'",
                    value.equals(BigInteger.valueOf(183L)));
        } else {
            value = value.longValue();
            expected = 183L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[21].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[21].sv_id.constellation + "' != '" + 44 + "'",
                    value.equals(BigInteger.valueOf(44L)));
        } else {
            value = value.longValue();
            expected = 44L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[21].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[21].sv_id.satId + "' != '" + 203 + "'",
                    value.equals(BigInteger.valueOf(203L)));
        } else {
            value = value.longValue();
            expected = 203L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[22].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[22].residual + "' != '" + -15793 + "'",
                    value.equals(BigInteger.valueOf(-15793L)));
        } else {
            value = value.longValue();
            expected = -15793L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[22].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[22].stddev + "' != '" + 253 + "'",
                    value.equals(BigInteger.valueOf(253L)));
        } else {
            value = value.longValue();
            expected = 253L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[22].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[22].sv_id.constellation + "' != '" + 176 + "'",
                    value.equals(BigInteger.valueOf(176L)));
        } else {
            value = value.longValue();
            expected = 176L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[22].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[22].sv_id.satId + "' != '" + 231 + "'",
                    value.equals(BigInteger.valueOf(231L)));
        } else {
            value = value.longValue();
            expected = 231L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[23].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[23].residual + "' != '" + -7589 + "'",
                    value.equals(BigInteger.valueOf(-7589L)));
        } else {
            value = value.longValue();
            expected = -7589L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[23].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[23].stddev + "' != '" + 116 + "'",
                    value.equals(BigInteger.valueOf(116L)));
        } else {
            value = value.longValue();
            expected = 116L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[23].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[23].sv_id.constellation + "' != '" + 103 + "'",
                    value.equals(BigInteger.valueOf(103L)));
        } else {
            value = value.longValue();
            expected = 103L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[23].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[23].sv_id.satId + "' != '" + 247 + "'",
                    value.equals(BigInteger.valueOf(247L)));
        } else {
            value = value.longValue();
            expected = 247L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[24].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[24].residual + "' != '" + -7362 + "'",
                    value.equals(BigInteger.valueOf(-7362L)));
        } else {
            value = value.longValue();
            expected = -7362L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[24].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[24].stddev + "' != '" + 240 + "'",
                    value.equals(BigInteger.valueOf(240L)));
        } else {
            value = value.longValue();
            expected = 240L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[24].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[24].sv_id.constellation + "' != '" + 23 + "'",
                    value.equals(BigInteger.valueOf(23L)));
        } else {
            value = value.longValue();
            expected = 23L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[24].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[24].sv_id.satId + "' != '" + 148 + "'",
                    value.equals(BigInteger.valueOf(148L)));
        } else {
            value = value.longValue();
            expected = 148L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[25].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[25].residual + "' != '" + 4813 + "'",
                    value.equals(BigInteger.valueOf(4813L)));
        } else {
            value = value.longValue();
            expected = 4813L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[25].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[25].stddev + "' != '" + 242 + "'",
                    value.equals(BigInteger.valueOf(242L)));
        } else {
            value = value.longValue();
            expected = 242L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[25].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[25].sv_id.constellation + "' != '" + 219 + "'",
                    value.equals(BigInteger.valueOf(219L)));
        } else {
            value = value.longValue();
            expected = 219L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[25].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[25].sv_id.satId + "' != '" + 29 + "'",
                    value.equals(BigInteger.valueOf(29L)));
        } else {
            value = value.longValue();
            expected = 29L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[26].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[26].residual + "' != '" + 20295 + "'",
                    value.equals(BigInteger.valueOf(20295L)));
        } else {
            value = value.longValue();
            expected = 20295L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[26].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[26].stddev + "' != '" + 37 + "'",
                    value.equals(BigInteger.valueOf(37L)));
        } else {
            value = value.longValue();
            expected = 37L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[26].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[26].sv_id.constellation + "' != '" + 72 + "'",
                    value.equals(BigInteger.valueOf(72L)));
        } else {
            value = value.longValue();
            expected = 72L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[26].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[26].sv_id.satId + "' != '" + 207 + "'",
                    value.equals(BigInteger.valueOf(207L)));
        } else {
            value = value.longValue();
            expected = 207L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[27].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[27].residual + "' != '" + -13623 + "'",
                    value.equals(BigInteger.valueOf(-13623L)));
        } else {
            value = value.longValue();
            expected = -13623L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[27].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[27].stddev + "' != '" + 91 + "'",
                    value.equals(BigInteger.valueOf(91L)));
        } else {
            value = value.longValue();
            expected = 91L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[27].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[27].sv_id.constellation + "' != '" + 176 + "'",
                    value.equals(BigInteger.valueOf(176L)));
        } else {
            value = value.longValue();
            expected = 176L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[27].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[27].sv_id.satId + "' != '" + 42 + "'",
                    value.equals(BigInteger.valueOf(42L)));
        } else {
            value = value.longValue();
            expected = 42L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[28].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[28].residual + "' != '" + 15250 + "'",
                    value.equals(BigInteger.valueOf(15250L)));
        } else {
            value = value.longValue();
            expected = 15250L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[28].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[28].stddev + "' != '" + 110 + "'",
                    value.equals(BigInteger.valueOf(110L)));
        } else {
            value = value.longValue();
            expected = 110L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[28].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[28].sv_id.constellation + "' != '" + 115 + "'",
                    value.equals(BigInteger.valueOf(115L)));
        } else {
            value = value.longValue();
            expected = 115L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[28].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[28].sv_id.satId + "' != '" + 105 + "'",
                    value.equals(BigInteger.valueOf(105L)));
        } else {
            value = value.longValue();
            expected = 105L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[29].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[29].residual + "' != '" + -18560 + "'",
                    value.equals(BigInteger.valueOf(-18560L)));
        } else {
            value = value.longValue();
            expected = -18560L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[29].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[29].stddev + "' != '" + 185 + "'",
                    value.equals(BigInteger.valueOf(185L)));
        } else {
            value = value.longValue();
            expected = 185L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[29].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[29].sv_id.constellation + "' != '" + 109 + "'",
                    value.equals(BigInteger.valueOf(109L)));
        } else {
            value = value.longValue();
            expected = 109L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[29].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[29].sv_id.satId + "' != '" + 44 + "'",
                    value.equals(BigInteger.valueOf(44L)));
        } else {
            value = value.longValue();
            expected = 44L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[30].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[30].residual + "' != '" + 23717 + "'",
                    value.equals(BigInteger.valueOf(23717L)));
        } else {
            value = value.longValue();
            expected = 23717L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[30].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[30].stddev + "' != '" + 79 + "'",
                    value.equals(BigInteger.valueOf(79L)));
        } else {
            value = value.longValue();
            expected = 79L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[30].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[30].sv_id.constellation + "' != '" + 31 + "'",
                    value.equals(BigInteger.valueOf(31L)));
        } else {
            value = value.longValue();
            expected = 31L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[30].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[30].sv_id.satId + "' != '" + 67 + "'",
                    value.equals(BigInteger.valueOf(67L)));
        } else {
            value = value.longValue();
            expected = 67L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[31].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[31].residual + "' != '" + 1886 + "'",
                    value.equals(BigInteger.valueOf(1886L)));
        } else {
            value = value.longValue();
            expected = 1886L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[31].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[31].stddev + "' != '" + 162 + "'",
                    value.equals(BigInteger.valueOf(162L)));
        } else {
            value = value.longValue();
            expected = 162L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[31].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[31].sv_id.constellation + "' != '" + 180 + "'",
                    value.equals(BigInteger.valueOf(180L)));
        } else {
            value = value.longValue();
            expected = 180L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[31].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[31].sv_id.satId + "' != '" + 189 + "'",
                    value.equals(BigInteger.valueOf(189L)));
        } else {
            value = value.longValue();
            expected = 189L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[32].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[32].residual + "' != '" + 12242 + "'",
                    value.equals(BigInteger.valueOf(12242L)));
        } else {
            value = value.longValue();
            expected = 12242L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[32].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[32].stddev + "' != '" + 7 + "'",
                    value.equals(BigInteger.valueOf(7L)));
        } else {
            value = value.longValue();
            expected = 7L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[32].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[32].sv_id.constellation + "' != '" + 156 + "'",
                    value.equals(BigInteger.valueOf(156L)));
        } else {
            value = value.longValue();
            expected = 156L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[32].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[32].sv_id.satId + "' != '" + 121 + "'",
                    value.equals(BigInteger.valueOf(121L)));
        } else {
            value = value.longValue();
            expected = 121L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[33].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[33].residual + "' != '" + 10670 + "'",
                    value.equals(BigInteger.valueOf(10670L)));
        } else {
            value = value.longValue();
            expected = 10670L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[33].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[33].stddev + "' != '" + 241 + "'",
                    value.equals(BigInteger.valueOf(241L)));
        } else {
            value = value.longValue();
            expected = 241L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[33].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[33].sv_id.constellation + "' != '" + 205 + "'",
                    value.equals(BigInteger.valueOf(205L)));
        } else {
            value = value.longValue();
            expected = 205L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[33].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[33].sv_id.satId + "' != '" + 7 + "'",
                    value.equals(BigInteger.valueOf(7L)));
        } else {
            value = value.longValue();
            expected = 7L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[34].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[34].residual + "' != '" + 25899 + "'",
                    value.equals(BigInteger.valueOf(25899L)));
        } else {
            value = value.longValue();
            expected = 25899L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[34].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[34].stddev + "' != '" + 186 + "'",
                    value.equals(BigInteger.valueOf(186L)));
        } else {
            value = value.longValue();
            expected = 186L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[34].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[34].sv_id.constellation + "' != '" + 210 + "'",
                    value.equals(BigInteger.valueOf(210L)));
        } else {
            value = value.longValue();
            expected = 210L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[34].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[34].sv_id.satId + "' != '" + 129 + "'",
                    value.equals(BigInteger.valueOf(129L)));
        } else {
            value = value.longValue();
            expected = 129L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[35].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[35].residual + "' != '" + -2078 + "'",
                    value.equals(BigInteger.valueOf(-2078L)));
        } else {
            value = value.longValue();
            expected = -2078L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[35].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[35].stddev + "' != '" + 187 + "'",
                    value.equals(BigInteger.valueOf(187L)));
        } else {
            value = value.longValue();
            expected = 187L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[35].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[35].sv_id.constellation + "' != '" + 195 + "'",
                    value.equals(BigInteger.valueOf(195L)));
        } else {
            value = value.longValue();
            expected = 195L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[35].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[35].sv_id.satId + "' != '" + 208 + "'",
                    value.equals(BigInteger.valueOf(208L)));
        } else {
            value = value.longValue();
            expected = 208L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[36].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[36].residual + "' != '" + -16264 + "'",
                    value.equals(BigInteger.valueOf(-16264L)));
        } else {
            value = value.longValue();
            expected = -16264L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[36].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[36].stddev + "' != '" + 102 + "'",
                    value.equals(BigInteger.valueOf(102L)));
        } else {
            value = value.longValue();
            expected = 102L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[36].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[36].sv_id.constellation + "' != '" + 160 + "'",
                    value.equals(BigInteger.valueOf(160L)));
        } else {
            value = value.longValue();
            expected = 160L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[36].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[36].sv_id.satId + "' != '" + 219 + "'",
                    value.equals(BigInteger.valueOf(219L)));
        } else {
            value = value.longValue();
            expected = 219L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[37].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[37].residual + "' != '" + -21002 + "'",
                    value.equals(BigInteger.valueOf(-21002L)));
        } else {
            value = value.longValue();
            expected = -21002L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[37].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[37].stddev + "' != '" + 94 + "'",
                    value.equals(BigInteger.valueOf(94L)));
        } else {
            value = value.longValue();
            expected = 94L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[37].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[37].sv_id.constellation + "' != '" + 42 + "'",
                    value.equals(BigInteger.valueOf(42L)));
        } else {
            value = value.longValue();
            expected = 42L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[37].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[37].sv_id.satId + "' != '" + 166 + "'",
                    value.equals(BigInteger.valueOf(166L)));
        } else {
            value = value.longValue();
            expected = 166L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[38].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[38].residual + "' != '" + 7902 + "'",
                    value.equals(BigInteger.valueOf(7902L)));
        } else {
            value = value.longValue();
            expected = 7902L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[38].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[38].stddev + "' != '" + 35 + "'",
                    value.equals(BigInteger.valueOf(35L)));
        } else {
            value = value.longValue();
            expected = 35L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[38].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[38].sv_id.constellation + "' != '" + 156 + "'",
                    value.equals(BigInteger.valueOf(156L)));
        } else {
            value = value.longValue();
            expected = 156L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[38].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[38].sv_id.satId + "' != '" + 102 + "'",
                    value.equals(BigInteger.valueOf(102L)));
        } else {
            value = value.longValue();
            expected = 102L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[39].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[39].residual + "' != '" + -30275 + "'",
                    value.equals(BigInteger.valueOf(-30275L)));
        } else {
            value = value.longValue();
            expected = -30275L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[39].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[39].stddev + "' != '" + 204 + "'",
                    value.equals(BigInteger.valueOf(204L)));
        } else {
            value = value.longValue();
            expected = 204L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[39].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[39].sv_id.constellation + "' != '" + 64 + "'",
                    value.equals(BigInteger.valueOf(64L)));
        } else {
            value = value.longValue();
            expected = 64L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[39].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[39].sv_id.satId + "' != '" + 247 + "'",
                    value.equals(BigInteger.valueOf(247L)));
        } else {
            value = value.longValue();
            expected = 247L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[40].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[40].residual + "' != '" + -8633 + "'",
                    value.equals(BigInteger.valueOf(-8633L)));
        } else {
            value = value.longValue();
            expected = -8633L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[40].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[40].stddev + "' != '" + 222 + "'",
                    value.equals(BigInteger.valueOf(222L)));
        } else {
            value = value.longValue();
            expected = 222L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[40].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[40].sv_id.constellation + "' != '" + 32 + "'",
                    value.equals(BigInteger.valueOf(32L)));
        } else {
            value = value.longValue();
            expected = 32L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[40].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[40].sv_id.satId + "' != '" + 220 + "'",
                    value.equals(BigInteger.valueOf(220L)));
        } else {
            value = value.longValue();
            expected = 220L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[41].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[41].residual + "' != '" + 6403 + "'",
                    value.equals(BigInteger.valueOf(6403L)));
        } else {
            value = value.longValue();
            expected = 6403L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[41].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[41].stddev + "' != '" + 45 + "'",
                    value.equals(BigInteger.valueOf(45L)));
        } else {
            value = value.longValue();
            expected = 45L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[41].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[41].sv_id.constellation + "' != '" + 246 + "'",
                    value.equals(BigInteger.valueOf(246L)));
        } else {
            value = value.longValue();
            expected = 246L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[41].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[41].sv_id.satId + "' != '" + 201 + "'",
                    value.equals(BigInteger.valueOf(201L)));
        } else {
            value = value.longValue();
            expected = 201L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[42].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[42].residual + "' != '" + 22643 + "'",
                    value.equals(BigInteger.valueOf(22643L)));
        } else {
            value = value.longValue();
            expected = 22643L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[42].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[42].stddev + "' != '" + 218 + "'",
                    value.equals(BigInteger.valueOf(218L)));
        } else {
            value = value.longValue();
            expected = 218L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[42].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[42].sv_id.constellation + "' != '" + 239 + "'",
                    value.equals(BigInteger.valueOf(239L)));
        } else {
            value = value.longValue();
            expected = 239L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[42].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[42].sv_id.satId + "' != '" + 251 + "'",
                    value.equals(BigInteger.valueOf(251L)));
        } else {
            value = value.longValue();
            expected = 251L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[43].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[43].residual + "' != '" + 16760 + "'",
                    value.equals(BigInteger.valueOf(16760L)));
        } else {
            value = value.longValue();
            expected = 16760L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[43].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[43].stddev + "' != '" + 175 + "'",
                    value.equals(BigInteger.valueOf(175L)));
        } else {
            value = value.longValue();
            expected = 175L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[43].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[43].sv_id.constellation + "' != '" + 209 + "'",
                    value.equals(BigInteger.valueOf(209L)));
        } else {
            value = value.longValue();
            expected = 209L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[43].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[43].sv_id.satId + "' != '" + 10 + "'",
                    value.equals(BigInteger.valueOf(10L)));
        } else {
            value = value.longValue();
            expected = 10L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[44].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[44].residual + "' != '" + -20951 + "'",
                    value.equals(BigInteger.valueOf(-20951L)));
        } else {
            value = value.longValue();
            expected = -20951L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[44].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[44].stddev + "' != '" + 137 + "'",
                    value.equals(BigInteger.valueOf(137L)));
        } else {
            value = value.longValue();
            expected = 137L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[44].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[44].sv_id.constellation + "' != '" + 194 + "'",
                    value.equals(BigInteger.valueOf(194L)));
        } else {
            value = value.longValue();
            expected = 194L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[44].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[44].sv_id.satId + "' != '" + 131 + "'",
                    value.equals(BigInteger.valueOf(131L)));
        } else {
            value = value.longValue();
            expected = 131L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[45].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[45].residual + "' != '" + -740 + "'",
                    value.equals(BigInteger.valueOf(-740L)));
        } else {
            value = value.longValue();
            expected = -740L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[45].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[45].stddev + "' != '" + 42 + "'",
                    value.equals(BigInteger.valueOf(42L)));
        } else {
            value = value.longValue();
            expected = 42L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[45].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[45].sv_id.constellation + "' != '" + 68 + "'",
                    value.equals(BigInteger.valueOf(68L)));
        } else {
            value = value.longValue();
            expected = 68L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[45].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[45].sv_id.satId + "' != '" + 17 + "'",
                    value.equals(BigInteger.valueOf(17L)));
        } else {
            value = value.longValue();
            expected = 17L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tropo_delay_correction.hydro;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tropo_delay_correction.hydro + "' != '" + -3035 + "'",
                    value.equals(BigInteger.valueOf(-3035L)));
        } else {
            value = value.longValue();
            expected = -3035L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tropo_delay_correction.stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tropo_delay_correction.stddev + "' != '" + 72 + "'",
                    value.equals(BigInteger.valueOf(72L)));
        } else {
            value = value.longValue();
            expected = 72L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tropo_delay_correction.wet;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tropo_delay_correction.wet + "' != '" + 78 + "'",
                    value.equals(BigInteger.valueOf(78L)));
        } else {
            value = value.longValue();
            expected = 78L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
