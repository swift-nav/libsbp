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
// spec/tests/yaml/swiftnav/sbp/acquisition/test_MsgAcqResultDepB.yaml by generate.py. Do not modify
// by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.acquisition.MsgAcqResultDepB;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_acquisition_MsgAcqResultDepBTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_acquisition_MsgAcqResultDepBTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 137, (byte) 167, (byte) 18, (byte) 66, (byte) 0, (byte) 0, (byte) 161,
                    (byte) 67, (byte) 240, (byte) 24, (byte) 156, (byte) 69, (byte) 9, (byte) 0,
                    (byte) 0, (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0xd7f6, 0x14, payload);
        MsgAcqResultDepB msg = new MsgAcqResultDepB(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        org.junit.Assert.assertEquals(msg.cf, 4.99511718750000000e+03, DELTA);
        org.junit.Assert.assertEquals(msg.cp, 3.22000000000000000e+02, DELTA);
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
                    "'" + msg.sid.sat + "' != '" + 9 + "'", value.equals(BigInteger.valueOf(9L)));
        } else {
            value = value.longValue();
            expected = 9L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.snr, 3.66636085510253906e+01, DELTA);
    }

    @Test
    public void test2() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_acquisition_MsgAcqResultDepBTest.test2");
        byte[] payload =
                new byte[] {
                    (byte) 206, (byte) 172, (byte) 16, (byte) 66, (byte) 0, (byte) 192, (byte) 82,
                    (byte) 68, (byte) 198, (byte) 199, (byte) 0, (byte) 198, (byte) 3, (byte) 0,
                    (byte) 0, (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0xd7f6, 0x14, payload);
        MsgAcqResultDepB msg = new MsgAcqResultDepB(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        org.junit.Assert.assertEquals(msg.cf, -8.24194335937500000e+03, DELTA);
        org.junit.Assert.assertEquals(msg.cp, 8.43000000000000000e+02, DELTA);
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
                    "'" + msg.sid.sat + "' != '" + 3 + "'", value.equals(BigInteger.valueOf(3L)));
        } else {
            value = value.longValue();
            expected = 3L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.snr, 3.61687545776367188e+01, DELTA);
    }

    @Test
    public void test3() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_acquisition_MsgAcqResultDepBTest.test3");
        byte[] payload =
                new byte[] {
                    (byte) 228, (byte) 27, (byte) 15, (byte) 66, (byte) 0, (byte) 128, (byte) 70,
                    (byte) 68, (byte) 228, (byte) 74, (byte) 148, (byte) 69, (byte) 18, (byte) 0,
                    (byte) 0, (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0xd7f6, 0x14, payload);
        MsgAcqResultDepB msg = new MsgAcqResultDepB(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        org.junit.Assert.assertEquals(msg.cf, 4.74536132812500000e+03, DELTA);
        org.junit.Assert.assertEquals(msg.cp, 7.94000000000000000e+02, DELTA);
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
                    "'" + msg.sid.sat + "' != '" + 18 + "'", value.equals(BigInteger.valueOf(18L)));
        } else {
            value = value.longValue();
            expected = 18L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.snr, 3.57772369384765625e+01, DELTA);
    }

    @Test
    public void test4() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_acquisition_MsgAcqResultDepBTest.test4");
        byte[] payload =
                new byte[] {
                    (byte) 46, (byte) 199, (byte) 14, (byte) 66, (byte) 0, (byte) 64, (byte) 129,
                    (byte) 67, (byte) 240, (byte) 24, (byte) 28, (byte) 69, (byte) 17, (byte) 0,
                    (byte) 0, (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0xd7f6, 0x14, payload);
        MsgAcqResultDepB msg = new MsgAcqResultDepB(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        org.junit.Assert.assertEquals(msg.cf, 2.49755859375000000e+03, DELTA);
        org.junit.Assert.assertEquals(msg.cp, 2.58500000000000000e+02, DELTA);
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
                    "'" + msg.sid.sat + "' != '" + 17 + "'", value.equals(BigInteger.valueOf(17L)));
        } else {
            value = value.longValue();
            expected = 17L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.snr, 3.56945114135742188e+01, DELTA);
    }

    @Test
    public void test5() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_acquisition_MsgAcqResultDepBTest.test5");
        byte[] payload =
                new byte[] {
                    (byte) 194, (byte) 24, (byte) 14, (byte) 66, (byte) 0, (byte) 128, (byte) 2,
                    (byte) 68, (byte) 129, (byte) 193, (byte) 249, (byte) 195, (byte) 5, (byte) 0,
                    (byte) 0, (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0xd7f6, 0x14, payload);
        MsgAcqResultDepB msg = new MsgAcqResultDepB(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        org.junit.Assert.assertEquals(msg.cf, -4.99511749267578125e+02, DELTA);
        org.junit.Assert.assertEquals(msg.cp, 5.22000000000000000e+02, DELTA);
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
                    "'" + msg.sid.sat + "' != '" + 5 + "'", value.equals(BigInteger.valueOf(5L)));
        } else {
            value = value.longValue();
            expected = 5L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.snr, 3.55241775512695312e+01, DELTA);
    }
}
