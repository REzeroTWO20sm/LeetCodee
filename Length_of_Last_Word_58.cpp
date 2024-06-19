#include <iostream>
#include <string>

// g++ Length_of_Last_Word_58.cpp -o Length_of_Last_Word_58 --std=c++14 -I/usr/local/include

// 65 - 90 and 97-122
// (90 >= int_char >= 65) && (122 >= int_char >= 97)
int lengthOfLastWord(std::string s) {
    if (s.empty()) {
        return 0;
    }

    int len = 0;
    bool inWord = false;

    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] != ' ') { 
            len++;
            inWord = true;
        } else {
            if (inWord) {
                break;
            }
        }
    }

    return len;
}

int main(){
    std::string string = "   fly Me   to   the moonoddo  ";
    int int_char = 0;
    // for(int i=string.size();i>=0;i--){
    //     int_char = string[i];
    //     std::cout << int_char << "  ";
    //     if(90 >= int_char >= 65){
    //         std::cout << "HEllO";
    //     }
    // }
    std::cout << std::endl << lengthOfLastWord(string) << std::endl;
}