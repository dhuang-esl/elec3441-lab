# ELEC3441 course environment

This student package contains four lab handouts, three homework handouts, and their starter files. Its Docker image pins the RISC-V GNU C/C++ toolchain, Spike and the RV32 proxy kernel, RARS, Logisim-Evolution, and Ripes. It also includes native GCC and Python/Matplotlib for Homework 3.

The image builds natively on Intel/AMD or Apple Silicon. Its graphical tools run in a browser, so students use the same Linux environment on macOS, Windows, or Linux.

The repository releases course materials progressively. Student work is stored separately in the persistent Docker volume and is not overwritten by later releases.

## Start the course environment

Install Docker Desktop, unpack this package, open a terminal in this directory, and run:

```sh
./manage build
./manage verify
./manage up
```

The first build can take several minutes because the image builds the pinned Ripes, Spike, and proxy-kernel sources for your computer. Later builds reuse Docker's cache.

Open <http://localhost:6080/vnc.html?autoconnect=1&resize=scale>. Working files persist in the Docker volume `elec3441-work` when the container is stopped or recreated.

On first start, the image copies clean materials into:

- `/workspace/labs/lab1` through `/workspace/labs/lab4`
- `/workspace/homeworks/hw1` through `/workspace/homeworks/hw3`
- `/workspace/handouts`

Running `prepare-workspace` later adds any newly released files without replacing existing student work.

Launch the graphical tools from the desktop terminal with `rars`, `logisim`, or `ripes`.

The `student` account has passwordless `sudo` for installing or configuring additional software when necessary. For example:

```sh
sudo apt-get update
sudo apt-get install <package>
```

Changes under `/workspace` persist in the `elec3441-work` volume. System packages installed with `sudo` belong to that particular container and are lost if `./manage up` recreates it; add anything required for the whole class to the Dockerfile and rebuild the image instead.

## Use VS Code

For editing C, C++, or assembly, use VS Code with Microsoft's **Dev Containers** extension:

1. Run `./manage up`.
2. In the VS Code Command Palette, choose **Dev Containers: Attach to Running Container...** and select `elec3441-lab`.
3. Open the relevant folder under `/workspace/labs` or `/workspace/homeworks`.
4. Use **Terminal > New Terminal** for compiler and simulator commands.

The browser desktop remains available for Logisim, RARS, and Ripes.

## Homework software

- Homework 1: open `/workspace/homeworks/hw1/rv32_addi.circ` in Logisim. The `test/s2mem.sh` script regenerates Logisim memory images with the RV32 toolchain.
- Homework 2: run `make` in `/workspace/homeworks/hw2/benchmarks`, then use `spike ... pk <benchmark>` as shown in the handout. All eight C/C++ benchmarks are included.
- Homework 3: compile the two matrix-multiplication programs with native `gcc`. Python with Matplotlib is available for plots. Timing and inferred cache sizes depend on the host CPU and Docker virtualization, so compare results only within the same machine and container.

Use `./manage stop` to stop the GUI, `./manage status` to inspect it, and `./manage shell` to open a terminal in the running container.

## Keep your work in Git

Git is installed inside the student image. The course repository is the read-only release source; do not push personal work to it. If you want version history or an online backup, create your own private GitHub repository and initialize it under `/workspace`:

```sh
cd /workspace
git init
git branch -M main
git remote add origin https://github.com/YOUR_ACCOUNT/YOUR_PRIVATE_REPOSITORY.git
```

Then commit and push your `labs` and `homeworks` directories normally. VS Code Dev Containers can reuse Git credentials configured on the host computer.

## Share with students

You may give students this entire package so they can build it locally. For a faster and more reproducible release, publish the verified image to a course registry and pin its immutable digest. Students can then set the published image before starting:

```sh
export ELEC3441_IMAGE=ghcr.io/COURSE/elec3441-lab@sha256:DIGEST
./manage verify
./manage up
```

Replace the example with the actual registry path and digest after the image is published. The browser desktop listens only on `127.0.0.1`; do not expose its passwordless noVNC port directly to the internet.

When this repository contains `image.ref`, `./manage pull`, `./manage verify`, and `./manage up` use that pinned image automatically. Students receive a later release with:

```sh
git pull --ff-only
./manage pull
./manage verify
./manage up
```

Their existing files under `/workspace` remain in the `elec3441-work` volume. See [PUBLISHING.md](PUBLISHING.md) for the instructor release procedure.
