#!/bin/bash

set -e

OPEN_REPORT=false
TARGETS=()

while [[ $# -gt 0 ]]; do
    case $1 in
        --open)
            OPEN_REPORT=true
            shift
            ;;
        --html)
            HTML_REPORT=true
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

if [[ "$OPEN_REPORT" == true && "$HTML_REPORT" == false ]]; then
    echo "Error: --open requires --html to be set" >&2
    exit 1
fi

echo "Generating coverage report..."

bazel coverage "${TARGETS[@]}"

if [[ "$HTML_REPORT" == true ]]; then
    echo "Generating HTML coverage report..."
    bazel run @lcov//:genhtml -- \
        --output "$(pwd)/code_coverage_html" \
        --source-directory="$(pwd)" \
        --branch-coverage \
        --ignore-errors inconsistent,gcov,unsupported,format,category,count,unused \
        --no-function-coverage \
        --filter brace,blank \
        --flat \
        --legend \
        --quiet \
        --title="Code Coverage Report" \
        "$(bazel info output_path)/_coverage/_coverage_report.dat"

    echo "Coverage report generated in code_coverage_html/"
fi

if [[ "$OPEN_REPORT" == true ]]; then
    if [[ "$OSTYPE" == "darwin"* ]]; then
        open "$(pwd)/code_coverage_html/index.html"
    elif [[ "$OSTYPE" == "linux-gnu"* ]]; then
        xdg-open "$(pwd)/code_coverage_html/index.html"
    else
        echo "Coverage report available at: $(pwd)/code_coverage_html/index.html"
    fi
fi
