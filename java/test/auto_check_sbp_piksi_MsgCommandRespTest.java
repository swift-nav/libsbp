/* Copyright (C) 2015-2022 Swift Navigation Inc.
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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/piksi/test_MsgCommandResp.yaml by
// generate.py. Do not modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.piksi.MsgCommandResp;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_piksi_MsgCommandRespTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_piksi_MsgCommandRespTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 118,
                    (byte) 215,
                    (byte) 131,
                    (byte) 160,
                    (byte) 210,
                    (byte) 110,
                    (byte) 150,
                    (byte) 103,
                };
        SBPMessage sbp = new SBPMessage(0xce39, 0xb9, payload);
        MsgCommandResp msg = new MsgCommandResp(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        value = msg.code;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.code + "' != '" + 1737912018 + "'",
                    value.equals(BigInteger.valueOf(1737912018L)));
        } else {
            value = value.longValue();
            expected = 1737912018L;
            org.junit.Assert.assertEquals(value, expected);
        }
        value = msg.sequence;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sequence + "' != '" + 2692994934L + "'",
                    value.equals(new BigInteger("2692994934")));
        } else {
            value = value.longValue();
            expected = 2692994934L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
