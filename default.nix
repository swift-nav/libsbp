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
    nodejs
    coreutils
    bash
    gnumake
    gnutar
    zip
    cmake
    git
    which
    llvm
    libcxxStdenv
  ];
  shellHook = ''  
    [[ -z "$SOURCE_DATE_EPOCH" ]] || unset SOURCE_DATE_EPOCH  
  '';
}
