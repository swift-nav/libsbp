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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/piksi/test_MsgIarState.yaml by
// generate.py. Do not modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.piksi.MsgIarState;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_piksi_MsgIarStateTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_piksi_MsgIarStateTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 1, (byte) 0, (byte) 0, (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0xd7f6, 0x19, payload);
        MsgIarState msg = new MsgIarState(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.num_hyps;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.num_hyps + "' != '" + 1 + "'", value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test2() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_piksi_MsgIarStateTest.test2");
        byte[] payload =
                new byte[] {
                    (byte) 0, (byte) 0, (byte) 0, (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x4c3, 0x19, payload);
        MsgIarState msg = new MsgIarState(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.num_hyps;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.num_hyps + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test3() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_piksi_MsgIarStateTest.test3");
        byte[] payload =
                new byte[] {
                    (byte) 1, (byte) 0, (byte) 0, (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x4c3, 0x19, payload);
        MsgIarState msg = new MsgIarState(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.num_hyps;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.num_hyps + "' != '" + 1 + "'", value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test4() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_piksi_MsgIarStateTest.test4");
        byte[] payload =
                new byte[] {
                    (byte) 217, (byte) 2, (byte) 0, (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x4c3, 0x19, payload);
        MsgIarState msg = new MsgIarState(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.num_hyps;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.num_hyps + "' != '" + 729 + "'",
                    value.equals(BigInteger.valueOf(729L)));
        } else {
            value = value.longValue();
            expected = 729L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test5() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_piksi_MsgIarStateTest.test5");
        byte[] payload =
                new byte[] {
                    (byte) 216, (byte) 2, (byte) 0, (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x4c3, 0x19, payload);
        MsgIarState msg = new MsgIarState(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.num_hyps;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.num_hyps + "' != '" + 728 + "'",
                    value.equals(BigInteger.valueOf(728L)));
        } else {
            value = value.longValue();
            expected = 728L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test6() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_piksi_MsgIarStateTest.test6");
        byte[] payload =
                new byte[] {
                    (byte) 215, (byte) 2, (byte) 0, (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x4c3, 0x19, payload);
        MsgIarState msg = new MsgIarState(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.num_hyps;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.num_hyps + "' != '" + 727 + "'",
                    value.equals(BigInteger.valueOf(727L)));
        } else {
            value = value.longValue();
            expected = 727L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test7() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_piksi_MsgIarStateTest.test7");
        byte[] payload =
                new byte[] {
                    (byte) 211, (byte) 2, (byte) 0, (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x4c3, 0x19, payload);
        MsgIarState msg = new MsgIarState(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.num_hyps;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.num_hyps + "' != '" + 723 + "'",
                    value.equals(BigInteger.valueOf(723L)));
        } else {
            value = value.longValue();
            expected = 723L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }
}
