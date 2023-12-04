#!/bin/bash

# Function to start an infinite loop as a background process
start_infinite_process() {
    while true; do
        echo "Infinite Process is running..."
        sleep 1
    done
}

# Start the first infinite process in the background
start_infinite_process &

# Save the PID (Process ID) of the first background process
pid_1=$!

# Start the second infinite process in the background
start_infinite_process &

# Save the PID of the second background process
pid_2=$!

# Wait for some time (you can adjust this as needed)
sleep 5

# Prematurely terminate the first process
kill $pid_1

echo "Infinite Process 1 terminated prematurely."

# Prematurely terminate the second process
kill $pid_2

echo "Infinite Process 2 terminated prematurely."
