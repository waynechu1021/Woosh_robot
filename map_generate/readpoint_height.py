#前提:点云高度为z轴
import numpy as np
import open3d as o3d
import matplotlib.pyplot as plt
from scipy.ndimage import gaussian_filter1d
import open3d as o3d
from sklearn.cluster import DBSCAN
from scipy.signal import find_peaks
# 读取PLY文件
ply_file_path = 'map_generate/record_2_13_raw_pre_o3d.ply' 
point_cloud = o3d.io.read_point_cloud(ply_file_path)
####
# 根据点云的z值(高度)按数量分布的直方图 参考hovsg
####
points = point_cloud.voxel_down_sample(voxel_size=0.05)
downpcd = np.asarray(points.points)
print("downpcd: ", downpcd.shape)
# divide z axis range into 0.01m bin
reselotion = 0.01
bins = np.abs(np.max(downpcd[:, 2]) - np.min(downpcd[:, 2])) / reselotion
print("bins", bins)
z_hist = np.histogram(downpcd[:, 2], bins=int(bins))
# smooth the histogram
z_hist_smooth = gaussian_filter1d(z_hist[0], sigma=2)
# Find the peaks in this histogram.
distance = 0.2 / reselotion
print("distance", distance)
# set the min peak height based on the histogram
print(np.mean(z_hist_smooth))
min_peak_height = np.percentile(z_hist_smooth, 90)
print("min_peak_height", min_peak_height)
peaks, _ = find_peaks(z_hist_smooth, distance=distance, height=min_peak_height)

# # plot the histogram
plt.figure()
plt.plot(z_hist[1][:-1], z_hist_smooth)
plt.plot(z_hist[1][peaks], z_hist_smooth[peaks], "x")
plt.hlines(
    min_peak_height, np.min(z_hist[1]), np.max(z_hist[1]), colors="r"
)
plt.show()
# cluster the peaks using DBSCAN
peaks_locations = z_hist[1][peaks]
print(peaks_locations)
clustering = DBSCAN(eps=1, min_samples=1).fit(peaks_locations.reshape(-1, 1))
labels = clustering.labels_
print(labels)
clustred_peaks = []
for i in range(len(np.unique(labels))):
    # for first and last cluster, find the top 1 peak
    if i == 0 or i == len(np.unique(labels)) - 1:
        p = peaks[labels == i]
        top_p = p[np.argsort(z_hist_smooth[p])[-1:]].tolist()
        top_p = [z_hist[1][p] for p in top_p]
        clustred_peaks.append(top_p)
        continue
    p = peaks[labels == i]
    top_p = p[np.argsort(z_hist_smooth[p])[-2:]].tolist()
    top_p = [z_hist[1][p] for p in top_p]
    clustred_peaks.append(top_p)
   
clustred_peaks = [item for sublist in clustred_peaks for item in sublist]
clustred_peaks = np.sort(clustred_peaks)
print("clustred_peaks", clustred_peaks)
# # 可视化点云
coordinate_frame = o3d.geometry.TriangleMesh.create_coordinate_frame(size=10, origin=[0, 0, 0])
o3d.visualization.draw_geometries([point_cloud,coordinate_frame], window_name='Point Cloud Visualization')

# # 获取点云的坐标数据（Numpy数组）
points = np.asarray(point_cloud.points)
# # 可视化区域底部的内容：地板和天花板高度：clustred_peaks[0]-0.15和[1]+0.15 
filtered_points = points[ (points[:, 2] >=clustred_peaks[0]-0.15)&(points[:, 2]<= clustred_peaks[1]+0.15)]
filtered_point_cloud = o3d.geometry.PointCloud()
filtered_point_cloud.points = o3d.utility.Vector3dVector(filtered_points)
o3d.visualization.draw_geometries([filtered_point_cloud], window_name='background')
# # 可视化障碍物的区域：clustred_peaks[0]+0.15和clustred_peaks[0]+0.15+机器人高度
filtered_points = points[ (points[:, 2] >=clustred_peaks[0]+0.15)&(points[:, 2]<= clustred_peaks[0]+1.15)]
filtered_point_cloud = o3d.geometry.PointCloud()
filtered_point_cloud.points = o3d.utility.Vector3dVector(filtered_points)
o3d.visualization.draw_geometries([filtered_point_cloud], window_name='avalibale')