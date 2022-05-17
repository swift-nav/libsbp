from dataclasses import dataclass

@dataclass
class ReleaseVersion:
  major: str
  minor: str
  patch: str
  patch_pre: str
  full_version: str
  is_staging: int
