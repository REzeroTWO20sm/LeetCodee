#include <string>
#include <iostream>
#include <vector>

//g++ cpp.cpp -o cpp --std=c++14 -I/usr/local/include

using namespace std;

std::string longestCommonPrefix(vector<std::string> &strs) {
    std::string word;
    if (strs.size()<=0) return word;
    for(int i=1; i<=strs[0].size(); i++){
        std::string w = strs[0].substr(0, i);
        bool match = true;
        for(int j=1; j<strs.size(); j++){
            if (i>strs[j].size() || w!=strs[j].substr(0, i) ) {
                match=false;
                break;
            }
        }
        if (!match) {
            return word;
        }
        word = w;
    }
    return word;
}

int main(){
    vector<std::string> vec_str{"asd","asdg","asd"};
    std::cout << longestCommonPrefix(vec_str);
}