# Woosh robot navgation

## System requirement
- Ubuntu-22.04/Ubuntu-24.04(Others may be ok, but we haven't tried them.)
- Ros /Humble/jazzy(Ros 2)

## Download the code
```bash
git clone https://github.com/waynechu1021/Woosh_robot.git
```

## Docker for the robot(Optional)
Currently we deploy the code on the robot's development board, and due to the OS/ROS version, we need docker. But if you just want to control it via your own PC, this step is optional. NOTE that all the steps in this section are done on the robot's development board.
```bash
cd Woosh_robot/docker
docker build -t nav .
./launch.sh
```
or you can enter the interactive interface
```bash
docker run --network host -it --name nav_container nav #when container doesn't exist
docker start -i -a nav_container #when container exists
```

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
Open a new terminal and run the open-vocabulary objNav
```shell
python3 run.py
```
Make sure that you have already launch the llm service for the robot, then you could control the robot via `POST` command.

## TODO
1. Cancel the action when the robot is executing.
2. More accurate determination of the feasible areas
3. Support more open-vocabulary object