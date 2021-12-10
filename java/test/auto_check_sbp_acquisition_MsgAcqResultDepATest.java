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
// spec/tests/yaml/swiftnav/sbp/acquisition/test_MsgAcqResultDepA.yaml by generate.py. Do not modify
// by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.acquisition.MsgAcqResultDepA;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_acquisition_MsgAcqResultDepATest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_acquisition_MsgAcqResultDepATest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 0,
                    (byte) 0,
                    (byte) 104,
                    (byte) 65,
                    (byte) 0,
                    (byte) 192,
                    (byte) 53,
                    (byte) 68,
                    (byte) 198,
                    (byte) 199,
                    (byte) 0,
                    (byte) 70,
                    (byte) 8,
                };
        SBPMessage sbp = new SBPMessage(0x4c3, 0x15, payload);
        MsgAcqResultDepA msg = new MsgAcqResultDepA(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        org.junit.Assert.assertEquals(msg.cf, 8.24194335937500000e+03, DELTA);
        org.junit.Assert.assertEquals(msg.cp, 7.27000000000000000e+02, DELTA);
        value = msg.prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.prn + "' != '" + 8 + "'", value.equals(BigInteger.valueOf(8L)));
        } else {
            value = value.longValue();
            expected = 8L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.snr, 1.45000000000000000e+01, DELTA);
    }

    @Test
    public void test2() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_acquisition_MsgAcqResultDepATest.test2");
        byte[] payload =
                new byte[] {
                    (byte) 205,
                    (byte) 204,
                    (byte) 116,
                    (byte) 65,
                    (byte) 0,
                    (byte) 192,
                    (byte) 179,
                    (byte) 67,
                    (byte) 33,
                    (byte) 81,
                    (byte) 59,
                    (byte) 68,
                    (byte) 9,
                };
        SBPMessage sbp = new SBPMessage(0x4c3, 0x15, payload);
        MsgAcqResultDepA msg = new MsgAcqResultDepA(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        org.junit.Assert.assertEquals(msg.cf, 7.49267639160156250e+02, DELTA);
        org.junit.Assert.assertEquals(msg.cp, 3.59500000000000000e+02, DELTA);
        value = msg.prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.prn + "' != '" + 9 + "'", value.equals(BigInteger.valueOf(9L)));
        } else {
            value = value.longValue();
            expected = 9L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.snr, 1.53000001907348633e+01, DELTA);
    }

    @Test
    public void test3() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_acquisition_MsgAcqResultDepATest.test3");
        byte[] payload =
                new byte[] {
                    (byte) 205,
                    (byte) 204,
                    (byte) 144,
                    (byte) 65,
                    (byte) 0,
                    (byte) 0,
                    (byte) 34,
                    (byte) 66,
                    (byte) 57,
                    (byte) 237,
                    (byte) 202,
                    (byte) 197,
                    (byte) 11,
                };
        SBPMessage sbp = new SBPMessage(0x4c3, 0x15, payload);
        MsgAcqResultDepA msg = new MsgAcqResultDepA(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        org.junit.Assert.assertEquals(msg.cf, -6.49365283203125000e+03, DELTA);
        org.junit.Assert.assertEquals(msg.cp, 4.05000000000000000e+01, DELTA);
        value = msg.prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.prn + "' != '" + 11 + "'", value.equals(BigInteger.valueOf(11L)));
        } else {
            value = value.longValue();
            expected = 11L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.snr, 1.81000003814697266e+01, DELTA);
    }

    @Test
    public void test4() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_acquisition_MsgAcqResultDepATest.test4");
        byte[] payload =
                new byte[] {
                    (byte) 205,
                    (byte) 204,
                    (byte) 116,
                    (byte) 65,
                    (byte) 0,
                    (byte) 32,
                    (byte) 9,
                    (byte) 68,
                    (byte) 129,
                    (byte) 193,
                    (byte) 121,
                    (byte) 196,
                    (byte) 12,
                };
        SBPMessage sbp = new SBPMessage(0x4c3, 0x15, payload);
        MsgAcqResultDepA msg = new MsgAcqResultDepA(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        org.junit.Assert.assertEquals(msg.cf, -9.99023498535156250e+02, DELTA);
        org.junit.Assert.assertEquals(msg.cp, 5.48500000000000000e+02, DELTA);
        value = msg.prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.prn + "' != '" + 12 + "'", value.equals(BigInteger.valueOf(12L)));
        } else {
            value = value.longValue();
            expected = 12L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.snr, 1.53000001907348633e+01, DELTA);
    }

    @Test
    public void test5() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_acquisition_MsgAcqResultDepATest.test5");
        byte[] payload =
                new byte[] {
                    (byte) 205,
                    (byte) 204,
                    (byte) 116,
                    (byte) 65,
                    (byte) 0,
                    (byte) 32,
                    (byte) 67,
                    (byte) 68,
                    (byte) 228,
                    (byte) 74,
                    (byte) 148,
                    (byte) 69,
                    (byte) 14,
                };
        SBPMessage sbp = new SBPMessage(0x4c3, 0x15, payload);
        MsgAcqResultDepA msg = new MsgAcqResultDepA(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        org.junit.Assert.assertEquals(msg.cf, 4.74536132812500000e+03, DELTA);
        org.junit.Assert.assertEquals(msg.cp, 7.80500000000000000e+02, DELTA);
        value = msg.prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.prn + "' != '" + 14 + "'", value.equals(BigInteger.valueOf(14L)));
        } else {
            value = value.longValue();
            expected = 14L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.snr, 1.53000001907348633e+01, DELTA);
    }

    @Test
    public void test6() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_acquisition_MsgAcqResultDepATest.test6");
        byte[] payload =
                new byte[] {
                    (byte) 228,
                    (byte) 56,
                    (byte) 35,
                    (byte) 67,
                    (byte) 0,
                    (byte) 32,
                    (byte) 18,
                    (byte) 68,
                    (byte) 129,
                    (byte) 193,
                    (byte) 249,
                    (byte) 195,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x4c3, 0x15, payload);
        MsgAcqResultDepA msg = new MsgAcqResultDepA(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        org.junit.Assert.assertEquals(msg.cf, -4.99511749267578125e+02, DELTA);
        org.junit.Assert.assertEquals(msg.cp, 5.84500000000000000e+02, DELTA);
        value = msg.prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.prn + "' != '" + 0 + "'", value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.snr, 1.63222229003906250e+02, DELTA);
    }
}
