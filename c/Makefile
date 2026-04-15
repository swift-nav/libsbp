do-all-unit-tests:
	bazel test --test_tag_filters=unit --test_output=all //...

do-all-integration-tests:
	bazel test --test_tag_filters=integration --test_output=all //...

clang-tidy-all-check:
	bazel build //... --config=clang-tidy

do-code-coverage:
	cd .. && uv run ./scripts/generate_code_coverage.sh

do-generate-coverage-report:
	cd .. && uv run ./scripts/generate_code_coverage.sh --html

gen-compile-commands:
	bazel run //tools/compile_commands:gen_compile_commands
