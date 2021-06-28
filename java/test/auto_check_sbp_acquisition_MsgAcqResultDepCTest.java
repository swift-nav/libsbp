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
// spec/tests/yaml/swiftnav/sbp/acquisition/test_MsgAcqResultDepC.yaml by generate.py. Do not modify
// by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.acquisition.MsgAcqResultDepC;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_acquisition_MsgAcqResultDepCTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_acquisition_MsgAcqResultDepCTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 72, (byte) 9, (byte) 34, (byte) 66, (byte) 155, (byte) 152, (byte) 228,
                    (byte) 67, (byte) 28, (byte) 34, (byte) 221, (byte) 68, (byte) 10, (byte) 0,
                    (byte) 0, (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0xc28, 0x1f, payload);
        MsgAcqResultDepC msg = new MsgAcqResultDepC(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        org.junit.Assert.assertEquals(msg.cf, 1.76906591796875000e+03, DELTA);
        org.junit.Assert.assertEquals(msg.cn0, 4.05090637207031250e+01, DELTA);
        org.junit.Assert.assertEquals(msg.cp, 4.57192230224609375e+02, DELTA);
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
                    "'" + msg.sid.sat + "' != '" + 10 + "'", value.equals(BigInteger.valueOf(10L)));
        } else {
            value = value.longValue();
            expected = 10L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test2() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_acquisition_MsgAcqResultDepCTest.test2");
        byte[] payload =
                new byte[] {
                    (byte) 132, (byte) 250, (byte) 45, (byte) 66, (byte) 207, (byte) 93, (byte) 88,
                    (byte) 68, (byte) 68, (byte) 185, (byte) 252, (byte) 195, (byte) 6, (byte) 0,
                    (byte) 0, (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0xc28, 0x1f, payload);
        MsgAcqResultDepC msg = new MsgAcqResultDepC(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        org.junit.Assert.assertEquals(msg.cf, -5.05447387695312500e+02, DELTA);
        org.junit.Assert.assertEquals(msg.cn0, 4.34946441650390625e+01, DELTA);
        org.junit.Assert.assertEquals(msg.cp, 8.65465759277343750e+02, DELTA);
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
                    "'" + msg.sid.sat + "' != '" + 6 + "'", value.equals(BigInteger.valueOf(6L)));
        } else {
            value = value.longValue();
            expected = 6L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test3() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_acquisition_MsgAcqResultDepCTest.test3");
        byte[] payload =
                new byte[] {
                    (byte) 163, (byte) 223, (byte) 24, (byte) 66, (byte) 64, (byte) 91, (byte) 102,
                    (byte) 67, (byte) 202, (byte) 243, (byte) 157, (byte) 196, (byte) 13, (byte) 0,
                    (byte) 0, (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0xc28, 0x1f, payload);
        MsgAcqResultDepC msg = new MsgAcqResultDepC(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        org.junit.Assert.assertEquals(msg.cf, -1.26361840820312500e+03, DELTA);
        org.junit.Assert.assertEquals(msg.cn0, 3.82183952331542969e+01, DELTA);
        org.junit.Assert.assertEquals(msg.cp, 2.30356445312500000e+02, DELTA);
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
                    "'" + msg.sid.sat + "' != '" + 13 + "'", value.equals(BigInteger.valueOf(13L)));
        } else {
            value = value.longValue();
            expected = 13L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test4() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_acquisition_MsgAcqResultDepCTest.test4");
        byte[] payload =
                new byte[] {
                    (byte) 129, (byte) 65, (byte) 21, (byte) 66, (byte) 224, (byte) 214, (byte) 124,
                    (byte) 67, (byte) 243, (byte) 138, (byte) 61, (byte) 69, (byte) 1, (byte) 0,
                    (byte) 0, (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0xc28, 0x1f, payload);
        MsgAcqResultDepC msg = new MsgAcqResultDepC(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        org.junit.Assert.assertEquals(msg.cf, 3.03268432617187500e+03, DELTA);
        org.junit.Assert.assertEquals(msg.cn0, 3.73139686584472656e+01, DELTA);
        org.junit.Assert.assertEquals(msg.cp, 2.52839355468750000e+02, DELTA);
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
                    "'" + msg.sid.sat + "' != '" + 1 + "'", value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test5() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_acquisition_MsgAcqResultDepCTest.test5");
        byte[] payload =
                new byte[] {
                    (byte) 126, (byte) 35, (byte) 62, (byte) 66, (byte) 226, (byte) 37, (byte) 102,
                    (byte) 68, (byte) 202, (byte) 243, (byte) 29, (byte) 69, (byte) 27, (byte) 0,
                    (byte) 0, (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0xc28, 0x1f, payload);
        MsgAcqResultDepC msg = new MsgAcqResultDepC(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        org.junit.Assert.assertEquals(msg.cf, 2.52723681640625000e+03, DELTA);
        org.junit.Assert.assertEquals(msg.cn0, 4.75346603393554688e+01, DELTA);
        org.junit.Assert.assertEquals(msg.cp, 9.20591918945312500e+02, DELTA);
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
                    "'" + msg.sid.sat + "' != '" + 27 + "'", value.equals(BigInteger.valueOf(27L)));
        } else {
            value = value.longValue();
            expected = 27L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }
}
