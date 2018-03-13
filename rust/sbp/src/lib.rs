pub mod client;
pub mod messages;

use std::io::Read;
fn read_string(buf: &mut Read) -> String {
    let mut s = String::new();
    buf.read_to_string(&mut s).unwrap();
    s
}

fn read_string_limit(buf: &mut Read, n: u64) -> String {
    read_string(&mut buf.take(n))
}

#[cfg(test)]
mod tests {
    #[test]
    fn it_works() {
        assert_eq!(2 + 2, 4);
    }
}
