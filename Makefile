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

.PHONY: help docs pdf html test release dist silly all docs pdf html c deps-c gen-c test-c python deps-python gen-python test-python javascript deps-javascript gen-javascript test-javascript java deps-java gen-java test-java haskell deps-haskell gen-haskell test-haskell haskell deps-protobuf gen-protobuf test-protobuf verify-prereq-generator verify-prereq-c verify-prereq-javascript verify-prereq-python verify-prereq-java verify-prereq-haskell verify-prereq-protobuf mapping

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
	@echo "  help      to display this help message"
	@echo "  all       to make SBP clients across all languages"
	@echo "  c         to make C headers"
	@echo "  dist      to distribute packages"
	@echo "  docs      to make HTML and pdf documentation"
	@echo "  html      to make all HTML language docs"
	@echo "  pdf       to make SBP LaTeX datasheet"
	@echo "  python    to make Python bindings"
	@echo "  pythonNG  to make Python (JIT) bindings"
	@echo "  haskell   to make Haskell bindings"
	@echo "  java      to make Java bindings"
	@echo "  protobuf  to make Protocol Buffer bindings"
	@echo "  release   to handle some release tasks"
	@echo "  test      to run all tests"
	@echo

all: c python pythonNG javascript java docs haskell protobuf
docs: verify-prereq-docs pdf html

c:          deps-c          gen-c          test-c
python:     deps-python     gen-python     test-python
pythonNG:   deps-python     gen-pythonNG
javascript: deps-javascript gen-javascript test-javascript
java:       deps-java       gen-java       test-java
haskell:    deps-haskell    gen-haskell    test-haskell
protobuf:   deps-protobuf   gen-protobuf   test-protobuf

# Prerequisite verification
verify-prereq-generator:
	@command -v python 1>/dev/null 2>/dev/null || { echo >&2 -e "I require \`python\` but it's not installed. Aborting.\n\nHave you installed Python?\n"; exit 1; }
	@command -v pip    1>/dev/null 2>/dev/null || { echo >&2 -e "I require \`pip\` but it's not installed.  Aborting.\n\nHave you installed pip?\n"; exit 1; }

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
	@command -v gradle  1>/dev/null 2>/dev/null || { echo >&2 -e "I require \`gradle\` but it's not installed. Aborting.\n\nHave you installed gradle? See the Java readme at \`java/README.rst\` for setup instructions.\n"; exit 1; }

verify-prereq-haskell: verify-prereq-generator

verify-prereq-protobuf: verify-prereq-generator

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

deps-protobuf: verify-prereq-protobuf

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

gen-python:
	$(call announce-begin,"Generating Python bindings")
	cd $(SWIFTNAV_ROOT)/generator; \
	$(SBP_GEN_BIN) -i $(SBP_SPEC_DIR) \
		       -o $(SWIFTNAV_ROOT)/python/sbp/ \
                       -r $(SBP_MAJOR_VERSION).$(SBP_MINOR_VERSION).$(SBP_PATCH_VERSION) \
		       --python
	$(call announce-end,"Finished generating Python bindings. Please check $(SWIFTNAV_ROOT)/python/sbp")

gen-pythonNG:
	$(call announce-begin,"Generating Python bindings")
	cd $(SWIFTNAV_ROOT)/generator; \
	$(SBP_GEN_BIN) -i $(SBP_SPEC_DIR) \
		       -o $(SWIFTNAV_ROOT)/python/sbp/jit \
                       -r $(SBP_MAJOR_VERSION).$(SBP_MINOR_VERSION).$(SBP_PATCH_VERSION) \
		       --pythonNG
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
	cd $(SWIFTNAV_ROOT)/generator; \
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

gen-protobuf:
	$(call announce-begin,"Generating Protocol Buffers bindings")
	cd $(SWIFTNAV_ROOT)/generator; \
	$(SBP_GEN_BIN) -i $(SBP_SPEC_DIR) \
					-o $(SWIFTNAV_ROOT)/proto/ \
					-r $(SBP_MAJOR_VERSION).$(SBP_MINOR_VERSION).$(SBP_PATCH_VERSION) \
					--protobuf
	$(call announce-begin,"Finished generating Protocol Buffers bindings")


# Testers

test: test-all-begin test-c test-java test-python test-haskell test-javascript test-all-end

test-all-begin:
	$(call announce-begin,"Running all tests")

test-all-end:
	$(call announce-end,"Finished running all tests")

test-c:
	$(call announce-begin,"Running C tests")
	cd $(SWIFTNAV_ROOT)/c; \
	mkdir -p build/ && cd build/; \
	cmake ../; \
	make
	$(call announce-end,"Finished running C tests")

test-python:
	$(call announce-begin,"Running Python tests")
ifdef TRAVIS_TARGET
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

test-protobuf:
	$(call announce-begin,"Running Protocol Buffer tests")
	$(call announce-end,"Finished running Protocol Buffer tests")

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
				   -o DRAFT_CHANGELOG.md \
				   swift-nav/libsbp
	$(call announce-end,"Added CHANGELOG details to DRAFT_CHANGELOG.md!")

mapping:
	@egrep -h '^( - MSG|    id:)' spec/yaml/swiftnav/sbp/*.yaml |\
    sed 'N;s/\n//' |\
    awk '{printf("%s  %5d  %s\n", $$4, $$4, $$2)}' |\
		sed 's/:$$//' |\
    sort
