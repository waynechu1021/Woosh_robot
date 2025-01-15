namespace embed {

/* 下位机系统 */
#define EMBED_SYSTEM_INIT_COMM_DISCON             120101000052  // 初始化连接异常|Initialization connection abnormal
#define EMBED_SYSTEM_INIT_EXEC_TIMEOUT            120101000112  // 初始化命令执行超时|Initialization execution timeout

/* 运动控制 */
#define EMBED_DRIVER_STEP_HARDWARE_ABNOR          120301000013  // 步进控制硬件异常|Stepping control hardware abnormal
#define EMBED_DRIVER_STEP_OCCUPIED                120301000022  // 步进控制控制被占用|Stepping control Occupied
#define EMBED_DRIVER_STEP_UNREACHABLE             120301000032  // 步进控制命令不可达|Stepping control order unreachable
#define EMBED_DRIVER_STEP_CANCEL                  120301000041  // 步进控制取消|Stepping control cancelled
#define EMBED_DRIVER_STEP_COMM_DISCON             120301000052  // 步进控制连接异常|Stepping control connection abnormal 
#define EMBED_DRIVER_STEP_COMM_ABNOR              120301000062  // 步进控制通讯异常|Stepping control communication abnormal
#define EMBED_DRIVER_STEP_SLAVE_FEEDBACK_ABNOR    120301000072  // 步进控制下级反馈异常|Stepping control slave feedback abnormal
#define EMBED_DRIVER_STEP_SLAVE_COMM_DISCON       120301000082  // 步进控制下级连接异常|Stepping control slave connection abnormal
#define EMBED_DRIVER_STEP_SLAVE_COMM_ABNOR        120301000092  // 步进控制下级通讯异常|Stepping control slave communication abnormal
#define EMBED_DRIVER_STEP_SLAVE_EXEC_TIMEOUT      120301000102  // 步进控制下级执行超时|Stepping control slave execution timeout
#define EMBED_DRIVER_STEP_EXEC_TIMEOUT            120301000112  // 步进控制命令执行超时|Stepping control order execution timeout
#define EMBED_DRIVER_STEP_START_STATUS_ABNOR      120301000162  // 步进控制起始状态异常|Stepping control starting status abnormal
#define EMBED_DRIVER_STEP_PROCESS_STATUS_ABNOR    120301000172  // 步进控制过程状态异常|Stepping control processing status abnormal
#define EMBED_DRIVER_STEP_END_STATUS_ABNOR        120301000182  // 步进控制结束状态异常|Stepping control ending status abnormal
#define EMBED_DRIVER_STEP_EXT_DISTURB             120301000192  // 步进控制外部干扰中断|Stepping control external disturbance
#define EMBED_DRIVER_STEP_PREEMPT                 120301000202  // 步进控制抢占中断|Stepping control preempted

/* 充电控制 */
#define EMBED_CHARGER_SEQ1_HARDWARE_ABNOR         120601000013  // 充电控制硬件异常|Charge control hardware abnormal
#define EMBED_CHARGER_SEQ1_OCCUPIED               120601000022  // 充电控制控制被占用|Charge control Occupied
#define EMBED_CHARGER_SEQ1_UNREACHABLE            120601000032  // 充电控制命令不可达|Charge control order unreachable
#define EMBED_CHARGER_SEQ1_CANCEL                 120601000041  // 充电控制取消|Charge control cancelled
#define EMBED_CHARGER_SEQ1_COMM_DISCON            120601000052  // 充电控制连接异常|Charge control connection abnormal
#define EMBED_CHARGER_SEQ1_COMM_ABNOR             120601000062  // 充电控制通讯异常|Charge control communication abnormal
#define EMBED_CHARGER_SEQ1_SLAVE_FEEDBACK_ABNOR   120601000072  // 充电控制下级反馈异常|Charge control slave feedback abnormal
#define EMBED_CHARGER_SEQ1_SLAVE_COMM_DISCON      120601000082  // 充电控制下级连接异常|Charge control slave connection abnormal
#define EMBED_CHARGER_SEQ1_SLAVE_COMM_ABNOR       120601000092  // 充电控制下级通讯异常|Charge control slave communication abnormal
#define EMBED_CHARGER_SEQ1_SLAVE_EXEC_TIMEOUT     120601000102  // 充电控制下级执行超时|Charge control slave execution timeout
#define EMBED_CHARGER_SEQ1_EXEC_TIMEOUT           120601000112  // 充电控制命令执行超时|Charge control order execution timeout
#define EMBED_CHARGER_SEQ1_START_STATUS_ABNOR     120601000162  // 充电控制起始状态异常|Charge control starting status abnormal
#define EMBED_CHARGER_SEQ1_PROCESS_STATUS_ABNOR   120601000172  // 充电控制过程状态异常|Charge control processing status abnormal
#define EMBED_CHARGER_SEQ1_END_STATUS_ABNOR       120601000182  // 充电控制结束状态异常|Charge control ending status abnormal
#define EMBED_CHARGER_SEQ1_EXT_DISTURB            120601000192  // 充电控制外部干扰中断|Charge control external disturbance
#define EMBED_CHARGER_SEQ1_PREEMPT                120601000202  // 充电控制抢占中断|Charge control preempted

/* 磁导引 */
#define EMBED_MAGNETISM_SEQ1_HARDWARE_ABNOR       122401000013  // 磁导引硬件异常|Magnetic guiding hardware Abnormal
#define EMBED_MAGNETISM_SEQ1_OCCUPIED             122401000022  // 磁导引控制被占用|Magnetic guiding Occupied
#define EMBED_MAGNETISM_SEQ1_UNREACHABLE          122401000032  // 磁导引命令不可达|Magnetic guiding order unreachable
#define EMBED_MAGNETISM_SEQ1_CANCEL               122401000041  // 磁导引取消|Magnetic guiding cancelled
#define EMBED_MAGNETISM_SEQ1_COMM_DISCON          122401000052  // 磁导引连接异常|Magnetic guiding connection abnormal
#define EMBED_MAGNETISM_SEQ1_COMM_ABNOR           122401000062  // 磁导引通讯异常|Magnetic guiding communication abnormal
#define EMBED_MAGNETISM_SEQ1_SLAVE_FEEDBACK_ABNOR 122401000072  // 磁导引下级反馈异常|Magnetic guiding slave feedback abnormal
#define EMBED_MAGNETISM_SEQ1_SLAVE_COMM_DISCON    122401000082  // 磁导引下级连接异常|Magnetic guiding slave connection abnormal
#define EMBED_MAGNETISM_SEQ1_SLAVE_COMM_ABNOR     122401000092  // 磁导引下级通讯异常|Magnetic guiding slave communication abnormal
#define EMBED_MAGNETISM_SEQ1_SLAVE_EXEC_TIMEOUT   122401000102  // 磁导引下级执行超时|Magnetic guiding slave execution timeout
#define EMBED_MAGNETISM_SEQ1_EXEC_TIMEOUT         122401000112  // 磁导引命令执行超时|Magnetic guiding order execution timeout
#define EMBED_MAGNETISM_SEQ1_START_STATUS_ABNOR   122401000162  // 磁导引起始状态异常|Magnetic guiding starting status abnormal
#define EMBED_MAGNETISM_SEQ1_PROCESS_STATUS_ABNOR 122401000172  // 磁导引过程状态异常|Magnetic guiding processing status abnormal
#define EMBED_MAGNETISM_SEQ1_END_STATUS_ABNOR     122401000182  // 磁导引结束状态异常|Magnetic guiding ending status abnormal
#define EMBED_MAGNETISM_SEQ1_EXT_DISTURB          122401000192  // 磁导引外部干扰中断|Magnetic guiding external disturbance
#define EMBED_MAGNETISM_SEQ1_PREEMPT              122401000202  // 磁导引抢占中断|Magnetic guiding preempted

/* UWB */
#define EMBED_BEACON_SEQ1_OUT_OF_GROUP            122501000011  // UWB不在组范围|UWB out of group

/* 举升控制 */
#define EMBED_LIFT_SEQ1_HARDWARE_ABNOR            124001000013  // 举升控制硬件异常|Lifting Control Hardware Abnormal
#define EMBED_LIFT_SEQ1_OCCUPIED                  124001000022  // 举升控制控制被占用|Lifting Control occupied
#define EMBED_LIFT_SEQ1_UNREACHABLE               124001000032  // 举升控制命令不可达|Lifting Control unreachable
#define EMBED_LIFT_SEQ1_CANCEL                    124001000041  // 举升控制取消|Lifting Control cancelled
#define EMBED_LIFT_SEQ1_COMM_DISCON               124001000052  // 举升控制连接异常|Lifting Control connection abnormal
#define EMBED_LIFT_SEQ1_COMM_ABNOR                124001000062  // 举升控制通讯异常|Lifting Control communication abnormal
#define EMBED_LIFT_SEQ1_SLAVE_FEEDBACK_ABNOR      124001000072  // 举升控制下级反馈异常|Lifting Control slave feedback abnormal
#define EMBED_LIFT_SEQ1_SLAVE_COMM_DISCON         124001000082  // 举升控制下级连接异常|Lifting Control slave connection abnormal
#define EMBED_LIFT_SEQ1_SLAVE_COMM_ABNOR          124001000092  // 举升控制下级通讯异常|Lifting Control slave communication abnormal
#define EMBED_LIFT_SEQ1_SLAVE_EXEC_TIMEOUT        124001000102  // 举升控制下级执行超时|Lifting Control slave execution timeout
#define EMBED_LIFT_SEQ1_EXEC_TIMEOUT              124001000112  // 举升控制命令执行超时|Lifting Control execution timeout
#define EMBED_LIFT_SEQ1_START_STATUS_ABNOR        124001000162  // 举升控制起始状态异常|Lifting Control starting status abnormal
#define EMBED_LIFT_SEQ1_PROCESS_STATUS_ABNOR      124001000172  // 举升控制过程状态异常|Lifting Control processing status abnormal
#define EMBED_LIFT_SEQ1_END_STATUS_ABNOR          124001000182  // 举升控制结束状态异常|Lifting Control ending status abnormal
#define EMBED_LIFT_SEQ1_EXT_DISTURB               124001000192  // 举升控制外部干扰中断|Lifting Control external disturbance
#define EMBED_LIFT_SEQ1_PREEMPT                   124001000202  // 举升控制抢占中断|Lifting Control preempted

/* 辊筒控制 */
#define EMBED_ROLLER_SEQ1_HARDWARE_ABNOR          124101000013  // 辊筒控制1层硬件异常|Roller Control one hardware abnormal
#define EMBED_ROLLER_SEQ1_OCCUPIED                124101000022  // 辊筒控制1层控制被占用|Roller Control one occupied
#define EMBED_ROLLER_SEQ1_UNREACHABLE             124101000032  // 辊筒控制1层命令不可达|Roller Control one unreachable
#define EMBED_ROLLER_SEQ1_CANCEL                  124101000041  // 辊筒控制1层取消|Roller Control one vancelled
#define EMBED_ROLLER_SEQ1_COMM_DISCON             124101000052  // 辊筒控制1层连接异常|Roller Control one vonnection abnormal
#define EMBED_ROLLER_SEQ1_COMM_ABNOR              124101000062  // 辊筒控制1层通讯异常|Roller Control one communication abnormal
#define EMBED_ROLLER_SEQ1_SLAVE_FEEDBACK_ABNOR    124101000072  // 辊筒控制1层下级反馈异常|Roller Control one slave feedback abnormal
#define EMBED_ROLLER_SEQ1_SLAVE_COMM_DISCON       124101000082  // 辊筒控制1层下级连接异常|Roller Control one slave connection abnormal
#define EMBED_ROLLER_SEQ1_SLAVE_COMM_ABNOR        124101000092  // 辊筒控制1层下级通讯异常|Roller Control one slave communication abnormal
#define EMBED_ROLLER_SEQ1_SLAVE_EXEC_TIMEOUT      124101000102  // 辊筒控制1层下级执行超时|Roller Control one slave execution timeout
#define EMBED_ROLLER_SEQ1_EXEC_TIMEOUT            124101000112  // 辊筒控制1层命令执行超时|Roller Control one execution timeout
#define EMBED_ROLLER_SEQ1_START_STATUS_ABNOR      124101000162  // 辊筒控制1层起始状态异常|Roller Control one starting status abnormal
#define EMBED_ROLLER_SEQ1_PROCESS_STATUS_ABNOR    124101000172  // 辊筒控制1层过程状态异常|Roller Control one processing status abnormal
#define EMBED_ROLLER_SEQ1_END_STATUS_ABNOR        124101000182  // 辊筒控制1层结束状态异常|Roller Control one ending status abnormal
#define EMBED_ROLLER_SEQ1_EXT_DISTURB             124101000192  // 辊筒控制1层外部干扰中断|Roller Control one external disturbance
#define EMBED_ROLLER_SEQ1_PREEMPT                 124101000202  // 辊筒控制1层抢占中断|Roller Control one preempted

#define EMBED_ROLLER_SEQ2_HARDWARE_ABNOR          124102000013  // 辊筒控制2层硬件异常|Roller Control two hardware abnormal
#define EMBED_ROLLER_SEQ2_OCCUPIED                124102000022  // 辊筒控制2层控制被占用|Roller Control two occupied
#define EMBED_ROLLER_SEQ2_UNREACHABLE             124102000032  // 辊筒控制2层命令不可达|Roller Control two unreachable
#define EMBED_ROLLER_SEQ2_CANCEL                  124102000041  // 辊筒控制2层取消|Roller Control two vancelled
#define EMBED_ROLLER_SEQ2_COMM_DISCON             124102000052  // 辊筒控制2层连接异常|Roller Control two vonnection abnormal
#define EMBED_ROLLER_SEQ2_COMM_ABNOR              124102000062  // 辊筒控制2层通讯异常|Roller Control two communication abnormal
#define EMBED_ROLLER_SEQ2_SLAVE_FEEDBACK_ABNOR    124102000072  // 辊筒控制2层下级反馈异常|Roller Control two slave feedback abnormal
#define EMBED_ROLLER_SEQ2_SLAVE_COMM_DISCON       124102000082  // 辊筒控制2层下级连接异常|Roller Control two slave connection abnormal
#define EMBED_ROLLER_SEQ2_SLAVE_COMM_ABNOR        124102000092  // 辊筒控制2层下级通讯异常|Roller Control two slave communication abnormal
#define EMBED_ROLLER_SEQ2_SLAVE_EXEC_TIMEOUT      124102000102  // 辊筒控制2层下级执行超时|Roller Control two slave execution timeout
#define EMBED_ROLLER_SEQ2_EXEC_TIMEOUT            124102000112  // 辊筒控制2层命令执行超时|Roller Control two execution timeout
#define EMBED_ROLLER_SEQ2_START_STATUS_ABNOR      124102000162  // 辊筒控制2层起始状态异常|Roller Control two starting status abnormal
#define EMBED_ROLLER_SEQ2_PROCESS_STATUS_ABNOR    124102000172  // 辊筒控制2层过程状态异常|Roller Control two processing status abnormal
#define EMBED_ROLLER_SEQ2_END_STATUS_ABNOR        124102000182  // 辊筒控制2层结束状态异常|Roller Control two ending status abnormal
#define EMBED_ROLLER_SEQ2_EXT_DISTURB             124102000192  // 辊筒控制2层外部干扰中断|Roller Control two external disturbance
#define EMBED_ROLLER_SEQ2_PREEMPT                 124102000202  // 辊筒控制2层抢占中断|Roller Control two preempted

/* 牵引控制 */
#define EMBED_TRACTOR_SEQ1_HARDWARE_ABNOR         124201000013  // 牵引控制硬件异常|Tractor Control hardware abnormal
#define EMBED_TRACTOR_SEQ1_OCCUPIED               124201000022  // 牵引控制控制被占用|Tractor Control occupied
#define EMBED_TRACTOR_SEQ1_UNREACHABLE            124201000032  // 牵引控制命令不可达|Tractor Control unreachable
#define EMBED_TRACTOR_SEQ1_CANCEL                 124201000041  // 牵引控制取消|Tractor Control cancelled
#define EMBED_TRACTOR_SEQ1_COMM_DISCON            124201000052  // 牵引控制连接异常|Tractor Control connection abnormal
#define EMBED_TRACTOR_SEQ1_COMM_ABNOR             124201000062  // 牵引控制通讯异常|Tractor Control communication abnormal
#define EMBED_TRACTOR_SEQ1_SLAVE_FEEDBACK_ABNOR   124201000072  // 牵引控制下级反馈异常|Tractor Control slave feedback abnormal
#define EMBED_TRACTOR_SEQ1_SLAVE_COMM_DISCON      124201000082  // 牵引控制下级连接异常|Tractor Control slave connection abnormal
#define EMBED_TRACTOR_SEQ1_SLAVE_COMM_ABNOR       124201000092  // 牵引控制下级通讯异常|Tractor Control slave communication abnormal
#define EMBED_TRACTOR_SEQ1_SLAVE_EXEC_TIMEOUT     124201000102  // 牵引控制下级执行超时|Tractor Control slave execution timeout
#define EMBED_TRACTOR_SEQ1_EXEC_TIMEOUT           124201000112  // 牵引控制命令执行超时|Tractor Control execution timeout
#define EMBED_TRACTOR_SEQ1_START_STATUS_ABNOR     124201000162  // 牵引控制起始状态异常|Tractor Control starting status abnormal
#define EMBED_TRACTOR_SEQ1_PROCESS_STATUS_ABNOR   124201000172  // 牵引控制过程状态异常|Tractor Control processing status abnormal
#define EMBED_TRACTOR_SEQ1_END_STATUS_ABNOR       124201000182  // 牵引控制结束状态异常|Tractor Control ending status abnormal
#define EMBED_TRACTOR_SEQ1_EXT_DISTURB            124201000192  // 牵引控制外部干扰中断|Tractor Control external disturbance
#define EMBED_TRACTOR_SEQ1_PREEMPT                124201000202  // 牵引控制抢占中断|Tractor Control preempted
}
