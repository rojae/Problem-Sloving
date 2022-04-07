/** ==================================================
* @fileName: parkFeeCalculate.cpp
* @author: rojae 
* @date: 2022.04.08
* @description: https://programmers.co.kr/learn/courses/30/lessons/92341
==================================================**/

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <cmath>

using namespace std;

int timeGap(string in, string out){
    int h1 = stoi(in.substr(0, 2));
    int m1 = stoi(in.substr(3, 2));
    int h2 = stoi(out.substr(0, 2));
    int m2 = stoi(out.substr(3, 2));

    int gap = (h2-h1)*60 + (m2-m1);
    
    return gap;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> ans;
    map<string, vector<string>> m;

    stringstream ss;

    for(auto record : records){
        ss.str(record);
        string time, number, status;
        ss >> time >> number >> status;
        
        m[number].push_back(time);
        ss.clear();
    }

    for(auto it : m){
        // 당일 출차를 하지 않았으면, 23:59으로 계산하자
        if(it.second.size() & 1)
            it.second.push_back("23:59");

        vector<string> info = it.second;
        int total = 0;
        for(int i=0; i<info.size()-1; i+=2){
            total += timeGap(info[i], info[i+1]);
        }

        int price = fees[1];
        if(total > fees[0]){
            price += ceil((total - fees[0]) / double(fees[2])) * fees[3];
        }
        ans.push_back(price);
    }

    return ans;
}

int main(){
    vector<int> fees = {180, 5000, 10, 600};
    vector<string> records = {"05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"};
    vector<int> result = solution(fees, records);

    for(auto one : result){
        cout << one << ' ';
    }

    return 0;
}

