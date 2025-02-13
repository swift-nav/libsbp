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
// spec/tests/yaml/swiftnav/sbp/linux/test_MsgLinuxProcessSocketQueues.yaml by generate.py. Do not
// modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.linux.MsgLinuxProcessSocketQueues;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_linux_MsgLinuxProcessSocketQueuesTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format(
                    "%n%s%n", "auto_check_sbp_linux_MsgLinuxProcessSocketQueuesTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 181,
                    (byte) 135,
                    (byte) 75,
                    (byte) 249,
                    (byte) 211,
                    (byte) 35,
                    (byte) 252,
                    (byte) 80,
                    (byte) 109,
                    (byte) 15,
                    (byte) 223,
                    (byte) 97,
                    (byte) 100,
                    (byte) 100,
                    (byte) 114,
                    (byte) 101,
                    (byte) 115,
                    (byte) 115,
                    (byte) 32,
                    (byte) 111,
                    (byte) 102,
                    (byte) 32,
                    (byte) 108,
                    (byte) 97,
                    (byte) 114,
                    (byte) 103,
                    (byte) 101,
                    (byte) 115,
                    (byte) 116,
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
        SBPMessage sbp = new SBPMessage(0xe8bb, 0x7f04, payload);
        MsgLinuxProcessSocketQueues msg = new MsgLinuxProcessSocketQueues(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        org.junit.Assert.assertEquals(
                msg.address_of_largest,
                "address of largest                                              ");
        org.junit.Assert.assertEquals(
                msg.cmdline, "/path/to/process-name arg0 arg1 arg2 arg3 arg4");
        value = msg.index;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.index + "' != '" + 181 + "'", value.equals(BigInteger.valueOf(181L)));
        } else {
            value = value.longValue();
            expected = 181L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.pid;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.pid + "' != '" + 19335 + "'",
                    value.equals(BigInteger.valueOf(19335L)));
        } else {
            value = value.longValue();
            expected = 19335L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.recv_queued;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.recv_queued + "' != '" + 54265 + "'",
                    value.equals(BigInteger.valueOf(54265L)));
        } else {
            value = value.longValue();
            expected = 54265L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.send_queued;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.send_queued + "' != '" + 64547 + "'",
                    value.equals(BigInteger.valueOf(64547L)));
        } else {
            value = value.longValue();
            expected = 64547L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.socket_states;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.socket_states + "' != '" + 57103 + "'",
                    value.equals(BigInteger.valueOf(57103L)));
        } else {
            value = value.longValue();
            expected = 57103L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.socket_types;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.socket_types + "' != '" + 27984 + "'",
                    value.equals(BigInteger.valueOf(27984L)));
        } else {
            value = value.longValue();
            expected = 27984L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
