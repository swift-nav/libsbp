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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/tracking/test_MsgTrackingStateDetailedDepA.yaml by generate.py. Do not modify by hand!

import java.math.BigInteger;

import org.junit.Test;

import org.json.JSONObject;

import com.swiftnav.sbp.SBPMessage;

import com.swiftnav.sbp.tracking.MsgTrackingStateDetailedDepA;


public class auto_check_sbp_tracking_MsgTrackingStateDetailedDepATest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_tracking_MsgTrackingStateDetailedDepATest.test1");
        byte[] payload = new byte[] {(byte)46,(byte)31,(byte)180,(byte)38,(byte)219,(byte)0,(byte)0,(byte)0,(byte)133,(byte)100,(byte)71,(byte)94,(byte)192,(byte)2,(byte)160,(byte)207,(byte)212,(byte)255,(byte)135,(byte)139,(byte)62,(byte)62,(byte)179,(byte)83,(byte)227,(byte)245,(byte)134,(byte)160,(byte)204,(byte)78,(byte)95,(byte)255,(byte)38,(byte)59,(byte)161,(byte)15,(byte)255,(byte)86,(byte)189,(byte)248,(byte)31,(byte)191,(byte)136,(byte)194,(byte)124,(byte)23,(byte)15,(byte)91,(byte)249,(byte)117,(byte)142,(byte)90,(byte)219,(byte)67,(byte)25,(byte)83,(byte)62, };
        SBPMessage sbp = new SBPMessage( 0x6e9b, 0x21, payload );
        MsgTrackingStateDetailedDepA msg = new MsgTrackingStateDetailedDepA( sbp );
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.L.f + "' != '" + 204 + "'", value.equals(BigInteger.valueOf( 204L ) ) );
        } else {
            value = value.longValue();
            expected = 204L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.L.i + "' != '" + -1601767965 + "'", value.equals(BigInteger.valueOf( -1601767965L ) ) );
        } else {
            value = value.longValue();
            expected = -1601767965L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.P + "' != '" + 1044286343 + "'", value.equals(BigInteger.valueOf( 1044286343L ) ) );
        } else {
            value = value.longValue();
            expected = 1044286343L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.P_std;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.P_std + "' != '" + 21427 + "'", value.equals(BigInteger.valueOf( 21427L ) ) );
        } else {
            value = value.longValue();
            expected = 21427L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acceleration;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.acceleration + "' != '" + -114 + "'", value.equals(BigInteger.valueOf( -114L ) ) );
        } else {
            value = value.longValue();
            expected = -114L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.clock_drift;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.clock_drift + "' != '" + 23311 + "'", value.equals(BigInteger.valueOf( 23311L ) ) );
        } else {
            value = value.longValue();
            expected = 23311L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.clock_offset;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.clock_offset + "' != '" + 6012 + "'", value.equals(BigInteger.valueOf( 6012L ) ) );
        } else {
            value = value.longValue();
            expected = 6012L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.cn0 + "' != '" + 78 + "'", value.equals(BigInteger.valueOf( 78L ) ) );
        } else {
            value = value.longValue();
            expected = 78L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.corr_spacing;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.corr_spacing + "' != '" + 30201 + "'", value.equals(BigInteger.valueOf( 30201L ) ) );
        } else {
            value = value.longValue();
            expected = 30201L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.doppler;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.doppler + "' != '" + 1459556257 + "'", value.equals(BigInteger.valueOf( 1459556257L ) ) );
        } else {
            value = value.longValue();
            expected = 1459556257L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.doppler_std;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.doppler_std + "' != '" + 63677 + "'", value.equals(BigInteger.valueOf( 63677L ) ) );
        } else {
            value = value.longValue();
            expected = 63677L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.lock + "' != '" + 65375 + "'", value.equals(BigInteger.valueOf( 65375L ) ) );
        } else {
            value = value.longValue();
            expected = 65375L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.misc_flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.misc_flags + "' != '" + 62 + "'", value.equals(BigInteger.valueOf( 62L ) ) );
        } else {
            value = value.longValue();
            expected = 62L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.nav_flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.nav_flags + "' != '" + 25 + "'", value.equals(BigInteger.valueOf( 25L ) ) );
        } else {
            value = value.longValue();
            expected = 25L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.pset_flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.pset_flags + "' != '" + 83 + "'", value.equals(BigInteger.valueOf( 83L ) ) );
        } else {
            value = value.longValue();
            expected = 83L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.recv_time;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.recv_time + "' != '" + 941247176494L + "'", value.equals( new BigInteger( "941247176494" ) ) );
        } else {
            value = value.longValue();
            expected = 941247176494L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.sid.code + "' != '" + 59 + "'", value.equals(BigInteger.valueOf( 59L ) ) );
        } else {
            value = value.longValue();
            expected = 59L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.sid.sat + "' != '" + 38 + "'", value.equals(BigInteger.valueOf( 38L ) ) );
        } else {
            value = value.longValue();
            expected = 38L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sync_flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.sync_flags + "' != '" + 90 + "'", value.equals(BigInteger.valueOf( 90L ) ) );
        } else {
            value = value.longValue();
            expected = 90L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tot.ns_residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.tot.ns_residual + "' != '" + -811597120 + "'", value.equals(BigInteger.valueOf( -811597120L ) ) );
        } else {
            value = value.longValue();
            expected = -811597120L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tot.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.tot.tow + "' != '" + 1581737093 + "'", value.equals(BigInteger.valueOf( 1581737093L ) ) );
        } else {
            value = value.longValue();
            expected = 1581737093L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tot.wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.tot.wn + "' != '" + 65492 + "'", value.equals(BigInteger.valueOf( 65492L ) ) );
        } else {
            value = value.longValue();
            expected = 65492L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tow_flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.tow_flags + "' != '" + 219 + "'", value.equals(BigInteger.valueOf( 219L ) ) );
        } else {
            value = value.longValue();
            expected = 219L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.track_flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.track_flags + "' != '" + 67 + "'", value.equals(BigInteger.valueOf( 67L ) ) );
        } else {
            value = value.longValue();
            expected = 67L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.uptime;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.uptime + "' != '" + 3263741727L + "'", value.equals( new BigInteger( "3263741727" ) ) );
        } else {
            value = value.longValue();
            expected = 3263741727L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
