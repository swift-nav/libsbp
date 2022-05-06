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
// spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrOrbitClockBoundsDegradation.yaml by generate.py. Do
// not modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.ssr.MsgSsrOrbitClockBoundsDegradation;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_ssr_MsgSsrOrbitClockBoundsDegradationTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format(
                    "%n%s%n", "auto_check_sbp_ssr_MsgSsrOrbitClockBoundsDegradationTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 180,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 3,
                    (byte) 0,
                    (byte) 1,
                    (byte) 2,
                    (byte) 3,
                    (byte) 48,
                    (byte) 15,
                    (byte) 1,
                    (byte) 10,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 200,
                    (byte) 199,
                    (byte) 198,
                    (byte) 197,
                    (byte) 196,
                    (byte) 195,
                    (byte) 194,
                    (byte) 193,
                };
        SBPMessage sbp = new SBPMessage(0x0042, 0x05DF, payload);
        MsgSsrOrbitClockBoundsDegradation msg = new MsgSsrOrbitClockBoundsDegradation(sbp);
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
        value = msg.orbit_clock_bounds_degradation.clock_bound_mu_dot;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'"
                            + msg.orbit_clock_bounds_degradation.clock_bound_mu_dot
                            + "' != '"
                            + 194
                            + "'",
                    value.equals(BigInteger.valueOf(194L)));
        } else {
            value = value.longValue();
            expected = 194L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.orbit_clock_bounds_degradation.clock_bound_sig_dot;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'"
                            + msg.orbit_clock_bounds_degradation.clock_bound_sig_dot
                            + "' != '"
                            + 193
                            + "'",
                    value.equals(BigInteger.valueOf(193L)));
        } else {
            value = value.longValue();
            expected = 193L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.orbit_clock_bounds_degradation.orb_along_bound_mu_dot;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'"
                            + msg.orbit_clock_bounds_degradation.orb_along_bound_mu_dot
                            + "' != '"
                            + 199
                            + "'",
                    value.equals(BigInteger.valueOf(199L)));
        } else {
            value = value.longValue();
            expected = 199L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.orbit_clock_bounds_degradation.orb_along_bound_sig_dot;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'"
                            + msg.orbit_clock_bounds_degradation.orb_along_bound_sig_dot
                            + "' != '"
                            + 196
                            + "'",
                    value.equals(BigInteger.valueOf(196L)));
        } else {
            value = value.longValue();
            expected = 196L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.orbit_clock_bounds_degradation.orb_cross_bound_mu_dot;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'"
                            + msg.orbit_clock_bounds_degradation.orb_cross_bound_mu_dot
                            + "' != '"
                            + 198
                            + "'",
                    value.equals(BigInteger.valueOf(198L)));
        } else {
            value = value.longValue();
            expected = 198L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.orbit_clock_bounds_degradation.orb_cross_bound_sig_dot;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'"
                            + msg.orbit_clock_bounds_degradation.orb_cross_bound_sig_dot
                            + "' != '"
                            + 195
                            + "'",
                    value.equals(BigInteger.valueOf(195L)));
        } else {
            value = value.longValue();
            expected = 195L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.orbit_clock_bounds_degradation.orb_radial_bound_mu_dot;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'"
                            + msg.orbit_clock_bounds_degradation.orb_radial_bound_mu_dot
                            + "' != '"
                            + 200
                            + "'",
                    value.equals(BigInteger.valueOf(200L)));
        } else {
            value = value.longValue();
            expected = 200L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.orbit_clock_bounds_degradation.orb_radial_bound_sig_dot;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'"
                            + msg.orbit_clock_bounds_degradation.orb_radial_bound_sig_dot
                            + "' != '"
                            + 197
                            + "'",
                    value.equals(BigInteger.valueOf(197L)));
        } else {
            value = value.longValue();
            expected = 197L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sat_bitmask;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sat_bitmask + "' != '" + 10 + "'",
                    value.equals(BigInteger.valueOf(10L)));
        } else {
            value = value.longValue();
            expected = 10L;
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
