cmake_minimum_required(VERSION 3.5)
#cmake_policy(SET CMP0057 NEW)
project(woosh_msgs)

find_package(ament_cmake REQUIRED)
find_package(std_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(actionlib_msgs REQUIRED)
find_package(action_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)

#set好像不能用通配符？？
set(action_files
  "docking_actions/AutoDock.action"
    "docking_actions/AutoDock2.action"
    
  "arm_actions/Arm.action"
  
  "controller_actions/ChargeControl.action"
    "controller_actions/LiftControl.action"
      "controller_actions/LiftControl2.action"
       "controller_actions/LiftControl3.action"
          "controller_actions/RollerControl.action"
            "controller_actions/SecondPosition.action"
             "controller_actions/StepControl.action"
                "controller_actions/TractorControl.action"
  "nav_actions/ArTrack.action"
    "nav_actions/ArTrackCharge.action"
        "nav_actions/MoveBase.action"
            "nav_actions/MultiMapNavigation.action"
                "nav_actions/NavigationMode.action"
                   "nav_actions/OdomCtrolAvoidObstacle.action"
                       "nav_actions/StepCtrlAvoidObstacle.action"
                            "nav_actions/TagLocalization.action"

)
set(msg_files
  "controller_msgs/Battery.msg"
    "controller_msgs/Beacon.msg"
      "controller_msgs/Beacons.msg"
        "controller_msgs/BleStatus.msg"
          "controller_msgs/BMS.msg"
            "controller_msgs/Charge.msg"
              "controller_msgs/Follower.msg"
                "controller_msgs/Information.msg"
                  "controller_msgs/IO.msg"
                    "controller_msgs/IOModule.msg"
                      "controller_msgs/IOModuleControl.msg"
"controller_msgs/IOs.msg"
"controller_msgs/JoystickConfig.msg"
"controller_msgs/LED.msg"
"controller_msgs/Log.msg"
"controller_msgs/Magnetism.msg"
"controller_msgs/Magnetisms.msg"
"controller_msgs/Manekineko.msg"
"controller_msgs/ModeConfig.msg"
"controller_msgs/Obstacle.msg"
"controller_msgs/Parameter.msg"
"controller_msgs/PeripheralConfig.msg"
"controller_msgs/Ranges.msg"
"controller_msgs/RFID.msg"
"controller_msgs/RFIDs.msg"
"controller_msgs/RfRemoteController.msg"
"controller_msgs/RobotInfo.msg"
"controller_msgs/ScannerStatus.msg"
"controller_msgs/StepControl.msg"
"controller_msgs/Weight.msg"
"controller_msgs/WheelConfig.msg"
"controller_msgs/WooshRosbagRecord0.msg"
"controller_msgs/WooshRosbagRecord1.msg"


  "wifi_msgs/WiFiStatus.msg"
  "task_msgs/RobotStatus.msg"
  
  "map_server/ArTagPose.msg"
    "map_server/ArTags.msg"
      "map_server/BidirectPath.msg"
        "map_server/DeploymentMarker.msg"
          "map_server/DeploymentMarkers.msg"
"map_server/Field.msg"
"map_server/GraphEdge.msg"
"map_server/GraphVertex.msg"
"map_server/MapModifyData.msg"
"map_server/MonoPath.msg"
"map_server/NavFieldPoint.msg"
"map_server/NavFields.msg"
"map_server/NavMode.msg"
"map_server/NavPath.msg"
"map_server/PathesGraph.msg"
"map_server/PathInfo.msg"
"map_server/ReflectorErrorID.msg"
"map_server/ReflectorErrorIDgroup.msg"


)

set(srv_files
  "controller_srvs/DriverFree.srv"
    "controller_srvs/SetSafetyField.srv"
      "controller_srvs/WooshInit0.srv"
        "controller_srvs/WooshInit1.srv"
        
  "follow_srvs/FollowCtl.srv"
  
  "nav_srvs/AddReflectors.srv"
   "nav_srvs/ArTrackLocate.srv"
    "nav_srvs/BeaconList.srv"
     "nav_srvs/Deployment.srv"
      "nav_srvs/GetRoadMap.srv"
       "nav_srvs/InitPose.srv"
 "nav_srvs/SaveMap.srv"
  "nav_srvs/ScanMatchInfo.srv"
   "nav_srvs/SetMapMerge.srv"
    "nav_srvs/SetMapServer.srv"

  "wifi_srvs/AddWiFi.srv"
    "wifi_srvs/DisableHotSpot.srv"
      "wifi_srvs/EnableHotSpot.srv"
        "wifi_srvs/ForgetWiFi.srv"
          "wifi_srvs/GetAvailableWiFiList.srv"
            "wifi_srvs/GetLastError.srv"
              "wifi_srvs/TriggerWiFiReconnect.srv"

  "system_srvs/PowerOff.srv"
    "system_srvs/Reboot.srv"
  "task_srvs/ExecTask.srv"

)

rosidl_generate_interfaces(${PROJECT_NAME}
${msg_files}
  ${srv_files}
  ${action_files}
  DEPENDENCIES std_msgs sensor_msgs geometry_msgs nav_msgs action_msgs
)

##generate_messages(
##  DEPENDENCIES std_msgs sensor_msgs geometry_msgs actionlib_msgs nav_msgs
##)

ament_export_dependencies(rosidl_default_runtime)


install(DIRECTORY include/${PROJECT_NAME}/
  DESTINATION ${PROJECT_NAME}
  FILES_MATCHING PATTERN "*.h"
  )

install(DIRECTORY controller_msgs/ map_server/ wifi_msgs/ task_msgs/
	DESTINATION ${PROJECT_NAME}/msg/
	FILES_MATCHING PATTERN "*.msg"
)

install(DIRECTORY controller_srvs/ follow_srvs/ nav_srvs/ wifi_srvs/ system_srvs/ task_srvs/
	DESTINATION ${PROJECT_NAME}/srv/
	FILES_MATCHING PATTERN "*.srv"
)

install(DIRECTORY docking_actions/ arm_actions/ controller_actions/ map_server/ nav_actions/
	DESTINATION ${PROJECT_NAME}/action/
	FILES_MATCHING PATTERN "*.action"
)
