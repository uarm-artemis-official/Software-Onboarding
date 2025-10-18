# Software Onboarding Project #3: ROS2 + Docker Quickstart

This project shows how to use Docker to create a reproducible Ubuntu + ROS2 (Humble) development container, build a minimal ROS2 workspace, and run a basic talker/listener demo (C++ talker and listener).

## Project Description
The Sentry’s mini-PC runs a specific Ubuntu and ROS2 configuration. Instead of setting up a full virtual machine or dual-booting into Linux to replicate that environment, we use a lightweight Docker container. This approach provides an isolated and reproducible development setup that mirrors the mini-PC’s software stack, without the resource overhead of traditional virtualization.


## What You'll Learn
- What Docker is and why people use it
- How to install Docker (Windows & macOS) and required settings  
- How to build the provided Docker image and start a dev container  
- What is a Dockerfile
- How to run a C++ talker and listener

## What is Docker (short)
Docker packages an OS image + dependencies into a container that runs the same anywhere. Use it to avoid host OS setup differences, reproduce development environments, and isolate ROS2 installs from your local system.
(Docker in 100 Seconds)[https://www.youtube.com/watch?v=Gjnup-PuquQ]

## Installation

### Windows (Docker Desktop + WSL2)
Install Docker Desktop: https://docs.docker.com/desktop/setup/install/windows-install/
Verify:
```powershell
docker --version
```

### macOS
Install Docker Desktop for Mac: https://docs.docker.com/desktop/setup/install/mac-install/
Verify:
```bash
docker --version
```


## Project Structure
- Dockerfile — Builds Ubuntu Jammy + ROS2 Humble, Python and C++
- SOFTWARE_ONBOARDING_3.md — this readme
- More to be added

From project root (Software-Onboarding-3):

1. Build Docker image:
```powershell
# Windows PowerShell (from project folder)
docker build -t uarm-humble .
```

2. Run container (mount workspace for development):
```powershell
# Windows (use WSL path or current dir; prefer WSL mount to avoid permissions)
# Example mounting current folder:
docker run -it --rm --name ros-dev -v "%CD%:/UARM" robonav-ros:humble bash
```
Or on macOS:
```bash
docker run -it --rm --name ros-dev -v "$(pwd):/UARM" robonav-ros:humble bash
```

## Docker Commands

**docker build**: 
This tells Docker to build an image from a Dockerfile. The Dockerfile defines the environment, dependencies, and setup instructions for your container

**-t**:
The -t flag assigns a name to the image being built.


**. (dot)**:
The dot represents the build context, which is the current directory. Docker uses this directory to find your Dockerfile and any files it needs (like scripts or source code) during the build.


After running this command, you’ll have a new Docker image you can list with:
**docker images**

Then you can start a container from that image using:
docker run -it uarm-humble bash

**docker build**:
Starts a new container from a specified image

**-it**:
Combines two flags:
• -i → interactive (keeps STDIN open)
• -t → allocates a pseudo-TTY (so you get a usable terminal).
Together, these let you interact with the container shell as if it were a normal Linux terminal.

**bash**:

The command to run inside the container when it starts. Here, it launches a Bash shell, giving you access to the Ubuntu environment defined by your Dockerfile.

**docker ps**:
Show all running containers



## Inside the container — build workspace and run demo

Source the installed workspace and run nodes (open two shells):
```bash
# Shell A: talker (C++)
source /opt/ros/humble/setup.bash
ros2 run demo_nodes_cpp talker

# Shell B: listener 
source /opt/ros/humble/setup.bash
ros2 run demo_nodes_cpp listener# or

```

You should see the C++ talker publishing messages and the listener printing received messages.



