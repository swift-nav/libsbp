import pusher
import pusherclient
import time

from sbp.client.drivers.pyserial_driver import PySerialDriver
from sbp.client.handler                 import Handler
from sbp.observation                    import *
from sbp.msg                            import SBP

DEFAULT_SERIAL_PORT = "/dev/ttyUSB0"
DEFAULT_SERIAL_BAUD = 1000000

def get_args():
  """
  Get and parse arguments.
  """
  import argparse
  parser = argparse.ArgumentParser(description="Swift Navigation SBP Pusher Example.")
  parser.add_argument("-a", "--app",
                      default=[None], nargs=1,
                      help="pusher app.")
  parser.add_argument("-k", "--key",
                      default=[None], nargs=1,
                      help="pusher app key.")
  parser.add_argument("-s", "--secret",
                      default=[None], nargs=1,
                      help="pusher app secret.")
  parser.add_argument("-p", "--port",
                      default=[DEFAULT_SERIAL_PORT], nargs=1,
                      help="specify the serial port to use.")
  parser.add_argument("-b", "--baud",
                      default=[DEFAULT_SERIAL_BAUD], nargs=1,
                      help="specify the baud rate to use.")
  parser.add_argument("-r", "--rx-channel-event",
                      default=[None], nargs=1,
                      help="pusher receive channel event.")
  parser.add_argument("-t", "--tx-channel-event",
                      default=[None], nargs=1,
                      help="pusher transmit channel event.")
  return parser.parse_args()

def main():
  args = get_args()
  app = args.app[0]
  key = args.key[0]
  secret = args.secret[0]
  port = args.port[0]
  baud = args.baud[0]
  rx_channel, rx_event = args.rx_channel_event[0].split(':')
  tx_channel, tx_event = args.tx_channel_event[0].split(':')
  push = pusher.Pusher(app_id=app, key=key, secret=secret, ssl=True, port=443)
  push_client = pusherclient.Pusher(key, secret=secret)
  with PySerialDriver(port, baud) as driver:
    with Handler(driver.read, driver.write) as handler:

      def push_it(sbp_msg):
        push.trigger(tx_channel, tx_event, sbp_msg.to_json_dict())

      def pull_it(data):
        handler.framer.write(SBP.from_json(data).pack())

      def connect_it(data):
        push_client.subscribe(rx_channel).bind(rx_event, pull_it)

      push_client.connection.bind('pusher:connection_established', connect_it)
      push_client.connect()

      handler.add_callback(push_it, [SBP_MSG_OBS, SBP_MSG_BASE_POS, SBP_MSG_OBS_DEP_A])

      try:
        while True:
          time.sleep(0.1)
      except KeyboardInterrupt:
        pass

if __name__ == "__main__":
  main()
