#include <iostream>
#include "degree.h"
#include <string>

1int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
bool inputcheck(std::string& in, std::string arr[]){
    for(int i : arr) {
        if (in == arr[i]) {
            std::cout << "Valid input found!";
            return true;
        }
    }
    std::cout << "No valid input found!" << std::endl;
    return false;
}