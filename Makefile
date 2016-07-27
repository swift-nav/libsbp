# Convenience Makefile for generating and releasing SBP client
# libraries. Please read and understand the contents of this file
# before using it to do Crazy Things.

SWIFTNAV_ROOT := $(shell pwd)
MAKEFLAGS += SWIFTNAV_ROOT=$(SWIFTNAV_ROOT)
SBP_SPEC_DIR := $(SWIFTNAV_ROOT)/spec/yaml/swiftnav/sbp/
SBP_TESTS_SPEC_DIR := $(SWIFTNAV_ROOT)/spec/tests/yaml/
SBP_GEN_BIN := python sbpg/generator.py
export PYTHONPATH := .:$(shell echo $$PYTHONPATH)

SBP_VERSION := $(shell PYTHONPATH=python python python/sbp/version.py)
SBP_MAJOR_VERSION := $(word 1, $(subst ., , $(SBP_VERSION)))
SBP_MINOR_VERSION := $(word 2, $(subst ., , $(SBP_VERSION)))
SBP_PATCH_VERSION := $(word 3, $(subst ., , $(SBP_VERSION)))

.PHONY: help docs pdf html test release dist silly all docs pdf html c deps-c gen-c test-c python deps-python gen-python test-python javascript deps-javascript gen-javascript test-javascript java deps-java gen-java test-java haskell deps-generator deps-haskell gen-haskell test-haskell verify-prereq-generator verify-prereq-c verify-prereq-javascript verify-prereq-python verify-prereq-java verify-prereq-haskell

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
	@echo "  deps      to install dependencies"
	@echo "  dist      to distribute packages"
	@echo "  docs      to make HTML and pdf documentation"
	@echo "  html      to make all HTML language docs"
	@echo "  pdf       to make SBP LaTeX datasheet"
	@echo "  python    to make Python bindings"
	@echo "  haskell   to make Haskell bindings"
	@echo "  java      to make Java bindings"
	@echo "  release   to handle some release tasks"
	@echo "  test      to run all tests"
	@echo

all: deps-generator c python javascript java haskell docs
docs: verify-prereq-docs deps-generator pdf html

c:          deps-c          gen-c          test-c
python:     deps-python     gen-python     test-python
javascript: deps-javascript gen-javascript test-javascript
java:       deps-java       gen-java       test-java
haskell:    deps-haskell    gen-haskell    test-haskell

# Prerequisite verification
verify-prereq-generator:
	@command -v python 1>/dev/null 2>/dev/null || { echo >&2 "I require \`python\` but it's not installed. Aborting.\n\nHave you installed Python?"; exit 1; }
	@command -v pip    1>/dev/null 2>/dev/null || { echo >&2 "I require \`pip\` but it's not installed.  Aborting.\n\nHave you installed pip?"; exit 1; }

verify-prereq-c:
	@command -v checkmk      1>/dev/null 2>/dev/null || { echo >&2 "I require \`checkmk\` but it's not installed. Aborting.\n\nHave you installed checkmk? See the C readme at \`c/README.md\` for setup instructions."; exit 1; }
	@command -v cmake        1>/dev/null 2>/dev/null || { echo >&2 "I require \`cmake\` but it's not installed. Aborting.\n\nHave you installed cmake? See the C readme at \`c/README.md\` for setup instructions."; exit 1; }
	@command -v pkg-config   1>/dev/null 2>/dev/null || { echo >&2 "I require \`pkg-config\` but it's not installed. Aborting.\n\nHave you installed pkg-config? See the C readme at \`c/README.md\` for setup instructions."; exit 1; }
	@command -v doxygen      1>/dev/null 2>/dev/null || { echo >&2 "I require \`doxygen\` but it's not installed. Aborting.\n\nHave you installed doxygen? See the C readme at \`c/README.md\` for setup instructions."; exit 1; }

