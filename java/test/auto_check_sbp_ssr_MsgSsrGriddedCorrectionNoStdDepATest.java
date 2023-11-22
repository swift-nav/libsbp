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
// spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrGriddedCorrectionNoStdDepA.yaml by generate.py. Do
// not modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.ssr.MsgSsrGriddedCorrectionNoStdDepA;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_ssr_MsgSsrGriddedCorrectionNoStdDepATest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format(
                    "%n%s%n", "auto_check_sbp_ssr_MsgSsrGriddedCorrectionNoStdDepATest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 179,
                    (byte) 240,
                    (byte) 33,
                    (byte) 169,
                    (byte) 236,
                    (byte) 34,
                    (byte) 117,
                    (byte) 245,
                    (byte) 67,
                    (byte) 248,
                    (byte) 233,
                    (byte) 236,
                    (byte) 230,
                    (byte) 230,
                    (byte) 103,
                    (byte) 122,
                    (byte) 63,
                    (byte) 101,
                    (byte) 231,
                    (byte) 157,
                    (byte) 115,
                    (byte) 162,
                    (byte) 197,
                    (byte) 146,
                    (byte) 35,
                    (byte) 107,
                    (byte) 222,
                    (byte) 109,
                    (byte) 52,
                    (byte) 41,
                    (byte) 86,
                    (byte) 12,
                    (byte) 237,
                    (byte) 184,
                    (byte) 65,
                    (byte) 204,
                    (byte) 137,
                    (byte) 148,
                    (byte) 171,
                    (byte) 183,
                    (byte) 11,
                    (byte) 0,
                    (byte) 180,
                    (byte) 203,
                    (byte) 172,
                    (byte) 53,
                    (byte) 196,
                    (byte) 85,
                    (byte) 186,
                    (byte) 115,
                    (byte) 203,
                    (byte) 92,
                    (byte) 166,
                    (byte) 30,
                    (byte) 42,
                    (byte) 13,
                    (byte) 200,
                    (byte) 71,
                    (byte) 98,
                    (byte) 137,
                    (byte) 219,
                    (byte) 160,
                    (byte) 95,
                    (byte) 216,
                    (byte) 95,
                    (byte) 250,
                    (byte) 99,
                    (byte) 196,
                    (byte) 92,
                    (byte) 214,
                    (byte) 159,
                    (byte) 253,
                    (byte) 195,
                    (byte) 222,
                    (byte) 233,
                    (byte) 146,
                    (byte) 233,
                    (byte) 63,
                    (byte) 76,
                    (byte) 24,
                    (byte) 106,
                    (byte) 40,
                    (byte) 253,
                    (byte) 65,
                    (byte) 9,
                    (byte) 183,
                    (byte) 40,
                    (byte) 215,
                    (byte) 188,
                    (byte) 59,
                    (byte) 117,
                    (byte) 69,
                    (byte) 97,
                    (byte) 115,
                    (byte) 60,
                    (byte) 56,
                    (byte) 0,
                    (byte) 141,
                    (byte) 207,
                    (byte) 171,
                    (byte) 54,
                    (byte) 161,
                    (byte) 23,
                    (byte) 61,
                    (byte) 0,
                    (byte) 87,
                    (byte) 230,
                    (byte) 123,
                    (byte) 87,
                    (byte) 36,
                    (byte) 184,
                    (byte) 255,
                    (byte) 14,
                    (byte) 163,
                    (byte) 187,
                    (byte) 224,
                    (byte) 43,
                    (byte) 151,
                    (byte) 151,
                    (byte) 104,
                    (byte) 39,
                    (byte) 57,
                    (byte) 5,
                    (byte) 54,
                    (byte) 48,
                    (byte) 224,
                    (byte) 181,
                    (byte) 129,
                    (byte) 60,
                    (byte) 92,
                    (byte) 171,
                    (byte) 114,
                    (byte) 109,
                    (byte) 109,
                    (byte) 12,
                    (byte) 23,
                    (byte) 118,
                    (byte) 8,
                    (byte) 64,
                    (byte) 159,
                    (byte) 54,
                    (byte) 216,
                    (byte) 33,
                    (byte) 20,
                    (byte) 24,
                    (byte) 68,
                    (byte) 160,
                    (byte) 36,
                    (byte) 38,
                    (byte) 222,
                    (byte) 145,
                    (byte) 190,
                    (byte) 92,
                    (byte) 99,
                    (byte) 108,
                    (byte) 159,
                    (byte) 232,
                    (byte) 240,
                    (byte) 227,
                    (byte) 221,
                    (byte) 253,
                    (byte) 15,
                    (byte) 62,
                    (byte) 23,
                    (byte) 121,
                    (byte) 185,
                    (byte) 168,
                    (byte) 116,
                    (byte) 4,
                    (byte) 147,
                    (byte) 123,
                    (byte) 72,
                    (byte) 223,
                    (byte) 119,
                    (byte) 226,
                    (byte) 242,
                    (byte) 161,
                    (byte) 204,
                    (byte) 180,
                    (byte) 202,
                    (byte) 137,
                    (byte) 166,
                    (byte) 58,
                    (byte) 24,
                    (byte) 124,
                    (byte) 19,
                    (byte) 181,
                    (byte) 188,
                    (byte) 16,
                    (byte) 107,
                    (byte) 66,
                    (byte) 231,
                    (byte) 63,
                    (byte) 1,
                    (byte) 64,
                    (byte) 252,
                    (byte) 115,
                    (byte) 62,
                    (byte) 233,
                    (byte) 97,
                    (byte) 250,
                    (byte) 86,
                    (byte) 156,
                    (byte) 221,
                    (byte) 49,
                    (byte) 178,
                    (byte) 32,
                    (byte) 73,
                    (byte) 198,
                    (byte) 67,
                    (byte) 249,
                    (byte) 253,
                    (byte) 74,
                    (byte) 56,
                    (byte) 38,
                    (byte) 165,
                    (byte) 119,
                    (byte) 92,
                    (byte) 99,
                    (byte) 44,
                    (byte) 95,
                    (byte) 131,
                    (byte) 89,
                    (byte) 192,
                    (byte) 225,
                    (byte) 55,
                    (byte) 95,
                    (byte) 171,
                    (byte) 88,
                    (byte) 205,
                    (byte) 21,
                    (byte) 116,
                    (byte) 231,
                    (byte) 83,
                    (byte) 71,
                    (byte) 71,
                    (byte) 100,
                    (byte) 110,
                    (byte) 217,
                    (byte) 254,
                    (byte) 152,
                    (byte) 212,
                    (byte) 18,
                    (byte) 8,
                    (byte) 40,
                    (byte) 157,
                    (byte) 244,
                    (byte) 54,
                    (byte) 72,
                    (byte) 240,
                    (byte) 231,
                    (byte) 189,
                    (byte) 111,
                    (byte) 195,
                };
        SBPMessage sbp = new SBPMessage(0x1c66, 0x5f0, payload);
        MsgSsrGriddedCorrectionNoStdDepA msg = new MsgSsrGriddedCorrectionNoStdDepA(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.header.iod_atmo;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.header.iod_atmo + "' != '" + 236 + "'",
                    value.equals(BigInteger.valueOf(236L)));
        } else {
            value = value.longValue();
            expected = 236L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.header.num_msgs;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.header.num_msgs + "' != '" + 62837 + "'",
                    value.equals(BigInteger.valueOf(62837L)));
        } else {
            value = value.longValue();
            expected = 62837L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.header.seq_num;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.header.seq_num + "' != '" + 63555 + "'",
                    value.equals(BigInteger.valueOf(63555L)));
        } else {
            value = value.longValue();
            expected = 63555L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.header.time.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.header.time.tow + "' != '" + 2837573811L + "'",
                    value.equals(new BigInteger("2837573811")));
        } else {
            value = value.longValue();
            expected = 2837573811L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.header.time.wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.header.time.wn + "' != '" + 8940 + "'",
                    value.equals(BigInteger.valueOf(8940L)));
        } else {
            value = value.longValue();
            expected = 8940L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.header.tropo_quality_indicator;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.header.tropo_quality_indicator + "' != '" + 230 + "'",
                    value.equals(BigInteger.valueOf(230L)));
        } else {
            value = value.longValue();
            expected = 230L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.header.update_interval;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.header.update_interval + "' != '" + 233 + "'",
                    value.equals(BigInteger.valueOf(233L)));
        } else {
            value = value.longValue();
            expected = 233L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.index;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.index + "' != '" + 26598 + "'",
                    value.equals(BigInteger.valueOf(26598L)));
        } else {
            value = value.longValue();
            expected = 26598L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[0].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[0].residual + "' != '" + -23949 + "'",
                    value.equals(BigInteger.valueOf(-23949L)));
        } else {
            value = value.longValue();
            expected = -23949L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[0].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[0].sv_id.constellation + "' != '" + 157 + "'",
                    value.equals(BigInteger.valueOf(157L)));
        } else {
            value = value.longValue();
            expected = 157L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[0].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[0].sv_id.satId + "' != '" + 231 + "'",
                    value.equals(BigInteger.valueOf(231L)));
        } else {
            value = value.longValue();
            expected = 231L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[1].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[1].residual + "' != '" + 27427 + "'",
                    value.equals(BigInteger.valueOf(27427L)));
        } else {
            value = value.longValue();
            expected = 27427L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[1].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[1].sv_id.constellation + "' != '" + 146 + "'",
                    value.equals(BigInteger.valueOf(146L)));
        } else {
            value = value.longValue();
            expected = 146L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[1].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[1].sv_id.satId + "' != '" + 197 + "'",
                    value.equals(BigInteger.valueOf(197L)));
        } else {
            value = value.longValue();
            expected = 197L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[2].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[2].residual + "' != '" + 10548 + "'",
                    value.equals(BigInteger.valueOf(10548L)));
        } else {
            value = value.longValue();
            expected = 10548L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[2].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[2].sv_id.constellation + "' != '" + 109 + "'",
                    value.equals(BigInteger.valueOf(109L)));
        } else {
            value = value.longValue();
            expected = 109L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[2].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[2].sv_id.satId + "' != '" + 222 + "'",
                    value.equals(BigInteger.valueOf(222L)));
        } else {
            value = value.longValue();
            expected = 222L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[3].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[3].residual + "' != '" + -18195 + "'",
                    value.equals(BigInteger.valueOf(-18195L)));
        } else {
            value = value.longValue();
            expected = -18195L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[3].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[3].sv_id.constellation + "' != '" + 12 + "'",
                    value.equals(BigInteger.valueOf(12L)));
        } else {
            value = value.longValue();
            expected = 12L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[3].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[3].sv_id.satId + "' != '" + 86 + "'",
                    value.equals(BigInteger.valueOf(86L)));
        } else {
            value = value.longValue();
            expected = 86L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[4].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[4].residual + "' != '" + -27511 + "'",
                    value.equals(BigInteger.valueOf(-27511L)));
        } else {
            value = value.longValue();
            expected = -27511L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[4].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[4].sv_id.constellation + "' != '" + 204 + "'",
                    value.equals(BigInteger.valueOf(204L)));
        } else {
            value = value.longValue();
            expected = 204L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[4].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[4].sv_id.satId + "' != '" + 65 + "'",
                    value.equals(BigInteger.valueOf(65L)));
        } else {
            value = value.longValue();
            expected = 65L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[5].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[5].residual + "' != '" + 11 + "'",
                    value.equals(BigInteger.valueOf(11L)));
        } else {
            value = value.longValue();
            expected = 11L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[5].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[5].sv_id.constellation + "' != '" + 183 + "'",
                    value.equals(BigInteger.valueOf(183L)));
        } else {
            value = value.longValue();
            expected = 183L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[5].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[5].sv_id.satId + "' != '" + 171 + "'",
                    value.equals(BigInteger.valueOf(171L)));
        } else {
            value = value.longValue();
            expected = 171L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[6].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[6].residual + "' != '" + 13740 + "'",
                    value.equals(BigInteger.valueOf(13740L)));
        } else {
            value = value.longValue();
            expected = 13740L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[6].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[6].sv_id.constellation + "' != '" + 203 + "'",
                    value.equals(BigInteger.valueOf(203L)));
        } else {
            value = value.longValue();
            expected = 203L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[6].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[6].sv_id.satId + "' != '" + 180 + "'",
                    value.equals(BigInteger.valueOf(180L)));
        } else {
            value = value.longValue();
            expected = 180L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[7].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[7].residual + "' != '" + 29626 + "'",
                    value.equals(BigInteger.valueOf(29626L)));
        } else {
            value = value.longValue();
            expected = 29626L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[7].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[7].sv_id.constellation + "' != '" + 85 + "'",
                    value.equals(BigInteger.valueOf(85L)));
        } else {
            value = value.longValue();
            expected = 85L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[7].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[7].sv_id.satId + "' != '" + 196 + "'",
                    value.equals(BigInteger.valueOf(196L)));
        } else {
            value = value.longValue();
            expected = 196L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[8].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[8].residual + "' != '" + 7846 + "'",
                    value.equals(BigInteger.valueOf(7846L)));
        } else {
            value = value.longValue();
            expected = 7846L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[8].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[8].sv_id.constellation + "' != '" + 92 + "'",
                    value.equals(BigInteger.valueOf(92L)));
        } else {
            value = value.longValue();
            expected = 92L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[8].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[8].sv_id.satId + "' != '" + 203 + "'",
                    value.equals(BigInteger.valueOf(203L)));
        } else {
            value = value.longValue();
            expected = 203L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[9].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[9].residual + "' != '" + 18376 + "'",
                    value.equals(BigInteger.valueOf(18376L)));
        } else {
            value = value.longValue();
            expected = 18376L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[9].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[9].sv_id.constellation + "' != '" + 13 + "'",
                    value.equals(BigInteger.valueOf(13L)));
        } else {
            value = value.longValue();
            expected = 13L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[9].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[9].sv_id.satId + "' != '" + 42 + "'",
                    value.equals(BigInteger.valueOf(42L)));
        } else {
            value = value.longValue();
            expected = 42L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[10].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[10].residual + "' != '" + -24357 + "'",
                    value.equals(BigInteger.valueOf(-24357L)));
        } else {
            value = value.longValue();
            expected = -24357L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[10].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[10].sv_id.constellation + "' != '" + 137 + "'",
                    value.equals(BigInteger.valueOf(137L)));
        } else {
            value = value.longValue();
            expected = 137L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[10].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[10].sv_id.satId + "' != '" + 98 + "'",
                    value.equals(BigInteger.valueOf(98L)));
        } else {
            value = value.longValue();
            expected = 98L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[11].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[11].residual + "' != '" + -1441 + "'",
                    value.equals(BigInteger.valueOf(-1441L)));
        } else {
            value = value.longValue();
            expected = -1441L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[11].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[11].sv_id.constellation + "' != '" + 216 + "'",
                    value.equals(BigInteger.valueOf(216L)));
        } else {
            value = value.longValue();
            expected = 216L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[11].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[11].sv_id.satId + "' != '" + 95 + "'",
                    value.equals(BigInteger.valueOf(95L)));
        } else {
            value = value.longValue();
            expected = 95L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[12].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[12].residual + "' != '" + -10660 + "'",
                    value.equals(BigInteger.valueOf(-10660L)));
        } else {
            value = value.longValue();
            expected = -10660L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[12].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[12].sv_id.constellation + "' != '" + 196 + "'",
                    value.equals(BigInteger.valueOf(196L)));
        } else {
            value = value.longValue();
            expected = 196L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[12].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[12].sv_id.satId + "' != '" + 99 + "'",
                    value.equals(BigInteger.valueOf(99L)));
        } else {
            value = value.longValue();
            expected = 99L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[13].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[13].residual + "' != '" + -8509 + "'",
                    value.equals(BigInteger.valueOf(-8509L)));
        } else {
            value = value.longValue();
            expected = -8509L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[13].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[13].sv_id.constellation + "' != '" + 253 + "'",
                    value.equals(BigInteger.valueOf(253L)));
        } else {
            value = value.longValue();
            expected = 253L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[13].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[13].sv_id.satId + "' != '" + 159 + "'",
                    value.equals(BigInteger.valueOf(159L)));
        } else {
            value = value.longValue();
            expected = 159L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[14].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[14].residual + "' != '" + 16361 + "'",
                    value.equals(BigInteger.valueOf(16361L)));
        } else {
            value = value.longValue();
            expected = 16361L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[14].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[14].sv_id.constellation + "' != '" + 146 + "'",
                    value.equals(BigInteger.valueOf(146L)));
        } else {
            value = value.longValue();
            expected = 146L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[14].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[14].sv_id.satId + "' != '" + 233 + "'",
                    value.equals(BigInteger.valueOf(233L)));
        } else {
            value = value.longValue();
            expected = 233L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[15].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[15].residual + "' != '" + 10346 + "'",
                    value.equals(BigInteger.valueOf(10346L)));
        } else {
            value = value.longValue();
            expected = 10346L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[15].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[15].sv_id.constellation + "' != '" + 24 + "'",
                    value.equals(BigInteger.valueOf(24L)));
        } else {
            value = value.longValue();
            expected = 24L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[15].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[15].sv_id.satId + "' != '" + 76 + "'",
                    value.equals(BigInteger.valueOf(76L)));
        } else {
            value = value.longValue();
            expected = 76L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[16].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[16].residual + "' != '" + -18679 + "'",
                    value.equals(BigInteger.valueOf(-18679L)));
        } else {
            value = value.longValue();
            expected = -18679L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[16].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[16].sv_id.constellation + "' != '" + 65 + "'",
                    value.equals(BigInteger.valueOf(65L)));
        } else {
            value = value.longValue();
            expected = 65L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[16].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[16].sv_id.satId + "' != '" + 253 + "'",
                    value.equals(BigInteger.valueOf(253L)));
        } else {
            value = value.longValue();
            expected = 253L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[17].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[17].residual + "' != '" + 15292 + "'",
                    value.equals(BigInteger.valueOf(15292L)));
        } else {
            value = value.longValue();
            expected = 15292L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[17].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[17].sv_id.constellation + "' != '" + 215 + "'",
                    value.equals(BigInteger.valueOf(215L)));
        } else {
            value = value.longValue();
            expected = 215L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[17].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[17].sv_id.satId + "' != '" + 40 + "'",
                    value.equals(BigInteger.valueOf(40L)));
        } else {
            value = value.longValue();
            expected = 40L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[18].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[18].residual + "' != '" + 29537 + "'",
                    value.equals(BigInteger.valueOf(29537L)));
        } else {
            value = value.longValue();
            expected = 29537L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[18].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[18].sv_id.constellation + "' != '" + 69 + "'",
                    value.equals(BigInteger.valueOf(69L)));
        } else {
            value = value.longValue();
            expected = 69L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[18].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[18].sv_id.satId + "' != '" + 117 + "'",
                    value.equals(BigInteger.valueOf(117L)));
        } else {
            value = value.longValue();
            expected = 117L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[19].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[19].residual + "' != '" + -29440 + "'",
                    value.equals(BigInteger.valueOf(-29440L)));
        } else {
            value = value.longValue();
            expected = -29440L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[19].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[19].sv_id.constellation + "' != '" + 56 + "'",
                    value.equals(BigInteger.valueOf(56L)));
        } else {
            value = value.longValue();
            expected = 56L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[19].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[19].sv_id.satId + "' != '" + 60 + "'",
                    value.equals(BigInteger.valueOf(60L)));
        } else {
            value = value.longValue();
            expected = 60L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[20].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[20].residual + "' != '" + -24266 + "'",
                    value.equals(BigInteger.valueOf(-24266L)));
        } else {
            value = value.longValue();
            expected = -24266L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[20].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[20].sv_id.constellation + "' != '" + 171 + "'",
                    value.equals(BigInteger.valueOf(171L)));
        } else {
            value = value.longValue();
            expected = 171L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[20].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[20].sv_id.satId + "' != '" + 207 + "'",
                    value.equals(BigInteger.valueOf(207L)));
        } else {
            value = value.longValue();
            expected = 207L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[21].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[21].residual + "' != '" + 22272 + "'",
                    value.equals(BigInteger.valueOf(22272L)));
        } else {
            value = value.longValue();
            expected = 22272L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[21].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[21].sv_id.constellation + "' != '" + 61 + "'",
                    value.equals(BigInteger.valueOf(61L)));
        } else {
            value = value.longValue();
            expected = 61L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[21].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[21].sv_id.satId + "' != '" + 23 + "'",
                    value.equals(BigInteger.valueOf(23L)));
        } else {
            value = value.longValue();
            expected = 23L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[22].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[22].residual + "' != '" + 9303 + "'",
                    value.equals(BigInteger.valueOf(9303L)));
        } else {
            value = value.longValue();
            expected = 9303L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[22].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[22].sv_id.constellation + "' != '" + 123 + "'",
                    value.equals(BigInteger.valueOf(123L)));
        } else {
            value = value.longValue();
            expected = 123L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[22].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[22].sv_id.satId + "' != '" + 230 + "'",
                    value.equals(BigInteger.valueOf(230L)));
        } else {
            value = value.longValue();
            expected = 230L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[23].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[23].residual + "' != '" + -23794 + "'",
                    value.equals(BigInteger.valueOf(-23794L)));
        } else {
            value = value.longValue();
            expected = -23794L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[23].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[23].sv_id.constellation + "' != '" + 255 + "'",
                    value.equals(BigInteger.valueOf(255L)));
        } else {
            value = value.longValue();
            expected = 255L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[23].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[23].sv_id.satId + "' != '" + 184 + "'",
                    value.equals(BigInteger.valueOf(184L)));
        } else {
            value = value.longValue();
            expected = 184L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[24].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[24].residual + "' != '" + -26837 + "'",
                    value.equals(BigInteger.valueOf(-26837L)));
        } else {
            value = value.longValue();
            expected = -26837L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[24].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[24].sv_id.constellation + "' != '" + 224 + "'",
                    value.equals(BigInteger.valueOf(224L)));
        } else {
            value = value.longValue();
            expected = 224L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[24].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[24].sv_id.satId + "' != '" + 187 + "'",
                    value.equals(BigInteger.valueOf(187L)));
        } else {
            value = value.longValue();
            expected = 187L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[25].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[25].residual + "' != '" + 14631 + "'",
                    value.equals(BigInteger.valueOf(14631L)));
        } else {
            value = value.longValue();
            expected = 14631L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[25].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[25].sv_id.constellation + "' != '" + 104 + "'",
                    value.equals(BigInteger.valueOf(104L)));
        } else {
            value = value.longValue();
            expected = 104L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[25].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[25].sv_id.satId + "' != '" + 151 + "'",
                    value.equals(BigInteger.valueOf(151L)));
        } else {
            value = value.longValue();
            expected = 151L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[26].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[26].residual + "' != '" + -8144 + "'",
                    value.equals(BigInteger.valueOf(-8144L)));
        } else {
            value = value.longValue();
            expected = -8144L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[26].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[26].sv_id.constellation + "' != '" + 54 + "'",
                    value.equals(BigInteger.valueOf(54L)));
        } else {
            value = value.longValue();
            expected = 54L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[26].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[26].sv_id.satId + "' != '" + 5 + "'",
                    value.equals(BigInteger.valueOf(5L)));
        } else {
            value = value.longValue();
            expected = 5L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[27].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[27].residual + "' != '" + 23612 + "'",
                    value.equals(BigInteger.valueOf(23612L)));
        } else {
            value = value.longValue();
            expected = 23612L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[27].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[27].sv_id.constellation + "' != '" + 129 + "'",
                    value.equals(BigInteger.valueOf(129L)));
        } else {
            value = value.longValue();
            expected = 129L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[27].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[27].sv_id.satId + "' != '" + 181 + "'",
                    value.equals(BigInteger.valueOf(181L)));
        } else {
            value = value.longValue();
            expected = 181L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[28].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[28].residual + "' != '" + 28013 + "'",
                    value.equals(BigInteger.valueOf(28013L)));
        } else {
            value = value.longValue();
            expected = 28013L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[28].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[28].sv_id.constellation + "' != '" + 114 + "'",
                    value.equals(BigInteger.valueOf(114L)));
        } else {
            value = value.longValue();
            expected = 114L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[28].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[28].sv_id.satId + "' != '" + 171 + "'",
                    value.equals(BigInteger.valueOf(171L)));
        } else {
            value = value.longValue();
            expected = 171L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[29].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[29].residual + "' != '" + 2166 + "'",
                    value.equals(BigInteger.valueOf(2166L)));
        } else {
            value = value.longValue();
            expected = 2166L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[29].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[29].sv_id.constellation + "' != '" + 23 + "'",
                    value.equals(BigInteger.valueOf(23L)));
        } else {
            value = value.longValue();
            expected = 23L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[29].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[29].sv_id.satId + "' != '" + 12 + "'",
                    value.equals(BigInteger.valueOf(12L)));
        } else {
            value = value.longValue();
            expected = 12L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[30].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[30].residual + "' != '" + -10186 + "'",
                    value.equals(BigInteger.valueOf(-10186L)));
        } else {
            value = value.longValue();
            expected = -10186L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[30].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[30].sv_id.constellation + "' != '" + 159 + "'",
                    value.equals(BigInteger.valueOf(159L)));
        } else {
            value = value.longValue();
            expected = 159L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[30].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[30].sv_id.satId + "' != '" + 64 + "'",
                    value.equals(BigInteger.valueOf(64L)));
        } else {
            value = value.longValue();
            expected = 64L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[31].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[31].residual + "' != '" + 17432 + "'",
                    value.equals(BigInteger.valueOf(17432L)));
        } else {
            value = value.longValue();
            expected = 17432L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[31].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[31].sv_id.constellation + "' != '" + 20 + "'",
                    value.equals(BigInteger.valueOf(20L)));
        } else {
            value = value.longValue();
            expected = 20L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[31].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[31].sv_id.satId + "' != '" + 33 + "'",
                    value.equals(BigInteger.valueOf(33L)));
        } else {
            value = value.longValue();
            expected = 33L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[32].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[32].residual + "' != '" + -8666 + "'",
                    value.equals(BigInteger.valueOf(-8666L)));
        } else {
            value = value.longValue();
            expected = -8666L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[32].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[32].sv_id.constellation + "' != '" + 36 + "'",
                    value.equals(BigInteger.valueOf(36L)));
        } else {
            value = value.longValue();
            expected = 36L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[32].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[32].sv_id.satId + "' != '" + 160 + "'",
                    value.equals(BigInteger.valueOf(160L)));
        } else {
            value = value.longValue();
            expected = 160L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[33].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[33].residual + "' != '" + 25436 + "'",
                    value.equals(BigInteger.valueOf(25436L)));
        } else {
            value = value.longValue();
            expected = 25436L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[33].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[33].sv_id.constellation + "' != '" + 190 + "'",
                    value.equals(BigInteger.valueOf(190L)));
        } else {
            value = value.longValue();
            expected = 190L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[33].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[33].sv_id.satId + "' != '" + 145 + "'",
                    value.equals(BigInteger.valueOf(145L)));
        } else {
            value = value.longValue();
            expected = 145L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[34].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[34].residual + "' != '" + -3864 + "'",
                    value.equals(BigInteger.valueOf(-3864L)));
        } else {
            value = value.longValue();
            expected = -3864L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[34].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[34].sv_id.constellation + "' != '" + 159 + "'",
                    value.equals(BigInteger.valueOf(159L)));
        } else {
            value = value.longValue();
            expected = 159L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[34].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[34].sv_id.satId + "' != '" + 108 + "'",
                    value.equals(BigInteger.valueOf(108L)));
        } else {
            value = value.longValue();
            expected = 108L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[35].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[35].residual + "' != '" + 4093 + "'",
                    value.equals(BigInteger.valueOf(4093L)));
        } else {
            value = value.longValue();
            expected = 4093L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[35].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[35].sv_id.constellation + "' != '" + 221 + "'",
                    value.equals(BigInteger.valueOf(221L)));
        } else {
            value = value.longValue();
            expected = 221L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[35].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[35].sv_id.satId + "' != '" + 227 + "'",
                    value.equals(BigInteger.valueOf(227L)));
        } else {
            value = value.longValue();
            expected = 227L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[36].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[36].residual + "' != '" + -18055 + "'",
                    value.equals(BigInteger.valueOf(-18055L)));
        } else {
            value = value.longValue();
            expected = -18055L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[36].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[36].sv_id.constellation + "' != '" + 23 + "'",
                    value.equals(BigInteger.valueOf(23L)));
        } else {
            value = value.longValue();
            expected = 23L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[36].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[36].sv_id.satId + "' != '" + 62 + "'",
                    value.equals(BigInteger.valueOf(62L)));
        } else {
            value = value.longValue();
            expected = 62L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[37].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[37].residual + "' != '" + -27900 + "'",
                    value.equals(BigInteger.valueOf(-27900L)));
        } else {
            value = value.longValue();
            expected = -27900L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[37].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[37].sv_id.constellation + "' != '" + 116 + "'",
                    value.equals(BigInteger.valueOf(116L)));
        } else {
            value = value.longValue();
            expected = 116L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[37].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[37].sv_id.satId + "' != '" + 168 + "'",
                    value.equals(BigInteger.valueOf(168L)));
        } else {
            value = value.longValue();
            expected = 168L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[38].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[38].residual + "' != '" + 30687 + "'",
                    value.equals(BigInteger.valueOf(30687L)));
        } else {
            value = value.longValue();
            expected = 30687L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[38].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[38].sv_id.constellation + "' != '" + 72 + "'",
                    value.equals(BigInteger.valueOf(72L)));
        } else {
            value = value.longValue();
            expected = 72L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[38].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[38].sv_id.satId + "' != '" + 123 + "'",
                    value.equals(BigInteger.valueOf(123L)));
        } else {
            value = value.longValue();
            expected = 123L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[39].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[39].residual + "' != '" + -13151 + "'",
                    value.equals(BigInteger.valueOf(-13151L)));
        } else {
            value = value.longValue();
            expected = -13151L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[39].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[39].sv_id.constellation + "' != '" + 242 + "'",
                    value.equals(BigInteger.valueOf(242L)));
        } else {
            value = value.longValue();
            expected = 242L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[39].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[39].sv_id.satId + "' != '" + 226 + "'",
                    value.equals(BigInteger.valueOf(226L)));
        } else {
            value = value.longValue();
            expected = 226L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[40].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[40].residual + "' != '" + -22903 + "'",
                    value.equals(BigInteger.valueOf(-22903L)));
        } else {
            value = value.longValue();
            expected = -22903L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[40].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[40].sv_id.constellation + "' != '" + 202 + "'",
                    value.equals(BigInteger.valueOf(202L)));
        } else {
            value = value.longValue();
            expected = 202L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[40].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[40].sv_id.satId + "' != '" + 180 + "'",
                    value.equals(BigInteger.valueOf(180L)));
        } else {
            value = value.longValue();
            expected = 180L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[41].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[41].residual + "' != '" + 4988 + "'",
                    value.equals(BigInteger.valueOf(4988L)));
        } else {
            value = value.longValue();
            expected = 4988L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[41].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[41].sv_id.constellation + "' != '" + 24 + "'",
                    value.equals(BigInteger.valueOf(24L)));
        } else {
            value = value.longValue();
            expected = 24L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[41].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[41].sv_id.satId + "' != '" + 58 + "'",
                    value.equals(BigInteger.valueOf(58L)));
        } else {
            value = value.longValue();
            expected = 58L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[42].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[42].residual + "' != '" + 27408 + "'",
                    value.equals(BigInteger.valueOf(27408L)));
        } else {
            value = value.longValue();
            expected = 27408L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[42].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[42].sv_id.constellation + "' != '" + 188 + "'",
                    value.equals(BigInteger.valueOf(188L)));
        } else {
            value = value.longValue();
            expected = 188L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[42].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[42].sv_id.satId + "' != '" + 181 + "'",
                    value.equals(BigInteger.valueOf(181L)));
        } else {
            value = value.longValue();
            expected = 181L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[43].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[43].residual + "' != '" + 319 + "'",
                    value.equals(BigInteger.valueOf(319L)));
        } else {
            value = value.longValue();
            expected = 319L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[43].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[43].sv_id.constellation + "' != '" + 231 + "'",
                    value.equals(BigInteger.valueOf(231L)));
        } else {
            value = value.longValue();
            expected = 231L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[43].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[43].sv_id.satId + "' != '" + 66 + "'",
                    value.equals(BigInteger.valueOf(66L)));
        } else {
            value = value.longValue();
            expected = 66L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[44].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[44].residual + "' != '" + 15987 + "'",
                    value.equals(BigInteger.valueOf(15987L)));
        } else {
            value = value.longValue();
            expected = 15987L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[44].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[44].sv_id.constellation + "' != '" + 252 + "'",
                    value.equals(BigInteger.valueOf(252L)));
        } else {
            value = value.longValue();
            expected = 252L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[44].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[44].sv_id.satId + "' != '" + 64 + "'",
                    value.equals(BigInteger.valueOf(64L)));
        } else {
            value = value.longValue();
            expected = 64L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[45].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[45].residual + "' != '" + 22266 + "'",
                    value.equals(BigInteger.valueOf(22266L)));
        } else {
            value = value.longValue();
            expected = 22266L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[45].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[45].sv_id.constellation + "' != '" + 97 + "'",
                    value.equals(BigInteger.valueOf(97L)));
        } else {
            value = value.longValue();
            expected = 97L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[45].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[45].sv_id.satId + "' != '" + 233 + "'",
                    value.equals(BigInteger.valueOf(233L)));
        } else {
            value = value.longValue();
            expected = 233L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[46].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[46].residual + "' != '" + -19919 + "'",
                    value.equals(BigInteger.valueOf(-19919L)));
        } else {
            value = value.longValue();
            expected = -19919L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[46].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[46].sv_id.constellation + "' != '" + 221 + "'",
                    value.equals(BigInteger.valueOf(221L)));
        } else {
            value = value.longValue();
            expected = 221L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[46].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[46].sv_id.satId + "' != '" + 156 + "'",
                    value.equals(BigInteger.valueOf(156L)));
        } else {
            value = value.longValue();
            expected = 156L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[47].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[47].residual + "' != '" + 17350 + "'",
                    value.equals(BigInteger.valueOf(17350L)));
        } else {
            value = value.longValue();
            expected = 17350L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[47].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[47].sv_id.constellation + "' != '" + 73 + "'",
                    value.equals(BigInteger.valueOf(73L)));
        } else {
            value = value.longValue();
            expected = 73L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[47].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[47].sv_id.satId + "' != '" + 32 + "'",
                    value.equals(BigInteger.valueOf(32L)));
        } else {
            value = value.longValue();
            expected = 32L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[48].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[48].residual + "' != '" + 14410 + "'",
                    value.equals(BigInteger.valueOf(14410L)));
        } else {
            value = value.longValue();
            expected = 14410L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[48].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[48].sv_id.constellation + "' != '" + 253 + "'",
                    value.equals(BigInteger.valueOf(253L)));
        } else {
            value = value.longValue();
            expected = 253L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[48].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[48].sv_id.satId + "' != '" + 249 + "'",
                    value.equals(BigInteger.valueOf(249L)));
        } else {
            value = value.longValue();
            expected = 249L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[49].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[49].residual + "' != '" + 23671 + "'",
                    value.equals(BigInteger.valueOf(23671L)));
        } else {
            value = value.longValue();
            expected = 23671L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[49].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[49].sv_id.constellation + "' != '" + 165 + "'",
                    value.equals(BigInteger.valueOf(165L)));
        } else {
            value = value.longValue();
            expected = 165L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[49].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[49].sv_id.satId + "' != '" + 38 + "'",
                    value.equals(BigInteger.valueOf(38L)));
        } else {
            value = value.longValue();
            expected = 38L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[50].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[50].residual + "' != '" + -31905 + "'",
                    value.equals(BigInteger.valueOf(-31905L)));
        } else {
            value = value.longValue();
            expected = -31905L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[50].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[50].sv_id.constellation + "' != '" + 44 + "'",
                    value.equals(BigInteger.valueOf(44L)));
        } else {
            value = value.longValue();
            expected = 44L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[50].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[50].sv_id.satId + "' != '" + 99 + "'",
                    value.equals(BigInteger.valueOf(99L)));
        } else {
            value = value.longValue();
            expected = 99L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[51].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[51].residual + "' != '" + 14305 + "'",
                    value.equals(BigInteger.valueOf(14305L)));
        } else {
            value = value.longValue();
            expected = 14305L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[51].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[51].sv_id.constellation + "' != '" + 192 + "'",
                    value.equals(BigInteger.valueOf(192L)));
        } else {
            value = value.longValue();
            expected = 192L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[51].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[51].sv_id.satId + "' != '" + 89 + "'",
                    value.equals(BigInteger.valueOf(89L)));
        } else {
            value = value.longValue();
            expected = 89L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[52].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[52].residual + "' != '" + -12968 + "'",
                    value.equals(BigInteger.valueOf(-12968L)));
        } else {
            value = value.longValue();
            expected = -12968L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[52].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[52].sv_id.constellation + "' != '" + 171 + "'",
                    value.equals(BigInteger.valueOf(171L)));
        } else {
            value = value.longValue();
            expected = 171L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[52].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[52].sv_id.satId + "' != '" + 95 + "'",
                    value.equals(BigInteger.valueOf(95L)));
        } else {
            value = value.longValue();
            expected = 95L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[53].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[53].residual + "' != '" + 21479 + "'",
                    value.equals(BigInteger.valueOf(21479L)));
        } else {
            value = value.longValue();
            expected = 21479L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[53].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[53].sv_id.constellation + "' != '" + 116 + "'",
                    value.equals(BigInteger.valueOf(116L)));
        } else {
            value = value.longValue();
            expected = 116L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[53].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[53].sv_id.satId + "' != '" + 21 + "'",
                    value.equals(BigInteger.valueOf(21L)));
        } else {
            value = value.longValue();
            expected = 21L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[54].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[54].residual + "' != '" + 28260 + "'",
                    value.equals(BigInteger.valueOf(28260L)));
        } else {
            value = value.longValue();
            expected = 28260L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[54].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[54].sv_id.constellation + "' != '" + 71 + "'",
                    value.equals(BigInteger.valueOf(71L)));
        } else {
            value = value.longValue();
            expected = 71L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[54].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[54].sv_id.satId + "' != '" + 71 + "'",
                    value.equals(BigInteger.valueOf(71L)));
        } else {
            value = value.longValue();
            expected = 71L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[55].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[55].residual + "' != '" + -11112 + "'",
                    value.equals(BigInteger.valueOf(-11112L)));
        } else {
            value = value.longValue();
            expected = -11112L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[55].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[55].sv_id.constellation + "' != '" + 254 + "'",
                    value.equals(BigInteger.valueOf(254L)));
        } else {
            value = value.longValue();
            expected = 254L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[55].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[55].sv_id.satId + "' != '" + 217 + "'",
                    value.equals(BigInteger.valueOf(217L)));
        } else {
            value = value.longValue();
            expected = 217L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[56].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[56].residual + "' != '" + -25304 + "'",
                    value.equals(BigInteger.valueOf(-25304L)));
        } else {
            value = value.longValue();
            expected = -25304L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[56].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[56].sv_id.constellation + "' != '" + 8 + "'",
                    value.equals(BigInteger.valueOf(8L)));
        } else {
            value = value.longValue();
            expected = 8L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[56].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[56].sv_id.satId + "' != '" + 18 + "'",
                    value.equals(BigInteger.valueOf(18L)));
        } else {
            value = value.longValue();
            expected = 18L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[57].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[57].residual + "' != '" + -4024 + "'",
                    value.equals(BigInteger.valueOf(-4024L)));
        } else {
            value = value.longValue();
            expected = -4024L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[57].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[57].sv_id.constellation + "' != '" + 54 + "'",
                    value.equals(BigInteger.valueOf(54L)));
        } else {
            value = value.longValue();
            expected = 54L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[57].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[57].sv_id.satId + "' != '" + 244 + "'",
                    value.equals(BigInteger.valueOf(244L)));
        } else {
            value = value.longValue();
            expected = 244L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[58].residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[58].residual + "' != '" + -15505 + "'",
                    value.equals(BigInteger.valueOf(-15505L)));
        } else {
            value = value.longValue();
            expected = -15505L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[58].sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[58].sv_id.constellation + "' != '" + 189 + "'",
                    value.equals(BigInteger.valueOf(189L)));
        } else {
            value = value.longValue();
            expected = 189L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_residuals[58].sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_residuals[58].sv_id.satId + "' != '" + 231 + "'",
                    value.equals(BigInteger.valueOf(231L)));
        } else {
            value = value.longValue();
            expected = 231L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tropo_delay_correction.hydro;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tropo_delay_correction.hydro + "' != '" + 16250 + "'",
                    value.equals(BigInteger.valueOf(16250L)));
        } else {
            value = value.longValue();
            expected = 16250L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tropo_delay_correction.wet;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tropo_delay_correction.wet + "' != '" + 101 + "'",
                    value.equals(BigInteger.valueOf(101L)));
        } else {
            value = value.longValue();
            expected = 101L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
