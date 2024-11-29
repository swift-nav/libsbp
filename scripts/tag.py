#!/usr/bin/env python

import sys
from datetime import datetime
import os
import re
import argparse
import subprocess

DOCKER_IMAGE = "swiftnav/libsbp-build:2023-12-19"
PWD = os.getcwd()

PREP_FOR_NEXT_RELEASE_FINISHED_MSG = """
A new commit has been generated and all language bindings rebuilt to take on a 'dirty' version number. 

After dismissing this message the commit will be shown .If everything appears ok you can push to master straight away.

If there are any mistakes now is the time to correct them. Make any changes which are quired then update the tag by running:

git add <files>
git commit --amend -m "prep for next release #no_auto_pr"

Once you have fixed everything you can push to master
"""

TAG_FINISHED_MSG = """
A new commit and tag have been created, all language bindings and documentation have been rebuilt, and the changelog updated.

After dismissing this message the commit will be shown. If everything looks good you can push to master straight away and continue with distribution.

If there are any mistakes now is the time to correct them. Make any changes which are required then update the tag by running:

git add <files>
git commit --amend -a -m "Release <VERSION>"
git tag -f -a <VERSION> -m "Version <VERSION> of libsbp."

Once you have fixed everything you can push to master

Once pushed prepare for the next release by running this script again with the "-p" flag.
"""

COMMIT_MSG = ""
TAG_MSG = ""
TAG_NAME = ""


def run_command(cmd: list, expect_success=True, docker=False):
    if docker:
        cmd = [
            "docker",
            "run",
            "-it",
            "--rm",
            "-v",
            f"{PWD}:/mnt/workspace",
            "-t",
            DOCKER_IMAGE,
        ] + cmd

    result = subprocess.run(cmd, capture_output=True, text=True)

    if result.returncode != 0 and expect_success:
        print(f"Command failed: {cmd}")
        print(result.stdout)
        print(result.stderr)
        sys.exit(1)

    return result.stdout


def get_current_tag():
    return run_command(
        ["git", "describe", "--match", "v*", "--always", "--tags"]
    ).strip()


def current_commit_is_tag():
    return re.match(r"^v[0-9]+\.[0-9]+\.[0-9]+$", get_current_tag())


def get_next_tag():
    current_tag = get_current_tag()
    major, minor, patch = current_tag.split(".")[:3]

    if "-" in patch:
        patch = patch.split("-")[0]

    return f"{major}.{minor}.{int(patch)+1}"


def fn_not_provided():
    assert False


class Step:
    def __init__(self, name, fn=fn_not_provided, args={}):
        self.name = name
        self.fn = fn
        self.args = args

    def run(self, index, total):
        print(f"[{index}/{total}] {self.name}")
        self.invoke()

    def invoke(self):
        self.fn(**self.args)


class CreateInitialCommit(Step):
    def __init__(self):
        Step.__init__(
            self,
            "Create initial commit",
            run_command,
            {"cmd": ["git", "commit", "--allow-empty", "-m", COMMIT_MSG]},
        )


class CreateInitialTag(Step):
    def __init__(self):
        Step.__init__(
            self,
            "Create initial tag",
            run_command,
            {"cmd": ["git", "tag", "-a", args.tag, "-m", TAG_MSG]},
        )


class UpdateCommit(Step):
    def __init__(self):
        Step.__init__(
            self,
            "Amend commit",
            run_command,
            {"cmd": ["git", "commit", "--amend", "-a", "-m", COMMIT_MSG]},
        )


class UpdateTag(Step):
    def __init__(self):
        Step.__init__(
            self,
            "Update tag",
            run_command,
            {"cmd": ["git", "tag", "-f", "-a", args.tag, "-m", TAG_MSG]},
        )


class BuildLanguages(Step):
    def __init__(self, languages):
        if args.generate_only:
            targets = ["gen-{}".format(lang) for lang in languages]
        else:
            targets = languages
        Step.__init__(
            self,
            f"Build {"" if args.generate_only else "and test "}languages: {', '.join(languages)}",
            run_command,
            {"cmd": ["make", *targets], "docker": True},
        )


class BuildDocumentation(Step):
    def __init__(self):
        Step.__init__(
            self,
            "Build documentation",
            run_command,
            {"cmd": ["make", "docs"], "docker": True},
        )


class GenerateDraftChangelog(Step):
    def __init__(self):
        Step.__init__(
            self,
            "Generate draft changelog",
            run_command,
            {"cmd": ["make", "release"]},
        )


