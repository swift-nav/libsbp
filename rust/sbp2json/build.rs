//! Makes the git tag/version available at build time via `VERGEN_GIT_DESCRIBE`.

use std::env;

use vergen_gitcl::{Emitter, Gitcl};

fn main() {
    // Hermetic/sandboxed builds (e.g. Bazel) have no git available and instead
    // inject the version directly via the VERGEN_GIT_DESCRIBE env var. Honour it
    // and skip running git entirely in that case.
    println!("cargo:rerun-if-env-changed=VERGEN_GIT_DESCRIBE");
    if let Some(describe) = env::var_os("VERGEN_GIT_DESCRIBE") {
        println!(
            "cargo:rustc-env=VERGEN_GIT_DESCRIBE={}",
            describe.to_string_lossy()
        );
        return;
    }

    // `git describe --tags --dirty` (lightweight tags included) -> VERGEN_GIT_DESCRIBE.
    let gitcl = Gitcl::builder().describe(true, true, None).build();

    Emitter::default()
        .add_instructions(&gitcl)
        .expect("Unable to add git instructions")
        .emit()
        .expect("Unable to emit instructions");
}
