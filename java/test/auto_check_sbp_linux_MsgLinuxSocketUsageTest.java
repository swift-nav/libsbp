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
// spec/tests/yaml/swiftnav/sbp/linux/test_MsgLinuxSocketUsage.yaml by generate.py. Do not modify by
// hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.linux.MsgLinuxSocketUsage;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_linux_MsgLinuxSocketUsageTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_linux_MsgLinuxSocketUsageTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 13,
                    (byte) 196,
                    (byte) 69,
                    (byte) 173,
                    (byte) 67,
                    (byte) 222,
                    (byte) 186,
                    (byte) 181,
                    (byte) 246,
                    (byte) 154,
                    (byte) 251,
                    (byte) 17,
                    (byte) 224,
                    (byte) 179,
                    (byte) 26,
                    (byte) 169,
                    (byte) 177,
                    (byte) 90,
                    (byte) 149,
                    (byte) 213,
                    (byte) 214,
                    (byte) 6,
                    (byte) 126,
                    (byte) 64,
                    (byte) 120,
                    (byte) 185,
                    (byte) 84,
                    (byte) 131,
                    (byte) 200,
                    (byte) 111,
                    (byte) 32,
                    (byte) 141,
                    (byte) 217,
                    (byte) 209,
                    (byte) 52,
                    (byte) 14,
                    (byte) 190,
                    (byte) 147,
                    (byte) 159,
                    (byte) 246,
                    (byte) 141,
                    (byte) 122,
                    (byte) 212,
                    (byte) 119,
                    (byte) 131,
                    (byte) 30,
                    (byte) 120,
                    (byte) 47,
                    (byte) 25,
                    (byte) 109,
                    (byte) 154,
                    (byte) 65,
                    (byte) 132,
                    (byte) 164,
                    (byte) 39,
                    (byte) 30,
                    (byte) 30,
                    (byte) 175,
                    (byte) 8,
                    (byte) 44,
                    (byte) 28,
                    (byte) 111,
                    (byte) 236,
                    (byte) 240,
                    (byte) 176,
                    (byte) 74,
                    (byte) 159,
                    (byte) 129,
                    (byte) 154,
                    (byte) 153,
                    (byte) 162,
                    (byte) 229,
                };
        SBPMessage sbp = new SBPMessage(0x8a72, 0x7f05, payload);
        MsgLinuxSocketUsage msg = new MsgLinuxSocketUsage(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.avg_queue_depth;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.avg_queue_depth + "' != '" + 2907030541L + "'",
                    value.equals(new BigInteger("2907030541")));
        } else {
            value = value.longValue();
            expected = 2907030541L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.max_queue_depth;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.max_queue_depth + "' != '" + 3048922691L + "'",
                    value.equals(new BigInteger("3048922691")));
        } else {
            value = value.longValue();
            expected = 3048922691L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.socket_state_counts[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.socket_state_counts[0] + "' != '" + 39670 + "'",
                    value.equals(BigInteger.valueOf(39670L)));
        } else {
            value = value.longValue();
            expected = 39670L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.socket_state_counts[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.socket_state_counts[1] + "' != '" + 4603 + "'",
                    value.equals(BigInteger.valueOf(4603L)));
        } else {
            value = value.longValue();
            expected = 4603L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.socket_state_counts[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.socket_state_counts[2] + "' != '" + 46048 + "'",
                    value.equals(BigInteger.valueOf(46048L)));
        } else {
            value = value.longValue();
            expected = 46048L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.socket_state_counts[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.socket_state_counts[3] + "' != '" + 43290 + "'",
                    value.equals(BigInteger.valueOf(43290L)));
        } else {
            value = value.longValue();
            expected = 43290L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.socket_state_counts[4];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.socket_state_counts[4] + "' != '" + 23217 + "'",
                    value.equals(BigInteger.valueOf(23217L)));
        } else {
            value = value.longValue();
            expected = 23217L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.socket_state_counts[5];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.socket_state_counts[5] + "' != '" + 54677 + "'",
                    value.equals(BigInteger.valueOf(54677L)));
        } else {
            value = value.longValue();
            expected = 54677L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.socket_state_counts[6];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.socket_state_counts[6] + "' != '" + 1750 + "'",
                    value.equals(BigInteger.valueOf(1750L)));
        } else {
            value = value.longValue();
            expected = 1750L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.socket_state_counts[7];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.socket_state_counts[7] + "' != '" + 16510 + "'",
                    value.equals(BigInteger.valueOf(16510L)));
        } else {
            value = value.longValue();
            expected = 16510L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.socket_state_counts[8];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.socket_state_counts[8] + "' != '" + 47480 + "'",
                    value.equals(BigInteger.valueOf(47480L)));
        } else {
            value = value.longValue();
            expected = 47480L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.socket_state_counts[9];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.socket_state_counts[9] + "' != '" + 33620 + "'",
                    value.equals(BigInteger.valueOf(33620L)));
        } else {
            value = value.longValue();
            expected = 33620L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.socket_state_counts[10];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.socket_state_counts[10] + "' != '" + 28616 + "'",
                    value.equals(BigInteger.valueOf(28616L)));
        } else {
            value = value.longValue();
            expected = 28616L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.socket_state_counts[11];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.socket_state_counts[11] + "' != '" + 36128 + "'",
                    value.equals(BigInteger.valueOf(36128L)));
        } else {
            value = value.longValue();
            expected = 36128L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.socket_state_counts[12];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.socket_state_counts[12] + "' != '" + 53721 + "'",
                    value.equals(BigInteger.valueOf(53721L)));
        } else {
            value = value.longValue();
            expected = 53721L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.socket_state_counts[13];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.socket_state_counts[13] + "' != '" + 3636 + "'",
                    value.equals(BigInteger.valueOf(3636L)));
        } else {
            value = value.longValue();
            expected = 3636L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.socket_state_counts[14];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.socket_state_counts[14] + "' != '" + 37822 + "'",
                    value.equals(BigInteger.valueOf(37822L)));
        } else {
            value = value.longValue();
            expected = 37822L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.socket_state_counts[15];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.socket_state_counts[15] + "' != '" + 63135 + "'",
                    value.equals(BigInteger.valueOf(63135L)));
        } else {
            value = value.longValue();
            expected = 63135L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.socket_type_counts[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.socket_type_counts[0] + "' != '" + 31373 + "'",
                    value.equals(BigInteger.valueOf(31373L)));
        } else {
            value = value.longValue();
            expected = 31373L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.socket_type_counts[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.socket_type_counts[1] + "' != '" + 30676 + "'",
                    value.equals(BigInteger.valueOf(30676L)));
        } else {
            value = value.longValue();
            expected = 30676L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.socket_type_counts[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.socket_type_counts[2] + "' != '" + 7811 + "'",
                    value.equals(BigInteger.valueOf(7811L)));
        } else {
            value = value.longValue();
            expected = 7811L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.socket_type_counts[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.socket_type_counts[3] + "' != '" + 12152 + "'",
                    value.equals(BigInteger.valueOf(12152L)));
        } else {
            value = value.longValue();
            expected = 12152L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.socket_type_counts[4];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.socket_type_counts[4] + "' != '" + 27929 + "'",
                    value.equals(BigInteger.valueOf(27929L)));
        } else {
            value = value.longValue();
            expected = 27929L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.socket_type_counts[5];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.socket_type_counts[5] + "' != '" + 16794 + "'",
                    value.equals(BigInteger.valueOf(16794L)));
        } else {
            value = value.longValue();
            expected = 16794L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.socket_type_counts[6];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.socket_type_counts[6] + "' != '" + 42116 + "'",
                    value.equals(BigInteger.valueOf(42116L)));
        } else {
            value = value.longValue();
            expected = 42116L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.socket_type_counts[7];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.socket_type_counts[7] + "' != '" + 7719 + "'",
                    value.equals(BigInteger.valueOf(7719L)));
        } else {
            value = value.longValue();
            expected = 7719L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.socket_type_counts[8];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.socket_type_counts[8] + "' != '" + 44830 + "'",
                    value.equals(BigInteger.valueOf(44830L)));
        } else {
            value = value.longValue();
            expected = 44830L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.socket_type_counts[9];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.socket_type_counts[9] + "' != '" + 11272 + "'",
                    value.equals(BigInteger.valueOf(11272L)));
        } else {
            value = value.longValue();
            expected = 11272L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.socket_type_counts[10];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.socket_type_counts[10] + "' != '" + 28444 + "'",
                    value.equals(BigInteger.valueOf(28444L)));
        } else {
            value = value.longValue();
            expected = 28444L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.socket_type_counts[11];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.socket_type_counts[11] + "' != '" + 61676 + "'",
                    value.equals(BigInteger.valueOf(61676L)));
        } else {
            value = value.longValue();
            expected = 61676L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.socket_type_counts[12];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.socket_type_counts[12] + "' != '" + 19120 + "'",
                    value.equals(BigInteger.valueOf(19120L)));
        } else {
            value = value.longValue();
            expected = 19120L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.socket_type_counts[13];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.socket_type_counts[13] + "' != '" + 33183 + "'",
                    value.equals(BigInteger.valueOf(33183L)));
        } else {
            value = value.longValue();
            expected = 33183L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.socket_type_counts[14];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.socket_type_counts[14] + "' != '" + 39322 + "'",
                    value.equals(BigInteger.valueOf(39322L)));
        } else {
            value = value.longValue();
            expected = 39322L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.socket_type_counts[15];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.socket_type_counts[15] + "' != '" + 58786 + "'",
                    value.equals(BigInteger.valueOf(58786L)));
        } else {
            value = value.longValue();
            expected = 58786L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
