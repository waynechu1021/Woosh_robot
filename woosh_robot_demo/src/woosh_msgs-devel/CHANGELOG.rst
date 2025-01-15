^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Changelog for package woosh_msgs
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

1.1.4 (2024-10-21)
------------------
* Modified translation
* 添加注释
* Add Manekineko msg
* Contributors: Zhengjun Zhang, fuguohe, yangjiefeng

1.1.3 (2024-10-16)
------------------
* add status code translation
* Add Liftcontrol3 action
* Contributors: Zhengjun Zhang, yangjiefeng

1.1.2 (2024-10-14)
------------------
* 添加导航方向
* Contributors: fuguohe

1.1.1 (2024-08-13)
------------------
* 添加斜向移动角度
* Contributors: fuguohe

1.1.0 (2024-08-12)
------------------
* Merge branch 'anydir_base' into devel
* 添加横移和斜移接口
* Add timer based adjustable lift control action
* Refine Log.msg for any direction moving robot base
* Contributors: Zhengjun Zhang, fuguohe, siyanmao

1.0.12 (2024-08-12)
-------------------
* Revert "Modify Log.msg to fit Y speed"
  This reverts commit 2aa7a375b0273b67766bc79d75b49a8d00952e97.
* Add timer based adjustable lift control action
* Modify Log.msg to fit Y speed
* Contributors: Zhengjun Zhang

1.0.11 (2024-07-03)
-------------------
* 更改arm action 添加task_name字段
* Contributors: 熊

1.0.10 (2024-07-02)
-------------------
* Add RF Remote controller msg
* Copy message, service and action file to ros defined directory.
* Contributors: Zhengjun Zhang

1.0.9 (2024-01-18)
------------------
* 添加初始化服务接口
* Contributors: fuguohe

1.0.8 (2023-08-18)
------------------
* Merge branch 'devel' of https://gitlab.wsrobotics.com/wooshbasedriver/woosh_msgs into devel
* 添加允许路线不绕行接口
* Add PowerOff and Reboot service
* Contributors: Zhengjun Zhang, fuguohe

1.0.7 (2023-07-04)
------------------
* 添加中途点被占的状态码
* 修改名字
* Contributors: fuguohe

1.0.6 (2023-05-11)
------------------
* 添加机器人状态信息
* Contributors: fuguohe

1.0.5 (2023-05-10)
------------------
* 添加任务执行过程
* 添加任务执行过程
* 添加makefile文件编译接口
* Contributors: fuguohe

1.0.4 (2023-05-10)
------------------
* 添加任务执行接口
* Contributors: fuguohe

1.0.3 (2023-03-01)
------------------
* 修改参数类型
* Contributors: fuguohe

1.0.2 (2023-02-28)
------------------
* 添加激光匹配jiek
* Contributors: fuguohe

1.0.1 (2023-01-03)
------------------
* rm changelog
* Update CHANGELOG.rst
* 修改版本
* woosh init
* Contributors: fuguohe

0.0.67 (2022-10-19)
-------------------
* Add CHANGELOG.rst
* Modify Ranges.msg
* Contributors: Zhigang Zeng

0.0.66 (2022-08-18)
-------------------
* Add CHANGELOG.rst
* Modify StepControl.action
* Contributors: Zhigang Zeng

0.0.65 (2022-06-20)
-------------------
* Add CHANGELOG.rst
* 添加域信息
* 修改重复状态码
* Contributors: Zhigang Zeng, fuguohe, yangjf

0.0.64 (2022-06-17)
-------------------
* Add CHANGELOG.rst
* Modify embed status code of charger
* 添加货物检测与火警检测状态码
* 提升应用部分状态码等级
* 整改状态码
* Contributors: Zhigang Zeng, yangjf

0.0.63 (2022-06-01)
-------------------
* Add CHANGELOG.rst
* 添加障碍物预警状态码
* Add new status
* Contributors: Zhigang Zeng, fuguohe

0.0.62 (2022-01-07)
-------------------
* Add CHANGELOG.rst
* Add charge status code
* Add ChargeControl.action
* Contributors: Zhigang Zeng

0.0.61 (2021-12-30)
-------------------
* Add CHANGELOG.rst
* Add new status code
* Add comment
* Contributors: Zhigang Zeng, fuguohe

0.0.60 (2021-12-21)
-------------------
* Add CHANGELOG.rst
* Add response success and message
* Refined
* 添加导航到达状态码
* Modify controller_srvs
* Remove header in RobotInfo.msg
* Remove FollowBeacon.msg
* Add header in controller_msgs
* Modify Battery.msg and Beacon.msg
* Contributors: Zhigang Zeng, fuguohe

0.0.59 (2021-11-18)
-------------------
* Add CHANGELOG.rst
* Add Magnetisms.msg and RFIDs.msg
* Contributors: Zhigang Zeng

