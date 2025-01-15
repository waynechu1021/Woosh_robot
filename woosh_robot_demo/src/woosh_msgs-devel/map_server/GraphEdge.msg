uint32 source		#边源marker的id
uint32 target		#边汇marker的id
uint32 field_id		#边所在域的id，如果边不在域内，则id为0
float32 weight		#边权重，主要影响路径规划
float32 busy_level	#繁忙系数，越大，路径规划器更不倾向选择该边
float32 path_length	#路径长度
nav_msgs/Path path	#边路径点
