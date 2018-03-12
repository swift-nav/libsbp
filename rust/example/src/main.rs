extern crate serialport;
extern crate sbp;

use serialport::prelude::*;
use std::time::Duration;

fn main() {
    let s = SerialPortSettings {
        baud_rate: BaudRate::Baud115200,
        data_bits: DataBits::Eight,
        flow_control: FlowControl::None,
        parity: Parity::None,
        stop_bits: StopBits::One,
        timeout: Duration::from_millis(100),
    };

    let mut port = serialport::open_with_settings("/dev/ttyUSB0", &s)
        .expect("open failed");
    loop {
        match sbp::client::framer::receive(&mut port) {
            Ok(x) => {
                println!("id = {}, sender = {}", x.msg_id, x.sender);
                println!("{:?}\n", x.payload);
            },
            Err(e) => {
                println!("{:?}", e);
            }
        }
    }
}
