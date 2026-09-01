# Publishing an ELEC3441 release

The repository releases student materials progressively. Only paths listed in
`student-materials/release-manifest.txt` are allowed into a verified image.
Verification fails if another file is accidentally left under `labs`,
`homeworks`, or `handouts`.

## 1. Check the release locally

```sh
./manage build
ELEC3441_IMAGE=elec3441-lab:local ./manage verify
```

## 2. Publish a version

Commit and push the release, then create a new version tag:

```sh
git add .
git commit -m "Prepare ELEC3441 release v2026.1"
git push origin main
git tag v2026.1
git push origin v2026.1
```

The `Publish course image` GitHub Actions workflow builds AMD64 and ARM64 on
separate native GitHub runners, assembles one multi-platform image, and
publishes it to `ghcr.io/dhuang-esl/elec3441-lab`.

For the first release, open the package settings on GitHub and change the
package visibility to Public. Public visibility lets students pull the image
without a GitHub login or token.

## 3. Pin the published digest

Open the completed workflow run and copy the immutable image reference from its
summary. Copy `image.ref.example` to `image.ref`, replace the placeholder with
that reference, then commit and push `image.ref`:

```sh
cp image.ref.example image.ref
git add image.ref
git commit -m "Pin the v2026.1 student image"
git push origin main
```

The file must contain exactly one reference, for example:

```text
ghcr.io/dhuang-esl/elec3441-lab@sha256:0123456789abcdef...
```

## 4. Release later material

Add only the new student-facing files. Add each released file or directory to
`student-materials/release-manifest.txt`, run the local verification again, and
publish the next tag. After the workflow succeeds, replace `image.ref` with the
new digest and push that one-file update.

Do not include solutions, marking material, or instructor-only expected results
in the repository or image.
