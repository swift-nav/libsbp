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
package com.swiftnav.sbp.drivers;


import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.IOException;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.URL;

public class SBPDriverHTTP extends SBPDriverStream {
    private final URL url;
    private final String uid;

    public SBPDriverHTTP(String uid_, String url_) throws MalformedURLException {
        url = new URL(url_);
        uid = uid_;
    }

    @Override
    protected void openStream() throws IOException {

        System.out.println("Connecting to " + url.toString());

        HttpURLConnection http = (HttpURLConnection) url.openConnection();
        // http.setDoOutput(true);
        // http.setChunkedStreamingMode(200);
        http.setRequestProperty("Device-Uid", uid);
        http.setRequestProperty("Accept", "application/vnd.swiftnav.broker.v1+sbp2");
        // http.setRequestProperty("Content-Type", "application/sbp");

        http.connect();
        System.out.println("" + http.getResponseCode() + " " + http.getResponseMessage());

        if (http.getDoOutput()) {
            out = new BufferedOutputStream(http.getOutputStream());
            System.out.println(out.toString());
        }
        if (http.getDoInput()) {
            in = new BufferedInputStream(http.getInputStream());
            System.out.println(in.toString());
        }
    }
}
