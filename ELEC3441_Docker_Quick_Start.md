STUDENT SETUP GUIDE

# ELEC3441 Docker Quick Start

Configure the course environment before Lab 1

<table>
<tr>
<td><strong>HOSTS</strong><br>Windows, macOS, Linux</td>
<td><strong>FIRST SETUP</strong><br>./manage pull</td>
<td><strong>DAILY START</strong><br>./manage up</td>
<td><strong>GUI</strong><br>Browser port 6080</td>
</tr>
</table>

> **Your goal:** finish the Ready Check before your first lab. The course tools run inside one Linux container, while RARS, Logisim-Evolution, and Ripes appear in your web browser.

## 1. Before you start

1. Use a Windows 10/11, macOS, or Linux computer with a 64-bit processor.

2. Recommended: at least 8 GB RAM, 20 GB free disk space, and a stable internet connection for the first image download.

3. Enable hardware virtualization. On managed university computers, ask IT if Docker installation or virtualization is blocked.

4. Install Git, then clone the ELEC3441 course repository. Keep the repository folder until the course is complete.

## 2. Install Docker for your platform

### Windows 10 or 11

Use Docker Desktop with the WSL 2 backend. First, open PowerShell as Administrator and run:

```powershell
wsl --install
wsl –-update
```

```powershell
wsl -s Ubuntu
```

Restart Windows if requested, then install [Docker Desktop for Windows](https://docs.docker.com/desktop/setup/install/windows-install/). Start Docker Desktop and wait until the engine reports that it is running. Run all course commands from an Ubuntu/WSL terminal, not from Command Prompt.

![Docker Desktop WSL integration settings](docs/images/docker-quick-start/docker-desktop-wsl-integration.png)

Launch Docker Desktop, go to settings -&gt; Resources -&gt; WSL integration.

Enable Docker integration for WSL Ubuntu.

Hit “Apply and Restart”

![Ubuntu WSL terminal](docs/images/docker-quick-start/windows-wsl-terminal.png)

Check Ubuntu have been set to default WSL distro, use command ‘wsl’ to switch to the Linux environment. You should be able to list the files.

Note: **/mnt/c** correspond to **C:\\** in the Windows environment

### macOS

Install the matching [Docker Desktop for Mac](https://docs.docker.com/desktop/setup/install/mac-install/) version for Apple Silicon or Intel. Start Docker Desktop and wait until it finishes loading. Use the macOS Terminal for all course commands.

### Linux

Install [Docker Engine](https://docs.docker.com/engine/install/) for your distribution. Ubuntu or Debian is recommended. Run 'docker version' in a terminal to confirm that your user can access Docker without an error.

## 3. Install VS Code

Install Visual Studio Code for editing C, C++, and assembly files. You can edit the cloned repository directly. Microsoft's Dev Containers extension is optional for opening a terminal inside the course container.

## 4. Download and start the course environment

5. Open a terminal and download the ELEC3441 course repository.

```sh
git clone https://github.com/dhuang-esl/elec3441-lab.git
cd elec3441-lab
```

6. Download the verified course image. The first pull can take several minutes, depending on your connection. Do not close the terminal while it is running.

```sh
./manage pull
```

7. Verify the complete installation.

```sh
./manage verify
```

> **Expected result:** the final line should say 'ELEC3441 student image verification passed'. If it does not, see Troubleshooting on page 3.

8. Start the browser desktop with the host's student-materials directory mounted at /workspace.

```sh
./manage up
```

9. Open the graphical desktop in your browser.

[http://localhost:6080/vnc.html?autoconnect=1&amp;resize=scale](http://localhost:6080/vnc.html?autoconnect=1&resize=scale)

![ELEC3441 browser desktop](docs/images/docker-quick-start/browser-desktop.png)

## 5. Attach VS Code

10. Open the VS Code Command Palette.

11. Choose 'Dev Containers: Attach to Running Container...'.

12. Select 'elec3441-lab'.

13. Open student-materials/labs/lab1 on the host, or /workspace/labs/lab1 when attached to the container.

14. Use Terminal &gt; New Terminal for compiler and simulator commands.

## Ready Check

15. ./manage pull and ./manage verify complete successfully.

16. The browser desktop opens at localhost:6080.

17. Typing rars, logisim, or ripes in the browser desktop terminal launches the expected tool.

18. VS Code can edit student-materials directly, or attach to elec3441-lab and open /workspace.

19. You understand that host student-materials and container /workspace are the same files.

## 6. Everyday commands

**Start or recreate the environment:** Run ./manage up, then open the browser desktop.

**Stop the environment:** Run ./manage stop.

**Open a terminal inside the container:** Run ./manage shell.

**Check whether the container is running:** Run ./manage status.

> Your work persists on the host: student-materials is bind-mounted at /workspace, so container edits immediately update the cloned repository.

## 7. Receive course updates

Before receiving new material, commit or stash your changes. Then update the cloned repository and resolve any Git conflicts.

```sh
git status
git pull
./manage verify
./manage up
```

The pulled files appear immediately under /workspace. If an instructor update changes a file you edited, Git will ask you to merge it instead of silently overwriting your work.

## 8. Troubleshooting

### Docker command not found

Start Docker Desktop. On Windows, open Ubuntu/WSL and run docker version. On Linux, confirm Docker Engine is installed and your account has permission to use it.

### Permission denied when running ./manage

Run 'chmod +x manage', then repeat the original ./manage command.

### The browser desktop does not open

Run './manage status', then './manage up'. Wait a few seconds and reload the browser page. Confirm that no other application is already using port 6080.

### The pull or verification fails

Check Docker, internet access, free disk space, and 'git status'. Rerun './manage pull' followed by './manage verify'. If failure continues, send the teaching team your OS/CPU, failed command and full error, outputs of 'docker version', 'git status', and './manage status', and a screenshot.

ELEC3441 Computer Architecture
