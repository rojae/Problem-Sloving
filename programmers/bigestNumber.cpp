/** ==================================================
* @fileName: bigestNumber.cpp
* @author: rojae 
* @date: 2022.04.02
* @description: https://programmers.co.kr/learn/courses/30/lessons/42746
==================================================**/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool compare(string a, string b){
    return a+b > b+a;
}

string solution(vector<int> numbers) {
    string ans = "";
    vector<string> stringNumbers;

    for(int i=0; i<numbers.size(); i++){
        stringNumbers.push_back(to_string(numbers[i]));
    }

    sort(stringNumbers.begin(), stringNumbers.end(), compare);

    for(int i=0; i<stringNumbers.size(); i++){
        ans += stringNumbers[i];
    }

    if(stringNumbers[0] == "0")
        ans = "0";
    return ans;
}

int main(){
    vector<int> numbers = {0, 0};
    cout << solution(numbers);    
    return 0;
}
