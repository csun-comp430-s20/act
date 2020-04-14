#!/bin/env bash

set -u

base="$(pwd)"
src="$base/src"
build="../build"
tests_tracefile="tests.info"
baseline_tracefile="baseline.info"
coverage_dir="coverage"
report_subdir="report"

rm -rf "$coverage_dir"
mkdir  "$coverage_dir" 
cd     "$coverage_dir"

# Capture baseline coverage
lcov --no-external --base-directory "$src" --capture --initial --directory "$build" --output-file "$baseline_tracefile" &&\

# Run tests
(cd "$build" && "./tests") &&\

# Capture test coverage
lcov --no-external --base-directory "$src" --capture --directory "$build" --output-file "$tests_tracefile" &&\

# Generate report
genhtml --legend --demangle-cpp --prefix $base --output-directory "$report_subdir" --baseline-file "$baseline_tracefile" "$tests_tracefile"
