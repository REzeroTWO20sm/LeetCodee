#include <bitset>
#include <iostream>
#include <string>

// g++ Add_Binary_67.cpp -o Add_Binary_67 --std=c++14 -I/usr/local/include



int main(){
    std::string num_one = "11010";
    std::string num_two = "100";

    std::bitset<9999999> binaryNumber_1{};
    std::bitset<9999999> binaryNumber_2{};
    binaryNumber_1 = std::bitset<9999999>(num_one);
    binaryNumber_2 = std::bitset<9999999>(num_two);

    int carry = 0; 
    std::bitset<9999999> sum;
    int maxLength = std::max(num_one.length(), num_two.length()); 

    for (int i = 0; i < maxLength; i++) { 
        int bitSum = 0;
        if (i < num_one.length()) {
            bitSum += binaryNumber_1[i];
        }
        if (i < num_two.length()) {
            bitSum += binaryNumber_2[i];
        }
        bitSum += carry;

        sum[i] = bitSum % 2;
        carry = bitSum / 2;
    }

    if (carry) {
        sum[maxLength] = 1;
    }

    std::string sumString = sum.to_string();
    sumString.erase(0, sumString.find_first_not_of('0'));

    std::cout << "Сумма: " << sumString << std::endl;
}