with import <nixpkgs> {};

stdenv.mkDerivation rec {
  name = "libsbp";
  env = buildEnv { name = name; paths = buildInputs; };
  buildInputs = [
    libiconv
    zlib
    clang_6
    check
    gradle
    zlib.dev
    ghc
    cabal-install
    python27Full
    python27Packages.virtualenv
    python27Packages.setuptools
    python27Packages.wheel
    python27Packages.twine
    python37Full
    python37Packages.virtualenv
    python37Packages.setuptools
    python37Packages.wheel
    python37Packages.twine
    nodejs
    coreutils
    bash
    gnumake
    gnutar
    zip
    cmake
    git
  ];
  shellHook = ''
    [[ -z "$SOURCE_DATE_EPOCH" ]] || unset SOURCE_DATE_EPOCH
  '';
}
