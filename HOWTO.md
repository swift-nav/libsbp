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

2. Generate new clients and documentation by running `make
   all`. Verify that the generated code, which isn't too complicated,
   meets your expectations, as allowed messages are limited by the
   underlying language implementation. For example, you can't specify
   a message that has a variable-length array in the middle of the
   message, since the generated SBP structs for the C client will
   materialize a 0-length array C99 extension in the middle of the
   struct. GCC won't compile this.

3. Add a [`test`](spec/tests/yaml/swiftnav/sbp) case and update the
   appropriate language libaries. Run `make test`.

4. Submit a pull request.

5. If Swift's internal test tooling needs to be updated to use your
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

Oh boy, so you've decided to release a new version of libsbp.

0. Branch and tag a new release. Tag the release version:

    ```shell
    # Produces most recent tag (e.g., v0.29)
    git describe --abbrev=0 --tags
    # Increment that value, create a new one (e.g, v0.30), and push
    git tag -a INCREMENTED_TAG
    git push upstream INCREMENTED_TAG
    ```

1. Verify that package dependencies, their version numbers, and the
   libsbp version number in the C, Python, and LaTeX developer
   documentation are consistent.

2. Add to RELEASE_NOTES.md and update the CHANGELOG details with `make
   release`. Submit a pull request. This requires
   [github-changelog-generator](https://github.com/skywinder/github-changelog-generator),
   and a CHANGELOG_GITHUB_TOKEN in your PATH if you don't already have
   them.

3. Create a release on
   [GitHub](https://github.com/swift-nav/libsbp/releases) and add the
   RELEASE_NOTES.md.

4. Distribute release packages: `make dist`. You may need credentials
   on the appropriate package repositories.

5. Announce release to the
   [forum](https://groups.google.com/forum/#!forum/swiftnav-discuss).

6. Releases are not only never perfect, they never really end. Please
   pay special attention to any downstream projects or users that may
   have issues or regressions as a consequence of the release version.

# Contributions

This library is developed internally by Swift Navigation. We welcome
Github issues and pull requests, as well as discussions of potential
problems and enhancement suggestions on the
[forum](https://groups.google.com/forum/#!forum/swiftnav-discuss).
