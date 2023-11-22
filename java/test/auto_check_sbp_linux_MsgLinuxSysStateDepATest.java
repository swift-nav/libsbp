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
// spec/tests/yaml/swiftnav/sbp/linux/test_MsgLinuxSysStateDepA.yaml by generate.py. Do not modify
// by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.linux.MsgLinuxSysStateDepA;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_linux_MsgLinuxSysStateDepATest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_linux_MsgLinuxSysStateDepATest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 188,
                    (byte) 163,
                    (byte) 211,
                    (byte) 194,
                    (byte) 115,
                    (byte) 71,
                    (byte) 101,
                    (byte) 103,
                    (byte) 124,
                    (byte) 201,
                };
        SBPMessage sbp = new SBPMessage(0x3854, 0x7f02, payload);
        MsgLinuxSysStateDepA msg = new MsgLinuxSysStateDepA(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.mem_total;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.mem_total + "' != '" + 41916 + "'",
                    value.equals(BigInteger.valueOf(41916L)));
        } else {
            value = value.longValue();
            expected = 41916L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.pcpu;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.pcpu + "' != '" + 211 + "'", value.equals(BigInteger.valueOf(211L)));
        } else {
            value = value.longValue();
            expected = 211L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.pid_count;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.pid_count + "' != '" + 51580 + "'",
                    value.equals(BigInteger.valueOf(51580L)));
        } else {
            value = value.longValue();
            expected = 51580L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.pmem;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.pmem + "' != '" + 194 + "'", value.equals(BigInteger.valueOf(194L)));
        } else {
            value = value.longValue();
            expected = 194L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.procs_starting;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.procs_starting + "' != '" + 18291 + "'",
                    value.equals(BigInteger.valueOf(18291L)));
        } else {
            value = value.longValue();
            expected = 18291L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.procs_stopping;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.procs_stopping + "' != '" + 26469 + "'",
                    value.equals(BigInteger.valueOf(26469L)));
        } else {
            value = value.longValue();
            expected = 26469L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
