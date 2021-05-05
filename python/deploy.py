#!/usr/bin/env python

import os
import sys
import glob
import shutil
import platform
import tempfile
import subprocess

if platform.machine().startswith("arm"):
    ALL_PY_VERSIONS = ["3.7", "3.8"]
else:
    ALL_PY_VERSIONS = ["3.6", "3.7", "3.8"]

SKIP_PY_VERS = os.environ.get("SKIP_PY_VERS", "").split(",") 

if 'PYPI_USERNAME' not in os.environ or 'PYPI_PASSWORD' not in os.environ:
    print("\n>>> WARNING: set PYPI_USERNAME and PYPI_PASSWORD to push to PyPI\n\n")
    sys.exit(1)

PYPI_USERNAME = os.environ.get('PYPI_USERNAME', None)
PYPI_PASSWORD = os.environ.get('PYPI_PASSWORD', None)

if 'SBP_VERSION' not in os.environ:
    print("\n!!! Please set SBP_VERSION in the environment !!!\n\n")
    sys.exit(1)

SBP_VERSION = os.environ['SBP_VERSION']

USE_TEST_PYPI = bool(os.environ.get('USE_TEST_PYPI', None))

if not platform.machine().startswith("arm") and not shutil.which('conda'):
    print("\n!!! Please install conda to deploy python !!!\n\n")
    sys.exit(1)

script_dir = os.path.dirname(os.path.abspath(__file__))
repo_dir = os.path.join(script_dir, "..")

os.chdir(script_dir)

if platform.system() == "Linux" and platform.python_version().startswith("3.4"):
    DASHDASH = ["--"]
else:
    DASHDASH = []

os.environ['IS_RELEASED'] = 'y'

def twine_upload(conda_dir, wheel, py_version="3.7", use_conda=True):

    if platform.machine().startswith("arm") and py_version in ALL_PY_VERSIONS:
        cmd_prefix = ["/usr/local/bin/python{}".format(py_version), "-m"]
        if use_conda:
            raise RuntimeError("Conda with Python {} is not supported on ARM".format(py_version))
    elif py_version in ALL_PY_VERSIONS:
        cmd_prefix = ["/usr/bin/python3", "-m"]
        if use_conda:
            cmd_prefix = ["conda", "run", "-p", conda_dir] + DASHDASH
    else:
        raise RuntimeError("Unsupported Python version: {} (platform: {})".format(py_version, platform.machine()))

    if PYPI_USERNAME is not None and PYPI_PASSWORD is not None:
        invoke = subprocess.check_call if not USE_TEST_PYPI else subprocess.call
        ret = invoke(cmd_prefix + [
            "twine", "upload", "-u", PYPI_USERNAME, "-p", PYPI_PASSWORD] + ([
            "--repository-url", "https://test.pypi.org/legacy/"]
                if USE_TEST_PYPI else []
            ) + [wheel])
    else:
        print(">>> WARNING: not pushing to PyPI (one of PYPI_USERNAME or PYPI_PASSWORD was empty)")

    if USE_TEST_PYPI and ret != 0:
        print(">>> WARNING: twine upload returned exit code {}".format(ret))


def build_wheel_native(conda_dir, deploy_dir, py_version):

    print(">>> Installing native deps for: {}...".format(py_version))

    py_version_prefix = "/usr/local"
    py_version_suffix = py_version

    python = "{}/bin/python{}".format(py_version_prefix, py_version_suffix)

    subprocess.check_call(["apt-get", "update"])

    subprocess.check_call(["apt-get", "install", "-y",
        "python3", "python3-pip", "python3-dev", "python3-setuptools"
    ])
    
    subprocess.check_call([
        python, "-m",
        "pip", "install", "--upgrade", "pip"
    ])

    subprocess.check_call([
        python, "-m",
        "pip", "install", "twine", "cython", "wheel", "setuptools"
    ])

    print(">>> Installing setup deps in Python {} environment...".format(py_version))

    subprocess.check_call([
        python, "-m",
        "pip", "install", "--ignore-installed",
        "-r", "test_requirements.txt"
    ])

    suffix = "" if py_version.startswith("3.") else "27"

    subprocess.check_call([
        python, "-m",
        "pip", "install", "--ignore-installed",
        "-r", "requirements{}.txt".format(suffix),
        "-r", "setup_requirements{}.txt".format(suffix),
    ])

    run_bdist(conda_dir, deploy_dir, py_version,
              py_version_prefix=py_version_prefix,
              py_version_suffix=py_version_suffix,
              use_conda=False)


def invoke_bdist(conda_dir, use_conda, py_version_prefix="/usr", py_version_suffix="3"):

    cmd_prefix = ["{}/bin/python{}".format(py_version_prefix, py_version_suffix)]

    if use_conda:
        cmd_prefix = ["conda", "run", "-p", conda_dir] + DASHDASH + ["python"]

    subprocess.check_call(cmd_prefix + [
        "setup.py", "bdist_wheel"
    ])


