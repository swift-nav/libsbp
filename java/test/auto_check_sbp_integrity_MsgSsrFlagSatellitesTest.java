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
// spec/tests/yaml/swiftnav/sbp/integrity/test_MsgSsrFlagSatellites.yaml by generate.py. Do not
// modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.integrity.MsgSsrFlagSatellites;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_integrity_MsgSsrFlagSatellitesTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_integrity_MsgSsrFlagSatellitesTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 180, (byte) 0, (byte) 0, (byte) 0, (byte) 3, (byte) 0, (byte) 1,
                    (byte) 2, (byte) 3, (byte) 4, (byte) 5, (byte) 3, (byte) 10, (byte) 11,
                    (byte) 12,
                };
        SBPMessage sbp = new SBPMessage(0x0042, 0x0BBD, payload);
        MsgSsrFlagSatellites msg = new MsgSsrFlagSatellites(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.chain_id;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.chain_id + "' != '" + 4 + "'", value.equals(BigInteger.valueOf(4L)));
        } else {
            value = value.longValue();
            expected = 4L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.const_id;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.const_id + "' != '" + 5 + "'", value.equals(BigInteger.valueOf(5L)));
        } else {
            value = value.longValue();
            expected = 5L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.faulty_sats[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.faulty_sats[0] + "' != '" + 10 + "'",
                    value.equals(BigInteger.valueOf(10L)));
        } else {
            value = value.longValue();
            expected = 10L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.faulty_sats[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.faulty_sats[1] + "' != '" + 11 + "'",
                    value.equals(BigInteger.valueOf(11L)));
        } else {
            value = value.longValue();
            expected = 11L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.faulty_sats[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.faulty_sats[2] + "' != '" + 12 + "'",
                    value.equals(BigInteger.valueOf(12L)));
        } else {
            value = value.longValue();
            expected = 12L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.n_faulty_sats;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.n_faulty_sats + "' != '" + 3 + "'",
                    value.equals(BigInteger.valueOf(3L)));
        } else {
            value = value.longValue();
            expected = 3L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.num_msgs;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.num_msgs + "' != '" + 1 + "'", value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
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
        value = msg.seq_num;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.seq_num + "' != '" + 2 + "'", value.equals(BigInteger.valueOf(2L)));
        } else {
            value = value.longValue();
            expected = 2L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.ssr_sol_id;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.ssr_sol_id + "' != '" + 3 + "'",
                    value.equals(BigInteger.valueOf(3L)));
        } else {
            value = value.longValue();
            expected = 3L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }
}
