/* Copyright (C) 2015-2021 Swift Navigation Inc.
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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/system/test_MsgGroupMeta.yaml by
// generate.py. Do not modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.system.MsgGroupMeta;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_system_MsgGroupMetaTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_system_MsgGroupMetaTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 1,
                    (byte) 2,
                    (byte) 3,
                    (byte) 10,
                    (byte) 255,
                    (byte) 10,
                    (byte) 2,
                    (byte) 2,
                    (byte) 255,
                };
        SBPMessage sbp = new SBPMessage(0xEEEE, 0xFF0A, payload);
        MsgGroupMeta msg = new MsgGroupMeta(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.flags + "' != '" + 2 + "'", value.equals(BigInteger.valueOf(2L)));
        } else {
            value = value.longValue();
            expected = 2L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.group_id;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.group_id + "' != '" + 1 + "'", value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.group_msgs[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.group_msgs[0] + "' != '" + 65290 + "'",
                    value.equals(BigInteger.valueOf(65290L)));
        } else {
            value = value.longValue();
            expected = 65290L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.group_msgs[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.group_msgs[1] + "' != '" + 522 + "'",
                    value.equals(BigInteger.valueOf(522L)));
        } else {
            value = value.longValue();
            expected = 522L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.group_msgs[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.group_msgs[2] + "' != '" + 65282 + "'",
                    value.equals(BigInteger.valueOf(65282L)));
        } else {
            value = value.longValue();
            expected = 65282L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.n_group_msgs;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.n_group_msgs + "' != '" + 3 + "'",
                    value.equals(BigInteger.valueOf(3L)));
        } else {
            value = value.longValue();
            expected = 3L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test2() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_system_MsgGroupMetaTest.test2");
        byte[] payload =
                new byte[] {
                    (byte) 1, (byte) 1, (byte) 14, (byte) 2, (byte) 1, (byte) 3, (byte) 1,
                    (byte) 10, (byte) 2, (byte) 17, (byte) 2, (byte) 9, (byte) 2, (byte) 20,
                    (byte) 2, (byte) 14, (byte) 2, (byte) 18, (byte) 2, (byte) 13, (byte) 2,
                    (byte) 21, (byte) 2, (byte) 33, (byte) 2, (byte) 3, (byte) 255, (byte) 6,
                    (byte) 255, (byte) 14, (byte) 255,
                };
        SBPMessage sbp = new SBPMessage(0x315, 0xFF0A, payload);
        MsgGroupMeta msg = new MsgGroupMeta(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.flags + "' != '" + 1 + "'", value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.group_id;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.group_id + "' != '" + 1 + "'", value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.group_msgs[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.group_msgs[0] + "' != '" + 258 + "'",
                    value.equals(BigInteger.valueOf(258L)));
        } else {
            value = value.longValue();
            expected = 258L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.group_msgs[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.group_msgs[1] + "' != '" + 259 + "'",
                    value.equals(BigInteger.valueOf(259L)));
        } else {
            value = value.longValue();
            expected = 259L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.group_msgs[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.group_msgs[2] + "' != '" + 522 + "'",
                    value.equals(BigInteger.valueOf(522L)));
        } else {
            value = value.longValue();
            expected = 522L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.group_msgs[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.group_msgs[3] + "' != '" + 529 + "'",
                    value.equals(BigInteger.valueOf(529L)));
        } else {
            value = value.longValue();
            expected = 529L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.group_msgs[4];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.group_msgs[4] + "' != '" + 521 + "'",
                    value.equals(BigInteger.valueOf(521L)));
        } else {
            value = value.longValue();
            expected = 521L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.group_msgs[5];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.group_msgs[5] + "' != '" + 532 + "'",
                    value.equals(BigInteger.valueOf(532L)));
        } else {
            value = value.longValue();
            expected = 532L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.group_msgs[6];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.group_msgs[6] + "' != '" + 526 + "'",
                    value.equals(BigInteger.valueOf(526L)));
        } else {
            value = value.longValue();
            expected = 526L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.group_msgs[7];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.group_msgs[7] + "' != '" + 530 + "'",
                    value.equals(BigInteger.valueOf(530L)));
        } else {
            value = value.longValue();
            expected = 530L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.group_msgs[8];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.group_msgs[8] + "' != '" + 525 + "'",
                    value.equals(BigInteger.valueOf(525L)));
        } else {
            value = value.longValue();
            expected = 525L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.group_msgs[9];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.group_msgs[9] + "' != '" + 533 + "'",
                    value.equals(BigInteger.valueOf(533L)));
        } else {
            value = value.longValue();
            expected = 533L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.group_msgs[10];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.group_msgs[10] + "' != '" + 545 + "'",
                    value.equals(BigInteger.valueOf(545L)));
        } else {
            value = value.longValue();
            expected = 545L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.group_msgs[11];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.group_msgs[11] + "' != '" + 65283 + "'",
                    value.equals(BigInteger.valueOf(65283L)));
        } else {
            value = value.longValue();
            expected = 65283L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.group_msgs[12];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.group_msgs[12] + "' != '" + 65286 + "'",
                    value.equals(BigInteger.valueOf(65286L)));
        } else {
            value = value.longValue();
            expected = 65286L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.group_msgs[13];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.group_msgs[13] + "' != '" + 65294 + "'",
                    value.equals(BigInteger.valueOf(65294L)));
        } else {
            value = value.longValue();
            expected = 65294L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.n_group_msgs;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.n_group_msgs + "' != '" + 14 + "'",
                    value.equals(BigInteger.valueOf(14L)));
        } else {
            value = value.longValue();
            expected = 14L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }
}
