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

SBP_VERSION := $(shell python python/sbp/version.py)
SBP_MAJOR_VERSION := $(word 1, $(subst ., , $(SBP_VERSION)))
SBP_MINOR_VERSION := $(word 2, $(subst ., , $(SBP_VERSION)))
SBP_PATCH_VERSION := $(word 3, $(subst ., , $(SBP_VERSION)))

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
	@echo "  python-jit   to make Python (JIT) bindings"
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

all: c python javascript java docs haskell protobuf rust jsonschema
clean:
	@echo "Removing the ./c/build directory..."
	rm -r $(SWIFTNAV_ROOT)/c/build
docs: verify-prereq-docs pdf html

c:            deps-c          gen-c          test-c
python-nojit: deps-python     gen-python-nojit
python-jit:   deps-python     gen-python-jit
python:       python-nojit python-jit test-python
javascript: deps-javascript gen-javascript test-javascript
java:       deps-java       gen-java       test-java
haskell:    deps-haskell    gen-haskell    test-haskell
rust:       deps-rust       gen-rust       test-rust
protobuf:   deps-protobuf   gen-protobuf   test-protobuf
jsonschema: deps-jsonschema gen-jsonschema test-jsonschema

quicktype-typescript: deps-quicktype-typescript gen-quicktype-typescript 	test-quicktype-typescript
quicktype-javascript: deps-quicktype-javascript gen-quicktype-javascript 	test-quicktype-javascript
quicktype-elm: 				deps-quicktype-elm 				gen-quicktype-elm 				test-quicktype-elm

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
	@command -v checkmk      1>/dev/null 2>/dev/null || { echo >&2 -e "I require \`checkmk\` but it's not installed. Aborting.\n\nHave you installed checkmk? See the C readme at \`c/README.md\` for setup instructions.\n"; exit 1; }
	@command -v cmake        1>/dev/null 2>/dev/null || { echo >&2 -e "I require \`cmake\` but it's not installed. Aborting.\n\nHave you installed cmake? See the C readme at \`c/README.md\` for setup instructions.\n"; exit 1; }
	@command -v pkg-config   1>/dev/null 2>/dev/null || { echo >&2 -e "I require \`pkg-config\` but it's not installed. Aborting.\n\nHave you installed pkg-config? See the C readme at \`c/README.md\` for setup instructions.\n"; exit 1; }
	@command -v doxygen      1>/dev/null 2>/dev/null || { echo >&2 -e "I require \`doxygen\` but it's not installed. Aborting.\n\nHave you installed doxygen? See the C readme at \`c/README.md\` for setup instructions.\n"; exit 1; }

verify-prereq-python: verify-prereq-generator
	@command -v python 1>/dev/null 2>/dev/null || { echo >&2 -e "I require \`python\` but it's not installed. Aborting.\n\nHave you installed Python? See the Python readme at \`python/README.rst\` for setup instructions.\n"; exit 1; }
	@command -v pip 1>/dev/null 2>/dev/null    || { echo >&2 -e "I require \`pip\` but it's not installed. Aborting.\n\nHave you installed pip? See the Python readme at \`python/README.rst\` for setup instructions.\n"; exit 1; }
	@command -v tox 1>/dev/null 2>/dev/null    || { echo >&2 -e "I require \`tox\` but it's not installed. Aborting.\n\nHave you installed tox? See the Python readme at \`python/README.rst\` for setup instructions.\n"; exit 1; }
	@command -v pandoc 1>/dev/null 2>/dev/null || { echo >&2 -e "I require \`pandoc\` but it's not installed. Aborting.\n\nHave you installed pandoc? See the Python readme at \`python/README.rst\` for setup instructions.\n"; exit 1; }
	@command -v llvm-config 1>/dev/null 2>/dev/null || { echo >&2 -e "I require \`llvm-config\` but it's not installed. Aborting.\n\nHave you installed LLVM? See the Python readme at \`python/README.rst\` for setup instructions.\n"; exit 1; }

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

deps-javascript: verify-prereq-javascript
	$(call announce-begin,"Installing Javascript dependencies")
	cd $(SWIFTNAV_ROOT); npm install
	cd $(SWIFTNAV_ROOT); npm run webpack
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

gen-c:
	$(call announce-begin,"Generating C headers")
	cd $(SWIFTNAV_ROOT)/generator; \
	$(SBP_GEN_BIN) -i $(SBP_SPEC_DIR) \
		       -o $(SWIFTNAV_ROOT)/c/include/libsbp \
                       -r $(SBP_MAJOR_VERSION).$(SBP_MINOR_VERSION).$(SBP_PATCH_VERSION) \
	               --c

	$(call announce-begin,"Generating C tests")
	cd $(SWIFTNAV_ROOT)/generator; \
	$(SBP_GEN_BIN) -i $(SBP_TESTS_SPEC_DIR) \
		       -o $(SWIFTNAV_ROOT)/c/test \
                       -r $(SBP_MAJOR_VERSION).$(SBP_MINOR_VERSION).$(SBP_PATCH_VERSION) \
	               --test-c

	$(call announce-end,"Finished generating C. Please check $(SWIFTNAV_ROOT)/c/include/libsbp.")

