do-all-unit-tests:
	bazel test --test_tag_filters=unit --test_output=all //...

do-all-integration-tests:
	bazel test --test_tag_filters=integration --test_output=all //...

clang-tidy-all-check:
	bazel build //... --config=clang-tidy

do-code-coverage:
	bazel coverage --test_tag_filters=unit --collect_code_coverage --combined_report=lcov //...

do-generate-coverage-report: do-code-coverage
	genhtml bazel-out/_coverage/_coverage_report.dat -o coverage
