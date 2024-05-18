#include <iostream>

// g++ SqrtX_69.cpp -o SqrtX_69 --std=c++14 -I/usr/local/include

double binarySearchSqrt(double num, double precision) {
    double low = 0.0;
    double high = num;
    double mid = (low + high) / 2.0;

    while (std::abs(mid * mid - num) > precision) {
        if(high * high == num){
            return high;
        }
        else if(low*low == num){
            return low;
        }
        else if (mid * mid > num) {
            high = mid;
        }
        else {
            low = mid;
        }
        mid = (low + high) / 2.0;
    }
    int result = mid;
    return result;
}

int main() {
    double num = 16.0;
    double precision = 0.01;

    double sqrtResult = binarySearchSqrt(num, precision);
    std::cout << "Квадратный корень числа " << num << " = " << sqrtResult << std::endl;

    return 0;
}
