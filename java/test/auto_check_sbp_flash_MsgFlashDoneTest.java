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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/flash/test_MsgFlashDone.yaml by generate.py. Do not modify by hand!

import java.math.BigInteger;

import org.junit.Test;

import org.json.JSONObject;

import com.swiftnav.sbp.SBPMessage;

import com.swiftnav.sbp.flash.MsgFlashDone;


public class auto_check_sbp_flash_MsgFlashDoneTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_flash_MsgFlashDoneTest.test1");
        byte[] payload = new byte[] {(byte)82, };
        SBPMessage sbp = new SBPMessage( 0x04c3, 0xe0, payload );
        MsgFlashDone msg = new MsgFlashDone( sbp );
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.response;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.response + "' != '" + 82 + "'", value.equals(BigInteger.valueOf( 82L ) ) );
        } else {
            value = value.longValue();
            expected = 82L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
