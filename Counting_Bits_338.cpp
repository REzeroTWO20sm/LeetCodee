#include <iostream>
#include <vector>

using namespace std;

int count_bits(int number){
    int buffer=0;
    while(number > 0){
        buffer += number % 2 ;
        number = number / 2 ;
    }
    return buffer;
}

void display_vector(const vector<int>& vector){
    cout << "[";
    for(int i=0;i<vector.size();i++){
        cout << vector[i] ;
        if(i<vector.size()-1){
            cout << ",";
        }
    }cout << "]";
}

int main(){
    vector<int> result {0};

    int number;
    cout << "Введите число: ";
    cin >> number;

    for(int i = 1;i<=number;i++){
        result.push_back(count_bits(i));
    }

    display_vector(result);
    
    return 0;
}
