#!/bin/bash

# Function to calculate the sum of n numbers
calculate_sum() {
    sum=0
    for ((i = 1; i <= $n; i++)); do
        read -p "Enter number $i: " num
        sum=$((sum + num))
    done
    echo "Sum of the numbers is: $sum"
}

# Main program
read -p "Enter the value of n: " n

if [[ $n =~ ^[0-9]+$ && $n -gt 0 ]]; then
    calculate_sum
else
    echo "Invalid input. Please enter a positive integer for n."
fi
