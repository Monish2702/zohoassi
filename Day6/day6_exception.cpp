#include <iostream>
#include <string>
#include <exception>

int main() {
    int numerator , denominator;
    std::cout << "Enter numerator: ";
    std::cin >> numerator;
    std::cout << "\nEnter denominator: ";
    std::cin >> denominator;

    //exception handling when divided by zero
    try {
        if (denominator == 0) {
            throw std::runtime_error("\nDenominator cannot be zero");
        }
        else {
            std::cout << numerator / denominator << std::endl;
        }
    }
    catch (std::runtime_error &e) {
        std::cout << e.what() << std::endl;
    }
    //exception handling when string is accessed out of bounds
    try {
        std::string s = "Hello";
        std::cout << s[10] << std::endl;
        throw s;
    }
    catch (std::string s) {
        std::cout <<"Out of bound: "<< s << std::endl;
    }
}