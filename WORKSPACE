workspace(name = "root")

new_local_repository(
    name = "my-check",
    build_file = "bazel/check.BUILD",
    path = "c/third_party/check",
)

local_repository(
    name = "my-googletest",
    path = "c/third_party/googletest",
)

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "rules_foreign_cc",
    strip_prefix = "rules_foreign_cc-c65e8cfbaa002bcd1ce9c26e9fec63b0b866c94b",
    url = "https://github.com/bazelbuild/rules_foreign_cc/archive/c65e8cfbaa002bcd1ce9c26e9fec63b0b866c94b.tar.gz",
)

load("@rules_foreign_cc//foreign_cc:repositories.bzl", "rules_foreign_cc_dependencies")

rules_foreign_cc_dependencies()

# Hedron's Compile Commands Extractor for Bazel
# Used to create compile_commands.json file
http_archive(
    name = "hedron_compile_commands",
    sha256 = "4b251a482a85de6c5cb0dc34c5671e73190b9ff348e9979fa2c033d81de0f928",
    strip_prefix = "bazel-compile-commands-extractor-5bb5ff2f32d542a986033102af771aa4206387b9",
    url = "https://github.com/hedronvision/bazel-compile-commands-extractor/archive/5bb5ff2f32d542a986033102af771aa4206387b9.tar.gz",
)

load("@hedron_compile_commands//:workspace_setup.bzl", "hedron_compile_commands_setup")

hedron_compile_commands_setup()
