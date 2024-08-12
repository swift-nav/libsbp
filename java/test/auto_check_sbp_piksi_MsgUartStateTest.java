/* Copyright (C) 2015-2022 Swift Navigation Inc.
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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/piksi/test_MsgUartState.yaml by
// generate.py. Do not modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.piksi.MsgUartState;
import com.swiftnav.sbp.piksi.MsgUartStateDepa;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_piksi_MsgUartStateTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_piksi_MsgUartStateTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 154,
                    (byte) 169,
                    (byte) 242,
                    (byte) 69,
                    (byte) 102,
                    (byte) 166,
                    (byte) 231,
                    (byte) 68,
                    (byte) 89,
                    (byte) 98,
                    (byte) 79,
                    (byte) 184,
                    (byte) 138,
                    (byte) 244,
                    (byte) 154,
                    (byte) 73,
                    (byte) 201,
                    (byte) 69,
                    (byte) 154,
                    (byte) 65,
                    (byte) 211,
                    (byte) 69,
                    (byte) 201,
                    (byte) 16,
                    (byte) 103,
                    (byte) 249,
                    (byte) 143,
                    (byte) 161,
                    (byte) 154,
                    (byte) 17,
                    (byte) 186,
                    (byte) 69,
                    (byte) 51,
                    (byte) 211,
                    (byte) 7,
                    (byte) 69,
                    (byte) 215,
                    (byte) 149,
                    (byte) 253,
                    (byte) 25,
                    (byte) 218,
                    (byte) 24,
                    (byte) 29,
                    (byte) 195,
                    (byte) 16,
                    (byte) 19,
                    (byte) 159,
                    (byte) 142,
                    (byte) 71,
                    (byte) 17,
                    (byte) 10,
                    (byte) 113,
                    (byte) 137,
                    (byte) 219,
                    (byte) 135,
                    (byte) 18,
                    (byte) 182,
                    (byte) 21,
                    (byte) 38,
                    (byte) 190,
                    (byte) 59,
                    (byte) 196,
                    (byte) 169,
                    (byte) 155,
                    (byte) 107,
                    (byte) 111,
                    (byte) 253,
                    (byte) 168,
                    (byte) 244,
                    (byte) 158,
                    (byte) 112,
                    (byte) 19,
                    (byte) 251,
                    (byte) 131,
                };
        SBPMessage sbp = new SBPMessage(0xe0c8, 0x1d, payload);
        MsgUartState msg = new MsgUartState(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.latency.avg;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.latency.avg + "' != '" + 319865629 + "'",
                    value.equals(BigInteger.valueOf(319865629L)));
        } else {
            value = value.longValue();
            expected = 319865629L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.latency.current;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.latency.current + "' != '" + 364253831 + "'",
                    value.equals(BigInteger.valueOf(364253831L)));
        } else {
            value = value.longValue();
            expected = 364253831L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.latency.lmax;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.latency.lmax + "' != '" + -611749622 + "'",
                    value.equals(BigInteger.valueOf(-611749622L)));
        } else {
            value = value.longValue();
            expected = -611749622L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.latency.lmin;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.latency.lmin + "' != '" + 289902239 + "'",
                    value.equals(BigInteger.valueOf(289902239L)));
        } else {
            value = value.longValue();
            expected = 289902239L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs_period.avg;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs_period.avg + "' != '" + -1002717658 + "'",
                    value.equals(BigInteger.valueOf(-1002717658L)));
        } else {
            value = value.longValue();
            expected = -1002717658L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs_period.current;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs_period.current + "' != '" + -2080697488 + "'",
                    value.equals(BigInteger.valueOf(-2080697488L)));
        } else {
            value = value.longValue();
            expected = -2080697488L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs_period.pmax;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs_period.pmax + "' != '" + -1628133123 + "'",
                    value.equals(BigInteger.valueOf(-1628133123L)));
        } else {
            value = value.longValue();
            expected = -1628133123L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.obs_period.pmin;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.obs_period.pmin + "' != '" + 1869323177 + "'",
                    value.equals(BigInteger.valueOf(1869323177L)));
        } else {
            value = value.longValue();
            expected = 1869323177L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.uart_a.crc_error_count;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.uart_a.crc_error_count + "' != '" + 25177 + "'",
                    value.equals(BigInteger.valueOf(25177L)));
        } else {
            value = value.longValue();
            expected = 25177L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.uart_a.io_error_count;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.uart_a.io_error_count + "' != '" + 47183 + "'",
                    value.equals(BigInteger.valueOf(47183L)));
        } else {
            value = value.longValue();
            expected = 47183L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.uart_a.rx_buffer_level;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.uart_a.rx_buffer_level + "' != '" + 244 + "'",
                    value.equals(BigInteger.valueOf(244L)));
        } else {
            value = value.longValue();
            expected = 244L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.uart_a.rx_throughput, 1.85319995117187500e+03, DELTA);
        value = msg.uart_a.tx_buffer_level;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.uart_a.tx_buffer_level + "' != '" + 138 + "'",
                    value.equals(BigInteger.valueOf(138L)));
        } else {
            value = value.longValue();
            expected = 138L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.uart_a.tx_throughput, 7.76520019531250000e+03, DELTA);
        value = msg.uart_b.crc_error_count;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.uart_b.crc_error_count + "' != '" + 4297 + "'",
                    value.equals(BigInteger.valueOf(4297L)));
        } else {
            value = value.longValue();
            expected = 4297L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.uart_b.io_error_count;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.uart_b.io_error_count + "' != '" + 63847 + "'",
                    value.equals(BigInteger.valueOf(63847L)));
        } else {
            value = value.longValue();
            expected = 63847L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.uart_b.rx_buffer_level;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.uart_b.rx_buffer_level + "' != '" + 161 + "'",
                    value.equals(BigInteger.valueOf(161L)));
        } else {
            value = value.longValue();
            expected = 161L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.uart_b.rx_throughput, 6.76020019531250000e+03, DELTA);
        value = msg.uart_b.tx_buffer_level;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.uart_b.tx_buffer_level + "' != '" + 143 + "'",
                    value.equals(BigInteger.valueOf(143L)));
        } else {
            value = value.longValue();
            expected = 143L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.uart_b.tx_throughput, 6.44120019531250000e+03, DELTA);
        value = msg.uart_ftdi.crc_error_count;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.uart_ftdi.crc_error_count + "' != '" + 38359 + "'",
                    value.equals(BigInteger.valueOf(38359L)));
        } else {
            value = value.longValue();
            expected = 38359L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.uart_ftdi.io_error_count;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.uart_ftdi.io_error_count + "' != '" + 6653 + "'",
                    value.equals(BigInteger.valueOf(6653L)));
        } else {
            value = value.longValue();
            expected = 6653L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.uart_ftdi.rx_buffer_level;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.uart_ftdi.rx_buffer_level + "' != '" + 24 + "'",
                    value.equals(BigInteger.valueOf(24L)));
        } else {
            value = value.longValue();
            expected = 24L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.uart_ftdi.rx_throughput, 2.17319995117187500e+03, DELTA);
        value = msg.uart_ftdi.tx_buffer_level;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.uart_ftdi.tx_buffer_level + "' != '" + 218 + "'",
                    value.equals(BigInteger.valueOf(218L)));
        } else {
            value = value.longValue();
            expected = 218L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.uart_ftdi.tx_throughput, 5.95420019531250000e+03, DELTA);

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }

    @Test
    public void test2() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_piksi_MsgUartStateTest.test2");
        byte[] payload =
                new byte[] {
                    (byte) 26, (byte) 191, (byte) 93, (byte) 63, (byte) 0, (byte) 0, (byte) 0,
                    (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 24, (byte) 0,
                    (byte) 123, (byte) 50, (byte) 62, (byte) 64, (byte) 0, (byte) 0, (byte) 0,
                    (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 40, (byte) 0,
                    (byte) 54, (byte) 7, (byte) 162, (byte) 64, (byte) 177, (byte) 57, (byte) 16,
                    (byte) 61, (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 81, (byte) 1,
                    (byte) 255, (byte) 255, (byte) 255, (byte) 255, (byte) 0, (byte) 0, (byte) 0,
                    (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 255, (byte) 255,
                    (byte) 255, (byte) 255,
                };
        SBPMessage sbp = new SBPMessage(0xd7f6, 0x18, payload);
        MsgUartStateDepa msg = new MsgUartStateDepa(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.latency.avg;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.latency.avg + "' != '" + -1 + "'",
                    value.equals(BigInteger.valueOf(-1L)));
        } else {
            value = value.longValue();
            expected = -1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.latency.current;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.latency.current + "' != '" + -1 + "'",
                    value.equals(BigInteger.valueOf(-1L)));
        } else {
            value = value.longValue();
            expected = -1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.latency.lmax;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.latency.lmax + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.latency.lmin;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.latency.lmin + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.uart_a.crc_error_count;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.uart_a.crc_error_count + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.uart_a.io_error_count;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.uart_a.io_error_count + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.uart_a.rx_buffer_level;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.uart_a.rx_buffer_level + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.uart_a.rx_throughput, 0.00000000000000000e+00, DELTA);
        value = msg.uart_a.tx_buffer_level;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.uart_a.tx_buffer_level + "' != '" + 24 + "'",
                    value.equals(BigInteger.valueOf(24L)));
        } else {
            value = value.longValue();
            expected = 24L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.uart_a.tx_throughput, 8.66197228431701660e-01, DELTA);
        value = msg.uart_b.crc_error_count;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.uart_b.crc_error_count + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.uart_b.io_error_count;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.uart_b.io_error_count + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.uart_b.rx_buffer_level;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.uart_b.rx_buffer_level + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.uart_b.rx_throughput, 0.00000000000000000e+00, DELTA);
        value = msg.uart_b.tx_buffer_level;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.uart_b.tx_buffer_level + "' != '" + 40 + "'",
                    value.equals(BigInteger.valueOf(40L)));
        } else {
            value = value.longValue();
            expected = 40L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.uart_b.tx_throughput, 2.97183108329772949e+00, DELTA);
        value = msg.uart_ftdi.crc_error_count;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.uart_ftdi.crc_error_count + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.uart_ftdi.io_error_count;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.uart_ftdi.io_error_count + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.uart_ftdi.rx_buffer_level;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.uart_ftdi.rx_buffer_level + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.uart_ftdi.rx_throughput, 3.52112688124179840e-02, DELTA);
        value = msg.uart_ftdi.tx_buffer_level;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.uart_ftdi.tx_buffer_level + "' != '" + 81 + "'",
                    value.equals(BigInteger.valueOf(81L)));
        } else {
            value = value.longValue();
            expected = 81L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.uart_ftdi.tx_throughput, 5.06338024139404297e+00, DELTA);

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }

    @Test
    public void test3() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_piksi_MsgUartStateTest.test3");
        byte[] payload =
                new byte[] {
                    (byte) 237, (byte) 232, (byte) 95, (byte) 63, (byte) 0, (byte) 0, (byte) 0,
                    (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 24, (byte) 0,
                    (byte) 198, (byte) 186, (byte) 63, (byte) 64, (byte) 0, (byte) 0, (byte) 0,
                    (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 40, (byte) 0,
                    (byte) 214, (byte) 72, (byte) 217, (byte) 64, (byte) 29, (byte) 72, (byte) 180,
                    (byte) 62, (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 85, (byte) 1,
                    (byte) 255, (byte) 255, (byte) 255, (byte) 255, (byte) 0, (byte) 0, (byte) 0,
                    (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 255, (byte) 255,
                    (byte) 255, (byte) 255,
                };
        SBPMessage sbp = new SBPMessage(0xd7f6, 0x18, payload);
        MsgUartStateDepa msg = new MsgUartStateDepa(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.latency.avg;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.latency.avg + "' != '" + -1 + "'",
                    value.equals(BigInteger.valueOf(-1L)));
        } else {
            value = value.longValue();
            expected = -1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.latency.current;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.latency.current + "' != '" + -1 + "'",
                    value.equals(BigInteger.valueOf(-1L)));
        } else {
            value = value.longValue();
            expected = -1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.latency.lmax;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.latency.lmax + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.latency.lmin;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.latency.lmin + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.uart_a.crc_error_count;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.uart_a.crc_error_count + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.uart_a.io_error_count;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.uart_a.io_error_count + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.uart_a.rx_buffer_level;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.uart_a.rx_buffer_level + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.uart_a.rx_throughput, 0.00000000000000000e+00, DELTA);
        value = msg.uart_a.tx_buffer_level;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.uart_a.tx_buffer_level + "' != '" + 24 + "'",
                    value.equals(BigInteger.valueOf(24L)));
        } else {
            value = value.longValue();
            expected = 24L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.uart_a.tx_throughput, 8.74647915363311768e-01, DELTA);
        value = msg.uart_b.crc_error_count;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.uart_b.crc_error_count + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.uart_b.io_error_count;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.uart_b.io_error_count + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.uart_b.rx_buffer_level;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.uart_b.rx_buffer_level + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.uart_b.rx_throughput, 0.00000000000000000e+00, DELTA);
        value = msg.uart_b.tx_buffer_level;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.uart_b.tx_buffer_level + "' != '" + 40 + "'",
                    value.equals(BigInteger.valueOf(40L)));
        } else {
            value = value.longValue();
            expected = 40L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.uart_b.tx_throughput, 2.99577474594116211e+00, DELTA);
        value = msg.uart_ftdi.crc_error_count;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.uart_ftdi.crc_error_count + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.uart_ftdi.io_error_count;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.uart_ftdi.io_error_count + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.uart_ftdi.rx_buffer_level;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.uart_ftdi.rx_buffer_level + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.uart_ftdi.rx_throughput, 3.52112680673599243e-01, DELTA);
        value = msg.uart_ftdi.tx_buffer_level;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.uart_ftdi.tx_buffer_level + "' != '" + 85 + "'",
                    value.equals(BigInteger.valueOf(85L)));
        } else {
            value = value.longValue();
            expected = 85L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.uart_ftdi.tx_throughput, 6.79014110565185547e+00, DELTA);

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
