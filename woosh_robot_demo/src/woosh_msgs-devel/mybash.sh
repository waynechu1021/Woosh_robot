import os
import re

# 指定包含 .msg 文件的目录
directory = "/home/llf/ros2_start_test/src/woosh_msgs-devel/nav_srvs"

# 正则表达式用于检测变量或常量定义
constant_pattern = re.compile(r"^(\w+)\s+(\w+)\s*=\s*(.+)$")  # 匹配常量：类型 名称 = 值
field_pattern = re.compile(r"^(\w+)\s+(\w+)$")  # 匹配普通字段：类型 名称

# 转换名称为全大写蛇形命名（用于常量）
def to_upper_snake_case(name):
    return re.sub(r'([a-z])([A-Z])', r'\1_\2', name).replace("__", "_").upper()

# 转换名称为全小写蛇形命名（用于变量）
def to_lower_snake_case(name):
    name = re.sub(r'([a-z])([A-Z])', r'\1_\2', name).replace("__", "_")
    return name.lower()

def process_msg_file(file_path):
    with open(file_path, "r") as file:
        lines = file.readlines()

    updated_lines = []
    for line in lines:
        constant_match = constant_pattern.match(line.strip())
        field_match = field_pattern.match(line.strip())

        # 如果是常量定义
        if constant_match:
            field_type, name, value = constant_match.groups()
            new_name = to_upper_snake_case(name)  # 转换为全大写蛇形命名
            updated_lines.append(f"{field_type} {new_name} = {value}\n")
        
        # 如果是变量定义
        elif field_match:
            field_type, name = field_match.groups()
            new_name = to_lower_snake_case(name)  # 转换为全小写蛇形命名
            updated_lines.append(f"{field_type} {new_name}\n")
        
        else:
            # 保持其他行原样
            updated_lines.append(line)

    # 将修改后的内容写回文件
    with open(file_path, "w") as file:
        file.writelines(updated_lines)
    print(f"Processed {file_path}")

# 遍历目录并处理所有 .msg 文件
for root, _, files in os.walk(directory):
    for file in files:
        if file.endswith(".msg"):
            process_msg_file(os.path.join(root, file))

