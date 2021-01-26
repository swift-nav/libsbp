const fs = require("fs");
const path = require("path");

const artifact = require("@actions/artifact");
const core = require("@actions/core");
const github = require("@actions/github");
const mime = require("mime");

const context = github.context;
const ghClient = github.getOctokit(process.env.GITHUB_TOKEN);

process.on("unhandledRejection", (err) => {
  core.error(err);
  core.setFailed(err.message);
});

async function downloadArtifacts(dir) {
  core.info(`downloading artifacts...`);
  let artifactClient = artifact.create();
  return artifactClient.downloadAllArtifacts(dir);
}

async function listDir(dir) {
  let subdirs = await fs.promises.readdir(dir);
  let files = await Promise.all(
    subdirs.map(async (subdir) => {
      const res = path.resolve(dir, subdir);
      return (await fs.promises.stat(res)).isDirectory() ? listDir(res) : res;
    })
  );
  return files.reduce((a, f) => a.concat(f), []);
}

async function createRelease() {
  core.info(`creating release...`);

  let { owner, repo } = context.repo;

  let tag = context.ref.replace("refs/tags/", "");

  let response = await ghClient.repos.createRelease({
    owner,
    repo,
    name: tag,
    tag_name: tag,
    body: "",
    draft: false,
    prerelease: false,
    target_commitish: context.sha,
  });

  return response.data;
}

async function upload(filename, url) {
  core.info(`uploading ${filename}...`);

  let file = await fs.promises.readFile(filename);

  return ghClient.repos.uploadReleaseAsset({
    file,
    url,
    name: path.basename(filename),
    headers: {
      "content-length": file.length,
      "content-type": mime.getType(filename) || "application/octet-stream",
    },
  });
}

async function main() {
  let dir = "./artifacts";

  let download = async () => {
    let artifacts = await downloadArtifacts(dir);
    core.info(`found artifacts:\n${JSON.stringify(artifacts, null, 2)}`);
    return listDir(dir);
  };

  let create = async () => {
    let release = await createRelease();
    core.info(`created release:\n${JSON.stringify(release, null, 2)}`);
    return release;
  };

  let [files, release] = await Promise.all([download(), create()]);

  core.info("starting artifact upload(s)");

  for (let file of files) {
    let res = await upload(file, release.upload_url);
    core.info(`upload complete:\n${JSON.stringify(res, null, 2)}`);
  }
}

main();
