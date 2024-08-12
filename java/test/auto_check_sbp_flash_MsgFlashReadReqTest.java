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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/flash/test_MsgFlashReadReq.yaml by
// generate.py. Do not modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.flash.MsgFlashReadReq;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_flash_MsgFlashReadReqTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_flash_MsgFlashReadReqTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 241, (byte) 28, (byte) 75, (byte) 244, (byte) 71,
                };
        SBPMessage sbp = new SBPMessage(0x04c3, 0xe7, payload);
        MsgFlashReadReq msg = new MsgFlashReadReq(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.addr_len;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.addr_len + "' != '" + 71 + "'",
                    value.equals(BigInteger.valueOf(71L)));
        } else {
            value = value.longValue();
            expected = 71L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.addr_start[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.addr_start[0] + "' != '" + 28 + "'",
                    value.equals(BigInteger.valueOf(28L)));
        } else {
            value = value.longValue();
            expected = 28L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.addr_start[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.addr_start[1] + "' != '" + 75 + "'",
                    value.equals(BigInteger.valueOf(75L)));
        } else {
            value = value.longValue();
            expected = 75L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.addr_start[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.addr_start[2] + "' != '" + 244 + "'",
                    value.equals(BigInteger.valueOf(244L)));
        } else {
            value = value.longValue();
            expected = 244L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.target;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.target + "' != '" + 241 + "'",
                    value.equals(BigInteger.valueOf(241L)));
        } else {
            value = value.longValue();
            expected = 241L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
