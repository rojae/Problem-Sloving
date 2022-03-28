/** ==================================================
* @fileName: travelRoute.cpp
* @author: rojae 
* @date: 2022.03.28
* @description: https://programmers.co.kr/learn/courses/30/lessons/43164
==================================================**/
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

int visit[10000] = {0};

vector<string> ans;

bool dfs(string start, vector<vector<string>> tickets, int cnt){
 
   if(cnt == tickets.size())
        return true;
    
    for(int i=0; i<tickets.size(); i++){
        if(visit[i] == 0 && start == tickets[i][0]){
            visit[i] = 1;
            ans.push_back(tickets[i][1]);
            bool result = dfs(tickets[i][1], tickets, cnt+1);

            if(result)
                return true;
            visit[i] = 0;
        }
    }
    ans.pop_back();
    return false;
}


vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    sort(tickets.begin(), tickets.end());
    
    string start = "ICN";
    ans.push_back(start);

    dfs(start, tickets, 0);
       
    return ans;
}

int main(){
    vector<vector<string>> tickets = {{"ICN", "JFK"}, {"HND", "IAD"}, {"JFK", "HND"}};
    vector<string> ans = solution(tickets);
    for(auto a : ans)
        cout << a << ' ';
    return 0;
}