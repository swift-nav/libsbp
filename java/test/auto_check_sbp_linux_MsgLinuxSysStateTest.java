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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/linux/test_MsgLinuxSysState.yaml
// by generate.py. Do not modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.linux.MsgLinuxSysState;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_linux_MsgLinuxSysStateTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_linux_MsgLinuxSysStateTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 20, (byte) 207, (byte) 125, (byte) 215, (byte) 196, (byte) 71,
                    (byte) 161, (byte) 229, (byte) 250, (byte) 186, (byte) 108, (byte) 30,
                    (byte) 106, (byte) 5, (byte) 9,
                };
        SBPMessage sbp = new SBPMessage(0xa755, 0x7f0a, payload);
        MsgLinuxSysState msg = new MsgLinuxSysState(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.flags + "' != '" + 9 + "'", value.equals(BigInteger.valueOf(9L)));
        } else {
            value = value.longValue();
            expected = 9L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.mem_total;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.mem_total + "' != '" + 53012 + "'",
                    value.equals(BigInteger.valueOf(53012L)));
        } else {
            value = value.longValue();
            expected = 53012L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.pcpu;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.pcpu + "' != '" + 125 + "'", value.equals(BigInteger.valueOf(125L)));
        } else {
            value = value.longValue();
            expected = 125L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.pid_count;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.pid_count + "' != '" + 47866 + "'",
                    value.equals(BigInteger.valueOf(47866L)));
        } else {
            value = value.longValue();
            expected = 47866L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.pmem;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.pmem + "' != '" + 215 + "'", value.equals(BigInteger.valueOf(215L)));
        } else {
            value = value.longValue();
            expected = 215L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.procs_starting;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.procs_starting + "' != '" + 18372 + "'",
                    value.equals(BigInteger.valueOf(18372L)));
        } else {
            value = value.longValue();
            expected = 18372L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.procs_stopping;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.procs_stopping + "' != '" + 58785 + "'",
                    value.equals(BigInteger.valueOf(58785L)));
        } else {
            value = value.longValue();
            expected = 58785L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.time;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.time + "' != '" + 90840684 + "'",
                    value.equals(BigInteger.valueOf(90840684L)));
        } else {
            value = value.longValue();
            expected = 90840684L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
