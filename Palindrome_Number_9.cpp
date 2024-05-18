#include <vector>
#include <iostream>

//g++ Palindrome_Number_9.cpp -o Palindrome_Number_9 --std=c++14 -I/usr/local/include

bool isPalindrome(int x) {
    if(x<0){
        return false;
    }
    long long result = 0;
    long long buffer = x;
    for(long long i=1;buffer!=0;i*=10){
        result += (buffer%10)*i;
        buffer /= 10;
    }
    long long reversed = 0;
    
    while (result != 0) {
        long long digit = result % 10;
        reversed = reversed * 10 + digit;
        result /= 10;
    }
    if(x==reversed){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    int x = 0;
    std::cin >> x;
    std::cout << std::endl << isPalindrome(x);

}