class MergeChangelogs(Step):
    def __init__(self):
        Step.__init__(self, "Merge changelogs")

    def invoke(self):
        with open("DRAFT_CHANGELOG.md", "r") as f:
            draft = f.readlines()

        # The first 4 lines are just the title and "unreleased" headers which we will recreate later
        draft = draft[4:]

        # The first line should now be the first real line of the "unreleased" section which is always a link to the full changelog. Find the next heading and discard everything afterwards
        assert draft[0].startswith("[Full Changelog]")

        for i in range(1, len(draft)):
            if draft[i].startswith("## [v"):
                draft = draft[: i - 1]
                break

        proposed = [
            f"## [{args.tag}](https://github.com/swift-nav/libsbp/tree/{args.tag}) ({datetime.today().strftime('%Y-%m-%d')})\n",
            "\n",
        ]

        # Strip out anything which looks like a Jira ticket number
        for i in range(len(draft)):
            proposed.append(re.sub(r"\\\[[A-Z]*-[0-9]*\\\](?=[^(])", r"", draft[i]))
        proposed.append("\n")
        print("Proposed new changelog section")
        print("\n".join(proposed))

        with open("CHANGELOG.md", "r") as f:
            changelog = f.readlines()

        with open("CHANGELOG.md", "w") as f:
            # Keep the first 2 lines from the origin alchangelog
            f.writelines(changelog[0:2])

            # Then the new section
            f.writelines(proposed)

            # Then the rest of the original
            f.writelines(changelog[2:])

        os.remove("DRAFT_CHANGELOG.md")


class ShowFinishedBanner(Step):
    def __init__(self, msg):
        Step.__init__(self, "Finished")
        self.__msg = msg

    def invoke(self):
        print(self.__msg)
        input("Press Enter to continue...")


class ShowHead(Step):
    def __init__(self):
        Step.__init__(self, "Show head", run_command, {"cmd": ["git", "show", "HEAD"]})


if __name__ == "__main__":
    if (
        not os.path.exists("spec")
        or not os.path.exists("generator")
        or not os.path.exists("scripts")
    ):
        print("This script must be run from the root of the libsbp repository")
        sys.exit(1)

    if (
        subprocess.run(["git", "diff", "--exit-code"], capture_output=True).returncode
        != 0
    ):
        print(
            "Working directory is not clean. Remove any and all changes before running this command"
        )
        sys.exit(1)

    parser = argparse.ArgumentParser(
        description=f"When run without arguments will tag the next version of libsbp which will be {get_next_tag()}"
    )

    parser.add_argument(
        "-t", "--tag", type=str, required=False, default=get_next_tag(), help="New tag"
    )
    parser.add_argument(
        "-p",
        "--prep_for_next_release",
        action="store_true",
        required=False,
        default=False,
        help="Prep for next release",
    )
    parser.add_argument(
        "-g",
        "--generate_only",
        action="store_true",
        required=False,
        default=False,
        help="Don't run tests, just generate sources",
    )

    global args
    args = parser.parse_args()

    steps = []

    if args.prep_for_next_release:
        if not current_commit_is_tag():
            print("Can only prep for next release from a properly tagged commit")
            sys.exit(1)

        COMMIT_MSG = "prep for next release #no_auto_pr"

        steps.append(CreateInitialCommit())
        steps.append(BuildLanguages(["python"]))
        steps.append(UpdateCommit())
        steps.append(
            BuildLanguages(
                ["java", "javascript", "protobuf", "c", "haskell", "javascript", "rust"]
            )
        )
        steps.append(UpdateCommit())
        steps.append(BuildLanguages(["javascript"]))
        steps.append(UpdateCommit())
        steps.append(BuildLanguages(["kaitai"]))
        steps.append(UpdateCommit())
        steps.append(ShowFinishedBanner(PREP_FOR_NEXT_RELEASE_FINISHED_MSG))
        steps.append(ShowHead())

    else:
        COMMIT_MSG = f"Release {args.tag}"
        TAG_MSG = f"Version {args.tag} of libsbp."

        if not re.match(r"^v[0-9]+\.[0-9]+\.[0-9]+$", args.tag):
            print(f"Invalid tag: {args.tag}")
            sys.exit(1)

        if (
            subprocess.run(["git", "show", args.tag], capture_output=True).returncode
            == 0
        ):
            print(f"Tag {args.tag} already exists")
            sys.exit(1)

        input(f"About to release libsbp {args.tag}. Press Enter to continue...")

        steps.append(CreateInitialCommit())
        steps.append(CreateInitialTag())
        steps.append(BuildLanguages(["python"]))
        steps.append(UpdateCommit())
        steps.append(UpdateTag())
        steps.append(
            BuildLanguages(
                ["java", "javascript", "protobuf", "c", "haskell", "javascript", "rust"]
            )
        )
        steps.append(UpdateCommit())
        steps.append(UpdateTag())
        steps.append(BuildLanguages(["javascript"]))
        steps.append(UpdateCommit())
        steps.append(UpdateTag())
        steps.append(BuildLanguages(["kaitai"]))
        steps.append(UpdateCommit())
        steps.append(UpdateTag())
        steps.append(BuildDocumentation())
        steps.append(UpdateCommit())
        steps.append(UpdateTag())
        steps.append(GenerateDraftChangelog())
        steps.append(MergeChangelogs())
        steps.append(UpdateCommit())
        steps.append(UpdateTag())
        steps.append(ShowFinishedBanner(TAG_FINISHED_MSG))
        steps.append(ShowHead())

    for i, step in enumerate(steps):
        step.run(i + 1, len(steps))
