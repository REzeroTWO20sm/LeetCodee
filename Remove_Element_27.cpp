#include <vector>
#include <iostream>

// g++ Remove_Element_27.cpp -o Remove_Element_27 --std=c++14 -I/usr/local/include

void removeElement(std::vector<int>& nums, int val) {
    std::vector<int> result{};

    // if(!nums[0]){
    //     return 0;
    // }

    int cout = 0;
    for(int i = 0;i<nums.size();i++){
        if(nums[i]!=val){
            result.push_back(nums[i]);
        }
        else{
            cout++;
        }
    }

    for(int i=0;i<result.size();i++){
        std::cout << result[i] << ","; 
    }std::cout << std::endl;

    std::cout << result.size() << std::endl;

    for(int i = 0;i<result.size();i++){
        nums[i] = result[i];
    }

    for(int i = nums.size();i>result.size();i--){
        nums[i] = 0;
    }

    for(int i=0;i<nums.size();i++){
        std::cout << nums[i] << ","; 
    }std::cout << std::endl;
}

int main(){
    std::vector<int> nums{0,1,2,2,3,0,4,2};
    int val = 2;

    removeElement(nums,val);
}