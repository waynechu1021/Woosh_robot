uint32 id		#通道id
int32 type		#通道类型, 双行道=0,单行道=1,单向道=2,路口=3, 狭窄通道=4,定位域=5,爬坡域=6,Odom域=7
float32 slope_angle 	#爬坡域角度
NavFieldPoint slope_arrow   #爬坡域箭头位姿
int32 capacity		#通道容量
float32 wait_time_out	#停等超时模式下的超时时间
int32 nav_mode		#导航模式,模糊避让=0,精准避让=1,停等=2,停等超时=3, 狭窄通道=10, 磁条导航=11, 二维码导航=12
float32 max_speed		#通道最高速度,设为0,则不约束最高速度,非0则以设定的速度为机器人在该通道的最高速度
int32 direction		#单向道的方向
float32 radius  #半径
float32 offset  # 偏移
NavFieldPoint[] vertex	#域顶点
NavFieldPoint[] nav_pos	#域中引导点数组,单向道中引导点的存储顺序决定其方向，数组里点的id有效
NavFieldPoint entry	#单向道入口
NavFieldPoint extrance	#单向道出口
