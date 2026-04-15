#!/usr/bin/env bash

set -euo pipefail

CREATE_PATCHES=false
APPLY_PATCHES=false

while [[ $# -gt 0 ]]; do
    case $1 in
        --create-patches)
            CREATE_PATCHES=true
            shift
            ;;
        --apply-patches)
            CREATE_PATCHES=true
            APPLY_PATCHES=true
            shift
            ;;
        --targets)
            shift
            while [[ $# -gt 0 && ! "$1" =~ ^-- ]]; do
                TARGETS+=("$1")
                shift
            done
            ;;
        *)
            echo "Unknown option: $1"
            exit 1
            ;;
    esac
done

# Set default targets if none provided
if [[ ${#TARGETS[@]} -eq 0 ]]; then
    TARGETS=("//...")
fi

buildevents=$(mktemp)
echo "Build events in $buildevents"

# NB: perhaps --remote_download_toplevel is needed as well with remote execution?
args+=(
    "--build_event_json_file=$buildevents"
    # Required for the buf allow_comment_ignores option to work properly
    # See https://github.com/bufbuild/rules_buf/issues/64#issuecomment-2125324929
    "--experimental_proto_descriptor_sets_include_source_info"
    "--remote_download_regex='.*AspectRulesLint.*'"
    "--config=lint"
    "--output_groups=rules_lint_machine"
    "--keep_going"
)

if [[ "$CREATE_PATCHES" == true ]]; then
    fix="patch"
    args+=(
        "--@aspect_rules_lint//lint:fix"
        "--output_groups=rules_lint_patch"
    )
fi

# Run linters
bazel build ${args[@]} "${TARGETS[@]}"

OUTPUT_DIR="$(pwd)/clang-tidy-output"
OUTPUT_DIR_MERGED_SARIF="$OUTPUT_DIR/merged-report.sarif"
OUTPUT_DIR_PATCHES="$OUTPUT_DIR/patches"

EXIT_CODE=0
bazel run @rules_swiftnav//tools/lint:extract_lint_results -- \
  --build-event-json-file=$buildevents --bazel-output-path="$(pwd)" \
  --output-merged-sarif-file="$OUTPUT_DIR_MERGED_SARIF" \
  --output-patch-folder="$OUTPUT_DIR_PATCHES" \
  --exit-code=1 || EXIT_CODE=$?

if [[ "$APPLY_PATCHES" == true ]]; then
    for patch in "$OUTPUT_DIR_PATCHES"/*.patch; do
        if [[ -f "$patch" ]]; then
            patch -p1 <"$patch"
        fi
    done
fi

exit $EXIT_CODE
