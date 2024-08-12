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
// spec/tests/yaml/swiftnav/sbp/tracking/test_MsgTrackingState.yaml by generate.py. Do not modify by
// hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.tracking.MsgTrackingState;
import com.swiftnav.sbp.tracking.MsgTrackingStateDepB;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_tracking_MsgTrackingStateTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_tracking_MsgTrackingStateTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 117,
                    (byte) 184,
                    (byte) 3,
                    (byte) 102,
                    (byte) 38,
                    (byte) 106,
                    (byte) 140,
                    (byte) 141,
                    (byte) 25,
                    (byte) 4,
                    (byte) 90,
                    (byte) 195,
                    (byte) 246,
                    (byte) 108,
                    (byte) 75,
                    (byte) 82,
                    (byte) 137,
                    (byte) 127,
                    (byte) 45,
                    (byte) 163,
                    (byte) 32,
                    (byte) 46,
                    (byte) 187,
                    (byte) 93,
                    (byte) 153,
                    (byte) 60,
                    (byte) 201,
                    (byte) 147,
                    (byte) 23,
                    (byte) 29,
                    (byte) 5,
                    (byte) 208,
                    (byte) 181,
                    (byte) 30,
                    (byte) 219,
                    (byte) 69,
                    (byte) 254,
                    (byte) 136,
                    (byte) 3,
                    (byte) 121,
                    (byte) 33,
                    (byte) 98,
                    (byte) 144,
                    (byte) 215,
                    (byte) 133,
                    (byte) 182,
                    (byte) 14,
                    (byte) 56,
                    (byte) 169,
                    (byte) 77,
                    (byte) 218,
                    (byte) 62,
                    (byte) 242,
                    (byte) 84,
                    (byte) 171,
                    (byte) 249,
                    (byte) 152,
                    (byte) 137,
                    (byte) 131,
                    (byte) 130,
                    (byte) 193,
                    (byte) 21,
                    (byte) 42,
                    (byte) 68,
                    (byte) 253,
                    (byte) 227,
                    (byte) 216,
                    (byte) 227,
                    (byte) 24,
                    (byte) 26,
                    (byte) 210,
                    (byte) 179,
                    (byte) 19,
                    (byte) 15,
                    (byte) 227,
                    (byte) 255,
                    (byte) 122,
                    (byte) 75,
                    (byte) 187,
                    (byte) 200,
                    (byte) 217,
                    (byte) 48,
                    (byte) 218,
                    (byte) 122,
                    (byte) 187,
                    (byte) 238,
                    (byte) 142,
                    (byte) 149,
                    (byte) 238,
                    (byte) 55,
                    (byte) 251,
                    (byte) 212,
                    (byte) 128,
                    (byte) 160,
                    (byte) 194,
                    (byte) 104,
                    (byte) 113,
                    (byte) 255,
                    (byte) 141,
                    (byte) 62,
                    (byte) 43,
                    (byte) 69,
                    (byte) 245,
                    (byte) 39,
                    (byte) 100,
                    (byte) 230,
                    (byte) 108,
                    (byte) 56,
                    (byte) 247,
                    (byte) 68,
                    (byte) 149,
                    (byte) 143,
                    (byte) 137,
                    (byte) 101,
                    (byte) 233,
                    (byte) 70,
                    (byte) 49,
                    (byte) 165,
                    (byte) 38,
                    (byte) 110,
                    (byte) 218,
                    (byte) 230,
                    (byte) 80,
                    (byte) 213,
                    (byte) 196,
                    (byte) 179,
                    (byte) 139,
                    (byte) 128,
                    (byte) 15,
                    (byte) 178,
                    (byte) 196,
                    (byte) 171,
                    (byte) 8,
                    (byte) 212,
                    (byte) 97,
                    (byte) 194,
                    (byte) 83,
                    (byte) 233,
                    (byte) 79,
                    (byte) 99,
                    (byte) 55,
                    (byte) 90,
                    (byte) 31,
                    (byte) 180,
                    (byte) 5,
                    (byte) 25,
                    (byte) 105,
                    (byte) 186,
                    (byte) 22,
                    (byte) 224,
                    (byte) 80,
                    (byte) 111,
                    (byte) 8,
                    (byte) 48,
                    (byte) 106,
                    (byte) 166,
                    (byte) 4,
                    (byte) 48,
                    (byte) 156,
                    (byte) 49,
                    (byte) 86,
                    (byte) 19,
                    (byte) 142,
                    (byte) 146,
                    (byte) 91,
                    (byte) 124,
                    (byte) 115,
                    (byte) 64,
                    (byte) 28,
                    (byte) 230,
                    (byte) 115,
                    (byte) 178,
                    (byte) 190,
                    (byte) 131,
                    (byte) 16,
                    (byte) 242,
                    (byte) 105,
                    (byte) 59,
                    (byte) 182,
                    (byte) 113,
                    (byte) 192,
                    (byte) 180,
                    (byte) 48,
                    (byte) 179,
                    (byte) 166,
                    (byte) 31,
                    (byte) 172,
                    (byte) 211,
                    (byte) 77,
                    (byte) 228,
                    (byte) 140,
                    (byte) 49,
                    (byte) 128,
                    (byte) 77,
                    (byte) 240,
                    (byte) 194,
                    (byte) 134,
                    (byte) 194,
                    (byte) 41,
                    (byte) 58,
                    (byte) 18,
                    (byte) 53,
                    (byte) 129,
                    (byte) 55,
                    (byte) 91,
                    (byte) 72,
                    (byte) 134,
                    (byte) 92,
                    (byte) 33,
                    (byte) 224,
                    (byte) 157,
                    (byte) 56,
                    (byte) 186,
                    (byte) 54,
                    (byte) 224,
                    (byte) 174,
                    (byte) 82,
                    (byte) 84,
                    (byte) 148,
                    (byte) 190,
                    (byte) 236,
                    (byte) 54,
                    (byte) 62,
                    (byte) 67,
                    (byte) 52,
                    (byte) 215,
                    (byte) 57,
                    (byte) 254,
                    (byte) 16,
                    (byte) 133,
                    (byte) 36,
                    (byte) 174,
                    (byte) 219,
                    (byte) 172,
                    (byte) 145,
                    (byte) 17,
                    (byte) 192,
                    (byte) 179,
                    (byte) 111,
                    (byte) 97,
                    (byte) 207,
                    (byte) 56,
                    (byte) 208,
                    (byte) 134,
                    (byte) 180,
                    (byte) 17,
                    (byte) 43,
                    (byte) 226,
                    (byte) 255,
                    (byte) 182,
                    (byte) 140,
                    (byte) 113,
                };
        SBPMessage sbp = new SBPMessage(0x8137, 0x41, payload);
        MsgTrackingState msg = new MsgTrackingState(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.states[0].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[0].cn0 + "' != '" + 102 + "'",
                    value.equals(BigInteger.valueOf(102L)));
        } else {
            value = value.longValue();
            expected = 102L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[0].fcn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[0].fcn + "' != '" + 3 + "'",
                    value.equals(BigInteger.valueOf(3L)));
        } else {
            value = value.longValue();
            expected = 3L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[0].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[0].sid.code + "' != '" + 184 + "'",
                    value.equals(BigInteger.valueOf(184L)));
        } else {
            value = value.longValue();
            expected = 184L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[0].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[0].sid.sat + "' != '" + 117 + "'",
                    value.equals(BigInteger.valueOf(117L)));
        } else {
            value = value.longValue();
            expected = 117L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[1].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[1].cn0 + "' != '" + 141 + "'",
                    value.equals(BigInteger.valueOf(141L)));
        } else {
            value = value.longValue();
            expected = 141L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[1].fcn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[1].fcn + "' != '" + 140 + "'",
                    value.equals(BigInteger.valueOf(140L)));
        } else {
            value = value.longValue();
            expected = 140L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[1].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[1].sid.code + "' != '" + 106 + "'",
                    value.equals(BigInteger.valueOf(106L)));
        } else {
            value = value.longValue();
            expected = 106L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[1].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[1].sid.sat + "' != '" + 38 + "'",
                    value.equals(BigInteger.valueOf(38L)));
        } else {
            value = value.longValue();
            expected = 38L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[2].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[2].cn0 + "' != '" + 195 + "'",
                    value.equals(BigInteger.valueOf(195L)));
        } else {
            value = value.longValue();
            expected = 195L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[2].fcn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[2].fcn + "' != '" + 90 + "'",
                    value.equals(BigInteger.valueOf(90L)));
        } else {
            value = value.longValue();
            expected = 90L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[2].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[2].sid.code + "' != '" + 4 + "'",
                    value.equals(BigInteger.valueOf(4L)));
        } else {
            value = value.longValue();
            expected = 4L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[2].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[2].sid.sat + "' != '" + 25 + "'",
                    value.equals(BigInteger.valueOf(25L)));
        } else {
            value = value.longValue();
            expected = 25L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[3].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[3].cn0 + "' != '" + 82 + "'",
                    value.equals(BigInteger.valueOf(82L)));
        } else {
            value = value.longValue();
            expected = 82L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[3].fcn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[3].fcn + "' != '" + 75 + "'",
                    value.equals(BigInteger.valueOf(75L)));
        } else {
            value = value.longValue();
            expected = 75L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[3].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[3].sid.code + "' != '" + 108 + "'",
                    value.equals(BigInteger.valueOf(108L)));
        } else {
            value = value.longValue();
            expected = 108L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[3].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[3].sid.sat + "' != '" + 246 + "'",
                    value.equals(BigInteger.valueOf(246L)));
        } else {
            value = value.longValue();
            expected = 246L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[4].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[4].cn0 + "' != '" + 163 + "'",
                    value.equals(BigInteger.valueOf(163L)));
        } else {
            value = value.longValue();
            expected = 163L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[4].fcn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[4].fcn + "' != '" + 45 + "'",
                    value.equals(BigInteger.valueOf(45L)));
        } else {
            value = value.longValue();
            expected = 45L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[4].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[4].sid.code + "' != '" + 127 + "'",
                    value.equals(BigInteger.valueOf(127L)));
        } else {
            value = value.longValue();
            expected = 127L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[4].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[4].sid.sat + "' != '" + 137 + "'",
                    value.equals(BigInteger.valueOf(137L)));
        } else {
            value = value.longValue();
            expected = 137L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[5].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[5].cn0 + "' != '" + 93 + "'",
                    value.equals(BigInteger.valueOf(93L)));
        } else {
            value = value.longValue();
            expected = 93L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[5].fcn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[5].fcn + "' != '" + 187 + "'",
                    value.equals(BigInteger.valueOf(187L)));
        } else {
            value = value.longValue();
            expected = 187L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[5].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[5].sid.code + "' != '" + 46 + "'",
                    value.equals(BigInteger.valueOf(46L)));
        } else {
            value = value.longValue();
            expected = 46L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[5].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[5].sid.sat + "' != '" + 32 + "'",
                    value.equals(BigInteger.valueOf(32L)));
        } else {
            value = value.longValue();
            expected = 32L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[6].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[6].cn0 + "' != '" + 147 + "'",
                    value.equals(BigInteger.valueOf(147L)));
        } else {
            value = value.longValue();
            expected = 147L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[6].fcn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[6].fcn + "' != '" + 201 + "'",
                    value.equals(BigInteger.valueOf(201L)));
        } else {
            value = value.longValue();
            expected = 201L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[6].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[6].sid.code + "' != '" + 60 + "'",
                    value.equals(BigInteger.valueOf(60L)));
        } else {
            value = value.longValue();
            expected = 60L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[6].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[6].sid.sat + "' != '" + 153 + "'",
                    value.equals(BigInteger.valueOf(153L)));
        } else {
            value = value.longValue();
            expected = 153L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[7].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[7].cn0 + "' != '" + 208 + "'",
                    value.equals(BigInteger.valueOf(208L)));
        } else {
            value = value.longValue();
            expected = 208L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[7].fcn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[7].fcn + "' != '" + 5 + "'",
                    value.equals(BigInteger.valueOf(5L)));
        } else {
            value = value.longValue();
            expected = 5L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[7].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[7].sid.code + "' != '" + 29 + "'",
                    value.equals(BigInteger.valueOf(29L)));
        } else {
            value = value.longValue();
            expected = 29L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[7].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[7].sid.sat + "' != '" + 23 + "'",
                    value.equals(BigInteger.valueOf(23L)));
        } else {
            value = value.longValue();
            expected = 23L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[8].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[8].cn0 + "' != '" + 69 + "'",
                    value.equals(BigInteger.valueOf(69L)));
        } else {
            value = value.longValue();
            expected = 69L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[8].fcn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[8].fcn + "' != '" + 219 + "'",
                    value.equals(BigInteger.valueOf(219L)));
        } else {
            value = value.longValue();
            expected = 219L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[8].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[8].sid.code + "' != '" + 30 + "'",
                    value.equals(BigInteger.valueOf(30L)));
        } else {
            value = value.longValue();
            expected = 30L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[8].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[8].sid.sat + "' != '" + 181 + "'",
                    value.equals(BigInteger.valueOf(181L)));
        } else {
            value = value.longValue();
            expected = 181L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[9].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[9].cn0 + "' != '" + 121 + "'",
                    value.equals(BigInteger.valueOf(121L)));
        } else {
            value = value.longValue();
            expected = 121L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[9].fcn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[9].fcn + "' != '" + 3 + "'",
                    value.equals(BigInteger.valueOf(3L)));
        } else {
            value = value.longValue();
            expected = 3L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[9].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[9].sid.code + "' != '" + 136 + "'",
                    value.equals(BigInteger.valueOf(136L)));
        } else {
            value = value.longValue();
            expected = 136L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[9].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[9].sid.sat + "' != '" + 254 + "'",
                    value.equals(BigInteger.valueOf(254L)));
        } else {
            value = value.longValue();
            expected = 254L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[10].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[10].cn0 + "' != '" + 215 + "'",
                    value.equals(BigInteger.valueOf(215L)));
        } else {
            value = value.longValue();
            expected = 215L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[10].fcn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[10].fcn + "' != '" + 144 + "'",
                    value.equals(BigInteger.valueOf(144L)));
        } else {
            value = value.longValue();
            expected = 144L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[10].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[10].sid.code + "' != '" + 98 + "'",
                    value.equals(BigInteger.valueOf(98L)));
        } else {
            value = value.longValue();
            expected = 98L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[10].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[10].sid.sat + "' != '" + 33 + "'",
                    value.equals(BigInteger.valueOf(33L)));
        } else {
            value = value.longValue();
            expected = 33L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[11].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[11].cn0 + "' != '" + 56 + "'",
                    value.equals(BigInteger.valueOf(56L)));
        } else {
            value = value.longValue();
            expected = 56L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[11].fcn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[11].fcn + "' != '" + 14 + "'",
                    value.equals(BigInteger.valueOf(14L)));
        } else {
            value = value.longValue();
            expected = 14L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[11].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[11].sid.code + "' != '" + 182 + "'",
                    value.equals(BigInteger.valueOf(182L)));
        } else {
            value = value.longValue();
            expected = 182L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[11].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[11].sid.sat + "' != '" + 133 + "'",
                    value.equals(BigInteger.valueOf(133L)));
        } else {
            value = value.longValue();
            expected = 133L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[12].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[12].cn0 + "' != '" + 62 + "'",
                    value.equals(BigInteger.valueOf(62L)));
        } else {
            value = value.longValue();
            expected = 62L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[12].fcn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[12].fcn + "' != '" + 218 + "'",
                    value.equals(BigInteger.valueOf(218L)));
        } else {
            value = value.longValue();
            expected = 218L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[12].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[12].sid.code + "' != '" + 77 + "'",
                    value.equals(BigInteger.valueOf(77L)));
        } else {
            value = value.longValue();
            expected = 77L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[12].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[12].sid.sat + "' != '" + 169 + "'",
                    value.equals(BigInteger.valueOf(169L)));
        } else {
            value = value.longValue();
            expected = 169L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[13].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[13].cn0 + "' != '" + 249 + "'",
                    value.equals(BigInteger.valueOf(249L)));
        } else {
            value = value.longValue();
            expected = 249L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[13].fcn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[13].fcn + "' != '" + 171 + "'",
                    value.equals(BigInteger.valueOf(171L)));
        } else {
            value = value.longValue();
            expected = 171L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[13].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[13].sid.code + "' != '" + 84 + "'",
                    value.equals(BigInteger.valueOf(84L)));
        } else {
            value = value.longValue();
            expected = 84L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[13].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[13].sid.sat + "' != '" + 242 + "'",
                    value.equals(BigInteger.valueOf(242L)));
        } else {
            value = value.longValue();
            expected = 242L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[14].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[14].cn0 + "' != '" + 130 + "'",
                    value.equals(BigInteger.valueOf(130L)));
        } else {
            value = value.longValue();
            expected = 130L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[14].fcn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[14].fcn + "' != '" + 131 + "'",
                    value.equals(BigInteger.valueOf(131L)));
        } else {
            value = value.longValue();
            expected = 131L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[14].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[14].sid.code + "' != '" + 137 + "'",
                    value.equals(BigInteger.valueOf(137L)));
        } else {
            value = value.longValue();
            expected = 137L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[14].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[14].sid.sat + "' != '" + 152 + "'",
                    value.equals(BigInteger.valueOf(152L)));
        } else {
            value = value.longValue();
            expected = 152L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[15].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[15].cn0 + "' != '" + 68 + "'",
                    value.equals(BigInteger.valueOf(68L)));
        } else {
            value = value.longValue();
            expected = 68L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[15].fcn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[15].fcn + "' != '" + 42 + "'",
                    value.equals(BigInteger.valueOf(42L)));
        } else {
            value = value.longValue();
            expected = 42L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[15].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[15].sid.code + "' != '" + 21 + "'",
                    value.equals(BigInteger.valueOf(21L)));
        } else {
            value = value.longValue();
            expected = 21L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[15].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[15].sid.sat + "' != '" + 193 + "'",
                    value.equals(BigInteger.valueOf(193L)));
        } else {
            value = value.longValue();
            expected = 193L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[16].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[16].cn0 + "' != '" + 227 + "'",
                    value.equals(BigInteger.valueOf(227L)));
        } else {
            value = value.longValue();
            expected = 227L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[16].fcn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[16].fcn + "' != '" + 216 + "'",
                    value.equals(BigInteger.valueOf(216L)));
        } else {
            value = value.longValue();
            expected = 216L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[16].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[16].sid.code + "' != '" + 227 + "'",
                    value.equals(BigInteger.valueOf(227L)));
        } else {
            value = value.longValue();
            expected = 227L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[16].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[16].sid.sat + "' != '" + 253 + "'",
                    value.equals(BigInteger.valueOf(253L)));
        } else {
            value = value.longValue();
            expected = 253L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[17].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[17].cn0 + "' != '" + 179 + "'",
                    value.equals(BigInteger.valueOf(179L)));
        } else {
            value = value.longValue();
            expected = 179L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[17].fcn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[17].fcn + "' != '" + 210 + "'",
                    value.equals(BigInteger.valueOf(210L)));
        } else {
            value = value.longValue();
            expected = 210L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[17].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[17].sid.code + "' != '" + 26 + "'",
                    value.equals(BigInteger.valueOf(26L)));
        } else {
            value = value.longValue();
            expected = 26L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[17].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[17].sid.sat + "' != '" + 24 + "'",
                    value.equals(BigInteger.valueOf(24L)));
        } else {
            value = value.longValue();
            expected = 24L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[18].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[18].cn0 + "' != '" + 255 + "'",
                    value.equals(BigInteger.valueOf(255L)));
        } else {
            value = value.longValue();
            expected = 255L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[18].fcn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[18].fcn + "' != '" + 227 + "'",
                    value.equals(BigInteger.valueOf(227L)));
        } else {
            value = value.longValue();
            expected = 227L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[18].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[18].sid.code + "' != '" + 15 + "'",
                    value.equals(BigInteger.valueOf(15L)));
        } else {
            value = value.longValue();
            expected = 15L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[18].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[18].sid.sat + "' != '" + 19 + "'",
                    value.equals(BigInteger.valueOf(19L)));
        } else {
            value = value.longValue();
            expected = 19L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[19].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[19].cn0 + "' != '" + 200 + "'",
                    value.equals(BigInteger.valueOf(200L)));
        } else {
            value = value.longValue();
            expected = 200L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[19].fcn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[19].fcn + "' != '" + 187 + "'",
                    value.equals(BigInteger.valueOf(187L)));
        } else {
            value = value.longValue();
            expected = 187L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[19].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[19].sid.code + "' != '" + 75 + "'",
                    value.equals(BigInteger.valueOf(75L)));
        } else {
            value = value.longValue();
            expected = 75L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[19].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[19].sid.sat + "' != '" + 122 + "'",
                    value.equals(BigInteger.valueOf(122L)));
        } else {
            value = value.longValue();
            expected = 122L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[20].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[20].cn0 + "' != '" + 122 + "'",
                    value.equals(BigInteger.valueOf(122L)));
        } else {
            value = value.longValue();
            expected = 122L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[20].fcn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[20].fcn + "' != '" + 218 + "'",
                    value.equals(BigInteger.valueOf(218L)));
        } else {
            value = value.longValue();
            expected = 218L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[20].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[20].sid.code + "' != '" + 48 + "'",
                    value.equals(BigInteger.valueOf(48L)));
        } else {
            value = value.longValue();
            expected = 48L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[20].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[20].sid.sat + "' != '" + 217 + "'",
                    value.equals(BigInteger.valueOf(217L)));
        } else {
            value = value.longValue();
            expected = 217L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[21].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[21].cn0 + "' != '" + 149 + "'",
                    value.equals(BigInteger.valueOf(149L)));
        } else {
            value = value.longValue();
            expected = 149L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[21].fcn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[21].fcn + "' != '" + 142 + "'",
                    value.equals(BigInteger.valueOf(142L)));
        } else {
            value = value.longValue();
            expected = 142L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[21].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[21].sid.code + "' != '" + 238 + "'",
                    value.equals(BigInteger.valueOf(238L)));
        } else {
            value = value.longValue();
            expected = 238L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[21].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[21].sid.sat + "' != '" + 187 + "'",
                    value.equals(BigInteger.valueOf(187L)));
        } else {
            value = value.longValue();
            expected = 187L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[22].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[22].cn0 + "' != '" + 212 + "'",
                    value.equals(BigInteger.valueOf(212L)));
        } else {
            value = value.longValue();
            expected = 212L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[22].fcn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[22].fcn + "' != '" + 251 + "'",
                    value.equals(BigInteger.valueOf(251L)));
        } else {
            value = value.longValue();
            expected = 251L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[22].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[22].sid.code + "' != '" + 55 + "'",
                    value.equals(BigInteger.valueOf(55L)));
        } else {
            value = value.longValue();
            expected = 55L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[22].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[22].sid.sat + "' != '" + 238 + "'",
                    value.equals(BigInteger.valueOf(238L)));
        } else {
            value = value.longValue();
            expected = 238L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[23].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[23].cn0 + "' != '" + 104 + "'",
                    value.equals(BigInteger.valueOf(104L)));
        } else {
            value = value.longValue();
            expected = 104L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[23].fcn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[23].fcn + "' != '" + 194 + "'",
                    value.equals(BigInteger.valueOf(194L)));
        } else {
            value = value.longValue();
            expected = 194L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[23].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[23].sid.code + "' != '" + 160 + "'",
                    value.equals(BigInteger.valueOf(160L)));
        } else {
            value = value.longValue();
            expected = 160L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[23].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[23].sid.sat + "' != '" + 128 + "'",
                    value.equals(BigInteger.valueOf(128L)));
        } else {
            value = value.longValue();
            expected = 128L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[24].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[24].cn0 + "' != '" + 62 + "'",
                    value.equals(BigInteger.valueOf(62L)));
        } else {
            value = value.longValue();
            expected = 62L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[24].fcn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[24].fcn + "' != '" + 141 + "'",
                    value.equals(BigInteger.valueOf(141L)));
        } else {
            value = value.longValue();
            expected = 141L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[24].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[24].sid.code + "' != '" + 255 + "'",
                    value.equals(BigInteger.valueOf(255L)));
        } else {
            value = value.longValue();
            expected = 255L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[24].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[24].sid.sat + "' != '" + 113 + "'",
                    value.equals(BigInteger.valueOf(113L)));
        } else {
            value = value.longValue();
            expected = 113L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[25].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[25].cn0 + "' != '" + 39 + "'",
                    value.equals(BigInteger.valueOf(39L)));
        } else {
            value = value.longValue();
            expected = 39L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[25].fcn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[25].fcn + "' != '" + 245 + "'",
                    value.equals(BigInteger.valueOf(245L)));
        } else {
            value = value.longValue();
            expected = 245L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[25].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[25].sid.code + "' != '" + 69 + "'",
                    value.equals(BigInteger.valueOf(69L)));
        } else {
            value = value.longValue();
            expected = 69L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[25].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[25].sid.sat + "' != '" + 43 + "'",
                    value.equals(BigInteger.valueOf(43L)));
        } else {
            value = value.longValue();
            expected = 43L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[26].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[26].cn0 + "' != '" + 56 + "'",
                    value.equals(BigInteger.valueOf(56L)));
        } else {
            value = value.longValue();
            expected = 56L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[26].fcn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[26].fcn + "' != '" + 108 + "'",
                    value.equals(BigInteger.valueOf(108L)));
        } else {
            value = value.longValue();
            expected = 108L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[26].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[26].sid.code + "' != '" + 230 + "'",
                    value.equals(BigInteger.valueOf(230L)));
        } else {
            value = value.longValue();
            expected = 230L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[26].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[26].sid.sat + "' != '" + 100 + "'",
                    value.equals(BigInteger.valueOf(100L)));
        } else {
            value = value.longValue();
            expected = 100L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[27].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[27].cn0 + "' != '" + 143 + "'",
                    value.equals(BigInteger.valueOf(143L)));
        } else {
            value = value.longValue();
            expected = 143L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[27].fcn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[27].fcn + "' != '" + 149 + "'",
                    value.equals(BigInteger.valueOf(149L)));
        } else {
            value = value.longValue();
            expected = 149L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[27].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[27].sid.code + "' != '" + 68 + "'",
                    value.equals(BigInteger.valueOf(68L)));
        } else {
            value = value.longValue();
            expected = 68L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[27].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[27].sid.sat + "' != '" + 247 + "'",
                    value.equals(BigInteger.valueOf(247L)));
        } else {
            value = value.longValue();
            expected = 247L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[28].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[28].cn0 + "' != '" + 70 + "'",
                    value.equals(BigInteger.valueOf(70L)));
        } else {
            value = value.longValue();
            expected = 70L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[28].fcn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[28].fcn + "' != '" + 233 + "'",
                    value.equals(BigInteger.valueOf(233L)));
        } else {
            value = value.longValue();
            expected = 233L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[28].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[28].sid.code + "' != '" + 101 + "'",
                    value.equals(BigInteger.valueOf(101L)));
        } else {
            value = value.longValue();
            expected = 101L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[28].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[28].sid.sat + "' != '" + 137 + "'",
                    value.equals(BigInteger.valueOf(137L)));
        } else {
            value = value.longValue();
            expected = 137L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[29].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[29].cn0 + "' != '" + 110 + "'",
                    value.equals(BigInteger.valueOf(110L)));
        } else {
            value = value.longValue();
            expected = 110L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[29].fcn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[29].fcn + "' != '" + 38 + "'",
                    value.equals(BigInteger.valueOf(38L)));
        } else {
            value = value.longValue();
            expected = 38L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[29].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[29].sid.code + "' != '" + 165 + "'",
                    value.equals(BigInteger.valueOf(165L)));
        } else {
            value = value.longValue();
            expected = 165L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[29].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[29].sid.sat + "' != '" + 49 + "'",
                    value.equals(BigInteger.valueOf(49L)));
        } else {
            value = value.longValue();
            expected = 49L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[30].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[30].cn0 + "' != '" + 213 + "'",
                    value.equals(BigInteger.valueOf(213L)));
        } else {
            value = value.longValue();
            expected = 213L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[30].fcn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[30].fcn + "' != '" + 80 + "'",
                    value.equals(BigInteger.valueOf(80L)));
        } else {
            value = value.longValue();
            expected = 80L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[30].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[30].sid.code + "' != '" + 230 + "'",
                    value.equals(BigInteger.valueOf(230L)));
        } else {
            value = value.longValue();
            expected = 230L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[30].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[30].sid.sat + "' != '" + 218 + "'",
                    value.equals(BigInteger.valueOf(218L)));
        } else {
            value = value.longValue();
            expected = 218L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[31].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[31].cn0 + "' != '" + 128 + "'",
                    value.equals(BigInteger.valueOf(128L)));
        } else {
            value = value.longValue();
            expected = 128L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[31].fcn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[31].fcn + "' != '" + 139 + "'",
                    value.equals(BigInteger.valueOf(139L)));
        } else {
            value = value.longValue();
            expected = 139L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[31].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[31].sid.code + "' != '" + 179 + "'",
                    value.equals(BigInteger.valueOf(179L)));
        } else {
            value = value.longValue();
            expected = 179L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[31].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[31].sid.sat + "' != '" + 196 + "'",
                    value.equals(BigInteger.valueOf(196L)));
        } else {
            value = value.longValue();
            expected = 196L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[32].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[32].cn0 + "' != '" + 171 + "'",
                    value.equals(BigInteger.valueOf(171L)));
        } else {
            value = value.longValue();
            expected = 171L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[32].fcn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[32].fcn + "' != '" + 196 + "'",
                    value.equals(BigInteger.valueOf(196L)));
        } else {
            value = value.longValue();
            expected = 196L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[32].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[32].sid.code + "' != '" + 178 + "'",
                    value.equals(BigInteger.valueOf(178L)));
        } else {
            value = value.longValue();
            expected = 178L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[32].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[32].sid.sat + "' != '" + 15 + "'",
                    value.equals(BigInteger.valueOf(15L)));
        } else {
            value = value.longValue();
            expected = 15L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[33].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[33].cn0 + "' != '" + 194 + "'",
                    value.equals(BigInteger.valueOf(194L)));
        } else {
            value = value.longValue();
            expected = 194L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[33].fcn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[33].fcn + "' != '" + 97 + "'",
                    value.equals(BigInteger.valueOf(97L)));
        } else {
            value = value.longValue();
            expected = 97L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[33].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[33].sid.code + "' != '" + 212 + "'",
                    value.equals(BigInteger.valueOf(212L)));
        } else {
            value = value.longValue();
            expected = 212L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[33].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[33].sid.sat + "' != '" + 8 + "'",
                    value.equals(BigInteger.valueOf(8L)));
        } else {
            value = value.longValue();
            expected = 8L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[34].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[34].cn0 + "' != '" + 99 + "'",
                    value.equals(BigInteger.valueOf(99L)));
        } else {
            value = value.longValue();
            expected = 99L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[34].fcn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[34].fcn + "' != '" + 79 + "'",
                    value.equals(BigInteger.valueOf(79L)));
        } else {
            value = value.longValue();
            expected = 79L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[34].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[34].sid.code + "' != '" + 233 + "'",
                    value.equals(BigInteger.valueOf(233L)));
        } else {
            value = value.longValue();
            expected = 233L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[34].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[34].sid.sat + "' != '" + 83 + "'",
                    value.equals(BigInteger.valueOf(83L)));
        } else {
            value = value.longValue();
            expected = 83L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[35].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[35].cn0 + "' != '" + 180 + "'",
                    value.equals(BigInteger.valueOf(180L)));
        } else {
            value = value.longValue();
            expected = 180L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[35].fcn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[35].fcn + "' != '" + 31 + "'",
                    value.equals(BigInteger.valueOf(31L)));
        } else {
            value = value.longValue();
            expected = 31L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[35].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[35].sid.code + "' != '" + 90 + "'",
                    value.equals(BigInteger.valueOf(90L)));
        } else {
            value = value.longValue();
            expected = 90L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[35].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[35].sid.sat + "' != '" + 55 + "'",
                    value.equals(BigInteger.valueOf(55L)));
        } else {
            value = value.longValue();
            expected = 55L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[36].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[36].cn0 + "' != '" + 186 + "'",
                    value.equals(BigInteger.valueOf(186L)));
        } else {
            value = value.longValue();
            expected = 186L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[36].fcn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[36].fcn + "' != '" + 105 + "'",
                    value.equals(BigInteger.valueOf(105L)));
        } else {
            value = value.longValue();
            expected = 105L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[36].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[36].sid.code + "' != '" + 25 + "'",
                    value.equals(BigInteger.valueOf(25L)));
        } else {
            value = value.longValue();
            expected = 25L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[36].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[36].sid.sat + "' != '" + 5 + "'",
                    value.equals(BigInteger.valueOf(5L)));
        } else {
            value = value.longValue();
            expected = 5L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[37].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[37].cn0 + "' != '" + 111 + "'",
                    value.equals(BigInteger.valueOf(111L)));
        } else {
            value = value.longValue();
            expected = 111L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[37].fcn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[37].fcn + "' != '" + 80 + "'",
                    value.equals(BigInteger.valueOf(80L)));
        } else {
            value = value.longValue();
            expected = 80L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[37].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[37].sid.code + "' != '" + 224 + "'",
                    value.equals(BigInteger.valueOf(224L)));
        } else {
            value = value.longValue();
            expected = 224L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[37].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[37].sid.sat + "' != '" + 22 + "'",
                    value.equals(BigInteger.valueOf(22L)));
        } else {
            value = value.longValue();
            expected = 22L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[38].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[38].cn0 + "' != '" + 166 + "'",
                    value.equals(BigInteger.valueOf(166L)));
        } else {
            value = value.longValue();
            expected = 166L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[38].fcn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[38].fcn + "' != '" + 106 + "'",
                    value.equals(BigInteger.valueOf(106L)));
        } else {
            value = value.longValue();
            expected = 106L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[38].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[38].sid.code + "' != '" + 48 + "'",
                    value.equals(BigInteger.valueOf(48L)));
        } else {
            value = value.longValue();
            expected = 48L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[38].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[38].sid.sat + "' != '" + 8 + "'",
                    value.equals(BigInteger.valueOf(8L)));
        } else {
            value = value.longValue();
            expected = 8L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[39].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[39].cn0 + "' != '" + 49 + "'",
                    value.equals(BigInteger.valueOf(49L)));
        } else {
            value = value.longValue();
            expected = 49L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[39].fcn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[39].fcn + "' != '" + 156 + "'",
                    value.equals(BigInteger.valueOf(156L)));
        } else {
            value = value.longValue();
            expected = 156L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[39].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[39].sid.code + "' != '" + 48 + "'",
                    value.equals(BigInteger.valueOf(48L)));
        } else {
            value = value.longValue();
            expected = 48L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[39].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[39].sid.sat + "' != '" + 4 + "'",
                    value.equals(BigInteger.valueOf(4L)));
        } else {
            value = value.longValue();
            expected = 4L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[40].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[40].cn0 + "' != '" + 146 + "'",
                    value.equals(BigInteger.valueOf(146L)));
        } else {
            value = value.longValue();
            expected = 146L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[40].fcn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[40].fcn + "' != '" + 142 + "'",
                    value.equals(BigInteger.valueOf(142L)));
        } else {
            value = value.longValue();
            expected = 142L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[40].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[40].sid.code + "' != '" + 19 + "'",
                    value.equals(BigInteger.valueOf(19L)));
        } else {
            value = value.longValue();
            expected = 19L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[40].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[40].sid.sat + "' != '" + 86 + "'",
                    value.equals(BigInteger.valueOf(86L)));
        } else {
            value = value.longValue();
            expected = 86L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[41].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[41].cn0 + "' != '" + 64 + "'",
                    value.equals(BigInteger.valueOf(64L)));
        } else {
            value = value.longValue();
            expected = 64L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[41].fcn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[41].fcn + "' != '" + 115 + "'",
                    value.equals(BigInteger.valueOf(115L)));
        } else {
            value = value.longValue();
            expected = 115L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[41].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[41].sid.code + "' != '" + 124 + "'",
                    value.equals(BigInteger.valueOf(124L)));
        } else {
            value = value.longValue();
            expected = 124L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[41].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[41].sid.sat + "' != '" + 91 + "'",
                    value.equals(BigInteger.valueOf(91L)));
        } else {
            value = value.longValue();
            expected = 91L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[42].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[42].cn0 + "' != '" + 178 + "'",
                    value.equals(BigInteger.valueOf(178L)));
        } else {
            value = value.longValue();
            expected = 178L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[42].fcn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[42].fcn + "' != '" + 115 + "'",
                    value.equals(BigInteger.valueOf(115L)));
        } else {
            value = value.longValue();
            expected = 115L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[42].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[42].sid.code + "' != '" + 230 + "'",
                    value.equals(BigInteger.valueOf(230L)));
        } else {
            value = value.longValue();
            expected = 230L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[42].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[42].sid.sat + "' != '" + 28 + "'",
                    value.equals(BigInteger.valueOf(28L)));
        } else {
            value = value.longValue();
            expected = 28L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[43].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[43].cn0 + "' != '" + 242 + "'",
                    value.equals(BigInteger.valueOf(242L)));
        } else {
            value = value.longValue();
            expected = 242L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[43].fcn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[43].fcn + "' != '" + 16 + "'",
                    value.equals(BigInteger.valueOf(16L)));
        } else {
            value = value.longValue();
            expected = 16L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[43].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[43].sid.code + "' != '" + 131 + "'",
                    value.equals(BigInteger.valueOf(131L)));
        } else {
            value = value.longValue();
            expected = 131L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[43].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[43].sid.sat + "' != '" + 190 + "'",
                    value.equals(BigInteger.valueOf(190L)));
        } else {
            value = value.longValue();
            expected = 190L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[44].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[44].cn0 + "' != '" + 113 + "'",
                    value.equals(BigInteger.valueOf(113L)));
        } else {
            value = value.longValue();
            expected = 113L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[44].fcn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[44].fcn + "' != '" + 182 + "'",
                    value.equals(BigInteger.valueOf(182L)));
        } else {
            value = value.longValue();
            expected = 182L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[44].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[44].sid.code + "' != '" + 59 + "'",
                    value.equals(BigInteger.valueOf(59L)));
        } else {
            value = value.longValue();
            expected = 59L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[44].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[44].sid.sat + "' != '" + 105 + "'",
                    value.equals(BigInteger.valueOf(105L)));
        } else {
            value = value.longValue();
            expected = 105L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[45].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[45].cn0 + "' != '" + 179 + "'",
                    value.equals(BigInteger.valueOf(179L)));
        } else {
            value = value.longValue();
            expected = 179L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[45].fcn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[45].fcn + "' != '" + 48 + "'",
                    value.equals(BigInteger.valueOf(48L)));
        } else {
            value = value.longValue();
            expected = 48L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[45].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[45].sid.code + "' != '" + 180 + "'",
                    value.equals(BigInteger.valueOf(180L)));
        } else {
            value = value.longValue();
            expected = 180L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[45].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[45].sid.sat + "' != '" + 192 + "'",
                    value.equals(BigInteger.valueOf(192L)));
        } else {
            value = value.longValue();
            expected = 192L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[46].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[46].cn0 + "' != '" + 211 + "'",
                    value.equals(BigInteger.valueOf(211L)));
        } else {
            value = value.longValue();
            expected = 211L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[46].fcn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[46].fcn + "' != '" + 172 + "'",
                    value.equals(BigInteger.valueOf(172L)));
        } else {
            value = value.longValue();
            expected = 172L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[46].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[46].sid.code + "' != '" + 31 + "'",
                    value.equals(BigInteger.valueOf(31L)));
        } else {
            value = value.longValue();
            expected = 31L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[46].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[46].sid.sat + "' != '" + 166 + "'",
                    value.equals(BigInteger.valueOf(166L)));
        } else {
            value = value.longValue();
            expected = 166L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[47].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[47].cn0 + "' != '" + 49 + "'",
                    value.equals(BigInteger.valueOf(49L)));
        } else {
            value = value.longValue();
            expected = 49L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[47].fcn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[47].fcn + "' != '" + 140 + "'",
                    value.equals(BigInteger.valueOf(140L)));
        } else {
            value = value.longValue();
            expected = 140L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[47].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[47].sid.code + "' != '" + 228 + "'",
                    value.equals(BigInteger.valueOf(228L)));
        } else {
            value = value.longValue();
            expected = 228L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[47].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[47].sid.sat + "' != '" + 77 + "'",
                    value.equals(BigInteger.valueOf(77L)));
        } else {
            value = value.longValue();
            expected = 77L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[48].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[48].cn0 + "' != '" + 194 + "'",
                    value.equals(BigInteger.valueOf(194L)));
        } else {
            value = value.longValue();
            expected = 194L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[48].fcn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[48].fcn + "' != '" + 240 + "'",
                    value.equals(BigInteger.valueOf(240L)));
        } else {
            value = value.longValue();
            expected = 240L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[48].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[48].sid.code + "' != '" + 77 + "'",
                    value.equals(BigInteger.valueOf(77L)));
        } else {
            value = value.longValue();
            expected = 77L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[48].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[48].sid.sat + "' != '" + 128 + "'",
                    value.equals(BigInteger.valueOf(128L)));
        } else {
            value = value.longValue();
            expected = 128L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[49].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[49].cn0 + "' != '" + 58 + "'",
                    value.equals(BigInteger.valueOf(58L)));
        } else {
            value = value.longValue();
            expected = 58L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[49].fcn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[49].fcn + "' != '" + 41 + "'",
                    value.equals(BigInteger.valueOf(41L)));
        } else {
            value = value.longValue();
            expected = 41L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[49].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[49].sid.code + "' != '" + 194 + "'",
                    value.equals(BigInteger.valueOf(194L)));
        } else {
            value = value.longValue();
            expected = 194L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[49].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[49].sid.sat + "' != '" + 134 + "'",
                    value.equals(BigInteger.valueOf(134L)));
        } else {
            value = value.longValue();
            expected = 134L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[50].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[50].cn0 + "' != '" + 55 + "'",
                    value.equals(BigInteger.valueOf(55L)));
        } else {
            value = value.longValue();
            expected = 55L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[50].fcn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[50].fcn + "' != '" + 129 + "'",
                    value.equals(BigInteger.valueOf(129L)));
        } else {
            value = value.longValue();
            expected = 129L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[50].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[50].sid.code + "' != '" + 53 + "'",
                    value.equals(BigInteger.valueOf(53L)));
        } else {
            value = value.longValue();
            expected = 53L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[50].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[50].sid.sat + "' != '" + 18 + "'",
                    value.equals(BigInteger.valueOf(18L)));
        } else {
            value = value.longValue();
            expected = 18L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[51].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[51].cn0 + "' != '" + 92 + "'",
                    value.equals(BigInteger.valueOf(92L)));
        } else {
            value = value.longValue();
            expected = 92L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[51].fcn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[51].fcn + "' != '" + 134 + "'",
                    value.equals(BigInteger.valueOf(134L)));
        } else {
            value = value.longValue();
            expected = 134L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[51].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[51].sid.code + "' != '" + 72 + "'",
                    value.equals(BigInteger.valueOf(72L)));
        } else {
            value = value.longValue();
            expected = 72L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[51].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[51].sid.sat + "' != '" + 91 + "'",
                    value.equals(BigInteger.valueOf(91L)));
        } else {
            value = value.longValue();
            expected = 91L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[52].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[52].cn0 + "' != '" + 56 + "'",
                    value.equals(BigInteger.valueOf(56L)));
        } else {
            value = value.longValue();
            expected = 56L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[52].fcn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[52].fcn + "' != '" + 157 + "'",
                    value.equals(BigInteger.valueOf(157L)));
        } else {
            value = value.longValue();
            expected = 157L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[52].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[52].sid.code + "' != '" + 224 + "'",
                    value.equals(BigInteger.valueOf(224L)));
        } else {
            value = value.longValue();
            expected = 224L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[52].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[52].sid.sat + "' != '" + 33 + "'",
                    value.equals(BigInteger.valueOf(33L)));
        } else {
            value = value.longValue();
            expected = 33L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[53].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[53].cn0 + "' != '" + 174 + "'",
                    value.equals(BigInteger.valueOf(174L)));
        } else {
            value = value.longValue();
            expected = 174L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[53].fcn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[53].fcn + "' != '" + 224 + "'",
                    value.equals(BigInteger.valueOf(224L)));
        } else {
            value = value.longValue();
            expected = 224L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[53].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[53].sid.code + "' != '" + 54 + "'",
                    value.equals(BigInteger.valueOf(54L)));
        } else {
            value = value.longValue();
            expected = 54L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[53].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[53].sid.sat + "' != '" + 186 + "'",
                    value.equals(BigInteger.valueOf(186L)));
        } else {
            value = value.longValue();
            expected = 186L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[54].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[54].cn0 + "' != '" + 190 + "'",
                    value.equals(BigInteger.valueOf(190L)));
        } else {
            value = value.longValue();
            expected = 190L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[54].fcn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[54].fcn + "' != '" + 148 + "'",
                    value.equals(BigInteger.valueOf(148L)));
        } else {
            value = value.longValue();
            expected = 148L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[54].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[54].sid.code + "' != '" + 84 + "'",
                    value.equals(BigInteger.valueOf(84L)));
        } else {
            value = value.longValue();
            expected = 84L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[54].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[54].sid.sat + "' != '" + 82 + "'",
                    value.equals(BigInteger.valueOf(82L)));
        } else {
            value = value.longValue();
            expected = 82L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[55].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[55].cn0 + "' != '" + 67 + "'",
                    value.equals(BigInteger.valueOf(67L)));
        } else {
            value = value.longValue();
            expected = 67L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[55].fcn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[55].fcn + "' != '" + 62 + "'",
                    value.equals(BigInteger.valueOf(62L)));
        } else {
            value = value.longValue();
            expected = 62L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[55].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[55].sid.code + "' != '" + 54 + "'",
                    value.equals(BigInteger.valueOf(54L)));
        } else {
            value = value.longValue();
            expected = 54L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[55].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[55].sid.sat + "' != '" + 236 + "'",
                    value.equals(BigInteger.valueOf(236L)));
        } else {
            value = value.longValue();
            expected = 236L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[56].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[56].cn0 + "' != '" + 254 + "'",
                    value.equals(BigInteger.valueOf(254L)));
        } else {
            value = value.longValue();
            expected = 254L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[56].fcn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[56].fcn + "' != '" + 57 + "'",
                    value.equals(BigInteger.valueOf(57L)));
        } else {
            value = value.longValue();
            expected = 57L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[56].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[56].sid.code + "' != '" + 215 + "'",
                    value.equals(BigInteger.valueOf(215L)));
        } else {
            value = value.longValue();
            expected = 215L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[56].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[56].sid.sat + "' != '" + 52 + "'",
                    value.equals(BigInteger.valueOf(52L)));
        } else {
            value = value.longValue();
            expected = 52L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[57].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[57].cn0 + "' != '" + 174 + "'",
                    value.equals(BigInteger.valueOf(174L)));
        } else {
            value = value.longValue();
            expected = 174L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[57].fcn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[57].fcn + "' != '" + 36 + "'",
                    value.equals(BigInteger.valueOf(36L)));
        } else {
            value = value.longValue();
            expected = 36L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[57].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[57].sid.code + "' != '" + 133 + "'",
                    value.equals(BigInteger.valueOf(133L)));
        } else {
            value = value.longValue();
            expected = 133L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[57].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[57].sid.sat + "' != '" + 16 + "'",
                    value.equals(BigInteger.valueOf(16L)));
        } else {
            value = value.longValue();
            expected = 16L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[58].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[58].cn0 + "' != '" + 17 + "'",
                    value.equals(BigInteger.valueOf(17L)));
        } else {
            value = value.longValue();
            expected = 17L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[58].fcn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[58].fcn + "' != '" + 145 + "'",
                    value.equals(BigInteger.valueOf(145L)));
        } else {
            value = value.longValue();
            expected = 145L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[58].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[58].sid.code + "' != '" + 172 + "'",
                    value.equals(BigInteger.valueOf(172L)));
        } else {
            value = value.longValue();
            expected = 172L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[58].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[58].sid.sat + "' != '" + 219 + "'",
                    value.equals(BigInteger.valueOf(219L)));
        } else {
            value = value.longValue();
            expected = 219L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[59].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[59].cn0 + "' != '" + 97 + "'",
                    value.equals(BigInteger.valueOf(97L)));
        } else {
            value = value.longValue();
            expected = 97L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[59].fcn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[59].fcn + "' != '" + 111 + "'",
                    value.equals(BigInteger.valueOf(111L)));
        } else {
            value = value.longValue();
            expected = 111L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[59].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[59].sid.code + "' != '" + 179 + "'",
                    value.equals(BigInteger.valueOf(179L)));
        } else {
            value = value.longValue();
            expected = 179L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[59].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[59].sid.sat + "' != '" + 192 + "'",
                    value.equals(BigInteger.valueOf(192L)));
        } else {
            value = value.longValue();
            expected = 192L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[60].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[60].cn0 + "' != '" + 134 + "'",
                    value.equals(BigInteger.valueOf(134L)));
        } else {
            value = value.longValue();
            expected = 134L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[60].fcn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[60].fcn + "' != '" + 208 + "'",
                    value.equals(BigInteger.valueOf(208L)));
        } else {
            value = value.longValue();
            expected = 208L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[60].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[60].sid.code + "' != '" + 56 + "'",
                    value.equals(BigInteger.valueOf(56L)));
        } else {
            value = value.longValue();
            expected = 56L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[60].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[60].sid.sat + "' != '" + 207 + "'",
                    value.equals(BigInteger.valueOf(207L)));
        } else {
            value = value.longValue();
            expected = 207L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[61].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[61].cn0 + "' != '" + 226 + "'",
                    value.equals(BigInteger.valueOf(226L)));
        } else {
            value = value.longValue();
            expected = 226L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[61].fcn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[61].fcn + "' != '" + 43 + "'",
                    value.equals(BigInteger.valueOf(43L)));
        } else {
            value = value.longValue();
            expected = 43L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[61].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[61].sid.code + "' != '" + 17 + "'",
                    value.equals(BigInteger.valueOf(17L)));
        } else {
            value = value.longValue();
            expected = 17L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[61].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[61].sid.sat + "' != '" + 180 + "'",
                    value.equals(BigInteger.valueOf(180L)));
        } else {
            value = value.longValue();
            expected = 180L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[62].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[62].cn0 + "' != '" + 113 + "'",
                    value.equals(BigInteger.valueOf(113L)));
        } else {
            value = value.longValue();
            expected = 113L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[62].fcn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[62].fcn + "' != '" + 140 + "'",
                    value.equals(BigInteger.valueOf(140L)));
        } else {
            value = value.longValue();
            expected = 140L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[62].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[62].sid.code + "' != '" + 182 + "'",
                    value.equals(BigInteger.valueOf(182L)));
        } else {
            value = value.longValue();
            expected = 182L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[62].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[62].sid.sat + "' != '" + 255 + "'",
                    value.equals(BigInteger.valueOf(255L)));
        } else {
            value = value.longValue();
            expected = 255L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }

    @Test
    public void test2() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_tracking_MsgTrackingStateTest.test2");
        byte[] payload =
                new byte[] {
                    (byte) 1, (byte) 202, (byte) 0, (byte) 0, (byte) 0, (byte) 197, (byte) 253,
                    (byte) 28, (byte) 66, (byte) 1, (byte) 203, (byte) 0, (byte) 0, (byte) 0,
                    (byte) 231, (byte) 99, (byte) 16, (byte) 66, (byte) 1, (byte) 208, (byte) 0,
                    (byte) 0, (byte) 0, (byte) 212, (byte) 129, (byte) 22, (byte) 66, (byte) 1,
                    (byte) 212, (byte) 0, (byte) 0, (byte) 0, (byte) 58, (byte) 21, (byte) 28,
                    (byte) 66, (byte) 1, (byte) 217, (byte) 0, (byte) 0, (byte) 0, (byte) 178,
                    (byte) 33, (byte) 40, (byte) 66, (byte) 1, (byte) 218, (byte) 0, (byte) 0,
                    (byte) 0, (byte) 235, (byte) 189, (byte) 21, (byte) 66, (byte) 1, (byte) 220,
                    (byte) 0, (byte) 0, (byte) 0, (byte) 29, (byte) 177, (byte) 25, (byte) 66,
                    (byte) 1, (byte) 222, (byte) 0, (byte) 0, (byte) 0, (byte) 43, (byte) 169,
                    (byte) 27, (byte) 66, (byte) 1, (byte) 225, (byte) 0, (byte) 0, (byte) 0,
                    (byte) 137, (byte) 125, (byte) 42, (byte) 66, (byte) 0, (byte) 0, (byte) 0,
                    (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 128, (byte) 191, (byte) 0,
                    (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 128,
                    (byte) 191,
                };
        SBPMessage sbp = new SBPMessage(0xd7f6, 0x13, payload);
        MsgTrackingStateDepB msg = new MsgTrackingStateDepB(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        org.junit.Assert.assertEquals(msg.states[0].cn0, 3.92478218078613281e+01, DELTA);
        value = msg.states[0].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[0].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[0].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[0].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[0].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[0].sid.sat + "' != '" + 202 + "'",
                    value.equals(BigInteger.valueOf(202L)));
        } else {
            value = value.longValue();
            expected = 202L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[0].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[0].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[1].cn0, 3.60975608825683594e+01, DELTA);
        value = msg.states[1].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[1].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[1].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[1].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[1].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[1].sid.sat + "' != '" + 203 + "'",
                    value.equals(BigInteger.valueOf(203L)));
        } else {
            value = value.longValue();
            expected = 203L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[1].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[1].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[2].cn0, 3.76267852783203125e+01, DELTA);
        value = msg.states[2].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[2].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[2].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[2].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[2].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[2].sid.sat + "' != '" + 208 + "'",
                    value.equals(BigInteger.valueOf(208L)));
        } else {
            value = value.longValue();
            expected = 208L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[2].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[2].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[3].cn0, 3.90207290649414062e+01, DELTA);
        value = msg.states[3].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[3].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[3].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[3].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[3].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[3].sid.sat + "' != '" + 212 + "'",
                    value.equals(BigInteger.valueOf(212L)));
        } else {
            value = value.longValue();
            expected = 212L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[3].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[3].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[4].cn0, 4.20329055786132812e+01, DELTA);
        value = msg.states[4].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[4].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[4].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[4].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[4].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[4].sid.sat + "' != '" + 217 + "'",
                    value.equals(BigInteger.valueOf(217L)));
        } else {
            value = value.longValue();
            expected = 217L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[4].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[4].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[5].cn0, 3.74354667663574219e+01, DELTA);
        value = msg.states[5].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[5].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[5].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[5].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[5].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[5].sid.sat + "' != '" + 218 + "'",
                    value.equals(BigInteger.valueOf(218L)));
        } else {
            value = value.longValue();
            expected = 218L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[5].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[5].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[6].cn0, 3.84229621887207031e+01, DELTA);
        value = msg.states[6].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[6].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[6].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[6].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[6].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[6].sid.sat + "' != '" + 220 + "'",
                    value.equals(BigInteger.valueOf(220L)));
        } else {
            value = value.longValue();
            expected = 220L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[6].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[6].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[7].cn0, 3.89152030944824219e+01, DELTA);
        value = msg.states[7].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[7].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[7].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[7].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[7].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[7].sid.sat + "' != '" + 222 + "'",
                    value.equals(BigInteger.valueOf(222L)));
        } else {
            value = value.longValue();
            expected = 222L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[7].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[7].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[8].cn0, 4.26225929260253906e+01, DELTA);
        value = msg.states[8].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[8].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[8].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[8].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[8].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[8].sid.sat + "' != '" + 225 + "'",
                    value.equals(BigInteger.valueOf(225L)));
        } else {
            value = value.longValue();
            expected = 225L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[8].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[8].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[9].cn0, -1.00000000000000000e+00, DELTA);
        value = msg.states[9].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[9].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[9].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[9].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[9].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[9].sid.sat + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[9].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[9].state + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[10].cn0, -1.00000000000000000e+00, DELTA);
        value = msg.states[10].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[10].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[10].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[10].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[10].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[10].sid.sat + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[10].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[10].state + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }

    @Test
    public void test3() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_tracking_MsgTrackingStateTest.test3");
        byte[] payload =
                new byte[] {
                    (byte) 1, (byte) 202, (byte) 0, (byte) 0, (byte) 0, (byte) 250, (byte) 249,
                    (byte) 27, (byte) 66, (byte) 1, (byte) 203, (byte) 0, (byte) 0, (byte) 0,
                    (byte) 40, (byte) 143, (byte) 11, (byte) 66, (byte) 1, (byte) 208, (byte) 0,
                    (byte) 0, (byte) 0, (byte) 190, (byte) 200, (byte) 21, (byte) 66, (byte) 1,
                    (byte) 212, (byte) 0, (byte) 0, (byte) 0, (byte) 251, (byte) 233, (byte) 26,
                    (byte) 66, (byte) 1, (byte) 217, (byte) 0, (byte) 0, (byte) 0, (byte) 209,
                    (byte) 238, (byte) 39, (byte) 66, (byte) 1, (byte) 218, (byte) 0, (byte) 0,
                    (byte) 0, (byte) 162, (byte) 219, (byte) 21, (byte) 66, (byte) 1, (byte) 220,
                    (byte) 0, (byte) 0, (byte) 0, (byte) 162, (byte) 197, (byte) 25, (byte) 66,
                    (byte) 1, (byte) 222, (byte) 0, (byte) 0, (byte) 0, (byte) 14, (byte) 35,
                    (byte) 28, (byte) 66, (byte) 1, (byte) 225, (byte) 0, (byte) 0, (byte) 0,
                    (byte) 9, (byte) 153, (byte) 43, (byte) 66, (byte) 0, (byte) 0, (byte) 0,
                    (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 128, (byte) 191, (byte) 0,
                    (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 128,
                    (byte) 191,
                };
        SBPMessage sbp = new SBPMessage(0xd7f6, 0x13, payload);
        MsgTrackingStateDepB msg = new MsgTrackingStateDepB(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        org.junit.Assert.assertEquals(msg.states[0].cn0, 3.89941177368164062e+01, DELTA);
        value = msg.states[0].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[0].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[0].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[0].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[0].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[0].sid.sat + "' != '" + 202 + "'",
                    value.equals(BigInteger.valueOf(202L)));
        } else {
            value = value.longValue();
            expected = 202L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[0].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[0].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[1].cn0, 3.48898010253906250e+01, DELTA);
        value = msg.states[1].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[1].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[1].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[1].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[1].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[1].sid.sat + "' != '" + 203 + "'",
                    value.equals(BigInteger.valueOf(203L)));
        } else {
            value = value.longValue();
            expected = 203L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[1].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[1].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[2].cn0, 3.74460372924804688e+01, DELTA);
        value = msg.states[2].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[2].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[2].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[2].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[2].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[2].sid.sat + "' != '" + 208 + "'",
                    value.equals(BigInteger.valueOf(208L)));
        } else {
            value = value.longValue();
            expected = 208L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[2].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[2].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[3].cn0, 3.87284965515136719e+01, DELTA);
        value = msg.states[3].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[3].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[3].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[3].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[3].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[3].sid.sat + "' != '" + 212 + "'",
                    value.equals(BigInteger.valueOf(212L)));
        } else {
            value = value.longValue();
            expected = 212L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[3].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[3].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[4].cn0, 4.19832191467285156e+01, DELTA);
        value = msg.states[4].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[4].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[4].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[4].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[4].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[4].sid.sat + "' != '" + 217 + "'",
                    value.equals(BigInteger.valueOf(217L)));
        } else {
            value = value.longValue();
            expected = 217L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[4].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[4].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[5].cn0, 3.74644851684570312e+01, DELTA);
        value = msg.states[5].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[5].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[5].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[5].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[5].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[5].sid.sat + "' != '" + 218 + "'",
                    value.equals(BigInteger.valueOf(218L)));
        } else {
            value = value.longValue();
            expected = 218L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[5].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[5].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[6].cn0, 3.84430007934570312e+01, DELTA);
        value = msg.states[6].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[6].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[6].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[6].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[6].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[6].sid.sat + "' != '" + 220 + "'",
                    value.equals(BigInteger.valueOf(220L)));
        } else {
            value = value.longValue();
            expected = 220L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[6].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[6].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[7].cn0, 3.90342330932617188e+01, DELTA);
        value = msg.states[7].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[7].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[7].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[7].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[7].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[7].sid.sat + "' != '" + 222 + "'",
                    value.equals(BigInteger.valueOf(222L)));
        } else {
            value = value.longValue();
            expected = 222L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[7].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[7].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[8].cn0, 4.28994483947753906e+01, DELTA);
        value = msg.states[8].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[8].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[8].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[8].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[8].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[8].sid.sat + "' != '" + 225 + "'",
                    value.equals(BigInteger.valueOf(225L)));
        } else {
            value = value.longValue();
            expected = 225L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[8].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[8].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[9].cn0, -1.00000000000000000e+00, DELTA);
        value = msg.states[9].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[9].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[9].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[9].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[9].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[9].sid.sat + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[9].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[9].state + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[10].cn0, -1.00000000000000000e+00, DELTA);
        value = msg.states[10].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[10].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[10].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[10].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[10].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[10].sid.sat + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[10].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[10].state + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }

    @Test
    public void test4() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_tracking_MsgTrackingStateTest.test4");
        byte[] payload =
                new byte[] {
                    (byte) 1, (byte) 202, (byte) 0, (byte) 0, (byte) 0, (byte) 123, (byte) 209,
                    (byte) 27, (byte) 66, (byte) 1, (byte) 203, (byte) 0, (byte) 0, (byte) 0,
                    (byte) 214, (byte) 64, (byte) 15, (byte) 66, (byte) 1, (byte) 208, (byte) 0,
                    (byte) 0, (byte) 0, (byte) 56, (byte) 55, (byte) 22, (byte) 66, (byte) 1,
                    (byte) 212, (byte) 0, (byte) 0, (byte) 0, (byte) 91, (byte) 142, (byte) 27,
                    (byte) 66, (byte) 1, (byte) 217, (byte) 0, (byte) 0, (byte) 0, (byte) 253,
                    (byte) 154, (byte) 41, (byte) 66, (byte) 1, (byte) 218, (byte) 0, (byte) 0,
                    (byte) 0, (byte) 128, (byte) 142, (byte) 22, (byte) 66, (byte) 1, (byte) 220,
                    (byte) 0, (byte) 0, (byte) 0, (byte) 17, (byte) 174, (byte) 23, (byte) 66,
                    (byte) 1, (byte) 222, (byte) 0, (byte) 0, (byte) 0, (byte) 155, (byte) 2,
                    (byte) 29, (byte) 66, (byte) 1, (byte) 225, (byte) 0, (byte) 0, (byte) 0,
                    (byte) 162, (byte) 100, (byte) 42, (byte) 66, (byte) 0, (byte) 0, (byte) 0,
                    (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 128, (byte) 191, (byte) 0,
                    (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 128,
                    (byte) 191,
                };
        SBPMessage sbp = new SBPMessage(0xd7f6, 0x13, payload);
        MsgTrackingStateDepB msg = new MsgTrackingStateDepB(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        org.junit.Assert.assertEquals(msg.states[0].cn0, 3.89545707702636719e+01, DELTA);
        value = msg.states[0].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[0].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[0].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[0].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[0].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[0].sid.sat + "' != '" + 202 + "'",
                    value.equals(BigInteger.valueOf(202L)));
        } else {
            value = value.longValue();
            expected = 202L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[0].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[0].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[1].cn0, 3.58133163452148438e+01, DELTA);
        value = msg.states[1].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[1].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[1].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[1].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[1].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[1].sid.sat + "' != '" + 203 + "'",
                    value.equals(BigInteger.valueOf(203L)));
        } else {
            value = value.longValue();
            expected = 203L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[1].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[1].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[2].cn0, 3.75539245605468750e+01, DELTA);
        value = msg.states[2].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[2].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[2].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[2].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[2].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[2].sid.sat + "' != '" + 208 + "'",
                    value.equals(BigInteger.valueOf(208L)));
        } else {
            value = value.longValue();
            expected = 208L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[2].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[2].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[3].cn0, 3.88890190124511719e+01, DELTA);
        value = msg.states[3].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[3].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[3].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[3].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[3].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[3].sid.sat + "' != '" + 212 + "'",
                    value.equals(BigInteger.valueOf(212L)));
        } else {
            value = value.longValue();
            expected = 212L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[3].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[3].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[4].cn0, 4.24013557434082031e+01, DELTA);
        value = msg.states[4].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[4].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[4].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[4].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[4].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[4].sid.sat + "' != '" + 217 + "'",
                    value.equals(BigInteger.valueOf(217L)));
        } else {
            value = value.longValue();
            expected = 217L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[4].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[4].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[5].cn0, 3.76391601562500000e+01, DELTA);
        value = msg.states[5].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[5].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[5].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[5].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[5].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[5].sid.sat + "' != '" + 218 + "'",
                    value.equals(BigInteger.valueOf(218L)));
        } else {
            value = value.longValue();
            expected = 218L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[5].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[5].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[6].cn0, 3.79199867248535156e+01, DELTA);
        value = msg.states[6].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[6].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[6].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[6].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[6].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[6].sid.sat + "' != '" + 220 + "'",
                    value.equals(BigInteger.valueOf(220L)));
        } else {
            value = value.longValue();
            expected = 220L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[6].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[6].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[7].cn0, 3.92525444030761719e+01, DELTA);
        value = msg.states[7].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[7].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[7].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[7].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[7].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[7].sid.sat + "' != '" + 222 + "'",
                    value.equals(BigInteger.valueOf(222L)));
        } else {
            value = value.longValue();
            expected = 222L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[7].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[7].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[8].cn0, 4.25982742309570312e+01, DELTA);
        value = msg.states[8].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[8].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[8].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[8].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[8].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[8].sid.sat + "' != '" + 225 + "'",
                    value.equals(BigInteger.valueOf(225L)));
        } else {
            value = value.longValue();
            expected = 225L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[8].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[8].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[9].cn0, -1.00000000000000000e+00, DELTA);
        value = msg.states[9].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[9].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[9].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[9].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[9].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[9].sid.sat + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[9].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[9].state + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[10].cn0, -1.00000000000000000e+00, DELTA);
        value = msg.states[10].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[10].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[10].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[10].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[10].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[10].sid.sat + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[10].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[10].state + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }

    @Test
    public void test5() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_tracking_MsgTrackingStateTest.test5");
        byte[] payload =
                new byte[] {
                    (byte) 1, (byte) 202, (byte) 0, (byte) 0, (byte) 0, (byte) 120, (byte) 122,
                    (byte) 29, (byte) 66, (byte) 1, (byte) 203, (byte) 0, (byte) 0, (byte) 0,
                    (byte) 66, (byte) 22, (byte) 18, (byte) 66, (byte) 1, (byte) 208, (byte) 0,
                    (byte) 0, (byte) 0, (byte) 153, (byte) 163, (byte) 24, (byte) 66, (byte) 1,
                    (byte) 212, (byte) 0, (byte) 0, (byte) 0, (byte) 178, (byte) 204, (byte) 28,
                    (byte) 66, (byte) 1, (byte) 217, (byte) 0, (byte) 0, (byte) 0, (byte) 220,
                    (byte) 59, (byte) 38, (byte) 66, (byte) 1, (byte) 218, (byte) 0, (byte) 0,
                    (byte) 0, (byte) 161, (byte) 27, (byte) 20, (byte) 66, (byte) 1, (byte) 220,
                    (byte) 0, (byte) 0, (byte) 0, (byte) 125, (byte) 107, (byte) 24, (byte) 66,
                    (byte) 1, (byte) 222, (byte) 0, (byte) 0, (byte) 0, (byte) 242, (byte) 46,
                    (byte) 28, (byte) 66, (byte) 1, (byte) 225, (byte) 0, (byte) 0, (byte) 0,
                    (byte) 231, (byte) 130, (byte) 41, (byte) 66, (byte) 0, (byte) 0, (byte) 0,
                    (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 128, (byte) 191, (byte) 0,
                    (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 128,
                    (byte) 191,
                };
        SBPMessage sbp = new SBPMessage(0xd7f6, 0x13, payload);
        MsgTrackingStateDepB msg = new MsgTrackingStateDepB(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        org.junit.Assert.assertEquals(msg.states[0].cn0, 3.93695983886718750e+01, DELTA);
        value = msg.states[0].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[0].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[0].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[0].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[0].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[0].sid.sat + "' != '" + 202 + "'",
                    value.equals(BigInteger.valueOf(202L)));
        } else {
            value = value.longValue();
            expected = 202L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[0].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[0].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[1].cn0, 3.65217361450195312e+01, DELTA);
        value = msg.states[1].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[1].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[1].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[1].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[1].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[1].sid.sat + "' != '" + 203 + "'",
                    value.equals(BigInteger.valueOf(203L)));
        } else {
            value = value.longValue();
            expected = 203L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[1].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[1].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[2].cn0, 3.81597633361816406e+01, DELTA);
        value = msg.states[2].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[2].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[2].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[2].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[2].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[2].sid.sat + "' != '" + 208 + "'",
                    value.equals(BigInteger.valueOf(208L)));
        } else {
            value = value.longValue();
            expected = 208L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[2].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[2].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[3].cn0, 3.91998977661132812e+01, DELTA);
        value = msg.states[3].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[3].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[3].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[3].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[3].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[3].sid.sat + "' != '" + 212 + "'",
                    value.equals(BigInteger.valueOf(212L)));
        } else {
            value = value.longValue();
            expected = 212L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[3].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[3].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[4].cn0, 4.15584564208984375e+01, DELTA);
        value = msg.states[4].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[4].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[4].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[4].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[4].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[4].sid.sat + "' != '" + 217 + "'",
                    value.equals(BigInteger.valueOf(217L)));
        } else {
            value = value.longValue();
            expected = 217L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[4].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[4].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[5].cn0, 3.70269813537597656e+01, DELTA);
        value = msg.states[5].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[5].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[5].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[5].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[5].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[5].sid.sat + "' != '" + 218 + "'",
                    value.equals(BigInteger.valueOf(218L)));
        } else {
            value = value.longValue();
            expected = 218L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[5].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[5].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[6].cn0, 3.81049690246582031e+01, DELTA);
        value = msg.states[6].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[6].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[6].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[6].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[6].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[6].sid.sat + "' != '" + 220 + "'",
                    value.equals(BigInteger.valueOf(220L)));
        } else {
            value = value.longValue();
            expected = 220L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[6].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[6].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[7].cn0, 3.90458450317382812e+01, DELTA);
        value = msg.states[7].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[7].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[7].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[7].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[7].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[7].sid.sat + "' != '" + 222 + "'",
                    value.equals(BigInteger.valueOf(222L)));
        } else {
            value = value.longValue();
            expected = 222L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[7].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[7].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[8].cn0, 4.23778343200683594e+01, DELTA);
        value = msg.states[8].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[8].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[8].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[8].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[8].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[8].sid.sat + "' != '" + 225 + "'",
                    value.equals(BigInteger.valueOf(225L)));
        } else {
            value = value.longValue();
            expected = 225L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[8].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[8].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[9].cn0, -1.00000000000000000e+00, DELTA);
        value = msg.states[9].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[9].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[9].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[9].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[9].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[9].sid.sat + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[9].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[9].state + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[10].cn0, -1.00000000000000000e+00, DELTA);
        value = msg.states[10].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[10].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[10].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[10].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[10].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[10].sid.sat + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[10].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[10].state + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }

    @Test
    public void test6() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_tracking_MsgTrackingStateTest.test6");
        byte[] payload =
                new byte[] {
                    (byte) 1, (byte) 202, (byte) 0, (byte) 0, (byte) 0, (byte) 103, (byte) 208,
                    (byte) 30, (byte) 66, (byte) 1, (byte) 203, (byte) 0, (byte) 0, (byte) 0,
                    (byte) 117, (byte) 24, (byte) 18, (byte) 66, (byte) 1, (byte) 208, (byte) 0,
                    (byte) 0, (byte) 0, (byte) 200, (byte) 173, (byte) 20, (byte) 66, (byte) 1,
                    (byte) 212, (byte) 0, (byte) 0, (byte) 0, (byte) 137, (byte) 68, (byte) 27,
                    (byte) 66, (byte) 1, (byte) 217, (byte) 0, (byte) 0, (byte) 0, (byte) 243,
                    (byte) 51, (byte) 40, (byte) 66, (byte) 1, (byte) 218, (byte) 0, (byte) 0,
                    (byte) 0, (byte) 225, (byte) 58, (byte) 23, (byte) 66, (byte) 1, (byte) 220,
                    (byte) 0, (byte) 0, (byte) 0, (byte) 132, (byte) 221, (byte) 22, (byte) 66,
                    (byte) 1, (byte) 222, (byte) 0, (byte) 0, (byte) 0, (byte) 157, (byte) 29,
                    (byte) 26, (byte) 66, (byte) 1, (byte) 225, (byte) 0, (byte) 0, (byte) 0,
                    (byte) 133, (byte) 21, (byte) 41, (byte) 66, (byte) 0, (byte) 0, (byte) 0,
                    (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 128, (byte) 191, (byte) 0,
                    (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 128,
                    (byte) 191,
                };
        SBPMessage sbp = new SBPMessage(0xd7f6, 0x13, payload);
        MsgTrackingStateDepB msg = new MsgTrackingStateDepB(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        org.junit.Assert.assertEquals(msg.states[0].cn0, 3.97035179138183594e+01, DELTA);
        value = msg.states[0].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[0].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[0].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[0].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[0].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[0].sid.sat + "' != '" + 202 + "'",
                    value.equals(BigInteger.valueOf(202L)));
        } else {
            value = value.longValue();
            expected = 202L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[0].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[0].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[1].cn0, 3.65238838195800781e+01, DELTA);
        value = msg.states[1].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[1].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[1].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[1].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[1].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[1].sid.sat + "' != '" + 203 + "'",
                    value.equals(BigInteger.valueOf(203L)));
        } else {
            value = value.longValue();
            expected = 203L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[1].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[1].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[2].cn0, 3.71697082519531250e+01, DELTA);
        value = msg.states[2].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[2].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[2].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[2].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[2].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[2].sid.sat + "' != '" + 208 + "'",
                    value.equals(BigInteger.valueOf(208L)));
        } else {
            value = value.longValue();
            expected = 208L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[2].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[2].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[3].cn0, 3.88169288635253906e+01, DELTA);
        value = msg.states[3].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[3].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[3].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[3].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[3].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[3].sid.sat + "' != '" + 212 + "'",
                    value.equals(BigInteger.valueOf(212L)));
        } else {
            value = value.longValue();
            expected = 212L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[3].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[3].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[4].cn0, 4.20507316589355469e+01, DELTA);
        value = msg.states[4].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[4].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[4].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[4].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[4].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[4].sid.sat + "' != '" + 217 + "'",
                    value.equals(BigInteger.valueOf(217L)));
        } else {
            value = value.longValue();
            expected = 217L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[4].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[4].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[5].cn0, 3.78074989318847656e+01, DELTA);
        value = msg.states[5].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[5].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[5].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[5].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[5].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[5].sid.sat + "' != '" + 218 + "'",
                    value.equals(BigInteger.valueOf(218L)));
        } else {
            value = value.longValue();
            expected = 218L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[5].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[5].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[6].cn0, 3.77163238525390625e+01, DELTA);
        value = msg.states[6].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[6].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[6].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[6].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[6].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[6].sid.sat + "' != '" + 220 + "'",
                    value.equals(BigInteger.valueOf(220L)));
        } else {
            value = value.longValue();
            expected = 220L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[6].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[6].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[7].cn0, 3.85289192199707031e+01, DELTA);
        value = msg.states[7].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[7].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[7].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[7].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[7].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[7].sid.sat + "' != '" + 222 + "'",
                    value.equals(BigInteger.valueOf(222L)));
        } else {
            value = value.longValue();
            expected = 222L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[7].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[7].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[8].cn0, 4.22710151672363281e+01, DELTA);
        value = msg.states[8].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[8].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[8].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[8].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[8].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[8].sid.sat + "' != '" + 225 + "'",
                    value.equals(BigInteger.valueOf(225L)));
        } else {
            value = value.longValue();
            expected = 225L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[8].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[8].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[9].cn0, -1.00000000000000000e+00, DELTA);
        value = msg.states[9].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[9].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[9].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[9].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[9].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[9].sid.sat + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[9].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[9].state + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[10].cn0, -1.00000000000000000e+00, DELTA);
        value = msg.states[10].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[10].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[10].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[10].sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[10].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[10].sid.sat + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[10].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[10].state + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
