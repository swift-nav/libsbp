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
// spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrOrbitClockBounds.yaml by generate.py. Do not modify
// by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.ssr.MsgSsrOrbitClockBounds;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_ssr_MsgSsrOrbitClockBoundsTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_ssr_MsgSsrOrbitClockBoundsTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 180, (byte) 0, (byte) 0, (byte) 0, (byte) 3, (byte) 0, (byte) 1,
                    (byte) 2, (byte) 3, (byte) 48, (byte) 15, (byte) 1, (byte) 2, (byte) 24,
                    (byte) 39, (byte) 38, (byte) 37, (byte) 1, (byte) 2, (byte) 3, (byte) 39,
                    (byte) 1, (byte) 3, (byte) 39, (byte) 38, (byte) 37, (byte) 1, (byte) 2,
                    (byte) 3, (byte) 39, (byte) 1,
                };
        SBPMessage sbp = new SBPMessage(0x0042, 0x05DE, payload);
        MsgSsrOrbitClockBounds msg = new MsgSsrOrbitClockBounds(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.const_id;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.const_id + "' != '" + 1 + "'", value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.header.num_msgs;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.header.num_msgs + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.header.seq_num;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.header.seq_num + "' != '" + 2 + "'",
                    value.equals(BigInteger.valueOf(2L)));
        } else {
            value = value.longValue();
            expected = 2L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.header.sol_id;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.header.sol_id + "' != '" + 48 + "'",
                    value.equals(BigInteger.valueOf(48L)));
        } else {
            value = value.longValue();
            expected = 48L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.header.time.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.header.time.tow + "' != '" + 180 + "'",
                    value.equals(BigInteger.valueOf(180L)));
        } else {
            value = value.longValue();
            expected = 180L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.header.time.wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.header.time.wn + "' != '" + 3 + "'",
                    value.equals(BigInteger.valueOf(3L)));
        } else {
            value = value.longValue();
            expected = 3L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.header.update_interval;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.header.update_interval + "' != '" + 3 + "'",
                    value.equals(BigInteger.valueOf(3L)));
        } else {
            value = value.longValue();
            expected = 3L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.n_sats;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.n_sats + "' != '" + 2 + "'", value.equals(BigInteger.valueOf(2L)));
        } else {
            value = value.longValue();
            expected = 2L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.orbit_clock_bounds[0].clock_bound_mu;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.orbit_clock_bounds[0].clock_bound_mu + "' != '" + 39 + "'",
                    value.equals(BigInteger.valueOf(39L)));
        } else {
            value = value.longValue();
            expected = 39L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.orbit_clock_bounds[0].clock_bound_sig;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.orbit_clock_bounds[0].clock_bound_sig + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.orbit_clock_bounds[0].orb_along_bound_mu;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.orbit_clock_bounds[0].orb_along_bound_mu + "' != '" + 38 + "'",
                    value.equals(BigInteger.valueOf(38L)));
        } else {
            value = value.longValue();
            expected = 38L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.orbit_clock_bounds[0].orb_along_bound_sig;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.orbit_clock_bounds[0].orb_along_bound_sig + "' != '" + 2 + "'",
                    value.equals(BigInteger.valueOf(2L)));
        } else {
            value = value.longValue();
            expected = 2L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.orbit_clock_bounds[0].orb_cross_bound_mu;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.orbit_clock_bounds[0].orb_cross_bound_mu + "' != '" + 37 + "'",
                    value.equals(BigInteger.valueOf(37L)));
        } else {
            value = value.longValue();
            expected = 37L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.orbit_clock_bounds[0].orb_cross_bound_sig;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.orbit_clock_bounds[0].orb_cross_bound_sig + "' != '" + 3 + "'",
                    value.equals(BigInteger.valueOf(3L)));
        } else {
            value = value.longValue();
            expected = 3L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.orbit_clock_bounds[0].orb_radial_bound_mu;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.orbit_clock_bounds[0].orb_radial_bound_mu + "' != '" + 39 + "'",
                    value.equals(BigInteger.valueOf(39L)));
        } else {
            value = value.longValue();
            expected = 39L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.orbit_clock_bounds[0].orb_radial_bound_sig;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.orbit_clock_bounds[0].orb_radial_bound_sig + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.orbit_clock_bounds[0].sat_id;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.orbit_clock_bounds[0].sat_id + "' != '" + 24 + "'",
                    value.equals(BigInteger.valueOf(24L)));
        } else {
            value = value.longValue();
            expected = 24L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.orbit_clock_bounds[1].clock_bound_mu;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.orbit_clock_bounds[1].clock_bound_mu + "' != '" + 39 + "'",
                    value.equals(BigInteger.valueOf(39L)));
        } else {
            value = value.longValue();
            expected = 39L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.orbit_clock_bounds[1].clock_bound_sig;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.orbit_clock_bounds[1].clock_bound_sig + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.orbit_clock_bounds[1].orb_along_bound_mu;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.orbit_clock_bounds[1].orb_along_bound_mu + "' != '" + 38 + "'",
                    value.equals(BigInteger.valueOf(38L)));
        } else {
            value = value.longValue();
            expected = 38L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.orbit_clock_bounds[1].orb_along_bound_sig;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.orbit_clock_bounds[1].orb_along_bound_sig + "' != '" + 2 + "'",
                    value.equals(BigInteger.valueOf(2L)));
        } else {
            value = value.longValue();
            expected = 2L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.orbit_clock_bounds[1].orb_cross_bound_mu;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.orbit_clock_bounds[1].orb_cross_bound_mu + "' != '" + 37 + "'",
                    value.equals(BigInteger.valueOf(37L)));
        } else {
            value = value.longValue();
            expected = 37L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.orbit_clock_bounds[1].orb_cross_bound_sig;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.orbit_clock_bounds[1].orb_cross_bound_sig + "' != '" + 3 + "'",
                    value.equals(BigInteger.valueOf(3L)));
        } else {
            value = value.longValue();
            expected = 3L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.orbit_clock_bounds[1].orb_radial_bound_mu;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.orbit_clock_bounds[1].orb_radial_bound_mu + "' != '" + 39 + "'",
                    value.equals(BigInteger.valueOf(39L)));
        } else {
            value = value.longValue();
            expected = 39L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.orbit_clock_bounds[1].orb_radial_bound_sig;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.orbit_clock_bounds[1].orb_radial_bound_sig + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.orbit_clock_bounds[1].sat_id;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.orbit_clock_bounds[1].sat_id + "' != '" + 3 + "'",
                    value.equals(BigInteger.valueOf(3L)));
        } else {
            value = value.longValue();
            expected = 3L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.ssr_iod;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.ssr_iod + "' != '" + 15 + "'", value.equals(BigInteger.valueOf(15L)));
        } else {
            value = value.longValue();
            expected = 15L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }
}
