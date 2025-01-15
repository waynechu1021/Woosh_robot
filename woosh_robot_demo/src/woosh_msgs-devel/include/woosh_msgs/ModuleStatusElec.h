namespace elec {

/* 下位机系统 */
#define ELEC_SYSTEM_MAIN_NORMAL           110101000000  // 主控板正常|SSC unit status normal
#define ELEC_SYSTEM_MAIN_COMM_DISCON      110101000012  // 主控板连接异常|SSC unit connection abnormal
#define ELEC_SYSTEM_MAIN_COMM_ABNOR       110101000022  // 主控板通讯异常|SSC unit communication abnormal
#define ELEC_SYSTEM_MAIN_REBOOT           110101000031  // 主控板启动|SSC unit rebooting
#define ELEC_SYSTEM_MAIN_NOT_READY        110101000042  // 主控板未就绪|SSC unit not ready

/* 安全装置 */
#define ELEC_SAFETY_ESB_NORMAL            110201000000  // 急停正常|E-stop button status normal
#define ELEC_SAFETY_ESB1_TRIGGER          110201000013  // 急停1触发|E-stop button one triggered
#define ELEC_SAFETY_ESB2_TRIGGER          110201000023  // 急停2触发|E-stop button two triggered
#define ELEC_SAFETY_ESB3_TRIGGER          110201000033  // 急停3触发|E-stop button three triggered
#define ELEC_SAFETY_CRASH_NORMAL          110202000000  // 安全触边正常|Safety edges status normal
#define ELEC_SAFETY_CRASH1_TRIGGER        110202000013  // 安全触边1触发|Safety edge one triggered
#define ELEC_SAFETY_CRASH2_TRIGGER        110202000023  // 安全触边2触发|Safety edge two triggered
#define ELEC_SAFETY_SEANNER_NORMAL        110203000000  // 安全扫描仪正常|Safety Scanner status normal
#define ELEC_SAFETY_SEANNER_TRIGGER       110203000012  // 安全扫描仪1触发|Safety Scanner one triggered
#define ELEC_SAFETY_SEANNER2_TRIGGER      110203000022  // 安全扫描仪2触发|Safety Scanner two triggered
#define ELEC_SAFETY_PLC_NORMAL            110204000000  // 安全PLC正常|Safety PLC status normal
#define ELEC_SAFETY_PLC_ABNOR             110204000013  // 安全PLC异常|Safety PLC abnormal

/* 电机驱动 */
#define ELEC_DRIVER_SEQ1_NORMAL           110301000000  // 左侧电机正常|Left motor status normal
#define ELEC_DRIVER_SEQ1_MOT_UVW          110301000013  // 左侧电机相线异常|Left motor UVW line abnormal
#define ELEC_DRIVER_SEQ1_MOT_HALL         110301000022  // 左侧电机霍尔异常|Left motor hall signal abnormal
#define ELEC_DRIVER_SEQ1_MOT_ENCODE       110301000032  // 左侧电机编码器异常|Left motor encoder signal abnormal
#define ELEC_DRIVER_SEQ1_MOT_OVTMP        110301000042  // 左侧电机过热|Left motor over-temperature
#define ELEC_DRIVER_SEQ1_MOT_OVLOAD       110301000052  // 左侧电机过载|Left motor over load
#define ELEC_DRIVER_SEQ1_MOT_OVER_SPD     110301000062  // 左侧电机超速|Left motor over-speed
#define ELEC_DRIVER_SEQ1_DRV_LOW_VLT      110301000072  // 左侧驱动器欠压|Left driver low voltage
#define ELEC_DRIVER_SEQ1_DRV_OVER_VLT     110301000082  // 左侧驱动器过压|Left driver over voltage
#define ELEC_DRIVER_SEQ1_DRV_OVER_CUR     110301000092  // 左侧驱动器过流|Left driver over current
#define ELEC_DRIVER_SEQ1_DRV_OVER_LOAD    110301000102  // 左侧驱动器过载|Left driver over load
#define ELEC_DRIVER_SEQ1_DRV_OVER_TEMP    110301000112  // 左侧驱动器过温|Left driver over temperature
#define ELEC_DRIVER_SEQ1_DRV_HW_ABNOR     110301000122  // 左侧驱动器硬件异常|Left driver hardware error
#define ELEC_DRIVER_SEQ1_DRV_CMD_ABNOR    110301000132  // 左侧驱动器指令异常|Left driver command abnormal
#define ELEC_DRIVER_SEQ1_DRV_EXT_STOP     110301000142  // 左侧驱动器外部禁止|Left driver external prohibition
#define ELEC_DRIVER_SEQ1_FAC_CODE0        110301000152  // 左侧驱动器厂商代码0|Left driver factory code zero
#define ELEC_DRIVER_SEQ1_FAC_CODE1        110301000162  // 左侧驱动器厂商代码1|Left driver factory code one
#define ELEC_DRIVER_SEQ1_FAC_CODE2        110301000172  // 左侧驱动器厂商代码2|Left driver factory code two
#define ELEC_DRIVER_SEQ1_FAC_CODE3        110301000182  // 左侧驱动器厂商代码3|Left driver factory code three
#define ELEC_DRIVER_SEQ1_FAC_CODE4        110301000192  // 左侧驱动器厂商代码4|Left driver factory code four
#define ELEC_DRIVER_SEQ1_FAC_CODE5        110301000202  // 左侧驱动器厂商代码5|Left driver factory code five
#define ELEC_DRIVER_SEQ1_FAC_CODE6        110301000212  // 左侧驱动器厂商代码6|Left driver factory code six
#define ELEC_DRIVER_SEQ1_FAC_CODE7        110301000222  // 左侧驱动器厂商代码7|Left driver factory code seven
#define ELEC_DRIVER_SEQ1_ST_COMM_ABNOR    110301000232  // 左侧通讯异常|Left driver communication abnormal
#define ELEC_DRIVER_SEQ1_ST_COMM_DISCON   110301000243  // 左侧通讯断线|Left driver communication disconnection
#define ELEC_DRIVER_SEQ1_ST_SPD_LOW       110301000252  // 左侧转速偏低|Left driver rotation speed low
#define ELEC_DRIVER_SEQ1_ST_SPD_HI        110301000262  // 左侧转速偏高|Left driver rotation speed high
#define ELEC_DRIVER_SEQ1_ST_STRAND        110301000272  // 左侧程序跳转异常|Left driver strand abnormal

#define ELEC_DRIVER_SEQ2_NORMAL           110302000000  // 右侧电机正常|Right motor status normal
#define ELEC_DRIVER_SEQ2_MOT_UVW          110302000013  // 右侧电机相线异常|Right motor UVW line abnormal
#define ELEC_DRIVER_SEQ2_MOT_HALL         110302000022  // 右侧电机霍尔异常|Right motor hall signal abnormal
#define ELEC_DRIVER_SEQ2_MOT_ENCODE       110302000032  // 右侧电机编码器异常|Right motor encoder signal abnormal
#define ELEC_DRIVER_SEQ2_MOT_OVTMP        110302000042  // 右侧电机过热|Right motor over-temperature
#define ELEC_DRIVER_SEQ2_MOT_OVLOAD       110302000052  // 右侧电机过载|Right motor over load
#define ELEC_DRIVER_SEQ2_MOT_OVER_SPD     110302000062  // 右侧电机超速|Right motor over-speed
#define ELEC_DRIVER_SEQ2_DRV_LOW_VLT      110302000072  // 右侧驱动器欠压|Right driver low voltage
#define ELEC_DRIVER_SEQ2_DRV_OVER_VLT     110302000082  // 右侧驱动器过压|Right driver over voltage
#define ELEC_DRIVER_SEQ2_DRV_OVER_CUR     110302000092  // 右侧驱动器过流|Right driver over current
#define ELEC_DRIVER_SEQ2_DRV_OVER_LOAD    110302000102  // 右侧驱动器过载|Right driver over load
#define ELEC_DRIVER_SEQ2_DRV_OVER_TEMP    110302000112  // 右侧驱动器过温|Right driver over temperature
#define ELEC_DRIVER_SEQ2_DRV_HW_ABNOR     110302000122  // 右侧驱动器硬件异常|Right driver hardware error
#define ELEC_DRIVER_SEQ2_DRV_CMD_ABNOR    110302000132  // 右侧驱动器指令异常|Right driver command abnormal
#define ELEC_DRIVER_SEQ2_DRV_EXT_STOP     110302000142  // 右侧驱动器外部禁止|Right driver external prohibition
#define ELEC_DRIVER_SEQ2_FAC_CODE0        110302000152  // 右侧驱动器厂商代码0|Right driver factory code zero
#define ELEC_DRIVER_SEQ2_FAC_CODE1        110302000162  // 右侧驱动器厂商代码1|Right driver factory code one
#define ELEC_DRIVER_SEQ2_FAC_CODE2        110302000172  // 右侧驱动器厂商代码2|Right driver factory code two
#define ELEC_DRIVER_SEQ2_FAC_CODE3        110302000182  // 右侧驱动器厂商代码3|Right driver factory code three
#define ELEC_DRIVER_SEQ2_FAC_CODE4        110302000192  // 右侧驱动器厂商代码4|Right driver factory code four
#define ELEC_DRIVER_SEQ2_FAC_CODE5        110302000202  // 右侧驱动器厂商代码5|Right driver factory code five
#define ELEC_DRIVER_SEQ2_FAC_CODE6        110302000212  // 右侧驱动器厂商代码6|Right driver factory code six
#define ELEC_DRIVER_SEQ2_FAC_CODE7        110302000222  // 右侧驱动器厂商代码7|Right driver factory code seven
#define ELEC_DRIVER_SEQ2_ST_COMM_ABNOR    110302000232  // 右侧通讯异常|Right driver communication abnormal
#define ELEC_DRIVER_SEQ2_ST_COMM_DISCON   110302000243  // 右侧通讯断线|Right driver communication disconnection
#define ELEC_DRIVER_SEQ2_ST_SPD_LOW       110302000252  // 右侧转速偏低|Right driver rotation speed low
#define ELEC_DRIVER_SEQ2_ST_SPD_HI        110302000262  // 右侧转速偏高|Right driver rotation speed high
#define ELEC_DRIVER_SEQ2_ST_STRAND        110302000272  // 右侧程序跳转异常|Right driver strand abnormal

/* 电源管理 */
#define ELEC_POWERMNG_SEQ1_NORMAL                 110401000000  // 电源管理板正常|Power Management Board status normal
#define ELEC_POWERMNG_SEQ1_COMM_DISCON            110401000013  // 电源管理板连接异常|Power Management Board connection abnormal
#define ELEC_POWERMNG_SEQ1_COMM_ABNOR             110401000021  // 电源管理板通讯异常|Power Management Board communication abnormal
#define ELEC_POWERMNG_SEQ1_REBOOT                 110401000031  // 电源管理板启动|Power Management Board rebooting
#define ELEC_POWERMNG_SEQ1_NOT_READY              110401000041  // 电源管理板未就绪|Power Management Board not ready
#define ELEC_POWERMNG_SEQ1_CHECK_ABNOR            110401000092  // 电源管理板自检异常|Power Management Board self-checking abnormal
#define ELEC_POWERMNG_SEQ1_CONTACTOR_ABNOR        110401000102  // 电源管理板接触器异常|Power Management Board contactor abnormal
#define ELEC_POWERMNG_SEQ1_DRV_LOW_VLT            110401000111  // 电源管理板低电压|Power Management Board driver low voltage
#define ELEC_POWERMNG_SEQ1_DRV_START_TIMEOUT      110401000122  // 电源管理板软启动超时|Power Management Board driver rebooting timeout
#define ELEC_POWERMNG_SEQ1_DRV_POWER_TIMEOUT      110401000132  // 电源管理板驱动上电超时|Power Management Board driver power-on timeout
#define ELEC_POWERMNG_SEQ1_START_ABNOR            110401000172  // 电源管理板非正常启动|Power Management Board driver rebooting abnormal
#define ELEC_POWERMNG_SEQ1_MASTER_START_TIMEOUT   110401000182  // 电源管理板主板开机超时|Power Management Board master rebooting timeout
#define ELEC_POWERMNG_SEQ1_MASTER_STATUS_ABNOR    110401000192  // 电源管理板主板状态异常|Power Management Board master status abnormal
#define ELEC_POWERMNG_SEQ1_CHARGE_OVER_CUR        110401000202  // 电源管理板充电过流|Power Management Board charging overcurrent
#define ELEC_POWERMNG_SEQ1_OVER_TEMP              110401000212  // 电源管理板过温|Power Management Board  overheat
#define ELEC_POWERMNG_SEQ1_BMS_COMM_ABNOR         110401000222  // 电源管理板BMS通讯异常|Power Management Board BMS communication abnormal

/* 激光雷达 */
#define ELEC_LASER_SEQ1_NORMAL            112001000000  // 前激光雷达正常|Front Laser Scanner status normal
#define ELEC_LASER_SEQ1_COMM_DISCON       112001000013  // 前激光雷达连接异常|Front Laser Scanner connection abnormal
#define ELEC_LASER_SEQ1_COMM_ABNOR        112001000022  // 前激光雷达通讯异常|Front Laser Scanner communication abnormal
#define ELEC_LASER_SEQ2_NORMAL            112002000000  // 后激光雷达正常|Rear Laser Scanner status normal
#define ELEC_LASER_SEQ2_COMM_DISCON       112002000013  // 后激光雷达连接异常|Rear Laser Scanner connection abnormal
#define ELEC_LASER_SEQ2_COMM_ABNOR        112002000022  // 后激光雷达通讯异常|Rear Laser Scanner communication abnormal

/* 摄像头 */
#define ELEC_CAMERA_SEQ1_NORMAL           112101000000  // 摄像头1正常|Camera one status normal
#define ELEC_CAMERA_SEQ1_COMM_DISCON      112101000013  // 摄像头1连接异常|Camera one connection abnormal
#define ELEC_CAMERA_SEQ1_COMM_ABNOR       112101000022  // 摄像头1通讯异常|Camera one communication abnormal
#define ELEC_CAMERA_SEQ2_NORMAL           112102000000  // 摄像头2正常|Camera two status normal
#define ELEC_CAMERA_SEQ2_COMM_DISCON      112102000013  // 摄像头2连接异常|Camera two connection abnormal
#define ELEC_CAMERA_SEQ2_COMM_ABNOR       112102000022  // 摄像头2通讯异常|Camera two communication abnormal

/* 灯带 */
#define ELEC_RGBLED_SEQ1_NORMAL           112201000000  // 灯带板正常|RGB LED status normal
#define ELEC_RGBLED_SEQ1_COMM_DISCON      112201000012  // 灯带板连接异常|RGB LED connection abnormal
#define ELEC_RGBLED_SEQ1_COMM_ABNOR       112201000021  // 灯带板通讯异常|RGB LED communication abnormal
#define ELEC_RGBLED_SEQ1_REBOOT           112201000031  // 灯带板启动|RGB LED rebooting
#define ELEC_RGBLED_SEQ1_NOT_READY        112201000041  // 灯带板未就绪|RGB LED not ready

/* 测距传感器 */
#define ELEC_SONAR_SEQ1_NORMAL            112301000000  // 测距传感器1正常|Sonar one status normal
#define ELEC_SONAR_SEQ1_COMM_DISCON       112301000011  // 测距传感器1连接异常|Sonar one connection abnormal
#define ELEC_SONAR_SEQ1_COMM_ABNOR        112301000021  // 测距传感器1通讯异常|Sonar one communication abnormal
#define ELEC_SONAR_SEQ1_REBOOT            112301000031  // 测距传感器1启动|Sonar one rebooting
#define ELEC_SONAR_SEQ1_NOT_READY         112301000041  // 测距传感器1未就绪|Sonar one not ready
#define ELEC_SONAR_SEQ1_HANG_DETECT       112301000092  // 测距传感器1悬空检测|Sonar one hanging detection
#define ELEC_SONAR_SEQ1_BARRIER_DETECT    112301000101  // 测距传感器1障碍物检测|Sonar one obstacle detection
#define ELEC_SONAR_SEQ2_NORMAL            112302000000  // 测距传感器2正常|Sonar two status normal
#define ELEC_SONAR_SEQ2_COMM_DISCON       112302000011  // 测距传感器2连接异常|Sonar two connection abnormal
#define ELEC_SONAR_SEQ2_COMM_ABNOR        112302000021  // 测距传感器2通讯异常|Sonar two communication abnormal
#define ELEC_SONAR_SEQ2_REBOOT            112302000031  // 测距传感器2启动|Sonar two rebooting
#define ELEC_SONAR_SEQ2_NOT_READY         112302000041  // 测距传感器2未就绪|Sonar two not ready
#define ELEC_SONAR_SEQ2_HANG_DETECT       112302000092  // 测距传感器2悬空检测|Sonar two hanging detection
#define ELEC_SONAR_SEQ2_BARRIER_DETECT    112302000101  // 测距传感器2障碍物检测|Sonar two obstacle detection
#define ELEC_SONAR_SEQ3_NORMAL            112303000000  // 测距传感器3正常|Sonar three status normal
#define ELEC_SONAR_SEQ3_COMM_DISCON       112303000011  // 测距传感器3连接异常|Sonar three connection abnormal
#define ELEC_SONAR_SEQ3_COMM_ABNOR        112303000021  // 测距传感器3通讯异常|Sonar three communication abnormal
#define ELEC_SONAR_SEQ3_REBOOT            112303000031  // 测距传感器3启动|Sonar three rebooting
#define ELEC_SONAR_SEQ3_NOT_READY         112303000041  // 测距传感器3未就绪|Sonar three not ready
#define ELEC_SONAR_SEQ3_HANG_DETECT       112303000092  // 测距传感器3悬空检测|Sonar three hanging detection
#define ELEC_SONAR_SEQ3_BARRIER_DETECT    112303000101  // 测距传感器3障碍物检测|Sonar three obstacle detection
#define ELEC_SONAR_SEQ4_NORMAL            112304000000  // 测距传感器4正常|Sonar four status normal
#define ELEC_SONAR_SEQ4_COMM_DISCON       112304000011  // 测距传感器4连接异常|Sonar four connection abnormal
#define ELEC_SONAR_SEQ4_COMM_ABNOR        112304000021  // 测距传感器4通讯异常|Sonar four communication abnormal
#define ELEC_SONAR_SEQ4_REBOOT            112304000031  // 测距传感器4启动|Sonar four rebooting
#define ELEC_SONAR_SEQ4_NOT_READY         112304000041  // 测距传感器4未就绪|Sonar four not ready
#define ELEC_SONAR_SEQ4_HANG_DETECT       112304000092  // 测距传感器4悬空检测|Sonar four hanging detection
#define ELEC_SONAR_SEQ4_BARRIER_DETECT    112304000101  // 测距传感器4障碍物检测|Sonar four obstacle detection
#define ELEC_SONAR_SEQ5_NORMAL            112305000000  // 测距传感器5正常|Sonar five status normal
#define ELEC_SONAR_SEQ5_COMM_DISCON       112305000011  // 测距传感器5连接异常|Sonar five connection abnormal
#define ELEC_SONAR_SEQ5_COMM_ABNOR        112305000021  // 测距传感器5通讯异常|Sonar five communication abnormal
#define ELEC_SONAR_SEQ5_REBOOT            112305000031  // 测距传感器5启动|Sonar five rebooting
#define ELEC_SONAR_SEQ5_NOT_READY         112305000041  // 测距传感器5未就绪|Sonar five not ready
#define ELEC_SONAR_SEQ5_HANG_DETECT       112305000092  // 测距传感器5悬空检测|Sonar five hanging detection
#define ELEC_SONAR_SEQ5_BARRIER_DETECT    112305000101  // 测距传感器5障碍物检测|Sonar five obstacle detection
#define ELEC_SONAR_SEQ6_NORMAL            112306000000  // 测距传感器6正常|Sonar six status normal
#define ELEC_SONAR_SEQ6_COMM_DISCON       112306000011  // 测距传感器6连接异常|Sonar six connection abnormal
#define ELEC_SONAR_SEQ6_COMM_ABNOR        112306000021  // 测距传感器6通讯异常|Sonar six communication abnormal
#define ELEC_SONAR_SEQ6_REBOOT            112306000031  // 测距传感器6启动|Sonar six rebooting
#define ELEC_SONAR_SEQ6_NOT_READY         112306000041  // 测距传感器6未就绪|Sonar six not ready
#define ELEC_SONAR_SEQ6_HANG_DETECT       112306000092  // 测距传感器6悬空检测|Sonar six hanging detection
#define ELEC_SONAR_SEQ6_BARRIER_DETECT    112306000101  // 测距传感器6障碍物检测|Sonar six obstacle detection
#define ELEC_SONAR_SEQ7_NORMAL            112307000000  // 测距传感器7正常|Sonar seven status normal
#define ELEC_SONAR_SEQ7_COMM_DISCON       112307000011  // 测距传感器7连接异常|Sonar seven connection abnormal
#define ELEC_SONAR_SEQ7_COMM_ABNOR        112307000021  // 测距传感器7通讯异常|Sonar seven communication abnormal
#define ELEC_SONAR_SEQ7_REBOOT            112307000031  // 测距传感器7启动|Sonar seven rebooting
#define ELEC_SONAR_SEQ7_NOT_READY         112307000041  // 测距传感器7未就绪|Sonar seven not ready
#define ELEC_SONAR_SEQ7_HANG_DETECT       112307000092  // 测距传感器7悬空检测|Sonar seven hanging detection
#define ELEC_SONAR_SEQ7_BARRIER_DETECT    112307000101  // 测距传感器7障碍物检测|Sonar seven obstacle detection
#define ELEC_SONAR_SEQ8_NORMAL            112308000000  // 测距传感器8正常|Sonar eight status normal
#define ELEC_SONAR_SEQ8_COMM_DISCON       112308000011  // 测距传感器8连接异常|Sonar eight connection abnormal
#define ELEC_SONAR_SEQ8_COMM_ABNOR        112308000021  // 测距传感器8通讯异常|Sonar eight communication abnormal
#define ELEC_SONAR_SEQ8_REBOOT            112308000031  // 测距传感器8启动|Sonar eight rebooting
#define ELEC_SONAR_SEQ8_NOT_READY         112308000041  // 测距传感器8未就绪|Sonar eight not ready
#define ELEC_SONAR_SEQ8_HANG_DETECT       112308000092  // 测距传感器8悬空检测|Sonar eight hanging detection
#define ELEC_SONAR_SEQ8_BARRIER_DETECT    112308000101  // 测距传感器8障碍物检测|Sonar eight obstacle detection
#define ELEC_SONAR_SEQ9_NORMAL            112309000000  // 测距传感器9正常|Sonar nine status normal
#define ELEC_SONAR_SEQ9_COMM_DISCON       112309000011  // 测距传感器9连接异常|Sonar nine connection abnormal
#define ELEC_SONAR_SEQ9_COMM_ABNOR        112309000021  // 测距传感器9通讯异常|Sonar nine communication abnormal
#define ELEC_SONAR_SEQ9_REBOOT            112309000031  // 测距传感器9启动|Sonar nine rebooting
#define ELEC_SONAR_SEQ9_NOT_READY         112309000041  // 测距传感器9未就绪|Sonar nine not ready
#define ELEC_SONAR_SEQ9_HANG_DETECT       112309000092  // 测距传感器9悬空检测|Sonar nine hanging detection
#define ELEC_SONAR_SEQ9_BARRIER_DETECT    112309000101  // 测距传感器9障碍物检测|Sonar nine obstacle detection
#define ELEC_SONAR_SEQ10_NORMAL           112310000000  // 测距传感器10正常|Sonar ten status normal
#define ELEC_SONAR_SEQ10_COMM_DISCON      112310000011  // 测距传感器10连接异常|Sonar ten connection abnormal
#define ELEC_SONAR_SEQ10_COMM_ABNOR       112310000021  // 测距传感器10通讯异常|Sonar ten communication abnormal
#define ELEC_SONAR_SEQ10_REBOOT           112310000031  // 测距传感器10启动|Sonar ten rebooting
#define ELEC_SONAR_SEQ10_NOT_READY        112310000041  // 测距传感器10未就绪|Sonar ten not ready
#define ELEC_SONAR_SEQ10_HANG_DETECT      112310000092  // 测距传感器10悬空检测|Sonar ten hanging detection
#define ELEC_SONAR_SEQ10_BARRIER_DETECT   112310000101  // 测距传感器10障碍物检测|Sonar ten obstacle detection
#define ELEC_SONAR_SEQ11_NORMAL           112311000000  // 测距传感器11正常|Sonar eleven status normal
#define ELEC_SONAR_SEQ11_COMM_DISCON      112311000011  // 测距传感器11连接异常|Sonar eleven connection abnormal
#define ELEC_SONAR_SEQ11_COMM_ABNOR       112311000021  // 测距传感器11通讯异常|Sonar eleven communication abnormal
#define ELEC_SONAR_SEQ11_REBOOT           112311000031  // 测距传感器11启动|Sonar eleven rebooting
#define ELEC_SONAR_SEQ11_NOT_READY        112311000041  // 测距传感器11未就绪|Sonar eleven not ready
#define ELEC_SONAR_SEQ11_HANG_DETECT      112311000092  // 测距传感器11悬空检测|Sonar eleven hanging detection
#define ELEC_SONAR_SEQ11_BARRIER_DETECT   112311000101  // 测距传感器11障碍物检测|Sonar eleven obstacle detection
#define ELEC_SONAR_SEQ12_NORMAL           112312000000  // 测距传感器12正常|Sonar twelve status normal
#define ELEC_SONAR_SEQ12_COMM_DISCON      112312000011  // 测距传感器12连接异常|Sonar twelve connection abnormal
#define ELEC_SONAR_SEQ12_COMM_ABNOR       112312000021  // 测距传感器12通讯异常|Sonar twelve communication abnormal
#define ELEC_SONAR_SEQ12_REBOOT           112312000031  // 测距传感器12启动|Sonar twelve rebooting
#define ELEC_SONAR_SEQ12_NOT_READY        112312000041  // 测距传感器12未就绪|Sonar twelve not ready
#define ELEC_SONAR_SEQ12_HANG_DETECT      112312000092  // 测距传感器12悬空检测|Sonar twelve hanging detection
#define ELEC_SONAR_SEQ12_BARRIER_DETECT   112312000101  // 测距传感器12障碍物检测|Sonar twelve obstacle detection
#define ELEC_SONAR_SEQ13_NORMAL           112313000000  // 测距传感器13正常|Sonar thirteen status normal
#define ELEC_SONAR_SEQ13_COMM_DISCON      112313000011  // 测距传感器13连接异常|Sonar thirteen connection abnormal
#define ELEC_SONAR_SEQ13_COMM_ABNOR       112313000021  // 测距传感器13通讯异常|Sonar thirteen communication abnormal
#define ELEC_SONAR_SEQ13_REBOOT           112313000031  // 测距传感器13启动|Sonar thirteen rebooting
#define ELEC_SONAR_SEQ13_NOT_READY        112313000041  // 测距传感器13未就绪|Sonar thirteen not ready
#define ELEC_SONAR_SEQ13_HANG_DETECT      112313000092  // 测距传感器13悬空检测|Sonar thirteen hanging detection
#define ELEC_SONAR_SEQ13_BARRIER_DETECT   112313000101  // 测距传感器13障碍物检测|Sonar thirteen obstacle detection
#define ELEC_SONAR_SEQ14_NORMAL           112314000000  // 测距传感器14正常|Sonar fourteen status normal
#define ELEC_SONAR_SEQ14_COMM_DISCON      112314000011  // 测距传感器14连接异常|Sonar fourteen connection abnormal
#define ELEC_SONAR_SEQ14_COMM_ABNOR       112314000021  // 测距传感器14通讯异常|Sonar fourteen communication abnormal
#define ELEC_SONAR_SEQ14_REBOOT           112314000031  // 测距传感器14启动|Sonar fourteen rebooting
#define ELEC_SONAR_SEQ14_NOT_READY        112314000041  // 测距传感器14未就绪|Sonar fourteen not ready
#define ELEC_SONAR_SEQ14_HANG_DETECT      112314000092  // 测距传感器14悬空检测|Sonar fourteen hanging detection
#define ELEC_SONAR_SEQ14_BARRIER_DETECT   112314000101  // 测距传感器14障碍物检测|Sonar fourteen obstacle detection
#define ELEC_SONAR_SEQ15_NORMAL           112315000000  // 测距传感器15正常|Sonar fifteen status normal
#define ELEC_SONAR_SEQ15_COMM_DISCON      112315000011  // 测距传感器15连接异常|Sonar fifteen connection abnormal
#define ELEC_SONAR_SEQ15_COMM_ABNOR       112315000021  // 测距传感器15通讯异常|Sonar fifteen communication abnormal
#define ELEC_SONAR_SEQ15_REBOOT           112315000031  // 测距传感器15启动|Sonar fifteen rebooting
#define ELEC_SONAR_SEQ15_NOT_READY        112315000041  // 测距传感器15未就绪|Sonar fifteen not ready
#define ELEC_SONAR_SEQ15_HANG_DETECT      112315000092  // 测距传感器15悬空检测|Sonar fifteen hanging detection
#define ELEC_SONAR_SEQ15_BARRIER_DETECT   112315000101  // 测距传感器15障碍物检测|Sonar fifteen obstacle detection
#define ELEC_SONAR_SEQ16_NORMAL           112316000000  // 测距传感器16正常|Sonar sixteen status normal
#define ELEC_SONAR_SEQ16_COMM_DISCON      112316000011  // 测距传感器16连接异常|Sonar sixteen connection abnormal
#define ELEC_SONAR_SEQ16_COMM_ABNOR       112316000021  // 测距传感器16通讯异常|Sonar sixteen communication abnormal
#define ELEC_SONAR_SEQ16_REBOOT           112316000031  // 测距传感器16启动|Sonar sixteen rebooting
#define ELEC_SONAR_SEQ16_NOT_READY        112316000041  // 测距传感器16未就绪|Sonar sixteen not ready
#define ELEC_SONAR_SEQ16_HANG_DETECT      112316000092  // 测距传感器16悬空检测|Sonar sixteen hanging detection
#define ELEC_SONAR_SEQ16_BARRIER_DETECT   112316000101  // 测距传感器16障碍物检测|Sonar sixteen obstacle detection
#define ELEC_SONAR_SEQ17_NORMAL           112317000000  // 测距传感器17正常|Sonar seventeen status normal
#define ELEC_SONAR_SEQ17_COMM_DISCON      112317000011  // 测距传感器17连接异常|Sonar seventeen connection abnormal
#define ELEC_SONAR_SEQ17_COMM_ABNOR       112317000021  // 测距传感器17通讯异常|Sonar seventeen communication abnormal
#define ELEC_SONAR_SEQ17_REBOOT           112317000031  // 测距传感器17启动|Sonar seventeen rebooting
#define ELEC_SONAR_SEQ17_NOT_READY        112317000041  // 测距传感器17未就绪|Sonar seventeen not ready
#define ELEC_SONAR_SEQ17_HANG_DETECT      112317000092  // 测距传感器17悬空检测|Sonar seventeen hanging detection
#define ELEC_SONAR_SEQ17_BARRIER_DETECT   112317000101  // 测距传感器17障碍物检测|Sonar seventeen obstacle detection
#define ELEC_SONAR_SEQ18_NORMAL           112318000000  // 测距传感器18正常|Sonar eighteen status normal
#define ELEC_SONAR_SEQ18_COMM_DISCON      112318000011  // 测距传感器18连接异常|Sonar eighteen connection abnormal
#define ELEC_SONAR_SEQ18_COMM_ABNOR       112318000021  // 测距传感器18通讯异常|Sonar eighteen communication abnormal
#define ELEC_SONAR_SEQ18_REBOOT           112318000031  // 测距传感器18启动|Sonar eighteen rebooting
#define ELEC_SONAR_SEQ18_NOT_READY        112318000041  // 测距传感器18未就绪|Sonar eighteen not ready
#define ELEC_SONAR_SEQ18_HANG_DETECT      112318000092  // 测距传感器18悬空检测|Sonar eighteen hanging detection
#define ELEC_SONAR_SEQ18_BARRIER_DETECT   112318000101  // 测距传感器18障碍物检测|Sonar eighteen obstacle detection
#define ELEC_SONAR_SEQ19_NORMAL           112319000000  // 测距传感器19正常|Sonar eighteen status normal
#define ELEC_SONAR_SEQ19_COMM_DISCON      112319000011  // 测距传感器19连接异常|Sonar eighteen connection abnormal
#define ELEC_SONAR_SEQ19_COMM_ABNOR       112319000021  // 测距传感器19通讯异常|Sonar eighteen communication abnormal
#define ELEC_SONAR_SEQ19_REBOOT           112319000031  // 测距传感器19启动|Sonar eighteen rebooting
#define ELEC_SONAR_SEQ19_NOT_READY        112319000041  // 测距传感器19未就绪|Sonar eighteen not ready
#define ELEC_SONAR_SEQ19_HANG_DETECT      112319000092  // 测距传感器19悬空检测|Sonar eighteen hanging detection
#define ELEC_SONAR_SEQ19_BARRIER_DETECT   112319000101  // 测距传感器19障碍物检测|Sonar eighteen obstacle detection
#define ELEC_SONAR_SEQ20_NORMAL           112320000000  // 测距传感器20正常|Sonar twenty status normal
#define ELEC_SONAR_SEQ20_COMM_DISCON      112320000011  // 测距传感器20连接异常|Sonar twenty connection abnormal
#define ELEC_SONAR_SEQ20_COMM_ABNOR       112320000021  // 测距传感器20通讯异常|Sonar twenty communication abnormal
#define ELEC_SONAR_SEQ20_REBOOT           112320000031  // 测距传感器20启动|Sonar twenty rebooting
#define ELEC_SONAR_SEQ20_NOT_READY        112320000041  // 测距传感器20未就绪|Sonar twenty not ready
#define ELEC_SONAR_SEQ20_HANG_DETECT      112320000092  // 测距传感器20悬空检测|Sonar twenty hanging detection
#define ELEC_SONAR_SEQ20_BARRIER_DETECT   112320000101  // 测距传感器20障碍物检测|Sonar twenty obstacle detection
#define ELEC_SONAR_SEQ21_NORMAL           112321000000  // 测距传感器21正常|Sonar twenty one status normal
#define ELEC_SONAR_SEQ21_COMM_DISCON      112321000011  // 测距传感器21连接异常|Sonar twenty one connection abnormal
#define ELEC_SONAR_SEQ21_COMM_ABNOR       112321000021  // 测距传感器21通讯异常|Sonar twenty one communication abnormal
#define ELEC_SONAR_SEQ21_REBOOT           112321000031  // 测距传感器21启动|Sonar twenty one rebooting
#define ELEC_SONAR_SEQ21_NOT_READY        112321000041  // 测距传感器21未就绪|Sonar twenty one not ready
#define ELEC_SONAR_SEQ21_HANG_DETECT      112321000092  // 测距传感器21悬空检测|Sonar twenty one hanging detection
#define ELEC_SONAR_SEQ21_BARRIER_DETECT   112321000101  // 测距传感器21障碍物检测|Sonar twenty one obstacle detection
#define ELEC_SONAR_SEQ22_NORMAL           112322000000  // 测距传感器22正常|Sonar twenty two status normal
#define ELEC_SONAR_SEQ22_COMM_DISCON      112322000011  // 测距传感器22连接异常|Sonar twenty two connection abnormal
#define ELEC_SONAR_SEQ22_COMM_ABNOR       112322000021  // 测距传感器22通讯异常|Sonar twenty two communication abnormal
#define ELEC_SONAR_SEQ22_REBOOT           112322000031  // 测距传感器22启动|Sonar twenty two rebooting
#define ELEC_SONAR_SEQ22_NOT_READY        112322000041  // 测距传感器22未就绪|Sonar twenty two not ready
#define ELEC_SONAR_SEQ22_HANG_DETECT      112322000092  // 测距传感器22悬空检测|Sonar twenty two hanging detection
#define ELEC_SONAR_SEQ22_BARRIER_DETECT   112322000101  // 测距传感器22障碍物检测|Sonar twenty two obstacle detection
#define ELEC_SONAR_SEQ23_NORMAL           112323000000  // 测距传感器23正常|Sonar twenty three status normal
#define ELEC_SONAR_SEQ23_COMM_DISCON      112323000011  // 测距传感器23连接异常|Sonar twenty three connection abnormal
#define ELEC_SONAR_SEQ23_COMM_ABNOR       112323000021  // 测距传感器23通讯异常|Sonar twenty three communication abnormal
#define ELEC_SONAR_SEQ23_REBOOT           112323000031  // 测距传感器23启动|Sonar twenty three rebooting
#define ELEC_SONAR_SEQ23_NOT_READY        112323000041  // 测距传感器23未就绪|Sonar twenty three not ready
#define ELEC_SONAR_SEQ23_HANG_DETECT      112323000092  // 测距传感器23悬空检测|Sonar twenty three hanging detection
#define ELEC_SONAR_SEQ23_BARRIER_DETECT   112323000101  // 测距传感器23障碍物检测|Sonar twenty three obstacle detection
#define ELEC_SONAR_SEQ24_NORMAL           112324000000  // 测距传感器24正常|Sonar twenty four status normal
#define ELEC_SONAR_SEQ24_COMM_DISCON      112324000011  // 测距传感器24连接异常|Sonar twenty four connection abnormal
#define ELEC_SONAR_SEQ24_COMM_ABNOR       112324000021  // 测距传感器24通讯异常|Sonar twenty four communication abnormal
#define ELEC_SONAR_SEQ24_REBOOT           112324000031  // 测距传感器24启动|Sonar twenty four rebooting
#define ELEC_SONAR_SEQ24_NOT_READY        112324000041  // 测距传感器24未就绪|Sonar twenty four not ready
#define ELEC_SONAR_SEQ24_HANG_DETECT      112324000092  // 测距传感器24悬空检测|Sonar twenty four hanging detection
#define ELEC_SONAR_SEQ24_BARRIER_DETECT   112324000101  // 测距传感器24障碍物检测|Sonar twenty four obstacle detection

/* 磁传感器 */
#define ELEC_MAGNETISM_SEQ1_NORMAL        112401000000  // 磁传感器正常|Magnetism status normal
#define ELEC_MAGNETISM_SEQ1_COMM_DISCON   112401000011  // 磁传感器连接异常|Magnetism connection abnormal
#define ELEC_MAGNETISM_SEQ1_COMM_ABNOR    112401000021  // 磁传感器通讯异常|Magnetism communication abnormal
#define ELEC_MAGNETISM_SEQ1_REBOOT        112401000031  // 磁传感器启动|Magnetism rebooting
#define ELEC_MAGNETISM_SEQ1_NOT_READY     112401000041  // 磁传感器未就绪|Magnetism not ready

/* UWB */
#define ELEC_UWB_SEQ1_NORMAL              112501000000  // UWB正常|UWB status normal
#define ELEC_UWB_SEQ1_COMM_DISCON         112501000011  // UWB连接异常|UWB connection abnormal
#define ELEC_UWB_SEQ1_COMM_ABNOR          112501000021  // UWB通讯异常|UWB communication abnormal
#define ELEC_UWB_SEQ1_REBOOT              112501000031  // UWB启动|UWB rebooting
#define ELEC_UWB_SEQ1_NOT_READY           112501000041  // UWB未就绪|UWB not ready

/* IMU */
#define ELEC_IMU_SEQ1_NORMAL              112601000000  // IMU正常|IMU status normal
#define ELEC_IMU_SEQ1_COMM_DISCON         112601000013  // IMU连接异常|IMU connection abnormal
#define ELEC_IMU_SEQ1_COMM_ABNOR          112601000022  // IMU通讯异常|IMU communication abnormal
#define ELEC_IMU_SEQ1_REBOOT              112601000031  // IMU启动|IMU rebooting
#define ELEC_IMU_SEQ1_NOT_READY           112601000042  // IMU未就绪|IMU not ready
#define ELEC_IMU_SEQ1_DRIFT               112601000092  // IMU漂移|IMU drifting

/* 举升机构 */
#define ELEC_LIFT_SEQ1_NORMAL               114001000000  // 举升机构正常|Lifting Mechanism one status normal
#define ELEC_LIFT_SEQ1_COMM_DISCON          114001000013  // 举升机构连接异常|Lifting Mechanism one connection abnormal
#define ELEC_LIFT_SEQ1_COMM_ABNOR           114001000022  // 举升机构通讯异常|Lifting Mechanism one communication abnormal
#define ELEC_LIFT_SEQ1_REBOOT               114001000031  // 举升机构启动|Lifting Mechanism one rebooting
#define ELEC_LIFT_SEQ1_NOT_READY            114001000041  // 举升机构未就绪|Lifting Mechanism one not ready
#define ELEC_LIFT_SEQ1_DRV_COMM_DISCON      114001000093  // 举升机构驱动器连接异常|Lifting Mechanism one driver connection abnormal
#define ELEC_LIFT_SEQ1_DRV_COMM_ABNOR       114001000102  // 举升机构驱动器通讯异常|Lifting Mechanism one driver communication abnormal
#define ELEC_LIFT_SEQ1_DRV_LOW_VLT          114001000112  // 举升机构驱动器欠压|Lifting Mechanism one driver low voltage
#define ELEC_LIFT_SEQ1_DRV_OVER_VLT         114001000122  // 举升机构驱动器过压|Lifting Mechanism one driver over voltage
#define ELEC_LIFT_SEQ1_DRV_OVER_TEMP        114001000132  // 举升机构驱动器过温|Lifting Mechanism one driver overheat
#define ELEC_LIFTR_SEQ1_MOT_UVW_ABNOR       114001000143  // 举升机构相线异常|Lifting Mechanism one motor UVW abnormal
#define ELEC_LIFTR_SEQ1_MOT_HALL_ABNOR      114001000152  // 举升机构霍尔异常|Lifting Mechanism one motor hall abnormal
#define ELEC_LIFTR_SEQ1_MOT_ENCODE_ABNOR    114001000162  // 举升机构编码器异常|Lifting Mechanism one motor encoder abnormal
#define ELEC_LIFTR_SEQ1_MOT_OVER_CUR        114001000172  // 举升机构电机过流|Lifting Mechanism one motor overcurrent
#define ELEC_LIFTR_SEQ1_MOT_OVER_LOAD       114001000182  // 举升机构电机过载|Lifting Mechanism one motor overload
#define ELEC_LIFTR_SEQ1_MOT_OVER_TEMP       114001000192  // 举升机构电机过温|Lifting Mechanism one motor overheat
#define ELEC_LIFTR_SEQ1_MOT_LOW_SPEED       114001000201  // 举升机构达不到目标转速|Lifting Mechanism one motor low rotation speed
#define ELEC_LIFTR_SEQ1_MOT_OVER_SPEED      114001000212  // 举升机构超过转速上限|Lifting Mechanism one motor over rotation speed
#define ELEC_LIFTR_SEQ1_DRV_OTHER_ABNOR     114001000242  // 举升机构驱动器其它异常|Lifting Mechanism one driver other abnormal
#define ELEC_LIFTR_SEQ1_LIMIT_UP_UNDETECT   114001000252  // 举升机构上限位未检测|Lifting Mechanism one upper limit not detected
#define ELEC_LIFTR_SEQ1_LIMIT_DOWN_UNDETECT 114001000262  // 举升机构下限位未检测|Lifting Mechanism one lower limit not detected
#define ELEC_LIFTR_SEQ1_LIMIT_LOGIC_ABNOR   114001000272  // 举升机构限位逻辑异常|Lifting Mechanism one limit logic abnormal
#define ELEC_LIFTR_SEQ1_EXEC_TIMEOUT        114001000332  // 举升机构执行超时|Lifting Mechanism one execution timeout
#define ELEC_LIFTR_SEQ1_SYNC_FAILED         114001000342  // 举升机构同步失败|Lifting Mechanism one synchronization failed
#define ELEC_LIFTR_SEQ1_POSE_ABNOR          114001000352  // 举升机构位置异常|Lifting Mechanism one pose abnormal

#define ELEC_LIFT_SEQ2_NORMAL               114002000000  // 举升机构正常|Lifting Mechanism two status normal
#define ELEC_LIFT_SEQ2_COMM_DISCON          114002000013  // 举升机构连接异常|Lifting Mechanism two connection abnormal
#define ELEC_LIFT_SEQ2_COMM_ABNOR           114002000022  // 举升机构通讯异常|Lifting Mechanism two communication abnormal
#define ELEC_LIFT_SEQ2_REBOOT               114002000031  // 举升机构启动|Lifting Mechanism two rebooting
#define ELEC_LIFT_SEQ2_NOT_READY            114002000041  // 举升机构未就绪|Lifting Mechanism two not ready
#define ELEC_LIFT_SEQ2_DRV_COMM_DISCON      114002000093  // 举升机构驱动器连接异常|Lifting Mechanism two driver connection abnormal
#define ELEC_LIFT_SEQ2_DRV_COMM_ABNOR       114002000102  // 举升机构驱动器通讯异常|Lifting Mechanism two driver communication abnormal
#define ELEC_LIFT_SEQ2_DRV_LOW_VLT          114002000112  // 举升机构驱动器欠压|Lifting Mechanism two driver low voltage
#define ELEC_LIFT_SEQ2_DRV_OVER_VLT         114002000122  // 举升机构驱动器过压|Lifting Mechanism two driver over voltage
#define ELEC_LIFT_SEQ2_DRV_OVER_TEMP        114002000132  // 举升机构驱动器过温|Lifting Mechanism two driver overheat
#define ELEC_LIFTR_SEQ2_MOT_UVW_ABNOR       114002000143  // 举升机构相线异常|Lifting Mechanism two motor UVW abnormal
#define ELEC_LIFTR_SEQ2_MOT_HALL_ABNOR      114002000152  // 举升机构霍尔异常|Lifting Mechanism two motor hall abnormal
#define ELEC_LIFTR_SEQ2_MOT_ENCODE_ABNOR    114002000162  // 举升机构编码器异常|Lifting Mechanism two motor encoder abnormal
#define ELEC_LIFTR_SEQ2_MOT_OVER_CUR        114002000172  // 举升机构电机过流|Lifting Mechanism two motor overcurrent
#define ELEC_LIFTR_SEQ2_MOT_OVER_LOAD       114002000182  // 举升机构电机过载|Lifting Mechanism two motor overload
#define ELEC_LIFTR_SEQ2_MOT_OVER_TEMP       114002000192  // 举升机构电机过温|Lifting Mechanism two motor overheat
#define ELEC_LIFTR_SEQ2_MOT_LOW_SPEED       114002000201  // 举升机构达不到目标转速|Lifting Mechanism two motor low rotation speed
#define ELEC_LIFTR_SEQ2_MOT_OVER_SPEED      114002000212  // 举升机构超过转速上限|Lifting Mechanism two motor over rotation speed
#define ELEC_LIFTR_SEQ2_DRV_OTHER_ABNOR     114002000242  // 举升机构驱动器其它异常|Lifting Mechanism two driver other abnormal
#define ELEC_LIFTR_SEQ2_LIMIT_UP_UNDETECT   114002000252  // 举升机构上限位未检测|Lifting Mechanism two upper limit not detected
#define ELEC_LIFTR_SEQ2_LIMIT_DOWN_UNDETECT 114002000262  // 举升机构下限位未检测|Lifting Mechanism two lower limit not detected
#define ELEC_LIFTR_SEQ2_LIMIT_LOGIC_ABNOR   114002000272  // 举升机构限位逻辑异常|Lifting Mechanism two limit logic abnormal
#define ELEC_LIFTR_SEQ2_EXEC_TIMEOUT        114002000332  // 举升机构执行超时|Lifting Mechanism two execution timeout
#define ELEC_LIFTR_SEQ2_SYNC_FAILED         114002000342  // 举升机构同步失败|Lifting Mechanism two synchronization failed
#define ELEC_LIFTR_SEQ2_POSE_ABNOR          114002000352  // 举升机构位置异常|Lifting Mechanism two pose abnormal

/* 辊筒机构 */
#define ELEC_ROLLER_SEQ1_NORMAL           114101000000  // 辊筒机构正常|Roller Mechanism one status normal
#define ELEC_ROLLER_SEQ1_BLOCK            114101000012  // 辊筒机构堵转停止|Roll mechanism one stops plugging
#define ELEC_ROLLER_SEQ1_NOT_STUDY        114101000023  // 辊筒机构未学习相序|Roll mechanism one did not learn the phase sequence
#define ELEC_ROLLER_SEQ1_HALL_ABNOR       114101000032  // 辊筒机构霍尔错误|Roller Mechanism one motor hall abnormal
#define ELEC_ROLLER_SEQ1_UNREACHABLE      114101000041  // 辊筒机构目标不可达|Roller Mechanism one not ready
#define ELEC_ROLLER_SEQ1_COMM_ABNOR       114101000052  // 辊筒机构通讯异常|Roller Mechanism one driver communication abnormal
#define ELEC_ROLLER_SEQ2_NORMAL           114102000000  // 辊筒机构正常|Roller Mechanism two status normal
#define ELEC_ROLLER_SEQ2_BLOCK            114102000012  // 辊筒机构堵转停止|Roll mechanism two stops plugging
#define ELEC_ROLLER_SEQ2_NOT_STUDY        114102000023  // 辊筒机构未学习相序|Roll mechanism two did not learn the phase sequence
#define ELEC_ROLLER_SEQ2_HALL_ABNOR       114102000032  // 辊筒机构霍尔错误|Roller Mechanism two motor hall abnormal
#define ELEC_ROLLER_SEQ2_UNREACHABLE      114102000041  // 辊筒机构目标不可达|Roller Mechanism two not ready
#define ELEC_ROLLER_SEQ2_COMM_ABNOR       114102000052  // 辊筒机构通讯异常|Roller Mechanism two driver communication abnormal

/* 牵引机构 */
#define ELEC_TRACTOR_SEQ1_NORMAL          114201000000  // 牵引机构正常|Tractor Mechanism status normal
#define ELEC_TRACTOR_SEQ1_BLOCK           114201000012  // 牵引机构堵转停止|Tractor mechanism stops plugging
#define ELEC_TRACTOR_SEQ1_NOT_STUDY       114201000023  // 牵引机构未学习相序|Tractor mechanism did not learn the phase sequence
#define ELEC_TRACTOR_SEQ1_HALL_ABNOR      114201000032  // 牵引机构霍尔错误|Tractor Mechanism motor hall abnormal
#define ELEC_TRACTOR_SEQ1_UNREACHABLE     114201000041  // 牵引机构目标不可达|Tractor Mechanism not ready
#define ELEC_TRACTOR_SEQ1_COMM_ABNOR      114201000052  // 牵引机构通讯异常|Tractor Mechanism driver communication abnormal
}
