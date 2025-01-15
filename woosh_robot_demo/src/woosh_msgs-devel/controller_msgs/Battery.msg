std_msgs/Header header
uint8 submodule
uint8 battery_percentage
uint8 charge_mode
uint8 charge_status
float32 battery_voltage
float32 battery_current
float32 time_remain
int8 temp_max
int8 temp_min
float32 capacity_memain
float32 capacity_mull
float32 capacity_mesign
uint16 charge_cycle
uint16 battery_cycle
float32 cell_voltage_max
float32 cell_voltage_min
uint32 bms_status

#chargeMode
uint8 MANUAL_MODE = 0
uint8 AUTO_MODE = 1

#chargeStatus
uint8 DISCHARGE = 0
uint8 CHARGING = 1
