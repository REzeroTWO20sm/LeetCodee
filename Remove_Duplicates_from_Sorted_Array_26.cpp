#include <vector>
#include <iostream>

// g++ Remove_Duplicates_from_Sorted_Array_26.cpp -o Remove_Duplicates_from_Sorted_Array_26 --std=c++14 -I/usr/local/include

int removeDuplicates(std::vector<int>& nums) {
    std::vector<int> result{0};
    
    if(nums[0]){
        // return true;
        result[0]=nums[0];
    }

    int i=0;
    int j=0;
    while(i<nums.size()){
        if(nums[i]!=result[j]){
            result.push_back(nums[i]);
            j++;
        }
        i++;
    }

    std::cout << result.size() << " - COUNT OF ORIGINAL NUMS" << std::endl;

    for(int i=0;i<result.size();i++){
        std::cout << result[i] << ","; 
    }std::cout << std::endl;

    return result.size();
}

int main(){
    std::vector<int> nums{1,1,2};//0,0,1,1,1,2,2,3,3,4
    for(int i=0;i<nums.size();i++){
        std::cout << nums[i] << ","; 
    }std::cout << " - OUR START MASSIVE" << std::endl;

    std::cout << removeDuplicates(nums) << std::endl;

    
}