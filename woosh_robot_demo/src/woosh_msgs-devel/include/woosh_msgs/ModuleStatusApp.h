namespace app {
/* 版本(1)|部门(1)|模块(2)|子模块(2)|功能状态(5)|级别(1) */

/* 局域网 */
#define APP_LAN_WIFI_CONNECT_NORMAL                      140101000000	// 与局域网WiFi连接正常|Connection with LAN WiFi is normal
#define APP_LAN_WIFI_CONNECT_BREAK                       140101000002	// 与局域网WiFi连接异常断开|Connection with LAN WiFi is break
/* 调度 */
#define APP_DMS_CONNECT_NORMAL                           140102000000	// 与调度连接正常|Connection with DMS is normal
#define APP_DMS_CONNECT_BREAK                            140102000002	// 与调度连接异常断开|Connection with DMS is break
/* 初始化 */
#define APP_INIT_NORMAL                                  140200000000	// 机器人初始化成功|Initialization successful
#define APP_INIT_FAILED_MOVEBASE_UNSTART                 140201000012	// MoveBase未启动成功,初始化失败|Failed to start MoveBase, Initialization failed
#define APP_INIT_FAILED_UNKNOWN_LOCATIONS                140201000022	// 机器人未知位置,初始化失败|AIV location unknown,Initialization failed
#define APP_INIT_FAILED_NOT_LOADED_MAP                   140201000032	// 地图未加载,初始化失败|Map not loaded, Initialization failed
#define APP_INIT_FAILED_MECHANISM_NOT_DOWN               140201000042	// 举升机构未放下,初始化失败|Lifting Mechanism not at bottom，Initialization failed
#define APP_INIT_USING_QRCODE                            140201000051	// 使用二维码初始化|Initialize using the QR code
#define APP_INIT_USING_RECORD_POS                        140201000061	// 使用记录点初始化|Initialize using the record pos
#define APP_INIT_USING_RESTORATION_POS                   140201000071	// 使用复位点初始化|Initialize using the restoration pos
/* 导航 */
#define APP_NAVIGATION_NORMAL                            140300000000	// 导航恢复|Navigation successful
/* 导航模式 */
#define APP_INCORRECT_NAVIGATION_TYPE                    140301000011	// 错误的导航到达类型,修改模式失败|Incorrect navigation arrival type, failed to modify mode
#define APP_FAILED_CALL_NAVIGATION_FAILED                140301000021	// 调用ROS切换导航模式失败|Failed to call ROS to switch navigation mode
/* 导航检测 */
#define APP_NAV_ROUTE_EMPTY_FAILED_VERIFY                140302000012	// 导航路径为空,校验路径失败|Navigation route is empty, failed to verify route
#define APP_NAV_ROUTE_EMPTY_FAILED_SAVED                 140302000011	// 导航路径为空,无法保存路径|Navigation route is empty, route cannot be saved
/* 虫洞检测 */
#define APP_UNFIND_WORMHOLES                             140303000012	// 找不到当前楼层的虫洞点|No Wormholes on current floor
#define APP_UNFIND_WORMHOLES_NEIGHBOR_MAP                140303000022	// 邻近地图没有相同id的虫洞|No Wormholes with the same ID on neighboring map
#define APP_FIND_WORMHOLES_FAILED                        140303000032	// 当前楼层路径有误,寻找虫洞失败|Incorrect route on current floor, failed to find Wormholes
/* 导航运行 */
#define APP_NAV_FAILED                                   140304000012	// 导航失败|Navigation failed
#define APP_NAV_START_CALL_FAILED                        140304000022	// 调用ROS开始导航失败|Failed to call ROS to start navigation
#define APP_NAV_PAUSE_CALL_FAILED                        140304000031	// 调用ROS暂停导航失败|Failed to call ROS to pause navigation
#define APP_NAV_CONTINUE_CALL_FAILED                     140304000041	// 调用ROS继续导航失败|Failed to call ROS to continue navigation
#define APP_NAV_CANCEL_CALL_FAILED                       140304000051	// 调用ROS取消导航失败|Failed to call ROS to cancel navigation
#define APP_NAV_CHECK_CALL_FAILED                        140304000062	// 调用ROS自检导航失败|Failed to call ROS to self-test navigation
/* 电梯导航 */
#define APP_CONNECT_ELEVATOR_CALL_FAILED                 140305000012	// 调用开始连接电梯失败|Failed to call start connect elevator
#define APP_CONNECT_ELEVATOR_FAILED                      140305000022	// 连接电梯失败|Failed to connect elevator
#define APP_UNFIND_ELEVATOR                              140305000032	// 未找到电梯|Elevator not found
#define APP_ELEVATOR_DETECT_LASER_FAILED                 140305000042	// 电梯检测laser电梯失败|Elevator fails to detect laser elevator
#define APP_ELEVATOR_GRATING_DETECTS_OBSTACLE            140305000052	// 电梯光栅检测到物体,正在退出|Elevator grating detects obstacle, exiting
#define APP_CALL_ELEVATOR_FAILED                         140305000062	// 呼叫电梯失败|Failed to call elevator
#define APP_CALL_ELEVATOR_TIMEOUT                        140305000072	// 呼叫电梯超时|Call elevator timeout
#define APP_CALL_ELEVATOR_SUCCEED                        140305000081	// 呼叫电梯成功|Call elevator successful
#define APP_START_FLOOR_EMPTY                            140305000092	// 始发楼层为空,呼叫电梯失败|Starting floor is empty, failed to call elevator
#define APP_OPEN_ELEVATOR_CALL_FAILED                    140305000102	// 调用电梯门打开失败|Failed to call elevator door to open
#define APP_OPEN_ELEVATOR_FAILED                         140305000112	// 梯门打开失败|Failed to open elevator door
#define APP_OPEN_ELEVATOR_TIMEOUT                        140305000122	// 电梯门打开超时|Open elevator door timeout
#define APP_OPEN_ELEVATOR_SUCCEED                        140305000131	// 电梯门打开成功|Open elevator door successful
#define APP_ELEVATOR_INCORRECT_STATE                     140305000142	// 电梯对接返回错误状态|Incorrect state return to dock elevator
#define APP_DOCK_ELEVATOR_FAILED                         140305000152	// 电梯对接失败|Failed to dock elevator
#define APP_DOCK_ELEVATOR_START_CALL_FAILED              140305000162	// 调用ROS开始电梯对接失败|Failed to call ROS to start elevator docking
#define APP_DOCK_ELEVATOR_PAUSE_CALL_FAILED              140305000171	// 调用ROS暂停电梯对接失败|Failed to call ROS to pause elevator docking
#define APP_DOCK_ELEVATOR_CONTINUE_CALL_FAILED           140305000181	// 调用ROS继续电梯对接失败|Failed to call ROS to continue elevator docking
#define APP_DOCK_ELEVATOR_CANCEL_CALL_FAILED             140305000191	// 调用ROS取消电梯对接失败|Failed to call ROS to cancel elevator docking
#define APP_DOCK_ELEVATOR_CHECK_CALL_FAILED              140305000202	// 调用ROS自检电梯对接失败|Failed to call ROS to self-test elevator docking
/* 虫洞切换 */
#define APP_MAP_ID_ERROR_TO_SWITCH_MAP                   140306000012	// 地图ID越界,虫洞切换地图失败|Map ID out of bounds, Wormholes fail to switch map
#define APP_WORMHOLES_FAILED_TO_SWITCH_MAP               140306000022	// 虫洞切换地图失败|Wormholes fail to switch map
/* 域检测 */
#define APP_UNFIND_FIELD_INFO                            140307000011	// 找不到对应的地图域信息|Failed to find corresponding map area
#define APP_UNFIND_FIELD_ID                              140307000021	// 找不到对应的域id|Failed to find corresponding area id
#define APP_NOT_NAV_FILTER_FIELD                         140307000031	// 非任务中导航,过滤进出域处理|Not navigation in task, filter in and out area processing
#define APP_AUTODOOR_TRIGGER                             140307000041	// 自动门标志触发,直接通过|Automatic door sign trigger, pass
#define APP_WARNING_TRIGGER                              140307000051	// 警示标志触发,直接通过|Warning sign trigger, pass
/* 狭窄导航 */
#define APP_DOCK_NARROW_FAILED                           140308000012	// 狭窄通道对接失败|Failed to dock narrow passage
#define APP_DOCK_NARROW_START_CALL_FAILED                140308000022	// 调用ROS开始狭窄通道对接失败|Failed to call ROS to start narrow passage docking
#define APP_DOCK_NARROW_PAUSE_CALL_FAILED                140308000031	// 调用ROS暂停狭窄通道对接失败|Failed to call ROS to pause narrow passage docking
#define APP_DOCK_NARROW_CONTINUE_CALL_FAILED             140308000041	// 调用ROS继续狭窄通道对接失败|Failed to call ROS to continue narrow passage docking
#define APP_DOCK_NARROW_CANCEL_CALL_FAILED               140308000051	// 调用ROS取消狭窄通道对接失败|Failed to call ROS to cancel narrow passage docking
#define APP_DOCK_NARROW_CHECK_CALL_FAILED                140308000062	// 调用ROS自检狭窄通道对接失败|Failed to call ROS to self-test narrow passage docking
/* 二维码识别 */
#define APP_SCAN_QRCODE_FAILED                           140309000012	// 二维码识别失败|Failed to scan QR code
#define APP_SCAN_QRCODE_START_CALL_FAILED                140309000022	// 调用ROS开始二维码识别失败|Failed to call ROS to start QR code scanning
#define APP_SCAN_QRCODE_PAUSE_CALL_FAILED                140309000031	// 调用ROS暂停二维码识别失败|Failed to call ROS to pause QR code scanning
#define APP_SCAN_QRCODE_CONTINUE_CALL_FAILED             140309000041	// 调用ROS继续二维码识别失败|Failed to call ROS to continue QR code scanning
#define APP_SCAN_QRCODE_CANCEL_CALL_FAILED               140309000051	// 调用ROS取消二维码识别失败|Failed to call ROS to cancel QR code scanning
#define APP_SCAN_QRCODE_CHECK_CALL_FAILED                140309000062	// 调用ROS自检二维码识别失败|Failed to call ROS to self-test QR code scanning
/* 泊车检测 */
#define APP_NOT_TURN_ON_PARK_SETTING                     140401000011	// 没有开启停车位设置开关|Parking spot setting switch is not turn on
#define APP_NO_AVAILABLE_PARK_SPOT                       140401000021	// 没有可用停车位可选择|No available parking spot to choose from
/* 充电检测 */
#define APP_NOT_TURN_ON_CHARGE_SETTING                   140402000011	// 没有开启自主充电设置开关|Auto-charging setting switch is not turn on
#define APP_NOT_ENABLED_CHARGE                           140402000021	// 没有使能自主充电|Auto-charging is not enabled
#define APP_NOT_LOW_BATTERY                              140402000031	// 不是低电量状态|Not low battery
#define APP_NOT_DURING_CHARGING_TIME                     140402000041	// 不是充电时间内|Not during charging time
#define APP_NOTAVAILABLE_CHARGE_PILE                     140402000051	// 没有可用充电桩可选择|No available charging pile to choose from
/* 充电控制 */
#define APP_CHARGE_CTRL_NORMAL                           140501000000	// 充电控制恢复|Charging control successful
#define APP_CHARGE_CTRL_FAILED                           140501000012	// 充电控制失败|Charging control failed
#define APP_CHARGE_CTRL_START_CALL_FAILED                140501000022	// 调用ROS开始充电控制失败|Failed to call ROS to start charging control
#define APP_CHARGE_CTRL_PAUSE_CALL_FAILED                140501000031	// 调用ROS暂停充电控制失败|Failed to call ROS to pause charging control
#define APP_CHARGE_CTRL_CONTINUE_CALL_FAILED             140501000041	// 调用ROS继续充电控制失败|Failed to call ROS to continue charging control
#define APP_CHARGE_CTRL_CANCEL_CALL_FAILED               140501000051	// 调用ROS取消充电控制失败|Failed to call ROS to cancel charging control
#define APP_CHARGE_CONTRO_CHECK_CALL_FAILED              140501000062	// 调用ROS自检充电控制失败|Failed to call ROS to self-test charging control
/* 举升控制 */
#define APP_LIFTING_CTRL_NORMAL                          140502000000	// 举升控制恢复|Lifting control successful
#define APP_LIFTING_NO_SETTING_LOAD                      140502000012	// 未设置任务上下料,举升控制失败|No task loading or unloading is set, lifting control failed
#define APP_LIFTING_MECHANISM_UNSAFT                     140502000022	// 举升机构不在最顶或最底,举升自检失败|Lifting Mechanism is not at the top or bottom, lifting self-test failed
#define APP_LIFTING_CTRL_FAILED                          140502000032	// 举升控制失败|Lifting control failed
#define APP_LIFTING_CTRL_START_CALL_FAILED               140502000042	// 调用ROS开始举升控制失败|Failed to call ROS to start lifting control
#define APP_LIFTING_CTRL_PAUSE_CALL_FAILED               140502000051	// 调用ROS暂停举升控制失败|Failed to call ROS to pause lifting control
#define APP_LIFTING_CTRL_CONTINUE_CALL_FAILED            140502000061	// 调用ROS继续举升控制失败|Failed to call ROS to continue lifting control
#define APP_LIFTING_CTRL_CANCEL_CALL_FAILED              140502000071	// 调用ROS取消举升控制失败|Failed to call ROS to cancel lifting control
#define APP_LIFTING_CTRL_CHECK_CALL_FAILED               140502000082	// 调用ROS自检举升控制失败|Failed to call ROS to self-test lifting control
/* 辊筒控制 */
#define APP_ROLLER_CTRL_NORMAL                           140503000000	// 辊筒控制恢复|Roller control successful
#define APP_ROLLER_NO_SETTING_LOAD                       140503000012	// 未设置任务上下料,辊筒控制失败|No task loading or unloading is set, roller control failed
#define APP_ROLLER_CTRL_FAILED                           140503000022	// 辊筒控制失败|Roller control failed
#define APP_ROLLER_CTRL_START_CALL_FAILED                140503000032	// 调用ROS开始辊筒控制失败|Failed to call ROS to start roller control
#define APP_ROLLER_CTRL_PAUSE_CALL_FAILED                140503000041	// 调用ROS暂停辊筒控制失败|Failed to call ROS to pause roller control
#define APP_ROLLER_CTRL_CONTINUE_CALL_FAILED             140503000051	// 调用ROS继续辊筒控制失败|Failed to call ROS to continue roller control
#define APP_ROLLER_CTRL_CANCEL_CALL_FAILED               140503000061	// 调用ROS取消辊筒控制失败|Failed to call ROS to cancel roller control
#define APP_ROLLER_CTRL_CHECK_CALL_FAILED                140503000072	// 调用ROS自检辊筒控制失败|Failed to call ROS to self-test roller control
/* 牵引控制 */
#define APP_TRACTION_CTRL_NORMAL                         140504000000	// 牵引控制恢复|Traction control successful
#define APP_TRACTION_NO_SETTING_LOAD                     140504000012	// 未设置任务上下料,牵引控制失败|No task loading or unloading is set, traction control failed
#define APP_TRACTION_CTRL_FAILED                         140504000022	// 牵引控制失败|Traction control failed
#define APP_TRACTION_CTRL_START_CALL_FAILED              140504000032	// 调用ROS开始牵引控制失败|Failed to call ROS to start traction control
#define APP_TRACTION_CTRL_PAUSE_CALL_FAILED              140504000041	// 调用ROS暂停牵引控制失败|Failed to call ROS to pause traction control
#define APP_TRACTION_CTRL_CONTINUE_CALL_FAILED           140504000051	// 调用ROS继续牵引控制失败|Failed to call ROS to continue traction control
#define APP_TRACTION_CTRL_CANCEL_CALL_FAILED             140504000061	// 调用ROS取消牵引控制失败|Failed to call ROS to cancel traction control
#define APP_TRACTION_CTRL_CHECK_CALL_FAILED              140504000072	// 调用ROS自检牵引控制失败|Failed to call ROS to self-test traction control
/* 机械臂控制 */
#define APP_ARM_CTRL_NORMAL                              140505000000	// 机械臂控制恢复|Arm control successful
#define APP_ARM_NO_SETTING_LOAD                          140505000012	// 未设置任务上下料,机械臂控制失败|No task loading or unloading is set, arm control failed
#define APP_ARM_CTRL_FAILED                              140505000022	// 机械臂控制失败|Arm control failed
#define APP_ARM_CTRL_START_CALL_FAILED                   140505000032	// 调用ROS开始机械臂控制失败|Failed to call ROS to start arm control
#define APP_ARM_CTRL_PAUSE_CALL_FAILED                   140505000041	// 调用ROS暂停机械臂控制失败|Failed to call ROS to pause arm control
#define APP_ARM_CTRL_CONTINUE_CALL_FAILED                140505000051	// 调用ROS继续机械臂控制失败|Failed to call ROS to continue arm control
#define APP_ARM_CTRL_CANCEL_CALL_FAILED                  140505000061	// 调用ROS取消机械臂控制失败|Failed to call ROS to cancel arm control
#define APP_ARM_CTRL_CHECK_CALL_FAILED                   140505000072	// 调用ROS自检机械臂控制失败|Failed to call ROS to self-test arm control
/* 步进控制 */
#define APP_STEP_CTRL_NORMAL                             140506000000	// 步进控制恢复|Stepping control successful
#define APP_STEP_CTRL_FAILED                             140506000012	// 步进控制失败|Stepping control failed
#define APP_STEP_CTRL_START_CALL_FAILED                  140506000022	// 调用ROS开始步进控制失败|Failed to call ROS to start stepping control
#define APP_STEP_CTRL_PAUSE_CALL_FAILED                  140506000031	// 调用ROS暂停步进控制失败|Failed to call ROS to pause stepping control
#define APP_STEP_CTRL_CONTINUE_CALL_FAILED               140506000041	// 调用ROS继续步进控制失败|Failed to call ROS to continue stepping control
#define APP_STEP_CTRL_CANCEL_CALL_FAILED                 140506000051	// 调用ROS取消步进控制失败|Failed to call ROS to cancel stepping control
#define APP_STEP_CTRL_CHECK_CALL_FAILED                  140506000062	// 调用ROS自检步进控制失败|Failed to call ROS to self-test stepping control
/* 雷达二次定位进入 */
#define APP_LIDAR_DOCK_ENTER_NORMAL                      140601000000	// 雷达二次定位进入恢复|Radar secondary positioning entry successful
#define APP_LIDAR_DOCK_RF_DATA_ABNORMAL                  140601000012	// 雷达对接射频数据校验异常|RF data verification of Radar docking is abnormal
#define APP_LIDAR_DOCK_DETECTED_OBSTACLES_ON_RACK        140601000022	// 雷达对接检测到货架上有障碍物|Radar dockingmndetected obstacles on rack
#define APP_LIDAR_DOCK_ENTER_FAILED                      140601000032	// 雷达二次定位进入失败|Radar secondary,mpositioning entry failed
#define APP_LIDAR_DOCK_ENTER_START_CALL_FAILED           140601000042	// 调用ROS开始雷达二次定位进入失败|Failed to call ROS to start Radar secondary positioning entry
#define APP_LIDAR_DOCK_ENTER_PAUSE_CALL_FAILED           140601000051	// 调用ROS暂停雷达二次定位进入失败|Failed to call ROS to pause Radar secondary positioning entry
#define APP_LIDAR_DOCK_ENTER_CONTINUE_CALL_FAILED        140601000061	// 调用ROS继续雷达二次定位进入失败|Failed to call ROS to continue Radar secondary positioning entry
#define APP_LIDAR_DOCK_ENTER_CANCEL_CALL_FAILED          140601000071	// 调用ROS取消雷达二次定位进入失败|Failed to call ROS to cancel Radar secondary positioning entry
#define APP_LIDAR_DOCK_ENTER_CHECK_CALL_FAILED           140601000082	// 调用ROS自检雷达二次定位进入失败|Failed to call ROS to self-test Radar secondary positioning entry
#define APP_LIDAR_DOCK_ENTER_OFFSET                      140601000092	// 雷达二次定位进入偏移|Radar secondary positioning entry offset
/* 雷达二次定位退出 */
#define APP_LIDAR_DOCK_EXIT_NORMAL                       140602000000	// 雷达二次定位退出恢复|Radar secondary positioning exit successful
#define APP_LIDAR_DOCK_EXIT_FAILED                       140602000012	// 雷达二次定位退出失败|Radar secondary positioning exit failed
#define APP_LIDAR_DOCK_EXIT_START_CALL_FAILED            140602000022	// 调用ROS开始雷达二次定位退出失败|Failed to call ROS to start Radar secondary positioning exit
#define APP_LIDAR_DOCK_EXIT_PAUSE_CALL_FAILED            140602000031	// 调用ROS暂停雷达二次定位退出失败|Failed to call ROS to pause Radar secondary positioning exit
#define APP_LIDAR_DOCK_EXIT_CONTINUE_CALL_FAILED         140602000041	// 调用ROS继续雷达二次定位退出失败|Failed to call ROS to continue Radar secondary positioning exit
#define APP_LIDAR_DOCK_EXIT_CANCEL_CALL_FAILED           140602000051	// 调用ROS取消雷达二次定位退出失败|Failed to call ROS to cancel Radar secondary positioning exit
#define APP_LIDAR_DOCK_EXIT_CHECK_CALL_FAILED            140602000062	// 调用ROS自检雷达二次定位退出失败|Failed to call ROS to self-test Radar secondary positioning exit
/* 磁条旋转定位 */
#define APP_MAG_DOCK_ROTATE_NORMAL                       140603000000	// 磁条旋转定位恢复|Magnetic Strip rotational positioning successful
#define APP_MAG_DOCK_ROTATE_START_CALL_FAILED            140603000012	// 调用ROS开始磁条旋转定位寻找失败|Failed to call ROS to start Magnetic Strip rotational positioning search
#define APP_MAG_DOCK_ROTATE_PAUSE_CALL_FAILED            140603000021	// 调用ROS暂停磁条旋转定位寻找失败|Failed to call ROS to pause Magnetic Strip rotational positioning search
#define APP_MAG_DOCK_ROTATE_CONTINUE_CALL_FAILED         140603000031	// 调用ROS继续磁条旋转定位寻找失败|Failed to call ROS to continue Magnetic Strip rotational positioning search
#define APP_MAG_DOCK_ROTATE_CANCEL_CALL_FAILED           140603000041	// 调用ROS取消磁条旋转定位寻找失败|Failed to call ROS to cancel Magnetic Strip rotational positioning search
#define APP_MAG_DOCK_ROTATE_CHECK_CALL_FAILED            140603000052	// 调用ROS自检磁条旋转定位寻找失败|Failed to call ROS to self-test Magnetic Strip rotational positioning search
#define APP_MAG_DOCK_ROTATE_FORWARD_FAILED               140603000062	// 磁条正向旋转寻找出错|Incorrect Magnetic Strip rotates forward search
#define APP_MAG_DOCK_ROTATE_BACKWARD_FAILED              140603000072	// 磁条反向旋转寻找出错|Incorrect Magnetic Strip rotates backward search
#define APP_MAG_DOCK_ROTATE_FAILED                       140603000082	// 磁条旋转定位寻找失败|Magnetic Strip rotational positioning search failed
/* 磁条二次定位进入 */
#define APP_MAG_DOCK_ENTER_NORMAL                        140604000000	// 磁条二次定位进入恢复|Magnetic Strip secondary positioning entry successful
#define APP_MAG_DOCK_RF_DATA_ABNORMAL                    140604000012	// 磁条对接射频数据校验异常|RF data verification of Magnetic Strip docking is abnormal
#define APP_MAG_DOCK_DETECTED_OBSTACLES_ON_RACK          140604000022	// 磁条对接检测到货架上有障碍物|Magnetic Strip docking detected obstacles on rack
#define APP_MAG_DOCK_ENTER_FAILED                        140604000032	// 磁条二次定位进入失败|Magnetic Strip secondary positioning entry failed
#define APP_MAG_DOCK_ENTER_START_CALL_FAILED             140604000042	// 调用ROS开始磁条二次定位进入失败|Failed to call ROS to start Magnetic Strip secondary positioning entry
#define APP_MAG_DOCK_ENTER_PAUSE_CALL_FAILED             140604000051	// 调用ROS暂停磁条二次定位进入失败|Failed to call ROS to pause Magnetic Strip secondary positioning entry
#define APP_MAG_DOCK_ENTER_CONTINUE_CALL_FAILED          140604000061	// 调用ROS继续磁条二次定位进入失败|Failed to call ROS to continue Magnetic Strip secondary positioning entry
#define APP_MAG_DOCK_ENTER_CANCEL_CALL_FAILED            140604000071	// 调用ROS取消磁条二次定位进入失败|Failed to call ROS to cancel Magnetic Strip secondary positioning entry
#define APP_MAG_DOCK_ENTER_CHECK_CALL_FAILED             140604000082	// 调用ROS自检磁条二次定位进入失败|Failed to call ROS to self-test Magnetic Strip secondary positioning entry
#define APP_MAG_DOCK_ENTER_OFFSET                        140604000092	// 磁条二次定位进入偏移|Magnetic Strip secondary positioning entry offset
/* 磁条二次定位退出 */
#define APP_MAG_DOCK_EXIT_NORMAL                         140605000000	// 磁条二次定位退出恢复|Magnetic Strip secondary positioning exit successful
#define APP_MAG_DOCK_EXIT_FAILED                         140605000012	// 磁条二次定位退出失败|Magnetic Strip secondary positioning exit failed
#define APP_MAG_DOCK_EXIT_START_CALL_FAILED              140605000022	// 调用ROS开始磁条二次定位退出失败|Failed to call ROS to start Magnetic Strip secondary positioning exit
#define APP_MAG_DOCK_EXIT_PAUSE_CALL_FAILED              140605000031	// 调用ROS暂停磁条二次定位退出失败|Failed to call ROS to pause Magnetic Strip secondary positioning exit
#define APP_MAG_DOCK_EXIT_CONTINUE_CALL_FAILED           140605000041	// 调用ROS继续磁条二次定位退出失败|Failed to call ROS to continue Magnetic Strip secondary positioning exit
#define APP_MAG_DOCK_EXIT_CANCEL_CALL_FAILED             140605000051	// 调用ROS取消磁条二次定位退出失败|Failed to call ROS to cancel Magnetic Strip secondary positioning exit
#define APP_MAG_DOCK_EXIT_CHECK_CALL_FAILED              140605000062	// 调用ROS自检磁条二次定位退出失败|Failed to call ROS to self-test Magnetic Strip secondary positioning exit
/* 构图 */
#define APP_UPDATE_MAPPING_BUFFER_NOT_EXIST              140701000011	// 更新构图缓冲文件不存在|Update create map buffer file does not exist
#define APP_UPDATE_MAPPING_PARAMETERS_ERROR              140701000021	// 更新构图参数有误|Incorrect updating create map parameters
#define APP_START_MAPPING_FAILED_TO_CLOSE_LOCALIZATION   140701000031	// 关闭 Localization 执行失败|Failed to close Localization execution
#define APP_START_MAPPING_FAILED_TO_CLOSE_MOVEBASE       140701000041	// 关闭 MoveBase 执行失败|Failed to close MoveBase execution
#define APP_START_MAPPING_FAILED_TO_CLOSE_MAP_SERVER     140701000053	// 关闭 MapServer 执行失败|Failed to close MapServer execution
#define APP_START_MAPPING_FAILED_TO_START_SLAM           140701000063	// 开启 SLAM 执行失败|Failed to start SLAM execution
#define APP_START_MAPPING_FAILED_TO_INIT                 140701000073	// 开始构图时，下位机初始化执行失败|Initialization of slave computer failed while starting create map
/* 停止构图 */
#define APP_STOP_MAPPING_FAILED_TO_CLOSE_SLAM            140702000011	// 关闭 SLAM 执行失败|Failed to close SLAM execution
#define APP_STOP_MAPPING_FAILED_TO_SETTING_MAP           140702000021	// 设置当前地图失败|Failed to set current map
#define APP_STOP_MAPPING_FAILED_TO_START_LOCALIZATION    140702000031	// 开启 Localization 执行失败|Failed to start Localization execution
#define APP_STOP_MAPPING_FAILED_TO_START_MOVEBASE        140702000041	// 开启 MoveBase 执行失败|Failed to start MoveBase execution
/* 保存地图 */
#define APP_SAVE_MAP_FAILED_CAUSE_SCENE_NAME_EMPTY       140703000011	// 保存地图的场景名为空,保存失败|Saved scene name is empty, save failed
#define APP_SAVE_MAP_FAILED_CAUSE_MAP_NAME_EMPTY         140703000021	// 保存地图的名字为空,保存失败|Saved map name is empty, save failed
#define APP_SAVE_MAP_FAILED_CAUSE_LOCATION_LOST          140703000031	// 定位丟失,保存失败|Location lost, save failed
#define APP_SAVE_MAP_FAILED_CAUSE_CREATE_DIR             140703000041	// 创建保存地图目录失败|Failed to create save map directory
#define APP_SAVE_MAP_FAILED_CAUSE_CREATE_ACTION_GROUP    140703000051	// 创建动作组合文件失败|Failed to create action group file
#define APP_SAVE_MAP_FAILED_CAUSE_LOAD_SCENE_INFO        140703000061	// 同场景保存时,读取场景信息文件失败|Failed to read scene file while saving the same scene
#define APP_SAVE_MAP_FAILED                              140703000071	// 保存地图失败|Failed to save map
/* 更新地图 */
#define APP_UPDATE_MAP_NONE_UPDATED_FILE                 140704000011	// 无更新文件数据|None updated file data
#define APP_UPDATE_MAP_FAILED_CAUSE_CREATE_DIR           140704000021	// 创建更新文件夹失败|Failed to create update folder
#define APP_UPDATE_MAP_FAILED_CAUSE_WRITE_FILE           140704000031	// 写入更新地图文件失败|Failed to write update map file
#define APP_UPDATE_MAP_FAILED_CAUSE_LOAD_ACTION_GROUP    140704000041	// 读取任务组集数据失败|Failed to read Task Set data
#define APP_UPDATE_MAP_FAILED_CAUSE_LOAD_SCENE_INFO      140704000051	// 更新地图文件时,读取场景信息文件失败|Failed to load scene info
/* 下拉地图 */
#define APP_UPLOAD_MAP_FAILED_CAUSE_SCENE_EMPTY          140705000011	// 机器人的场景为空，请构建完再请求|AIV scene is empty, request after create
#define APP_UPLOAD_MAP_FAILED_CAUSE_SCENE_NOT_EXIST      140705000021	// 请求上传的场景不存在|Scene requested for upload does not exist
/* 切换地图 */
#define APP_SWITCH_MAP_FAILED_CAUSE_LOAD_SCENE_INFO      140706000011	// 切换地图时,读取场景信息文件失败|Failed to read scene file while switching map
#define APP_SWITCH_MAP_FAILED_CAUSE_UPDATE_FILE          140706000021	// 切换地图时,文件更新失败|Failed to update file while switching map
#define APP_SWITCH_MAP_FAILED_CAUSE_UNFIND_MAP           140706000031	// 找不到切换的目标地图|Unable to find switched target map
#define APP_SWITCH_MAP_FAILED_CAUSE_LOAD_MAP             140706000043	// 地图切换时,加载地图失败|Failed to load map while switching map
#define APP_SWITCH_MAP_NEED_INIT                         140706000053	// 手动切换至不同地图,需要初始化|Manually switch to a different map, need to initialize
/* 删除地图 */
#define APP_DELETE_MAP_FAILED_CAUSE_SCENE_NAME_EMPTY     140707000011	// 删除的场景名为空,删除失败|Deleted scene name is empty, failed to delete
#define APP_DELETE_MAP_FAILED_CAUSE_USING_SCENE          140707000021	// 不能删除当前使用的场景|Using scene cannot be deleted
#define APP_DELETE_MAP_FAILED_CAUSE_USING_MAP            140707000031	// 不能删除当前使用的地图|Using map cannot be deleted
#define APP_DELETE_MAP_FAILED_CAUSE_WRITE_SCENE          140707000041	// 写入场景数据失败|Failed to write scene data
#define APP_DELETE_MAP_FAILED_CAUSE_LOAD_SCENE_INFO      140707000053	// 同场景删除地图时,读取场景信息文件失败|Delete map in same scene, failed to read scene folder
/* 更改地图 */
#define APP_MODIFY_MAP_FAILED_CAUSE_SCENE_NOT_EXIST      140708000011	// 场景文件夹不存在,修改失败|Scene folder does not exist, failed to modify
#define APP_MODIFY_MAP_FAILED_CAUSE_ONLY_SCENE_DIR_NAME  140708000021	// 仅更改场景文件夹名字失败|Failed to change scene folder name
#define APP_MODIFY_MAP_FAILED_CAUSE_MAP_EMPTY            140708000031	// 更改的地图名或被更改的地图名字为空，更改失败|Change or changed map name is empty, failed to modify
#define APP_MODIFY_MAP_FAILED_CAUSE_SAME_NAME            140708000041	// 更改的地图名或被更改的地图名字与当前地图名相同，更改失败|Change or changed map name has the same name as current map, failed to modify
#define APP_MODIFY_MAP_FAILED_CAUSE_SCENE_INFO_NOT_EXIST 140708000051	// 场景信息文件不存在|Scene folder does not exist
#define APP_MODIFY_MAP_FAILED_CAUSE_UNFIND_MAP_NAME      140708000061	// scene.json找不到更改地图名字，更改地图名字失败|Cannot find changed map name in Scene.json, failed to modify map name
#define APP_MODIFY_MAP_FAILED_CAUSE_WRITE_SCENE_JSON     140708000071	// scene.json修改写入失败，更改地图名字失败|Failed to write Scene.json modification, failed to modify map name
#define APP_MODIFY_MAP_FAILED_CAUSE_MAP_DIR_NOT_EXIST    140708000081	// 地图文件夹不存在|Map folder does not exist
#define APP_MODIFY_MAP_FAILED_CAUSE_MAP_DIR_NAME         140708000091	// 更改地图文件夹名字失败|Failed to change map folder name
#define APP_MODIFY_MAP_FAILED_CAUSE_MAP_BUFFER_NAME      140708000101	// 更改缓冲地图文件名字失败|Failed to change buffer map folder name
#define APP_MODIFY_MAP_FAILED_CAUSE_SCENE_DIR_NAME       140708000111	// 更改场景文件夹名字失败|Failed to change scene folder name
/* 加载地图 */
#define APP_LOAD_MAP_FAILED_CAUSE_LOAD_TASK_SET          140709000013	// 读取任务组集数据失败|Failed to read Task Set data
#define APP_LOAD_MAP_FAILED_CAUSE_LOAD_SCENE_INFO        140709000023	// 读取场景信息文件失败|Failed to read scene file
#define APP_LOAD_MAP_FAILED_CAUSE_MAP_NAME_EMPTY         140709000033	// 当前地图名字为空,找不到对应id的地图名字|Map name is empty, failed to find map name with corresponding ID
#define APP_LOAD_MAP_FAILED                              140709000043	// 加载地图失败|Failed to load map
#define APP_LOAD_MAP_FAILED_TO_START_LOCALIZATION        140709000053	// 开启定位失败|Failed to open positioning
/* 请求 */
#define APP_SDK_VERSION_ERROR                            140801000011	// SDK版本不一致,请求失败|SDK version is inconsistent, request failed
#define APP_ERROR_CTRL_MODE_TO_SWITCH_WORK_MODE          140801000021	// 不是自动模式,不允许切换工作模式|Not in Automatic mode, working mode cannot be switch
#define APP_ERROR_STATE_TO_SWITCH_WORK_MODE              140801000031	// 当前机器人状态不允许切换工作模式|State cannot be switched working mode
#define APP_ERROR_MODE_TO_MAPPING                        140801000041	// 机器人不处于自动或部署模式,构图请求失败|AIV is not in Automatic or Deployment mode, failed to request create map
#define APP_ERROR_MODE_TO_SAVE_MODE                      140801000051	// 机器人不处于自动或部署模式,保存构图失败|AIV is not in Automatic or Deployment mode, failed to save create map
#define APP_NOT_NAV_TO_CHANGE_NAV_ROUTE                  140801000061	// 当前不在导航中,改变导航路径失败|Not in navigation, failed to change navigation route
#define APP_NOT_NAV_TO_CHANGE_NAV_MODE                   140801000071	// 当前不在导航中,改变导航模式失败|Not in navigation, failed to change navigation mode
#define APP_ERROR_CTRL_MODE_TO_ORDER_ACTION              140801000081	// 机器人不处于自动模式,动作命令失败|AIV is not in Automatic mode, action command failed
#define APP_ERROR_STATE_TO_SPEED_CTRL                    140801000091	// 当前机器人状态或动作状态不允许速度控制|AIV state or action state cannot be speed controlled
#define APP_ERROR_WORK_MODE_TO_DEPLOYMENT                140801000101	// 机器人不处于部署模式,部署请求失败|AIV is not in Deployment mode, failed to request deployment
#define APP_FAILED_TO_START_TASK_CAUSE_TASKING           140801000111	// 当前有任务在进行，开始失败|In task, failed to start
#define APP_ERROR_MODE_TO_START_TASK                     140801000121	// 机器人不处于自动或单机模式,开始失败|AIV is not in Automatic or Stand-alone mode, failed to start
#define APP_FAILED_TO_REQ_EXECUTION_CASE_TASKING         140801000131	// 任务执行中,执行请求失败|Task in progress, failed to request execution
#define APP_UNFIND_TASK_SET_ID                           140801000141	// 找不到相应的任务组id|Failed to find corresponding Task Set ID
#define APP_TASK_PARSING_FAILED                          140801000151	// 单机任务解析失败|Stand-alone mode task parsing failed
#define APP_TASK_FAILED_TO_START_CAUSE_TASK_COMPLETED    140801000161	// 该任务已完成过,开始失败|Task has completed, failed to start
#define APP_TASK_FAILED_CAUSE_FIRE_TRIGGERED             140801000171	// 火警信号触发,开始失败|Fire alarm triggered，failed to start
#define APP_ABNORMAL_CARGO                               140801000181	// 货物检测异常|Goods detect abnormal
#define APP_ABNORMAL_MECHANISM                           140801000191	// 机构检测异常|Mechanism detect abnormal
#define APP_HARDWARE_WARNING                             140801000201	// 存在硬件设备警告|Hardware warning
#define APP_HARDWARE_FAILURE                             140801000211	// 存在硬件设备故障|Hardware failure
#define APP_ERROR_STATE_TO_SWITCH_MAP                    140801000221	// 当前机器人状态不允许切换地图|AIV state cannot be switched map
#define APP_ERROR_STATE_TO_ININT                         140801000232	// 当前机器人状态不允许初始化|AIV state cannot be initialized
#define APP_ERROR_CTRL_MODE_TO_ININT                     140801000242	// 当前控制模式不允许初始化|Control mode cannot be initialized
#define APP_FAILED_TO_CHANGE_CAUSE_ROUTE_EMPTY           140801000251	// 改变导航路径为空,改变导航路径失败|Failed to change navigation route because route is empty
#define APP_ERROR_STATE_TO_ACCEPT_TASK                   140801000261	// 当前机器人状态不可接受任务|AIV state cannot accept task
#define APP_ERROR_STATE_TO_PAUSE                         140801000271	// 当前机器人状态不可暂停|AIV state cannot pause
#define APP_ERROR_STATE_TO_CONTINUE                      140801000281	// 当前机器人状态不可继续|AIV state cannot continue
#define APP_ERROR_TASK_TYPE_TO_BREAK_WAIT                140801000291	// 任务类型不为等待,打破等待失败|Task type is not wait, failed to break wait
/* 工具 */
#define APP_MODEL_CHANGE_FAILED                          140802000012	// 模型变化失败|Model change failed
#define APP_SET_UP_THE_PROTECTION_FIELD_FAILED           140802000021	// 保护区设置失败|Failed to set up the Protection Field
#define APP_FAILED_TO_GET_IP                             140802000031	// 获取不到ip地址|Failed to get IP
#define APP_ERROR_CTRL_MODE                              140802000041	// 不存在的控制模式|Non-existent control mode
#define APP_SWITCH_AUTO_MODE                             140802000051	// 切换至自动模式|Switch to automatic mode
#define APP_SWITCH_MANUAL_MODE                           140802000061	// 切换至手动模式|Switch to manual mode
#define APP_SWITCH_MAINTAIN_MODE                         140802000071	// 切换至维护模式|Switch to maintenance mode
#define APP_TRIGGER_PAUSE_OR_CONTINUE_BUTTON             140802000081	// 暂停/继续按钮触发|Pause/continue button triggers

}



