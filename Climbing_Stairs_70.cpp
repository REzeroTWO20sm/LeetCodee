#include <iostream>
#include <vector>

// g++ Climbing_Stairs_70.cpp -o Climbing_Stairs_70 --std=c++14 -I/usr/local/include

// int climbStairs(int n) {
//     std::vector<int> steps{};
//     for(int i=0;i<n;i++){
//         steps.push_back(1);
//     }
//     int num = n;
//     int count = 1;
//     while(num>0){
//         if(num-2>0){
//             num-=2;
//             steps.push_back(2);
//         }
//         else if(num-1>0){
//             num-=1;
//             steps.push_back(1);
//         }
//         else if(num==0){
//             count +=1;
//         }
//     }
// }

// int climbStairs(int n) {
//     std::vector<std::vector<int>> steps;
//     steps.push_back({n,1});

//     for(int i)
//     for(int i=0;i<n;i++){
//         steps.push_back({i});
//     }


//     int num = n;
//     int count = 1;


//     while(num>0){
//         if(num-2>0){
//             num-=2;
//             steps.push_back(2);
//         }
//         else if(num-1>0){
//             num-=1;
//             steps.push_back(1);
//         }
//         else if(num==0){
//             count +=1;
//         }
//     }
// }

int climbStairs(int n) {
    if (n <= 2) {
        return n;
    }
    
    int first = 1;
    int second = 2;
    
    for (int i = 3; i <= n; i++) {
        int third = first + second;
        first = second;
        second = third;
    }
    
    return second;
}


int main(){
    int num = 3;
    // std::vector<std::vector<int>> steps;
    // // for(int i=0;i<5;i++){
    // //     steps[0][i]==1;
    // // }
    // //steps[0][0]==1;
    // //steps.push_back({5,1});
    // steps.push_back(std::vector<int>(num,1));

    // for(int i)

    // while(num>=0){

    // }
    // std::cout << "[ ";
    // for(int i=0;i<steps[0].size();i++){
    //     std::cout << steps[0][i] << " , ";
    // }std::cout << " ]";
    std::cout << climbStairs(num);
}