0.0.58 (2021-11-04)
-------------------
* Add CHANGELOG.rst
* Add RFID.msg
* Modify SecondPosition.action
* Contributors: Zhigang Zeng

0.0.57 (2021-09-28)
-------------------
* Add CHANGELOG.rst
* Modify CMakeLists.txt
* Add CHANGELOG.rst
* 添加完整wifi模块
* Contributors: Zhigang Zeng, yangjf

0.0.56 (2021-09-26)
-------------------
* Add CHANGELOG.rst
* Add Point by point navigation function
* Refined
* Add status
* Add arm action
* Contributors: Zhigang Zeng, fuguohe

0.0.55 (2021-08-31 13:55:14 +0800)
----------------------------------
* Add CHANGELOG.rst
* 重定义NacMade.msg交互
* Add ArTags.msg
* Contributors: Zhigang Zeng, xiehairong, xixh

0.0.54 (2021-07-29)
-------------------
* Add CHANGELOG.rst
* Add follower msg
* 添加英文注释
* 修改recovery失败的状态码为130102000092
* 增加aic_auto_dock的料车对接类型
* 增加recovery失败的状态码130102000011
* 添加定位成功失败的状态码
* Contributors: Zhigang Zeng, aicrobo, yangjf

0.0.53 (2021-06-06)
-------------------
* Update CHANGELOG.rst
* Add follow service defination
* Contributors: Your Name, fuguohe

0.0.52 (2021-06-03)
-------------------
* Update CHANGELOG.rst
* change width data type
* add width in Paht_info.msg
* Contributors: fuguohe, 黄锡霖

0.0.51 (2021-04-23 18:34)
-------------------------
* Add CHANGELOG.rst
* add Path_info.msg for softguide interface
* interface for road map generation
* 修改应用组状态码
* AddReflectors.srv
* 修改reflector_errorID.msg数据类型
* 修改deploymentTool参数类型
* 修改deploymentTool参数类型
* Add ArTrackLocate.srv for package aic_ar_track_locate
* add numberOfFailBeacons variable to display the number of unstable beacons
* delete unneccesary variable in Deployment.srv
* 完善deployment部署工具接口
* 添加deployment msg
* 添加reflectors接口
* Add SetMapMerge.srv
* Contributors: Weiqi Xu, Your Name, Yuming Liang, Zhigang Zeng, huangxl, xiehairong, yangjf, 黄锡霖

0.0.50 (2021-04-23 12:42)
-------------------------
* Add CHANGELOG.rst
* Modify main board disconnect level
* Add sonar hang and barrier detect status code
* Contributors: Zhigang Zeng

0.0.49 (2021-03-19)
-------------------
* Add CHANGELOG.rst
* Modify powermng low voltage status code
* Contributors: Zhigang Zeng

0.0.48 (2021-02-26)
-------------------
* Add CHANGELOG.rst
* Add sonar number
* Modify ModuleStatusElec.h
* Add SensorRanges.msg
* Contributors: Zhigang Zeng

0.0.47 (2020-12-11)
-------------------
* Add CHANGELOG.rst
* modify init status code
* modify status code
* 单机域检测/changed_nav_mode添加id号
* Contributors: Weiqi Xu, Zhigang Zeng, 杨洁峰

0.0.46 (2020-11-18)
-------------------
* Add CHANGELOG.rst
* Modify the system status
* Contributors: Zhigang Zeng, fuguohe

0.0.45 (2020-11-09)
-------------------
* Add CHANGELOG.rst
* Add SetSafetyField.srv
* Contributors: Zhigang Zeng

0.0.44 (2020-10-28)
-------------------
* Add CHANGELOG.rst
* Add submodule in LED.msg
* Contributors: Zhigang Zeng

0.0.43 (2020-10-13)
-------------------
* Add CHANGELOG.rst
* Modify IMU status code
* Contributors: Zhigang Zeng

0.0.42 (2020-09-22)
-------------------
* Add CHANGELOG.rst
* Modify status code of power manager
* Contributors: Zhigang Zeng

0.0.41 (2020-08-04)
-------------------
* Add CHANGELOG.rst
* 添加rosbag接口
* Modify lift status code and add IMU status code
* Remove debain files
* Contributors: Weiqi Xu, Zhigang Zeng

0.0.40 (2020-07-23)
-------------------
* Add CHANGELOG.rst
* Add aic_ar_track_charge_status code
* Change .action , add result about statusCode
* Add a file: ArTrackCharge.action
* Contributors: Zhigang Zeng, xiehairong

0.0.39 (2020-07-15)
-------------------
* Add CHANGELOG.rst
* Add ScannerStatus.msg
* 修改autodock2接口
* Fix bug
* 二次定位新接口
* Contributors: Weiqi Xu, Zhigang Zeng

