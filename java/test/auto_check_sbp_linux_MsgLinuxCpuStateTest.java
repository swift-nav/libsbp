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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/linux/test_MsgLinuxCpuState.yaml
// by generate.py. Do not modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.linux.MsgLinuxCpuState;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_linux_MsgLinuxCpuStateTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_linux_MsgLinuxCpuStateTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 101,
                    (byte) 122,
                    (byte) 195,
                    (byte) 98,
                    (byte) 215,
                    (byte) 35,
                    (byte) 94,
                    (byte) 235,
                    (byte) 20,
                    (byte) 112,
                    (byte) 114,
                    (byte) 111,
                    (byte) 99,
                    (byte) 101,
                    (byte) 115,
                    (byte) 115,
                    (byte) 45,
                    (byte) 110,
                    (byte) 97,
                    (byte) 109,
                    (byte) 101,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 47,
                    (byte) 112,
                    (byte) 97,
                    (byte) 116,
                    (byte) 104,
                    (byte) 47,
                    (byte) 116,
                    (byte) 111,
                    (byte) 47,
                    (byte) 112,
                    (byte) 114,
                    (byte) 111,
                    (byte) 99,
                    (byte) 101,
                    (byte) 115,
                    (byte) 115,
                    (byte) 45,
                    (byte) 110,
                    (byte) 97,
                    (byte) 109,
                    (byte) 101,
                    (byte) 32,
                    (byte) 97,
                    (byte) 114,
                    (byte) 103,
                    (byte) 48,
                    (byte) 32,
                    (byte) 97,
                    (byte) 114,
                    (byte) 103,
                    (byte) 49,
                    (byte) 32,
                    (byte) 97,
                    (byte) 114,
                    (byte) 103,
                    (byte) 50,
                    (byte) 32,
                    (byte) 97,
                    (byte) 114,
                    (byte) 103,
                    (byte) 51,
                    (byte) 32,
                    (byte) 97,
                    (byte) 114,
                    (byte) 103,
                    (byte) 52,
                };
        SBPMessage sbp = new SBPMessage(0x8594, 0x7f08, payload);
        MsgLinuxCpuState msg = new MsgLinuxCpuState(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        org.junit.Assert.assertEquals(
                msg.cmdline, "/path/to/process-name arg0 arg1 arg2 arg3 arg4");
        value = msg.flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.flags + "' != '" + 20 + "'", value.equals(BigInteger.valueOf(20L)));
        } else {
            value = value.longValue();
            expected = 20L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.index;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.index + "' != '" + 101 + "'", value.equals(BigInteger.valueOf(101L)));
        } else {
            value = value.longValue();
            expected = 101L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.pcpu;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.pcpu + "' != '" + 98 + "'", value.equals(BigInteger.valueOf(98L)));
        } else {
            value = value.longValue();
            expected = 98L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.pid;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.pid + "' != '" + 50042 + "'",
                    value.equals(BigInteger.valueOf(50042L)));
        } else {
            value = value.longValue();
            expected = 50042L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.time;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.time + "' != '" + 3948815319L + "'",
                    value.equals(new BigInteger("3948815319")));
        } else {
            value = value.longValue();
            expected = 3948815319L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.tname, "process-name   ");

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
