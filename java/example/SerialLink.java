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
import com.swiftnav.sbp.client.SBPFramer;
import com.swiftnav.sbp.client.SBPHandler;
import com.swiftnav.sbp.drivers.SBPDriverJSSC;
import com.swiftnav.sbp.logging.MsgLog;
import com.swiftnav.sbp.navigation.MsgPosLLH;
import jssc.SerialPortException;

public class SerialLink {
  private SBPHandler handler;
  private SBPFramer framer;
  private String[] fix_type = new String[8];

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

  private void populate_fix_type() {
    fix_type[0] = "No fix";
    fix_type[1] = "SPP";
    fix_type[2] = "DGPS";
    fix_type[3] = "float";
    fix_type[4] = "fixed";
    fix_type[5] = "DR";
    fix_type[6] = "SBAS";
    fix_type[7] = "UNKNOWN";
  }

  public static void usage() {
    System.out.println("usage: SerialLink <port> [baudrate]");
    System.exit(-1);
  }

  SerialLink(String port) {
    this(port, SBPDriverJSSC.BAUDRATE_DEFAULT);
  }

  SerialLink(String port, int baudrate) {
    populate_fix_type();
    try {
      framer = new SBPFramer(new SBPDriverJSSC(port, baudrate));
      handler = new SBPHandler(framer);
      handler.start();
    } catch (SerialPortException e) {
      System.err.println("Failed to open serial port: " + e.toString());
      System.exit(-2);
    }
    for (SBPMessage msg : handler) {
      switch (msg.type) {
        case MsgLog.TYPE:
          logHandler(msg);
          break;
        case MsgPosLLH.TYPE:
          llhHandler(msg);
          break;
      }
    }
  }

  public void logHandler(SBPMessage msg_) {
    MsgLog msg = (MsgLog) msg_;
    System.out.print(msg.text);
  }

  public void llhHandler(SBPMessage msg_) {
    MsgPosLLH msg = (MsgPosLLH) msg_;
    int fix_type = msg.flags & 0x7;
    System.out.printf(
        "POSLLH message received -- fix_type: %s, tow [ms]: %d", this.fix_type[fix_type], msg.tow);
    if (fix_type != 0) {
      System.out.printf(
          ", lat[deg]: %f, lon[deg]: %f, ellipsoid alt[m]: %f, horizontal accuracy[m]: %f, vertical_accuracy[m]: %f, n_sats: %d",
          msg.lat,
          msg.lon,
          msg.height,
          msg.h_accuracy / 1000.0,
          msg.v_accuracy / 1000.0,
          msg.n_sats);
    }
    System.out.println();
  }
}
