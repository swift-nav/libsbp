//! An example for how to parse SBP from a serial port
//!
//! Note that this example requires that you have `libudev` installed
//! before you can compile it

use std::time::Duration;

use sbp::{Sbp, iter_messages};

fn main() {
    let mut port = serialport::new("/dev/ttyUSB0", 115200)
        .data_bits(serialport::DataBits::Eight)
        .flow_control(serialport::FlowControl::None)
        .parity(serialport::Parity::None)
        .stop_bits(serialport::StopBits::One)
        .timeout(Duration::from_millis(1000))
        .open()
        .expect("open failed");

    for msg in iter_messages(&mut port) {
        match msg {
            Ok(Sbp::MsgLog(x)) => println!("{}", x.text),
            Ok(Sbp::MsgPosLlh(x)) => println!("{} {} {}", x.lat, x.lon, x.height),
            Err(e) => {
                eprintln!("{e:?}");
                break;
            }
            _ => {}
        }
    }
}
