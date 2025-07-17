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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/system/test_MsgPpsTime.yaml by generate.py. Do not modify by hand!

import java.math.BigInteger;

import org.junit.Test;

import org.json.JSONObject;

import com.swiftnav.sbp.SBPMessage;

import com.swiftnav.sbp.system.MsgPpsTime;


public class auto_check_sbp_system_MsgPpsTimeTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_system_MsgPpsTimeTest.test1");
        byte[] payload = new byte[] {(byte)140,(byte)146,(byte)133,(byte)197,(byte)160,(byte)0,(byte)0,(byte)0,(byte)255, };
        SBPMessage sbp = new SBPMessage( 0xd1de, 0xff08, payload );
        MsgPpsTime msg = new MsgPpsTime( sbp );
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.flags + "' != '" + 255 + "'", value.equals(BigInteger.valueOf( 255L ) ) );
        } else {
            value = value.longValue();
            expected = 255L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.time;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.time + "' != '" + 690508632716L + "'", value.equals( new BigInteger( "690508632716" ) ) );
        } else {
            value = value.longValue();
            expected = 690508632716L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
