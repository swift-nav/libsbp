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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/system/test_MsgStatusJournal.yaml
// by generate.py. Do not modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.system.MsgStatusJournal;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_system_MsgStatusJournalTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_system_MsgStatusJournalTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 1, (byte) 0, (byte) 1, (byte) 4, (byte) 100, (byte) 0, (byte) 0,
                    (byte) 0, (byte) 7, (byte) 3, (byte) 146, (byte) 16, (byte) 0, (byte) 0,
                    (byte) 6, (byte) 0, (byte) 1, (byte) 13, (byte) 186, (byte) 19, (byte) 0,
                    (byte) 0, (byte) 6, (byte) 0, (byte) 1, (byte) 14, (byte) 184, (byte) 34,
                    (byte) 0, (byte) 0, (byte) 6, (byte) 0, (byte) 1, (byte) 15,
                };
        SBPMessage sbp = new SBPMessage(0x88D3, 0xFFFD, payload);
        MsgStatusJournal msg = new MsgStatusJournal(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.journal[0].component;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.journal[0].component + "' != '" + 6 + "'",
                    value.equals(BigInteger.valueOf(6L)));
        } else {
            value = value.longValue();
            expected = 6L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.journal[0].generic;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.journal[0].generic + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.journal[0].specific;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.journal[0].specific + "' != '" + 13 + "'",
                    value.equals(BigInteger.valueOf(13L)));
        } else {
            value = value.longValue();
            expected = 13L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.journal[0].uptime;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.journal[0].uptime + "' != '" + 4242 + "'",
                    value.equals(BigInteger.valueOf(4242L)));
        } else {
            value = value.longValue();
            expected = 4242L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.journal[1].component;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.journal[1].component + "' != '" + 6 + "'",
                    value.equals(BigInteger.valueOf(6L)));
        } else {
            value = value.longValue();
            expected = 6L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.journal[1].generic;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.journal[1].generic + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.journal[1].specific;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.journal[1].specific + "' != '" + 14 + "'",
                    value.equals(BigInteger.valueOf(14L)));
        } else {
            value = value.longValue();
            expected = 14L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.journal[1].uptime;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.journal[1].uptime + "' != '" + 5050 + "'",
                    value.equals(BigInteger.valueOf(5050L)));
        } else {
            value = value.longValue();
            expected = 5050L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.journal[2].component;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.journal[2].component + "' != '" + 6 + "'",
                    value.equals(BigInteger.valueOf(6L)));
        } else {
            value = value.longValue();
            expected = 6L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.journal[2].generic;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.journal[2].generic + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.journal[2].specific;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.journal[2].specific + "' != '" + 15 + "'",
                    value.equals(BigInteger.valueOf(15L)));
        } else {
            value = value.longValue();
            expected = 15L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.journal[2].uptime;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.journal[2].uptime + "' != '" + 8888 + "'",
                    value.equals(BigInteger.valueOf(8888L)));
        } else {
            value = value.longValue();
            expected = 8888L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.n_packets;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.n_packets + "' != '" + 3 + "'", value.equals(BigInteger.valueOf(3L)));
        } else {
            value = value.longValue();
            expected = 3L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.n_status_reports;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.n_status_reports + "' != '" + 100 + "'",
                    value.equals(BigInteger.valueOf(100L)));
        } else {
            value = value.longValue();
            expected = 100L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.packet_index;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.packet_index + "' != '" + 7 + "'",
                    value.equals(BigInteger.valueOf(7L)));
        } else {
            value = value.longValue();
            expected = 7L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reporting_system;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.reporting_system + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sbp_version;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sbp_version + "' != '" + 1025 + "'",
                    value.equals(BigInteger.valueOf(1025L)));
        } else {
            value = value.longValue();
            expected = 1025L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test2() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_system_MsgStatusJournalTest.test2");
        byte[] payload =
                new byte[] {
                    (byte) 1, (byte) 0, (byte) 1, (byte) 4, (byte) 100, (byte) 0, (byte) 0,
                    (byte) 0, (byte) 7, (byte) 1, (byte) 146, (byte) 16, (byte) 0, (byte) 0,
                    (byte) 6, (byte) 0, (byte) 1, (byte) 13,
                };
        SBPMessage sbp = new SBPMessage(0x88D3, 0xFFFD, payload);
        MsgStatusJournal msg = new MsgStatusJournal(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.journal[0].component;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.journal[0].component + "' != '" + 6 + "'",
                    value.equals(BigInteger.valueOf(6L)));
        } else {
            value = value.longValue();
            expected = 6L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.journal[0].generic;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.journal[0].generic + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.journal[0].specific;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.journal[0].specific + "' != '" + 13 + "'",
                    value.equals(BigInteger.valueOf(13L)));
        } else {
            value = value.longValue();
            expected = 13L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.journal[0].uptime;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.journal[0].uptime + "' != '" + 4242 + "'",
                    value.equals(BigInteger.valueOf(4242L)));
        } else {
            value = value.longValue();
            expected = 4242L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.n_packets;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.n_packets + "' != '" + 1 + "'", value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.n_status_reports;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.n_status_reports + "' != '" + 100 + "'",
                    value.equals(BigInteger.valueOf(100L)));
        } else {
            value = value.longValue();
            expected = 100L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.packet_index;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.packet_index + "' != '" + 7 + "'",
                    value.equals(BigInteger.valueOf(7L)));
        } else {
            value = value.longValue();
            expected = 7L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.reporting_system;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.reporting_system + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sbp_version;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sbp_version + "' != '" + 1025 + "'",
                    value.equals(BigInteger.valueOf(1025L)));
        } else {
            value = value.longValue();
            expected = 1025L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }
}
