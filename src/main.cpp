// src/main.cpp
#include <iostream>
#include "algos.hpp"

int main() {
    std::string s1 = "abbaca";
    std::cout << "removeDuplicates:" << "\n";
    std::cout << "given string: " << s1 << "\n";
    std::cout << "output string: " << removeDuplicates(s1) << "\n";

    std::string s2 = "ab<c";
    std::cout << "clean_backspace_string:" << "\n";
    std::cout << "given string: " << s2 << "\n";
    std::cout << "output string: " << clean_backspace_string(s2) << "\n";

    return 0;
}

