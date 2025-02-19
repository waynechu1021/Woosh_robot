# 使用 ROS Jazzy 作为基础镜像
FROM docker.1ms.run/osrf/ros:jazzy-desktop

RUN apt-get update && \
    apt-get install -y \
    git \
    unzip \
    python3-colcon-common-extensions \
    python3-pip \
    python3-dev \
    build-essential \
    libprotobuf-dev \
    && rm -rf /var/lib/apt/lists/*

# RUN pip install --user --upgrade pip --index-url https://mirrors.sustech.edu.cn/pypi/web/simple
RUN pip config set global.index-url https://mirrors.sustech.edu.cn/pypi/web/simple

RUN pip3 install --user \
    requests \
    numpy \
    scipy \
    SpeechRecognition \
    openai \
    --break-system-packages\
    && rm -rf /root/.cache/pip

WORKDIR /root
RUN git clone https://github.com/waynechu1021/Woosh_robot.git

WORKDIR /root/Woosh_robot
RUN chmod +x ros-jazzy-woosh-robot-agent_0.0.1-0noble_amd64.run
RUN ./ros-jazzy-woosh-robot-agent_0.0.1-0noble_amd64.run

WORKDIR /root/Woosh_robot
RUN /bin/bash -c "source /opt/ros/${ROS_DISTRO}/setup.bash && \
cd woosh_robot_demo && colcon build"
CMD /bin/bash -c "git pull && \
    source ./woosh_robot_demo/install/setup.bash && \
    cd run && python3 run.py"
# CMD /bin/bash -c "source ./woosh_robot_demo/install/setup.bash && \
#     cd run && python3 run.py"
