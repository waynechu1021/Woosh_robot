#!/bin/bash

CONTAINER_NAME="nav_container"
IMAGE_NAME="nav"

if docker ps -a --format '{{.Names}}' | grep -w "$CONTAINER_NAME" > /dev/null; then
    echo "容器 $CONTAINER_NAME 已存在，正在启动..."
    docker start "$CONTAINER_NAME"
else
    echo "容器 $CONTAINER_NAME 不存在，正在创建并启动..."
    docker run --network host -d --name "$CONTAINER_NAME" "$IMAGE_NAME"
fi
