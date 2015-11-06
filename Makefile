# Convenience Makefile for generating and releasing SBP client
# libraries. Please read and understand the contents of this file
# before using it to do Crazy Things.

SWIFTNAV_ROOT := $(shell pwd)
MAKEFLAGS += SWIFTNAV_ROOT=$(SWIFTNAV_ROOT)
SBP_SPEC_DIR := $(SWIFTNAV_ROOT)/spec/yaml/swiftnav/sbp/
SBP_GEN_BIN := python sbpg/generator.py
export PYTHONPATH := .

SBP_VERSION := $(shell PYTHONPATH=python python python/sbp/version.py)
SBP_MAJOR_VERSION := $(word 1, $(subst ., , $(SBP_VERSION)))
SBP_MINOR_VERSION := $(word 2, $(subst ., , $(SBP_VERSION)))
SBP_PATCH_VERSION := $(word 3, $(subst ., , $(SBP_VERSION)))

.PHONY: help all c python javascript docs pdf html test release dist silly java haskell

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

all: deps c python javascript haskell test docs

c:
	@echo
	@echo "Generating C headers..."
	@echo
	cd $(SWIFTNAV_ROOT)/generator; \
	$(SBP_GEN_BIN) -i $(SBP_SPEC_DIR) \
		       -o $(SWIFTNAV_ROOT)/c/include/libsbp \
                       -r $(SBP_MAJOR_VERSION).$(SBP_MINOR_VERSION) \
	               --c
	@echo
	@echo "Finished. Please check $(SWIFTNAV_ROOT)/c/include/libsbp."

deps:
	@echo
	@echo "Installing dependencies..."
	@echo
	cd $(SWIFTNAV_ROOT)/generator; \
	sudo pip install -r requirements.txt
	@echo
	@echo "Finished!"

python:
	@echo
	@echo "Generating Python bindings..."
	@echo
	cd $(SWIFTNAV_ROOT)/generator; \
	$(SBP_GEN_BIN) -i $(SBP_SPEC_DIR) \
		       -o $(SWIFTNAV_ROOT)/python/sbp/ \
                       -r $(SBP_MAJOR_VERSION).$(SBP_MINOR_VERSION) \
		       --python
	@echo
	@echo "Finished! Please check $(SWIFTNAV_ROOT)/python/sbp."

javascript:
	@echo
	@echo "Generating JavaScript bindings..."
	@echo
	cd $(SWIFTNAV_ROOT)/generator; \
	$(SBP_GEN_BIN) -i $(SBP_SPEC_DIR) \
		       -o $(SWIFTNAV_ROOT)/javascript/sbp/ \
                       -r $(SBP_MAJOR_VERSION).$(SBP_MINOR_VERSION) \
		       --javascript;\
	cd $(SWIFTNAV_ROOT);
	@echo
	@echo "Finished! Please check $(SWIFTNAV_ROOT)/javascript/sbp."

java:
	@echo
	@echo "Generating Java bindings..."
	@echo
	cd $(SWIFTNAV_ROOT)/generator; \
	$(SBP_GEN_BIN) -i $(SBP_SPEC_DIR) \
		       -o $(SWIFTNAV_ROOT)/java/src/ \
		       -r $(SBP_MAJOR_VERSION).$(SBP_MINOR_VERSION) \
		       --java
	@echo
	@echo "Finished! Please check $(SWIFTNAV_ROOT)/java/src/sbp."

haskell:
	@echo
	@echo "Generating Haskell bindings..."
	@echo
	cd $(SWIFTNAV_ROOT)/generator; \
	$(SBP_GEN_BIN) -i $(SBP_SPEC_DIR) \
					-o $(SWIFTNAV_ROOT)/haskell/ \
					-r $(SBP_MAJOR_VERSION).$(SBP_MINOR_VERSION).$(SBP_PATCH_VERSION) \
					--haskell
	@echo
	@echo "Finished! Please check $(SWIFTNAV_ROOT)/haskell."

dist:
	@echo
	@echo "Deploy packages ..."
	@echo
	cd $(SWIFTNAV_ROOT)/python; \
	python setup.py sdist upload -r pypi
	@echo
	@echo "Finished! Please check $(SWIFTNAV_ROOT)/python/sbp."

docs: pdf html

pdf:
	@echo
	@echo "Generating datasheet documentation..."
	@echo
	cd $(SWIFTNAV_ROOT)/generator; \
	$(SBP_GEN_BIN) -i $(SBP_SPEC_DIR) \
		       -o $(SWIFTNAV_ROOT)/latex/ \
                       -r $(SBP_MAJOR_VERSION).$(SBP_MINOR_VERSION) \
	               --latex
	@echo
	@echo "Finished!"
	@echo "Please check $(SWIFTNAV_ROOT)/latex and $(SWIFTNAV_ROOT)/docs."

html:
	@echo
	@echo "Generating bindings documentation..."
	@echo
	@echo "Generating C documentation..."
	@echo
	cd $(SWIFTNAV_ROOT)/c; \
	mkdir -p build/ && cd build/; \
	cmake ../; \
	make docs
	@echo
	@echo "Generating Python documentation..."
	@echo
	cd $(SWIFTNAV_ROOT)/python/docs/ && make html
	@echo
	@echo "Finished!"

test: test-all-begin test-c test-java test-python test-javascript test-all-end

test-all-begin:
	@echo
	@echo "Running all tests..."

test-all-end:
	@echo
	@echo "Finished!"

test-c: c
	@echo
	@echo "Running C tests..."
	@echo
	cd $(SWIFTNAV_ROOT)/c; \
	mkdir -p build/ && cd build/; \
	cmake ../; \
	make test

test-java: java
	@echo
	@echo "No Java tests - TODO"

test-python: python
	@echo
	@echo "Running Python tests..."
	@echo
	cd $(SWIFTNAV_ROOT)/python/ && tox

test-javascript: javascript
	@echo
	@echo "Running JavaScript tests..."
	@echo
	npm test

release:
	@echo
	@echo "Run release boilerplate..."
	@echo
	github_changelog_generator --no-author \
				   -t $(CHANGELOG_GITHUB_TOKEN)$ \
				   -o DRAFT_CHANGELOG.md \
				   swift-nav/libsbp
	@echo
	@echo "Added CHANGELOG details to DRAFT_CHANGELOG.md!"