verify-prereq-python:
	@command -v python 1>/dev/null 2>/dev/null || { echo >&2 "I require \`python\` but it's not installed. Aborting.\n\nHave you installed Python? See the Python readme at \`python/README.rst\` for setup instructions."; exit 1; }
	@command -v pip 1>/dev/null 2>/dev/null    || { echo >&2 "I require \`pip\` but it's not installed. Aborting.\n\nHave you installed pip? See the Python readme at \`python/README.rst\` for setup instructions."; exit 1; }
	@command -v tox 1>/dev/null 2>/dev/null    || { echo >&2 "I require \`tox\` but it's not installed. Aborting.\n\nHave you installed tox? See the Python readme at \`python/README.rst\` for setup instructions."; exit 1; }
	@command -v pandoc 1>/dev/null 2>/dev/null || { echo >&2 "I require \`pandoc\` but it's not installed. Aborting.\n\nHave you installed pandoc? See the Python readme at \`python/README.rst\` for setup instructions."; exit 1; }

verify-prereq-javascript:
	@command -v node   1>/dev/null 2>/dev/null || { echo >&2 "I require \`node\` but it's not installed. Aborting.\n\nHave you installed Node.js? See the JavaScript readme at \`javascript/README.md\` for setup instructions."; exit 1; }
	@command -v npm    1>/dev/null 2>/dev/null || { echo >&2 "I require \`npm\` but it's not installed. Aborting.\n\nHave you installed NPM? See the JavaScript readme at \`javascript/README.md\` for setup instructions."; exit 1; }
	@command -v mocha  1>/dev/null 2>/dev/null || { echo >&2 "I require \`mocha\` but it's not installed. Aborting.\n\nHave you installed mocha? See the JavaScript readme at \`javascript/README.md\` for setup instructions."; exit 1; }

verify-prereq-java: ;

verify-prereq-haskell: ;

verify-prereq-docs:
	@command -v pdflatex  1>/dev/null 2>/dev/null || { echo >&2 "I require \`pdflatex\` but it's not installed. Aborting.\n\nHave you installed pdflatex? See the generator readme (Installing instructions) at \`generator/README.md\` for setup instructions."; exit 1; }

# Dependencies

deps-c: verify-prereq-c

deps-python: verify-prereq-python

deps-javascript: verify-prereq-javascript
	$(call announce-begin,"Installing Javascript dependencies")
	cd $(SWIFTNAV_ROOT); npm install
	$(call announce-end,"Finished installing Javascript dependencies")

deps-java: verify-prereq-java

deps-haskell: verify-prereq-haskell

deps-generator: verify-prereq-generator
	$(call announce-begin,"Installing generator dependencies")
	cd $(SWIFTNAV_ROOT)/generator; python -m pip install --user -r requirements.txt
	$(call announce-end,"Finished installing generator dependencies")

# Generators

gen-c: deps-generator
	$(call announce-begin,"Generating C headers")
	cd $(SWIFTNAV_ROOT)/generator; \
	$(SBP_GEN_BIN) -i $(SBP_SPEC_DIR) \
		       -o $(SWIFTNAV_ROOT)/c/include/libsbp \
                       -r $(SBP_MAJOR_VERSION).$(SBP_MINOR_VERSION) \
	               --c

	$(call announce-begin,"Generating C tests")
	rm -f $(SWIFTNAV_ROOT)/c/test/auto_check*.c; \
	cd $(SWIFTNAV_ROOT)/generator; \
	$(SBP_GEN_BIN) -i $(SBP_TESTS_SPEC_DIR) \
		       -o $(SWIFTNAV_ROOT)/c/test \
                       -r $(SBP_MAJOR_VERSION).$(SBP_MINOR_VERSION) \
	               --test-c

	$(call announce-end,"Finished generating C. Please check $(SWIFTNAV_ROOT)/c/include/libsbp.")