0.0.38 (2020-06-19)
-------------------
* Add CHANGELOG.rst
* Modify the nav mode action
* Modify navigation mode msg
* Field.msg edited online with Bitbucket
* Contributors: Bin Wang, Zhigang Zeng, fuguohe

0.0.37 (2020-05-12)
-------------------
* Add CHANGELOG.rst
* Modify SecondPosition.action and Magnetism.msg
* Contributors: Zhigang Zeng

0.0.36 (2020-03-30)
-------------------
* Add CHANGELOG.rst
* Add status code of application
* Add aic_ar_track status code
* Modify ModuleStatusElec.h and ModuleStatusEmbed.h
* Contributors: Zhigang Zeng, jeffrey, xiehairong

0.0.35 (2020-03-06)
-------------------
* Add CHANGELOG.rst
* Modify sys status code
* Modify sys code
* Modify sys status code
* Modify module status ofelec and embed
* Contributors: Weiqi Xu, Zhigang Zeng

0.0.34 (2020-01-06)
-------------------
* Add CHANGELOG.rst
* Add beacon id string in Beacon.msg
* Modify sys error msg
* Add lift_type
* Add goal : id range
* Add pause and resume
* Add geometry_msgs/Point distination
* Add ArTagIdAndPose
* Contributors: Weiqi Xu, Zhigang Zeng, xiehairong

0.0.33 (2019-11-11)
-------------------
* Add CHANGELOG.rst
* Field.msg edited
* Add slope_angle to map_server/Field.msg
* Field.msg edited online with Bitbucket
* Contributors: Bin Wang, Weiqi Xu, Zhigang Zeng

0.0.32 (2019-10-31)
-------------------
* Update CHANGELOG.rst
* Modify OdomCtrolAvoidObstacle.action
* Add maxRPM and maxSpeed in Parameter.msg
* Contributors: Weiqi Xu, Zhigang Zeng

0.0.31 (2019-09-25)
-------------------
* Add CHANGELOG.rst
* Add process state
* Add navigation module status
* Contributors: Zhigang Zeng, fuguohe

0.0.30 (2019-09-12)
-------------------
* Add CHANGELOG.rst
* Modify AutoDock.action
* Modify controller_actions
* Add tmp navmode msgs
* Add field and graph msgs for MapServer
* Modify AutoDock.action and OdomCtrolAvoidObstacle.action
* Modify include/aic_msgs cmakelist
* Modify ModuleStatusSys.h and OdomCtrolAvoidObstacle.action
* Modify AutoDock.action
* Modify cmakelist.txt
* Modify AutoDock.action and NarrowPassage.action, add Elevator.action
* Contributors: Weiqi Xu, Zhigang Zeng, liuyansui

0.0.29 (2019-08-21)
-------------------
* Add CHANGELOG.rst
* Modify OdomCtrolAvoidObstacle.action
* Add SystemAgent services
* Modify RollerControl.action
* Add ModuleStatus definition
* Modify IO.msg and RollerControl.action
* Add wormhole reach feedback
* Add MultiMapNavigation.action
* Contributors: Weiqi Xu, Yuming Liang, Zhengjun Zhang, Zhigang Zeng

0.0.28 (2019-07-15)
-------------------
* Add CHANGELOG.rst
* Modify Parameter.msg
* Add TractorControl.action
* Modify OdomCtrolAvoidObstacle.action
* Modify NarrowPassages.action
* Modify RollerControl.action
* Contributors: Weiqi Xu, Zhigang Zeng

0.0.27 (2019-05-23)
-------------------
* Add CHANGELOG.rst
* Add NarrowPassages.action
* Redefine the action goal
* Add LiftControl.action
* Contributors: Weiqi Xu, Zhigang Zeng

0.0.26 (2019-03-18)
-------------------
* Add CHANGELOG.rst
* Remove network_msgs and network_srvs
* Modify AutoCharge.action and OdomCtrolAvoidObstacle.action
* Add door status to AutoChargeAction.h
* Modify LED.msg
* Modify controller_actions add RollerControl.Action
* Add FollowBeacon.msg
* Contributors: Weiqi Xu, Zhigang Zeng

0.0.25 (2019-01-16)
-------------------
* Add CHANGELOG.rst
* Modify RobotInfo.msg
* Add RobotInfo.msg
* Add OdomCtrolAvoidObstacle.action
* Add IOChannelControl.msg and IOChannel.msg
* Contributors: Weiqi Xu, Zhigang Zeng

0.0.24 (2018-12-19)
-------------------
* Add CHANGELOG.rst
* Modify Error.msg
* Add commenting
* Modify AutoCharge.action
* Modify autodock.action
* Add step control precent
* Add battery remain time
* Add network_msgs and network_srvs
* Contributors: Weiqi Xu, Zhigang Zeng

