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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/orientation/test_MsgBaselineHeading.yaml by generate.py. Do not modify by hand!

import java.math.BigInteger;

import org.junit.Test;

import org.json.JSONObject;

import com.swiftnav.sbp.SBPMessage;

import com.swiftnav.sbp.orientation.MsgBaselineHeading;


public class auto_check_sbp_orientation_MsgBaselineHeadingTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_orientation_MsgBaselineHeadingTest.test1");
        byte[] payload = new byte[] {(byte)156,(byte)45,(byte)13,(byte)196,(byte)44,(byte)84,(byte)197,(byte)61,(byte)91,(byte)91, };
        SBPMessage sbp = new SBPMessage( 0x5dd3, 0x20f, payload );
        MsgBaselineHeading msg = new MsgBaselineHeading( sbp );
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.flags + "' != '" + 91 + "'", value.equals(BigInteger.valueOf( 91L ) ) );
        } else {
            value = value.longValue();
            expected = 91L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.heading;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.heading + "' != '" + 1036342316 + "'", value.equals(BigInteger.valueOf( 1036342316L ) ) );
        } else {
            value = value.longValue();
            expected = 1036342316L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.n_sats;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.n_sats + "' != '" + 91 + "'", value.equals(BigInteger.valueOf( 91L ) ) );
        } else {
            value = value.longValue();
            expected = 91L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.tow + "' != '" + 3289197980L + "'", value.equals( new BigInteger( "3289197980" ) ) );
        } else {
            value = value.longValue();
            expected = 3289197980L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
