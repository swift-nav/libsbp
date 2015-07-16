import pusher
import time

from sbp.client.drivers.pyserial_driver import PySerialDriver
from sbp.client.handler                 import Handler
from sbp.observation                    import SBP_MSG_OBS, SBP_MSG_BASE_POS

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
  parser.add_argument("-c", "--channel",
                      default=[None], nargs=1,
                      help="pusher channel.")
  return parser.parse_args()

def main():
  args = get_args()
  app = args.app[0]
  key = args.key[0]
  secret = args.secret[0]
  port = args.port[0]
  baud = args.baud[0]
  channel = args.channel[0]
  push = pusher.Pusher(app_id=app, key=key, secret=secret, ssl=True, port=443)
  with PySerialDriver(port, baud) as driver:
    with Handler(driver.read, driver.write) as handler:

      def pushit(sbp_msg):
        try:
          push.trigger(channel, str(sbp_msg.msg_type), sbp_msg.to_json_dict())
        except:
          import traceback
          traceback.print_exc()

      handler.add_callback(pushit, [SBP_MSG_OBS, SBP_MSG_BASE_POS])

      try:
        while True:
          time.sleep(0.1)
      except KeyboardInterrupt:
        pass

if __name__ == "__main__":
  main()
