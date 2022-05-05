#!/usr/bin/env python

import os
import sys
import glob
import shutil
import platform
import tempfile
import subprocess

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


def twine_upload(wheel):
    cmd_prefix = ["python3", "-m"]
    if PYPI_USERNAME is not None and PYPI_PASSWORD is not None:
        invoke = subprocess.check_call if not USE_TEST_PYPI else subprocess.call
        cmd = ["twine", "upload", "-u", PYPI_USERNAME, "-p", PYPI_PASSWORD]
        cmd = cmd_prefix + cmd + (
                ["--repository-url", "https://test.pypi.org/legacy/"] if USE_TEST_PYPI else [])
        ret_wheel = invoke(cmd + [wheel])
    else:
        print(">>> WARNING: not pushing to PyPI (one of PYPI_USERNAME or PYPI_PASSWORD was empty)")

    if USE_TEST_PYPI and ret_wheel != 0:
        print(">>> WARNING: upload of wheel failed, exit code: {}".format(ret_wheel))


def invoke_bdist():
    subprocess.check_call(["python3", "setup.py", "bdist_wheel"])


def invoke_sdist():
    subprocess.check_call(["python3", "setup.py", "sdist"])


def run_bdist(deploy_dir):
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

    invoke_bdist()

    whl_pattern = "dist/sbp-{}-*.whl".format(SBP_VERSION)
    print(">>> Uploading Python wheel (glob: {})...".format(whl_pattern))

    wheels = glob.glob(whl_pattern)
    if not wheels:
        print("\n!!! No Python wheel (.whl) file found...\n\n")
        sys.exit(1)

    wheel = wheels[0]

    print(">>> Found wheel (of {} matches): {}".format(len(wheels), wheel))

    print(">>> Copying wheel {} to {}".format(wheel, old_cwd))
    shutil.copy(wheel, old_cwd)

    wheel = wheel.replace("-linux_x86_64", "-manylinux1_x86_64")
    twine_upload(wheel)

    print(">>> Building source tarball ...")

    invoke_sdist()

    tarball_pattern = "dist/sbp-{}*.tar.gz".format(SBP_VERSION)
    print(">>> Uploading source tarball (glob: {})...".format(tarball_pattern))

    tarballs = glob.glob(tarball_pattern)
    if not tarballs:
        print("\n!!! No source tarball (.tgz) file found...\n\n")
        sys.exit(1)

    tarball = tarballs[0]

    print(">>> Found source tarball (of {} matches): {}".format(len(tarballs), tarball))

    print(">>> Copying tarball {} to {}".format(tarball, old_cwd))
    shutil.copy(tarball, old_cwd)

    twine_upload(tarball)


def build_wheel(deploy_dir):
    print(">>> Installing build deps in Python environment...")
    subprocess.check_call([
        "conda", "install", "--yes",
        "wheel", "setuptools", "pip"
    ])
    subprocess.check_call(
        ["python", "-m", "pip", "install", "--upgrade", "pip"])
    subprocess.check_call(
        ["python", "-m", "pip", "install", "twine"])
    print(">>> Installing setup deps in Python environment...")
    subprocess.check_call(
        ["python", "-m", "pip", "install",
         "-r", "setup_requirements.txt",
         "-r", "test_requirements.txt"])
    subprocess.check_call(
        ["python", "-m", "pip", "install",
         "-r", "requirements.txt",
         "-r", "setup_requirements.txt"])
    run_bdist(deploy_dir)


def main():
    print(">>> Building wheel...")
    deploy_dir = tempfile.mkdtemp()
    build_wheel(deploy_dir)


if __name__ == '__main__':
    main()
