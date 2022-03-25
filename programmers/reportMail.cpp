/** ==================================================
* @fileName: reportMail.cpp
* @author: rojae 
* @date: 2022.03.26
* @description: https://programmers.co.kr/learn/courses/30/lessons/92334
==================================================**/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int ans[1001];
vector<vector<int>> reported(1001);

vector<int> solution(vector<string> id_list, vector<string> report, int k);

int main(){
    vector<string> id_list = {"con", "ryan"};
    vector<string> report = {"ryan con", "ryan con", "ryan con", "ryan con"};
    int k = 3;

    vector<int> ans = solution(id_list, report, k);
    
    for(int i : ans)
        std::cout << i << '\n';
    
    return 0;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    map<string, int> id_to_num;
    vector<int> answer;
    for (int i = 0; i < id_list.size(); i++) {
        id_to_num[id_list[i]] = i;
    }
    for (int i = 0; i < report.size(); i++) {
        istringstream ss(report[i]);
        string stringBuffer;
        string str1, str2;
        ss >> str1 >> str2;
        int a = id_to_num.find(str1)->second;
        int b = id_to_num.find(str2)->second;
        reported[b].push_back(a);
    }
    for (int i = 0; i < id_list.size(); i++) {
        sort(reported[i].begin(), reported[i].end());
        reported[i].erase(unique(reported[i].begin(), reported[i].end()), reported[i].end());
    }
    for (int i = 0; i < id_list.size(); i++) {
        if (reported[i].size() >= k) {
            for (int j = 0; j < reported[i].size(); j++) {
                ans[reported[i][j]]++;
            }
        }
    }
    for (int i = 0;i < id_list.size(); i++) {
        answer.push_back(ans[i]);
    }
    return answer;
}