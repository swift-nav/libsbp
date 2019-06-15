.PHONY: deploy

ifeq ($(OS),Windows_NT)
PYTHON := python
else
PYTHON := python3
endif

DEPLOY_PYTHON := $(CURDIR)/deploy.py
DEPLOY_COMMAND := $(PYTHON) $(DEPLOY_PYTHON)

deploy: export SBP_VERSION=$(SBP_VERSION)
deploy:
	$(DEPLOY_COMMAND)
