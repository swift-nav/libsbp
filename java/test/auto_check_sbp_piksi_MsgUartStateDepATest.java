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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/piksi/test_MsgUartStateDepA.yaml
// by generate.py. Do not modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.piksi.MsgUartStateDepa;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_piksi_MsgUartStateDepATest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_piksi_MsgUartStateDepATest.test1");
        byte[] payload =
                new byte[] {
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
                    (byte) 154,
                    (byte) 153,
                    (byte) 57,
                    (byte) 65,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 15,
                    (byte) 0,
                    (byte) 255,
                    (byte) 255,
                    (byte) 255,
                    (byte) 255,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 255,
                    (byte) 255,
                    (byte) 255,
                    (byte) 255,
                };
        SBPMessage sbp = new SBPMessage(0x4c3, 0x18, payload);
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
                    "'" + msg.uart_a.tx_buffer_level + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.uart_a.tx_throughput, 0.00000000000000000e+00, DELTA);
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
                    "'" + msg.uart_b.tx_buffer_level + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.uart_b.tx_throughput, 0.00000000000000000e+00, DELTA);
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
                    "'" + msg.uart_ftdi.rx_buffer_level + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.uart_ftdi.rx_throughput, 0.00000000000000000e+00, DELTA);
        value = msg.uart_ftdi.tx_buffer_level;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.uart_ftdi.tx_buffer_level + "' != '" + 15 + "'",
                    value.equals(BigInteger.valueOf(15L)));
        } else {
            value = value.longValue();
            expected = 15L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.uart_ftdi.tx_throughput, 1.16000003814697266e+01, DELTA);
    }

    @Test
    public void test2() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_piksi_MsgUartStateDepATest.test2");
        byte[] payload =
                new byte[] {
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
                    (byte) 2,
                    (byte) 43,
                    (byte) 135,
                    (byte) 61,
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
                    (byte) 255,
                    (byte) 255,
                    (byte) 255,
                    (byte) 255,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 255,
                    (byte) 255,
                    (byte) 255,
                    (byte) 255,
                };
        SBPMessage sbp = new SBPMessage(0x4c3, 0x18, payload);
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
                    "'" + msg.uart_a.tx_buffer_level + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.uart_a.tx_throughput, 0.00000000000000000e+00, DELTA);
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
                    "'" + msg.uart_b.tx_buffer_level + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.uart_b.tx_throughput, 0.00000000000000000e+00, DELTA);
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
                    "'" + msg.uart_ftdi.rx_buffer_level + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.uart_ftdi.rx_throughput, 0.00000000000000000e+00, DELTA);
        value = msg.uart_ftdi.tx_buffer_level;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.uart_ftdi.tx_buffer_level + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.uart_ftdi.tx_throughput, 6.59999996423721313e-02, DELTA);
    }

    @Test
    public void test3() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_piksi_MsgUartStateDepATest.test3");
        byte[] payload =
                new byte[] {
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
                    (byte) 4,
                    (byte) 86,
                    (byte) 14,
                    (byte) 62,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 10,
                    (byte) 0,
                    (byte) 255,
                    (byte) 255,
                    (byte) 255,
                    (byte) 255,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 255,
                    (byte) 255,
                    (byte) 255,
                    (byte) 255,
                };
        SBPMessage sbp = new SBPMessage(0x4c3, 0x18, payload);
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
                    "'" + msg.uart_a.tx_buffer_level + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.uart_a.tx_throughput, 0.00000000000000000e+00, DELTA);
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
                    "'" + msg.uart_b.tx_buffer_level + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.uart_b.tx_throughput, 0.00000000000000000e+00, DELTA);
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
                    "'" + msg.uart_ftdi.rx_buffer_level + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.uart_ftdi.rx_throughput, 0.00000000000000000e+00, DELTA);
        value = msg.uart_ftdi.tx_buffer_level;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.uart_ftdi.tx_buffer_level + "' != '" + 10 + "'",
                    value.equals(BigInteger.valueOf(10L)));
        } else {
            value = value.longValue();
            expected = 10L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.uart_ftdi.tx_throughput, 1.38999998569488525e-01, DELTA);
    }

    @Test
    public void test4() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_piksi_MsgUartStateDepATest.test4");
        byte[] payload =
                new byte[] {
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
                    (byte) 2,
                    (byte) 43,
                    (byte) 135,
                    (byte) 61,
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
                    (byte) 255,
                    (byte) 255,
                    (byte) 255,
                    (byte) 255,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 0,
                    (byte) 255,
                    (byte) 255,
                    (byte) 255,
                    (byte) 255,
                };
        SBPMessage sbp = new SBPMessage(0x4c3, 0x18, payload);
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
                    "'" + msg.uart_a.tx_buffer_level + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.uart_a.tx_throughput, 0.00000000000000000e+00, DELTA);
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
                    "'" + msg.uart_b.tx_buffer_level + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.uart_b.tx_throughput, 0.00000000000000000e+00, DELTA);
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
                    "'" + msg.uart_ftdi.rx_buffer_level + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.uart_ftdi.rx_throughput, 0.00000000000000000e+00, DELTA);
        value = msg.uart_ftdi.tx_buffer_level;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.uart_ftdi.tx_buffer_level + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.uart_ftdi.tx_throughput, 6.59999996423721313e-02, DELTA);
    }

    @Test
    public void test5() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_piksi_MsgUartStateDepATest.test5");
        byte[] payload =
                new byte[] {
                    (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 138, (byte) 75, (byte) 6,
                    (byte) 60, (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 0,
                    (byte) 80, (byte) 113, (byte) 201, (byte) 61, (byte) 0, (byte) 0, (byte) 0,
                    (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 2, (byte) 0,
                    (byte) 145, (byte) 237, (byte) 252, (byte) 62, (byte) 0, (byte) 0, (byte) 0,
                    (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 38, (byte) 0,
                    (byte) 255, (byte) 255, (byte) 255, (byte) 255, (byte) 0, (byte) 0, (byte) 0,
                    (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 255, (byte) 255,
                    (byte) 255, (byte) 255,
                };
        SBPMessage sbp = new SBPMessage(0x4c3, 0x18, payload);
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
        org.junit.Assert.assertEquals(msg.uart_a.rx_throughput, 8.19672085344791412e-03, DELTA);
        value = msg.uart_a.tx_buffer_level;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.uart_a.tx_buffer_level + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.uart_a.tx_throughput, 0.00000000000000000e+00, DELTA);
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
                    "'" + msg.uart_b.tx_buffer_level + "' != '" + 2 + "'",
                    value.equals(BigInteger.valueOf(2L)));
        } else {
            value = value.longValue();
            expected = 2L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.uart_b.tx_throughput, 9.83606576919555664e-02, DELTA);
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
                    "'" + msg.uart_ftdi.rx_buffer_level + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.uart_ftdi.rx_throughput, 0.00000000000000000e+00, DELTA);
        value = msg.uart_ftdi.tx_buffer_level;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.uart_ftdi.tx_buffer_level + "' != '" + 38 + "'",
                    value.equals(BigInteger.valueOf(38L)));
        } else {
            value = value.longValue();
            expected = 38L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.uart_ftdi.tx_throughput, 4.93999987840652466e-01, DELTA);
    }

    @Test
    public void test6() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_piksi_MsgUartStateDepATest.test6");
        byte[] payload =
                new byte[] {
                    (byte) 166, (byte) 155, (byte) 68, (byte) 60, (byte) 0, (byte) 0, (byte) 0,
                    (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 2, (byte) 0,
                    (byte) 166, (byte) 155, (byte) 68, (byte) 60, (byte) 0, (byte) 0, (byte) 0,
                    (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 2, (byte) 0,
                    (byte) 236, (byte) 81, (byte) 168, (byte) 63, (byte) 0, (byte) 0, (byte) 0,
                    (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 50, (byte) 0,
                    (byte) 255, (byte) 255, (byte) 255, (byte) 255, (byte) 0, (byte) 0, (byte) 0,
                    (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 255, (byte) 255,
                    (byte) 255, (byte) 255,
                };
        SBPMessage sbp = new SBPMessage(0x4c3, 0x18, payload);
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
                    "'" + msg.uart_a.tx_buffer_level + "' != '" + 2 + "'",
                    value.equals(BigInteger.valueOf(2L)));
        } else {
            value = value.longValue();
            expected = 2L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.uart_a.tx_throughput, 1.20000001043081284e-02, DELTA);
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
                    "'" + msg.uart_b.tx_buffer_level + "' != '" + 2 + "'",
                    value.equals(BigInteger.valueOf(2L)));
        } else {
            value = value.longValue();
            expected = 2L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.uart_b.tx_throughput, 1.20000001043081284e-02, DELTA);
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
                    "'" + msg.uart_ftdi.rx_buffer_level + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.uart_ftdi.rx_throughput, 0.00000000000000000e+00, DELTA);
        value = msg.uart_ftdi.tx_buffer_level;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.uart_ftdi.tx_buffer_level + "' != '" + 50 + "'",
                    value.equals(BigInteger.valueOf(50L)));
        } else {
            value = value.longValue();
            expected = 50L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.uart_ftdi.tx_throughput, 1.31500005722045898e+00, DELTA);
    }
}
