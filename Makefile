# Convenience Makefile for generating and releasing SBP client
# libraries. Please read and understand the contents of this file
# before using it to do Crazy Things.

SHELL := /bin/bash
SWIFTNAV_ROOT := $(CURDIR)
MAKEFLAGS += SWIFTNAV_ROOT=$(SWIFTNAV_ROOT)
SBP_SPEC_DIR := $(SWIFTNAV_ROOT)/spec/yaml/swiftnav/sbp/
SBP_TESTS_SPEC_DIR := $(SWIFTNAV_ROOT)/spec/tests/yaml/

GENENV ?= py  # the system's default python version
SBP_GEN_BIN := tox -e $(GENENV) --

SBP_TOX_PARALLEL ?= 0

SBP_VERSION := $(shell git describe --match 'v*' --always --tags)
SBP_VERSION_UNPREFIXED := $(shell echo $(SBP_VERSION) | sed 's/^v//')
SBP_STAGING := $(shell git describe --match 'libsbp-staging*' --always --tags | grep -q '^libsbp-staging' && echo 1 || echo 0)

CHANGELOG_MAX_ISSUES := 100

.PHONY: help test release dist clean all docs pdf html c deps-c gen-c test-c python deps-python gen-python test-python javascript deps-javascript gen-javascript test-javascript java deps-java gen-java test-java haskell deps-haskell gen-haskell test-haskell haskell deps-protobuf gen-protobuf test-protobuf verify-prereq-generator verify-prereq-c verify-prereq-javascript verify-prereq-python verify-prereq-java verify-prereq-haskell verify-prereq-protobuf mapping rust deps-rust gen-rust test-rust deps-jsonschema gen-jsonschema test-jsonschema verify-prereq-jsonschema deps-quicktype-typescript gen-quicktype-typescript test-quicktype-typescript verify-prereq-quicktype-typescript deps-quicktype-javascript gen-quicktype-javascript test-quicktype-javascript verify-prereq-quicktype-javascript deps-quicktype-elm gen-quicktype-elm test-quicktype-elm verify-prereq-quicktype-elm

# Functions
define announce-begin
	@echo
	@echo "$1 ..."
	@echo
endef

define announce-end
	@echo
	@echo "$1"
	@echo
endef

# Help!
help:
	@echo
	@echo "Helper for generating and releasing SBP client libraries."
	@echo
	@echo "(Please read before using!)"
	@echo
	@echo "Please use \`make <target>' where <target> is one of"
	@echo "  help         to display this help message"
	@echo "  all          to make SBP clients across all languages"
	@echo "  clean        to remove any output files"
	@echo "  c            to make C headers"
	@echo "  dist         to distribute packages"
	@echo "  docs         to make HTML and pdf documentation"
	@echo "  html         to make all HTML language docs"
	@echo "  pdf          to make SBP LaTeX datasheet"
	@echo "  python       to make Python bindings"
	@echo "  haskell      to make Haskell bindings"
	@echo "  java         to make Java bindings"
	@echo "  rust         to make Rust bindings"
	@echo "  protobuf     to make Protocol Buffer bindings"
	@echo "  jsonschema   to make JSON Schema definitions"
	@echo "  release      to handle some release tasks"
	@echo "  test         to run all tests"
	@echo
	@echo "JSON Schema specific targets:"
	@echo "  quicktype-typescript   generate TypeScript module from JSON Schema"
	@echo "  quicktype-javascript   generate JavaScript module from JSON Schema"
	@echo "  quicktype-elm          generate Elm module from JSON Schema"
	@echo

packaged-languages: c python haskell rust javascript

non-packaged-languages: java protobuf jsonschema quicktype

all: packaged-languages docs non-packaged-languages

clean:
	@echo "Removing the ./c/build directory..."
	rm -fr $(SWIFTNAV_ROOT)/c/build
	@echo "Removing the ./python/docs/build directory..."
	rm -fr $(SWIFTNAV_ROOT)/python/docs/build
	@echo "Removing ./latex/sbp_out.* ..."
	rm -f $(SWIFTNAV_ROOT)/latex/sbp_out.*
