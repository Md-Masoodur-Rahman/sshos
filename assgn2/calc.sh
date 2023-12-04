#!/bin/bash

while true; do
    echo "Simple Calculator Menu"
    echo "1. Addition"
    echo "2. Subtraction"
    echo "3. Multiplication"
    echo "4. Division"
    echo "5. Exit"
    
    read -p "Enter your choice (1-5): " choice

    case $choice in
        1)
            read -p "Enter first number: " num1
            read -p "Enter second number: " num2
            result=$((num1 + num2))
            echo "Result: $result"
            ;;
        2)
            read -p "Enter first number: " num1
            read -p "Enter second number: " num2
            result=$((num1 - num2))
            echo "Result: $result"
            ;;
        3)
            read -p "Enter first number: " num1
            read -p "Enter second number: " num2
            result=$((num1 * num2))
            echo "Result: $result"
            ;;
        4)
            read -p "Enter dividend: " dividend
            read -p "Enter divisor: " divisor
            if [ $divisor -eq 0 ]; then
                echo "Error: Division by zero is not allowed."
            else
                result=$(echo "scale=2; $dividend / $divisor" | bc)
                echo "Result: $result"
            fi
            ;;
        5)
            echo "Exiting the calculator. Goodbye!"
            exit 0
            ;;
        *)
            echo "Invalid choice. Please enter a number between 1 and 5."
            ;;
    esac

    echo # Blank line for better readability
done