gen-python: deps-generator
	$(call announce-begin,"Generating Python bindings")
	cd $(SWIFTNAV_ROOT)/generator; \
	$(SBP_GEN_BIN) -i $(SBP_SPEC_DIR) \
		       -o $(SWIFTNAV_ROOT)/python/sbp/ \
                       -r $(SBP_MAJOR_VERSION).$(SBP_MINOR_VERSION) \
		       --python
	$(call announce-end,"Finished generating Python bindings. Please check $(SWIFTNAV_ROOT)/python/sbp")

gen-javascript: deps-generator
	$(call announce-begin,"Generating JavaScript bindings")
	cd $(SWIFTNAV_ROOT)/generator; \
	$(SBP_GEN_BIN) -i $(SBP_SPEC_DIR) \
		       -o $(SWIFTNAV_ROOT)/javascript/sbp/ \
                       -r $(SBP_MAJOR_VERSION).$(SBP_MINOR_VERSION) \
		       --javascript
	cd $(SWIFTNAV_ROOT)
	$(call announce-begin,"Bumping NPM version")
	@- npm version "v$(SBP_MAJOR_VERSION).$(SBP_MINOR_VERSION).$(SBP_PATCH_VERSION)" --no-git-tag-version >/dev/null 2>&1
	$(call announce-end,"Finished generating JavaScript bindings. Please check $(SWIFTNAV_ROOT)/javascript/sbp")

gen-java: deps-generator
	$(call announce-begin,"Generating Java bindings")
	cd $(SWIFTNAV_ROOT)/generator; \
	$(SBP_GEN_BIN) -i $(SBP_SPEC_DIR) \
		       -o $(SWIFTNAV_ROOT)/java/src/ \
		       -r $(SBP_MAJOR_VERSION).$(SBP_MINOR_VERSION) \
		       --java
	$(call announce-end,"Finished generating Java bindings. Please check $(SWIFTNAV_ROOT)/java/src/sbp")

gen-haskell: deps-generator
	$(call announce-begin,"Generating Haskell bindings")
	cd $(SWIFTNAV_ROOT)/generator; \
	$(SBP_GEN_BIN) -i $(SBP_SPEC_DIR) \
					-o $(SWIFTNAV_ROOT)/haskell/ \
					-r $(SBP_MAJOR_VERSION).$(SBP_MINOR_VERSION).$(SBP_PATCH_VERSION) \
					--haskell
	$(call announce-begin,"Finished generating Haskell bindings")

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
	cd $(SWIFTNAV_ROOT)/python/ && python -m pip install --user -r requirements.txt && python -m tox
	$(call announce-end,"Finished running Python tests")

test-javascript:
	$(call announce-begin,"Running JavaScript tests")
	npm install; \
	npm test
	$(call announce-end,"Finished running JavaScript tests")

test-java:
	$(call announce-begin,"No Java tests - TODO")

test-haskell:
	$(call announce-begin,"Running Haskell tests")
	cd $(SWIFTNAV_ROOT)/haskell/ && stack build --test
	$(call announce-end,"Finished running Haskell tests")

dist:
	$(call announce-begin,"Deploying packages")
	pushd $(SWIFTNAV_ROOT)/python
	python setup.py sdist upload -r pypi
	popd
	npm publish
	pushd $(SWIFTNAV_ROOT)/haskell
	stack sdist
	stack upload .
	popd
	$(call announce-end,"Finished deploying packages")

pdf:
	$(call announce-begin,"Generating PDF datasheet documentation")
	cd $(SWIFTNAV_ROOT)/generator; \
	$(SBP_GEN_BIN) -i $(SBP_SPEC_DIR) \
		       -o $(SWIFTNAV_ROOT)/latex/ \
                       -r $(SBP_MAJOR_VERSION).$(SBP_MINOR_VERSION) \
	               --latex
	$(call announce-end,"Finished! Please check $(SWIFTNAV_ROOT)/latex and $(SWIFTNAV_ROOT)/docs")

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
				   -t $(CHANGELOG_GITHUB_TOKEN)$ \
				   -o DRAFT_CHANGELOG.md \
				   swift-nav/libsbp
	$(call announce-end,"Added CHANGELOG details to DRAFT_CHANGELOG.md!")
