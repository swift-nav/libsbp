libsbp Development Procedures
=============================

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

Oh boy, so you've decided to release a new version of libsbp. It's recommended
this process is performed on a Mac, as it has been known to go wrong on Linux.

The v1.2.5 release for Python on PyPi failed to install due to missing
`requirements.txt` file in the uploaded archive after a deployment was done on
Ubuntu 16.04.

0. Branch and tag a new release. Tag the release version:

    ```shell
    # Produces most recent tag (e.g., v0.29)
    git describe --abbrev=0 --tags
    # Increment that value, create a new one (e.g, v0.30), and push
    git tag -a INCREMENTED_TAG -m "Version INCREMENTED_TAG of libsbp."
    ```

1. Run `make all`.  If running the release macOS you may need to install
   llvm though brew (recommend installing llvm 6 with `brew instal llvm@6`)
   then add it to your path with `export PATH=$(brew --prefix llvm@6)/bin:$PATH`.
   You can also use Nixpkgs to setup a complete build environment for
   running a release.  [Install Nixpkgs](https://nixos.org/nix/download.html)
   and then run `nix-shell` prior to running `make all`.

2. This will bump versions in the following files:
   - `python/sbp/RELEASE-VERSION`
   - `docs/sbp.pdf`
   - `haskell/sbp.cabal`
   - `package.json`
   - `c/include/libsbp/version.h`
   - `package-lock.json` -- you can typically revert all the changes in this
     file except for the libsbp version change:
     ```shell
     git add -p package-lock.json
     # enter 'y' for version change, 'd' to stop adding changes
     git commit -m 'package-lock.json version bump'
     git checkout package-lock.json
     ```
   Commit the docs, these above version bumps and re-tag:
   ```shell
   git add docs/sbp.pdf
   git commit -m 'Update docs'
   git add python/sbp/RELEASE-VERSION haskell/sbp.cabal.m4 package.json c/include/libsbp/version.h
   git commit -m 'Version bumps'
   git tag -f -a INCREMENTED_TAG -m "Version INCREMENTED_TAG of libsbp."
   ```

3. Verify that package dependencies, their version numbers, and the
   libsbp version number in the C, Python, JavaScript, and LaTeX developer
   documentation are consistent.

   - JavaScript: Manually update `package-lock.json`.

   - Others: should be automatically extracted from git tag

4. Update the CHANGELOG details with `make release`. Submit a pull request and
   get it merged. This requires
   [github-changelog-generator](https://github.com/skywinder/github-changelog-generator),
   and a `CHANGELOG_GITHUB_TOKEN` in your `PATH` if you don't already have
   them.

5. After the release PR is merged, recreate the tag:
    ```shell
    git checkout master
    git pull
    git tag -d INCREMENTED_TAG
    git tag -a INCREMENTED_TAG -m "Version INCREMENTED_TAG of libsbp."
    git push origin INCREMENTED_TAG
    ```

6. Create a release on
   [GitHub](https://github.com/swift-nav/libsbp/releases) and add the
   RELEASE_NOTES.md.

7. Distribute release packages.  You can attempt to run all releases
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

8. Releases are not only never perfect, they never really end. Please
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

Python distribution requires compilation for the JIT accelerated `sbp.jit`
package.  This package uses the Python `numba` library, which supports AOT
compilation of a native Python extension.  The distributions for each platform
can be created by running the `make dist-python` target on each platform
(Windows, Mac OS X, Linux x86/ARM through docker).

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

The Linux x86 build of libsbp can be done throuch docker via the "manylinux"
project by running the following set of commands:
```
docker build -f python/Dockerfile.x86_64 -t libsbp-amd64 .
docker run -v libsbp-amd64-root:/root -v $PWD:/work --rm -it libsbp-amd64 /bin/bash
cd /work
make dist-python PYPI_USERNAME=swiftnav PYPI_PASSWORD=...
```

The Linux ARM build of libsbp can be done through docker via the following set
of commands:
```
docker build -f python/Dockerfile.arm -t libsbp-arm .
docker run -v libsbp-arm-root:/root -v $PWD:/work --rm -it swiftnav/piksi-tools-stretch-arm:2019.06.25 libsbp-arm /bin/bash
cd /work
make dist-python PYPI_USERNAME=swiftnav PYPI_PASSWORD=...
```

## Building on Windows

In order to build on Windows, first install the necessary compilers per the
instructions [on this Microsoft developer blog][1] install the 64-bit Python
3.7 version of [Conda][2]

[1]: https://devblogs.microsoft.com/python/unable-to-find-vcvarsall-bat/
[2]: https://docs.conda.io/en/latest/miniconda.html

In order to compile for 64-bit: start a command shell with the x64 set
of compiler tools (shortcut `x64 Native Tools Command Prompt for VS 2019`).
Then activate Conda with the `activate.bat` script in the Conda installation.

Invoke the `dist-python` target from `libsbp` (with appropriate PyPI auth).

In order to compile for 32-bit: start a command shell with the x86 set
of compiler tools (shortcut `x86 Native Tools Command Prompt for VS 2019`).
Then activate Conda with the `activate.bat` script in the Conda installation.

Prior to invoking the `dist-python` target.  Set the following global variable
to force Conda to create 32-bit environemnts:
```
set CONDA_FORCE_32BIT=1
```

Then invoke the `dist-python` target per usual. (Side note: at some point
it was also necessary to delete libraries from `C:\Users\<user>\AppData\Roaming\Python`
in order to prevent 32-bit Conda Python from loading libraries of the wrong
architecture).

# Contributions

This library is developed internally by Swift Navigation. We welcome
Github issues and pull requests, as well as discussions of potential
problems and enhancement suggestions on the
[forum](https://groups.google.com/forum/#!forum/swiftnav-discuss).
