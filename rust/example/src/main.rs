extern crate serialport;
extern crate sbp;

use serialport::prelude::*;
use std::time::Duration;
use sbp::messages::SBP;
use sbp::Error;

fn main() {
    let s = SerialPortSettings {
        baud_rate: BaudRate::Baud115200,
        data_bits: DataBits::Eight,
        flow_control: FlowControl::None,
        parity: Parity::None,
        stop_bits: StopBits::One,
        timeout: Duration::from_millis(1000),
    };

    let mut port = serialport::open_with_settings("/dev/ttyUSB0", &s)
        .expect("open failed");

    loop {
        match sbp::client::parser::parse(&mut port) {
            Ok(SBP::MsgLog(x)) =>
                println!("{}", x.text),
            Ok(SBP::MsgPosLLH(x)) =>
                println!("{} {} {}", x.lat, x.lon, x.height),
            Ok(_) => (),

            Err(Error::InvalidPreamble) => (),
            Err(Error::CRCMismatch) => (),
            Err(Error::ParseError) => (),
            Err(Error::IoError(ref x)) if x.kind() == std::io::ErrorKind::TimedOut => (),

            Err(e) => {
                println!("{:?}", e);
                break;
            }
        }
    }
}
