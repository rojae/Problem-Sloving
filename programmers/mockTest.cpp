/*
* ==================================================
* author : rojae
* description : https://programmers.co.kr/learn/courses/30/lessons/42840
* ==================================================
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

vector<int> solution(vector<int> answers);

int student1[] = {1, 2, 3, 4, 5};
int student2[] = {2, 1, 2, 3, 2, 4, 2, 5};
int student3[] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
int cnt[3] = {0,};

int main(){
    vector<int> answers = {1,2,3,4,5};
    vector<int> ans = solution(answers);

    for(auto i : ans)
        cout << i << ' ';

    return 0;
}

vector<int> solution(vector<int> answers) {
    vector<int> ans;
    int m = 0;

    for(int i=0; i<answers.size(); i++){
        if(student1[i % 5] == answers.at(i))
            cnt[0]++;
        if(student2[i % 8] == answers.at(i))
            cnt[1]++;
        if(student3[i % 10] == answers.at(i))
            cnt[2]++;
    }

    m = max(cnt[0], max(cnt[1], cnt[2]));

    for(int i=0; i<3; i++){
        if(cnt[i] == m)
            ans.push_back(i+1);
    }

    return ans;
}