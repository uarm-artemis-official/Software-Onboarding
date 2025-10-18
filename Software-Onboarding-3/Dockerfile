# ubuntu 22.04 == ubuntu:jammy
FROM ubuntu:jammy

ENV DEBIAN_FRONTEND=noninteractive
SHELL ["/bin/bash", "-o", "pipefail", "-c"]

# Enable universe, install base packages (software-properties-common provides add-apt-repository)
RUN apt-get update \
 && apt-get install -y --no-install-recommends \
    software-properties-common \
    apt-transport-https \
    ca-certificates \
    locales \
    curl \
    gnupg \
    lsb-release \
    build-essential \
    git \
    python3-pip \
    sudo \
 && add-apt-repository universe \
 && rm -rf /var/lib/apt/lists/*

# Set locale
RUN locale-gen en_US en_US.UTF-8
ENV LANG=en_US.UTF-8
ENV LC_ALL=en_US.UTF-8

# Add ROS2 GPG key and repo (safer with signed-by)
RUN curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key | gpg --dearmor -o /usr/share/keyrings/ros-archive-keyring.gpg \
 && echo "deb [signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu $(lsb_release -cs) main" \
    > /etc/apt/sources.list.d/ros2-latest.list

# Install ROS2 and colcon (colcon is available from universe)
RUN apt-get update \
 && apt-get install -y --no-install-recommends \
    ros-humble-desktop \
    python3-colcon-common-extensions \
 && rm -rf /var/lib/apt/lists/*

# Source ROS2 setup for interactive shells
RUN echo "source /opt/ros/humble/setup.bash" >> /root/.bashrc

# Copy and run install scripts (allow scripts to fail but prefer they succeed)
COPY bash/install_cpp.sh /tmp/
COPY bash/install_py.sh /tmp/
COPY bash/install_ros2.sh /tmp/
RUN bash /tmp/install_cpp.sh || true
RUN bash /tmp/install_py.sh || true
RUN bash /tmp/install_ros2.sh || true

# Create workspace and copy code
RUN mkdir -p /UARM/src
WORKDIR /UARM
COPY . /UARM

# Default command
CMD ["bash"]
