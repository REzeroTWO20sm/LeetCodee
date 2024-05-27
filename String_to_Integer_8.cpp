#include <string>
#include <iostream>
#include <set>


// g++ String_to_Integer_8.cpp -o String_to_Integer_8 --std=c++14 -I/usr/local/include

int myAtoi(std::string s) {
    int buffer;
    int result = 0;
    int factor = 1;// -042
    std::string good_str = "";
    for(int i=0;i<s.length();i++){
        buffer = s[i];
        if((s[i] >= '0' && s[i] <= '9') || (s[i] == '-')){
            good_str+=s[i];
            std::cout << std::endl << good_str << std::endl;
        }
        else if(s[i] == ' '){
            continue;
        }
        else{
            break;
        }
        
    }
    
    for(int i=good_str.length()-1;i>=0;i--){
        buffer = good_str[i];
        if(buffer == 49){
            result+=1*factor;
            factor*=10;
        }
        else if(buffer == 50){
            result+=2*factor;
            factor*=10;
        }
        else if(buffer == 51){
            result+=3*factor;
            factor*=10;
        }
        else if(buffer == 52){
            result+=4*factor;
            factor*=10;
        }
        else if(buffer == 53){
            result+=5*factor;
            factor*=10;
        }
        else if(buffer == 54){
            result+=6*factor;
            factor*=10;
        }
        else if(buffer == 55){
            result+=7*factor;
            factor*=10;
        }
        else if(buffer == 56){
            result+=8*factor;
            factor*=10;
        }
        else if(buffer == 57){
            result+=9*factor;
            factor*=10;
        }
        else if(buffer == 48){
            result+=0*factor;
            factor*=10;
        }
        else if(good_str[i] == '-' && i>0){
            return 0;
        }
    }
    if(good_str[0] == '-'){
        result*=-1;
    }
    return result;
}




int main(){
    std::cout << myAtoi("1338f0f0");
}