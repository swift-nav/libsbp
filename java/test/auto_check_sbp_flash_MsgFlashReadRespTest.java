/*
 * Copyright (C) 2015-2021 Swift Navigation Inc.
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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/flash/test_MsgFlashReadResp.yaml by generate.py. Do not modify by hand!

import java.math.BigInteger;

import org.junit.Test;

import org.json.JSONObject;

import com.swiftnav.sbp.SBPMessage;

import com.swiftnav.sbp.flash.MsgFlashReadResp;


public class auto_check_sbp_flash_MsgFlashReadRespTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_flash_MsgFlashReadRespTest.test1");
        byte[] payload = new byte[] {(byte)136,(byte)155,(byte)52,(byte)172,(byte)124, };
        SBPMessage sbp = new SBPMessage( 0x04c3, 0xe1, payload );
        MsgFlashReadResp msg = new MsgFlashReadResp( sbp );
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.addr_len;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.addr_len + "' != '" + 124 + "'", value.equals(BigInteger.valueOf( 124L ) ) );
        } else {
            value = value.longValue();
            expected = 124L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.addr_start[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.addr_start[0] + "' != '" + 155 + "'", value.equals(BigInteger.valueOf( 155L ) ) );
        } else {
            value = value.longValue();
            expected = 155L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.addr_start[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.addr_start[1] + "' != '" + 52 + "'", value.equals(BigInteger.valueOf( 52L ) ) );
        } else {
            value = value.longValue();
            expected = 52L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.addr_start[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.addr_start[2] + "' != '" + 172 + "'", value.equals(BigInteger.valueOf( 172L ) ) );
        } else {
            value = value.longValue();
            expected = 172L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.target;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.target + "' != '" + 136 + "'", value.equals(BigInteger.valueOf( 136L ) ) );
        } else {
            value = value.longValue();
            expected = 136L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
