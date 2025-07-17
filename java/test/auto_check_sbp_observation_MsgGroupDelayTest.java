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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/observation/test_MsgGroupDelay.yaml by generate.py. Do not modify by hand!

import java.math.BigInteger;

import org.junit.Test;

import org.json.JSONObject;

import com.swiftnav.sbp.SBPMessage;

import com.swiftnav.sbp.observation.MsgGroupDelay;


public class auto_check_sbp_observation_MsgGroupDelayTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_observation_MsgGroupDelayTest.test1");
        byte[] payload = new byte[] {(byte)176,(byte)207,(byte)6,(byte)0,(byte)106,(byte)8,(byte)22,(byte)0,(byte)1,(byte)254,(byte)253,(byte)165,(byte)255,(byte)237,(byte)23, };
        SBPMessage sbp = new SBPMessage( 0x007b, 0x94, payload );
        MsgGroupDelay msg = new MsgGroupDelay( sbp );
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.isc_l1ca;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.isc_l1ca + "' != '" + -91 + "'", value.equals(BigInteger.valueOf( -91L ) ) );
        } else {
            value = value.longValue();
            expected = -91L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.isc_l2c;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.isc_l2c + "' != '" + 6125 + "'", value.equals(BigInteger.valueOf( 6125L ) ) );
        } else {
            value = value.longValue();
            expected = 6125L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.sid.code + "' != '" + 0 + "'", value.equals(BigInteger.valueOf( 0L ) ) );
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.sid.sat + "' != '" + 22 + "'", value.equals(BigInteger.valueOf( 22L ) ) );
        } else {
            value = value.longValue();
            expected = 22L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.t_op.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.t_op.tow + "' != '" + 446384 + "'", value.equals(BigInteger.valueOf( 446384L ) ) );
        } else {
            value = value.longValue();
            expected = 446384L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.t_op.wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.t_op.wn + "' != '" + 2154 + "'", value.equals(BigInteger.valueOf( 2154L ) ) );
        } else {
            value = value.longValue();
            expected = 2154L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tgd;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.tgd + "' != '" + -514 + "'", value.equals(BigInteger.valueOf( -514L ) ) );
        } else {
            value = value.longValue();
            expected = -514L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.valid;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.valid + "' != '" + 1 + "'", value.equals(BigInteger.valueOf( 1L ) ) );
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
