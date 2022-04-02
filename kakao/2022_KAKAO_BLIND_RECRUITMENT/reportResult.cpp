/** ==================================================
* @fileName: reportResult.cpp
* @author: rojae 
* @date: 2022.04.02
* @description: https://programmers.co.kr/learn/courses/30/lessons/92334
==================================================**/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    map<string, int> idToNumber;
    vector<vector<int>> reportVector(id_list.size());
    vector<int> ans(id_list.size());

    for(int i=0; i<id_list.size(); i++){
        idToNumber[id_list[i]] = i;
    }

    for(int i=0; i<report.size(); i++){
        istringstream ss(report[i]);
        string reporter, reportee;
        ss >> reporter >> reportee;
        int reporterId = idToNumber[reporter];
        int reporteeId = idToNumber[reportee];

        // 중복 신고인지 체크
        if(find(reportVector[reporteeId].begin(), reportVector[reporteeId].end(), reporterId) == reportVector[reporteeId].end())
            reportVector[reporteeId].push_back(reporterId);
    }
    
    for(int i=0; i<reportVector.size(); i++){
        if(reportVector[i].size() >= k){
            for(int j=0; j<reportVector[i].size(); j++){
                ans[reportVector[i][j]]++;
            }
        }
    }

    return ans;
}

int main(){
    vector<string> id_list = {"con", "ryan"};
    vector<string> report = {"ryan con", "ryan con", "ryan con", "ryan con"};
    int k = 3;

    vector<int> res = solution(id_list, report, k);

    for(int one : res){
        cout << one << ' ';
    }

    return 0;
}