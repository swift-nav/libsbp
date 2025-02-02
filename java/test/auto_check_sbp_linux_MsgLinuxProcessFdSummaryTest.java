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
// spec/tests/yaml/swiftnav/sbp/linux/test_MsgLinuxProcessFdSummary.yaml by generate.py. Do not
// modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.linux.MsgLinuxProcessFdSummary;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_linux_MsgLinuxProcessFdSummaryTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_linux_MsgLinuxProcessFdSummaryTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 19, (byte) 131, (byte) 200, (byte) 77, (byte) 102, (byte) 100, (byte) 49,
                    (byte) 0, (byte) 102, (byte) 100, (byte) 50, (byte) 0, (byte) 102, (byte) 100,
                    (byte) 51, (byte) 0, (byte) 102, (byte) 100, (byte) 52, (byte) 0, (byte) 102,
                    (byte) 100, (byte) 53, (byte) 0, (byte) 102, (byte) 100, (byte) 54, (byte) 0,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0xf867, 0x7f07, payload);
        MsgLinuxProcessFdSummary msg = new MsgLinuxProcessFdSummary(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        org.junit.Assert.assertEquals(msg.most_opened, "fd1 fd2 fd3 fd4 fd5 fd6  ");
        value = msg.sys_fd_count;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sys_fd_count + "' != '" + 1304986387 + "'",
                    value.equals(BigInteger.valueOf(1304986387L)));
        } else {
            value = value.longValue();
            expected = 1304986387L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
