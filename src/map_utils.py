import numpy as np
import pyrealsense2 as rs
import cv2, io, requests, json, logging, math
from scipy.spatial import cKDTree

def world_to_pixel(world_coords, map_image, origin, resolution):
    x, y = world_coords
    x = np.asarray(x)
    y = np.asarray(y)
    pixel_x = ((x - origin[0]) / resolution).astype(int)
    pixel_y = map_image.shape[0] - ((y - origin[1]) / resolution).astype(int) # the Coordinate system of cv2 located in the left top
    return pixel_x, pixel_y

def pixel_to_world(pixel_coords, map_image, origin, resolution):
    px, py = pixel_coords
    world_x = px * resolution + origin[0]
    world_y = (map_image.shape[0] - py)* resolution + origin[1]
    return world_x, world_y

def find_nearest_feasible_point(pixel_coords, free_points):
    # free_points = np.argwhere(map_image > 220)  # get all the feasible area
    tree = cKDTree(free_points)
    distance, index = tree.query(pixel_coords, k = 1,distance_upper_bound=400)  # find the nearest feasible point
    nearest_pixel = free_points[index]
    return (nearest_pixel[1], nearest_pixel[0])

def theta2Quaternion(x,y,theta):
    z = math.sin(theta / 2)
    w = math.cos(theta / 2)
    return x, y, z, w 

def calculate_theta(x1, y1, x2, y2): #x2 -> x1
    dx = x1 - x2  #
    dy = y1 - y2  
    theta = math.atan2(dy, dx)  # calculate angle
    return theta

def is_point_feasible(world_coords, map_image, origin, resolution, window_size, free_points):
    # convert to pixel coordinate
    pixel_coords = world_to_pixel(world_coords, map_image, origin, resolution)
    px, py = pixel_coords

    if 0 <= px < map_image.shape[1] and 0 <= py < map_image.shape[0]:
        # if map_image[py, px] > 220:
        if np.all(map_image[py-window_size:py+window_size, px-window_size:px+window_size] > 220):
            return True, world_coords
        else:
            # find the nearest feasible pixel
            nearest_pixel = find_nearest_feasible_point((py, px), free_points)
            nearest_world = pixel_to_world(nearest_pixel, map_image, origin, resolution)
            return False, nearest_world
    else:
        logging.error("Input point is outside the map range!")
        raise ValueError("Input point is outside the map range!")


def convert_text2cordinate(query_text, system_prompt, map_image, origin, resolution, window_size, free_points):
    try:
        result_from_gpt = requests.post("http://172.18.35.200:8000/uploads/llm_queries", json={"instruction": system_prompt, "prompt": query_text} )
        result_from_gpt = result_from_gpt.json()['read_message']
        result_from_gpt = result_from_gpt.replace('```json\n','')
        result_from_gpt = result_from_gpt.replace('```','')
        result_from_gpt = json.loads(result_from_gpt)
        logging.info(f'location: {result_from_gpt}')

        if not isinstance(result_from_gpt,list):
            return None, None, None
        if len(result_from_gpt) == 0:
            return None, None, None
        x,y,theta = result_from_gpt[0]["中心坐标"]
        input_coords = [x, y]
        feasible, result_coords = is_point_feasible(input_coords, map_image, origin, resolution, window_size, free_points)
        if feasible:
            logging.info(f"The input points {input_coords} are inside the feasible region.")
        else:
            new_x, new_y = result_coords
            theta = calculate_theta(x, y, new_x, new_y) #new -> old
            logging.info(f"The input points {input_coords} are NOT inside the feasible region, The nearest feasible point is {new_x, new_y}.")
            x, y = new_x, new_y
        return x, y, theta
    except requests.RequestException as e:
        logging.error(f"Error during request: {e}")
        return None, None, None
    except json.JSONDecodeError as e:
        logging.error(f"Error decoding JSON response: {e}")
        return None, None, None

def convert_image2pose(use_depth = False):
    serial_number = "152222070646" # head in the robot
    pipeline = rs.pipeline()
    config = rs.config()
    config.enable_device(serial_number)

    # color streaming, with resolution of 848x480 at fps = 30
    config.enable_stream(rs.stream.color, 848, 480, rs.format.bgr8, 30)
    # config.enable_stream(rs.stream.depth, 848, 480, rs.format.z16, 30)

    pipeline.start(config)
    frames = pipeline.wait_for_frames()

    color_frame = frames.get_color_frame()

    color_image = np.asanyarray(color_frame.get_data())
    _, color_encoded = cv2.imencode('.jpg', color_image)
    color_bytes = io.BytesIO(color_encoded.tobytes())

    files = {
        "image": ("color.jpg", color_bytes, "image/jpeg")
    }

    if use_depth:
        depth_frame = frames.get_depth_frame()
        depth_image = np.asanyarray(depth_frame.get_data()).to(np.float32) / 1000.0
        depth_buf = io.BytesIO()
        np.save(depth_buf, depth_image)
        depth_buf.seek(0)
        files["depth_image"] = ("depth_file.npy", depth_buf, "application/octet-stream")

    pipeline.stop()
    # result = requests.post("http://172.18.35.200:8000/uploads/llm_queries", json={"color_image": color_image, "depth_image": depth_image})
    result = requests.post("http://10.16.242.37:5000/localize",files=files)
    result = result.json()
    x, y, theta = result['x'], result['y'], result['theta']
    return x, y, theta

