#include <string>
#include <iostream>

// g++ Find_the_Index_of_the_First_Occurrence_in_a_String_28.cpp -o Find_the_Index_of_the_First_Occurrence_in_a_String_28 --std=c++14 -I/usr/local/include

int strStr(std::string haystack, std::string needle) {
    return haystack.find(needle);
}

int main(){
    std::string string = "sadbutsad";
    std::string find_these = "sad";
    std::cout << strStr(string,find_these) << std::endl;
}