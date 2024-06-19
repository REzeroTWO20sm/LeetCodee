#include <iostream>
#include <vector>

using namespace std;

// g++ cpp.cpp -o cpp --std=c++14 -I/usr/local/include

void sort(vector<int>& vector){
    int buffer=0;
    for(int i = 0;i<vector.size();i++){
        for(int j=0;j<vector.size();j++){
            if(vector[i]<vector[j]){
                buffer = vector[i];
                vector[i] = vector[j];
                vector[j] = buffer;
            }
        }
    }
}

void display_vector(const vector<int>& vector){
    cout << "[";
    for(int i=0;i<vector.size();i++){
        cout << vector[i] ;
        if(i<vector.size()-1){
            cout << ",";
        }
    }std::cout << "]";
}

int search_missing_num(const vector<int>& vector){
    int max = vector.back();
    int sum_right = 0;
    int sum_not_right = 0;
    for(int i=0;i<=max;i++){
        sum_right+=i;
    }
    for(auto& iter : vector){
        sum_not_right+=iter;
    }
    if(vector[0]!=0){
        return 0;
    }
    else if(sum_right-sum_not_right == 0){
        return max+1;
    }
    return sum_right-sum_not_right;
}

int main(){
    vector<int> nums {9,6,4,2,3,5,7,0,1};

    sort(nums); // [0,1,2,3,4,5,6,7,9]

    display_vector(nums); // [0,1,2,3,4,5,6,7,9]

    cout << "  Missing number - " << search_missing_num(nums) << "." << endl; // 8

    return 0;
}
