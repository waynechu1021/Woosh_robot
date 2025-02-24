# 使用 ROS Jazzy 作为基础镜像
# FROM docker.1ms.run/osrf/ros:jazzy-desktop
FROM docker.1ms.run/arm64v8/ros:foxy

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
    && rm -rf /var/lib/apt/lists/*

# RUN pip install --user --upgrade pip --index-url https://mirrors.sustech.edu.cn/pypi/web/simple
RUN pip config set global.index-url https://mirrors.sustech.edu.cn/pypi/web/simple

RUN pip3 install --user \
    requests \
    numpy \
    scipy \
    SpeechRecognition \
    opencv-python-headless \
    openai \
    flask \
    && rm -rf /root/.cache/pip

WORKDIR /root
RUN git clone https://github.com/waynechu1021/Woosh_robot.git
#COPY /home/rm/nav_private/Woosh_robot/ .

WORKDIR /root/Woosh_robot

COPY ros-foxy-woosh-robot-agent_0.0.1-0focal_arm64.run .
RUN chmod +x ros-foxy-woosh-robot-agent_0.0.1-0focal_arm64.run
RUN ./ros-foxy-woosh-robot-agent_0.0.1-0focal_arm64.run

WORKDIR /root/Woosh_robot
CMD /bin/bash -c "git pull && \
    cd run && GPT_KEY=\"\" python3 run.py"
