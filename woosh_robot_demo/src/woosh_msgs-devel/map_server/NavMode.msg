uint32 id                #通道id
int32 type               #通道类型, 双行道=0,单行道=1,单向道=2,路口=3, 狭窄通道=4,定位域=5,爬坡域=6,Odom域=7,自动门域=8,限速域=9
int8 triggered_mode      #触发模式  ，  进方域：0  ，  出方域：1    进圆域：2    出圆域：3
geometry_msgs/Point nav_in   #通道入点
geometry_msgs/Point nav_out  #通道出点
