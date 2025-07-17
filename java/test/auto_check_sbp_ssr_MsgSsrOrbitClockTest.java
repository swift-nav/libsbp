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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrOrbitClock.yaml by generate.py. Do not modify by hand!

import java.math.BigInteger;

import org.junit.Test;

import org.json.JSONObject;

import com.swiftnav.sbp.SBPMessage;

import com.swiftnav.sbp.ssr.MsgSsrOrbitClock;


public class auto_check_sbp_ssr_MsgSsrOrbitClockTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_ssr_MsgSsrOrbitClockTest.test1");
        byte[] payload = new byte[] {(byte)83,(byte)208,(byte)102,(byte)207,(byte)164,(byte)29,(byte)203,(byte)212,(byte)236,(byte)255,(byte)152,(byte)233,(byte)207,(byte)55,(byte)94,(byte)54,(byte)58,(byte)128,(byte)68,(byte)27,(byte)117,(byte)176,(byte)110,(byte)251,(byte)61,(byte)244,(byte)122,(byte)50,(byte)95,(byte)52,(byte)144,(byte)232,(byte)24,(byte)10,(byte)37,(byte)127,(byte)163,(byte)66,(byte)177,(byte)105,(byte)156,(byte)245,(byte)10,(byte)249,(byte)107,(byte)218,(byte)17,(byte)186,(byte)56,(byte)72, };
        SBPMessage sbp = new SBPMessage( 0xe535, 0x5dd, payload );
        MsgSsrOrbitClock msg = new MsgSsrOrbitClock( sbp );
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.along;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.along + "' != '" + -1334502588 + "'", value.equals(BigInteger.valueOf( -1334502588L ) ) );
        } else {
            value = value.longValue();
            expected = -1334502588L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.c0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.c0 + "' != '" + -174298703 + "'", value.equals(BigInteger.valueOf( -174298703L ) ) );
        } else {
            value = value.longValue();
            expected = -174298703L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.c1;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.c1 + "' != '" + -630458102 + "'", value.equals(BigInteger.valueOf( -630458102L ) ) );
        } else {
            value = value.longValue();
            expected = -630458102L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.c2;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.c2 + "' != '" + 1211677201 + "'", value.equals(BigInteger.valueOf( 1211677201L ) ) );
        } else {
            value = value.longValue();
            expected = 1211677201L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.cross;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.cross + "' != '" + -197264530 + "'", value.equals(BigInteger.valueOf( -197264530L ) ) );
        } else {
            value = value.longValue();
            expected = -197264530L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.dot_along;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.dot_along + "' != '" + 169404560 + "'", value.equals(BigInteger.valueOf( 169404560L ) ) );
        } else {
            value = value.longValue();
            expected = 169404560L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.dot_cross;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.dot_cross + "' != '" + 1118011173 + "'", value.equals(BigInteger.valueOf( 1118011173L ) ) );
        } else {
            value = value.longValue();
            expected = 1118011173L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.dot_radial;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.dot_radial + "' != '" + 878654074 + "'", value.equals(BigInteger.valueOf( 878654074L ) ) );
        } else {
            value = value.longValue();
            expected = 878654074L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.iod;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.iod + "' != '" + 936372632 + "'", value.equals(BigInteger.valueOf( 936372632L ) ) );
        } else {
            value = value.longValue();
            expected = 936372632L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.iod_ssr;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.iod_ssr + "' != '" + 255 + "'", value.equals(BigInteger.valueOf( 255L ) ) );
        } else {
            value = value.longValue();
            expected = 255L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.radial;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.radial + "' != '" + -2143668642 + "'", value.equals(BigInteger.valueOf( -2143668642L ) ) );
        } else {
            value = value.longValue();
            expected = -2143668642L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.sid.code + "' != '" + 212 + "'", value.equals(BigInteger.valueOf( 212L ) ) );
        } else {
            value = value.longValue();
            expected = 212L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.sid.sat + "' != '" + 203 + "'", value.equals(BigInteger.valueOf( 203L ) ) );
        } else {
            value = value.longValue();
            expected = 203L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.time.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.time.tow + "' != '" + 3479621715L + "'", value.equals( new BigInteger( "3479621715" ) ) );
        } else {
            value = value.longValue();
            expected = 3479621715L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.time.wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.time.wn + "' != '" + 7588 + "'", value.equals(BigInteger.valueOf( 7588L ) ) );
        } else {
            value = value.longValue();
            expected = 7588L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.update_interval;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.update_interval + "' != '" + 236 + "'", value.equals(BigInteger.valueOf( 236L ) ) );
        } else {
            value = value.longValue();
            expected = 236L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
