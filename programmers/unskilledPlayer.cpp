/*
* ==================================================
* author : rojae
* description : https://programmers.co.kr/learn/courses/30/lessons/42576
* ==================================================
*/

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string solution(vector<string> participant, vector<string> completion);

int main(){
    vector<string> part = {"mislav", "stanko", "mislav", "ana"};
    vector<string> comp = {"stanko", "ana", "mislav"};

    string ans = solution(part, comp);
    cout << ans;

    return 0;
}

string solution(vector<string> participant, vector<string> completion) {
    map<string, int> map;
    string ans;

    for(int i=0; i<participant.size(); i++){
       if(map.find(participant[i]) != map.end())
            map[participant[i]]++;
        else
            map.insert(pair<string, int> (participant[i], 1));
    }

    for(int i=0; i<completion.size(); i++){
        map[completion[i]]--;
    }

    for(pair<string, int> i : map){
        if(i.second != 0)
            ans = i.first;
    }

    return ans;
}