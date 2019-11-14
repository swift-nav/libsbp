#!/usr/bin/env python

import os
import sys
import glob
import shutil
import platform
import tempfile
import subprocess

#CP27MU = "2.7u"
ALL_PY_VERSIONS = ["3.4", "3.5", "3.6", "3.7"]
AMD64_PY_VERSION = ["3.5", "3.6", "3.7"]

SKIP_PY_VERS = os.environ.get("SKIP_PY_VERS", "").split(",") 

if 'PYPI_USERNAME' not in os.environ:
    print("\n!!! Please set PYPI_USERNAME in the environment !!!\n\n")
    sys.exit(1)

PYPI_USERNAME = os.environ['PYPI_USERNAME']

if 'PYPI_PASSWORD' not in os.environ:
    print("\n!!! Please set PYPI_PASSWORD in the environment !!!\n\n")
    sys.exit(1)

PYPI_PASSWORD = os.environ['PYPI_PASSWORD']

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

#    if platform.machine().startswith("arm") and py_version == CP27MU:
#        cmd_prefix = ["/opt/cp27mu/bin/python2.7", "-m"]
#        if use_conda:
#            raise RuntimeError("Conda with Python {} is not supported on ARM".format(py_version))
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

    invoke = subprocess.check_call if not USE_TEST_PYPI else subprocess.call
    ret = invoke(cmd_prefix + [
        "twine", "upload", "-u", PYPI_USERNAME, "-p", PYPI_PASSWORD] + ([
        "--repository-url", "https://test.pypi.org/legacy/"]
            if USE_TEST_PYPI else []
        ) + [wheel])

    if USE_TEST_PYPI and ret != 0:
        print(">>> Warning: twine upload returned exit code {}".format(ret))


def build_wheel_native(conda_dir, deploy_dir, py_version):

    print(">>> Installing native deps for: {}...".format(py_version))

    py_version_prefix = "/usr/local"
    py_version_suffix = py_version

#    if py_version == CP27MU:
#        py_version_prefix = "/opt/cp27mu"
#        py_version_suffix = "2.7"

    if py_version not in ALL_PY_VERSIONS:
        raise RuntimeError("Unsupported Python version")

    python = "{}/bin/python{}".format(py_version_prefix, py_version_suffix)

    subprocess.check_call(["apt-get", "update"])

    if py_version.startswith("3."):
        subprocess.check_call(["apt-get", "install", "-y",
            "python3", "python3-pip", "python3-dev", "python3-setuptools"
        ])
    else:
        subprocess.check_call(["apt-get", "install", "-y",
            "python", "python-pip", "python-dev", "python-setuptools"
        ])
    
    subprocess.check_call([
        python, "-m",
        "pip", "install", "--upgrade", "pip"
    ])
    subprocess.check_call([
        python, "-m",
        "pip", "install", "twine", "numpy", "cython", "wheel", "setuptools"
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

#    with open("module/setup.py", "rb") as fp:
#        data = fp.read()
#    with open("module/setup.py", "wb") as fp:
#        fp.write(data.replace(b"IS_RELEASED = False", b"IS_RELEASED = True"))

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
        "pip", "install", "--upgrade", "pip"
    ])
    subprocess.check_call([
        "conda", "run", "-p", conda_dir] + DASHDASH + [
        "pip", "install", "twine", "numpy"
    ])

#    if py_version.startswith("2.7"):
#        subprocess.check_call([
#            "conda", "run", "-p", conda_dir] + DASHDASH + [
#            "pip", "install", "enum34"
#        ])

    if platform.system() == "Linux" and platform.machine().startswith("x86"):
        subprocess.check_call([
            "python3", "-m",
            "pip", "install", "auditwheel"
        ])

    print(">>> Installing setup deps in Python {} conda environment...".format(py_version))

    subprocess.check_call([
        "conda", "run", "-p", conda_dir] + DASHDASH + [
        "pip", "install", "--ignore-installed", 
        "-r", "setup_requirements.txt",
        "-r", "test_requirements.txt",
    ])

    suffix = "" if py_version.startswith("3.") else "27"

    subprocess.check_call([
        "conda", "run", "-p", conda_dir] + DASHDASH + [
        "pip", "install", "--ignore-installed", 
        "-r", "requirements{}.txt".format(suffix),
        "-r", "setup_requirements{}.txt".format(suffix),
    ])

    run_bdist(conda_dir, deploy_dir, py_version, use_conda=True)


def build_native_on_arm(py_version):
    if platform.system() != "Linux":
        return False
    return platform.machine().startswith("arm")


def build_wheel(conda_dir, deploy_dir, py_version):
    if build_native_on_arm(py_version):
        build_wheel_native(conda_dir, deploy_dir, py_version)
    else:
        build_wheel_conda(conda_dir, deploy_dir, py_version)


def py_versions():
    def _py_versions():
        if os.environ.get('LIBSBP_BUILD_ANY', None):
            return ["3.7"]
        if platform.machine().startswith("arm"):
            return ALL_PY_VERSIONS
        return AMD64_PY_VERSION
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
        if platform.system() != "Linux" or not platform.machine().startswith("arm"):
            shutil.rmtree(conda_tmp_dir)
        else:
            subprocess.check_call(["rm", "-fr", conda_dir])
        if platform.system() == "Windows":
            # Workaround a permission denied error that happens for the copied
            #   .git directory...
            subprocess.check_call(["rmdir", "/s", "/q", deploy_dir], shell=True)
        else:
            shutil.rmtree(deploy_dir)
