#include <string>
#include <regex>
#include <iostream>

// g++ Valid_Number_65.cpp -o Valid_Number_65 --std=c++14 -I/usr/local/include

bool isNumber(std::string s) {
    std::regex pattern(R"(^[-+]?(?:\d+(?:\.\d*)?|\.\d+)(?:[eE][-+]?\d+)?$)"); 
    if (regex_match(s, pattern)) {
        std::cout << "true";
        return true;
    } else {
        std::cout << "false";
        return false;
    }
}

int main(){
    std::regex pattern(R"(^[-+]?(?:\d+(?:\.\d*)?|\.\d+)(?:[eE][-+]?\d+)?$)"); 
    std::string string = "123";
    isNumber(string);
}