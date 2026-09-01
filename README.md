# ELEC3441 course environment

This repository provides the verified ELEC3441 Linux environment and releases course materials progressively. The current release contains Lab 1. Later labs and homework will be added when they are announced.

Its published Docker image pins the RISC-V GNU C/C++ toolchain, Spike and the RV32 proxy kernel, RARS, Logisim-Evolution, and Ripes. It also includes native GCC, Git, and Python with Matplotlib.

The published image supports Intel/AMD and Apple Silicon. Its graphical tools run in a browser, so students use the same Linux environment on macOS, Windows, or Linux.

The repository releases course materials progressively. Student work is stored separately in the persistent Docker volume and is not overwritten by later releases.

For platform-specific installation instructions, see [ELEC3441 Docker Quick Start](ELEC3441_Docker_Quick_Start.docx).

## Start the course environment

Install Git and Docker Desktop on Windows or macOS, or Git and Docker Engine on Linux. On Windows, use an Ubuntu/WSL terminal for all commands.

Clone the course repository:

```sh
git clone https://github.com/dhuang-esl/elec3441-lab.git
cd elec3441-lab
```

Download the verified image, check it, and start the environment:

```sh
./manage pull
./manage verify
./manage up
```

The repository's [`image.ref`](image.ref) pins an immutable, verified image. Students do not need to enter a registry address or build the image themselves. The first pull can take several minutes depending on the internet connection.

Open <http://localhost:6080/vnc.html?autoconnect=1&resize=scale>. Working files persist in the Docker volume `elec3441-work` when the container is stopped or recreated.

On first start, the image copies the currently released materials into:

- `/workspace/labs/lab1`
- `/workspace/handouts/lab1.pdf`

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

## Software for later homework

The image is already prepared for the later homework releases: Logisim and the RV32 toolchain for Homework 1, Spike and the proxy kernel for Homework 2, and native GCC plus Python/Matplotlib for Homework 3. Follow the relevant handout after the teaching team releases it.

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

## Receive later course releases

When the teaching team announces an update, run these commands from the cloned repository:

```sh
git pull --ff-only
./manage pull
./manage verify
./manage up
```

Their existing files under `/workspace` remain in the `elec3441-work` volume. See [PUBLISHING.md](PUBLISHING.md) for the instructor release procedure.
