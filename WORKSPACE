workspace(name = "root")

new_local_repository(
    name = "my-check",
    build_file = "bazel/check.BUILD",
    path = "c/third_party/check",
)

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "rules_foreign_cc",
    strip_prefix = "rules_foreign_cc-c65e8cfbaa002bcd1ce9c26e9fec63b0b866c94b",
    url = "https://github.com/bazelbuild/rules_foreign_cc/archive/c65e8cfbaa002bcd1ce9c26e9fec63b0b866c94b.tar.gz",
)

load("@rules_foreign_cc//foreign_cc:repositories.bzl", "rules_foreign_cc_dependencies")

rules_foreign_cc_dependencies()

