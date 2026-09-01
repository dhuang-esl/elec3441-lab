# Publishing ELEC3441 materials and environment images

Course materials and the Docker image have separate release cycles. The image
contains only the software environment. Students receive labs, homework, and
handouts through Git and bind-mount `student-materials` at `/workspace`.

Only paths listed in `student-materials/release-manifest.txt` are accepted by
verification. Do not include solutions, marking material, or instructor-only
expected results in this repository.

## 1. Release course material

Add the new student-facing files under `student-materials`, then add each
released file or directory to `student-materials/release-manifest.txt`.

Verify the current material against the pinned environment image:

```sh
./manage pull
./manage verify
git diff --check
git status --short
```

Review the listed changes, stage only the intended release files, then commit
and push `main`. A materials-only release does not require a Docker build or Git
tag.

```sh
git add student-materials
git commit -m "Release the next ELEC3441 materials"
git push origin main
```

Students receive the release with `git pull`. Because they edit the same tracked
files through the bind mount, announce any correction to a previously released
file so they know that Git may require a merge.

## 2. Publish a software-environment image

Publish a new image only when the Dockerfile, installed tools, or container
scripts change. Check it locally first:

```sh
./manage build
ELEC3441_IMAGE=elec3441-lab:local ./manage verify
```

Choose a new, unused tag and never move or reuse a published tag:

```sh
release_tag=v2026.2
test -z "$(git tag --list "$release_tag")"

git add Dockerfile .dockerignore container manage .github/workflows/publish-image.yml
git commit -m "Prepare ELEC3441 environment $release_tag"
git push origin main
git tag "$release_tag"
git push origin "$release_tag"
```

The `Publish course image` workflow builds and verifies AMD64 and ARM64 on
separate native runners, assembles one multi-platform image, and publishes it
to `ghcr.io/dhuang-esl/elec3441-lab`.

## 3. Pin the published digest

After the workflow succeeds, copy its immutable image reference into the single
line in `image.ref`, then commit and push that update:

```sh
git add image.ref
git commit -m "Pin verified ELEC3441 environment image"
git push origin main
```

The file must contain exactly one reference:

```text
ghcr.io/dhuang-esl/elec3441-lab@sha256:0123456789abcdef...
```

Keep the GHCR package Public and confirm that a machine without a GitHub login
can pull the pinned reference.
