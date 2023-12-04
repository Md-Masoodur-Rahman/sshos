#!/bin/bash

# Function to perform Bubble Sort on an array
bubble_sort() {
    local array=("$@")
    local n=${#array[@]}
    local swapped

    for ((i = 0; i < n-1; i++)); do
        swapped=false
        for ((j = 0; j < n-i-1; j++)); do
            if ((array[j] > array[j+1])); then
                # Swap elements
                temp=${array[j]}
                array[j]=${array[j+1]}
                array[j+1]=$temp
                swapped=true
            fi
        done

        # If no two elements were swapped in inner loop, array is sorted
        if [ "$swapped" = false ]; then
            break
        fi
    done

    # Print the sorted array
    printf "%s\n" "${array[@]}"
}

# Example usage
numbers=(64 34 25 12 22 11 90)
sorted_array=$(bubble_sort "${numbers[@]}")

echo "Sorted Array:"
echo "$sorted_array"
