#include <iostream>

// g++ Add_Digits_258.cpp -o Add_Digits_258 --std=c++14 -I/usr/local/include

using namespace std;

int sum_nums(int num){
    int sum;
    if(num<10){
        return num;
    }
    while(num>0){
        sum+=num%10;
        num /= 10;
    }num = sum;
    
    return sum_nums(num);
}



int main(){
    int num = 38;
    cout << sum_nums(num);
}
