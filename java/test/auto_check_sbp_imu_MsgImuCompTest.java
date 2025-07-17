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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/imu/test_MsgImuComp.yaml by generate.py. Do not modify by hand!

import java.math.BigInteger;

import org.junit.Test;

import org.json.JSONObject;

import com.swiftnav.sbp.SBPMessage;

import com.swiftnav.sbp.imu.MsgImuComp;


public class auto_check_sbp_imu_MsgImuCompTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_imu_MsgImuCompTest.test1");
        byte[] payload = new byte[] {(byte)26,(byte)1,(byte)0,(byte)192,(byte)0,(byte)0,(byte)0,(byte)0,(byte)206,(byte)0,(byte)96,(byte)0,(byte)0,(byte)0,(byte)223,(byte)255,(byte)255,(byte)255,(byte)44,(byte)16,(byte)0,(byte)0,(byte)60,(byte)0,(byte)0,(byte)0,(byte)208,(byte)254,(byte)255,(byte)255,(byte)238,(byte)255,(byte)255,(byte)255, };
        SBPMessage sbp = new SBPMessage( 0x1234, 0x905, payload );
        MsgImuComp msg = new MsgImuComp( sbp );
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.acc_comp_x;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.acc_comp_x + "' != '" + 96 + "'", value.equals(BigInteger.valueOf( 96L ) ) );
        } else {
            value = value.longValue();
            expected = 96L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acc_comp_y;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.acc_comp_y + "' != '" + -33 + "'", value.equals(BigInteger.valueOf( -33L ) ) );
        } else {
            value = value.longValue();
            expected = -33L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acc_comp_z;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.acc_comp_z + "' != '" + 4140 + "'", value.equals(BigInteger.valueOf( 4140L ) ) );
        } else {
            value = value.longValue();
            expected = 4140L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.flags + "' != '" + 206 + "'", value.equals(BigInteger.valueOf( 206L ) ) );
        } else {
            value = value.longValue();
            expected = 206L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.gyr_comp_x;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.gyr_comp_x + "' != '" + 60 + "'", value.equals(BigInteger.valueOf( 60L ) ) );
        } else {
            value = value.longValue();
            expected = 60L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.gyr_comp_y;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.gyr_comp_y + "' != '" + -304 + "'", value.equals(BigInteger.valueOf( -304L ) ) );
        } else {
            value = value.longValue();
            expected = -304L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.gyr_comp_z;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.gyr_comp_z + "' != '" + -18 + "'", value.equals(BigInteger.valueOf( -18L ) ) );
        } else {
            value = value.longValue();
            expected = -18L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.time;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.time + "' != '" + 3221225754L + "'", value.equals( new BigInteger( "3221225754" ) ) );
        } else {
            value = value.longValue();
            expected = 3221225754L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
