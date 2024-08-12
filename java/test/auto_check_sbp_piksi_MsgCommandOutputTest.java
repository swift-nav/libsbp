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

// This file was auto-generated from spec/tests/yaml/swiftnav/sbp/piksi/test_MsgCommandOutput.yaml
// by generate.py. Do not modify by hand!


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.piksi.MsgCommandOutput;
import java.math.BigInteger;
import org.json.JSONObject;
import org.junit.Test;

public class auto_check_sbp_piksi_MsgCommandOutputTest {

    public static boolean debug = false;
    private static final double DELTA = 1e-15;

    @Test
    public void test1() throws Throwable {
        if (debug) System.out.format("%n%s%n", "auto_check_sbp_piksi_MsgCommandOutputTest.test1");
        byte[] payload =
                new byte[] {
                    (byte) 126, (byte) 164, (byte) 116, (byte) 149, (byte) 83, (byte) 111,
                    (byte) 109, (byte) 101, (byte) 32, (byte) 111, (byte) 117, (byte) 116,
                    (byte) 112, (byte) 117, (byte) 116, (byte) 32, (byte) 116, (byte) 101,
                    (byte) 120, (byte) 116,
                };
        SBPMessage sbp = new SBPMessage(0x5432, 0xbc, payload);
        MsgCommandOutput msg = new MsgCommandOutput(sbp);
        JSONObject json = msg.toJSON();
        Number value;
        Number expected;
        org.junit.Assert.assertEquals(msg.line, "Some output text");
        value = msg.sequence;
        if (value instanceof BigInteger) {
            org.junit.Assert.assertTrue(
                    "'" + msg.sequence + "' != '" + 2507449470L + "'",
                    value.equals(new BigInteger("2507449470")));
        } else {
            value = value.longValue();
            expected = 2507449470L;
            org.junit.Assert.assertEquals(value, expected);
        }

        org.junit.Assert.assertNotEquals("", msg.getFriendlyName());
    }
}
