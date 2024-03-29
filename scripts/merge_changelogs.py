#!/usr/bin/env python
import re
import sys
from datetime import datetime

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
    f"## [{sys.argv[1]}](https://github.com/swift-nav/libsbp/tree/{sys.argv[1]}) ({datetime.today().strftime('%Y-%m-%d')})\n",
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
    # Keep the first 2 lines from the original changelog
    f.writelines(changelog[0:2])

    # Then the new section
    f.writelines(proposed)

    # Then the rest of the original
    f.writelines(changelog[2:])
