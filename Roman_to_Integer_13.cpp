#include <string>
#include <iostream>

// g++ cpp.cpp -o cpp --std=c++14 -I/usr/local/include

int CharToInt(char s_char) {
    int result = 0;
    if(s_char == 'I'){
        result+=1;
        return result;
    }
    else if(s_char == 'V'){
        result+=5;
        return result;
    }
    else if(s_char == 'X'){
        result+=10;
        return result;
    }
    else if(s_char == 'L'){
        result+=50;
        return result;
    }
    else if(s_char == 'C'){
        result+=100;
        return result;
    }
    else if(s_char == 'D'){
        result+=500;
        return result;
    }
    else if(s_char == 'M'){
        result+=1000;
        return result;
    }
    return result;
}

int romanToInt(std::string s) {
    if (s.size()<=0) return 0;
    int result = CharToInt(s[0]);
    for (int i=1; i<s.size(); i++){
        int prev = CharToInt(s[i-1]);
        int curr = CharToInt(s[i]);
        if (prev < curr) {
            result = result - prev + (curr-prev);
        }else{
            result += curr;
        }
    }
    return result;
}




int main(){
    std::string str_1 = "MCMXCIV";
    std::cout << romanToInt(str_1) << std::endl;
}