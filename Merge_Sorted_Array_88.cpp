#include <iostream>
#include <vector>

//g++ Merge_Sorted_Array_88.cpp -o Merge_Sorted_Array_88 --std=c++14 -I/usr/local/include

void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
    int i = m - 1; 
    int j = n - 1; 
    int k = m + n - 1; 
    
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];
            i--;
        } else {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }
    
    while (j >= 0) {
        nums1[k] = nums2[j];
        j--;
        k--;
    }
}

int main(){
    std::vector<int> nums1{2,4,6,8,10,0,0,0};//{1}//{1,2,3,0,0,0}
    std::vector<int> nums2{1,3,5};//{}//{2,5,6}

    int m = 5;
    int n = 3;

    merge(nums1, m, nums2, n);

    std::cout << "[";
    for(auto it : nums1){
        std::cout << it << " , ";
    }std::cout << "]";
}