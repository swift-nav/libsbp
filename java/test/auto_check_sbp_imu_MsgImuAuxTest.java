/* Copyright (C) 2015-2021 Swift Navigation Inc.
 * Contact: https://support.swiftnav.com
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */
package com.swiftnav.sbp.test;

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/imu/test_MsgImuAux.yaml by
// generate.py. Do not modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.imu.MsgImuAux;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_imu_MsgImuAuxTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_imu_MsgImuAuxTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 1, (byte) 244, (byte) 10, (byte) 66,
                };
        SBPMessage sbp = new SBPMessage(0x1234, 0x901, payload);
        MsgImuAux msg = new MsgImuAux(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.imu_conf;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.imu_conf + "' != '" + 66 + "'",
                    value.equals(BigInteger.valueOf(66L)));
        } else {
            value = value.longValue();
            expected = 66L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.imu_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.imu_type + "' != '" + 1 + "'", value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.temp;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.temp + "' != '" + 2804 + "'",
                    value.equals(BigInteger.valueOf(2804L)));
        } else {
            value = value.longValue();
            expected = 2804L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }
}
