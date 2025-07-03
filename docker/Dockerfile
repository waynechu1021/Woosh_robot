# 使用 ROS Jazzy 作为基础镜像
# FROM docker.1ms.run/osrf/ros:jazzy-desktop

# FROM docker.1ms.run/arm64v8/ros:foxy
FROM docker.1ms.run/arm64v8/ros:humble

RUN rm /etc/apt/sources.list.d/ros2-snapshots.list || true
RUN sed -i "s@http://.*archive.ubuntu.com@https://mirrors.sustech.edu.cn@g" /etc/apt/sources.list
RUN sed -i "s@http://.*security.ubuntu.com@https://mirrors.sustech.edu.cn@g" /etc/apt/sources.list

# RUN echo "deb https://mirrors.sustech.edu.cn/ubuntu-ports/ focal main restricted universe multiverse" > /etc/apt/sources.list \
#     && echo "deb https://mirrors.sustech.edu.cn/ubuntu-ports/ focal-updates main restricted universe multiverse" >> /etc/apt/sources.list \
#     && echo "deb https://mirrors.sustech.edu.cn/ubuntu-ports/ focal-backports main restricted universe multiverse" >> /etc/apt/sources.list \
#     && echo "deb https://mirrors.sustech.edu.cn/ubuntu-ports/ focal-security main restricted universe multiverse" >> /etc/apt/sources.list

RUN echo "deb https://mirrors.sustech.edu.cn/ubuntu-ports/ jammy main restricted universe multiverse" > /etc/apt/sources.list \
    && echo "deb https://mirrors.sustech.edu.cn/ubuntu-ports/ jammy-updates main restricted universe multiverse" >> /etc/apt/sources.list \
    && echo "deb https://mirrors.sustech.edu.cn/ubuntu-ports/ jammy-backports main restricted universe multiverse" >> /etc/apt/sources.list \
    && echo "deb https://mirrors.sustech.edu.cn/ubuntu-ports/ jammy-security main restricted universe multiverse" >> /etc/apt/sources.list

RUN apt-get update && \
    apt-get install -y \
    git \
    unzip \
    python3-colcon-common-extensions \
    python3-pip \
    python3-dev \
    build-essential \
    libprotobuf-dev \
    libgl1 \
    libusb-1.0-0 \
    && rm -rf /var/lib/apt/lists/*

# RUN pip install --user --upgrade pip --index-url https://mirrors.sustech.edu.cn/pypi/web/simple
RUN pip config set global.index-url https://mirrors.sustech.edu.cn/pypi/web/simple

RUN pip3 install --user \
    requests \
    numpy \
    scipy \
    pyyaml \
    opencv-python-headless \
    openai \
    flask \
    open3d \
    pyrealsense2 \
    && rm -rf /root/.cache/pip

WORKDIR /root
RUN git clone https://github.com/waynechu1021/Woosh_robot.git
#COPY /home/rm/nav_private/Woosh_robot/ .

WORKDIR /root/Woosh_robot

# COPY ros-foxy-woosh-robot-agent_0.0.1-0focal_arm64.run .
# RUN chmod +x ros-foxy-woosh-robot-agent_0.0.1-0focal_arm64.run
# RUN ./ros-foxy-woosh-robot-agent_0.0.1-0focal_arm64.run

COPY ros-humble-woosh-robot-agent_0.0.2-0jammy_arm64.run .
RUN chmod +x ros-humble-woosh-robot-agent_0.0.2-0jammy_arm64.run
RUN ./ros-humble-woosh-robot-agent_0.0.2-0jammy_arm64.run

WORKDIR /root/Woosh_robot
CMD /bin/bash -c "cd run && GPT_KEY=\"\" python3 run.py"