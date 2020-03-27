use std::boxed::Box;
use std::fs::File;
use std::io::prelude::*;
use std::rc::Rc;

use sha2::{Sha256, Digest};

mod common;
use common::find_project_root;

use sbp::sbp2json::json2sbp_read_loop;
use sbp::sbp2json::sbp2json_read_loop;
use sbp::sbp2json::Result;

#[test]
fn test_sbp2json() -> Result<()> {
    let root = find_project_root().unwrap();
    let root = root.as_path();
    let input_path = root.join("test_data/roundtrip.sbp");
    let output_path = root.join("test_data/test_sbp2json.output.json");

    {
        let mut input_file = File::open(input_path)?;
        let output_file = File::create(output_path)?;

        let mut output_file: Rc<Box<dyn Write>> = Rc::new(Box::new(output_file));

        sbp2json_read_loop(false, false, false, &mut input_file, &mut output_file)?;

        let input_path = root.join("test_data/test_sbp2json.output.json");
        let output_path = root.join("test_data/test_sbp2json.output.sbp");

        let mut input_file = File::open(input_path)?;
        let output_file = File::create(output_path)?;

        let mut output_file: Rc<Box<dyn Write>> = Rc::new(Box::new(output_file));

        json2sbp_read_loop(false, &mut input_file, &mut output_file)?;
    }

    let input_path = root.join("test_data/roundtrip.sbp");
    let output_path = root.join("test_data/test_sbp2json.output.sbp");

    let mut input_file = File::open(input_path)?;
    let mut output_file = File::open(output_path)?;

    let mut input_file_hash = Sha256::new();
    let mut output_file_hash = Sha256::new();

    std::io::copy(&mut input_file, &mut input_file_hash).map(|_|())?;
    std::io::copy(&mut output_file, &mut output_file_hash).map(|_|())?;

    let input_digest = input_file_hash.result();
    let output_digest = output_file_hash.result();

    eprintln!(" input: {}", hex::encode(&input_digest[..]));
    eprintln!("output: {}", hex::encode(&output_digest[..]));

    assert_eq!(input_digest, output_digest);

    Ok(())
}
