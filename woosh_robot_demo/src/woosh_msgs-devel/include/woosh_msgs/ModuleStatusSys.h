namespace sys {
/*** 导航 ***/

#define SYS_NAV_LOCALIZATION_SUCCESS                                         130103000000  // 定位正常|Global Localization success
#define SYS_NAV_LOCALIZATION_FAILED                                          130103000012  // 定位丢失|Global Localization failed
#define SYS_NAV_LOCALIZATION_INITIAL                                         130103000021  // 初始化位置|Initialization position
#define SYS_NAV_LOCALIZATION_POSE_JUMP                                       130103000031  // 粒子坐标出现跳变|Particle coordinates have jumped

#define SYS_NAV_MOVE_BASE_STATR                                              130104000000  // 收到新的导航任务，导航避障开始|New navigation task received, navigation obstacle avoidance start
#define SYS_NAV_LOCAL_PLANNER_OBSTACLES_AHEAD                                130104000011  // 前方有障碍物|Obstacles ahead
#define SYS_NAV_LOCAL_PLANNER_OBSTACLES_TOO_NEAR                             130104000021  // 障碍物太近|Obstacles Too Close
#define SYS_NAV_LOCAL_PLANNER_OBSTACLES_NEAR                                 130104000111  // 检测范围内有障碍物|Obstacles in the detection range
#define SYS_NAV_LOCAL_PLANNER_AVOID_FAILED                                   130104000032  // 避障失败|Avoidance Failed
#define SYS_NAV_LOCAL_PLANNER_AVOID_SUCCESS                                  130104000031  // 避障成功|Avoidance Succeed
#define SYS_NAV_LOCAL_PLANNER_RECOVERY_FAILED                                130104000102  // recovery失败|Recovery failed
#define SYS_NAV_MOVE_BASE_STATRTING                                          130104000051  // 起步|Starting
#define SYS_NAV_MOVE_BASE_GO_STRAIGHT                                        130104000061  // 直行|Go straight
#define SYS_NAV_MOVE_BASE_TURN_RIGHT                                         130104000071  // 右转|Turn right
#define SYS_NAV_MOVE_BASE_TURN_LEFT                                          130104000081  // 左转|Turn left
#define SYS_NAV_MOVE_BASE_SUCCESS                                            130104000041  // 目标点导航到达|Navigation reach destination
#define SYS_NAV_MOVE_BASE_TEMPORARY_POINT_SUCCESS                            130104000091  // 临时点导航到达|Navigation reach temporary point
#define SYS_NAV_MOVE_BASE_FAILED                                             130104000042  // 目标点导航失败|Navigation destination failed
#define SYS_NAV_MOVE_BASE_TEMPORARY_POINT_FAILED                             130104000092  // 临时点导航失败|Navigation temporary point failed


/**路径规划**/
#define SYS_NAV_GLOBAL_PLANNER_SUCESS                                        130101000000  // 路径规划成功|Route Planning success
#define SYS_NAV_GLOBAL_PLANNER_TARGET_POINT_OCCUPIED                         130101000011  // 目标点被占，路径规划失败|Destination occupied, unable to plan route
#define SYS_NAV_GLOBAL_PLANNER_FAILED                                        130101000021  // 目标点无法达到，无法找到合理的路径|Destination cannot be reached, reasonable path cannot be found
#define SYS_NAV_GLOBAL_PLANNER_ROBOT_IN_STATIC                               130101000031  // 机器人在实体障碍物中，可能位置不对|AIV in a physical obstacle, position may incorrect 
#define SYS_NAV_WAITING_PERMISSION                                           130101000041  // 等待路径授权|Waiting for the permission of the new path
#define SYS_NAV_GLOBAL_PLANNER_TEMPORARY_POINT_OCCUPIED                      130101000051  // 中途点被占，路径规划失败|Midway point occupied, unable to plan route

/*** 二次定位 ***/
#define SYS_SECONDARY_LOCALIZATION_RECOGNIZE_FAILED                          130501000012  // 特征识别失败|Secondary positioning recognization failed
#define SYS_SECONDARY_LOCALIZATION_RECOGNIZE_START                           130501000000  // 开始特征识别|Secondary positioning recognization start

#define SYS_SECONDARY_LOCALIZATION_POSITION_CALIBRATION_FAILED               130502000012  // 位置调整失败|Secondary positioning position calibration failed
#define SYS_SECONDARY_LOCALIZATION_POSITION_CALIBRATION_AVOIDING             130502000021  // 位置调整被障碍物阻挡|Secondary positioning position calibration blocked
#define SYS_SECONDARY_LOCALIZATION_POSITION_CALIBRATION_TIMEOUT              130502000032  // 位置调整避障超时|Secondary positioning position calibration timeout
#define SYS_SECONDARY_LOCALIZATION_POSITION_CALIBRATION_AVOID_SUCCESS        130502000041  // 障碍物离开，机器人继续导航|Secondary positioning obstacle clear, AIV continues to navigate
#define SYS_SECONDARY_LOCALIZATION_POSITION_CALIBRATION_START                130502000000  // 开始位置调整|Secondary positioning position calibration start

#define SYS_SECONDARY_LOCALIZATION_DOCKING_FAILED                            130503000012  // 对接进入失败|Secondary positioning docking failed
#define SYS_SECONDARY_LOCALIZATION_DOCKING_AVOIDING                          130503000021  // 对接进入被障碍物阻挡|Secondary positioning docking blocked by obstacles
#define SYS_SECONDARY_LOCALIZATION_DOCKING_TIMEOUT                           130503000032  // 对接进入避障超时|Secondary positioning docking timeout
#define SYS_SECONDARY_LOCALIZATION_DOCKINGD_OUTOF_MOVING_RANGE               130503000042  // 二次识别超出设定范围|Secondary positioning docking out of moving range
#define SYS_SECONDARY_LOCALIZATION_DOCKINGD_AVOID_SUCCESS                    130503000051  // 障碍物离开，机器人继续导航|Secondary positioning obstacle clear, AIV continues to navigate
#define SYS_SECONDARY_LOCALIZATION_DOCKING_START                             130503000000  // 开始对接进入|Secondary positioning docking start

#define SYS_SECONDARY_LOCALIZATION_VERIFYING_FAILED                          130504000012  // 校验失败|Secondary positioning verification failed
#define SYS_SECONDARY_LOCALIZATION_VERIFYING_START                           130504000000  // 开始校验|Secondary positioning  verification start

#define SYS_SECONDARY_LOCALIZATION_LEAVING_FAILED                            130505000012  // 脱离退出失败|Secondary positioning leaving failed
#define SYS_SECONDARY_LOCALIZATION_LEAVING_AVOIDING                          130505000021  // 脱离退出被障碍物阻挡|Secondary positioning leaving blocked
#define SYS_SECONDARY_LOCALIZATION_LEAVING_TIMEOUT                           130505000032  // 脱离退出避障超时|Secondary positioning leaving timeout
#define SYS_SECONDARY_LOCALIZATION_LEAVING_AVOID_SUCCESS                     130505000041  // 障碍物离开，机器人继续导航|Secondary positioning obstacle clear, AIV continues to navigate
#define SYS_SECONDARY_LOCALIZATION_LEAVING_START                             130505000000  // 开始脱离退出|Secondary positioning detaching start

#define SYS_SECONDARY_LOCALIZATION_OTHER_FAILURE                             130506000012  // 其他异常失败|Secondary positioning other failure

#define SYS_SECONDARY_LOCALIZATION_GETOUT_FAILED                             130507000012  // 退出失败|Secondary positioning exiting failed
#define SYS_SECONDARY_LOCALIZATION_GETOUT_START                              130507000000  // 开始退出|Secondary positioning exiting start

#define SYS_SECONDARY_LOCALIZATION_MECHANISM_FAILED                          130508000012  // 机械装置控制失败|Secondary positioning mechanism failed
#define SYS_SECONDARY_LOCALIZATION_MECHANISM_START                           130508000000  // 开始机械装置控制|Secondary positioning mechanism start

/*** 狭窄通道 ***/
#define SYS_NARROW_PASSAGES_RECOGNIZE_FAILED                                 130601000012  // 特征识别失败|Narrow Passage recognization failed
#define SYS_NARROW_PASSAGES_RECOGNIZE_START                                  130601000000  // 开始特征识别|Narrow Passage recognization start

#define SYS_NARROW_PASSAGES_LOCALIZATION_POSITION_FAILED                     130602000012  // 位置调整失败|Narrow Passage localization positioning failed
#define SYS_NARROW_PASSAGES_LOCALIZATION_POSITION_AVOIDING                   130602000021  // 位置调整被障碍物阻挡|Narrow Passage localization positioning blocked
#define SYS_NARROW_PASSAGES_LOCALIZATION_POSITION_TIMEOUT                    130602000032  // 位置调整避障超时|Narrow Passage localization positioning timeout
#define SYS_NARROW_PASSAGES_LOCALIZATION_POSITION_AVOID_SUCCESS              130602000041  // 障碍物离开，机器人继续导航|Narrow Passage obstacle clear, AIV continues to navigate
#define SYS_NARROW_PASSAGES_LOCALIZATION_POSITION_START                      130602000000  // 开始位置调整|Narrow Passage localization positioning start

#define SYS_NARROW_PASSAGES_NAV_FAILED                                       130603000012  // 狭窄通道导航失败|Narrow Passage navigation failed
#define SYS_NARROW_PASSAGES_NAV_AVOIDING                                     130603000021  // 狭窄通道导航时被障碍物阻挡|Narrow Passage navigation blocked
#define SYS_NARROW_PASSAGES_NAV_TIMEOUT                                      130603000032  // 狭窄通道避障超时|Narrow Passage navigation timeout
#define SYS_NARROW_PASSAGES_NAV_ERROR                                        130603000042  // 狭窄通道通过异常|Narrow Passage navigation error
#define SYS_NARROW_PASSAGES_NAV_VERIFY_FAILED                                130603000052  // 到达位置与实际地图不符|Narrow Passage navigation verification failed
#define SYS_NARROW_PASSAGES_NAV_AVOID_SUCCESS                                130603000061  // 障碍物离开，机器人继续导航ceed|Narrow Passage obstacle clear, AIV continues to navigate
#define SYS_NARROW_PASSAGES_NAV_START                                        130603000000  // 开始狭窄通道导航|Narrow Passage leaving start

#define SYS_NARROW_PASSAGES_LEAVING_FAILED                                   130604000012  // 脱离退出失败|Narrow Passage leaving failed
#define SYS_NARROW_PASSAGES_LEAVING_AVOIDING                                 130604000021  // 脱离退出被障碍物阻挡|Narrow Passage leaving blocked
#define SYS_NARROW_PASSAGES_LEAVING_TIMEOUT                                  130604000032  // 脱离退出避障超时|Narrow Passage leaving timeout
#define SYS_NARROW_PASSAGES_LEAVING_AVOID_SUCCESS                            130604000041  // 障碍物离开，机器人继续导航|Narrow Passage obstacle clear, AIV continues to navigate
#define SYS_NARROW_PASSAGES_START                                            130604000000  // 开始脱离退出|Narrow Passage leaving start

#define SYS_NARROW_PASSAGES_OTHER_FAILURE                                    130604000042  // 狭窄通道二次识别失败|Narrow Passage other failure

/*** 步进控制 ***/
#define SYS_MOVE_AVOID_FAILED                                                130701000012  // 步进控制失败|Stepping Control failed
#define SYS_MOVE_AVOID_AVOIDING                                              130701000021  // 步进控制被障碍物阻挡|Stepping Control avoidance blocked
#define SYS_MOVE_AVOID_TIMEOUT                                               130701000032  // 步进控制避障超时|Stepping Control timeout
#define SYS_MOVE_AVOID_SUCCESS                                               130701000000  // 步进控制成功|Stepping Control success

/*** 二维码识别 ***/
#define SYS_AR_TRACK_MOVE_AVOID_TIMEOUT                                      130801000032  // 运动避障超时|QR code reconization moving avoidance timeout
#define SYS_AR_TRACK_MOVE_AVOIDING                                           130801000021  // 运动遇到障碍物|QR code reconization moving into obstacles
#define SYS_AR_TRACK_MOVE_SUCCESS                                            130801000010  // 运动成功|QR code reconization moving success
#define SYS_AR_TRACK_FIND_FAIL                                               130801000041  // 未找到二维码|QR Code scanning failed
#define SYS_AR_TRACK_RECOGNIZE_FAILED                                        130801000051  // 识别失败|QR code recognization failed
#define SYS_AR_TRACK_RECOGNIZE_TIMEOUT                                       130801000062  // 识别超时|QR code reconization timeout
#define SYS_AR_TRACK_RECOGNIZE_SUCCESS                                       130801000000  // 识别成功|QR Recognization success
#define SYS_AR_TRACK_RECEIVE_IMAGE_FAILED                                    130801000072  // 接收图像失败|QR code reconization receiving image failed

/*** 二维码对接 ***/
#define SYS_AR_TRACK_CHARGE_SUCCESS                                          130901000000  // 二维码对接成功|QR Code Docking success
#define SYS_AR_TRACK_CHARGE_TIMEOUT                                          130901000012  // 二维码对接超时失败|QR Code Docking timeout

/*** cartographer ***/
#define SYS_CARTOGRAPHER_LOCALIZATION_SUCCESS                                131001000001  // 全局定位成功|Cartographer Global Localization success
#define SYS_CARTOGRAPHER_LOCALIZATION_FAILED                                 131001000011  // 全局定位失败|Cartographer Global Localization failed
/*** 复合机器人  ***/
#define SYS_FETCH_SUCCESS                                                    131011000000  // 取料成功|Arm AIV load successful
#define SYS_FETCH_FAILED                                                     131011000012  // 取料失败|Arm AIV load failed
#define SYS_FEED_SUCCESS                                                     131011000010  // 喂料成功|Arm AIV unload successful
#define SYS_FEED_FAILED                                                      131011000012  // 喂料失败|Arm AIV unload failed
#define SYS_RECOGNITION_FAILED                                               131011000021  // 识别失败|Arm AIV reconization failed
#define SYS_RECOGNITION_SUCCESS                                              131011000020  // 识别成功|Arm AIV reconization successful
/*** verify 检测 ***/
#define SYS_VERIFY_HAVE_OBSTACLES                                            131101000002  // 检测范围内有障碍物|Obstacles in the detection range
#define SYS_VERIFY_NO_OBSTACLES                                              131101000000  // 检测范围内无障碍物|No obstacles in the detection range

}
