// Created By: Finn Kitor
// Date: December 4th, 2023
// This program rounds a number with any decimal places the user inputs

#include <cmath>
#include <iostream>
#include <stdexcept>

void round_decimal(double& decimalNumber, int numDecimalPlaces) {
    // Multiply the decimal number by 10 raised to the power of the number of decimal places,
    // so that the desired decimal place becomes the unit place.
    double multiplier = std::pow(10, numDecimalPlaces);
    decimalNumber *= multiplier;

    // Round the decimal number to the nearest integer.
    int roundedNumber = static_cast<int>(decimalNumber + 0.5);

    // Divide the rounded number by the multiplier to restore the original decimal number.
    decimalNumber = roundedNumber / multiplier;
}

int main() {
    try {
        double decimalNumber;
        int numDecimalPlaces;

        // Get the decimal number from the user.
        std::cout << "Enter a decimal number: ";
        std::cin >> decimalNumber;

        // Get the number of decimal places to round to from the user.
        std::cout << "Enter the number of decimal places to round to: ";
        std::cin >> numDecimalPlaces;

        // Validate the input.
        if (std::cin.fail()) {
            throw std::invalid_argument("Invalid input. Please enter a valid decimal number and number of decimal places.");
        }

        // Call the round_decimal function to round the decimal number.
        round_decimal(decimalNumber, numDecimalPlaces);

        // Print the rounded number.
        std::cout << "Rounded number: " << decimalNumber << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}