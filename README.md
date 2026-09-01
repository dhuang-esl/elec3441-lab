# ELEC3441 course environment

This repository provides the verified ELEC3441 Linux environment and releases course materials progressively. The current release contains Lab 1. Later labs and homework will be added when they are announced.

Its published Docker image pins the RISC-V GNU C/C++ toolchain, Spike and the RV32 proxy kernel, RARS, Logisim-Evolution, and Ripes. It also includes native GCC, Git, and Python with Matplotlib.

The published image supports Intel/AMD and Apple Silicon. Its graphical tools run in a browser, so students use the same Linux environment on macOS, Windows, or Linux.

The repository releases course materials progressively. The host directory `student-materials` is mounted directly at `/workspace` inside the container, so edits made in either place are the same files.

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

Open <http://localhost:6080/vnc.html?autoconnect=1&resize=scale>. Working files persist in the cloned repository when the container is stopped, recreated, or deleted.

The single bind mount maps these paths:

- Host `student-materials/labs/lab1` → container `/workspace/labs/lab1`
- Host `student-materials/handouts/lab1.pdf` → container `/workspace/handouts/lab1.pdf`

The Docker image contains only the software environment. Course files come from the Git checkout, not from the image.

Launch the graphical tools from the desktop terminal with `rars`, `logisim`, or `ripes`.

The `student` account has passwordless `sudo` for installing or configuring additional software when necessary. For example:

```sh
sudo apt-get update
sudo apt-get install <package>
```

Changes under `/workspace` immediately update the host's `student-materials` directory. System packages installed with `sudo` belong to that particular container and are lost if `./manage up` recreates it; tell the teaching team if the whole class needs an additional package.

## Use VS Code

You can open the cloned repository directly in VS Code and edit files under `student-materials`. To use a terminal inside the course container, either run `./manage shell` or use Microsoft's **Dev Containers** extension:

1. Run `./manage up`.
2. In the VS Code Command Palette, choose **Dev Containers: Attach to Running Container...** and select `elec3441-lab`.
3. Open the relevant folder under `/workspace/labs` or `/workspace/homeworks`.
4. Use **Terminal > New Terminal** for compiler and simulator commands.

The browser desktop remains available for Logisim, RARS, and Ripes.

## Software for later homework

The image is already prepared for the later homework releases: Logisim and the RV32 toolchain for Homework 1, Spike and the proxy kernel for Homework 2, and native GCC plus Python/Matplotlib for Homework 3. Follow the relevant handout after the teaching team releases it.

Use `./manage stop` to stop the GUI, `./manage status` to inspect it, and `./manage shell` to open a terminal in the running container.

## Keep your work in Git

The cloned course repository is also your working copy. You may commit your changes locally, create your own branch, or connect a private fork for backup. Do not push student work to the official course repository.

Before pulling a course update, use `git status` and commit or stash unfinished changes. If an instructor update changes the same file, Git will ask you to resolve the conflict instead of silently overwriting your work.

## Receive later course releases

When the teaching team announces new material, run these commands from the cloned repository after committing or stashing your changes:

```sh
git status
git pull
./manage verify
./manage up
```

If the teaching team also announces a software-environment update, run `./manage pull` after `git pull`. See [PUBLISHING.md](PUBLISHING.md) for the instructor release procedure.
