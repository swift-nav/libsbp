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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/ndb/test_MsgNdbEvent.yaml by generate.py. Do not modify by hand!

import java.math.BigInteger;

import org.junit.Test;

import org.json.JSONObject;

import com.swiftnav.sbp.SBPMessage;

import com.swiftnav.sbp.ndb.MsgNdbEvent;


public class auto_check_sbp_ndb_MsgNdbEventTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_ndb_MsgNdbEventTest.test1");
        byte[] payload = new byte[] {(byte)254,(byte)188,(byte)70,(byte)185,(byte)69,(byte)0,(byte)0,(byte)0,(byte)249,(byte)73,(byte)205,(byte)115,(byte)238,(byte)74,(byte)98,(byte)66,(byte)182,(byte)148, };
        SBPMessage sbp = new SBPMessage( 0xaea4, 0x400, payload );
        MsgNdbEvent msg = new MsgNdbEvent( sbp );
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.data_source;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.data_source + "' != '" + 115 + "'", value.equals(BigInteger.valueOf( 115L ) ) );
        } else {
            value = value.longValue();
            expected = 115L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.event;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.event + "' != '" + 249 + "'", value.equals(BigInteger.valueOf( 249L ) ) );
        } else {
            value = value.longValue();
            expected = 249L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.object_sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.object_sid.code + "' != '" + 74 + "'", value.equals(BigInteger.valueOf( 74L ) ) );
        } else {
            value = value.longValue();
            expected = 74L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.object_sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.object_sid.sat + "' != '" + 238 + "'", value.equals(BigInteger.valueOf( 238L ) ) );
        } else {
            value = value.longValue();
            expected = 238L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.object_type;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.object_type + "' != '" + 73 + "'", value.equals(BigInteger.valueOf( 73L ) ) );
        } else {
            value = value.longValue();
            expected = 73L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.original_sender;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.original_sender + "' != '" + 38070 + "'", value.equals(BigInteger.valueOf( 38070L ) ) );
        } else {
            value = value.longValue();
            expected = 38070L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.recv_time;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.recv_time + "' != '" + 299461164286L + "'", value.equals( new BigInteger( "299461164286" ) ) );
        } else {
            value = value.longValue();
            expected = 299461164286L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.result;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.result + "' != '" + 205 + "'", value.equals(BigInteger.valueOf( 205L ) ) );
        } else {
            value = value.longValue();
            expected = 205L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.src_sid.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.src_sid.code + "' != '" + 66 + "'", value.equals(BigInteger.valueOf( 66L ) ) );
        } else {
            value = value.longValue();
            expected = 66L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.src_sid.sat;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.src_sid.sat + "' != '" + 98 + "'", value.equals(BigInteger.valueOf( 98L ) ) );
        } else {
            value = value.longValue();
            expected = 98L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
