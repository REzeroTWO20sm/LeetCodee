#include <vector>
#include <iostream>

// g++ Plus_One_66.cpp -o Plus_One_66 --std=c++14 -I/usr/local/include

std::vector<int> plusOne(std::vector<int>& digits) {
    int carry = 1;
    for (int i = digits.size() - 1; i >= 0; i--) {
        int sum = digits[i] + carry;
        carry = sum / 10;
        digits[i] = sum % 10;
    }
    if (carry > 0) {
        digits.insert(digits.begin(), carry);
    }

    return digits; 
}

int main(){
    std::vector<int> digits{1,2,3};

    std::cout << "[ ";
    for(auto num : plusOne(digits)){
        std::cout << num << " ";
    }std::cout << "]";
}