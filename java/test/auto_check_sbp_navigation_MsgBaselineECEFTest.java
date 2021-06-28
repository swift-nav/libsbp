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

// This file was auto-generated from
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgBaselineECEF.yaml by generate.py. Do not modify
// by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.navigation.MsgBaselineECEF;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_navigation_MsgBaselineECEFTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgBaselineECEFTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 40, (byte) 244, (byte) 122, (byte) 19, (byte) 150, (byte) 98, (byte) 238,
                    (byte) 255, (byte) 190, (byte) 64, (byte) 20, (byte) 0, (byte) 246, (byte) 163,
                    (byte) 9, (byte) 0, (byte) 0, (byte) 0, (byte) 14, (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x88d3, 0x20b, payload);
        MsgBaselineECEF msg = new MsgBaselineECEF(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.accuracy;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.accuracy + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
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
        value = msg.n_sats;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.n_sats + "' != '" + 14 + "'", value.equals(BigInteger.valueOf(14L)));
        } else {
            value = value.longValue();
            expected = 14L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tow + "' != '" + 326825000 + "'",
                    value.equals(BigInteger.valueOf(326825000L)));
        } else {
            value = value.longValue();
            expected = 326825000L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.x;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.x + "' != '" + -1154410 + "'",
                    value.equals(BigInteger.valueOf(-1154410L)));
        } else {
            value = value.longValue();
            expected = -1154410L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.y;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.y + "' != '" + 1327294 + "'",
                    value.equals(BigInteger.valueOf(1327294L)));
        } else {
            value = value.longValue();
            expected = 1327294L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.z;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.z + "' != '" + 631798 + "'",
                    value.equals(BigInteger.valueOf(631798L)));
        } else {
            value = value.longValue();
            expected = 631798L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test2() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgBaselineECEFTest.test2");
        byte[] payload =
                new byte[] {
                    (byte) 16, (byte) 248, (byte) 122, (byte) 19, (byte) 72, (byte) 99, (byte) 238,
                    (byte) 255, (byte) 191, (byte) 65, (byte) 20, (byte) 0, (byte) 138, (byte) 162,
                    (byte) 9, (byte) 0, (byte) 0, (byte) 0, (byte) 15, (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x88d3, 0x20b, payload);
        MsgBaselineECEF msg = new MsgBaselineECEF(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.accuracy;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.accuracy + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
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
        value = msg.n_sats;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.n_sats + "' != '" + 15 + "'", value.equals(BigInteger.valueOf(15L)));
        } else {
            value = value.longValue();
            expected = 15L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tow + "' != '" + 326826000 + "'",
                    value.equals(BigInteger.valueOf(326826000L)));
        } else {
            value = value.longValue();
            expected = 326826000L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.x;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.x + "' != '" + -1154232 + "'",
                    value.equals(BigInteger.valueOf(-1154232L)));
        } else {
            value = value.longValue();
            expected = -1154232L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.y;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.y + "' != '" + 1327551 + "'",
                    value.equals(BigInteger.valueOf(1327551L)));
        } else {
            value = value.longValue();
            expected = 1327551L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.z;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.z + "' != '" + 631434 + "'",
                    value.equals(BigInteger.valueOf(631434L)));
        } else {
            value = value.longValue();
            expected = 631434L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test3() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgBaselineECEFTest.test3");
        byte[] payload =
                new byte[] {
                    (byte) 248, (byte) 251, (byte) 122, (byte) 19, (byte) 41, (byte) 99, (byte) 238,
                    (byte) 255, (byte) 181, (byte) 65, (byte) 20, (byte) 0, (byte) 148, (byte) 161,
                    (byte) 9, (byte) 0, (byte) 0, (byte) 0, (byte) 15, (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x88d3, 0x20b, payload);
        MsgBaselineECEF msg = new MsgBaselineECEF(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.accuracy;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.accuracy + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
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
        value = msg.n_sats;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.n_sats + "' != '" + 15 + "'", value.equals(BigInteger.valueOf(15L)));
        } else {
            value = value.longValue();
            expected = 15L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tow + "' != '" + 326827000 + "'",
                    value.equals(BigInteger.valueOf(326827000L)));
        } else {
            value = value.longValue();
            expected = 326827000L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.x;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.x + "' != '" + -1154263 + "'",
                    value.equals(BigInteger.valueOf(-1154263L)));
        } else {
            value = value.longValue();
            expected = -1154263L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.y;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.y + "' != '" + 1327541 + "'",
                    value.equals(BigInteger.valueOf(1327541L)));
        } else {
            value = value.longValue();
            expected = 1327541L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.z;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.z + "' != '" + 631188 + "'",
                    value.equals(BigInteger.valueOf(631188L)));
        } else {
            value = value.longValue();
            expected = 631188L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test4() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgBaselineECEFTest.test4");
        byte[] payload =
                new byte[] {
                    (byte) 224,
                    (byte) 255,
                    (byte) 122,
                    (byte) 19,
                    (byte) 188,
                    (byte) 97,
                    (byte) 238,
                    (byte) 255,
                    (byte) 81,
                    (byte) 64,
                    (byte) 20,
                    (byte) 0,
                    (byte) 65,
                    (byte) 160,
                    (byte) 9,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 15,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x88d3, 0x20b, payload);
        MsgBaselineECEF msg = new MsgBaselineECEF(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.accuracy;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.accuracy + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
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
        value = msg.n_sats;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.n_sats + "' != '" + 15 + "'", value.equals(BigInteger.valueOf(15L)));
        } else {
            value = value.longValue();
            expected = 15L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tow + "' != '" + 326828000 + "'",
                    value.equals(BigInteger.valueOf(326828000L)));
        } else {
            value = value.longValue();
            expected = 326828000L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.x;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.x + "' != '" + -1154628 + "'",
                    value.equals(BigInteger.valueOf(-1154628L)));
        } else {
            value = value.longValue();
            expected = -1154628L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.y;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.y + "' != '" + 1327185 + "'",
                    value.equals(BigInteger.valueOf(1327185L)));
        } else {
            value = value.longValue();
            expected = 1327185L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.z;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.z + "' != '" + 630849 + "'",
                    value.equals(BigInteger.valueOf(630849L)));
        } else {
            value = value.longValue();
            expected = 630849L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test5() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgBaselineECEFTest.test5");
        byte[] payload =
                new byte[] {
                    (byte) 200, (byte) 3, (byte) 123, (byte) 19, (byte) 189, (byte) 96, (byte) 238,
                    (byte) 255, (byte) 93, (byte) 63, (byte) 20, (byte) 0, (byte) 98, (byte) 159,
                    (byte) 9, (byte) 0, (byte) 0, (byte) 0, (byte) 15, (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x88d3, 0x20b, payload);
        MsgBaselineECEF msg = new MsgBaselineECEF(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.accuracy;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.accuracy + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
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
        value = msg.n_sats;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.n_sats + "' != '" + 15 + "'", value.equals(BigInteger.valueOf(15L)));
        } else {
            value = value.longValue();
            expected = 15L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tow + "' != '" + 326829000 + "'",
                    value.equals(BigInteger.valueOf(326829000L)));
        } else {
            value = value.longValue();
            expected = 326829000L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.x;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.x + "' != '" + -1154883 + "'",
                    value.equals(BigInteger.valueOf(-1154883L)));
        } else {
            value = value.longValue();
            expected = -1154883L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.y;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.y + "' != '" + 1326941 + "'",
                    value.equals(BigInteger.valueOf(1326941L)));
        } else {
            value = value.longValue();
            expected = 1326941L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.z;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.z + "' != '" + 630626 + "'",
                    value.equals(BigInteger.valueOf(630626L)));
        } else {
            value = value.longValue();
            expected = 630626L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }
}
