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
// spec/tests/yaml/swiftnav/sbp/linux/test_MsgLinuxCpuStateDepA.yaml by generate.py. Do not modify
// by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.linux.MsgLinuxCpuStateDepA;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_linux_MsgLinuxCpuStateDepATest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_linux_MsgLinuxCpuStateDepATest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 51,
                    (byte) 240,
                    (byte) 250,
                    (byte) 178,
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
        SBPMessage sbp = new SBPMessage(0x5b0c, 0x7f00, payload);
        MsgLinuxCpuStateDepA msg = new MsgLinuxCpuStateDepA(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        org.junit.Assert.assertEquals(
                msg.cmdline, "/path/to/process-name arg0 arg1 arg2 arg3 arg4");
        value = msg.index;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.index + "' != '" + 51 + "'", value.equals(BigInteger.valueOf(51L)));
        } else {
            value = value.longValue();
            expected = 51L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.pcpu;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.pcpu + "' != '" + 178 + "'", value.equals(BigInteger.valueOf(178L)));
        } else {
            value = value.longValue();
            expected = 178L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.pid;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.pid + "' != '" + 64240 + "'",
                    value.equals(BigInteger.valueOf(64240L)));
        } else {
            value = value.longValue();
            expected = 64240L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.tname, "process-name   ");

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
