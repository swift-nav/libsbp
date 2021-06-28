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
// spec/tests/yaml/swiftnav/sbp/navigation/test_MsgGPSTimeDepA.yaml by generate.py. Do not modify by
// hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.navigation.MsgGPSTimeDepA;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_navigation_MsgGPSTimeDepATest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgGPSTimeDepATest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 251,
                    (byte) 6,
                    (byte) 120,
                    (byte) 46,
                    (byte) 39,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0xd7f6, 0x100, payload);
        MsgGPSTimeDepA msg = new MsgGPSTimeDepA(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.flags + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.ns_residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.ns_residual + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tow + "' != '" + 2567800 + "'",
                    value.equals(BigInteger.valueOf(2567800L)));
        } else {
            value = value.longValue();
            expected = 2567800L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.wn + "' != '" + 1787 + "'", value.equals(BigInteger.valueOf(1787L)));
        } else {
            value = value.longValue();
            expected = 1787L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test2() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgGPSTimeDepATest.test2");
        byte[] payload =
                new byte[] {
                    (byte) 251,
                    (byte) 6,
                    (byte) 220,
                    (byte) 46,
                    (byte) 39,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0xd7f6, 0x100, payload);
        MsgGPSTimeDepA msg = new MsgGPSTimeDepA(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.flags + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.ns_residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.ns_residual + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tow + "' != '" + 2567900 + "'",
                    value.equals(BigInteger.valueOf(2567900L)));
        } else {
            value = value.longValue();
            expected = 2567900L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.wn + "' != '" + 1787 + "'", value.equals(BigInteger.valueOf(1787L)));
        } else {
            value = value.longValue();
            expected = 1787L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test3() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgGPSTimeDepATest.test3");
        byte[] payload =
                new byte[] {
                    (byte) 251,
                    (byte) 6,
                    (byte) 64,
                    (byte) 47,
                    (byte) 39,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0xd7f6, 0x100, payload);
        MsgGPSTimeDepA msg = new MsgGPSTimeDepA(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.flags + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.ns_residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.ns_residual + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tow + "' != '" + 2568000 + "'",
                    value.equals(BigInteger.valueOf(2568000L)));
        } else {
            value = value.longValue();
            expected = 2568000L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.wn + "' != '" + 1787 + "'", value.equals(BigInteger.valueOf(1787L)));
        } else {
            value = value.longValue();
            expected = 1787L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test4() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgGPSTimeDepATest.test4");
        byte[] payload =
                new byte[] {
                    (byte) 251,
                    (byte) 6,
                    (byte) 164,
                    (byte) 47,
                    (byte) 39,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0xd7f6, 0x100, payload);
        MsgGPSTimeDepA msg = new MsgGPSTimeDepA(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.flags + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.ns_residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.ns_residual + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tow + "' != '" + 2568100 + "'",
                    value.equals(BigInteger.valueOf(2568100L)));
        } else {
            value = value.longValue();
            expected = 2568100L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.wn + "' != '" + 1787 + "'", value.equals(BigInteger.valueOf(1787L)));
        } else {
            value = value.longValue();
            expected = 1787L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test5() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgGPSTimeDepATest.test5");
        byte[] payload =
                new byte[] {
                    (byte) 251,
                    (byte) 6,
                    (byte) 8,
                    (byte) 48,
                    (byte) 39,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0xd7f6, 0x100, payload);
        MsgGPSTimeDepA msg = new MsgGPSTimeDepA(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.flags + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.ns_residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.ns_residual + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
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
        value = msg.wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.wn + "' != '" + 1787 + "'", value.equals(BigInteger.valueOf(1787L)));
        } else {
            value = value.longValue();
            expected = 1787L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test6() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgGPSTimeDepATest.test6");
        byte[] payload =
                new byte[] {
                    (byte) 46,
                    (byte) 7,
                    (byte) 212,
                    (byte) 157,
                    (byte) 67,
                    (byte) 24,
                    (byte) 111,
                    (byte) 147,
                    (byte) 252,
                    (byte) 255,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x4c3, 0x100, payload);
        MsgGPSTimeDepA msg = new MsgGPSTimeDepA(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.flags + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.ns_residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.ns_residual + "' != '" + -224401 + "'",
                    value.equals(BigInteger.valueOf(-224401L)));
        } else {
            value = value.longValue();
            expected = -224401L;
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
        value = msg.wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.wn + "' != '" + 1838 + "'", value.equals(BigInteger.valueOf(1838L)));
        } else {
            value = value.longValue();
            expected = 1838L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test7() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgGPSTimeDepATest.test7");
        byte[] payload =
                new byte[] {
                    (byte) 46,
                    (byte) 7,
                    (byte) 56,
                    (byte) 158,
                    (byte) 67,
                    (byte) 24,
                    (byte) 109,
                    (byte) 103,
                    (byte) 3,
                    (byte) 0,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x4c3, 0x100, payload);
        MsgGPSTimeDepA msg = new MsgGPSTimeDepA(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.flags + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.ns_residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.ns_residual + "' != '" + 223085 + "'",
                    value.equals(BigInteger.valueOf(223085L)));
        } else {
            value = value.longValue();
            expected = 223085L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tow + "' != '" + 407084600 + "'",
                    value.equals(BigInteger.valueOf(407084600L)));
        } else {
            value = value.longValue();
            expected = 407084600L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.wn + "' != '" + 1838 + "'", value.equals(BigInteger.valueOf(1838L)));
        } else {
            value = value.longValue();
            expected = 1838L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test8() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgGPSTimeDepATest.test8");
        byte[] payload =
                new byte[] {
                    (byte) 46,
                    (byte) 7,
                    (byte) 156,
                    (byte) 158,
                    (byte) 67,
                    (byte) 24,
                    (byte) 233,
                    (byte) 152,
                    (byte) 252,
                    (byte) 255,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x4c3, 0x100, payload);
        MsgGPSTimeDepA msg = new MsgGPSTimeDepA(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.flags + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.ns_residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.ns_residual + "' != '" + -222999 + "'",
                    value.equals(BigInteger.valueOf(-222999L)));
        } else {
            value = value.longValue();
            expected = -222999L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tow + "' != '" + 407084700 + "'",
                    value.equals(BigInteger.valueOf(407084700L)));
        } else {
            value = value.longValue();
            expected = 407084700L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.wn + "' != '" + 1838 + "'", value.equals(BigInteger.valueOf(1838L)));
        } else {
            value = value.longValue();
            expected = 1838L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test9() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgGPSTimeDepATest.test9");
        byte[] payload =
                new byte[] {
                    (byte) 46,
                    (byte) 7,
                    (byte) 0,
                    (byte) 159,
                    (byte) 67,
                    (byte) 24,
                    (byte) 240,
                    (byte) 154,
                    (byte) 3,
                    (byte) 0,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x4c3, 0x100, payload);
        MsgGPSTimeDepA msg = new MsgGPSTimeDepA(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.flags + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.ns_residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.ns_residual + "' != '" + 236272 + "'",
                    value.equals(BigInteger.valueOf(236272L)));
        } else {
            value = value.longValue();
            expected = 236272L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tow + "' != '" + 407084800 + "'",
                    value.equals(BigInteger.valueOf(407084800L)));
        } else {
            value = value.longValue();
            expected = 407084800L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.wn + "' != '" + 1838 + "'", value.equals(BigInteger.valueOf(1838L)));
        } else {
            value = value.longValue();
            expected = 1838L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test10() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgGPSTimeDepATest.test10");
        byte[] payload =
                new byte[] {
                    (byte) 46,
                    (byte) 7,
                    (byte) 100,
                    (byte) 159,
                    (byte) 67,
                    (byte) 24,
                    (byte) 144,
                    (byte) 101,
                    (byte) 252,
                    (byte) 255,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x4c3, 0x100, payload);
        MsgGPSTimeDepA msg = new MsgGPSTimeDepA(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.flags + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.ns_residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.ns_residual + "' != '" + -236144 + "'",
                    value.equals(BigInteger.valueOf(-236144L)));
        } else {
            value = value.longValue();
            expected = -236144L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tow + "' != '" + 407084900 + "'",
                    value.equals(BigInteger.valueOf(407084900L)));
        } else {
            value = value.longValue();
            expected = 407084900L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.wn + "' != '" + 1838 + "'", value.equals(BigInteger.valueOf(1838L)));
        } else {
            value = value.longValue();
            expected = 1838L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test11() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgGPSTimeDepATest.test11");
        byte[] payload =
                new byte[] {
                    (byte) 46,
                    (byte) 7,
                    (byte) 46,
                    (byte) 162,
                    (byte) 68,
                    (byte) 24,
                    (byte) 205,
                    (byte) 230,
                    (byte) 250,
                    (byte) 255,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x4c3, 0x100, payload);
        MsgGPSTimeDepA msg = new MsgGPSTimeDepA(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.flags + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.ns_residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.ns_residual + "' != '" + -334131 + "'",
                    value.equals(BigInteger.valueOf(-334131L)));
        } else {
            value = value.longValue();
            expected = -334131L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tow + "' != '" + 407151150 + "'",
                    value.equals(BigInteger.valueOf(407151150L)));
        } else {
            value = value.longValue();
            expected = 407151150L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.wn + "' != '" + 1838 + "'", value.equals(BigInteger.valueOf(1838L)));
        } else {
            value = value.longValue();
            expected = 1838L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }
}
