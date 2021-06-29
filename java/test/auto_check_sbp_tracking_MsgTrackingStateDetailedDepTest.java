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

// This file was auto-generated from
// spec/tests/yaml/swiftnav/sbp/tracking/test_MsgTrackingStateDetailedDep.yaml by generate.py. Do
// not modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.tracking.MsgTrackingStateDetailedDep;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_tracking_MsgTrackingStateDetailedDepTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format(
                    "%n%s%n", "auto_check_sbp_tracking_MsgTrackingStateDetailedDepTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 163,
                    (byte) 151,
                    (byte) 112,
                    (byte) 215,
                    (byte) 1,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 39,
                    (byte) 5,
                    (byte) 0,
                    (byte) 0,
                    (byte) 169,
                    (byte) 177,
                    (byte) 208,
                    (byte) 54,
                    (byte) 15,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 85,
                    (byte) 61,
                    (byte) 0,
                    (byte) 0,
                    (byte) 39,
                    (byte) 0,
                    (byte) 1,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 40,
                    (byte) 0,
                    (byte) 108,
                    (byte) 1,
                    (byte) 0,
                    (byte) 11,
                    (byte) 0,
                    (byte) 0,
                    (byte) 9,
                };
        SBPMessage sbp = new SBPMessage(0x673b, 0x11, payload);
        MsgTrackingStateDetailedDep msg = new MsgTrackingStateDetailedDep(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.L.f + "' != '" + 169 + "'", value.equals(BigInteger.valueOf(169L)));
        } else {
            value = value.longValue();
            expected = 169L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.L.i + "' != '" + 1319 + "'", value.equals(BigInteger.valueOf(1319L)));
        } else {
            value = value.longValue();
            expected = 1319L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.P + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.P_std;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.P_std + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acceleration;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.acceleration + "' != '" + 108 + "'",
                    value.equals(BigInteger.valueOf(108L)));
        } else {
            value = value.longValue();
            expected = 108L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.clock_drift;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.clock_drift + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.clock_offset;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.clock_offset + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.cn0 + "' != '" + 177 + "'", value.equals(BigInteger.valueOf(177L)));
        } else {
            value = value.longValue();
            expected = 177L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.corr_spacing;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.corr_spacing + "' != '" + 40 + "'",
                    value.equals(BigInteger.valueOf(40L)));
        } else {
            value = value.longValue();
            expected = 40L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.doppler;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.doppler + "' != '" + 15701 + "'",
                    value.equals(BigInteger.valueOf(15701L)));
        } else {
            value = value.longValue();
            expected = 15701L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.doppler_std;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.doppler_std + "' != '" + 39 + "'",
                    value.equals(BigInteger.valueOf(39L)));
        } else {
            value = value.longValue();
            expected = 39L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.lock + "' != '" + 14032 + "'",
                    value.equals(BigInteger.valueOf(14032L)));
        } else {
            value = value.longValue();
            expected = 14032L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.misc_flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.misc_flags + "' != '" + 9 + "'",
                    value.equals(BigInteger.valueOf(9L)));
        } else {
            value = value.longValue();
            expected = 9L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.nav_flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.nav_flags + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.pset_flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.pset_flags + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.recv_time;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.recv_time + "' != '" + 7909447587L + "'",
                    value.equals(new BigInteger("7909447587")));
        } else {
            value = value.longValue();
            expected = 7909447587L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sid.code + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sid.sat + "' != '" + 15 + "'", value.equals(BigInteger.valueOf(15L)));
        } else {
            value = value.longValue();
            expected = 15L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sync_flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sync_flags + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tot.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tot.tow + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tot.wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tot.wn + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tow_flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tow_flags + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.track_flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.track_flags + "' != '" + 11 + "'",
                    value.equals(BigInteger.valueOf(11L)));
        } else {
            value = value.longValue();
            expected = 11L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.uptime;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.uptime + "' != '" + 1 + "'", value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test2() throws Throwable {
        if (debug)
            System.out.format(
                    "%n%s%n", "auto_check_sbp_tracking_MsgTrackingStateDetailedDepTest.test2");
        byte[] payload =
                new byte[] {
                    (byte) 97,
                    (byte) 251,
                    (byte) 61,
                    (byte) 245,
                    (byte) 1,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 18,
                    (byte) 7,
                    (byte) 0,
                    (byte) 0,
                    (byte) 14,
                    (byte) 175,
                    (byte) 208,
                    (byte) 54,
                    (byte) 15,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 51,
                    (byte) 61,
                    (byte) 0,
                    (byte) 0,
                    (byte) 30,
                    (byte) 0,
                    (byte) 1,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 40,
                    (byte) 0,
                    (byte) 224,
                    (byte) 1,
                    (byte) 0,
                    (byte) 11,
                    (byte) 0,
                    (byte) 0,
                    (byte) 9,
                };
        SBPMessage sbp = new SBPMessage(0x673b, 0x11, payload);
        MsgTrackingStateDetailedDep msg = new MsgTrackingStateDetailedDep(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.L.f + "' != '" + 14 + "'", value.equals(BigInteger.valueOf(14L)));
        } else {
            value = value.longValue();
            expected = 14L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.L.i + "' != '" + 1810 + "'", value.equals(BigInteger.valueOf(1810L)));
        } else {
            value = value.longValue();
            expected = 1810L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.P + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.P_std;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.P_std + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acceleration;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.acceleration + "' != '" + -32 + "'",
                    value.equals(BigInteger.valueOf(-32L)));
        } else {
            value = value.longValue();
            expected = -32L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.clock_drift;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.clock_drift + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.clock_offset;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.clock_offset + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.cn0 + "' != '" + 175 + "'", value.equals(BigInteger.valueOf(175L)));
        } else {
            value = value.longValue();
            expected = 175L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.corr_spacing;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.corr_spacing + "' != '" + 40 + "'",
                    value.equals(BigInteger.valueOf(40L)));
        } else {
            value = value.longValue();
            expected = 40L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.doppler;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.doppler + "' != '" + 15667 + "'",
                    value.equals(BigInteger.valueOf(15667L)));
        } else {
            value = value.longValue();
            expected = 15667L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.doppler_std;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.doppler_std + "' != '" + 30 + "'",
                    value.equals(BigInteger.valueOf(30L)));
        } else {
            value = value.longValue();
            expected = 30L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.lock + "' != '" + 14032 + "'",
                    value.equals(BigInteger.valueOf(14032L)));
        } else {
            value = value.longValue();
            expected = 14032L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.misc_flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.misc_flags + "' != '" + 9 + "'",
                    value.equals(BigInteger.valueOf(9L)));
        } else {
            value = value.longValue();
            expected = 9L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.nav_flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.nav_flags + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.pset_flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.pset_flags + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.recv_time;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.recv_time + "' != '" + 8409447265L + "'",
                    value.equals(new BigInteger("8409447265")));
        } else {
            value = value.longValue();
            expected = 8409447265L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sid.code + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sid.sat + "' != '" + 15 + "'", value.equals(BigInteger.valueOf(15L)));
        } else {
            value = value.longValue();
            expected = 15L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sync_flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sync_flags + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tot.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tot.tow + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tot.wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tot.wn + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tow_flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tow_flags + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.track_flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.track_flags + "' != '" + 11 + "'",
                    value.equals(BigInteger.valueOf(11L)));
        } else {
            value = value.longValue();
            expected = 11L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.uptime;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.uptime + "' != '" + 1 + "'", value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test3() throws Throwable {
        if (debug)
            System.out.format(
                    "%n%s%n", "auto_check_sbp_tracking_MsgTrackingStateDetailedDepTest.test3");
        byte[] payload =
                new byte[] {
                    (byte) 139,
                    (byte) 218,
                    (byte) 236,
                    (byte) 18,
                    (byte) 2,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 250,
                    (byte) 8,
                    (byte) 0,
                    (byte) 0,
                    (byte) 8,
                    (byte) 179,
                    (byte) 208,
                    (byte) 54,
                    (byte) 15,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 67,
                    (byte) 61,
                    (byte) 0,
                    (byte) 0,
                    (byte) 22,
                    (byte) 0,
                    (byte) 2,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 40,
                    (byte) 0,
                    (byte) 27,
                    (byte) 1,
                    (byte) 0,
                    (byte) 11,
                    (byte) 0,
                    (byte) 2,
                    (byte) 9,
                };
        SBPMessage sbp = new SBPMessage(0x673b, 0x11, payload);
        MsgTrackingStateDetailedDep msg = new MsgTrackingStateDetailedDep(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.L.f + "' != '" + 8 + "'", value.equals(BigInteger.valueOf(8L)));
        } else {
            value = value.longValue();
            expected = 8L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.L.i + "' != '" + 2298 + "'", value.equals(BigInteger.valueOf(2298L)));
        } else {
            value = value.longValue();
            expected = 2298L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.P + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.P_std;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.P_std + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acceleration;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.acceleration + "' != '" + 27 + "'",
                    value.equals(BigInteger.valueOf(27L)));
        } else {
            value = value.longValue();
            expected = 27L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.clock_drift;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.clock_drift + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.clock_offset;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.clock_offset + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.cn0 + "' != '" + 179 + "'", value.equals(BigInteger.valueOf(179L)));
        } else {
            value = value.longValue();
            expected = 179L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.corr_spacing;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.corr_spacing + "' != '" + 40 + "'",
                    value.equals(BigInteger.valueOf(40L)));
        } else {
            value = value.longValue();
            expected = 40L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.doppler;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.doppler + "' != '" + 15683 + "'",
                    value.equals(BigInteger.valueOf(15683L)));
        } else {
            value = value.longValue();
            expected = 15683L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.doppler_std;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.doppler_std + "' != '" + 22 + "'",
                    value.equals(BigInteger.valueOf(22L)));
        } else {
            value = value.longValue();
            expected = 22L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.lock + "' != '" + 14032 + "'",
                    value.equals(BigInteger.valueOf(14032L)));
        } else {
            value = value.longValue();
            expected = 14032L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.misc_flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.misc_flags + "' != '" + 9 + "'",
                    value.equals(BigInteger.valueOf(9L)));
        } else {
            value = value.longValue();
            expected = 9L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.nav_flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.nav_flags + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.pset_flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.pset_flags + "' != '" + 2 + "'",
                    value.equals(BigInteger.valueOf(2L)));
        } else {
            value = value.longValue();
            expected = 2L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.recv_time;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.recv_time + "' != '" + 8907446923L + "'",
                    value.equals(new BigInteger("8907446923")));
        } else {
            value = value.longValue();
            expected = 8907446923L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sid.code + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sid.sat + "' != '" + 15 + "'", value.equals(BigInteger.valueOf(15L)));
        } else {
            value = value.longValue();
            expected = 15L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sync_flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sync_flags + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tot.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tot.tow + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tot.wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tot.wn + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tow_flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tow_flags + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.track_flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.track_flags + "' != '" + 11 + "'",
                    value.equals(BigInteger.valueOf(11L)));
        } else {
            value = value.longValue();
            expected = 11L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.uptime;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.uptime + "' != '" + 2 + "'", value.equals(BigInteger.valueOf(2L)));
        } else {
            value = value.longValue();
            expected = 2L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test4() throws Throwable {
        if (debug)
            System.out.format(
                    "%n%s%n", "auto_check_sbp_tracking_MsgTrackingStateDetailedDepTest.test4");
        byte[] payload =
                new byte[] {
                    (byte) 255,
                    (byte) 251,
                    (byte) 170,
                    (byte) 48,
                    (byte) 2,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 226,
                    (byte) 10,
                    (byte) 0,
                    (byte) 0,
                    (byte) 125,
                    (byte) 181,
                    (byte) 208,
                    (byte) 54,
                    (byte) 15,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 29,
                    (byte) 61,
                    (byte) 0,
                    (byte) 0,
                    (byte) 10,
                    (byte) 0,
                    (byte) 2,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 40,
                    (byte) 0,
                    (byte) 220,
                    (byte) 1,
                    (byte) 0,
                    (byte) 11,
                    (byte) 0,
                    (byte) 3,
                    (byte) 9,
                };
        SBPMessage sbp = new SBPMessage(0x673b, 0x11, payload);
        MsgTrackingStateDetailedDep msg = new MsgTrackingStateDetailedDep(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.L.f + "' != '" + 125 + "'", value.equals(BigInteger.valueOf(125L)));
        } else {
            value = value.longValue();
            expected = 125L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.L.i + "' != '" + 2786 + "'", value.equals(BigInteger.valueOf(2786L)));
        } else {
            value = value.longValue();
            expected = 2786L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.P + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.P_std;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.P_std + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acceleration;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.acceleration + "' != '" + -36 + "'",
                    value.equals(BigInteger.valueOf(-36L)));
        } else {
            value = value.longValue();
            expected = -36L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.clock_drift;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.clock_drift + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.clock_offset;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.clock_offset + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.cn0 + "' != '" + 181 + "'", value.equals(BigInteger.valueOf(181L)));
        } else {
            value = value.longValue();
            expected = 181L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.corr_spacing;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.corr_spacing + "' != '" + 40 + "'",
                    value.equals(BigInteger.valueOf(40L)));
        } else {
            value = value.longValue();
            expected = 40L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.doppler;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.doppler + "' != '" + 15645 + "'",
                    value.equals(BigInteger.valueOf(15645L)));
        } else {
            value = value.longValue();
            expected = 15645L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.doppler_std;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.doppler_std + "' != '" + 10 + "'",
                    value.equals(BigInteger.valueOf(10L)));
        } else {
            value = value.longValue();
            expected = 10L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.lock + "' != '" + 14032 + "'",
                    value.equals(BigInteger.valueOf(14032L)));
        } else {
            value = value.longValue();
            expected = 14032L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.misc_flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.misc_flags + "' != '" + 9 + "'",
                    value.equals(BigInteger.valueOf(9L)));
        } else {
            value = value.longValue();
            expected = 9L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.nav_flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.nav_flags + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.pset_flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.pset_flags + "' != '" + 3 + "'",
                    value.equals(BigInteger.valueOf(3L)));
        } else {
            value = value.longValue();
            expected = 3L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.recv_time;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.recv_time + "' != '" + 9406446591L + "'",
                    value.equals(new BigInteger("9406446591")));
        } else {
            value = value.longValue();
            expected = 9406446591L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sid.code + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sid.sat + "' != '" + 15 + "'", value.equals(BigInteger.valueOf(15L)));
        } else {
            value = value.longValue();
            expected = 15L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sync_flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sync_flags + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tot.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tot.tow + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tot.wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tot.wn + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tow_flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tow_flags + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.track_flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.track_flags + "' != '" + 11 + "'",
                    value.equals(BigInteger.valueOf(11L)));
        } else {
            value = value.longValue();
            expected = 11L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.uptime;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.uptime + "' != '" + 2 + "'", value.equals(BigInteger.valueOf(2L)));
        } else {
            value = value.longValue();
            expected = 2L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test5() throws Throwable {
        if (debug)
            System.out.format(
                    "%n%s%n", "auto_check_sbp_tracking_MsgTrackingStateDetailedDepTest.test5");
        byte[] payload =
                new byte[] {
                    (byte) 189,
                    (byte) 95,
                    (byte) 120,
                    (byte) 78,
                    (byte) 2,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 203,
                    (byte) 12,
                    (byte) 0,
                    (byte) 0,
                    (byte) 64,
                    (byte) 184,
                    (byte) 208,
                    (byte) 54,
                    (byte) 15,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 24,
                    (byte) 61,
                    (byte) 0,
                    (byte) 0,
                    (byte) 4,
                    (byte) 0,
                    (byte) 3,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 40,
                    (byte) 0,
                    (byte) 2,
                    (byte) 1,
                    (byte) 0,
                    (byte) 11,
                    (byte) 0,
                    (byte) 3,
                    (byte) 9,
                };
        SBPMessage sbp = new SBPMessage(0x673b, 0x11, payload);
        MsgTrackingStateDetailedDep msg = new MsgTrackingStateDetailedDep(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.L.f;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.L.f + "' != '" + 64 + "'", value.equals(BigInteger.valueOf(64L)));
        } else {
            value = value.longValue();
            expected = 64L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.L.i;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.L.i + "' != '" + 3275 + "'", value.equals(BigInteger.valueOf(3275L)));
        } else {
            value = value.longValue();
            expected = 3275L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.P;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.P + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.P_std;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.P_std + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acceleration;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.acceleration + "' != '" + 2 + "'",
                    value.equals(BigInteger.valueOf(2L)));
        } else {
            value = value.longValue();
            expected = 2L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.clock_drift;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.clock_drift + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.clock_offset;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.clock_offset + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.cn0 + "' != '" + 184 + "'", value.equals(BigInteger.valueOf(184L)));
        } else {
            value = value.longValue();
            expected = 184L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.corr_spacing;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.corr_spacing + "' != '" + 40 + "'",
                    value.equals(BigInteger.valueOf(40L)));
        } else {
            value = value.longValue();
            expected = 40L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.doppler;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.doppler + "' != '" + 15640 + "'",
                    value.equals(BigInteger.valueOf(15640L)));
        } else {
            value = value.longValue();
            expected = 15640L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.doppler_std;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.doppler_std + "' != '" + 4 + "'",
                    value.equals(BigInteger.valueOf(4L)));
        } else {
            value = value.longValue();
            expected = 4L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.lock;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.lock + "' != '" + 14032 + "'",
                    value.equals(BigInteger.valueOf(14032L)));
        } else {
            value = value.longValue();
            expected = 14032L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.misc_flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.misc_flags + "' != '" + 9 + "'",
                    value.equals(BigInteger.valueOf(9L)));
        } else {
            value = value.longValue();
            expected = 9L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.nav_flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.nav_flags + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.pset_flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.pset_flags + "' != '" + 3 + "'",
                    value.equals(BigInteger.valueOf(3L)));
        } else {
            value = value.longValue();
            expected = 3L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.recv_time;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.recv_time + "' != '" + 9906446269L + "'",
                    value.equals(new BigInteger("9906446269")));
        } else {
            value = value.longValue();
            expected = 9906446269L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sid.code + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sid.reserved + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sid.sat + "' != '" + 15 + "'", value.equals(BigInteger.valueOf(15L)));
        } else {
            value = value.longValue();
            expected = 15L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sync_flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sync_flags + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tot.tow;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tot.tow + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tot.wn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tot.wn + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tow_flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tow_flags + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.track_flags;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.track_flags + "' != '" + 11 + "'",
                    value.equals(BigInteger.valueOf(11L)));
        } else {
            value = value.longValue();
            expected = 11L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.uptime;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.uptime + "' != '" + 3 + "'", value.equals(BigInteger.valueOf(3L)));
        } else {
            value = value.longValue();
            expected = 3L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }
}
