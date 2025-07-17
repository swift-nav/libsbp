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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/telemetry/test_MsgTelSv.yaml by generate.py. Do not modify by hand!

import java.math.BigInteger;

import org.junit.Test;

import org.json.JSONObject;

import com.swiftnav.sbp.SBPMessage;

import com.swiftnav.sbp.telemetry.MsgTelSv;


public class auto_check_sbp_telemetry_MsgTelSvTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_telemetry_MsgTelSvTest.test1");
        byte[] payload = new byte[] {(byte)175,(byte)8,(byte)208,(byte)221,(byte)62,(byte)24,(byte)16,(byte)1,(byte)40,(byte)50,(byte)5,(byte)226,(byte)255,(byte)1,(byte)0,(byte)1,(byte)1,(byte)1,(byte)33,(byte)12, };
        SBPMessage sbp = new SBPMessage( 0x2694, 0x120, payload );
        MsgTelSv msg = new MsgTelSv( sbp );
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.n_obs;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.n_obs + "' != '" + 16 + "'", value.equals(BigInteger.valueOf( 16L ) ) );
        } else {
            value = value.longValue();
            expected = 16L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.origin_flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.origin_flags + "' != '" + 1 + "'", value.equals(BigInteger.valueOf( 1L ) ) );
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sv_tel[0].availability_flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.sv_tel[0].availability_flags + "' != '" + 5 + "'", value.equals(BigInteger.valueOf( 5L ) ) );
        } else {
            value = value.longValue();
            expected = 5L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sv_tel[0].az;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.sv_tel[0].az + "' != '" + 40 + "'", value.equals(BigInteger.valueOf( 40L ) ) );
        } else {
            value = value.longValue();
            expected = 40L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sv_tel[0].correction_flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.sv_tel[0].correction_flags + "' != '" + 1 + "'", value.equals(BigInteger.valueOf( 1L ) ) );
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sv_tel[0].el;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.sv_tel[0].el + "' != '" + 50 + "'", value.equals(BigInteger.valueOf( 50L ) ) );
        } else {
            value = value.longValue();
            expected = 50L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sv_tel[0].ephemeris_flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.sv_tel[0].ephemeris_flags + "' != '" + 1 + "'", value.equals(BigInteger.valueOf( 1L ) ) );
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sv_tel[0].outlier_flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.sv_tel[0].outlier_flags + "' != '" + 1 + "'", value.equals(BigInteger.valueOf( 1L ) ) );
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sv_tel[0].phase_residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.sv_tel[0].phase_residual + "' != '" + 1 + "'", value.equals(BigInteger.valueOf( 1L ) ) );
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sv_tel[0].pseudorange_residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.sv_tel[0].pseudorange_residual + "' != '" + -30 + "'", value.equals(BigInteger.valueOf( -30L ) ) );
        } else {
            value = value.longValue();
            expected = -30L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sv_tel[0].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.sv_tel[0].sid.code + "' != '" + 12 + "'", value.equals(BigInteger.valueOf( 12L ) ) );
        } else {
            value = value.longValue();
            expected = 12L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sv_tel[0].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.sv_tel[0].sid.sat + "' != '" + 33 + "'", value.equals(BigInteger.valueOf( 33L ) ) );
        } else {
            value = value.longValue();
            expected = 33L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.tow + "' != '" + 406773200 + "'", value.equals(BigInteger.valueOf( 406773200L ) ) );
        } else {
            value = value.longValue();
            expected = 406773200L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.wn + "' != '" + 2223 + "'", value.equals(BigInteger.valueOf( 2223L ) ) );
        } else {
            value = value.longValue();
            expected = 2223L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
