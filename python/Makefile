
.PHONY: deploy

DEPLOY_PYTHON := $(CURDIR)/deploy.py
DEPLOY_COMMAND := python $(DEPLOY_PYTHON)

deploy: export SBP_VERSION=$(SBP_VERSION)
deploy:
	$(DEPLOY_COMMAND)
