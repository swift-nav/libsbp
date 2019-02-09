with import <nixpkgs> {};

stdenv.mkDerivation rec {
  name = "libsbp";
  env = buildEnv { name = name; paths = buildInputs; };
  buildInputs = [
    libiconv
    zlib
    clang_5
    check
    gradle
    zlib.dev
    ghc
    cabal-install
  ];
}
