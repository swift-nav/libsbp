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
// spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrCodePhaseBiasesBounds.yaml by generate.py. Do not
// modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.ssr.MsgSsrCodePhaseBiasesBounds;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_ssr_MsgSsrCodePhaseBiasesBoundsTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_ssr_MsgSsrCodePhaseBiasesBoundsTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 180, (byte) 0, (byte) 0, (byte) 0, (byte) 3, (byte) 0, (byte) 1,
                    (byte) 2, (byte) 1, (byte) 14, (byte) 15, (byte) 1, (byte) 3, (byte) 0,
                    (byte) 3, (byte) 39, (byte) 1, (byte) 39, (byte) 1, (byte) 1, (byte) 3,
                    (byte) 39, (byte) 1, (byte) 39, (byte) 1, (byte) 1, (byte) 1, (byte) 39,
                    (byte) 1, (byte) 39, (byte) 1,
                };
        SBPMessage sbp = new SBPMessage(0x0042, 0x05EC, payload);
        MsgSsrCodePhaseBiasesBounds msg = new MsgSsrCodePhaseBiasesBounds(sbp);
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
                    "'" + msg.header.sol_id + "' != '" + 14 + "'",
                    value.equals(BigInteger.valueOf(14L)));
        } else {
            value = value.longValue();
            expected = 14L;
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
                    "'" + msg.header.update_interval + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.n_sats_signals;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.n_sats_signals + "' != '" + 3 + "'",
                    value.equals(BigInteger.valueOf(3L)));
        } else {
            value = value.longValue();
            expected = 3L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.satellites_signals[0].code_bias_bound_mu;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.satellites_signals[0].code_bias_bound_mu + "' != '" + 39 + "'",
                    value.equals(BigInteger.valueOf(39L)));
        } else {
            value = value.longValue();
            expected = 39L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.satellites_signals[0].code_bias_bound_sig;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.satellites_signals[0].code_bias_bound_sig + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.satellites_signals[0].phase_bias_bound_mu;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.satellites_signals[0].phase_bias_bound_mu + "' != '" + 39 + "'",
                    value.equals(BigInteger.valueOf(39L)));
        } else {
            value = value.longValue();
            expected = 39L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.satellites_signals[0].phase_bias_bound_sig;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.satellites_signals[0].phase_bias_bound_sig + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.satellites_signals[0].sat_id;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.satellites_signals[0].sat_id + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.satellites_signals[0].signal_id;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.satellites_signals[0].signal_id + "' != '" + 3 + "'",
                    value.equals(BigInteger.valueOf(3L)));
        } else {
            value = value.longValue();
            expected = 3L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.satellites_signals[1].code_bias_bound_mu;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.satellites_signals[1].code_bias_bound_mu + "' != '" + 39 + "'",
                    value.equals(BigInteger.valueOf(39L)));
        } else {
            value = value.longValue();
            expected = 39L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.satellites_signals[1].code_bias_bound_sig;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.satellites_signals[1].code_bias_bound_sig + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.satellites_signals[1].phase_bias_bound_mu;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.satellites_signals[1].phase_bias_bound_mu + "' != '" + 39 + "'",
                    value.equals(BigInteger.valueOf(39L)));
        } else {
            value = value.longValue();
            expected = 39L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.satellites_signals[1].phase_bias_bound_sig;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.satellites_signals[1].phase_bias_bound_sig + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.satellites_signals[1].sat_id;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.satellites_signals[1].sat_id + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.satellites_signals[1].signal_id;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.satellites_signals[1].signal_id + "' != '" + 3 + "'",
                    value.equals(BigInteger.valueOf(3L)));
        } else {
            value = value.longValue();
            expected = 3L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.satellites_signals[2].code_bias_bound_mu;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.satellites_signals[2].code_bias_bound_mu + "' != '" + 39 + "'",
                    value.equals(BigInteger.valueOf(39L)));
        } else {
            value = value.longValue();
            expected = 39L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.satellites_signals[2].code_bias_bound_sig;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.satellites_signals[2].code_bias_bound_sig + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.satellites_signals[2].phase_bias_bound_mu;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.satellites_signals[2].phase_bias_bound_mu + "' != '" + 39 + "'",
                    value.equals(BigInteger.valueOf(39L)));
        } else {
            value = value.longValue();
            expected = 39L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.satellites_signals[2].phase_bias_bound_sig;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.satellites_signals[2].phase_bias_bound_sig + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.satellites_signals[2].sat_id;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.satellites_signals[2].sat_id + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.satellites_signals[2].signal_id;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.satellites_signals[2].signal_id + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
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
