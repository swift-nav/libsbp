with import <nixpkgs> {};

stdenv.mkDerivation rec {
  name = "libsbp";
  env = buildEnv { name = name; paths = buildInputs; };
  buildInputs = [
    jq
    libiconv
    stack
    zlib.dev
  ];
}
