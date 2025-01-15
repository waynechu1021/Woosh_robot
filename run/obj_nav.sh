#!/bin/bash

# Define variables
QUERY_URL="http://10.16.2.104:12345/hovsg_query"
QUERY_TEXT="find the elevator"

# Send query request
RESPONSE=$(curl -s -X POST "$QUERY_URL" \
    -H "Content-Type: application/json" \
    -d "{\"query\": \"$QUERY_TEXT\"}")

# Extract pose information
X=$(echo $RESPONSE | jq -r '.center[0]')
Y=$(echo $RESPONSE | jq -r '.center[1]')
THETA=$(echo $RESPONSE | jq -r '.center[2]')

# Check if pose information is valid
if [[ "$X" == "null" || "$Y" == "null" || "$THETA" == "null" ]]; then
    echo "Failed to retrieve valid pose from response: $RESPONSE"
    exit 1
fi

# Print navigation command
NAV_COMMAND="ros2 run woosh_robot_demo movebase_goal --ros-args -p t_x:=$X -p t_y:=$Y -p t_theta:=$THETA"
echo "Executing navigation command: $NAV_COMMAND"

# Execute navigation command
$NAV_COMMAND