0.0.23 (2018-11-15)
-------------------
* Add CHANGELOG.rst
* Split navigation interface
* Contributors: Zhigang Zeng, fuguohe

0.0.22 (2018-08-07)
-------------------
* Add CHANGELOG.rst
* Add AutoCharge.action, StepCtrlAvoidObstacle.action and TagLocalization.action
* Contributors: Shuaifeng Liu, Zhigang Zeng

0.0.21 (2018-08-02)
-------------------
* Add CHANGELOG.rst
* Add AicInit.srv
* Contributors: Zhigang Zeng

0.0.20 (2018-07-26)
-------------------
* Add CHANGELOG.rst
* Add SecondPosition.action
* Contributors: Zhigang Zeng

0.0.19 (2018-05-10)
-------------------
* Add CHANGELOG.rst
* Add speed
* Add waiting timeout
* Add navigation mode
* Add DriverFree.srv
* Add ModeConfig.msg
* Contributors: Zhigang Zeng, fuguohe

0.0.18 (2018-04-18)
-------------------
* Add CHANGELOG.rst
* Add PeripheralConfig.msg
* Modify IO.msg
* Contributors: Zhigang Zeng

0.0.17 (2018-04-11)
-------------------
* Add CHANGELOG.rst
* Modify IO.msg
* Remove Calibration.msg
* Refine AutoDock.action
* Contributors: Zhigang Zeng, caixiaopeng

0.0.16 (2018-03-07)
-------------------
* Add CHANGELOG.rst
* Modify CMakeLists.txt for adding charge_actions
* Modify MoveBase.action
* Contributors: Guohe Fu, Zhigang Zeng, liuyansui

0.0.15 (2018-01-30)
-------------------
* Add CHANGELOG.rst
* Add beacon group and max_range
* Contributors: Zhigang Zeng, fuguohe

0.0.14 (2018-01-18)
-------------------
* Add CHANGELOG.rst
* Add autodock action
* Update Error.msg
* Contributors: Zhigang Zeng, liuyansui

0.0.13 (2017-12-22)
-------------------
* Add CHANGELOG.rst
* Add Charge.msg
* Contributors: Zhigang Zeng

0.0.12 (2017-12-04)
-------------------
* Add CHANGELOG.rst
* Modify Log.msg
* Contributors: Zhigang Zeng

0.0.11 (2017-11-20)
-------------------
* Add CHANGELOG.rst
* Add BMS.msg
* Add WheelConfig.msg
* Add Calibration.msg
* Add JoystickConfig.msg
* Update Parameter.msg
* Contributors: Zhigang Zeng

0.0.10 (2017-10-29 22:30)
-------------------------
* Add CHANGELOG.rst
* Contributors: Zhigang Zeng

0.0.9 (2017-10-29 22:20)
------------------------
* Add CHANGELOG.rst
* Update Log.msg
* Update Battery.msg
* Contributors: Zhigang Zeng

0.0.8 (2017-10-16)
------------------
* Update CHANGELOG.rst
* Add IOs_msg
* Modify nav_srvs::SaveMap
* Refine BeaconLists.srv
* Contributors: Zhigang Zeng, yuanboshe

0.0.7 (2017-10-02)
------------------
* Update CHANGELOG.rst
* Add api invoke exception in errorMsg
* Modify DriverBoard.msg
* Update Battery.msg
* Add Weight.msg
* Add Magnetism.msg and Location.action
* Contributors: Zhigang Zeng, caixp

0.0.6 (2017-09-13)
------------------
* Update CHANGELOG.rst
* Fix bug: cann't compile successfully
* Add nav_srvs
* Add ModifyMap msg
* Modify information and log message
* Add driver board message
* Contributors: Xiaopeng Cai, Zhigang Zeng, yuanboshe

0.0.5 (2017-09-01)
------------------
* Update CHANGELOG.rst
* Add nav_actions
* Add LED message
* Modify information message
* Modify error message
* Contributors: Zhigang Zeng, yuanboshe

0.0.4 (2017-08-18)
------------------
* Update CHANGELOG.rst
* Add ble Status message
* Modify key message
* Modify chassis information message
* Add chassis information message
* Modify beacon message
* Add error meessage memment
* Contributors: Zhigang Zeng, yuanboshe, zengzg

0.0.3 (2017-05-22)
------------------
* Update CHANGELOG.rst
* Add PointCloud2
* Add Step control action
* Contributors: fuguohe, yuanboshe, zengzg

0.0.2 (2017-05-03)
------------------
* Update CHANGELOG.rst
* Add ultrasonic rang sensors message
* Modify beacon message
* Contributors: fugh, yuanboshe

0.0.1 (2017-04-06)
------------------
* Add CHANGELOG.rst
* Normalize controller_msgs
* Add controller_msgs
* Contributors: yuanboshe
