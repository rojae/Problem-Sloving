/** ==================================================
* @fileName: kthNumber.cpp
* @author: rojae 
* @date: 2022.03.29
* @description: https://programmers.co.kr/learn/courses/30/lessons/42748
==================================================**/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> ans;

    for(int i=0; i<commands.size(); i++){
        vector<int> v;
        for(int j=commands[i][0]-1; j<commands[i][1]; j++){
            v.push_back(array[j]);
        }
        sort(v.begin(), v.end());
        ans.push_back(v.at(commands[i][2]-1));
    }

    return ans;
}

int main(){
    vector<int> array = {1, 5, 2, 6, 3, 7, 4};
    vector<vector<int>> commands = {{2, 5, 3}, {4, 4, 1}, {1, 7, 3}};
    vector<int> ans = solution(array, commands);

    for(auto one : ans)
        cout << one << ' ';

    return 0;
}