docs: verify-prereq-docs pdf html

c:          deps-c          gen-c          test-c
python:     deps-python     gen-python     test-python
javascript: deps-javascript gen-javascript test-javascript bundle-javascript
java:       deps-java       gen-java       test-java       java-examples
haskell:    deps-haskell    gen-haskell    test-haskell
rust:       deps-rust       gen-rust       test-rust
protobuf:   deps-protobuf   gen-protobuf   test-protobuf
jsonschema: deps-jsonschema gen-jsonschema test-jsonschema

quicktype-typescript: deps-quicktype-typescript gen-quicktype-typescript test-quicktype-typescript
quicktype-javascript: deps-quicktype-javascript gen-quicktype-javascript test-quicktype-javascript
quicktype-elm:        deps-quicktype-elm        gen-quicktype-elm        test-quicktype-elm
quicktype:            quicktype-typescript      quicktype-javascript     quicktype-elm

# Prerequisite verification
verify-prereq-generator:
ifeq ($(OS), Windows_NT)
	@python --version 1> nul 2> nul || (echo I require `python` but it's not installed. Aborting. & echo. & echo. & echo Have you installed Python? & echo. & exit 1)
	@pip --version 1> nul 2> nul || (echo I require `pip` but it's not installed. Aborting. & echo. & echo. & echo Have you installed pip? & echo. & exit 1)
else
	@command -v python 1>/dev/null 2>/dev/null || { echo >&2 -e "I require \`python\` but it's not installed. Aborting.\n\nHave you installed Python?\n"; exit 1; }
	@command -v pip    1>/dev/null 2>/dev/null || { echo >&2 -e "I require \`pip\` but it's not installed.  Aborting.\n\nHave you installed pip?\n"; exit 1; }
endif

verify-prereq-c: verify-prereq-generator
	@command -v clang-format-6.0 1>/dev/null 2>/dev/null || { echo >&2 -e "I require \`clang-format-6.0\` but it's not installed. Aborting.\n\nHave you installed clang-format-6.0? See the C readme at \`c/README.md\` for setup instructions.\n"; exit 1; }
	@command -v checkmk      1>/dev/null 2>/dev/null || { echo >&2 -e "I require \`checkmk\` but it's not installed. Aborting.\n\nHave you installed checkmk? See the C readme at \`c/README.md\` for setup instructions.\n"; exit 1; }
	@command -v cmake        1>/dev/null 2>/dev/null || { echo >&2 -e "I require \`cmake\` but it's not installed. Aborting.\n\nHave you installed cmake? See the C readme at \`c/README.md\` for setup instructions.\n"; exit 1; }
	@command -v pkg-config   1>/dev/null 2>/dev/null || { echo >&2 -e "I require \`pkg-config\` but it's not installed. Aborting.\n\nHave you installed pkg-config? See the C readme at \`c/README.md\` for setup instructions.\n"; exit 1; }
	@command -v doxygen      1>/dev/null 2>/dev/null || { echo >&2 -e "I require \`doxygen\` but it's not installed. Aborting.\n\nHave you installed doxygen? See the C readme at \`c/README.md\` for setup instructions.\n"; exit 1; }

verify-prereq-python: verify-prereq-generator
	@command -v python 1>/dev/null 2>/dev/null || { echo >&2 -e "I require \`python\` but it's not installed. Aborting.\n\nHave you installed Python? See the Python readme at \`python/README.rst\` for setup instructions.\n"; exit 1; }
	@command -v pip 1>/dev/null 2>/dev/null    || { echo >&2 -e "I require \`pip\` but it's not installed. Aborting.\n\nHave you installed pip? See the Python readme at \`python/README.rst\` for setup instructions.\n"; exit 1; }
	@command -v tox 1>/dev/null 2>/dev/null    || { echo >&2 -e "I require \`tox\` but it's not installed. Aborting.\n\nHave you installed tox? See the Python readme at \`python/README.rst\` for setup instructions.\n"; exit 1; }

verify-prereq-javascript: verify-prereq-generator
	@command -v node   1>/dev/null 2>/dev/null || { echo >&2 -e "I require \`node\` but it's not installed. Aborting.\n\nHave you installed Node.js? See the JavaScript readme at \`javascript/README.md\` for setup instructions.\n"; exit 1; }
	@command -v npm    1>/dev/null 2>/dev/null || { echo >&2 -e "I require \`npm\` but it's not installed. Aborting.\n\nHave you installed NPM? See the JavaScript readme at \`javascript/README.md\` for setup instructions.\n"; exit 1; }
	@command -v mocha  1>/dev/null 2>/dev/null || { echo >&2 -e "I require \`mocha\` but it's not installed. Aborting.\n\nHave you installed mocha? See the JavaScript readme at \`javascript/README.md\` for setup instructions.\n"; exit 1; }

verify-prereq-java: verify-prereq-generator
ifeq ($(OS), Windows_NT)
	@gradle --version 1> nul 2> nul || (echo I require `gradle` but it's not installed. Aborting. & echo. & echo. & echo Have you installed gradle? See the Java readme at `java/README.rst` for setup instructions. & echo. & exit 1)
else
	@command -v gradle  1>/dev/null 2>/dev/null || { echo >&2 -e "I require \`gradle\` but it's not installed. Aborting.\n\nHave you installed gradle? See the Java readme at \`java/README.rst\` for setup instructions.\n"; exit 1; }
endif

verify-prereq-haskell: verify-prereq-generator

verify-prereq-rust:
	@command -v cargo   1>/dev/null 2>/dev/null || { echo >&2 -e "I require \`cargo\` but it's not installed. Aborting.\n\nHave you installed Rust? See the Rust readme at \`rust/README.md\` for setup instructions.\n"; exit 1; }
	@command -v rustfmt 1>/dev/null 2>/dev/null || { echo >&2 -e "I require \`rustfmt\` but it's not installed. Aborting.\n\nHave you installed Rust? See the Rust readme at \`rust/README.md\` for setup instructions.\n"; exit 1; }

verify-prereq-protobuf: ;

verify-prereq-jsonschema: ;

verify-prereq-quicktype:
	@command -v quicktype 1>/dev/null 2>/dev/null || { echo >&2 -e "I require \`quicktype\` but it's not installed. Aborting.\n\nHave you installed quicktype? See the generator README (Installing instructions) at \`generator/README.md\` for setup instructions.\n"; exit 1; }

verify-prereq-docs: verify-prereq-generator
	@command -v pdflatex  1>/dev/null 2>/dev/null || { echo >&2 -e "I require \`pdflatex\` but it's not installed. Aborting.\n\nHave you installed pdflatex? See the generator readme (Installing instructions) at \`generator/README.md\` for setup instructions.\n"; exit 1; }
	@command -v sphinx-build  1>/dev/null 2>/dev/null || { echo >&2 -e "I require \`sphinx-build\` but it's not installed. Aborting.\n\nHave you installed sphinx-build? See the generator readme (Installing instructions) at \`generator/README.md\` for setup instructions.\n"; exit 1; }

# Dependencies

deps-c: verify-prereq-c

deps-python: verify-prereq-python

bundle-javascript: deps-javascript
	$(call announce-begin,"Building Javascript bundle")
	cd $(SWIFTNAV_ROOT); npm run webpack
	$(call announce-end,"Finished building JavaScript bundle")

deps-javascript: verify-prereq-javascript
	$(call announce-begin,"Installing Javascript dependencies")
	cd $(SWIFTNAV_ROOT); npm install
	$(call announce-end,"Finished installing Javascript dependencies")

deps-java: verify-prereq-java

deps-haskell: verify-prereq-haskell

deps-rust: verify-prereq-rust

deps-protobuf: verify-prereq-protobuf

deps-jsonschema: verify-prereq-jsonschema

deps-quicktype-typescript: verify-prereq-quicktype

deps-quicktype-javascript: verify-prereq-quicktype

deps-quicktype-elm: verify-prereq-quicktype

# Generators

gen: gen-c gen-python gen-javascript gen-java gen-haskell gen-rust gen-protobuf gen-jsonschema gen-quicktype
gen-quicktype: gen-quicktype-typescript gen-quicktype-elm

gen-c_args = -i $(SBP_SPEC_DIR) \
             -o $(SWIFTNAV_ROOT)/c \
             -r $(SBP_VERSION)
ifeq ($(SBP_STAGING), 1)
	gen-c_args += -s
endif

gen-c:
	$(call announce-begin,"Generating C headers and sources")
	cd $(SWIFTNAV_ROOT)/generator; \
	$(SBP_GEN_BIN) $(gen-c_args) \
	               --c

	$(call announce-begin,"Generating C tests")
	cd $(SWIFTNAV_ROOT)/generator; \
	$(SBP_GEN_BIN) -i $(SBP_TESTS_SPEC_DIR) \
		       -o $(SWIFTNAV_ROOT)/c/test \
		       -r $(SBP_VERSION) \
	               --test-c

	$(call announce-begin,"Formatting C code")

	cd $(SWIFTNAV_ROOT)/c; \
	mkdir -p build/ && cd build/; \
	cmake $(CMAKEFLAGS) ../; \
	$(MAKE) clang-format-all

	$(call announce-end,"Finished formatting C code")

	$(call announce-end,"Finished generating C. Please check $(SWIFTNAV_ROOT)/c/include/libsbp.")

gen-python:
	$(call announce-begin,"Generating Python bindings")
	cd $(SWIFTNAV_ROOT)/generator; \
	$(SBP_GEN_BIN) -i $(SBP_SPEC_DIR) \
		       -o $(SWIFTNAV_ROOT)/python/sbp/ \
		       -r $(SBP_VERSION) \
		       --python

	$(call announce-begin,"Formatting Python code")
	tox -e py --run-command="autoflake -i --remove-all-unused-imports -r python/sbp"
	$(call announce-end,"Finished formatting Python code")
	$(call announce-end,"Finished generating Python bindings. Please check $(SWIFTNAV_ROOT)/python/sbp")

gen-javascript:
	$(call announce-begin,"Generating JavaScript bindings")
	cd $(SWIFTNAV_ROOT)/generator; \
	$(SBP_GEN_BIN) -i $(SBP_SPEC_DIR) \
		       -o $(SWIFTNAV_ROOT)/javascript/sbp/ \
		       -r $(SBP_VERSION_UNPREFIXED) \
		       --javascript
	cd $(SWIFTNAV_ROOT)
	$(call announce-begin,"Bumping NPM version")
	@- npm version "$(shell cat javascript/sbp/RELEASE-VERSION)" --no-git-tag-version >/dev/null 2>&1 || :
	@- npm run webpack >/dev/null 2>&1
	$(call announce-end,"Finished generating JavaScript bindings. Please check $(SWIFTNAV_ROOT)/javascript/sbp")

gen-java:
	$(call announce-begin,"Generating Java bindings")
	cd $(SWIFTNAV_ROOT)/generator && \
	$(SBP_GEN_BIN) -i $(SBP_SPEC_DIR) \
		       -o $(SWIFTNAV_ROOT)/java/src/ \
		       -r $(SBP_VERSION) \
		       --java
	$(call announce-end,"Finished generating Java bindings. Please check $(SWIFTNAV_ROOT)/java/src/sbp")

	$(call announce-begin,"Generating Java tests")

	cd $(SWIFTNAV_ROOT)/generator; \
	$(SBP_GEN_BIN) -i $(SBP_TESTS_SPEC_DIR) \
	-o $(SWIFTNAV_ROOT)/java/test/ \
		       -r $(SBP_VERSION_UNPREFIXED) \
	               --test-java

	$(call announce-end,"Finished generating Java tests")

	$(call announce-begin,"Formatting Java code")
	cd $(SWIFTNAV_ROOT)/java && gradle spotlessApply
	$(call announce-end,"Finished formatting Java code")

gen-haskell:
	$(call announce-begin,"Generating Haskell bindings")
	cd $(SWIFTNAV_ROOT)/generator; \
	$(SBP_GEN_BIN) -i $(SBP_SPEC_DIR) \
					-o $(SWIFTNAV_ROOT)/haskell/ \
					-r $(SBP_VERSION_UNPREFIXED) \
					--haskell
	$(call announce-begin,"Finished generating Haskell bindings")

gen-rust:
	$(call announce-begin,"Generating Rust bindings")

	cd $(SWIFTNAV_ROOT)/generator; \
	$(SBP_GEN_BIN) -i $(SBP_SPEC_DIR) \
					-o $(SWIFTNAV_ROOT)/rust/ \
					-r $(SBP_VERSION_UNPREFIXED) \
					--rust

	$(call announce-end,"Finished generating Rust bindings")

	$(call announce-begin,"Generating Rust tests")

	cd $(SWIFTNAV_ROOT)/generator; \
	$(SBP_GEN_BIN) -i $(SBP_TESTS_SPEC_DIR) \
	-o $(SWIFTNAV_ROOT)/rust/sbp/tests/ \
		       -r $(SBP_VERSION_UNPREFIXED) \
	               --test-rust

	$(call announce-end,"Finished generating Rust tests")

	$(call announce-begin,"Formatting Rust code")

	cd $(SWIFTNAV_ROOT)/rust/sbp && rustup run stable cargo fmt

	$(call announce-end,"Finished formatting Rust code")

	$(call announce-end,"Finished generating Rust bindings")

gen-protobuf:
	$(call announce-begin,"Generating Protocol Buffers bindings")
	cd $(SWIFTNAV_ROOT)/generator; \
	$(SBP_GEN_BIN) -i $(SBP_SPEC_DIR) \
					-o $(SWIFTNAV_ROOT)/proto/ \
					-r $(SBP_VERSION) \
					--protobuf
	$(call announce-begin,"Finished generating Protocol Buffers bindings")

gen-jsonschema:
	$(call announce-begin,"Generating JSON Schema definitions")
	cd $(SWIFTNAV_ROOT)/generator; \
	$(SBP_GEN_BIN) -i $(SBP_SPEC_DIR) \
					-o $(SWIFTNAV_ROOT)/jsonschema/ \
					-r $(SBP_VERSION) \
					--jsonschema
	$(call announce-begin,"Finished generating JSON Schema definitions")

gen-quicktype-typescript:
	$(call announce-begin,"Generating TypeScript module from JSON Schema")
	(cd jsonschema; quicktype -l typescript --src-lang schema *.json >../sbpjson/typescript/SbpJson.ts)
	$(call announce-begin,"Finished generating TypeScript module from JSON Schema definitions")

gen-quicktype-javascript:
	$(call announce-begin,"Generating JavaScript module from JSON Schema")
	(cd jsonschema; quicktype -l javascript --src-lang schema *.json >../sbpjson/javascript/SbpJson.js)
	$(call announce-begin,"Finished generating JavaScript module from JSON Schema definitions")

gen-quicktype-elm:
	$(call announce-begin,"Generating Elm module from JSON Schema")
	(cd jsonschema; quicktype -l elm --module SbpJson --src-lang schema *.json >../sbpjson/elm/SbpJson.elm)
	$(call announce-begin,"Finished generating Elm module from JSON Schema definitions")

# Testers

test: test-all-begin test-c test-c-v4 test-java test-python test-haskell test-javascript test-rust test-all-end

test-all-begin:
	$(call announce-begin,"Running all tests")

test-all-end:
	$(call announce-end,"Finished running all tests")

test-c:
	$(call announce-begin,"Running C tests")
	cd $(SWIFTNAV_ROOT)/c; \
	mkdir -p build/ && cd build/; \
	cmake $(CMAKEFLAGS) ../; \
	$(MAKE) -j4; \
	$(MAKE) do-all-tests
	$(call announce-end,"Finished running C tests")

test-c-v4:
	$(call announce-begin,"Running C tests")
	cd $(SWIFTNAV_ROOT)/c; \
	mkdir -p build/ && cd build/; \
	cmake $(CMAKEFLAGS) ../; \
	$(MAKE) -j4; \
	$(MAKE) do-test-libsbp-v4 do-test-libsbp-cpp-v4
	$(call announce-end,"Finished running C tests")

test-python:
	$(call announce-begin,"Running Python tests")
	cd $(SWIFTNAV_ROOT)/python/ && tox --parallel $(SBP_TOX_PARALLEL) --skip-missing-interpreters
	$(call announce-end,"Finished running Python tests")

test-javascript:
	$(call announce-begin,"Running JavaScript tests")
	npm install
	npm test
	$(call announce-end,"Finished running JavaScript tests")

test-java:
	$(call announce-begin,"Running Java tests")
	cd $(SWIFTNAV_ROOT)/java && gradle test -i
	$(call announce-end,"Finished running Java tests")

test-haskell:
	$(call announce-begin,"Running Haskell tests")
	cd $(SWIFTNAV_ROOT)/haskell/ && stack build --test --allow-different-user
	$(call announce-end,"Finished running Haskell tests")

test-rust:
	$(call announce-begin,"Running Rust tests")
	cargo test --verbose --all-features --all-targets
	$(call announce-begin,"Running Rust doc tests")
	cargo test --doc
	$(call announce-begin,"Building Rust examples")
	cargo build --examples --verbose --all-features --all-targets
	$(call announce-end,"Finished running Rust tests")

test-protobuf:
	$(call announce-begin,"Running Protocol Buffer tests")
	$(call announce-end,"Finished running Protocol Buffer tests")

test-jsonschema:
	$(call announce-begin,"Running JSON Schema tests")
	$(call announce-end,"Finished running JSON Schema tests")

test-quicktype-typescript:
	$(call announce-begin,"Running TypeScript JSON Schema tests [not yet implemented]")
	$(call announce-end,"Finished running TypeScript JSON Schema tests")

test-quicktype-javascript:
	$(call announce-begin,"Running JavaScript JSON Schema tests [not yet implemented]")
	$(call announce-end,"Finished running JavaScript JSON Schema tests")

test-quicktype-elm:
	$(call announce-begin,"Running Elm JSON Schema tests [not yet implemented]")
	$(call announce-end,"Finished running Elm JSON Schema tests")

dist-python:
	$(call announce-begin,"Deploying Python package")
	$(MAKE) -C $(SWIFTNAV_ROOT)/python SBP_VERSION="$(SBP_VERSION_UNPREFIXED)" deploy
	$(call announce-end,"Finished deploying Python package")

dist-javascript:
	$(call announce-begin,"Deploying Javascript package")
	npm publish
	$(call announce-end,"Finished deploying Javascript package")

dist-haskell:
	$(call announce-begin,"Deploying Haskell package")
	(cd $(SWIFTNAV_ROOT)/haskell; stack sdist; stack upload .)
	$(call announce-end,"Finished deploying Haskell package")

dist-rust:
	$(call announce-begin,"Deploying Rust 'sbp' package")
	cargo release -v --package sbp --execute $(SBP_VERSION_UNPREFIXED)
	$(call announce-end,"Finished deploying Rust 'sbp' package")
	$(call announce-begin,"Deploying Rust 'sbp2json' package")
	cargo release -v --package sbp2json --execute $(SBP_VERSION_UNPREFIXED)
	$(call announce-end,"Finished deploying Rust 'sbp2json' package")
	$(call announce-begin,"Reverting commit made by 'sbp2json' deployment")
	git reset --hard $(SBP_VERSION)
	$(call announce-end,"Finished reverting commit made by 'sbp2json' deployment")

dist-java:
	$(call announce-begin,"Deploying Java to maven central")
	cd java && VERSION=$(SBP_VERSION_UNPREFIXED) gradle publish --info
	$(call announce-end,"Finished deploying Java to maven central")

dist: dist-python dist-javascript dist-haskell dist-rust dist-java

pdf:
	$(call announce-begin,"Generating PDF datasheet documentation")
	$(MAKE) pdf-for-real
	# This is a big hack, but we do this twice to ensure that all tables
	#   within the PDF get generated correctly.
	$(MAKE) pdf-for-real
	$(call announce-end,"Finished! Please check $(SWIFTNAV_ROOT)/latex and $(SWIFTNAV_ROOT)/docs")

pdf-for-real:
	cd $(SWIFTNAV_ROOT)/generator; \
	$(SBP_GEN_BIN) -i $(SBP_SPEC_DIR) \
		       -o $(SWIFTNAV_ROOT)/latex/ \
		       -r $(SBP_VERSION) \
	               --latex

html:
	$(call announce-begin,"Generating html documentation")
	$(MAKE) html-c
	$(MAKE) html-python
	$(call announce-end,"Finished generating html documentation")

html-c:
	$(call announce-begin,"Generating C bindings documentation")
	cd $(SWIFTNAV_ROOT)/c && \
	  mkdir -p build      && \
	  cd build            && \
	  cmake ..            && \
	  $(MAKE) docs
	$(call announce-end,"Finished generating C bindings documentation at c/build/docs/html/index.html")

html-python:
	$(call announce-begin,"Generating Python documentation")
	tox -e py --run-command="make -C python/docs spelling html"
	$(call announce-end,"Finished generating Python documentation at python/docs/build/html/index.html")

release:
	$(call announce-begin,"Run release boilerplate")
	docker run -it --rm -v $(PWD):/usr/local/src/your-app ferrarimarco/github-changelog-generator \
	  --max-issues $(CHANGELOG_MAX_ISSUES) \
	  -t $(CHANGELOG_GITHUB_TOKEN) \
	  --user swift-nav --project libsbp \
	  -o DRAFT_CHANGELOG.md \
	  swift-nav/libsbp
	$(call announce-end,"Added CHANGELOG details to DRAFT_CHANGELOG.md!")

mapping:
	@egrep -h '^( - MSG|    id:)' spec/yaml/swiftnav/sbp/*.yaml |\
	 sed 'N;s/\n//' |\
	 awk '{printf("%s  %5d  %s\n", $$4, $$4, $$2)}' |\
	 sed 's/:$$//' |\
	 sort

benchmark:
	@PYTHONPATH=$(PWD)/test_data ./test_data/benchmark_main.py

java-examples:
	$(call announce-begin,"Building java example fat jar")
	cd $(SWIFTNAV_ROOT)/java/example && gradle clean fatjar
	$(call announce-end,"Finished building fat jar")

javadoc javadocs:
	$(call announce-begin,"Building javadocs")
	cd $(SWIFTNAV_ROOT)/java && gradle javadoc --stacktrace
	$(call announce-end,"Finished building javadocs")

spec-validator-fmt:
	python -m black scripts/spec_validator.py

spec-validator-test:
	python -m pylint --disable=C0116,W1203 scripts/spec_validator.py
	python -m mypy --install scripts/spec_validator.py
	python -m black --check scripts/spec_validator.py
	./scripts/validation_test_harness.bash 2>&1 | grep -E 'PASS|FAIL'

version:
	@echo "SBP version: $(SBP_VERSION)"
	@echo "SBP is staging: $(SBP_STAGING)"
