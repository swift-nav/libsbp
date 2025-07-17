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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/navigation/test_MsgPosLlhAcc.yaml by generate.py. Do not modify by hand!

import java.math.BigInteger;

import org.junit.Test;

import org.json.JSONObject;

import com.swiftnav.sbp.SBPMessage;

import com.swiftnav.sbp.navigation.MsgPosLLHAcc;


public class auto_check_sbp_navigation_MsgPosLlhAccTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_navigation_MsgPosLlhAccTest.test1");
        byte[] payload = new byte[] {(byte)39,(byte)120,(byte)110,(byte)18,(byte)51,(byte)51,(byte)51,(byte)51,(byte)51,(byte)139,(byte)189,(byte)64,(byte)154,(byte)153,(byte)153,(byte)153,(byte)25,(byte)151,(byte)192,(byte)64,(byte)51,(byte)51,(byte)51,(byte)51,(byte)51,(byte)161,(byte)176,(byte)64,(byte)51,(byte)51,(byte)51,(byte)51,(byte)51,(byte)101,(byte)179,(byte)64,(byte)51,(byte)163,(byte)22,(byte)69,(byte)154,(byte)25,(byte)173,(byte)69,(byte)102,(byte)134,(byte)243,(byte)68,(byte)154,(byte)201,(byte)196,(byte)69,(byte)205,(byte)224,(byte)0,(byte)70,(byte)51,(byte)35,(byte)72,(byte)69,(byte)51,(byte)99,(byte)31,(byte)69,(byte)95,(byte)27,(byte)72, };
        SBPMessage sbp = new SBPMessage( 0x1c02, 0x218, payload );
        MsgPosLLHAcc msg = new MsgPosLLHAcc( sbp );
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        org.junit.Assert.assertEquals(msg.at_accuracy, 6.29720019531250000e+03, DELTA);
        value = msg.confidence_and_geoid;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.confidence_and_geoid + "' != '" + 95 + "'", value.equals(BigInteger.valueOf( 95L ) ) );
        } else {
            value = value.longValue();
            expected = 95L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.ct_accuracy, 1.94819995117187500e+03, DELTA);
        value = msg.flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.flags + "' != '" + 72 + "'", value.equals(BigInteger.valueOf( 72L ) ) );
        } else {
            value = value.longValue();
            expected = 72L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.h_accuracy, 2.41019995117187500e+03, DELTA);
        org.junit.Assert.assertEquals(msg.h_ellipse.orientation, 2.55019995117187500e+03, DELTA);
        org.junit.Assert.assertEquals(msg.h_ellipse.semi_major, 8.24820019531250000e+03, DELTA);
        org.junit.Assert.assertEquals(msg.h_ellipse.semi_minor, 3.20219995117187500e+03, DELTA);
        org.junit.Assert.assertEquals(msg.height, 4.25719999999999982e+03, DELTA);
        org.junit.Assert.assertEquals(msg.lat, 7.56319999999999982e+03, DELTA);
        org.junit.Assert.assertEquals(msg.lon, 8.49420000000000073e+03, DELTA);
        value = msg.n_sats;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.n_sats + "' != '" + 27 + "'", value.equals(BigInteger.valueOf( 27L ) ) );
        } else {
            value = value.longValue();
            expected = 27L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.orthometric_height, 4.96519999999999982e+03, DELTA);
        value = msg.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.tow + "' != '" + 309229607 + "'", value.equals(BigInteger.valueOf( 309229607L ) ) );
        } else {
            value = value.longValue();
            expected = 309229607L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.v_accuracy, 5.53920019531250000e+03, DELTA);

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
