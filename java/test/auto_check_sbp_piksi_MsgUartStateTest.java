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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/piksi/test_MsgUartState.yaml by
// generate.py. Do not modify by hand!


import com.swiftnav.sbp.SBPMessage;
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
    }

    @Test
    public void test2() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_piksi_MsgUartStateTest.test2");
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
    }
}