gen-python-nojit:
	$(call announce-begin,"Generating Python bindings")
	cd $(SWIFTNAV_ROOT)/generator; \
	$(SBP_GEN_BIN) -i $(SBP_SPEC_DIR) \
		       -o $(SWIFTNAV_ROOT)/python/sbp/ \
                       -r $(SBP_MAJOR_VERSION).$(SBP_MINOR_VERSION).$(SBP_PATCH_VERSION) \
		       --python
	$(call announce-end,"Finished generating Python bindings. Please check $(SWIFTNAV_ROOT)/python/sbp")

gen-python-jit:
	$(call announce-begin,"Generating Python bindings")
	cd $(SWIFTNAV_ROOT)/generator; \
	$(SBP_GEN_BIN) -i $(SBP_SPEC_DIR) \
		       -o $(SWIFTNAV_ROOT)/python/sbp/jit \
                       -r $(SBP_MAJOR_VERSION).$(SBP_MINOR_VERSION).$(SBP_PATCH_VERSION) \
		       --python_jit
	$(call announce-end,"Finished generating Python bindings. Please check $(SWIFTNAV_ROOT)/python/sbp")

gen-javascript:
	$(call announce-begin,"Generating JavaScript bindings")
	cd $(SWIFTNAV_ROOT)/generator; \
	$(SBP_GEN_BIN) -i $(SBP_SPEC_DIR) \
		       -o $(SWIFTNAV_ROOT)/javascript/sbp/ \
                       -r $(SBP_MAJOR_VERSION).$(SBP_MINOR_VERSION) \
		       --javascript
	cd $(SWIFTNAV_ROOT)
	$(call announce-begin,"Bumping NPM version")
	@- npm version "v$(SBP_MAJOR_VERSION).$(SBP_MINOR_VERSION).$(SBP_PATCH_VERSION)" --no-git-tag-version >/dev/null 2>&1
	@- npm run webpack >/dev/null 2>&1
	$(call announce-end,"Finished generating JavaScript bindings. Please check $(SWIFTNAV_ROOT)/javascript/sbp")

gen-java:
	$(call announce-begin,"Generating Java bindings")
	cd $(SWIFTNAV_ROOT)/generator && \
	$(SBP_GEN_BIN) -i $(SBP_SPEC_DIR) \
		       -o $(SWIFTNAV_ROOT)/java/src/ \
		       -r $(SBP_MAJOR_VERSION).$(SBP_MINOR_VERSION) \
		       --java
	$(call announce-end,"Finished generating Java bindings. Please check $(SWIFTNAV_ROOT)/java/src/sbp")

gen-haskell:
	$(call announce-begin,"Generating Haskell bindings")
	cd $(SWIFTNAV_ROOT)/generator; \
	$(SBP_GEN_BIN) -i $(SBP_SPEC_DIR) \
					-o $(SWIFTNAV_ROOT)/haskell/ \
					-r $(SBP_MAJOR_VERSION).$(SBP_MINOR_VERSION).$(SBP_PATCH_VERSION) \
					--haskell
	$(call announce-begin,"Finished generating Haskell bindings")

gen-rust:
	$(call announce-begin,"Generating Rust bindings")
	cd $(SWIFTNAV_ROOT)/generator; \
	$(SBP_GEN_BIN) -i $(SBP_SPEC_DIR) \
					-o $(SWIFTNAV_ROOT)/rust/ \
					-r $(SBP_MAJOR_VERSION).$(SBP_MINOR_VERSION).$(SBP_PATCH_VERSION) \
					--rust

	$(call announce-begin,"Generating Rust tests")
	cd $(SWIFTNAV_ROOT)/generator; \
	$(SBP_GEN_BIN) -i $(SBP_TESTS_SPEC_DIR) \
	-o $(SWIFTNAV_ROOT)/rust/sbp/tests/ \
                       -r $(SBP_MAJOR_VERSION).$(SBP_MINOR_VERSION).$(SBP_PATCH_VERSION) \
	               --test-rust

	cd $(SWIFTNAV_ROOT)/rust/sbp && cargo fmt
	$(call announce-begin,"Finished generating Rust bindings")

