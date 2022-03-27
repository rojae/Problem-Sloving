/** ==================================================
* @fileName: functionDev.cpp
* @author: rojae 
* @date: 2022.03.27
* @description: https://programmers.co.kr/learn/courses/30/lessons/42586
==================================================**/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

queue<int> days;
vector<int> ans;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    for(int i=0; i<progresses.size(); i++){
        int cost = (100 - progresses.at(i));
        int mod = (cost % speeds.at(i) > 0)? 1 : 0;
        cost = (cost / speeds.at(i)) + mod;

        if(days.empty()){
            days.push(cost);
        }
        else{
            if(days.front() >= cost){
                days.push(cost);
            }
            else{
                ans.push_back(days.size());
                while(!days.empty())
                    days.pop();
                days.push(cost);
            }
        }
    }

    if(!days.empty())
        ans.push_back(days.size());

    return ans;
}

int main(){
    vector<int> progresses = {5, 5, 5};
    vector<int> speeds = {21, 25, 20};
    vector<int> ans = solution(progresses, speeds);

    for(auto i : ans)
        cout << i << ' ';
    return 0;
}

