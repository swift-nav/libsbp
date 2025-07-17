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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/flash/test_MsgStmUniqueIdResp.yaml by generate.py. Do not modify by hand!

import java.math.BigInteger;

import org.junit.Test;

import org.json.JSONObject;

import com.swiftnav.sbp.SBPMessage;

import com.swiftnav.sbp.flash.MsgStmUniqueIdResp;


public class auto_check_sbp_flash_MsgStmUniqueIdRespTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug)
            System.out.format("%n%s%n", "auto_check_sbp_flash_MsgStmUniqueIdRespTest.test1");
        byte[] payload = new byte[] {(byte)196,(byte)16,(byte)15,(byte)163,(byte)85,(byte)221,(byte)119,(byte)102,(byte)32,(byte)194,(byte)56,(byte)144, };
        SBPMessage sbp = new SBPMessage( 0x04c3, 0xe5, payload );
        MsgStmUniqueIdResp msg = new MsgStmUniqueIdResp( sbp );
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.stm_id[0];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stm_id[0] + "' != '" + 196 + "'", value.equals(BigInteger.valueOf( 196L ) ) );
        } else {
            value = value.longValue();
            expected = 196L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stm_id[1];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stm_id[1] + "' != '" + 16 + "'", value.equals(BigInteger.valueOf( 16L ) ) );
        } else {
            value = value.longValue();
            expected = 16L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stm_id[2];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stm_id[2] + "' != '" + 15 + "'", value.equals(BigInteger.valueOf( 15L ) ) );
        } else {
            value = value.longValue();
            expected = 15L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stm_id[3];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stm_id[3] + "' != '" + 163 + "'", value.equals(BigInteger.valueOf( 163L ) ) );
        } else {
            value = value.longValue();
            expected = 163L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stm_id[4];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stm_id[4] + "' != '" + 85 + "'", value.equals(BigInteger.valueOf( 85L ) ) );
        } else {
            value = value.longValue();
            expected = 85L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stm_id[5];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stm_id[5] + "' != '" + 221 + "'", value.equals(BigInteger.valueOf( 221L ) ) );
        } else {
            value = value.longValue();
            expected = 221L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stm_id[6];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stm_id[6] + "' != '" + 119 + "'", value.equals(BigInteger.valueOf( 119L ) ) );
        } else {
            value = value.longValue();
            expected = 119L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stm_id[7];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stm_id[7] + "' != '" + 102 + "'", value.equals(BigInteger.valueOf( 102L ) ) );
        } else {
            value = value.longValue();
            expected = 102L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stm_id[8];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stm_id[8] + "' != '" + 32 + "'", value.equals(BigInteger.valueOf( 32L ) ) );
        } else {
            value = value.longValue();
            expected = 32L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stm_id[9];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stm_id[9] + "' != '" + 194 + "'", value.equals(BigInteger.valueOf( 194L ) ) );
        } else {
            value = value.longValue();
            expected = 194L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stm_id[10];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stm_id[10] + "' != '" + 56 + "'", value.equals(BigInteger.valueOf( 56L ) ) );
        } else {
            value = value.longValue();
            expected = 56L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.stm_id[11];
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue("'" + msg.stm_id[11] + "' != '" + 144 + "'", value.equals(BigInteger.valueOf( 144L ) ) );
        } else {
            value = value.longValue();
            expected = 144L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
