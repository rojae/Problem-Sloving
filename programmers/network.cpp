/** ==================================================
* @fileName: network.cpp
* @author: rojae 
* @date: 2022.03.25
* @description: https://programmers.co.kr/learn/courses/30/lessons/43162
==================================================**/

#include <iostream>
#include <vector>

using namespace std;

bool visit[200] = {false,};
int ans = 0;

int solution(int n, vector<vector<int>> computers);

int main(){
    vector<vector<int>> computers = {{1,1,0}, {1,1,0}, {0,0,1}};
    cout << solution(computers.size(), computers) << '\n';
}

bool dfs(vector<vector<int>> computers, int idx, int n){
    if(idx == n)
        return false;
    else if(!visit[idx]){
        visit[idx] = true;
    }
    
    for(int i=0; i<n; i++){
        if(visit[i] == false && idx != i && computers[idx][i] == 1){
            dfs(computers, i, n);
        }
    }
    return true;
}

int solution(int n, vector<vector<int>> computers) {
    for(int i=0; i<n; i++){
        if(!visit[i] && dfs(computers, i, n))
            ans++;
    }
    
    return ans;
}