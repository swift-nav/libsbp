libsbp Development Procedures
=============================

<!-- toc -->

- [Adding and Testing New Messages](#adding-and-testing-new-messages)
- [Message Guidelines](#message-guidelines)
- [Releasing New Versions of the Library](#releasing-new-versions-of-the-library)
- [Installing QuickType](#installing-quicktype)
- [Distributing Python](#distributing-python)
  * [Building on Windows](#building-on-windows)
  * [Troubleshooting](#troubleshooting)
    + [Error: `!!! No Python wheel (.whl) file found...`](#error--no-python-wheel-whl-file-found)
    + [Tox error: `ERROR: FAIL could not package project`](#tox-error-error-fail-could-not-package-project)
    + [Tox error: `ERROR: cowardly refusing to delete envdir`](#tox-error-error-cowardly-refusing-to-delete-envdir)
- [Contributions](#contributions)

<!-- tocstop -->

This document summarizes some practices around contributions to this
library. These instructions don't come with a warranty yet, so please
feel free to update it to mirror reality.

# Adding and Testing New Messages

Adding new SBP messages is currently a very organic, social
process. This is likely to change in the future.

0. Read, understand, and imitate the current SBP definition syntax by
   looking at the annotated [`example`](spec/example/yaml) and
   [`existing`](spec/yaml/swiftnav/sbp) messages.

1. Add a message definition to the approprate package, or create a new
   one if needed. Read the **Message Guidelines** below.

2. Increment `number_of_messages` in `python/tests/sbp/test_table.py`
   by the corresponding number of new messages.

3. Generate new clients and documentation by running `make
   all`. Verify that the generated code, which isn't too complicated,
   meets your expectations, as allowed messages are limited by the
   underlying language implementation. For example, you can't specify
   a message that has a variable-length array in the middle of the
   message, since the generated SBP structs for the C client will
   materialize a 0-length array C99 extension in the middle of the
   struct. GCC won't compile this.

4. (Optional) Add a [`test`](spec/tests/yaml/swiftnav/sbp) case and
   update the appropriate language libaries. Run `make test`.

5. Submit a pull request.

6. If Swift's internal test tooling needs to be updated to use your
   new message, deploy the updated Python client first, and then the C
   client. We haven't quite decided on the details of this process.

# Message Guidelines

Some thoughts to consider when adding a new message:

- Messages should be as simple as possible but no simpler.

- *Build for the future*. Once a message is promoted to "stable" its
  general structure must never change. You should think very hard
  about what kinds of fields you may wish you had included in the
  future. Consider adding some extra reserved bits for future
  expansion (within reason).

- *Size matters*. SBP is designed to be a lightweight protocol used by
  small, embedded devices. Consider using fixed point representations
  where possible, and don't specify excessive precision or
  range. Avoid non-byte aligned types though, they are a pain to
  decode.

- *Generalize*. SBP is a protocol that exists separately from any
  specific device that uses SBP (e.g. Piksi). It should be with a very
  heavy heart that you include anything device specific in the
  protocol, and even then it should only be added to a device specific
  package.

- *Draft message changes*. There are different ways to change draft
  messages, which are allowed to be in flux. Doing so isn't free of
  consequences, particularly if that message is used by others during
  internal development. Changing a message name, its ID, or its field
  contents is fine, as long as the migrating consumers is a
  well-understood process.

# Releasing New Versions of the Library

## Using Docker

It's highly recommended to use the docker container to run the release process,
the docker container can be pulled from DockerHub and launched via this command:

``docker run  -v $PWD:/mnt/workspace -i -t swiftnav/libsbp-build:2020.09.15``

Check this [link](https://hub.docker.com/r/swiftnav/libsbp-build/tags) for newer tags.

## The Process

Oh boy, so you've decided to release a new version of libsbp.  It's recommended
this process is performed using the above docker container.  You'll likely want
to run the git commands outside of the container and the `make ...` commands
inside the container (so you don't have to setup git inside the docker container).

0. Branch and tag a new release. Tag the release version:

    ```shell
    # Produces most recent tag (e.g., v2.7.5)
    git describe --abbrev=0 --tags
    # Increment that value, create a new one (e.g, v2.7.6)
    git tag -a INCREMENTED_TAG -m "Version INCREMENTED_TAG of libsbp."
    ```

1. Make sure that the repo is reported as clean, e.g.

    ```shell
    git describe --tags --dirty --always
    ```

   This will ensure that version information for language libraries
   will be generated cleanly.

   If running the release macOS you may need to install
   llvm though brew (recommend installing llvm 6 with `brew instal llvm@6`)
   then add it to your path with `export PATH=$(brew --prefix llvm@6)/bin:$PATH`.
   You can also use Nixpkgs to setup a complete build environment for
   running a release.  [Install Nixpkgs](https://nixos.org/nix/download.html)
   and then run `nix-shell` prior to running `make all`.

2. Run make tagets for each language and re-tag.  For python:

    ```shell
    make python
    git add python/sbp/RELEASE-VERSION
    git commit -m 'INCREMENTED_TAG'
    git tag -f -a INCREMENTED_TAG -m "Version INCREMENTED_TAG of libsbp."
    ```

   For Java, jsonschema, and Protobuf (these should not require bumping the git tag,
   unless the geneated files are out of date):

    ```shell
    make java jsonschema protobuf
    ```

   For C, Haskell and JavaScript:

    ```shell
    make c haskell javascript rust
    git add c/include/libsbp/version.h haskell/sbp.cabal package.json package-lock.json rust/sbp/Cargo.toml
    git commit -m 'INCREMENTED_TAG'
    git tag -f -a INCREMENTED_TAG -m "Version INCREMENTED_TAG of libsbp."
    ```

3. Finally, build the docs:

    ```shell
    make docs
    ```

   Then commit the docs and re-tag:

    ```shell
    git add docs/sbp.pdf
    git commit -m 'Update docs'
    git tag -f -a INCREMENTED_TAG -m "Version INCREMENTED_TAG of libsbp."
    ```

4. Verify that package dependencies, their version numbers, and the
   libsbp version number in the C, Python, JavaScript, and LaTeX developer
   documentation are consistent.

   - JavaScript: Manually update `package-lock.json`.

   - Others: should be automatically extracted from git tag

5. Update the CHANGELOG details with `make release`. Submit a pull request and
   get it merged. This requires
   [github-changelog-generator](https://github.com/skywinder/github-changelog-generator),
   and a `CHANGELOG_GITHUB_TOKEN` in your `PATH` if you don't already have
   them.

6. After the release PR is merged, recreate the tag:
    ```shell
    git checkout master
    git pull
    git tag -d INCREMENTED_TAG
    git tag -a INCREMENTED_TAG -m "Version INCREMENTED_TAG of libsbp."
    git push origin INCREMENTED_TAG
    ```

7. Create a release on
   [GitHub](https://github.com/swift-nav/libsbp/releases) and add the
   RELEASE_NOTES.md.

8. Distribute release packages.  You can attempt to run all releases
   with `make dist` -- this will likely not work through... it is
   advisable to run each dist target separately.  In particular:

   - `make dist-javascript`
   - `make dist-haskell`
   - `make dist-pdf`
   - `make dist-python` (see section on Python below)

   You may need credentials on the appropriate package repositories. Ignore the
   GPG error in `stack`, the package will get uploaded correctly anyway.  If
   the release is a Python only change it may be appropriate to just publish to
   PyPI with `make dist-python` (see section on Python below) -- we typically
   update all other supported languages when we make an official firmware
   release.

9. Releases are not only never perfect, they never really end. Please
   pay special attention to any downstream projects or users that may
   have issues or regressions as a consequence of the release version.

# Installing QuickType

For web clients we generate JSON schema definitions of the SBP message.
This allows web clients to build "native" objects out of SBP JSON.
We use the quick [QuickType](https://github.com/quicktype/quicktype) tool
to generate libraries for JavaScript, TypeScript, and Elm.

In order to run the `make quicktype-*` target you need to install the
quicktype tool first.  No particular version of this tool is required
at the moment.

# Distributing Python

Python package distribution requires compilation for the JIT accelerated
`sbp.jit` package.  This package uses the Python `numba` library, which
supports AOT compilation of a native Python extension.  The distributions
for each platform can be created by running the `make dist-python` target
on each platform (Windows, Mac OS X, Linux x86/ARM through docker).

For example, running this:
```
make dist-python PYPI_USERNAME=swiftnav PYPI_PASSWORD=...
```

...will produce and upload a `.whl` appropriate for that platform.  A
wheel that targets any platform (this build disables Numba/Numpy support)
can be produced and uploaded by running the following command:
```
make dist-python PYPI_USERNAME=swiftnav PYPI_PASSWORD=... LIBSBP_BUILD_ANY=y
```

The Linux x86 build of libsbp should be done through docker via the
"manylinux" project by running the following set of commands:
```
docker build -f python/Dockerfile.x86_64 -t libsbp-amd64 .
docker run -v libsbp-amd64-root:/root -v $PWD:/work --rm -it libsbp-amd64 /bin/bash
cd /work
make dist-python PYPI_USERNAME=swiftnav PYPI_PASSWORD=...
```

The Linux ARM build of libsbp can be done through docker via the following set
of commands:
```
docker run -v libsbp-arm-root:/root -v $PWD:/work --rm -it swiftnav/libsbp-arm:2020.09.15 libsbp-arm /bin/bash
cd /work
make dist-python PYPI_USERNAME=swiftnav PYPI_PASSWORD=...
```

## Building on Windows

In order to build on Windows, first install the necessary compilers per the
instructions [on this Microsoft developer blog][1] (shortcut: install
[Microsoft Visual Studio Community 2019][msvsc2019] and select the "native
Python development" option, or you can install [Visual Studio Build
Tools][vcbuildtools] and install the "C++ build tools", also make sure to
install MSVC v140 and MSCV v141.  Afterwards install the 64-bit Python 3.7
version of [Conda][2].  You'll also need to install [Chocolatey][3].

[1]: https://devblogs.microsoft.com/python/unable-to-find-vcvarsall-bat/
[2]: https://docs.conda.io/en/latest/miniconda.html
[3]: https://chocolatey.org/docs/installation
[msvsc2019]: https://www.microsoft.com/en-us/download/details.aspx?id=48159
[vcbuildtools]: https://visualstudio.microsoft.com/downloads/#build-tools-for-visual-studio-2019

For Chocolatey, the following packages are recommended:
- make
- vcredist140
- vcredist2015

In order to compile for 64-bit: start a command shell with the x64 set
of compiler tools (shortcut `x64 Native Tools Command Prompt for VS 2019`).
Then activate Conda with the `activate.bat` script in the Conda installation.

Alternately, if you're using PowerShell, you can use the utility here:
https://github.com/olegsych/posh-vs -- in order to  bring Visual Studio
compilers into your PowerShell session.  For example for 64-bit:

```
Import-BatchEnvironment 'C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvars64.bat'
$env:CONDA_FORCE_32BIT = 0
```

Or if you install the Visual Studio Build tools:

```
Import-BatchEnvironment 'C:\Program Files (x86)\Microsoft Visual Studio\2019\BuildTools\VC\Auxiliary\Build\vcvars64.bat'
$env:CONDA_FORCE_32BIT = 1
```

And for 32-bit:
```
Import-BatchEnvironment 'C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvars32.bat'
$env:CONDA_FORCE_32BIT = 1
```

Or if you install the Visual Studio Build tools:

```
Import-BatchEnvironment 'C:\Program Files (x86)\Microsoft Visual Studio\2019\BuildTools\VC\Auxiliary\Build\vcvars32.bat'
$env:CONDA_FORCE_32BIT = 0
```

Then invoke the `dist-python` target from `libsbp` (with appropriate PyPI auth).
This will need to be once for 32-bit and 64-bit.

If not using PowerShell, to compile for 32-bit: start a command shell with 
the x86 set of compiler tools (shortcut `x86 Native Tools Command Prompt for VS 2019`).
Then activate Conda with the `activate.bat` script in the Conda installation.

Prior to invoking the `dist-python` target.  Set the following global variable
to force Conda to create 32-bit environemnts:

    set CONDA_FORCE_32BIT=1

Then invoke the `dist-python` target per usual. (Side note: at some point
it was also necessary to delete libraries from `C:\Users\<user>\AppData\Roaming\Python`
in order to prevent 32-bit Conda Python from loading libraries of the wrong
architecture).

## Troubleshooting

### Error: `!!! No Python wheel (.whl) file found...`

This usually means the git checkout you're building from is not in a "clean" state.  The
build scripts will use the git command `git describe --tag --always --dirty` to generate
a version.  Either temporarily force update the tag with `git tag -f vM.N.X` (do not
push this unintentionally) and/or make sure you're submodule are up-to-date with
`git submodule update --init --checkout --recursive`.

### Tox error: `ERROR: FAIL could not package project`

Tox needs to be run with the Python it was installed with (and apparently must
run with Python 2) otherwise you'll get an error similar to:

    ERROR: FAIL could not package project - v = InvocationError('/home/ubuntu/dev/libsbp/python/.tox/.tox/bin/python setup.py sdist --formats=zip --dist-dir /home/ubuntu/dev/libsbp/python/.tox/dist', -11)

Tox also seems to have issues interacting with conda environments.  The easiest
way to work around this is to remove conda from your path and make sure tox is
installed with a Python2 version of the interpreter.

### Tox error: `ERROR: cowardly refusing to delete envdir`

Tox may fail with the following error:

    ERROR: cowardly refusing to delete `envdir` (it does not look like a virtualenv): /home/ubuntu/dev/libsbp/python/.tox/py38-nojit

There's an open tox issue for this: https://github.com/tox-dev/tox/issues/1354
-- the only workaround that resolved this was to downgrade tox:

    pip install --upgrade --force-reinstall tox==3.12.1

# Contributions

This library is developed internally by Swift Navigation. We welcome
Github issues and pull requests, as well as discussions of potential
problems and enhancement suggestions on the
[forum](https://groups.google.com/forum/#!forum/swiftnav-discuss).
