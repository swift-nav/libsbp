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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/tracking/test_MsgTrackingIq.yaml by generate.py. Do not modify by hand!

import java.math.BigInteger;

import org.junit.Test;

import org.json.JSONObject;

import com.swiftnav.sbp.SBPMessage;

import com.swiftnav.sbp.tracking.MsgTrackingIq;


public class auto_check_sbp_tracking_MsgTrackingIqTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_tracking_MsgTrackingIqTest.test1");
        byte[] payload = new byte[] {(byte)145,(byte)121,(byte)203,(byte)47,(byte)217,(byte)239,(byte)55,(byte)45,(byte)38,(byte)189,(byte)88,(byte)159,(byte)19,(byte)208,(byte)12, };
        SBPMessage sbp = new SBPMessage( 0x5002, 0x2d, payload );
        MsgTrackingIq msg = new MsgTrackingIq( sbp );
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.channel;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.channel + "' != '" + 145 + "'", value.equals(BigInteger.valueOf( 145L ) ) );
        } else {
            value = value.longValue();
            expected = 145L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.corrs[0].I;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.corrs[0].I + "' != '" + -9937 + "'", value.equals(BigInteger.valueOf( -9937L ) ) );
        } else {
            value = value.longValue();
            expected = -9937L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.corrs[0].Q;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.corrs[0].Q + "' != '" + 14319 + "'", value.equals(BigInteger.valueOf( 14319L ) ) );
        } else {
            value = value.longValue();
            expected = 14319L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.corrs[1].I;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.corrs[1].I + "' != '" + 9773 + "'", value.equals(BigInteger.valueOf( 9773L ) ) );
        } else {
            value = value.longValue();
            expected = 9773L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.corrs[1].Q;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.corrs[1].Q + "' != '" + 22717 + "'", value.equals(BigInteger.valueOf( 22717L ) ) );
        } else {
            value = value.longValue();
            expected = 22717L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.corrs[2].I;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.corrs[2].I + "' != '" + 5023 + "'", value.equals(BigInteger.valueOf( 5023L ) ) );
        } else {
            value = value.longValue();
            expected = 5023L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.corrs[2].Q;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.corrs[2].Q + "' != '" + 3280 + "'", value.equals(BigInteger.valueOf( 3280L ) ) );
        } else {
            value = value.longValue();
            expected = 3280L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.sid.code + "' != '" + 203 + "'", value.equals(BigInteger.valueOf( 203L ) ) );
        } else {
            value = value.longValue();
            expected = 203L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.sid.sat + "' != '" + 121 + "'", value.equals(BigInteger.valueOf( 121L ) ) );
        } else {
            value = value.longValue();
            expected = 121L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
