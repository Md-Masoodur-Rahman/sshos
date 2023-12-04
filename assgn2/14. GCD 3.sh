#!/bin/bash

my_function() {
    local local_variable="I am local"
    echo "Inside function: $local_variable"
}

# Call the function
my_function

# Try to access the local variable outside the function (will result in an error)
echo "Outside function: $local_variable"
