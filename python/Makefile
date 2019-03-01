HAS_NIX := $(shell which nix-shell || echo y)

DEPLOY_PYTHON := $(CURDIR)/deploy.sh

.PHONY: deploy

ifneq ($(HAS_NIX),)
DEPLOY_COMMAND := nix-shell ../default.nix --pure	--run "PYPI_USERNAME=$(PYPI_USERNAME) PYPI_PASSWORD=$(PYPI_PASSWORD) SBP_VERSION=$(SBP_VERSION) $(DEPLOY_PYTHON)"
else
DEPLOY_COMMAND := SBP_VERSION=$(SBP_VERSION) $(SHELL) $(DEPLOY_PYTHON)
endif

deploy:
	@[ -n "$(PYPI_USERNAME)" ] || { echo "\n!!! Please set PYPI_USERNAME in the environment !!!\n"; exit 1; }
	@[ -n "$(PYPI_PASSWORD)" ] || { echo "\n!!! Please set PYPI_PASSWORD in the environment !!!\n"; exit 1; }
	$(DEPLOY_COMMAND)
