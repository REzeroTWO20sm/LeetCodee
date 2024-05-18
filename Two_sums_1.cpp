#include "vector"
#include "iostream"

std::vector<int> twoSum(std::vector<int>& nums, int target){
    std::vector<int> mas{};
    for(int i=0;i<nums.size();i++){
        for(int j=1;j<nums.size();j++){
            if(nums[i]+nums[j]==target && i!=j){
                mas.push_back(i);
                mas.push_back(j);
                return mas;
            }
        }
    }
    return mas;
}

int main(){
    //Solution sol1;
    std::vector<int> nums{2,5,5,11};
    int target=10;
    twoSum(nums, target);
}