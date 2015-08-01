# Copyright (C) 2015 Swift Navigation Inc.
# Contact: Fergus Noble <fergus@swiftnav.com>
#
# This source is subject to the license found in the file 'LICENSE' which must
# be be distributed together with this source. All other rights reserved.
#
# THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
# EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.

"""
the :mod:`sbp.client.examples.tweet` module contains a basic example of
reading SBP messages from a serial port, decoding TWEET messages and pushing
them to the twitter API.
"""

from sbp.client.drivers.pyserial_driver import PySerialDriver
from sbp.client.handler import Handler, Framer
from sbp.logging import SBP_MSG_TWEET, MsgTweet

import time
import twitter

twit = None

def main():

  import argparse
  parser = argparse.ArgumentParser(description="Swift Navigation Tweetxample.")
  parser.add_argument("TOKEN")
  parser.add_argument("TOKEN_KEY")
  parser.add_argument("CON_SEC")
  parser.add_argument("CON_SEC_KEY")
  parser.add_argument("-p", "--port",
                      default=['/dev/ttyUSB0'], nargs=1,
                      help="specify the serial port to use.")
  args = parser.parse_args()

  my_auth = twitter.OAuth(args.TOKEN, args.TOKEN_KEY,
                          args.CON_SEC, args.CON_SEC_KEY)
  twit = twitter.Twitter(auth=my_auth)

  # Open a connection to Piksi using the default baud rate (1Mbaud)
  with PySerialDriver(args.port[0], baud=1000000) as driver:
    # Create a handler to connect our Piksi driver to our callbacks
    with Handler(driver.read, driver.write, verbose=True) as handler:
      try:
        for msg, metadata in handler.filter(SBP_MSG_TWEET):
          if twit is not None:
            twit.statuses.update(msg)
      except KeyboardInterrupt:
        pass

if __name__ == "__main__":
  main()

