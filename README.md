# Woosh robot navgation

## Overview
```text
├── docker 
│   ├── Dockerfile
│   ├── launch.sh
│   ├── ros-foxy-woosh-robot-agent_0.0.1-0focal_arm64.run
│   └── ros-humble-woosh-robot-agent_0.0.2-0jammy_arm64.run
├── map_generate
│   ├── map.png
│   ├── map.yaml
│   ├── mesh2map_black.py
│   ├── point2map_black.py
│   └── readpoint_height.py
├── requirements.txt
├── ros-humble-woosh-robot-agent_0.0.1-0jammy_amd64.run
├── ros-jazzy-woosh-robot-agent_0.0.1-0noble_amd64.run
├── run
│   ├── Nav2Node
│   │   ├── __init__.py
│   │   ├── get_pose_speed.py
│   │   ├── move_base.py
│   │   ├── step_control.py
│   │   └── stop.py
│   ├── Node
│   │   ├── __init__.py
│   │   ├── get_lidar.py
│   │   ├── get_pose_speed.py
│   │   ├── init_robot.py
│   │   ├── move_base.py
│   │   ├── mute.py
│   │   ├── set_pose.py
│   │   ├── step_control.py
│   │   └── stop.py
│   ├── icp.py
│   ├── map
│   │   ├── map_07_02.png
│   │   ├── map_07_02.txt
│   │   ├── map_07_02.yaml
│   │   ├── scan_by_robot.png
│   │   ├── scan_by_robot.txt
│   │   └── scan_by_robot.yaml
│   ├── map_utils.py
│   └── run.py
```

## Use in your PC

### Requirement
- WSL2 Ubuntu-22.04
- ROS2 Humble

### Download the code
```bash
git clone https://github.com/waynechu1021/Woosh_robot.git
cd Woosh_robot
pip install -r requirements.txt
```

### Connect to the woosh robot
Assume that you have connected to the robot either in Wifi or in wired connection, and the ip is `169.254.128.2`(change according to the situation). 
```bash
export RMW_IMPLEMENTATION=rmw_cyclonedds_cpp
```
If you are using dual network cards, then specify the network interface name used by ROS 2 communication by
```bash
export RMW_NETWORK_INTERFACE=eth2 # change this to the network that connect to the robot
```
### Run
```bash
python3 run.py
```

### Send instruction
Open another terminal, then you can send instruction like
```bash
curl -X POST -H "Content-Type: application/json" -d '{"query_text": "where2go"}' http://127.0.0.1:5000/text_nav
curl -X POST http://127.0.0.1:5000/stop
curl -X POST http://127.0.0.1:5000/get_lidar
curl -X POST -H "Content-Type: application/json" -d '{"direction": "left", "theta": "1.2"}' http://127.0.0.1:5000/rotate
curl -X POST -H "Content-Type: application/json" -d '{"direction": "forward", "distance": "0.5"}' http://127.0.0.1:5000/forward
```

## Deployment on the edge device

### Download the code
```bash
git clone https://github.com/waynechu1021/Woosh_robot.git
cd Woosh_robot/docker
```

### Build docker image
```bash
docker build -t nav .
./launch.sh
```


## TODO
1. Stabliza the VPR