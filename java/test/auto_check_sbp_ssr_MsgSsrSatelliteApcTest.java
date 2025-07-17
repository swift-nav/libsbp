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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrSatelliteApc.yaml by generate.py. Do not modify by hand!

import java.math.BigInteger;

import org.junit.Test;

import org.json.JSONObject;

import com.swiftnav.sbp.SBPMessage;

import com.swiftnav.sbp.ssr.MsgSsrSatelliteApc;


public class auto_check_sbp_ssr_MsgSsrSatelliteApcTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_ssr_MsgSsrSatelliteApcTest.test1");
        byte[] payload = new byte[] {(byte)127,(byte)58,(byte)9,(byte)0,(byte)174,(byte)8,(byte)1,(byte)2,(byte)3,(byte)2,(byte)0,(byte)4,(byte)61,(byte)0,(byte)1,(byte)0,(byte)255,(byte)255,(byte)217,(byte)2,(byte)11,(byte)10,(byte)8,(byte)5,(byte)1,(byte)252,(byte)248,(byte)246,(byte)246,(byte)246,(byte)249,(byte)252,(byte)0,(byte)6,(byte)12,(byte)22,(byte)30,(byte)41,(byte)41,(byte)41,(byte)41, };
        SBPMessage sbp = new SBPMessage( 0x0, 0x605, payload );
        MsgSsrSatelliteApc msg = new MsgSsrSatelliteApc( sbp );
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.apc[0].pco[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.apc[0].pco[0] + "' != '" + 1 + "'", value.equals(BigInteger.valueOf( 1L ) ) );
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[0].pco[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.apc[0].pco[1] + "' != '" + -1 + "'", value.equals(BigInteger.valueOf( -1L ) ) );
        } else {
            value = value.longValue();
            expected = -1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[0].pco[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.apc[0].pco[2] + "' != '" + 729 + "'", value.equals(BigInteger.valueOf( 729L ) ) );
        } else {
            value = value.longValue();
            expected = 729L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[0].pcv[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.apc[0].pcv[0] + "' != '" + 11 + "'", value.equals(BigInteger.valueOf( 11L ) ) );
        } else {
            value = value.longValue();
            expected = 11L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[0].pcv[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.apc[0].pcv[1] + "' != '" + 10 + "'", value.equals(BigInteger.valueOf( 10L ) ) );
        } else {
            value = value.longValue();
            expected = 10L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[0].pcv[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.apc[0].pcv[2] + "' != '" + 8 + "'", value.equals(BigInteger.valueOf( 8L ) ) );
        } else {
            value = value.longValue();
            expected = 8L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[0].pcv[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.apc[0].pcv[3] + "' != '" + 5 + "'", value.equals(BigInteger.valueOf( 5L ) ) );
        } else {
            value = value.longValue();
            expected = 5L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[0].pcv[4];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.apc[0].pcv[4] + "' != '" + 1 + "'", value.equals(BigInteger.valueOf( 1L ) ) );
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[0].pcv[5];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.apc[0].pcv[5] + "' != '" + -4 + "'", value.equals(BigInteger.valueOf( -4L ) ) );
        } else {
            value = value.longValue();
            expected = -4L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[0].pcv[6];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.apc[0].pcv[6] + "' != '" + -8 + "'", value.equals(BigInteger.valueOf( -8L ) ) );
        } else {
            value = value.longValue();
            expected = -8L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[0].pcv[7];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.apc[0].pcv[7] + "' != '" + -10 + "'", value.equals(BigInteger.valueOf( -10L ) ) );
        } else {
            value = value.longValue();
            expected = -10L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[0].pcv[8];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.apc[0].pcv[8] + "' != '" + -10 + "'", value.equals(BigInteger.valueOf( -10L ) ) );
        } else {
            value = value.longValue();
            expected = -10L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[0].pcv[9];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.apc[0].pcv[9] + "' != '" + -10 + "'", value.equals(BigInteger.valueOf( -10L ) ) );
        } else {
            value = value.longValue();
            expected = -10L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[0].pcv[10];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.apc[0].pcv[10] + "' != '" + -7 + "'", value.equals(BigInteger.valueOf( -7L ) ) );
        } else {
            value = value.longValue();
            expected = -7L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[0].pcv[11];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.apc[0].pcv[11] + "' != '" + -4 + "'", value.equals(BigInteger.valueOf( -4L ) ) );
        } else {
            value = value.longValue();
            expected = -4L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[0].pcv[12];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.apc[0].pcv[12] + "' != '" + 0 + "'", value.equals(BigInteger.valueOf( 0L ) ) );
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[0].pcv[13];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.apc[0].pcv[13] + "' != '" + 6 + "'", value.equals(BigInteger.valueOf( 6L ) ) );
        } else {
            value = value.longValue();
            expected = 6L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[0].pcv[14];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.apc[0].pcv[14] + "' != '" + 12 + "'", value.equals(BigInteger.valueOf( 12L ) ) );
        } else {
            value = value.longValue();
            expected = 12L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[0].pcv[15];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.apc[0].pcv[15] + "' != '" + 22 + "'", value.equals(BigInteger.valueOf( 22L ) ) );
        } else {
            value = value.longValue();
            expected = 22L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[0].pcv[16];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.apc[0].pcv[16] + "' != '" + 30 + "'", value.equals(BigInteger.valueOf( 30L ) ) );
        } else {
            value = value.longValue();
            expected = 30L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[0].pcv[17];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.apc[0].pcv[17] + "' != '" + 41 + "'", value.equals(BigInteger.valueOf( 41L ) ) );
        } else {
            value = value.longValue();
            expected = 41L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[0].pcv[18];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.apc[0].pcv[18] + "' != '" + 41 + "'", value.equals(BigInteger.valueOf( 41L ) ) );
        } else {
            value = value.longValue();
            expected = 41L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[0].pcv[19];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.apc[0].pcv[19] + "' != '" + 41 + "'", value.equals(BigInteger.valueOf( 41L ) ) );
        } else {
            value = value.longValue();
            expected = 41L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[0].pcv[20];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.apc[0].pcv[20] + "' != '" + 41 + "'", value.equals(BigInteger.valueOf( 41L ) ) );
        } else {
            value = value.longValue();
            expected = 41L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[0].sat_info;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.apc[0].sat_info + "' != '" + 4 + "'", value.equals(BigInteger.valueOf( 4L ) ) );
        } else {
            value = value.longValue();
            expected = 4L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[0].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.apc[0].sid.code + "' != '" + 0 + "'", value.equals(BigInteger.valueOf( 0L ) ) );
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[0].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.apc[0].sid.sat + "' != '" + 2 + "'", value.equals(BigInteger.valueOf( 2L ) ) );
        } else {
            value = value.longValue();
            expected = 2L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.apc[0].svn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.apc[0].svn + "' != '" + 61 + "'", value.equals(BigInteger.valueOf( 61L ) ) );
        } else {
            value = value.longValue();
            expected = 61L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.iod_ssr;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.iod_ssr + "' != '" + 3 + "'", value.equals(BigInteger.valueOf( 3L ) ) );
        } else {
            value = value.longValue();
            expected = 3L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sol_id;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.sol_id + "' != '" + 2 + "'", value.equals(BigInteger.valueOf( 2L ) ) );
        } else {
            value = value.longValue();
            expected = 2L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.time.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.time.tow + "' != '" + 604799 + "'", value.equals(BigInteger.valueOf( 604799L ) ) );
        } else {
            value = value.longValue();
            expected = 604799L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.time.wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.time.wn + "' != '" + 2222 + "'", value.equals(BigInteger.valueOf( 2222L ) ) );
        } else {
            value = value.longValue();
            expected = 2222L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.update_interval;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.update_interval + "' != '" + 1 + "'", value.equals(BigInteger.valueOf( 1L ) ) );
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
