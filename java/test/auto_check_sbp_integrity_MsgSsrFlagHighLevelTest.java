/* Copyright (C) 2015-2022 Swift Navigation Inc.
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

// This file was auto-generated from
// spec/tests/yaml/swiftnav/sbp/integrity/test_MsgSsrFlagHighLevel.yaml by generate.py. Do not
// modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.integrity.MsgSsrFlagHighLevel;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_integrity_MsgSsrFlagHighLevelTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_integrity_MsgSsrFlagHighLevelTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 180,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 3,
                    (byte) 0,
                    (byte) 104,
                    (byte) 1,
                    (byte) 0,
                    (byte) 0,
                    (byte) 6,
                    (byte) 0,
                    (byte) 10,
                    (byte) 20,
                    (byte) 0,
                    (byte) 30,
                    (byte) 0,
                    (byte) 40,
                    (byte) 1,
                    (byte) 2,
                    (byte) 3,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 4,
                    (byte) 5,
                    (byte) 6,
                    (byte) 7,
                };
        SBPMessage sbp = new SBPMessage(0x0042, 0x0BB9, payload);
        MsgSsrFlagHighLevel msg = new MsgSsrFlagHighLevel(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.chain_id;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.chain_id + "' != '" + 40 + "'",
                    value.equals(BigInteger.valueOf(40L)));
        } else {
            value = value.longValue();
            expected = 40L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.corr_time.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.corr_time.tow + "' != '" + 360 + "'",
                    value.equals(BigInteger.valueOf(360L)));
        } else {
            value = value.longValue();
            expected = 360L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.corr_time.wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.corr_time.wn + "' != '" + 6 + "'",
                    value.equals(BigInteger.valueOf(6L)));
        } else {
            value = value.longValue();
            expected = 6L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs_time.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs_time.tow + "' != '" + 180 + "'",
                    value.equals(BigInteger.valueOf(180L)));
        } else {
            value = value.longValue();
            expected = 180L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs_time.wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs_time.wn + "' != '" + 3 + "'",
                    value.equals(BigInteger.valueOf(3L)));
        } else {
            value = value.longValue();
            expected = 3L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.reserved[0] + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.reserved[1] + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.reserved[2] + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.reserved[3] + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[4];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.reserved[4] + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reserved[5];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.reserved[5] + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.ssr_sol_id;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.ssr_sol_id + "' != '" + 10 + "'",
                    value.equals(BigInteger.valueOf(10L)));
        } else {
            value = value.longValue();
            expected = 10L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tile_id;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tile_id + "' != '" + 30 + "'", value.equals(BigInteger.valueOf(30L)));
        } else {
            value = value.longValue();
            expected = 30L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tile_set_id;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tile_set_id + "' != '" + 20 + "'",
                    value.equals(BigInteger.valueOf(20L)));
        } else {
            value = value.longValue();
            expected = 20L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.use_bds_sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.use_bds_sat + "' != '" + 3 + "'",
                    value.equals(BigInteger.valueOf(3L)));
        } else {
            value = value.longValue();
            expected = 3L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.use_gal_sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.use_gal_sat + "' != '" + 2 + "'",
                    value.equals(BigInteger.valueOf(2L)));
        } else {
            value = value.longValue();
            expected = 2L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.use_gps_sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.use_gps_sat + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.use_iono_grid_point_sat_los;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.use_iono_grid_point_sat_los + "' != '" + 7 + "'",
                    value.equals(BigInteger.valueOf(7L)));
        } else {
            value = value.longValue();
            expected = 7L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.use_iono_grid_points;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.use_iono_grid_points + "' != '" + 5 + "'",
                    value.equals(BigInteger.valueOf(5L)));
        } else {
            value = value.longValue();
            expected = 5L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.use_iono_tile_sat_los;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.use_iono_tile_sat_los + "' != '" + 6 + "'",
                    value.equals(BigInteger.valueOf(6L)));
        } else {
            value = value.longValue();
            expected = 6L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.use_tropo_grid_points;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.use_tropo_grid_points + "' != '" + 4 + "'",
                    value.equals(BigInteger.valueOf(4L)));
        } else {
            value = value.longValue();
            expected = 4L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }
}
