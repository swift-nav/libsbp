libsbp Development Procedures
=============================

<!-- toc -->

- [Adding and Testing New Messages](#adding-and-testing-new-messages)
  * [Generating missing tests](#generating-missing-tests)
- [Message Guidelines](#message-guidelines)
- [Releasing New Versions of the Library](#releasing-new-versions-of-the-library)
  * [Using Docker](#using-docker)
  * [The Process](#the-process)
- [Installing QuickType](#installing-quicktype)
- [Distributing Rust](#distributing-rust)
- [Distributing Python](#distributing-python)
  * [Troubleshooting](#troubleshooting)
    + [Error: `!!! No Python wheel (.whl) file found...`](#error--no-python-wheel-whl-file-found)
    + [Tox error: `ERROR: FAIL could not package project`](#tox-error-error-fail-could-not-package-project)
    + [Tox error: `ERROR: cowardly refusing to delete envdir`](#tox-error-error-cowardly-refusing-to-delete-envdir)
- [Distributing Java](#distributing-java)
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

3. If adding a new "group" of messages (adding a new YAML file to
   `spec/yaml/swiftnav/sbp`), add the new message group to 
   `python/sbp/table.py` and `javascript/sbp/msg.js`. 

4. Generate new clients and documentation by running `make
   all`. Verify that the generated code, which isn't too complicated,
   meets your expectations, as allowed messages are limited by the
   underlying language implementation. For example, you can't specify
   a message that has a variable-length array in the middle of the
   message, since the generated SBP structs for the C client will
   materialize a 0-length array C99 extension in the middle of the
   struct. GCC won't compile this.

5. (Optional) Add a [`test`](spec/tests/yaml/swiftnav/sbp) case and
   update the appropriate language libaries using `make gen`.
   If a test case is not added, increment `EXPECTED_MISSING_MESSAGES`
   in `python/tests/sbp/test_messages.py`.

6. Run `make test`.

7. Submit a pull request.

8. If Swift's internal test tooling needs to be updated to use your
   new message, deploy the updated Python client first, and then the C
   client. We haven't quite decided on the details of this process.

##  Generating missing tests
There are some tools that can assist with generating YAML based tests, like the
ones already defined in the [`test`](spec/tests/yaml/swiftnav/sbp) directory.
These YAML files are used to generate tests in the various languages that libsbp
supports, to ensure that serializing and deserializing messages works as
intended

### Existing Messages
For messages that are already being sent (eg: by Starling, or by a Piksi), the
`generator/missing.py` script can be used to connect to a socket and
automatically generate tests for any received messages that do not already have
tests.

Usage for `missing`:

```shell
python missing.py --host [HOST] --port [PORT]
```

### New Messages
The `json2test` script can be used to automatically generate tests for newly
defined messages.

To use `json2test` a JSON file should be hand written with example contents of a
message. For example, to generate tests for the `MSG_HEARTBEAT` message (which
contains a single field named `flags`), you would generate a JSON file of the
form:

```json
{
   "msg_type": 65535,
   "flags": 12345,
   "sender": 9876
}
```

And then generate a test for using `json2test` with:

```shell
PYTHONPATH="python/" python generator/json2test.py --input heartbeat.json --output spec/tests/yaml/swiftnav/sbp/system/test_MsgHeartbeat.yaml
```

Usage for `json2test`

```shell
python json2test --input [PATH_TO_JSON_IN] --output [PATH_TO_YAML_OUT]
```

* The `msg_type` can also be provided through a CLI parameter, with `--msg-id
  [MESSAGE_ID]`

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

    docker run -e SBP_TOX_PARALLEL=auto -v $PWD:/mnt/workspace \
      -i -t swiftnav/libsbp-build:2022-06-14

You can invoke individual stages like so:

    docker run -e SBP_TOX_PARALLEL=auto -v $PWD:/mnt/workspace \
      -i -t swiftnav/libsbp-build:2022-06-14 \
      /bin/bash -c "make python"

Check this [link](https://hub.docker.com/r/swiftnav/libsbp-build/tags) for newer tags.

## The Process

Oh boy, so you've decided to release a new version of libsbp.  It's recommended
this process is performed using the above docker container.  You'll likely want
to run the git commands outside of the container and the `make ...` commands
inside the container (so you don't have to setup git inside the docker container).

1. It's easiest to do this on the master branch. Start by tagging the release version:

    ```shell
    # Produces most recent tag (e.g., v2.7.5)
    git describe --abbrev=0 --tags
    # Increment that value, create a new one (e.g, v2.7.6)
    git tag -a <INCREMENTED_TAG> -m "Version <INCREMENTED_TAG> of libsbp."
    ```

    For library versions (i.e. `<INCREMENTED_TAG>`) we try to follow 
    [SemVer](https://semver.org/).  For message versioning refer to this [document
    on versioning](./VERSIONING.md).
    
2. Make sure that the repo is reported as clean, e.g.

    ```shell
    git describe --tags --dirty --always
    ```

   This will ensure that version information for language libraries
   will be generated cleanly.

3. Run make targets for each language and re-tag.  For python:

    ```shell
    make python
    git add python/sbp/RELEASE-VERSION
    git commit -m 'Release <INCREMENTED_TAG>'
    git tag -f -a INCREMENTED_TAG -m "Version <INCREMENTED_TAG> of libsbp."
    ```

   For Java, jsonschema, and Protobuf (these should not require bumping the git tag,
   unless the geneated files are out of date):

    ```shell
    make java jsonschema protobuf
    ```

   For C, Haskell and JavaScript:

    ```shell
    make c haskell javascript rust
    git add c/include/libsbp/version.h haskell/sbp.cabal javascript/sbp/RELEASE-VERSION package.json package-lock.json rust/sbp/Cargo.toml
    git commit --amend -a -m 'Release <INCREMENTED_TAG>'
    git tag -f -a INCREMENTED_TAG -m "Version INCREMENTED_TAG of libsbp."
    ```

4. Finally, build the docs:

    ```shell
    make docs
    ```
   
   Be sure to inspect the [docs](docs/sbp.pdf) manually, as LaTeX sometimes needs to be run multiple
   times to compile properly. If something looks off with the docs, run `make docs` repeatedly until 
   the issue is fixed.

   Then commit the docs and re-tag:

    ```shell
    git add docs/sbp.pdf
    git commit --amend -a -m 'Release <INCREMENTED_TAG>'
    git tag -f -a INCREMENTED_TAG -m "Version INCREMENTED_TAG of libsbp."
    ```

5. Verify that package dependencies, their version numbers, and the
   libsbp version number in the C, Python, JavaScript, and LaTeX developer
   documentation are consistent.

6. Push the release to GitHub:
    ```shell
    git push origin master <INCREMENTED_TAG>
    ```

7. Update the CHANGELOG details with `make release`. Submit a pull request and
   get it merged. This requires a GitHub token to be loaded into your environment
   at `CHANGELOG_GITHUB_TOKEN`.  The Makefile will use docker to run the
   tool that generates a `DRAFT_CHANGELOG.md`.

   It's generally a good idea to scrub any internal ticket numbers from
   `DRAFT_CHANGELOG.md` as they add uncessary noise for customers.

7. Create a release on
   [GitHub](https://github.com/swift-nav/libsbp/releases) and add the
   section for the new release from `DRAFT_CHANGELOG.md` to the release
   notes.

   It's also nice to add a link to the protocol docs for that release
   below the "Full Changelog" link, for example:

   ```markdown
   [Protocol Documentation](https://github.com/swift-nav/libsbp/blob/v3.4.6/docs/sbp.pdf)
   ```

8. Prep for the next development cycle.  Add the new release section from
   `DRAFT_CHANGELOG.md` to `CHANGELOG.md` and re-run `make release`.

    ```
    vim/emacs/nano CHANGELOG.md  # add new change log entries
    git add CHANGELOG.md
    make all
    git add python/sbp/RELEASE-VERSION c/include/libsbp/version.h haskell/sbp.cabal javascript/sbp/RELEASE-VERSION package.json package-lock.json rust/sbp/Cargo.toml docs/sbp.pdf
    git commit -m 'update CHANGELOG.md, prep for next release #no_auto_pr'
    git push origin master
    ```

9. Distribute release packages.  You can attempt to run all releases
   with `make dist` -- this will likely not work through... it is
   advisable to run each dist target separately.  In particular:

   - `make dist-javascript`
   - `make dist-haskell`
   - `make dist-rust` (see section on Rust below)
   - `make dist-python` (see section on Python below)
   - `make dist-java` (see section on Java below)

   You may need credentials on the appropriate package repositories. Ignore the
   GPG error in `stack`, the package will get uploaded correctly anyway.  If
   the release is a Python only change it may be appropriate to just publish to
   PyPI with `make dist-python` (see section on Python below) -- we typically
   update all other supported languages when we make an official firmware
   release.

10. Releases are not only never perfect, they never really end. Please
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

# Distributing Rust

To distribute Rust.  Use the `cargo-release` tool:

```
cargo install cargo-release
```

**FIRST** just try running the `dist-rust` target:

```
make dist-rust
```

If that doesn't work (consider fixing the make target), otherwise try releasing
`sbp` and `sbp2json` crates separately, first `sbp`, this will do a dry run
first:

```
cargo release --package sbp <INCREMENTED_TAG>
```

Then use `--execute` to actually run the release:

```
cargo release --package sbp <INCREMENTED_TAG> --execute
```

Next, release `sbp2son`, first do a dry-run:

```
cargo release --package sbp2json <INCREMENTED_TAG>
```

Then, reset any modifications from the dry run, and then actually release `sbp2son`:

```
git checkout .
cargo release --package sbp2json <INCREMENTED_TAG> --execute
```

Then rollback any commits that are created:

```
git reset --hard v<INCREMENTED_TAG>
```

# Distributing Python

The build of the libsbp wheel can be done via the `libsbp-build` container
described above.

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

# Distributing Java

To distribute java, ensure you have the correct credentials and prerequisites
- Gradle 7+
- gradle.properties
- Sonatype deployer account
- Your own GPG key

## Generating GPG key for Java

SonaType open source repo requires a GPG key for signatures.  Generate GPG key via:

```shell
gpg --gen-key
gpg --export-secret-keys >keys.gpg
gpg --keyserver keyserver.ubuntu.com --send-keys <KEY_ID>
```

To locate the value for `signing.keyId` (needed below) run:

```shell
❯ gpg --list-keys --keyid-format short                                                                                                                              (base)
/home/ubuntu/.gnupg/pubring.kbx
-------------------------------
pub   rsa3072/AB7D02BF 2022-05-03 [SC] [expires: 2024-05-02]
      573C656383B86BBD618F4ABCFEB6DDB1AB7D02BF
uid         [ultimate] Jason Anthony Mobarak <jason@swift-nav.com>
sub   rsa3072/BB59B113 2022-05-03 [E] [expires: 2024-05-02]
```

The `signing.keyId` value to use from above is `BB59B113`. The `/keys` folder
to should map to location where your gpg key will be stored. Then, create
`gradle.properties` in the `java` directory as follows:


```shell
# last 8 digit of gpg key
signing.keyId=xxx
# password for gpg key
signing.password=xxx
# path to exported secret gpg keys
signing.secretKeyRingFile=/keys/keys.gpg

# sonatype logins
ossrhUsername=xxx
ossrhPassword=xxx
```

Modify `ossrhUsername` and `ossrhPassword` with the sonatype deployer account
(or an individual one with deployer role).  See [SonaType getting started
guide](https://central.sonatype.org/publish/publish-guide/) for more details.
Internal Swift developers should have access to shared credentials via
LastPass.

For more info see: <https://docs.gradle.org/current/userguide/signing_plugin.html>

Now, invoke docker like this in order to run the `dist-java` task:

```shell
docker run -v $HOME/Documents:/keys -v $PWD:/mnt/workspace -i -t swiftnav/libsbp-build:2022-06-14
```

To publish, you'll run `make dist-java` (which will run `gradle sign` and
`gradle publish`). After publishing, go to [Nexus Repository
Manager](https://s01.oss.sonatype.org/). Select the deployed version, close the
staging repository and release to finish it off.

Follow the instructions here for how to "close" and then "release" and staging
repository on SonaType's repository manager:

- <https://central.sonatype.org/publish/release>

# Contributions

This library is developed internally by Swift Navigation. We welcome
GitHub issues and pull requests, as well as discussions of potential
problems and enhancement suggestions.
