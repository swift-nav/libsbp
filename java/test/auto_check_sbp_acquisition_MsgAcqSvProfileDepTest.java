/*
 * Copyright (C) 2015-2021 Swift Navigation Inc.
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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/acquisition/test_MsgAcqSvProfileDep.yaml by generate.py. Do not modify by hand!

import java.math.BigInteger;

import org.junit.Test;

import org.json.JSONObject;

import com.swiftnav.sbp.SBPMessage;

import com.swiftnav.sbp.acquisition.MsgAcqSvProfileDep;


public class auto_check_sbp_acquisition_MsgAcqSvProfileDepTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_acquisition_MsgAcqSvProfileDepTest.test1");
        byte[] payload = new byte[] {(byte)67,(byte)103,(byte)151,(byte)0,(byte)12,(byte)22,(byte)0,(byte)0,(byte)0,(byte)187,(byte)0,(byte)91,(byte)0,(byte)0,(byte)0,(byte)75,(byte)0,(byte)0,(byte)0,(byte)132,(byte)0,(byte)0,(byte)0,(byte)36,(byte)0,(byte)0,(byte)0,(byte)60,(byte)0,(byte)0,(byte)0,(byte)241,(byte)0,(byte)0,(byte)0,(byte)238,(byte)38,(byte)111,(byte)0,(byte)179,(byte)23,(byte)0,(byte)1,(byte)0,(byte)176,(byte)0,(byte)166,(byte)0,(byte)0,(byte)0,(byte)234,(byte)0,(byte)0,(byte)0,(byte)155,(byte)0,(byte)0,(byte)0,(byte)24,(byte)0,(byte)0,(byte)0,(byte)212,(byte)0,(byte)0,(byte)0,(byte)247,(byte)0,(byte)0,(byte)0,(byte)142,(byte)213,(byte)68,(byte)0,(byte)53,(byte)24,(byte)0,(byte)0,(byte)0,(byte)52,(byte)0,(byte)49,(byte)0,(byte)0,(byte)0,(byte)245,(byte)0,(byte)0,(byte)0,(byte)76,(byte)0,(byte)0,(byte)0,(byte)248,(byte)0,(byte)0,(byte)0,(byte)212,(byte)0,(byte)0,(byte)0,(byte)101,(byte)0,(byte)0,(byte)0, };
        SBPMessage sbp = new SBPMessage( 0x04c3, 0x1e, payload );
        MsgAcqSvProfileDep msg = new MsgAcqSvProfileDep( sbp );
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.acq_sv_profile[0].bin_width;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.acq_sv_profile[0].bin_width + "' != '" + 187 + "'", value.equals(BigInteger.valueOf( 187L ) ) );
        } else {
            value = value.longValue();
            expected = 187L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[0].cf;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.acq_sv_profile[0].cf + "' != '" + 60 + "'", value.equals(BigInteger.valueOf( 60L ) ) );
        } else {
            value = value.longValue();
            expected = 60L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[0].cf_max;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.acq_sv_profile[0].cf_max + "' != '" + 36 + "'", value.equals(BigInteger.valueOf( 36L ) ) );
        } else {
            value = value.longValue();
            expected = 36L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[0].cf_min;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.acq_sv_profile[0].cf_min + "' != '" + 132 + "'", value.equals(BigInteger.valueOf( 132L ) ) );
        } else {
            value = value.longValue();
            expected = 132L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[0].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.acq_sv_profile[0].cn0 + "' != '" + 151 + "'", value.equals(BigInteger.valueOf( 151L ) ) );
        } else {
            value = value.longValue();
            expected = 151L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[0].cp;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.acq_sv_profile[0].cp + "' != '" + 241 + "'", value.equals(BigInteger.valueOf( 241L ) ) );
        } else {
            value = value.longValue();
            expected = 241L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[0].int_time;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.acq_sv_profile[0].int_time + "' != '" + 12 + "'", value.equals(BigInteger.valueOf( 12L ) ) );
        } else {
            value = value.longValue();
            expected = 12L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[0].job_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.acq_sv_profile[0].job_type + "' != '" + 67 + "'", value.equals(BigInteger.valueOf( 67L ) ) );
        } else {
            value = value.longValue();
            expected = 67L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[0].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.acq_sv_profile[0].sid.code + "' != '" + 0 + "'", value.equals(BigInteger.valueOf( 0L ) ) );
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[0].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.acq_sv_profile[0].sid.reserved + "' != '" + 0 + "'", value.equals(BigInteger.valueOf( 0L ) ) );
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[0].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.acq_sv_profile[0].sid.sat + "' != '" + 22 + "'", value.equals(BigInteger.valueOf( 22L ) ) );
        } else {
            value = value.longValue();
            expected = 22L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[0].status;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.acq_sv_profile[0].status + "' != '" + 103 + "'", value.equals(BigInteger.valueOf( 103L ) ) );
        } else {
            value = value.longValue();
            expected = 103L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[0].time_spent;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.acq_sv_profile[0].time_spent + "' != '" + 75 + "'", value.equals(BigInteger.valueOf( 75L ) ) );
        } else {
            value = value.longValue();
            expected = 75L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[0].timestamp;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.acq_sv_profile[0].timestamp + "' != '" + 91 + "'", value.equals(BigInteger.valueOf( 91L ) ) );
        } else {
            value = value.longValue();
            expected = 91L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[1].bin_width;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.acq_sv_profile[1].bin_width + "' != '" + 176 + "'", value.equals(BigInteger.valueOf( 176L ) ) );
        } else {
            value = value.longValue();
            expected = 176L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[1].cf;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.acq_sv_profile[1].cf + "' != '" + 212 + "'", value.equals(BigInteger.valueOf( 212L ) ) );
        } else {
            value = value.longValue();
            expected = 212L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[1].cf_max;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.acq_sv_profile[1].cf_max + "' != '" + 24 + "'", value.equals(BigInteger.valueOf( 24L ) ) );
        } else {
            value = value.longValue();
            expected = 24L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[1].cf_min;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.acq_sv_profile[1].cf_min + "' != '" + 155 + "'", value.equals(BigInteger.valueOf( 155L ) ) );
        } else {
            value = value.longValue();
            expected = 155L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[1].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.acq_sv_profile[1].cn0 + "' != '" + 111 + "'", value.equals(BigInteger.valueOf( 111L ) ) );
        } else {
            value = value.longValue();
            expected = 111L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[1].cp;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.acq_sv_profile[1].cp + "' != '" + 247 + "'", value.equals(BigInteger.valueOf( 247L ) ) );
        } else {
            value = value.longValue();
            expected = 247L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[1].int_time;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.acq_sv_profile[1].int_time + "' != '" + 179 + "'", value.equals(BigInteger.valueOf( 179L ) ) );
        } else {
            value = value.longValue();
            expected = 179L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[1].job_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.acq_sv_profile[1].job_type + "' != '" + 238 + "'", value.equals(BigInteger.valueOf( 238L ) ) );
        } else {
            value = value.longValue();
            expected = 238L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[1].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.acq_sv_profile[1].sid.code + "' != '" + 1 + "'", value.equals(BigInteger.valueOf( 1L ) ) );
        } else {
            value = value.longValue();
            expected = 1L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[1].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.acq_sv_profile[1].sid.reserved + "' != '" + 0 + "'", value.equals(BigInteger.valueOf( 0L ) ) );
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[1].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.acq_sv_profile[1].sid.sat + "' != '" + 23 + "'", value.equals(BigInteger.valueOf( 23L ) ) );
        } else {
            value = value.longValue();
            expected = 23L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[1].status;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.acq_sv_profile[1].status + "' != '" + 38 + "'", value.equals(BigInteger.valueOf( 38L ) ) );
        } else {
            value = value.longValue();
            expected = 38L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[1].time_spent;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.acq_sv_profile[1].time_spent + "' != '" + 234 + "'", value.equals(BigInteger.valueOf( 234L ) ) );
        } else {
            value = value.longValue();
            expected = 234L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[1].timestamp;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.acq_sv_profile[1].timestamp + "' != '" + 166 + "'", value.equals(BigInteger.valueOf( 166L ) ) );
        } else {
            value = value.longValue();
            expected = 166L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[2].bin_width;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.acq_sv_profile[2].bin_width + "' != '" + 52 + "'", value.equals(BigInteger.valueOf( 52L ) ) );
        } else {
            value = value.longValue();
            expected = 52L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[2].cf;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.acq_sv_profile[2].cf + "' != '" + 212 + "'", value.equals(BigInteger.valueOf( 212L ) ) );
        } else {
            value = value.longValue();
            expected = 212L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[2].cf_max;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.acq_sv_profile[2].cf_max + "' != '" + 248 + "'", value.equals(BigInteger.valueOf( 248L ) ) );
        } else {
            value = value.longValue();
            expected = 248L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[2].cf_min;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.acq_sv_profile[2].cf_min + "' != '" + 76 + "'", value.equals(BigInteger.valueOf( 76L ) ) );
        } else {
            value = value.longValue();
            expected = 76L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[2].cn0;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.acq_sv_profile[2].cn0 + "' != '" + 68 + "'", value.equals(BigInteger.valueOf( 68L ) ) );
        } else {
            value = value.longValue();
            expected = 68L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[2].cp;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.acq_sv_profile[2].cp + "' != '" + 101 + "'", value.equals(BigInteger.valueOf( 101L ) ) );
        } else {
            value = value.longValue();
            expected = 101L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[2].int_time;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.acq_sv_profile[2].int_time + "' != '" + 53 + "'", value.equals(BigInteger.valueOf( 53L ) ) );
        } else {
            value = value.longValue();
            expected = 53L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[2].job_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.acq_sv_profile[2].job_type + "' != '" + 142 + "'", value.equals(BigInteger.valueOf( 142L ) ) );
        } else {
            value = value.longValue();
            expected = 142L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[2].sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.acq_sv_profile[2].sid.code + "' != '" + 0 + "'", value.equals(BigInteger.valueOf( 0L ) ) );
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[2].sid.reserved;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.acq_sv_profile[2].sid.reserved + "' != '" + 0 + "'", value.equals(BigInteger.valueOf( 0L ) ) );
        } else {
            value = value.longValue();
            expected = 0L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[2].sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.acq_sv_profile[2].sid.sat + "' != '" + 24 + "'", value.equals(BigInteger.valueOf( 24L ) ) );
        } else {
            value = value.longValue();
            expected = 24L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[2].status;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.acq_sv_profile[2].status + "' != '" + 213 + "'", value.equals(BigInteger.valueOf( 213L ) ) );
        } else {
            value = value.longValue();
            expected = 213L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[2].time_spent;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.acq_sv_profile[2].time_spent + "' != '" + 245 + "'", value.equals(BigInteger.valueOf( 245L ) ) );
        } else {
            value = value.longValue();
            expected = 245L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.acq_sv_profile[2].timestamp;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.acq_sv_profile[2].timestamp + "' != '" + 49 + "'", value.equals(BigInteger.valueOf( 49L ) ) );
        } else {
            value = value.longValue();
            expected = 49L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
