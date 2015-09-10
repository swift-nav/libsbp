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

.PHONY: help all c python docs pdf html test release dist silly java haskell

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
	@echo "  haskell   to make Haskell bindings"
	@echo "  java      to make Java bindings"
	@echo "  release   to handle some release tasks"
	@echo "  test      to run all tests"
	@echo

all: c python haskell test docs

c:
	@echo
	@echo "Generating C headers..."
	@echo
	cd $(SWIFTNAV_ROOT)/generator; \
	$(SBP_GEN_BIN) -i $(SBP_SPEC_DIR) \
		       -o $(SWIFTNAV_ROOT)/c/include/libsbp \
                       -r $(SBP_MAJOR_VERSION).$(SBP_MINOR_VERSION) \
	               --c;\
	cd $(SWIFTNAV_ROOT);
	@echo
	@echo "Finished. Please check $(SWIFTNAV_ROOT)/c/include/libsbp."

python:
	@echo
	@echo "Generating Python bindings..."
	@echo
	cd $(SWIFTNAV_ROOT)/generator; \
	$(SBP_GEN_BIN) -i $(SBP_SPEC_DIR) \
		       -o $(SWIFTNAV_ROOT)/python/sbp/ \
                       -r $(SBP_MAJOR_VERSION).$(SBP_MINOR_VERSION) \
		       --python;\
	cd $(SWIFTNAV_ROOT);
	@echo
	@echo "Finished! Please check $(SWIFTNAV_ROOT)/python/sbp."

java:
	@echo
	@echo "Generating Java bindings..."
	@echo
	cd $(SWIFTNAV_ROOT)/generator; \
	$(SBP_GEN_BIN) -i $(SBP_SPEC_DIR) \
		       -o $(SWIFTNAV_ROOT)/java/src/ \
		       -r $(SBP_MAJOR_VERSION).$(SBP_MINOR_VERSION) \
		       --java;\
	cd $(SWIFTNAV_ROOT);
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
					--haskell;\
	cd $(SWIFTNAV_ROOT);
	@echo
	@echo "Finished! Please check $(SWIFTNAV_ROOT)/haskell."

dist:
	@echo
	@echo "Deploy packages ..."
	@echo
	cd $(SWIFTNAV_ROOT)/python; \
	python setup.py sdist upload -r pypi; \
	cd $(SWIFTNAV_ROOT);
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
	               --latex;\
	cd $(SWIFTNAV_ROOT);
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
	make docs;
	@echo
	@echo "Generating Python documentation..."
	@echo
	cd $(SWIFTNAV_ROOT)/python/docs/ && make html
	cd $(SWIFTNAV_ROOT);
	@echo
	@echo "Finished!"

test:	java
	@echo
	@echo "Run tests..."
	@echo
	@echo "Running C tests..."
	@echo
	cd $(SWIFTNAV_ROOT)/c; \
	mkdir -p build/ && cd build/; \
	cmake ../; \
	make test;
	@echo
	@echo "Running Python tests..."
	@echo
	cd $(SWIFTNAV_ROOT)/python/ && tox
	cd $(SWIFTNAV_ROOT);
	@echo
	@echo "Running Java tests..."
	@echo
	cd $(SWIFTNAV_ROOT)/java/ && gradle test
	cd $(SWIFTNAV_ROOT);
	@echo
	@echo "Finished!"

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
