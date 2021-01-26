const os = require("os");

const core = require("@actions/core");
const exec = require("@actions/exec");

const os_setup = {
  linux: async () => {
    core.info("Setting up linux");
    await exec.exec("sudo apt-get -qq update");
    await exec.exec(
      "sudo apt-get -qq install -y pkg-config build-essential libudev-dev"
    );
  },
  darwin: async () => {
    core.info("Setting up osx");
    await exec.exec("brew install cmake");
  },
  win32: async () => {
    core.info("Setting up windows");
    core.addPath("C:\\msys64\\mingw64\\bin");
  },
};

async function main() {
  let platform = os.platform();
  let setup = os_setup[platform];

  if (!setup) {
    core.setFailed("Could not detect OS");
    process.exit(1);
  }

  try {
    await setup();
  } catch (error) {
    core.setFailed(error.message);
  }
}

main();
