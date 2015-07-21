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
import com.swiftnav.sbp.SBPMessage;
import com.swiftnav.sbp.client.SBPCallback;
import com.swiftnav.sbp.client.SBPHandler;
import com.swiftnav.sbp.drivers.SBPDriverJSSC;
import com.swiftnav.sbp.loggers.JSONLogger;
import com.swiftnav.sbp.logging.MsgLog;
import com.swiftnav.sbp.tracking.MsgTrackingState;
import com.swiftnav.sbp.tracking.TrackingChannelState;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.lang.Integer;
import java.lang.NumberFormatException;
import java.lang.System;
import java.util.Calendar;

import jssc.SerialPortException;

public class SerialLink {
    private SBPHandler handler;

    public static void main(String[] args) {
        if (args.length == 1) {
            new SerialLink(args[0]);
        } else if (args.length == 2) {
            int baudrate = 0;
            try {
                baudrate = Integer.parseInt(args[1]);
            } catch (NumberFormatException e) {
                usage();
            }
            new SerialLink(args[0], baudrate);
        } else {
            usage();
        }
    }

    public static void usage() {
        System.out.println("usage: SerialLink <port> [baudrate]");
        System.exit(-1);
    }

    SerialLink(String port) {
        this(port, SBPDriverJSSC.BAUDRATE_DEFAULT);
    }
    SerialLink(String port, int baudrate) {
        try {
            handler = new SBPHandler(new SBPDriverJSSC(port, baudrate));
        } catch (SerialPortException e) {
            System.err.println("Failed to open serial port: " + e.toString());
            System.exit(-2);
        }
        handler.addCallback(MsgLog.TYPE, logHandler);
        handler.addCallback(MsgTrackingState.TYPE, trackingHandler);
        try {
            Calendar cal = Calendar.getInstance();
            String logfile = String.format("serial-link-%1$tY%1$tm%1$td-%1$tH%1$tM%1$tS.log.json", cal);
            handler.addCallback(new JSONLogger(new FileOutputStream(logfile)));
        } catch (FileNotFoundException e) {
            System.err.println("Error opening logfile: " + e.toString());
        }
        handler.start();
    }

    SBPCallback logHandler = new SBPCallback() {
        @Override
        public void receiveCallback(SBPMessage msg_) {
            MsgLog msg = (MsgLog)msg_;
            System.out.print(msg.text);
        }
    };

    SBPCallback trackingHandler = new SBPCallback() {
        @Override
        public void receiveCallback(SBPMessage msg_) {
            MsgTrackingState msg = (MsgTrackingState)msg_;
            
            boolean tracking = false;
            for (TrackingChannelState state : msg.states)
                if (state.state != 0)
                    tracking = true;
            if (!tracking)
                return;

            System.out.print("Tracking: ");
            for (TrackingChannelState state : msg.states) {
                if (state.state != 0)
                    System.out.printf("PRN%d(%.1f) ", state.sid + 1, state.cn0);
            }
            System.out.println();
        }
    };
}
