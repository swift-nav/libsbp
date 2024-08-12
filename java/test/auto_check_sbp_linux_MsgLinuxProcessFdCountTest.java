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
// spec/tests/yaml/swiftnav/sbp/linux/test_MsgLinuxProcessFdCount.yaml by generate.py. Do not modify
// by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.linux.MsgLinuxProcessFdCount;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_linux_MsgLinuxProcessFdCountTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_linux_MsgLinuxProcessFdCountTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 164,
                    (byte) 189,
                    (byte) 165,
                    (byte) 5,
                    (byte) 139,
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
        SBPMessage sbp = new SBPMessage(0xc31e, 0x7f06, payload);
        MsgLinuxProcessFdCount msg = new MsgLinuxProcessFdCount(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        org.junit.Assert.assertEquals(
                msg.cmdline, "/path/to/process-name arg0 arg1 arg2 arg3 arg4");
        value = msg.fd_count;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.fd_count + "' != '" + 35589 + "'",
                    value.equals(BigInteger.valueOf(35589L)));
        } else {
            value = value.longValue();
            expected = 35589L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.index;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.index + "' != '" + 164 + "'", value.equals(BigInteger.valueOf(164L)));
        } else {
            value = value.longValue();
            expected = 164L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.pid;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.pid + "' != '" + 42429 + "'",
                    value.equals(BigInteger.valueOf(42429L)));
        } else {
            value = value.longValue();
            expected = 42429L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
