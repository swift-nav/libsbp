//! An example for how to parse SBP from a serial port
//!
//! Note that this example requires that you have `libudev` installed
//! before you can compile it

use std::time::Duration;

use serialport::prelude::*;

use sbp::{iter_messages, Sbp};

fn main() {
    let s = SerialPortSettings {
        baud_rate: BaudRate::Baud115200,
        data_bits: DataBits::Eight,
        flow_control: FlowControl::None,
        parity: Parity::None,
        stop_bits: StopBits::One,
        timeout: Duration::from_millis(1000),
    };

    let mut port = serialport::open_with_settings("/dev/ttyUSB0", &s).expect("open failed");

    for msg in iter_messages(&mut port) {
        match msg {
            Ok(Sbp::MsgLog(x)) => println!("{}", x.text),
            Ok(Sbp::MsgPosLlh(x)) => println!("{} {} {}", x.lat, x.lon, x.height),
            Err(e) => {
                eprintln!("{:?}", e);
                break;
            }
            _ => {}
        }
    }
}
