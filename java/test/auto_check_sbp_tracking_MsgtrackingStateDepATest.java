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
// spec/tests/yaml/swiftnav/sbp/tracking/test_MsgtrackingStateDepA.yaml by generate.py. Do not
// modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.tracking.MsgTrackingStateDepA;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_tracking_MsgtrackingStateDepATest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_tracking_MsgtrackingStateDepATest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 1, (byte) 0, (byte) 204, (byte) 177, (byte) 51, (byte) 65, (byte) 1,
                    (byte) 2, (byte) 198, (byte) 4, (byte) 39, (byte) 65, (byte) 1, (byte) 3,
                    (byte) 219, (byte) 182, (byte) 27, (byte) 65, (byte) 1, (byte) 7, (byte) 132,
                    (byte) 120, (byte) 101, (byte) 65, (byte) 1, (byte) 10, (byte) 91, (byte) 91,
                    (byte) 251, (byte) 64, (byte) 1, (byte) 13, (byte) 42, (byte) 37, (byte) 163,
                    (byte) 64, (byte) 1, (byte) 22, (byte) 130, (byte) 184, (byte) 215, (byte) 64,
                    (byte) 1, (byte) 30, (byte) 115, (byte) 53, (byte) 75, (byte) 65, (byte) 1,
                    (byte) 31, (byte) 16, (byte) 74, (byte) 126, (byte) 65, (byte) 1, (byte) 25,
                    (byte) 132, (byte) 196, (byte) 135, (byte) 64, (byte) 1, (byte) 6, (byte) 100,
                    (byte) 59, (byte) 223, (byte) 64,
                };
        SBPMessage sbp = new SBPMessage(0x4c3, 0x16, payload);
        MsgTrackingStateDepA msg = new MsgTrackingStateDepA(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        org.junit.Assert.assertEquals(msg.states[0].cn0, 1.12309074401855469e+01, DELTA);
        value = msg.states[0].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[0].prn + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[0].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[0].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[1].cn0, 1.04386653900146484e+01, DELTA);
        value = msg.states[1].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[1].prn + "' != '" + 2 + "'",
                    value.equals(BigInteger.valueOf(2L)));
        } else {
            value = value.longValue();
            expected = 2L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[1].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[1].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[2].cn0, 9.73214244842529297e+00, DELTA);
        value = msg.states[2].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[2].prn + "' != '" + 3 + "'",
                    value.equals(BigInteger.valueOf(3L)));
        } else {
            value = value.longValue();
            expected = 3L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[2].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[2].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[3].cn0, 1.43419227600097656e+01, DELTA);
        value = msg.states[3].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[3].prn + "' != '" + 7 + "'",
                    value.equals(BigInteger.valueOf(7L)));
        } else {
            value = value.longValue();
            expected = 7L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[3].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[3].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[4].cn0, 7.85490179061889648e+00, DELTA);
        value = msg.states[4].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[4].prn + "' != '" + 10 + "'",
                    value.equals(BigInteger.valueOf(10L)));
        } else {
            value = value.longValue();
            expected = 10L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[4].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[4].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[5].cn0, 5.09828662872314453e+00, DELTA);
        value = msg.states[5].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[5].prn + "' != '" + 13 + "'",
                    value.equals(BigInteger.valueOf(13L)));
        } else {
            value = value.longValue();
            expected = 13L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[5].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[5].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[6].cn0, 6.74127292633056641e+00, DELTA);
        value = msg.states[6].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[6].prn + "' != '" + 22 + "'",
                    value.equals(BigInteger.valueOf(22L)));
        } else {
            value = value.longValue();
            expected = 22L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[6].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[6].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[7].cn0, 1.27005491256713867e+01, DELTA);
        value = msg.states[7].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[7].prn + "' != '" + 30 + "'",
                    value.equals(BigInteger.valueOf(30L)));
        } else {
            value = value.longValue();
            expected = 30L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[7].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[7].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[8].cn0, 1.58930816650390625e+01, DELTA);
        value = msg.states[8].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[8].prn + "' != '" + 31 + "'",
                    value.equals(BigInteger.valueOf(31L)));
        } else {
            value = value.longValue();
            expected = 31L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[8].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[8].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[9].cn0, 4.24273872375488281e+00, DELTA);
        value = msg.states[9].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[9].prn + "' != '" + 25 + "'",
                    value.equals(BigInteger.valueOf(25L)));
        } else {
            value = value.longValue();
            expected = 25L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[9].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[9].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[10].cn0, 6.97599983215332031e+00, DELTA);
        value = msg.states[10].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[10].prn + "' != '" + 6 + "'",
                    value.equals(BigInteger.valueOf(6L)));
        } else {
            value = value.longValue();
            expected = 6L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[10].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[10].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test2() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_tracking_MsgtrackingStateDepATest.test2");
        byte[] payload =
                new byte[] {
                    (byte) 1, (byte) 0, (byte) 216, (byte) 57, (byte) 48, (byte) 65, (byte) 1,
                    (byte) 2, (byte) 145, (byte) 41, (byte) 46, (byte) 65, (byte) 1, (byte) 3,
                    (byte) 4, (byte) 26, (byte) 34, (byte) 65, (byte) 1, (byte) 7, (byte) 177,
                    (byte) 67, (byte) 109, (byte) 65, (byte) 1, (byte) 10, (byte) 61, (byte) 80,
                    (byte) 249, (byte) 64, (byte) 1, (byte) 13, (byte) 250, (byte) 199, (byte) 155,
                    (byte) 64, (byte) 1, (byte) 22, (byte) 55, (byte) 19, (byte) 215, (byte) 64,
                    (byte) 1, (byte) 30, (byte) 138, (byte) 138, (byte) 79, (byte) 65, (byte) 1,
                    (byte) 31, (byte) 214, (byte) 179, (byte) 119, (byte) 65, (byte) 1, (byte) 25,
                    (byte) 53, (byte) 138, (byte) 120, (byte) 64, (byte) 1, (byte) 6, (byte) 183,
                    (byte) 247, (byte) 129, (byte) 64,
                };
        SBPMessage sbp = new SBPMessage(0x4c3, 0x16, payload);
        MsgTrackingStateDepA msg = new MsgTrackingStateDepA(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        org.junit.Assert.assertEquals(msg.states[0].cn0, 1.10141220092773438e+01, DELTA);
        value = msg.states[0].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[0].prn + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[0].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[0].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[1].cn0, 1.08851480484008789e+01, DELTA);
        value = msg.states[1].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[1].prn + "' != '" + 2 + "'",
                    value.equals(BigInteger.valueOf(2L)));
        } else {
            value = value.longValue();
            expected = 2L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[1].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[1].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[2].cn0, 1.01313514709472656e+01, DELTA);
        value = msg.states[2].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[2].prn + "' != '" + 3 + "'",
                    value.equals(BigInteger.valueOf(3L)));
        } else {
            value = value.longValue();
            expected = 3L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[2].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[2].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[3].cn0, 1.48290262222290039e+01, DELTA);
        value = msg.states[3].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[3].prn + "' != '" + 7 + "'",
                    value.equals(BigInteger.valueOf(7L)));
        } else {
            value = value.longValue();
            expected = 7L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[3].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[3].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[4].cn0, 7.79104471206665039e+00, DELTA);
        value = msg.states[4].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[4].prn + "' != '" + 10 + "'",
                    value.equals(BigInteger.valueOf(10L)));
        } else {
            value = value.longValue();
            expected = 10L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[4].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[4].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[5].cn0, 4.86816120147705078e+00, DELTA);
        value = msg.states[5].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[5].prn + "' != '" + 13 + "'",
                    value.equals(BigInteger.valueOf(13L)));
        } else {
            value = value.longValue();
            expected = 13L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[5].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[5].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[6].cn0, 6.72109556198120117e+00, DELTA);
        value = msg.states[6].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[6].prn + "' != '" + 22 + "'",
                    value.equals(BigInteger.valueOf(22L)));
        } else {
            value = value.longValue();
            expected = 22L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[6].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[6].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[7].cn0, 1.29713230133056641e+01, DELTA);
        value = msg.states[7].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[7].prn + "' != '" + 30 + "'",
                    value.equals(BigInteger.valueOf(30L)));
        } else {
            value = value.longValue();
            expected = 30L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[7].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[7].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[8].cn0, 1.54814052581787109e+01, DELTA);
        value = msg.states[8].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[8].prn + "' != '" + 31 + "'",
                    value.equals(BigInteger.valueOf(31L)));
        } else {
            value = value.longValue();
            expected = 31L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[8].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[8].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[9].cn0, 3.88343548774719238e+00, DELTA);
        value = msg.states[9].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[9].prn + "' != '" + 25 + "'",
                    value.equals(BigInteger.valueOf(25L)));
        } else {
            value = value.longValue();
            expected = 25L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[9].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[9].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[10].cn0, 4.06148862838745117e+00, DELTA);
        value = msg.states[10].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[10].prn + "' != '" + 6 + "'",
                    value.equals(BigInteger.valueOf(6L)));
        } else {
            value = value.longValue();
            expected = 6L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[10].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[10].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test3() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_tracking_MsgtrackingStateDepATest.test3");
        byte[] payload =
                new byte[] {
                    (byte) 1, (byte) 0, (byte) 141, (byte) 76, (byte) 60, (byte) 65, (byte) 1,
                    (byte) 2, (byte) 69, (byte) 139, (byte) 46, (byte) 65, (byte) 1, (byte) 3,
                    (byte) 146, (byte) 27, (byte) 30, (byte) 65, (byte) 1, (byte) 7, (byte) 235,
                    (byte) 56, (byte) 97, (byte) 65, (byte) 1, (byte) 10, (byte) 141, (byte) 213,
                    (byte) 243, (byte) 64, (byte) 1, (byte) 13, (byte) 250, (byte) 170, (byte) 166,
                    (byte) 64, (byte) 1, (byte) 22, (byte) 17, (byte) 101, (byte) 201, (byte) 64,
                    (byte) 1, (byte) 30, (byte) 172, (byte) 183, (byte) 83, (byte) 65, (byte) 1,
                    (byte) 31, (byte) 238, (byte) 193, (byte) 120, (byte) 65, (byte) 1, (byte) 25,
                    (byte) 220, (byte) 48, (byte) 132, (byte) 64, (byte) 1, (byte) 6, (byte) 49,
                    (byte) 214, (byte) 54, (byte) 64,
                };
        SBPMessage sbp = new SBPMessage(0x4c3, 0x16, payload);
        MsgTrackingStateDepA msg = new MsgTrackingStateDepA(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        org.junit.Assert.assertEquals(msg.states[0].cn0, 1.17686891555786133e+01, DELTA);
        value = msg.states[0].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[0].prn + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[0].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[0].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[1].cn0, 1.09090013504028320e+01, DELTA);
        value = msg.states[1].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[1].prn + "' != '" + 2 + "'",
                    value.equals(BigInteger.valueOf(2L)));
        } else {
            value = value.longValue();
            expected = 2L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[1].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[1].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[2].cn0, 9.88173103332519531e+00, DELTA);
        value = msg.states[2].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[2].prn + "' != '" + 3 + "'",
                    value.equals(BigInteger.valueOf(3L)));
        } else {
            value = value.longValue();
            expected = 3L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[2].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[2].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[3].cn0, 1.40763959884643555e+01, DELTA);
        value = msg.states[3].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[3].prn + "' != '" + 7 + "'",
                    value.equals(BigInteger.valueOf(7L)));
        } else {
            value = value.longValue();
            expected = 7L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[3].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[3].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[4].cn0, 7.61981821060180664e+00, DELTA);
        value = msg.states[4].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[4].prn + "' != '" + 10 + "'",
                    value.equals(BigInteger.valueOf(10L)));
        } else {
            value = value.longValue();
            expected = 10L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[4].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[4].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[5].cn0, 5.20837116241455078e+00, DELTA);
        value = msg.states[5].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[5].prn + "' != '" + 13 + "'",
                    value.equals(BigInteger.valueOf(13L)));
        } else {
            value = value.longValue();
            expected = 13L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[5].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[5].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[6].cn0, 6.29358720779418945e+00, DELTA);
        value = msg.states[6].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[6].prn + "' != '" + 22 + "'",
                    value.equals(BigInteger.valueOf(22L)));
        } else {
            value = value.longValue();
            expected = 22L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[6].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[6].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[7].cn0, 1.32323417663574219e+01, DELTA);
        value = msg.states[7].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[7].prn + "' != '" + 30 + "'",
                    value.equals(BigInteger.valueOf(30L)));
        } else {
            value = value.longValue();
            expected = 30L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[7].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[7].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[8].cn0, 1.55473461151123047e+01, DELTA);
        value = msg.states[8].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[8].prn + "' != '" + 31 + "'",
                    value.equals(BigInteger.valueOf(31L)));
        } else {
            value = value.longValue();
            expected = 31L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[8].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[8].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[9].cn0, 4.13096427917480469e+00, DELTA);
        value = msg.states[9].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[9].prn + "' != '" + 25 + "'",
                    value.equals(BigInteger.valueOf(25L)));
        } else {
            value = value.longValue();
            expected = 25L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[9].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[9].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[10].cn0, 2.85682320594787598e+00, DELTA);
        value = msg.states[10].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[10].prn + "' != '" + 6 + "'",
                    value.equals(BigInteger.valueOf(6L)));
        } else {
            value = value.longValue();
            expected = 6L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[10].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[10].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test4() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_tracking_MsgtrackingStateDepATest.test4");
        byte[] payload =
                new byte[] {
                    (byte) 1, (byte) 0, (byte) 55, (byte) 143, (byte) 120, (byte) 66, (byte) 0,
                    (byte) 0, (byte) 0, (byte) 0, (byte) 128, (byte) 191, (byte) 0, (byte) 0,
                    (byte) 0, (byte) 0, (byte) 128, (byte) 191, (byte) 0, (byte) 0, (byte) 0,
                    (byte) 0, (byte) 128, (byte) 191, (byte) 0, (byte) 0, (byte) 0, (byte) 0,
                    (byte) 128, (byte) 191, (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 128,
                    (byte) 191, (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 128, (byte) 191,
                    (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 128, (byte) 191, (byte) 0,
                    (byte) 0, (byte) 0, (byte) 0, (byte) 128, (byte) 191, (byte) 0, (byte) 0,
                    (byte) 0, (byte) 0, (byte) 128, (byte) 191, (byte) 0, (byte) 0, (byte) 0,
                    (byte) 0, (byte) 128, (byte) 191,
                };
        SBPMessage sbp = new SBPMessage(0x4c3, 0x16, payload);
        MsgTrackingStateDepA msg = new MsgTrackingStateDepA(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        org.junit.Assert.assertEquals(msg.states[0].cn0, 6.21398582458496094e+01, DELTA);
        value = msg.states[0].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[0].prn + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[0].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[0].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[1].cn0, -1.00000000000000000e+00, DELTA);
        value = msg.states[1].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[1].prn + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[1].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[1].state + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[2].cn0, -1.00000000000000000e+00, DELTA);
        value = msg.states[2].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[2].prn + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[2].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[2].state + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[3].cn0, -1.00000000000000000e+00, DELTA);
        value = msg.states[3].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[3].prn + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[3].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[3].state + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[4].cn0, -1.00000000000000000e+00, DELTA);
        value = msg.states[4].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[4].prn + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[4].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[4].state + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[5].cn0, -1.00000000000000000e+00, DELTA);
        value = msg.states[5].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[5].prn + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[5].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[5].state + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[6].cn0, -1.00000000000000000e+00, DELTA);
        value = msg.states[6].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[6].prn + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[6].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[6].state + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[7].cn0, -1.00000000000000000e+00, DELTA);
        value = msg.states[7].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[7].prn + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[7].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[7].state + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[8].cn0, -1.00000000000000000e+00, DELTA);
        value = msg.states[8].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[8].prn + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[8].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[8].state + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[9].cn0, -1.00000000000000000e+00, DELTA);
        value = msg.states[9].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[9].prn + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[9].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[9].state + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[10].cn0, -1.00000000000000000e+00, DELTA);
        value = msg.states[10].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[10].prn + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[10].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[10].state + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test5() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_tracking_MsgtrackingStateDepATest.test5");
        byte[] payload =
                new byte[] {
                    (byte) 1, (byte) 0, (byte) 218, (byte) 14, (byte) 19, (byte) 66, (byte) 1,
                    (byte) 2, (byte) 210, (byte) 3, (byte) 21, (byte) 65, (byte) 1, (byte) 3,
                    (byte) 234, (byte) 214, (byte) 134, (byte) 65, (byte) 0, (byte) 0, (byte) 0,
                    (byte) 0, (byte) 128, (byte) 191, (byte) 0, (byte) 0, (byte) 0, (byte) 0,
                    (byte) 128, (byte) 191, (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 128,
                    (byte) 191, (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 128, (byte) 191,
                    (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 128, (byte) 191, (byte) 0,
                    (byte) 0, (byte) 0, (byte) 0, (byte) 128, (byte) 191, (byte) 0, (byte) 0,
                    (byte) 0, (byte) 0, (byte) 128, (byte) 191, (byte) 0, (byte) 0, (byte) 0,
                    (byte) 0, (byte) 128, (byte) 191,
                };
        SBPMessage sbp = new SBPMessage(0x4c3, 0x16, payload);
        MsgTrackingStateDepA msg = new MsgTrackingStateDepA(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        org.junit.Assert.assertEquals(msg.states[0].cn0, 3.67645034790039062e+01, DELTA);
        value = msg.states[0].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[0].prn + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[0].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[0].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[1].cn0, 9.31343269348144531e+00, DELTA);
        value = msg.states[1].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[1].prn + "' != '" + 2 + "'",
                    value.equals(BigInteger.valueOf(2L)));
        } else {
            value = value.longValue();
            expected = 2L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[1].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[1].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[2].cn0, 1.68549385070800781e+01, DELTA);
        value = msg.states[2].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[2].prn + "' != '" + 3 + "'",
                    value.equals(BigInteger.valueOf(3L)));
        } else {
            value = value.longValue();
            expected = 3L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[2].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[2].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[3].cn0, -1.00000000000000000e+00, DELTA);
        value = msg.states[3].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[3].prn + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[3].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[3].state + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[4].cn0, -1.00000000000000000e+00, DELTA);
        value = msg.states[4].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[4].prn + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[4].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[4].state + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[5].cn0, -1.00000000000000000e+00, DELTA);
        value = msg.states[5].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[5].prn + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[5].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[5].state + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[6].cn0, -1.00000000000000000e+00, DELTA);
        value = msg.states[6].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[6].prn + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[6].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[6].state + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[7].cn0, -1.00000000000000000e+00, DELTA);
        value = msg.states[7].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[7].prn + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[7].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[7].state + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[8].cn0, -1.00000000000000000e+00, DELTA);
        value = msg.states[8].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[8].prn + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[8].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[8].state + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[9].cn0, -1.00000000000000000e+00, DELTA);
        value = msg.states[9].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[9].prn + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[9].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[9].state + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[10].cn0, -1.00000000000000000e+00, DELTA);
        value = msg.states[10].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[10].prn + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[10].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[10].state + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }

    @Test
    public void test6() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_tracking_MsgtrackingStateDepATest.test6");
        byte[] payload =
                new byte[] {
                    (byte) 1, (byte) 0, (byte) 98, (byte) 39, (byte) 219, (byte) 65, (byte) 1,
                    (byte) 2, (byte) 0, (byte) 0, (byte) 56, (byte) 64, (byte) 1, (byte) 3,
                    (byte) 121, (byte) 123, (byte) 7, (byte) 65, (byte) 0, (byte) 0, (byte) 0,
                    (byte) 0, (byte) 128, (byte) 191, (byte) 0, (byte) 0, (byte) 0, (byte) 0,
                    (byte) 128, (byte) 191, (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 128,
                    (byte) 191, (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 128, (byte) 191,
                    (byte) 0, (byte) 0, (byte) 0, (byte) 0, (byte) 128, (byte) 191, (byte) 0,
                    (byte) 0, (byte) 0, (byte) 0, (byte) 128, (byte) 191, (byte) 0, (byte) 0,
                    (byte) 0, (byte) 0, (byte) 128, (byte) 191, (byte) 0, (byte) 0, (byte) 0,
                    (byte) 0, (byte) 128, (byte) 191,
                };
        SBPMessage sbp = new SBPMessage(0x4c3, 0x16, payload);
        MsgTrackingStateDepA msg = new MsgTrackingStateDepA(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        org.junit.Assert.assertEquals(msg.states[0].cn0, 2.73942298889160156e+01, DELTA);
        value = msg.states[0].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[0].prn + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[0].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[0].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[1].cn0, 2.87500000000000000e+00, DELTA);
        value = msg.states[1].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[1].prn + "' != '" + 2 + "'",
                    value.equals(BigInteger.valueOf(2L)));
        } else {
            value = value.longValue();
            expected = 2L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[1].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[1].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[2].cn0, 8.46764469146728516e+00, DELTA);
        value = msg.states[2].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[2].prn + "' != '" + 3 + "'",
                    value.equals(BigInteger.valueOf(3L)));
        } else {
            value = value.longValue();
            expected = 3L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[2].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[2].state + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[3].cn0, -1.00000000000000000e+00, DELTA);
        value = msg.states[3].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[3].prn + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[3].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[3].state + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[4].cn0, -1.00000000000000000e+00, DELTA);
        value = msg.states[4].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[4].prn + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[4].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[4].state + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[5].cn0, -1.00000000000000000e+00, DELTA);
        value = msg.states[5].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[5].prn + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[5].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[5].state + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[6].cn0, -1.00000000000000000e+00, DELTA);
        value = msg.states[6].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[6].prn + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[6].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[6].state + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[7].cn0, -1.00000000000000000e+00, DELTA);
        value = msg.states[7].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[7].prn + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[7].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[7].state + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[8].cn0, -1.00000000000000000e+00, DELTA);
        value = msg.states[8].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[8].prn + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[8].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[8].state + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[9].cn0, -1.00000000000000000e+00, DELTA);
        value = msg.states[9].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[9].prn + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[9].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[9].state + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        org.junit.Assert.assertEquals(msg.states[10].cn0, -1.00000000000000000e+00, DELTA);
        value = msg.states[10].prn;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[10].prn + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.states[10].state;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.states[10].state + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
    }
}