gen-protobuf:
	$(call announce-begin,"Generating Protocol Buffers bindings")
	cd $(SWIFTNAV_ROOT)/generator; \
	$(SBP_GEN_BIN) -i $(SBP_SPEC_DIR) \
					-o $(SWIFTNAV_ROOT)/proto/ \
					-r $(SBP_MAJOR_VERSION).$(SBP_MINOR_VERSION).$(SBP_PATCH_VERSION) \
					--protobuf
	$(call announce-begin,"Finished generating Protocol Buffers bindings")

gen-jsonschema:
	$(call announce-begin,"Generating JSON Schema definitions")
	cd $(SWIFTNAV_ROOT)/generator; \
	$(SBP_GEN_BIN) -i $(SBP_SPEC_DIR) \
					-o $(SWIFTNAV_ROOT)/jsonschema/ \
					-r $(SBP_MAJOR_VERSION).$(SBP_MINOR_VERSION).$(SBP_PATCH_VERSION) \
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

test: test-all-begin test-c test-java test-python test-haskell test-javascript test-rust test-all-end

test-all-begin:
	$(call announce-begin,"Running all tests")

test-all-end:
	$(call announce-end,"Finished running all tests")

test-c:
	$(call announce-begin,"Running C tests")
	cd $(SWIFTNAV_ROOT)/c; \
	mkdir -p build/ && cd build/; \
	cmake $(CMAKEFLAGS) ../; \
	make
	$(call announce-end,"Finished running C tests")

test-python:
	$(call announce-begin,"Running Python tests")
ifdef CI
	cd $(SWIFTNAV_ROOT)/python/ && tox -- $(SWIFTNAV_ROOT)/haskell
else
	cd $(SWIFTNAV_ROOT)/python/ && tox --skip-missing-interpreters
endif
	$(call announce-end,"Finished running Python tests")

test-javascript:
	$(call announce-begin,"Running JavaScript tests")
	npm install; \
	npm test
	$(call announce-end,"Finished running JavaScript tests")

test-java:
	$(call announce-begin,"Running Java tests")
	cd $(SWIFTNAV_ROOT)/java && gradle test
	$(call announce-end,"Finished running Java tests")

test-haskell:
	$(call announce-begin,"Running Haskell tests")
	cd $(SWIFTNAV_ROOT)/haskell/ && stack build --test --allow-different-user
	$(call announce-end,"Finished running Haskell tests")

test-rust:
	$(call announce-begin,"Running Rust tests")
	cargo test --verbose --all-targets
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
	make -C $(SWIFTNAV_ROOT)/python SBP_VERSION="$(SBP_MAJOR_VERSION).$(SBP_MINOR_VERSION).$(SBP_PATCH_VERSION)" deploy
	$(call announce-end,"Finished deploying Python package")

dist-javascript:
	$(call announce-begin,"Deploying Javascript package")
	npm publish
	$(call announce-begin,"Finished deploying Javascript package")

dist-haskell:
	$(call announce-begin,"Deploying Haskell package")
	(cd $(SWIFTNAV_ROOT)/haskell; stack sdist; stack upload .)
	$(call announce-begin,"Finished deploying Haskell package")

dist-pdf:
	$(call announce-begin,"Deploying PDF documentation")
	make pdf_dist
	$(call announce-begin,"Finished deploying PDF documentation")

dist: dist-python dist-javascript dist-haskell dist-pdf

pdf:
	$(call announce-begin,"Generating PDF datasheet documentation")
	cd $(SWIFTNAV_ROOT)/generator; \
	$(SBP_GEN_BIN) -i $(SBP_SPEC_DIR) \
		       -o $(SWIFTNAV_ROOT)/latex/ \
                       -r $(SBP_MAJOR_VERSION).$(SBP_MINOR_VERSION).$(SBP_PATCH_VERSION) \
	               --latex
	$(call announce-end,"Finished! Please check $(SWIFTNAV_ROOT)/latex and $(SWIFTNAV_ROOT)/docs")

pdf_dist:
	s3cmd put  $(SWIFTNAV_ROOT)/docs/sbp.pdf s3://downloads.swiftnav.com/sbp/docs/sbp_$(SBP_VERSION).pdf

html:
	$(call announce-begin,"Generating bindings documentation")
	$(call announce-begin,"Generating C bindings documentation")
	cd $(SWIFTNAV_ROOT)/c; \
	mkdir -p build/ && cd build/; \
	cmake ../; \
	make docs
	$(call announce-begin,"Generating Python documentation")
	cd $(SWIFTNAV_ROOT)/python/docs/ && make html
	$(call announce-end,"Finished generating documentation")

release:
	$(call announce-begin,"Run release boilerplate")
	github_changelog_generator --no-author \
				   --max-issues $(CHANGELOG_MAX_ISSUES) \
				   -t $(CHANGELOG_GITHUB_TOKEN)$ \
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
