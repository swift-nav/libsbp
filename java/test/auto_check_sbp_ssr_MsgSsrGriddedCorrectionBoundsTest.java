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
// spec/tests/yaml/swiftnav/sbp/ssr/test_MsgSsrGriddedCorrectionBounds.yaml by generate.py. Do not
// modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.ssr.MsgSsrGriddedCorrectionBounds;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_ssr_MsgSsrGriddedCorrectionBoundsTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format(
                    "%n%s%n", "auto_check_sbp_ssr_MsgSsrGriddedCorrectionBoundsTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 180, (byte) 0, (byte) 0, (byte) 0, (byte) 3, (byte) 0, (byte) 1,
                    (byte) 1, (byte) 10, (byte) 0, (byte) 15, (byte) 1, (byte) 0, (byte) 10,
                    (byte) 0, (byte) 39, (byte) 232, (byte) 3, (byte) 244, (byte) 1, (byte) 100,
                    (byte) 200, (byte) 150, (byte) 100, (byte) 150, (byte) 100, (byte) 2, (byte) 5,
                    (byte) 10, (byte) 16, (byte) 0, (byte) 17, (byte) 18, (byte) 19, (byte) 20,
                    (byte) 21, (byte) 6, (byte) 10, (byte) 22, (byte) 0, (byte) 23, (byte) 24,
                    (byte) 25, (byte) 26, (byte) 27,
                };
        SBPMessage sbp = new SBPMessage(0x0042, 0x05FE, payload);
        MsgSsrGriddedCorrectionBounds msg = new MsgSsrGriddedCorrectionBounds(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.grid_point_id;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.grid_point_id + "' != '" + 1000 + "'",
                    value.equals(BigInteger.valueOf(1000L)));
        } else {
            value = value.longValue();
            expected = 1000L;
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
                    "'" + msg.header.seq_num + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.header.sol_id;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.header.sol_id + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
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
                    "'" + msg.header.update_interval + "' != '" + 10 + "'",
                    value.equals(BigInteger.valueOf(10L)));
        } else {
            value = value.longValue();
            expected = 10L;
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
        value = msg.ssr_iod_atmo;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.ssr_iod_atmo + "' != '" + 15 + "'",
                    value.equals(BigInteger.valueOf(15L)));
        } else {
            value = value.longValue();
            expected = 15L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[0].stec_bound_mu;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_sat_list[0].stec_bound_mu + "' != '" + 18 + "'",
                    value.equals(BigInteger.valueOf(18L)));
        } else {
            value = value.longValue();
            expected = 18L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[0].stec_bound_mu_dot;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_sat_list[0].stec_bound_mu_dot + "' != '" + 20 + "'",
                    value.equals(BigInteger.valueOf(20L)));
        } else {
            value = value.longValue();
            expected = 20L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[0].stec_bound_sig;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_sat_list[0].stec_bound_sig + "' != '" + 19 + "'",
                    value.equals(BigInteger.valueOf(19L)));
        } else {
            value = value.longValue();
            expected = 19L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[0].stec_bound_sig_dot;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_sat_list[0].stec_bound_sig_dot + "' != '" + 21 + "'",
                    value.equals(BigInteger.valueOf(21L)));
        } else {
            value = value.longValue();
            expected = 21L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[0].stec_residual.residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_sat_list[0].stec_residual.residual + "' != '" + 16 + "'",
                    value.equals(BigInteger.valueOf(16L)));
        } else {
            value = value.longValue();
            expected = 16L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[0].stec_residual.stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_sat_list[0].stec_residual.stddev + "' != '" + 17 + "'",
                    value.equals(BigInteger.valueOf(17L)));
        } else {
            value = value.longValue();
            expected = 17L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[0].stec_residual.sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'"
                            + msg.stec_sat_list[0].stec_residual.sv_id.constellation
                            + "' != '"
                            + 10
                            + "'",
                    value.equals(BigInteger.valueOf(10L)));
        } else {
            value = value.longValue();
            expected = 10L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[0].stec_residual.sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_sat_list[0].stec_residual.sv_id.satId + "' != '" + 5 + "'",
                    value.equals(BigInteger.valueOf(5L)));
        } else {
            value = value.longValue();
            expected = 5L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[1].stec_bound_mu;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_sat_list[1].stec_bound_mu + "' != '" + 24 + "'",
                    value.equals(BigInteger.valueOf(24L)));
        } else {
            value = value.longValue();
            expected = 24L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[1].stec_bound_mu_dot;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_sat_list[1].stec_bound_mu_dot + "' != '" + 26 + "'",
                    value.equals(BigInteger.valueOf(26L)));
        } else {
            value = value.longValue();
            expected = 26L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[1].stec_bound_sig;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_sat_list[1].stec_bound_sig + "' != '" + 25 + "'",
                    value.equals(BigInteger.valueOf(25L)));
        } else {
            value = value.longValue();
            expected = 25L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[1].stec_bound_sig_dot;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_sat_list[1].stec_bound_sig_dot + "' != '" + 27 + "'",
                    value.equals(BigInteger.valueOf(27L)));
        } else {
            value = value.longValue();
            expected = 27L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[1].stec_residual.residual;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_sat_list[1].stec_residual.residual + "' != '" + 22 + "'",
                    value.equals(BigInteger.valueOf(22L)));
        } else {
            value = value.longValue();
            expected = 22L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[1].stec_residual.stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_sat_list[1].stec_residual.stddev + "' != '" + 23 + "'",
                    value.equals(BigInteger.valueOf(23L)));
        } else {
            value = value.longValue();
            expected = 23L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[1].stec_residual.sv_id.constellation;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'"
                            + msg.stec_sat_list[1].stec_residual.sv_id.constellation
                            + "' != '"
                            + 10
                            + "'",
                    value.equals(BigInteger.valueOf(10L)));
        } else {
            value = value.longValue();
            expected = 10L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stec_sat_list[1].stec_residual.sv_id.satId;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.stec_sat_list[1].stec_residual.sv_id.satId + "' != '" + 6 + "'",
                    value.equals(BigInteger.valueOf(6L)));
        } else {
            value = value.longValue();
            expected = 6L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tile_id;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tile_id + "' != '" + 10 + "'", value.equals(BigInteger.valueOf(10L)));
        } else {
            value = value.longValue();
            expected = 10L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tile_set_id;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tile_set_id + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tropo_delay_correction.hydro;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tropo_delay_correction.hydro + "' != '" + 500 + "'",
                    value.equals(BigInteger.valueOf(500L)));
        } else {
            value = value.longValue();
            expected = 500L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tropo_delay_correction.stddev;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tropo_delay_correction.stddev + "' != '" + 200 + "'",
                    value.equals(BigInteger.valueOf(200L)));
        } else {
            value = value.longValue();
            expected = 200L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tropo_delay_correction.wet;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tropo_delay_correction.wet + "' != '" + 100 + "'",
                    value.equals(BigInteger.valueOf(100L)));
        } else {
            value = value.longValue();
            expected = 100L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tropo_qi;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tropo_qi + "' != '" + 39 + "'",
                    value.equals(BigInteger.valueOf(39L)));
        } else {
            value = value.longValue();
            expected = 39L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tropo_v_hydro_bound_mu;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tropo_v_hydro_bound_mu + "' != '" + 150 + "'",
                    value.equals(BigInteger.valueOf(150L)));
        } else {
            value = value.longValue();
            expected = 150L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tropo_v_hydro_bound_sig;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tropo_v_hydro_bound_sig + "' != '" + 100 + "'",
                    value.equals(BigInteger.valueOf(100L)));
        } else {
            value = value.longValue();
            expected = 100L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tropo_v_wet_bound_mu;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tropo_v_wet_bound_mu + "' != '" + 150 + "'",
                    value.equals(BigInteger.valueOf(150L)));
        } else {
            value = value.longValue();
            expected = 150L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.tropo_v_wet_bound_sig;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.tropo_v_wet_bound_sig + "' != '" + 100 + "'",
                    value.equals(BigInteger.valueOf(100L)));
        } else {
            value = value.longValue();
            expected = 100L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }
}
