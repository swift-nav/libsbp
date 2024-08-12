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
// spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrGriddedCorrectionDepA.yaml by generate.py. Do not
// modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.ssr.MsgSsrGriddedCorrectionDepA;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_ssr_MsgSsrGriddedCorrectionDepATest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_ssr_MsgSsrGriddedCorrectionDepATest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 164,
                    (byte) 217,
                    (byte) 44,
                    (byte) 53,
                    (byte) 98,
                    (byte) 93,
                    (byte) 63,
                    (byte) 147,
                    (byte) 104,
                    (byte) 252,
                    (byte) 133,
                    (byte) 245,
                    (byte) 28,
                    (byte) 95,
                    (byte) 100,
                    (byte) 147,
                    (byte) 41,
                    (byte) 33,
                    (byte) 92,
                    (byte) 87,
                    (byte) 25,
                    (byte) 142,
                    (byte) 151,
                    (byte) 74,
                    (byte) 151,
                    (byte) 95,
                    (byte) 94,
                    (byte) 7,
                    (byte) 146,
                    (byte) 237,
                    (byte) 45,
                    (byte) 167,
                    (byte) 86,
                    (byte) 42,
                    (byte) 116,
                    (byte) 224,
                    (byte) 169,
                    (byte) 234,
                    (byte) 220,
                    (byte) 23,
                    (byte) 176,
                    (byte) 18,
                    (byte) 13,
                    (byte) 178,
                    (byte) 79,
                    (byte) 160,
                    (byte) 160,
                    (byte) 110,
                    (byte) 15,
                    (byte) 53,
                    (byte) 206,
                    (byte) 151,
                    (byte) 158,
                    (byte) 22,
                    (byte) 117,
                    (byte) 184,
                    (byte) 48,
                    (byte) 170,
                    (byte) 82,
                    (byte) 40,
                    (byte) 53,
                    (byte) 122,
                    (byte) 69,
                    (byte) 180,
                    (byte) 110,
                    (byte) 38,
                    (byte) 65,
                    (byte) 104,
                    (byte) 244,
                    (byte) 19,
                    (byte) 238,
                    (byte) 227,
                    (byte) 88,
                    (byte) 169,
                    (byte) 164,
                    (byte) 146,
                    (byte) 63,
                    (byte) 37,
                    (byte) 183,
                    (byte) 85,
                    (byte) 71,
                    (byte) 235,
                    (byte) 168,
                    (byte) 114,
                    (byte) 211,
                    (byte) 105,
                    (byte) 221,
                    (byte) 156,
                    (byte) 60,
                    (byte) 18,
                    (byte) 230,
                    (byte) 2,
                    (byte) 142,
                    (byte) 172,
                    (byte) 16,
                    (byte) 39,
                    (byte) 33,
                    (byte) 126,
                    (byte) 106,
                    (byte) 99,
                    (byte) 188,
                    (byte) 234,
                    (byte) 41,
                    (byte) 162,
                    (byte) 197,
                    (byte) 138,
                    (byte) 227,
                    (byte) 80,
                    (byte) 12,
                    (byte) 54,
                    (byte) 67,
                    (byte) 238,
                    (byte) 5,
                    (byte) 93,
                    (byte) 1,
                    (byte) 207,
                    (byte) 129,
                    (byte) 13,
                    (byte) 46,
                    (byte) 115,
                    (byte) 49,
                    (byte) 58,
                    (byte) 185,
                    (byte) 127,
                    (byte) 156,
                    (byte) 200,
                    (byte) 96,
                    (byte) 217,
                    (byte) 202,
                    (byte) 15,
                    (byte) 245,
                    (byte) 55,
                    (byte) 198,
                    (byte) 81,
                    (byte) 218,
                    (byte) 132,
                    (byte) 70,
                    (byte) 73,
                    (byte) 82,
                    (byte) 147,
                    (byte) 26,
                    (byte) 255,
                    (byte) 14,
                    (byte) 134,
                    (byte) 96,
                    (byte) 138,
                    (byte) 55,
                    (byte) 214,
                    (byte) 83,
                    (byte) 156,
                    (byte) 170,
                    (byte) 163,
                    (byte) 79,
                    (byte) 173,
                    (byte) 228,
                    (byte) 115,
                    (byte) 51,
                    (byte) 241,
                    (byte) 107,
                    (byte) 245,
                    (byte) 112,
                    (byte) 168,
                    (byte) 210,
                    (byte) 10,
                    (byte) 5,
                    (byte) 117,
                    (byte) 1,
                    (byte) 57,
                    (byte) 108,
                    (byte) 248,
                    (byte) 212,
                    (byte) 145,
                    (byte) 119,
                    (byte) 226,
                    (byte) 165,
                    (byte) 5,
                    (byte) 141,
                    (byte) 202,
                    (byte) 106,
                    (byte) 0,
                    (byte) 60,
                    (byte) 36,
                    (byte) 61,
                    (byte) 243,
                    (byte) 203,
                    (byte) 216,
                    (byte) 215,
                    (byte) 12,
                    (byte) 137,
                    (byte) 16,
                    (byte) 28,
                    (byte) 247,
                    (byte) 115,
                    (byte) 152,
                    (byte) 181,
                    (byte) 119,
                    (byte) 208,
                    (byte) 228,
                    (byte) 203,
                    (byte) 236,
                    (byte) 34,
                    (byte) 167,
                    (byte) 196,
                    (byte) 32,
                    (byte) 109,
                    (byte) 1,
                    (byte) 17,
                    (byte) 101,
                    (byte) 200,
                    (byte) 25,
                    (byte) 94,
                    (byte) 125,
                    (byte) 168,
                    (byte) 137,
                    (byte) 157,
                    (byte) 4,
                    (byte) 164,
                    (byte) 29,
                    (byte) 31,
                    (byte) 48,
                    (byte) 132,
                    (byte) 72,
                    (byte) 229,
                    (byte) 126,
                    (byte) 186,
                    (byte) 68,
                    (byte) 76,
                    (byte) 133,
                    (byte) 21,
                    (byte) 0,
                    (byte) 180,
                    (byte) 139,
                    (byte) 164,
                    (byte) 148,
                    (byte) 119,
                    (byte) 149,
                    (byte) 214,
                    (byte) 120,
                    (byte) 177,
                    (byte) 201,
                    (byte) 80,
                    (byte) 80,
                    (byte) 105,
                    (byte) 10,
                    (byte) 136,
                    (byte) 118,
                    (byte) 77,
                    (byte) 46,
                    (byte) 233,
                    (byte) 233,
                    (byte) 227,
                    (byte) 11,
                    (byte) 158,
                    (byte) 103,
                };
        SBPMessage sbp = new SBPMessage(0x6a6c, 0x5fa, payload);
        MsgSsrGriddedCorrectionDepA msg = new MsgSsrGriddedCorrectionDepA(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.header.iod_atmo;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.header.iod_atmo + "' != '" + 245 + "'",
                    value.equals(BigInteger.valueOf(245L)));
        } else {
            value = value.longValue();
            expected = 245L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.header.num_msgs;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.header.num_msgs + "' != '" + 37695 + "'",
                    value.equals(BigInteger.valueOf(37695L)));
        } else {
            value = value.longValue();
            expected = 37695L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.header.seq_num;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.header.seq_num + "' != '" + 64616 + "'",
                    value.equals(BigInteger.valueOf(64616L)));
        } else {
            value = value.longValue();
            expected = 64616L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.header.time.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.header.time.tow + "' != '" + 892131748 + "'",
                    value.equals(BigInteger.valueOf(892131748L)));
        } else {
            value = value.longValue();
            expected = 892131748L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.header.time.wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.header.time.wn + "' != '" + 23906 + "'",
                    value.equals(BigInteger.valueOf(23906L)));
        } else {
            value = value.longValue();
            expected = 23906L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.header.tropo_quality_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.header.tropo_quality_indicator + "' != '" + 28 + "'",
                    value.equals(BigInteger.valueOf(28L)));
        } else {
            value = value.longValue();
            expected = 28L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.header.update_interval;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.header.update_interval + "' != '" + 133 + "'",
                    value.equals(BigInteger.valueOf(133L)));
        } else {
            value = value.longValue();
            expected = 133L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.index;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.index + "' != '" + 25695 + "'",
                    value.equals(BigInteger.valueOf(25695L)));
        } else {
            value = value.longValue();
            expected = 25695L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[0].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[0].residual + "' != '" + -26738 + "'",
                    value.equals(BigInteger.valueOf(-26738L)));
        } else {
            value = value.longValue();
            expected = -26738L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[0].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[0].stddev + "' != '" + 74 + "'",
                    value.equals(BigInteger.valueOf(74L)));
        } else {
            value = value.longValue();
            expected = 74L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[0].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[0].sv_id.constellation + "' != '" + 25 + "'",
                    value.equals(BigInteger.valueOf(25L)));
        } else {
            value = value.longValue();
            expected = 25L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[0].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[0].sv_id.satId + "' != '" + 87 + "'",
                    value.equals(BigInteger.valueOf(87L)));
        } else {
            value = value.longValue();
            expected = 87L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[1].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[1].residual + "' != '" + 1886 + "'",
                    value.equals(BigInteger.valueOf(1886L)));
        } else {
            value = value.longValue();
            expected = 1886L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[1].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[1].stddev + "' != '" + 146 + "'",
                    value.equals(BigInteger.valueOf(146L)));
        } else {
            value = value.longValue();
            expected = 146L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[1].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[1].sv_id.constellation + "' != '" + 95 + "'",
                    value.equals(BigInteger.valueOf(95L)));
        } else {
            value = value.longValue();
            expected = 95L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[1].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[1].sv_id.satId + "' != '" + 151 + "'",
                    value.equals(BigInteger.valueOf(151L)));
        } else {
            value = value.longValue();
            expected = 151L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[2].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[2].residual + "' != '" + 22183 + "'",
                    value.equals(BigInteger.valueOf(22183L)));
        } else {
            value = value.longValue();
            expected = 22183L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[2].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[2].stddev + "' != '" + 42 + "'",
                    value.equals(BigInteger.valueOf(42L)));
        } else {
            value = value.longValue();
            expected = 42L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[2].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[2].sv_id.constellation + "' != '" + 45 + "'",
                    value.equals(BigInteger.valueOf(45L)));
        } else {
            value = value.longValue();
            expected = 45L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[2].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[2].sv_id.satId + "' != '" + 237 + "'",
                    value.equals(BigInteger.valueOf(237L)));
        } else {
            value = value.longValue();
            expected = 237L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[3].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[3].residual + "' != '" + -5463 + "'",
                    value.equals(BigInteger.valueOf(-5463L)));
        } else {
            value = value.longValue();
            expected = -5463L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[3].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[3].stddev + "' != '" + 220 + "'",
                    value.equals(BigInteger.valueOf(220L)));
        } else {
            value = value.longValue();
            expected = 220L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[3].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[3].sv_id.constellation + "' != '" + 224 + "'",
                    value.equals(BigInteger.valueOf(224L)));
        } else {
            value = value.longValue();
            expected = 224L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[3].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[3].sv_id.satId + "' != '" + 116 + "'",
                    value.equals(BigInteger.valueOf(116L)));
        } else {
            value = value.longValue();
            expected = 116L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[4].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[4].residual + "' != '" + 3346 + "'",
                    value.equals(BigInteger.valueOf(3346L)));
        } else {
            value = value.longValue();
            expected = 3346L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[4].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[4].stddev + "' != '" + 178 + "'",
                    value.equals(BigInteger.valueOf(178L)));
        } else {
            value = value.longValue();
            expected = 178L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[4].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[4].sv_id.constellation + "' != '" + 176 + "'",
                    value.equals(BigInteger.valueOf(176L)));
        } else {
            value = value.longValue();
            expected = 176L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[4].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[4].sv_id.satId + "' != '" + 23 + "'",
                    value.equals(BigInteger.valueOf(23L)));
        } else {
            value = value.longValue();
            expected = 23L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[5].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[5].residual + "' != '" + 28320 + "'",
                    value.equals(BigInteger.valueOf(28320L)));
        } else {
            value = value.longValue();
            expected = 28320L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[5].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[5].stddev + "' != '" + 15 + "'",
                    value.equals(BigInteger.valueOf(15L)));
        } else {
            value = value.longValue();
            expected = 15L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[5].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[5].sv_id.constellation + "' != '" + 160 + "'",
                    value.equals(BigInteger.valueOf(160L)));
        } else {
            value = value.longValue();
            expected = 160L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[5].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[5].sv_id.satId + "' != '" + 79 + "'",
                    value.equals(BigInteger.valueOf(79L)));
        } else {
            value = value.longValue();
            expected = 79L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[6].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[6].residual + "' != '" + -24937 + "'",
                    value.equals(BigInteger.valueOf(-24937L)));
        } else {
            value = value.longValue();
            expected = -24937L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[6].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[6].stddev + "' != '" + 22 + "'",
                    value.equals(BigInteger.valueOf(22L)));
        } else {
            value = value.longValue();
            expected = 22L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[6].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[6].sv_id.constellation + "' != '" + 206 + "'",
                    value.equals(BigInteger.valueOf(206L)));
        } else {
            value = value.longValue();
            expected = 206L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[6].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[6].sv_id.satId + "' != '" + 53 + "'",
                    value.equals(BigInteger.valueOf(53L)));
        } else {
            value = value.longValue();
            expected = 53L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[7].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[7].residual + "' != '" + -21968 + "'",
                    value.equals(BigInteger.valueOf(-21968L)));
        } else {
            value = value.longValue();
            expected = -21968L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[7].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[7].stddev + "' != '" + 82 + "'",
                    value.equals(BigInteger.valueOf(82L)));
        } else {
            value = value.longValue();
            expected = 82L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[7].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[7].sv_id.constellation + "' != '" + 184 + "'",
                    value.equals(BigInteger.valueOf(184L)));
        } else {
            value = value.longValue();
            expected = 184L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[7].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[7].sv_id.satId + "' != '" + 117 + "'",
                    value.equals(BigInteger.valueOf(117L)));
        } else {
            value = value.longValue();
            expected = 117L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[8].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[8].residual + "' != '" + 17786 + "'",
                    value.equals(BigInteger.valueOf(17786L)));
        } else {
            value = value.longValue();
            expected = 17786L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[8].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[8].stddev + "' != '" + 180 + "'",
                    value.equals(BigInteger.valueOf(180L)));
        } else {
            value = value.longValue();
            expected = 180L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[8].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[8].sv_id.constellation + "' != '" + 53 + "'",
                    value.equals(BigInteger.valueOf(53L)));
        } else {
            value = value.longValue();
            expected = 53L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[8].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[8].sv_id.satId + "' != '" + 40 + "'",
                    value.equals(BigInteger.valueOf(40L)));
        } else {
            value = value.longValue();
            expected = 40L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[9].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[9].residual + "' != '" + 26689 + "'",
                    value.equals(BigInteger.valueOf(26689L)));
        } else {
            value = value.longValue();
            expected = 26689L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[9].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[9].stddev + "' != '" + 244 + "'",
                    value.equals(BigInteger.valueOf(244L)));
        } else {
            value = value.longValue();
            expected = 244L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[9].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[9].sv_id.constellation + "' != '" + 38 + "'",
                    value.equals(BigInteger.valueOf(38L)));
        } else {
            value = value.longValue();
            expected = 38L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[9].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[9].sv_id.satId + "' != '" + 110 + "'",
                    value.equals(BigInteger.valueOf(110L)));
        } else {
            value = value.longValue();
            expected = 110L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[10].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[10].residual + "' != '" + 22755 + "'",
                    value.equals(BigInteger.valueOf(22755L)));
        } else {
            value = value.longValue();
            expected = 22755L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[10].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[10].stddev + "' != '" + 169 + "'",
                    value.equals(BigInteger.valueOf(169L)));
        } else {
            value = value.longValue();
            expected = 169L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[10].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[10].sv_id.constellation + "' != '" + 238 + "'",
                    value.equals(BigInteger.valueOf(238L)));
        } else {
            value = value.longValue();
            expected = 238L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[10].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[10].sv_id.satId + "' != '" + 19 + "'",
                    value.equals(BigInteger.valueOf(19L)));
        } else {
            value = value.longValue();
            expected = 19L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[11].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[11].residual + "' != '" + 9535 + "'",
                    value.equals(BigInteger.valueOf(9535L)));
        } else {
            value = value.longValue();
            expected = 9535L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[11].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[11].stddev + "' != '" + 183 + "'",
                    value.equals(BigInteger.valueOf(183L)));
        } else {
            value = value.longValue();
            expected = 183L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[11].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[11].sv_id.constellation + "' != '" + 146 + "'",
                    value.equals(BigInteger.valueOf(146L)));
        } else {
            value = value.longValue();
            expected = 146L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[11].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[11].sv_id.satId + "' != '" + 164 + "'",
                    value.equals(BigInteger.valueOf(164L)));
        } else {
            value = value.longValue();
            expected = 164L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[12].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[12].residual + "' != '" + -22293 + "'",
                    value.equals(BigInteger.valueOf(-22293L)));
        } else {
            value = value.longValue();
            expected = -22293L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[12].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[12].stddev + "' != '" + 114 + "'",
                    value.equals(BigInteger.valueOf(114L)));
        } else {
            value = value.longValue();
            expected = 114L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[12].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[12].sv_id.constellation + "' != '" + 71 + "'",
                    value.equals(BigInteger.valueOf(71L)));
        } else {
            value = value.longValue();
            expected = 71L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[12].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[12].sv_id.satId + "' != '" + 85 + "'",
                    value.equals(BigInteger.valueOf(85L)));
        } else {
            value = value.longValue();
            expected = 85L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[13].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[13].residual + "' != '" + -25379 + "'",
                    value.equals(BigInteger.valueOf(-25379L)));
        } else {
            value = value.longValue();
            expected = -25379L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[13].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[13].stddev + "' != '" + 60 + "'",
                    value.equals(BigInteger.valueOf(60L)));
        } else {
            value = value.longValue();
            expected = 60L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[13].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[13].sv_id.constellation + "' != '" + 105 + "'",
                    value.equals(BigInteger.valueOf(105L)));
        } else {
            value = value.longValue();
            expected = 105L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[13].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[13].sv_id.satId + "' != '" + 211 + "'",
                    value.equals(BigInteger.valueOf(211L)));
        } else {
            value = value.longValue();
            expected = 211L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[14].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[14].residual + "' != '" + -29182 + "'",
                    value.equals(BigInteger.valueOf(-29182L)));
        } else {
            value = value.longValue();
            expected = -29182L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[14].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[14].stddev + "' != '" + 172 + "'",
                    value.equals(BigInteger.valueOf(172L)));
        } else {
            value = value.longValue();
            expected = 172L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[14].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[14].sv_id.constellation + "' != '" + 230 + "'",
                    value.equals(BigInteger.valueOf(230L)));
        } else {
            value = value.longValue();
            expected = 230L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[14].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[14].sv_id.satId + "' != '" + 18 + "'",
                    value.equals(BigInteger.valueOf(18L)));
        } else {
            value = value.longValue();
            expected = 18L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[15].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[15].residual + "' != '" + 32289 + "'",
                    value.equals(BigInteger.valueOf(32289L)));
        } else {
            value = value.longValue();
            expected = 32289L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[15].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[15].stddev + "' != '" + 106 + "'",
                    value.equals(BigInteger.valueOf(106L)));
        } else {
            value = value.longValue();
            expected = 106L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[15].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[15].sv_id.constellation + "' != '" + 39 + "'",
                    value.equals(BigInteger.valueOf(39L)));
        } else {
            value = value.longValue();
            expected = 39L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[15].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[15].sv_id.satId + "' != '" + 16 + "'",
                    value.equals(BigInteger.valueOf(16L)));
        } else {
            value = value.longValue();
            expected = 16L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[16].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[16].residual + "' != '" + 10730 + "'",
                    value.equals(BigInteger.valueOf(10730L)));
        } else {
            value = value.longValue();
            expected = 10730L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[16].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[16].stddev + "' != '" + 162 + "'",
                    value.equals(BigInteger.valueOf(162L)));
        } else {
            value = value.longValue();
            expected = 162L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[16].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[16].sv_id.constellation + "' != '" + 188 + "'",
                    value.equals(BigInteger.valueOf(188L)));
        } else {
            value = value.longValue();
            expected = 188L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[16].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[16].sv_id.satId + "' != '" + 99 + "'",
                    value.equals(BigInteger.valueOf(99L)));
        } else {
            value = value.longValue();
            expected = 99L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[17].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[17].residual + "' != '" + 20707 + "'",
                    value.equals(BigInteger.valueOf(20707L)));
        } else {
            value = value.longValue();
            expected = 20707L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[17].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[17].stddev + "' != '" + 12 + "'",
                    value.equals(BigInteger.valueOf(12L)));
        } else {
            value = value.longValue();
            expected = 12L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[17].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[17].sv_id.constellation + "' != '" + 138 + "'",
                    value.equals(BigInteger.valueOf(138L)));
        } else {
            value = value.longValue();
            expected = 138L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[17].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[17].sv_id.satId + "' != '" + 197 + "'",
                    value.equals(BigInteger.valueOf(197L)));
        } else {
            value = value.longValue();
            expected = 197L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[18].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[18].residual + "' != '" + 1518 + "'",
                    value.equals(BigInteger.valueOf(1518L)));
        } else {
            value = value.longValue();
            expected = 1518L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[18].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[18].stddev + "' != '" + 93 + "'",
                    value.equals(BigInteger.valueOf(93L)));
        } else {
            value = value.longValue();
            expected = 93L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[18].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[18].sv_id.constellation + "' != '" + 67 + "'",
                    value.equals(BigInteger.valueOf(67L)));
        } else {
            value = value.longValue();
            expected = 67L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[18].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[18].sv_id.satId + "' != '" + 54 + "'",
                    value.equals(BigInteger.valueOf(54L)));
        } else {
            value = value.longValue();
            expected = 54L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[19].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[19].residual + "' != '" + 3457 + "'",
                    value.equals(BigInteger.valueOf(3457L)));
        } else {
            value = value.longValue();
            expected = 3457L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[19].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[19].stddev + "' != '" + 46 + "'",
                    value.equals(BigInteger.valueOf(46L)));
        } else {
            value = value.longValue();
            expected = 46L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[19].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[19].sv_id.constellation + "' != '" + 207 + "'",
                    value.equals(BigInteger.valueOf(207L)));
        } else {
            value = value.longValue();
            expected = 207L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[19].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[19].sv_id.satId + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[20].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[20].residual + "' != '" + -18118 + "'",
                    value.equals(BigInteger.valueOf(-18118L)));
        } else {
            value = value.longValue();
            expected = -18118L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[20].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[20].stddev + "' != '" + 127 + "'",
                    value.equals(BigInteger.valueOf(127L)));
        } else {
            value = value.longValue();
            expected = 127L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[20].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[20].sv_id.constellation + "' != '" + 49 + "'",
                    value.equals(BigInteger.valueOf(49L)));
        } else {
            value = value.longValue();
            expected = 49L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[20].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[20].sv_id.satId + "' != '" + 115 + "'",
                    value.equals(BigInteger.valueOf(115L)));
        } else {
            value = value.longValue();
            expected = 115L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[21].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[21].residual + "' != '" + -9888 + "'",
                    value.equals(BigInteger.valueOf(-9888L)));
        } else {
            value = value.longValue();
            expected = -9888L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[21].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[21].stddev + "' != '" + 202 + "'",
                    value.equals(BigInteger.valueOf(202L)));
        } else {
            value = value.longValue();
            expected = 202L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[21].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[21].sv_id.constellation + "' != '" + 200 + "'",
                    value.equals(BigInteger.valueOf(200L)));
        } else {
            value = value.longValue();
            expected = 200L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[21].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[21].sv_id.satId + "' != '" + 156 + "'",
                    value.equals(BigInteger.valueOf(156L)));
        } else {
            value = value.longValue();
            expected = 156L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[22].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[22].residual + "' != '" + -14793 + "'",
                    value.equals(BigInteger.valueOf(-14793L)));
        } else {
            value = value.longValue();
            expected = -14793L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[22].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[22].stddev + "' != '" + 81 + "'",
                    value.equals(BigInteger.valueOf(81L)));
        } else {
            value = value.longValue();
            expected = 81L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[22].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[22].sv_id.constellation + "' != '" + 245 + "'",
                    value.equals(BigInteger.valueOf(245L)));
        } else {
            value = value.longValue();
            expected = 245L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[22].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[22].sv_id.satId + "' != '" + 15 + "'",
                    value.equals(BigInteger.valueOf(15L)));
        } else {
            value = value.longValue();
            expected = 15L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[23].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[23].residual + "' != '" + 18758 + "'",
                    value.equals(BigInteger.valueOf(18758L)));
        } else {
            value = value.longValue();
            expected = 18758L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[23].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[23].stddev + "' != '" + 82 + "'",
                    value.equals(BigInteger.valueOf(82L)));
        } else {
            value = value.longValue();
            expected = 82L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[23].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[23].sv_id.constellation + "' != '" + 132 + "'",
                    value.equals(BigInteger.valueOf(132L)));
        } else {
            value = value.longValue();
            expected = 132L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[23].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[23].sv_id.satId + "' != '" + 218 + "'",
                    value.equals(BigInteger.valueOf(218L)));
        } else {
            value = value.longValue();
            expected = 218L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[24].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[24].residual + "' != '" + 3839 + "'",
                    value.equals(BigInteger.valueOf(3839L)));
        } else {
            value = value.longValue();
            expected = 3839L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[24].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[24].stddev + "' != '" + 134 + "'",
                    value.equals(BigInteger.valueOf(134L)));
        } else {
            value = value.longValue();
            expected = 134L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[24].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[24].sv_id.constellation + "' != '" + 26 + "'",
                    value.equals(BigInteger.valueOf(26L)));
        } else {
            value = value.longValue();
            expected = 26L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[24].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[24].sv_id.satId + "' != '" + 147 + "'",
                    value.equals(BigInteger.valueOf(147L)));
        } else {
            value = value.longValue();
            expected = 147L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[25].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[25].residual + "' != '" + -10697 + "'",
                    value.equals(BigInteger.valueOf(-10697L)));
        } else {
            value = value.longValue();
            expected = -10697L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[25].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[25].stddev + "' != '" + 83 + "'",
                    value.equals(BigInteger.valueOf(83L)));
        } else {
            value = value.longValue();
            expected = 83L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[25].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[25].sv_id.constellation + "' != '" + 138 + "'",
                    value.equals(BigInteger.valueOf(138L)));
        } else {
            value = value.longValue();
            expected = 138L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[25].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[25].sv_id.satId + "' != '" + 96 + "'",
                    value.equals(BigInteger.valueOf(96L)));
        } else {
            value = value.longValue();
            expected = 96L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[26].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[26].residual + "' != '" + 20387 + "'",
                    value.equals(BigInteger.valueOf(20387L)));
        } else {
            value = value.longValue();
            expected = 20387L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[26].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[26].stddev + "' != '" + 173 + "'",
                    value.equals(BigInteger.valueOf(173L)));
        } else {
            value = value.longValue();
            expected = 173L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[26].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[26].sv_id.constellation + "' != '" + 170 + "'",
                    value.equals(BigInteger.valueOf(170L)));
        } else {
            value = value.longValue();
            expected = 170L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[26].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[26].sv_id.satId + "' != '" + 156 + "'",
                    value.equals(BigInteger.valueOf(156L)));
        } else {
            value = value.longValue();
            expected = 156L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[27].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[27].residual + "' != '" + -3789 + "'",
                    value.equals(BigInteger.valueOf(-3789L)));
        } else {
            value = value.longValue();
            expected = -3789L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[27].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[27].stddev + "' != '" + 107 + "'",
                    value.equals(BigInteger.valueOf(107L)));
        } else {
            value = value.longValue();
            expected = 107L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[27].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[27].sv_id.constellation + "' != '" + 115 + "'",
                    value.equals(BigInteger.valueOf(115L)));
        } else {
            value = value.longValue();
            expected = 115L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[27].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[27].sv_id.satId + "' != '" + 228 + "'",
                    value.equals(BigInteger.valueOf(228L)));
        } else {
            value = value.longValue();
            expected = 228L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[28].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[28].residual + "' != '" + -11608 + "'",
                    value.equals(BigInteger.valueOf(-11608L)));
        } else {
            value = value.longValue();
            expected = -11608L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[28].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[28].stddev + "' != '" + 10 + "'",
                    value.equals(BigInteger.valueOf(10L)));
        } else {
            value = value.longValue();
            expected = 10L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[28].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[28].sv_id.constellation + "' != '" + 112 + "'",
                    value.equals(BigInteger.valueOf(112L)));
        } else {
            value = value.longValue();
            expected = 112L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[28].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[28].sv_id.satId + "' != '" + 245 + "'",
                    value.equals(BigInteger.valueOf(245L)));
        } else {
            value = value.longValue();
            expected = 245L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[29].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[29].residual + "' != '" + 14593 + "'",
                    value.equals(BigInteger.valueOf(14593L)));
        } else {
            value = value.longValue();
            expected = 14593L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[29].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[29].stddev + "' != '" + 108 + "'",
                    value.equals(BigInteger.valueOf(108L)));
        } else {
            value = value.longValue();
            expected = 108L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[29].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[29].sv_id.constellation + "' != '" + 117 + "'",
                    value.equals(BigInteger.valueOf(117L)));
        } else {
            value = value.longValue();
            expected = 117L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[29].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[29].sv_id.satId + "' != '" + 5 + "'",
                    value.equals(BigInteger.valueOf(5L)));
        } else {
            value = value.longValue();
            expected = 5L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[30].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[30].residual + "' != '" + 30609 + "'",
                    value.equals(BigInteger.valueOf(30609L)));
        } else {
            value = value.longValue();
            expected = 30609L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[30].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[30].stddev + "' != '" + 226 + "'",
                    value.equals(BigInteger.valueOf(226L)));
        } else {
            value = value.longValue();
            expected = 226L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[30].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[30].sv_id.constellation + "' != '" + 212 + "'",
                    value.equals(BigInteger.valueOf(212L)));
        } else {
            value = value.longValue();
            expected = 212L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[30].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[30].sv_id.satId + "' != '" + 248 + "'",
                    value.equals(BigInteger.valueOf(248L)));
        } else {
            value = value.longValue();
            expected = 248L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[31].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[31].residual + "' != '" + -13683 + "'",
                    value.equals(BigInteger.valueOf(-13683L)));
        } else {
            value = value.longValue();
            expected = -13683L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[31].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[31].stddev + "' != '" + 106 + "'",
                    value.equals(BigInteger.valueOf(106L)));
        } else {
            value = value.longValue();
            expected = 106L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[31].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[31].sv_id.constellation + "' != '" + 5 + "'",
                    value.equals(BigInteger.valueOf(5L)));
        } else {
            value = value.longValue();
            expected = 5L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[31].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[31].sv_id.satId + "' != '" + 165 + "'",
                    value.equals(BigInteger.valueOf(165L)));
        } else {
            value = value.longValue();
            expected = 165L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[32].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[32].residual + "' != '" + 15652 + "'",
                    value.equals(BigInteger.valueOf(15652L)));
        } else {
            value = value.longValue();
            expected = 15652L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[32].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[32].stddev + "' != '" + 243 + "'",
                    value.equals(BigInteger.valueOf(243L)));
        } else {
            value = value.longValue();
            expected = 243L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[32].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[32].sv_id.constellation + "' != '" + 60 + "'",
                    value.equals(BigInteger.valueOf(60L)));
        } else {
            value = value.longValue();
            expected = 60L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[32].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[32].sv_id.satId + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[33].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[33].residual + "' != '" + 3287 + "'",
                    value.equals(BigInteger.valueOf(3287L)));
        } else {
            value = value.longValue();
            expected = 3287L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[33].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[33].stddev + "' != '" + 137 + "'",
                    value.equals(BigInteger.valueOf(137L)));
        } else {
            value = value.longValue();
            expected = 137L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[33].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[33].sv_id.constellation + "' != '" + 216 + "'",
                    value.equals(BigInteger.valueOf(216L)));
        } else {
            value = value.longValue();
            expected = 216L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[33].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[33].sv_id.satId + "' != '" + 203 + "'",
                    value.equals(BigInteger.valueOf(203L)));
        } else {
            value = value.longValue();
            expected = 203L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[34].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[34].residual + "' != '" + 29687 + "'",
                    value.equals(BigInteger.valueOf(29687L)));
        } else {
            value = value.longValue();
            expected = 29687L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[34].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[34].stddev + "' != '" + 152 + "'",
                    value.equals(BigInteger.valueOf(152L)));
        } else {
            value = value.longValue();
            expected = 152L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[34].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[34].sv_id.constellation + "' != '" + 28 + "'",
                    value.equals(BigInteger.valueOf(28L)));
        } else {
            value = value.longValue();
            expected = 28L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[34].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[34].sv_id.satId + "' != '" + 16 + "'",
                    value.equals(BigInteger.valueOf(16L)));
        } else {
            value = value.longValue();
            expected = 16L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[35].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[35].residual + "' != '" + -6960 + "'",
                    value.equals(BigInteger.valueOf(-6960L)));
        } else {
            value = value.longValue();
            expected = -6960L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[35].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[35].stddev + "' != '" + 203 + "'",
                    value.equals(BigInteger.valueOf(203L)));
        } else {
            value = value.longValue();
            expected = 203L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[35].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[35].sv_id.constellation + "' != '" + 119 + "'",
                    value.equals(BigInteger.valueOf(119L)));
        } else {
            value = value.longValue();
            expected = 119L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[35].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[35].sv_id.satId + "' != '" + 181 + "'",
                    value.equals(BigInteger.valueOf(181L)));
        } else {
            value = value.longValue();
            expected = 181L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[36].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[36].residual + "' != '" + -15193 + "'",
                    value.equals(BigInteger.valueOf(-15193L)));
        } else {
            value = value.longValue();
            expected = -15193L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[36].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[36].stddev + "' != '" + 32 + "'",
                    value.equals(BigInteger.valueOf(32L)));
        } else {
            value = value.longValue();
            expected = 32L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[36].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[36].sv_id.constellation + "' != '" + 34 + "'",
                    value.equals(BigInteger.valueOf(34L)));
        } else {
            value = value.longValue();
            expected = 34L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[36].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[36].sv_id.satId + "' != '" + 236 + "'",
                    value.equals(BigInteger.valueOf(236L)));
        } else {
            value = value.longValue();
            expected = 236L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[37].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[37].residual + "' != '" + 25873 + "'",
                    value.equals(BigInteger.valueOf(25873L)));
        } else {
            value = value.longValue();
            expected = 25873L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[37].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[37].stddev + "' != '" + 200 + "'",
                    value.equals(BigInteger.valueOf(200L)));
        } else {
            value = value.longValue();
            expected = 200L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[37].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[37].sv_id.constellation + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[37].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[37].sv_id.satId + "' != '" + 109 + "'",
                    value.equals(BigInteger.valueOf(109L)));
        } else {
            value = value.longValue();
            expected = 109L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[38].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[38].residual + "' != '" + -22403 + "'",
                    value.equals(BigInteger.valueOf(-22403L)));
        } else {
            value = value.longValue();
            expected = -22403L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[38].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[38].stddev + "' != '" + 137 + "'",
                    value.equals(BigInteger.valueOf(137L)));
        } else {
            value = value.longValue();
            expected = 137L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[38].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[38].sv_id.constellation + "' != '" + 94 + "'",
                    value.equals(BigInteger.valueOf(94L)));
        } else {
            value = value.longValue();
            expected = 94L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[38].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[38].sv_id.satId + "' != '" + 25 + "'",
                    value.equals(BigInteger.valueOf(25L)));
        } else {
            value = value.longValue();
            expected = 25L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[39].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[39].residual + "' != '" + 7588 + "'",
                    value.equals(BigInteger.valueOf(7588L)));
        } else {
            value = value.longValue();
            expected = 7588L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[39].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[39].stddev + "' != '" + 31 + "'",
                    value.equals(BigInteger.valueOf(31L)));
        } else {
            value = value.longValue();
            expected = 31L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[39].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[39].sv_id.constellation + "' != '" + 4 + "'",
                    value.equals(BigInteger.valueOf(4L)));
        } else {
            value = value.longValue();
            expected = 4L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[39].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[39].sv_id.satId + "' != '" + 157 + "'",
                    value.equals(BigInteger.valueOf(157L)));
        } else {
            value = value.longValue();
            expected = 157L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[40].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[40].residual + "' != '" + -6840 + "'",
                    value.equals(BigInteger.valueOf(-6840L)));
        } else {
            value = value.longValue();
            expected = -6840L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[40].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[40].stddev + "' != '" + 126 + "'",
                    value.equals(BigInteger.valueOf(126L)));
        } else {
            value = value.longValue();
            expected = 126L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[40].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[40].sv_id.constellation + "' != '" + 132 + "'",
                    value.equals(BigInteger.valueOf(132L)));
        } else {
            value = value.longValue();
            expected = 132L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[40].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[40].sv_id.satId + "' != '" + 48 + "'",
                    value.equals(BigInteger.valueOf(48L)));
        } else {
            value = value.longValue();
            expected = 48L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[41].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[41].residual + "' != '" + -31412 + "'",
                    value.equals(BigInteger.valueOf(-31412L)));
        } else {
            value = value.longValue();
            expected = -31412L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[41].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[41].stddev + "' != '" + 21 + "'",
                    value.equals(BigInteger.valueOf(21L)));
        } else {
            value = value.longValue();
            expected = 21L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[41].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[41].sv_id.constellation + "' != '" + 68 + "'",
                    value.equals(BigInteger.valueOf(68L)));
        } else {
            value = value.longValue();
            expected = 68L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[41].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[41].sv_id.satId + "' != '" + 186 + "'",
                    value.equals(BigInteger.valueOf(186L)));
        } else {
            value = value.longValue();
            expected = 186L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[42].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[42].residual + "' != '" + -23413 + "'",
                    value.equals(BigInteger.valueOf(-23413L)));
        } else {
            value = value.longValue();
            expected = -23413L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[42].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[42].stddev + "' != '" + 148 + "'",
                    value.equals(BigInteger.valueOf(148L)));
        } else {
            value = value.longValue();
            expected = 148L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[42].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[42].sv_id.constellation + "' != '" + 180 + "'",
                    value.equals(BigInteger.valueOf(180L)));
        } else {
            value = value.longValue();
            expected = 180L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[42].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[42].sv_id.satId + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[43].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[43].residual + "' != '" + 30934 + "'",
                    value.equals(BigInteger.valueOf(30934L)));
        } else {
            value = value.longValue();
            expected = 30934L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[43].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[43].stddev + "' != '" + 177 + "'",
                    value.equals(BigInteger.valueOf(177L)));
        } else {
            value = value.longValue();
            expected = 177L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[43].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[43].sv_id.constellation + "' != '" + 149 + "'",
                    value.equals(BigInteger.valueOf(149L)));
        } else {
            value = value.longValue();
            expected = 149L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[43].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[43].sv_id.satId + "' != '" + 119 + "'",
                    value.equals(BigInteger.valueOf(119L)));
        } else {
            value = value.longValue();
            expected = 119L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[44].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[44].residual + "' != '" + 26960 + "'",
                    value.equals(BigInteger.valueOf(26960L)));
        } else {
            value = value.longValue();
            expected = 26960L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[44].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[44].stddev + "' != '" + 10 + "'",
                    value.equals(BigInteger.valueOf(10L)));
        } else {
            value = value.longValue();
            expected = 10L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[44].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[44].sv_id.constellation + "' != '" + 80 + "'",
                    value.equals(BigInteger.valueOf(80L)));
        } else {
            value = value.longValue();
            expected = 80L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[44].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[44].sv_id.satId + "' != '" + 201 + "'",
                    value.equals(BigInteger.valueOf(201L)));
        } else {
            value = value.longValue();
            expected = 201L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[45].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[45].residual + "' != '" + 11853 + "'",
                    value.equals(BigInteger.valueOf(11853L)));
        } else {
            value = value.longValue();
            expected = 11853L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[45].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[45].stddev + "' != '" + 233 + "'",
                    value.equals(BigInteger.valueOf(233L)));
        } else {
            value = value.longValue();
            expected = 233L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[45].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[45].sv_id.constellation + "' != '" + 118 + "'",
                    value.equals(BigInteger.valueOf(118L)));
        } else {
            value = value.longValue();
            expected = 118L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[45].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[45].sv_id.satId + "' != '" + 136 + "'",
                    value.equals(BigInteger.valueOf(136L)));
        } else {
            value = value.longValue();
            expected = 136L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[46].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[46].residual + "' != '" + -25077 + "'",
                    value.equals(BigInteger.valueOf(-25077L)));
        } else {
            value = value.longValue();
            expected = -25077L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[46].stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[46].stddev + "' != '" + 103 + "'",
                    value.equals(BigInteger.valueOf(103L)));
        } else {
            value = value.longValue();
            expected = 103L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[46].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[46].sv_id.constellation + "' != '" + 227 + "'",
                    value.equals(BigInteger.valueOf(227L)));
        } else {
            value = value.longValue();
            expected = 227L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[46].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[46].sv_id.satId + "' != '" + 233 + "'",
                    value.equals(BigInteger.valueOf(233L)));
        } else {
            value = value.longValue();
            expected = 233L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tropo_delay_correction.hydro;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tropo_delay_correction.hydro + "' != '" + 10643 + "'",
                    value.equals(BigInteger.valueOf(10643L)));
        } else {
            value = value.longValue();
            expected = 10643L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tropo_delay_correction.stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tropo_delay_correction.stddev + "' != '" + 92 + "'",
                    value.equals(BigInteger.valueOf(92L)));
        } else {
            value = value.longValue();
            expected = 92L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tropo_delay_correction.wet;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tropo_delay_correction.wet + "' != '" + 33 + "'",
                    value.equals(BigInteger.valueOf(33L)));
        } else {
            value = value.longValue();
            expected = 33L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
