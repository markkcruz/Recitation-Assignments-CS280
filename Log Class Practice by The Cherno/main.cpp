//
// Created by Jinrain on 4/27/2021.
//
#include <iostream>

void Function(){
    static int i = 0; // first time it will create it to 0, on subsequent calls, it will refer to that variable 1, 2, 3, 4, 5Z
    i++;
    std::cout << i << std::endl;
}

int main() {
    std::cin.get();
}