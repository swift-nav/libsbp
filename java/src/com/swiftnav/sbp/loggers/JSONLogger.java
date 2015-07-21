/*
 * Copyright (C) 2015 Swift Navigation Inc.
 * Contact: Gareth McMullin <gareth@swiftnav.com>
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */
package com.swiftnav.sbp.loggers;

import com.swiftnav.sbp.client.SBPCallback;
import com.swiftnav.sbp.SBPMessage;

import org.json.JSONException;
import org.json.JSONObject;

import java.io.IOException;
import java.io.OutputStream;
import java.util.Calendar;
import java.util.TimeZone;

public class JSONLogger implements SBPCallback {
    private OutputStream stream;
    private long starttime;

    public JSONLogger(OutputStream stream_) {
        stream = stream_;
        starttime = utc();
    }

    private long utc() {
        Calendar cal = Calendar.getInstance(TimeZone.getTimeZone("UTC"));
        return cal.getTimeInMillis() / 1000;
    }

    private long delta() {
        return utc() - starttime;
    }

    @Override
    public void receiveCallback(SBPMessage msg) {
        JSONObject logobj = new JSONObject();
        try {
            logobj.put("delta", delta());
            logobj.put("timestamp", utc());
            logobj.put("data", msg.toJSON());
        } catch (JSONException e) {
            e.printStackTrace();
        }

        try {
            stream.write((logobj.toString() + "\n").getBytes());
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
