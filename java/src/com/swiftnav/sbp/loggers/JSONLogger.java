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

import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.client.SBPSender;

import org.json.JSONException;
import org.json.JSONObject;

import java.io.IOException;
import java.io.OutputStream;
import java.util.Calendar;
import java.util.Date;
import java.util.TimeZone;
import java.text.DateFormat;
import java.text.SimpleDateFormat;


public class JSONLogger implements SBPSender {
    private OutputStream stream;

    public JSONLogger(OutputStream stream_) {
        stream = stream_;
    }

    private String ISOTimestamp() {
        // http://stackoverflow.com/questions/1459656/how-to-get-the-current-time-in-yyyy-mm-dd-hhmisec-millisecond-format-in-java?rq=1
        // http://stackoverflow.com/questions/3914404/how-to-get-current-moment-in-iso-8601-format
        TimeZone tz = TimeZone.getTimeZone("UTC");
        DateFormat df = new SimpleDateFormat("yyyy-MM-dd'T'HH:mm:ss.SSS'Z'");
        df.setTimeZone(tz);
        String asISO = df.format(new Date());
        return asISO;
    }

    @Override
    public void sendMessage(SBPMessage msg) throws IOException {
        JSONObject logobj = new JSONObject();
        try {
            logobj.put("time", ISOTimestamp());
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
