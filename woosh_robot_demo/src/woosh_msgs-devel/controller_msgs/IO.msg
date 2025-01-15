std_msgs/Header header
uint8 module
uint8 submodule
uint8 id
uint8 status

#channel and IO
#0x01 movebase key
#0x02 motor
#0x03 alarm  0.Beep 1.red 2.yellow 3.green 4.laser
#0x81 photoelec

#status
#0 default
#1 trigger
#2 stop
