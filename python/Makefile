HAS_NIX := $(shell which nix-shell || echo y)

DEPLOY_PYTHON := "( \
python setup.py sdist bdist_wheel && \
twine upload -u '$(PYPI_USERNAME)' -p '$(PYPI_PASSWORD)' dist/sbp-$(SBP_VERSION)-*.whl )"

.PHONY: deploy

ifneq ($(HAS_NIX),)
DEPLOY_COMMAND := nix-shell ../default.nix --pure	--command $(DEPLOY_PYTHON)
else
DEPLOY_COMMAND := $(SHELL) -c $(DEPLOY_PYTHON)
endif

deploy:
	@$(DEPLOY_COMMAND)
