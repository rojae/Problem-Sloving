/** ==================================================
* @fileName: faker.cpp
* @author: rojae 
* @date: 2022.03.29
* @description: https://programmers.co.kr/learn/courses/30/lessons/42578
==================================================**/

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int ans = 1;
    map<string, int> m;

    for(auto one : clothes){
        m[one[1]]++;
    }

    map<string, int>::iterator iter;

    for(iter=m.begin(); iter!=m.end(); iter++){
        ans *= iter->second+1;
    }

    return ans-1;
}

int main(){
    vector<vector<string>> clothes = {{"yellowhat", "headgear"}, {"bluesunglasses", "eyewear"}, {"green_turban", "headgear"}};
    cout << solution(clothes);
    return 0;
}