"Define linter aspects"

load("@aspect_rules_lint//lint:clang_tidy.bzl", "lint_clang_tidy_aspect")
load("@aspect_rules_lint//lint:lint_test.bzl", "lint_test")

clang_tidy = lint_clang_tidy_aspect(
    binary = Label("//tools/lint:clang_tidy"),
    global_config = [
        Label("//:clang_tidy_config"),
    ],
    lint_target_headers = True,
    angle_includes_are_system = True,
    verbose = False,
    rule_kinds = ["cc_binary", "cc_library", "cc_test"],
)
clang_tidy_test = lint_test(aspect = clang_tidy)
