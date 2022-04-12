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
package com.swiftnav.sbp.examples;


import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.client.SBPFramer;
import com.swiftnav.sbp.client.SBPHandler;
import com.swiftnav.sbp.drivers.SBPDriverTCP;
import com.swiftnav.sbp.navigation.MsgPosLLH;

public class TCPExample {

    public static void main(String[] args) {
        if (args.length != 2) {
            System.out.println("usage: TCPExample <server> <port>");
            return;
        }
        String server = args[0];
        int port = Integer.parseInt(args[1]);
        new TCPExample().start(server, port);
    }

    public void start(String server, int port) {
        SBPFramer framer = new SBPFramer(new SBPDriverTCP(server, port));
        SBPHandler handler = new SBPHandler(framer);
        handler.start();

        for (SBPMessage msg : handler) {
            if (msg.type == MsgPosLLH.TYPE) {
                MsgPosLLH posLLH = ((MsgPosLLH) msg);
                System.out.printf("%s %s%n", posLLH.lat, posLLH.lon);
            }
        }
    }
}
