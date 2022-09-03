fn main() {
    use vergen::{generate_cargo_keys, ConstantsFlags};
    let flags = ConstantsFlags::all();
    generate_cargo_keys(flags).expect("Unable to generate the cargo keys!");
}
