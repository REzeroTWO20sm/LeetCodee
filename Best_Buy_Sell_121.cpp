#include <vector>
#include <iostream>

using namespace std;

// g++ Best_Buy_Sell_121.cpp -o Best_Buy_Sell_121 --std=c++14 -I/usr/local/include

int search(const vector<int>& vector){
    if (vector.empty()) {
            return 0;
        }
    
        int maxProfit = 0;
        int minPrice = vector[0];

        for (int i = 1; i < vector.size(); ++i) {
            minPrice = std::min(minPrice, vector[i]);
            maxProfit = std::max(maxProfit, vector[i] - minPrice);
        }

        return maxProfit;
}

int main(){
    vector<int> nums = {2,4,9,1};
    cout << search(nums);
}