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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgDopsDepA.yaml
// by generate.py. Do not modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.navigation.MsgDopsDepA;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_navigation_MsgDopsDepATest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgDopsDepATest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 8, (byte) 48, (byte) 39, (byte) 0, (byte) 180, (byte) 0, (byte) 190,
                    (byte) 0, (byte) 170, (byte) 0, (byte) 160, (byte) 0, (byte) 150, (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0xd7f6, 0x206, payload);
        MsgDopsDepA msg = new MsgDopsDepA(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.gdop;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.gdop + "' != '" + 180 + "'", value.equals(BigInteger.valueOf(180L)));
        } else {
            value = value.longValue();
            expected = 180L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.hdop;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.hdop + "' != '" + 160 + "'", value.equals(BigInteger.valueOf(160L)));
        } else {
            value = value.longValue();
            expected = 160L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.pdop;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.pdop + "' != '" + 190 + "'", value.equals(BigInteger.valueOf(190L)));
        } else {
            value = value.longValue();
            expected = 190L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tdop;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tdop + "' != '" + 170 + "'", value.equals(BigInteger.valueOf(170L)));
        } else {
            value = value.longValue();
            expected = 170L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tow + "' != '" + 2568200 + "'",
                    value.equals(BigInteger.valueOf(2568200L)));
        } else {
            value = value.longValue();
            expected = 2568200L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.vdop;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.vdop + "' != '" + 150 + "'", value.equals(BigInteger.valueOf(150L)));
        } else {
            value = value.longValue();
            expected = 150L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test2() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgDopsDepATest.test2");
        byte[] payload =
                new byte[] {
                    (byte) 240, (byte) 51, (byte) 39, (byte) 0, (byte) 180, (byte) 0, (byte) 190,
                    (byte) 0, (byte) 170, (byte) 0, (byte) 160, (byte) 0, (byte) 150, (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0xd7f6, 0x206, payload);
        MsgDopsDepA msg = new MsgDopsDepA(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.gdop;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.gdop + "' != '" + 180 + "'", value.equals(BigInteger.valueOf(180L)));
        } else {
            value = value.longValue();
            expected = 180L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.hdop;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.hdop + "' != '" + 160 + "'", value.equals(BigInteger.valueOf(160L)));
        } else {
            value = value.longValue();
            expected = 160L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.pdop;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.pdop + "' != '" + 190 + "'", value.equals(BigInteger.valueOf(190L)));
        } else {
            value = value.longValue();
            expected = 190L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tdop;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tdop + "' != '" + 170 + "'", value.equals(BigInteger.valueOf(170L)));
        } else {
            value = value.longValue();
            expected = 170L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tow + "' != '" + 2569200 + "'",
                    value.equals(BigInteger.valueOf(2569200L)));
        } else {
            value = value.longValue();
            expected = 2569200L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.vdop;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.vdop + "' != '" + 150 + "'", value.equals(BigInteger.valueOf(150L)));
        } else {
            value = value.longValue();
            expected = 150L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test3() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgDopsDepATest.test3");
        byte[] payload =
                new byte[] {
                    (byte) 216, (byte) 55, (byte) 39, (byte) 0, (byte) 180, (byte) 0, (byte) 190,
                    (byte) 0, (byte) 170, (byte) 0, (byte) 160, (byte) 0, (byte) 150, (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0xd7f6, 0x206, payload);
        MsgDopsDepA msg = new MsgDopsDepA(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.gdop;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.gdop + "' != '" + 180 + "'", value.equals(BigInteger.valueOf(180L)));
        } else {
            value = value.longValue();
            expected = 180L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.hdop;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.hdop + "' != '" + 160 + "'", value.equals(BigInteger.valueOf(160L)));
        } else {
            value = value.longValue();
            expected = 160L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.pdop;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.pdop + "' != '" + 190 + "'", value.equals(BigInteger.valueOf(190L)));
        } else {
            value = value.longValue();
            expected = 190L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tdop;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tdop + "' != '" + 170 + "'", value.equals(BigInteger.valueOf(170L)));
        } else {
            value = value.longValue();
            expected = 170L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tow + "' != '" + 2570200 + "'",
                    value.equals(BigInteger.valueOf(2570200L)));
        } else {
            value = value.longValue();
            expected = 2570200L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.vdop;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.vdop + "' != '" + 150 + "'", value.equals(BigInteger.valueOf(150L)));
        } else {
            value = value.longValue();
            expected = 150L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test4() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgDopsDepATest.test4");
        byte[] payload =
                new byte[] {
                    (byte) 212, (byte) 157, (byte) 67, (byte) 24, (byte) 247, (byte) 0, (byte) 215,
                    (byte) 0, (byte) 123, (byte) 0, (byte) 17, (byte) 1, (byte) 44, (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x4c3, 0x206, payload);
        MsgDopsDepA msg = new MsgDopsDepA(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.gdop;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.gdop + "' != '" + 247 + "'", value.equals(BigInteger.valueOf(247L)));
        } else {
            value = value.longValue();
            expected = 247L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.hdop;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.hdop + "' != '" + 273 + "'", value.equals(BigInteger.valueOf(273L)));
        } else {
            value = value.longValue();
            expected = 273L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.pdop;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.pdop + "' != '" + 215 + "'", value.equals(BigInteger.valueOf(215L)));
        } else {
            value = value.longValue();
            expected = 215L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tdop;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tdop + "' != '" + 123 + "'", value.equals(BigInteger.valueOf(123L)));
        } else {
            value = value.longValue();
            expected = 123L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tow + "' != '" + 407084500 + "'",
                    value.equals(BigInteger.valueOf(407084500L)));
        } else {
            value = value.longValue();
            expected = 407084500L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.vdop;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.vdop + "' != '" + 44 + "'", value.equals(BigInteger.valueOf(44L)));
        } else {
            value = value.longValue();
            expected = 44L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test5() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgDopsDepATest.test5");
        byte[] payload =
                new byte[] {
                    (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 255, (byte) 255, (byte) 255,
                    (byte) 255, (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x4c3, 0x206, payload);
        MsgDopsDepA msg = new MsgDopsDepA(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.gdop;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.gdop + "' != '" + 65535 + "'",
                    value.equals(BigInteger.valueOf(65535L)));
        } else {
            value = value.longValue();
            expected = 65535L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.hdop;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.hdop + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.pdop;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.pdop + "' != '" + 65535 + "'",
                    value.equals(BigInteger.valueOf(65535L)));
        } else {
            value = value.longValue();
            expected = 65535L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tdop;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tdop + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tow + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.vdop;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.vdop + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test6() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgDopsDepATest.test6");
        byte[] payload =
                new byte[] {
                    (byte) 128, (byte) 165, (byte) 68, (byte) 24, (byte) 92, (byte) 1, (byte) 56,
                    (byte) 1, (byte) 155, (byte) 0, (byte) 125, (byte) 2, (byte) 113, (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x4c3, 0x206, payload);
        MsgDopsDepA msg = new MsgDopsDepA(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.gdop;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.gdop + "' != '" + 348 + "'", value.equals(BigInteger.valueOf(348L)));
        } else {
            value = value.longValue();
            expected = 348L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.hdop;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.hdop + "' != '" + 637 + "'", value.equals(BigInteger.valueOf(637L)));
        } else {
            value = value.longValue();
            expected = 637L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.pdop;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.pdop + "' != '" + 312 + "'", value.equals(BigInteger.valueOf(312L)));
        } else {
            value = value.longValue();
            expected = 312L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tdop;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tdop + "' != '" + 155 + "'", value.equals(BigInteger.valueOf(155L)));
        } else {
            value = value.longValue();
            expected = 155L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tow + "' != '" + 407152000 + "'",
                    value.equals(BigInteger.valueOf(407152000L)));
        } else {
            value = value.longValue();
            expected = 407152000L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.vdop;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.vdop + "' != '" + 113 + "'", value.equals(BigInteger.valueOf(113L)));
        } else {
            value = value.longValue();
            expected = 113L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test7() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgDopsDepATest.test7");
        byte[] payload =
                new byte[] {
                    (byte) 104, (byte) 169, (byte) 68, (byte) 24, (byte) 92, (byte) 1, (byte) 55,
                    (byte) 1, (byte) 155, (byte) 0, (byte) 125, (byte) 2, (byte) 113, (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x4c3, 0x206, payload);
        MsgDopsDepA msg = new MsgDopsDepA(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.gdop;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.gdop + "' != '" + 348 + "'", value.equals(BigInteger.valueOf(348L)));
        } else {
            value = value.longValue();
            expected = 348L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.hdop;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.hdop + "' != '" + 637 + "'", value.equals(BigInteger.valueOf(637L)));
        } else {
            value = value.longValue();
            expected = 637L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.pdop;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.pdop + "' != '" + 311 + "'", value.equals(BigInteger.valueOf(311L)));
        } else {
            value = value.longValue();
            expected = 311L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tdop;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tdop + "' != '" + 155 + "'", value.equals(BigInteger.valueOf(155L)));
        } else {
            value = value.longValue();
            expected = 155L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tow + "' != '" + 407153000 + "'",
                    value.equals(BigInteger.valueOf(407153000L)));
        } else {
            value = value.longValue();
            expected = 407153000L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.vdop;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.vdop + "' != '" + 113 + "'", value.equals(BigInteger.valueOf(113L)));
        } else {
            value = value.longValue();
            expected = 113L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test8() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgDopsDepATest.test8");
        byte[] payload =
                new byte[] {
                    (byte) 80, (byte) 173, (byte) 68, (byte) 24, (byte) 92, (byte) 1, (byte) 55,
                    (byte) 1, (byte) 155, (byte) 0, (byte) 125, (byte) 2, (byte) 112, (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x4c3, 0x206, payload);
        MsgDopsDepA msg = new MsgDopsDepA(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.gdop;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.gdop + "' != '" + 348 + "'", value.equals(BigInteger.valueOf(348L)));
        } else {
            value = value.longValue();
            expected = 348L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.hdop;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.hdop + "' != '" + 637 + "'", value.equals(BigInteger.valueOf(637L)));
        } else {
            value = value.longValue();
            expected = 637L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.pdop;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.pdop + "' != '" + 311 + "'", value.equals(BigInteger.valueOf(311L)));
        } else {
            value = value.longValue();
            expected = 311L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tdop;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tdop + "' != '" + 155 + "'", value.equals(BigInteger.valueOf(155L)));
        } else {
            value = value.longValue();
            expected = 155L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tow + "' != '" + 407154000 + "'",
                    value.equals(BigInteger.valueOf(407154000L)));
        } else {
            value = value.longValue();
            expected = 407154000L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.vdop;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.vdop + "' != '" + 112 + "'", value.equals(BigInteger.valueOf(112L)));
        } else {
            value = value.longValue();
            expected = 112L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test9() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgDopsDepATest.test9");
        byte[] payload =
                new byte[] {
                    (byte) 56, (byte) 177, (byte) 68, (byte) 24, (byte) 92, (byte) 1, (byte) 55,
                    (byte) 1, (byte) 155, (byte) 0, (byte) 125, (byte) 2, (byte) 112, (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x4c3, 0x206, payload);
        MsgDopsDepA msg = new MsgDopsDepA(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.gdop;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.gdop + "' != '" + 348 + "'", value.equals(BigInteger.valueOf(348L)));
        } else {
            value = value.longValue();
            expected = 348L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.hdop;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.hdop + "' != '" + 637 + "'", value.equals(BigInteger.valueOf(637L)));
        } else {
            value = value.longValue();
            expected = 637L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.pdop;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.pdop + "' != '" + 311 + "'", value.equals(BigInteger.valueOf(311L)));
        } else {
            value = value.longValue();
            expected = 311L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tdop;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tdop + "' != '" + 155 + "'", value.equals(BigInteger.valueOf(155L)));
        } else {
            value = value.longValue();
            expected = 155L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tow + "' != '" + 407155000 + "'",
                    value.equals(BigInteger.valueOf(407155000L)));
        } else {
            value = value.longValue();
            expected = 407155000L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.vdop;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.vdop + "' != '" + 112 + "'", value.equals(BigInteger.valueOf(112L)));
        } else {
            value = value.longValue();
            expected = 112L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }
}
