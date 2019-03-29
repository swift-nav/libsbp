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
    python27Packages.setuptools
    python27Packages.virtualenv
    python27Packages.pip
    python37Full
    python37Packages.setuptools
    python27Packages.virtualenv
    python37Packages.pip
    nodejs
    coreutils
    bash
    gnumake
    gnutar
    zip
    cmake
    git
    which
  ];
  shellHook = ''
    [[ -z "$SOURCE_DATE_EPOCH" ]] || unset SOURCE_DATE_EPOCH
    rm -rf .dist.py2
    rm -rf .dist.py3
    virtualenv .dist.py2
    virtualenv .dist.py3 --python=`which python3`
    .dist.py2/bin/pip install --ignore-installed twine wheel virtualenv
    .dist.py3/bin/pip install --ignore-installed twine wheel virtualenv
    source .dist.py3/bin/activate
  '';
}
