# Woosh robot navgation

## System requirement
- Ubuntu-24.04(Others may be ok, but we haven't tried them.)
- Ros jazzy(Ros 2)

## Re-build the Demo
```shell
cd woosh_robot_demo
rm -rf build/ devel/ log/
colcon build
```
Then add `source /path/woosh_robot_demo/install/setup.sh` to your `.bashrc` and source it.

## Connect to the woosh robot
Assume that you have connected to the robot either in Wifi or in wired connection, and the ip is 169.254.128.2(change according to the situation). 

You can try `ping 169.254.128.2` to make sure you have connected to the robot.

Then add the following to the `.bashrc` and source it.

```bash
export RMW_IMPLEMENTATION=rmw_cyclonedds_cpp
export RMW_NETWORK_INTERFACE=eth2  #the network interface that connect to the robot
```

**Note** that you must ensure your computer also connect to the Internet at the same time, this is to make the machine could transmit query text and receive the location from another computer. You can also run the relevant program on this machine.

## Run
<!-- Open a terminal and run the robot agent like

```shell
ros2 run woosh_robot_agent agent --ros-args -r __ns:=/woosh_robot -p ip:="169.254.128.2"
``` -->

Then open a new terminal and run the open-vocabulary objNav
```shell
python3 run.py
```

## TODO
1. More accurate determination of the feasible areas
2. Support more open-vocabulary object