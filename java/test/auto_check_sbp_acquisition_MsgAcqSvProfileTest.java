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

// This file was auto-generated from
// spec/tests/yaml/swiftnav/sbp/acquisition/test_MsgAcqSvProfile.yaml by generate.py. Do not modify
// by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.acquisition.MsgAcqSvProfile;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_acquisition_MsgAcqSvProfileTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_acquisition_MsgAcqSvProfileTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 7, (byte) 13, (byte) 38, (byte) 0, (byte) 97, (byte) 22, (byte) 0,
                    (byte) 174, (byte) 0, (byte) 52, (byte) 0, (byte) 0, (byte) 0, (byte) 49,
                    (byte) 0, (byte) 0, (byte) 0, (byte) 61, (byte) 0, (byte) 0, (byte) 0,
                    (byte) 147, (byte) 0, (byte) 0, (byte) 0, (byte) 47, (byte) 0, (byte) 0,
                    (byte) 0, (byte) 140, (byte) 0, (byte) 0, (byte) 0, (byte) 166, (byte) 210,
                    (byte) 59, (byte) 0, (byte) 253, (byte) 23, (byte) 1, (byte) 121, (byte) 0,
                    (byte) 190, (byte) 0, (byte) 0, (byte) 0, (byte) 175, (byte) 0, (byte) 0,
                    (byte) 0, (byte) 175, (byte) 0, (byte) 0, (byte) 0, (byte) 142, (byte) 0,
                    (byte) 0, (byte) 0, (byte) 237, (byte) 0, (byte) 0, (byte) 0, (byte) 12,
                    (byte) 0, (byte) 0, (byte) 0, (byte) 126, (byte) 88, (byte) 21, (byte) 0,
                    (byte) 153, (byte) 24, (byte) 0, (byte) 8, (byte) 0, (byte) 130, (byte) 0,
                    (byte) 0, (byte) 0, (byte) 172, (byte) 0, (byte) 0, (byte) 0, (byte) 91,
                    (byte) 0, (byte) 0, (byte) 0, (byte) 191, (byte) 0, (byte) 0, (byte) 0,
                    (byte) 84, (byte) 0, (byte) 0, (byte) 0, (byte) 82, (byte) 0, (byte) 0,
                    (byte) 0,
                };
        SBPMessage sbp = new SBPMessage(0x04c3, 0x2e, payload);
        MsgAcqSvProfile msg = new MsgAcqSvProfile(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.acq_sv_profile[0].bin_width;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.acq_sv_profile[0].bin_width + "' != '" + 174 + "'",
                    value.equals(BigInteger.valueOf(174L)));
        } else {
            value = value.longValue();
            expected = 174L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[0].cf;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.acq_sv_profile[0].cf + "' != '" + 47 + "'",
                    value.equals(BigInteger.valueOf(47L)));
        } else {
            value = value.longValue();
            expected = 47L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[0].cf_max;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.acq_sv_profile[0].cf_max + "' != '" + 147 + "'",
                    value.equals(BigInteger.valueOf(147L)));
        } else {
            value = value.longValue();
            expected = 147L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[0].cf_min;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.acq_sv_profile[0].cf_min + "' != '" + 61 + "'",
                    value.equals(BigInteger.valueOf(61L)));
        } else {
            value = value.longValue();
            expected = 61L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[0].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.acq_sv_profile[0].cn0 + "' != '" + 38 + "'",
                    value.equals(BigInteger.valueOf(38L)));
        } else {
            value = value.longValue();
            expected = 38L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[0].cp;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.acq_sv_profile[0].cp + "' != '" + 140 + "'",
                    value.equals(BigInteger.valueOf(140L)));
        } else {
            value = value.longValue();
            expected = 140L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[0].int_time;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.acq_sv_profile[0].int_time + "' != '" + 97 + "'",
                    value.equals(BigInteger.valueOf(97L)));
        } else {
            value = value.longValue();
            expected = 97L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[0].job_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.acq_sv_profile[0].job_type + "' != '" + 7 + "'",
                    value.equals(BigInteger.valueOf(7L)));
        } else {
            value = value.longValue();
            expected = 7L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[0].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.acq_sv_profile[0].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[0].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.acq_sv_profile[0].sid.sat + "' != '" + 22 + "'",
                    value.equals(BigInteger.valueOf(22L)));
        } else {
            value = value.longValue();
            expected = 22L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[0].status;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.acq_sv_profile[0].status + "' != '" + 13 + "'",
                    value.equals(BigInteger.valueOf(13L)));
        } else {
            value = value.longValue();
            expected = 13L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[0].time_spent;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.acq_sv_profile[0].time_spent + "' != '" + 49 + "'",
                    value.equals(BigInteger.valueOf(49L)));
        } else {
            value = value.longValue();
            expected = 49L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[0].timestamp;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.acq_sv_profile[0].timestamp + "' != '" + 52 + "'",
                    value.equals(BigInteger.valueOf(52L)));
        } else {
            value = value.longValue();
            expected = 52L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[1].bin_width;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.acq_sv_profile[1].bin_width + "' != '" + 121 + "'",
                    value.equals(BigInteger.valueOf(121L)));
        } else {
            value = value.longValue();
            expected = 121L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[1].cf;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.acq_sv_profile[1].cf + "' != '" + 237 + "'",
                    value.equals(BigInteger.valueOf(237L)));
        } else {
            value = value.longValue();
            expected = 237L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[1].cf_max;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.acq_sv_profile[1].cf_max + "' != '" + 142 + "'",
                    value.equals(BigInteger.valueOf(142L)));
        } else {
            value = value.longValue();
            expected = 142L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[1].cf_min;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.acq_sv_profile[1].cf_min + "' != '" + 175 + "'",
                    value.equals(BigInteger.valueOf(175L)));
        } else {
            value = value.longValue();
            expected = 175L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[1].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.acq_sv_profile[1].cn0 + "' != '" + 59 + "'",
                    value.equals(BigInteger.valueOf(59L)));
        } else {
            value = value.longValue();
            expected = 59L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[1].cp;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.acq_sv_profile[1].cp + "' != '" + 12 + "'",
                    value.equals(BigInteger.valueOf(12L)));
        } else {
            value = value.longValue();
            expected = 12L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[1].int_time;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.acq_sv_profile[1].int_time + "' != '" + 253 + "'",
                    value.equals(BigInteger.valueOf(253L)));
        } else {
            value = value.longValue();
            expected = 253L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[1].job_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.acq_sv_profile[1].job_type + "' != '" + 166 + "'",
                    value.equals(BigInteger.valueOf(166L)));
        } else {
            value = value.longValue();
            expected = 166L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[1].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.acq_sv_profile[1].sid.code + "' != '" + 1 + "'",
                    value.equals(BigInteger.valueOf(1L)));
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[1].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.acq_sv_profile[1].sid.sat + "' != '" + 23 + "'",
                    value.equals(BigInteger.valueOf(23L)));
        } else {
            value = value.longValue();
            expected = 23L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[1].status;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.acq_sv_profile[1].status + "' != '" + 210 + "'",
                    value.equals(BigInteger.valueOf(210L)));
        } else {
            value = value.longValue();
            expected = 210L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[1].time_spent;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.acq_sv_profile[1].time_spent + "' != '" + 175 + "'",
                    value.equals(BigInteger.valueOf(175L)));
        } else {
            value = value.longValue();
            expected = 175L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[1].timestamp;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.acq_sv_profile[1].timestamp + "' != '" + 190 + "'",
                    value.equals(BigInteger.valueOf(190L)));
        } else {
            value = value.longValue();
            expected = 190L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[2].bin_width;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.acq_sv_profile[2].bin_width + "' != '" + 8 + "'",
                    value.equals(BigInteger.valueOf(8L)));
        } else {
            value = value.longValue();
            expected = 8L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[2].cf;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.acq_sv_profile[2].cf + "' != '" + 84 + "'",
                    value.equals(BigInteger.valueOf(84L)));
        } else {
            value = value.longValue();
            expected = 84L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[2].cf_max;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.acq_sv_profile[2].cf_max + "' != '" + 191 + "'",
                    value.equals(BigInteger.valueOf(191L)));
        } else {
            value = value.longValue();
            expected = 191L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[2].cf_min;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.acq_sv_profile[2].cf_min + "' != '" + 91 + "'",
                    value.equals(BigInteger.valueOf(91L)));
        } else {
            value = value.longValue();
            expected = 91L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[2].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.acq_sv_profile[2].cn0 + "' != '" + 21 + "'",
                    value.equals(BigInteger.valueOf(21L)));
        } else {
            value = value.longValue();
            expected = 21L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[2].cp;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.acq_sv_profile[2].cp + "' != '" + 82 + "'",
                    value.equals(BigInteger.valueOf(82L)));
        } else {
            value = value.longValue();
            expected = 82L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[2].int_time;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.acq_sv_profile[2].int_time + "' != '" + 153 + "'",
                    value.equals(BigInteger.valueOf(153L)));
        } else {
            value = value.longValue();
            expected = 153L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[2].job_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.acq_sv_profile[2].job_type + "' != '" + 126 + "'",
                    value.equals(BigInteger.valueOf(126L)));
        } else {
            value = value.longValue();
            expected = 126L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[2].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.acq_sv_profile[2].sid.code + "' != '" + 0 + "'",
                    value.equals(BigInteger.valueOf(0L)));
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[2].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.acq_sv_profile[2].sid.sat + "' != '" + 24 + "'",
                    value.equals(BigInteger.valueOf(24L)));
        } else {
            value = value.longValue();
            expected = 24L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[2].status;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.acq_sv_profile[2].status + "' != '" + 88 + "'",
                    value.equals(BigInteger.valueOf(88L)));
        } else {
            value = value.longValue();
            expected = 88L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[2].time_spent;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.acq_sv_profile[2].time_spent + "' != '" + 172 + "'",
                    value.equals(BigInteger.valueOf(172L)));
        } else {
            value = value.longValue();
            expected = 172L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[2].timestamp;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.acq_sv_profile[2].timestamp + "' != '" + 130 + "'",
                    value.equals(BigInteger.valueOf(130L)));
        } else {
            value = value.longValue();
            expected = 130L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
