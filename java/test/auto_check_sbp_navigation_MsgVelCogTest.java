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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgVelCog.yaml by
// generate.py. Do not modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.navigation.MsgVelCog;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_navigation_MsgVelCogTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgVelCogTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 48, (byte) 246, (byte) 122, (byte) 19, (byte) 232, (byte) 3, (byte) 0,
                    (byte) 0, (byte) 208, (byte) 7, (byte) 0, (byte) 0, (byte) 184, (byte) 11,
                    (byte) 0, (byte) 0, (byte) 160, (byte) 15, (byte) 0, (byte) 0, (byte) 136,
                    (byte) 19, (byte) 0, (byte) 0, (byte) 112, (byte) 23, (byte) 0, (byte) 0,
                    (byte) 62,
                };
        SBPMessage sbp = new SBPMessage(0x88D3, 0x21C, payload);
        MsgVelCog msg = new MsgVelCog(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.cog;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.cog + "' != '" + 1000 + "'", value.equals(BigInteger.valueOf(1000L)));
        } else {
            value = value.longValue();
            expected = 1000L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.cog_accuracy;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.cog_accuracy + "' != '" + 4000 + "'",
                    value.equals(BigInteger.valueOf(4000L)));
        } else {
            value = value.longValue();
            expected = 4000L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.flags + "' != '" + 62 + "'", value.equals(BigInteger.valueOf(62L)));
        } else {
            value = value.longValue();
            expected = 62L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sog;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sog + "' != '" + 2000 + "'", value.equals(BigInteger.valueOf(2000L)));
        } else {
            value = value.longValue();
            expected = 2000L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sog_accuracy;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sog_accuracy + "' != '" + 5000 + "'",
                    value.equals(BigInteger.valueOf(5000L)));
        } else {
            value = value.longValue();
            expected = 5000L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tow + "' != '" + 326825520 + "'",
                    value.equals(BigInteger.valueOf(326825520L)));
        } else {
            value = value.longValue();
            expected = 326825520L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.vel_d;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.vel_d + "' != '" + 3000 + "'",
                    value.equals(BigInteger.valueOf(3000L)));
        } else {
            value = value.longValue();
            expected = 3000L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.vel_d_accuracy;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.vel_d_accuracy + "' != '" + 6000 + "'",
                    value.equals(BigInteger.valueOf(6000L)));
        } else {
            value = value.longValue();
            expected = 6000L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test2() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgVelCogTest.test2");
        byte[] payload =
                new byte[] {
                    (byte) 48, (byte) 246, (byte) 122, (byte) 19, (byte) 123, (byte) 0, (byte) 0,
                    (byte) 0, (byte) 200, (byte) 1, (byte) 0, (byte) 0, (byte) 24, (byte) 252,
                    (byte) 255, (byte) 255, (byte) 0, (byte) 149, (byte) 186, (byte) 10, (byte) 100,
                    (byte) 0, (byte) 0, (byte) 0, (byte) 100, (byte) 0, (byte) 0, (byte) 0,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x88D3, 0x21C, payload);
        MsgVelCog msg = new MsgVelCog(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.cog;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.cog + "' != '" + 123 + "'", value.equals(BigInteger.valueOf(123L)));
        } else {
            value = value.longValue();
            expected = 123L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.cog_accuracy;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.cog_accuracy + "' != '" + 180000000 + "'",
                    value.equals(BigInteger.valueOf(180000000L)));
        } else {
            value = value.longValue();
            expected = 180000000L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.flags + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sog;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sog + "' != '" + 456 + "'", value.equals(BigInteger.valueOf(456L)));
        } else {
            value = value.longValue();
            expected = 456L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sog_accuracy;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sog_accuracy + "' != '" + 100 + "'",
                    value.equals(BigInteger.valueOf(100L)));
        } else {
            value = value.longValue();
            expected = 100L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tow + "' != '" + 326825520 + "'",
                    value.equals(BigInteger.valueOf(326825520L)));
        } else {
            value = value.longValue();
            expected = 326825520L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.vel_d;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.vel_d + "' != '" + -1000 + "'",
                    value.equals(BigInteger.valueOf(-1000L)));
        } else {
            value = value.longValue();
            expected = -1000L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.vel_d_accuracy;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.vel_d_accuracy + "' != '" + 100 + "'",
                    value.equals(BigInteger.valueOf(100L)));
        } else {
            value = value.longValue();
            expected = 100L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test3() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgVelCogTest.test3");
        byte[] payload =
                new byte[] {
                    (byte) 48,
                    (byte) 246,
                    (byte) 122,
                    (byte) 19,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x88D3, 0x21C, payload);
        MsgVelCog msg = new MsgVelCog(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.cog;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.cog + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.cog_accuracy;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.cog_accuracy + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.flags + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sog;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sog + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sog_accuracy;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sog_accuracy + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tow + "' != '" + 326825520 + "'",
                    value.equals(BigInteger.valueOf(326825520L)));
        } else {
            value = value.longValue();
            expected = 326825520L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.vel_d;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.vel_d + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.vel_d_accuracy;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.vel_d_accuracy + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }
}