def run_bdist(conda_dir,
              deploy_dir,
              py_version,
              py_version_prefix="/usr",
              py_version_suffix="3",
              use_conda=True):

    print(">>> Building staging area for deployment ...")

    old_cwd = os.getcwd()

    os.chdir(deploy_dir)
    os.mkdir('module')

    shutil.copytree(os.path.join(repo_dir, ".git"), ".git")

    shutil.copy(os.path.join(script_dir, ".coveragerc"), "module/.coveragerc")
    shutil.copy(os.path.join(script_dir, ".gitignore"), "module/.gitignore")
    shutil.copy(os.path.join(script_dir, ".flake8"), "module/.flake8")

    for dirent in glob.glob(os.path.join(script_dir, "*")):
        _, leaf_name = os.path.split(dirent)
        if os.path.isdir(dirent):
            print('Copying (recursive) {}'.format(dirent))
            shutil.copytree(dirent, os.path.join("module", leaf_name))
        else:
            print('Copying (non-recursive) {}'.format(dirent))
            shutil.copy(dirent, os.path.join("module", leaf_name))

    print(">>> Pruning ...")

    if os.path.exists("module/docs/_build"):
        shutil.rmtree("module/docs/_build")

    for dirent in glob.glob("module/build/*"):
        shutil.rmtree(dirent) if os.path.isdir(dirent) else os.unlink(dirent)

    os.chdir("module")

    print(">>> Staged to '{}'...'".format(deploy_dir))
    print(">>> Building Python wheel ...")

    invoke_bdist(conda_dir,
                 use_conda,
                 py_version_prefix=py_version_prefix,
                 py_version_suffix=py_version_suffix)

    whl_pattern = "dist/sbp-{}-*.whl".format(SBP_VERSION)
    print(">>> Uploading Python wheel (glob: {})...".format(whl_pattern))

    wheels = glob.glob(whl_pattern)
    if not wheels:
        print("\n!!! No Python wheel (.whl) file found...\n\n")
        sys.exit(1)

    wheel = wheels[0]

    print(">>> Found wheel (of {} matches): {}".format(len(wheels), wheel))

    if os.environ.get('LIBSBP_BUILD_ANY', None) is None:
        if platform.system() == "Linux" and platform.machine().startswith("x86"):
            print(">>> Running 'auditwheel' against wheel: {}".format(wheel))
            subprocess.check_call([
                "python3", "-m",
                "auditwheel", "repair", "-w", "dist", wheel
            ])

    print(">>> Copying wheel {} to {}".format(wheel, old_cwd))
    shutil.copy(wheel, old_cwd)

    wheel = wheel.replace("-linux_x86_64", "-manylinux1_x86_64")
    twine_upload(conda_dir, wheel, py_version, use_conda)


def build_wheel_conda(conda_dir, deploy_dir, py_version):

    print(">>> Creating conda environment for Python version: {}...".format(py_version))

    subprocess.check_call([
        "conda", "create", "--yes", "-p", conda_dir,
        "python={}".format(py_version)])

    if platform.system() == 'Linux' and platform.machine() == 'x86_64':
        subprocess.check_call([
            "conda", "install", "--yes", "-p", conda_dir,
            "gcc_linux-64", "gxx_linux-64"
        ])

    print(">>> Installing build deps in Python {} conda environment...".format(py_version))

    subprocess.check_call([
        "conda", "install", "-p", conda_dir, "--yes",
        "cython", "wheel", "setuptools"
    ])
    subprocess.check_call([
        "conda", "run", "-p", conda_dir] + DASHDASH + [
        "python", "-m", "pip", "install", "--upgrade", "pip"
    ])

    subprocess.check_call([
        "conda", "run", "-p", conda_dir] + DASHDASH + [
        "python", "-m", "pip", "install", "twine"
    ])

    if platform.system() == "Linux" and platform.machine().startswith("x86"):
        subprocess.check_call([
            "python3", "-m",
            "pip", "install", "auditwheel"
        ])

    print(">>> Installing setup deps in Python {} conda environment...".format(py_version))

    subprocess.check_call([
        "conda", "run", "-p", conda_dir] + DASHDASH + [
        "python", "-m", "pip", "install",
        "-r", "setup_requirements.txt",
        "-r", "test_requirements.txt",
    ])

    suffix = "" if py_version.startswith("3.") else "27"

    subprocess.check_call([
        "conda", "run", "-p", conda_dir] + DASHDASH + [
        "python", "-m", "pip", "install",
        "-r", "requirements{}.txt".format(suffix),
        "-r", "setup_requirements{}.txt".format(suffix),
    ])

    run_bdist(conda_dir, deploy_dir, py_version, use_conda=True)


def build_native_on_arm(py_version):
    if platform.system() != "Linux":
        return False
    return platform.machine().startswith("arm")


def build_wheel(conda_dir, deploy_dir, py_version):
    if py_version not in ALL_PY_VERSIONS:
        raise RuntimeError("Unsupported Python version: {py_version}, must be one of {!}".format(py_version, repr(ALL_PY_VERSIONS)))
    if build_native_on_arm(py_version):
        build_wheel_native(conda_dir, deploy_dir, py_version)
    else:
        build_wheel_conda(conda_dir, deploy_dir, py_version)


def py_versions():
    def _py_versions():
        if os.environ.get('LIBSBP_BUILD_ANY', None):
            return ["3.7"]
        return ALL_PY_VERSIONS
    for pyver in _py_versions():
        if pyver in SKIP_PY_VERS:
            continue
        yield pyver


for py_version in py_versions():

    print(">>> Building wheel for Python {}...".format(py_version))

    conda_tmp_dir = tempfile.mkdtemp()
    conda_dir = os.path.join(conda_tmp_dir, "conda")

    deploy_dir = tempfile.mkdtemp()

    try:
        build_wheel(conda_dir, deploy_dir, py_version)
    finally:
        os.chdir(script_dir)
        # Workaround a permission denied errors that happens on Windows
        if platform.system() == "Windows":
            subprocess.check_call(["rmdir", "/s", "/q", conda_dir], shell=True)
        else:
            subprocess.check_call(["rm", "-rf", conda_dir])
        if platform.system() == "Windows":
            subprocess.check_call(["rmdir", "/s", "/q", deploy_dir], shell=True)
        else:
            subprocess.check_call(["rm", "-rf", deploy_dir])
