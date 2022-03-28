/** ==================================================
* @fileName: makeBigNum.cpp
* @author: rojae 
* @date: 2022.03.29
* @description: https://programmers.co.kr/learn/courses/30/lessons/42883
==================================================**/
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string solution(string number, int k) {
    string ans;

    int needCnt = number.size() - k;
    int idx = -1;

    for(int i=0; i<needCnt; i++){
        char m = '0';
        for(int j=idx+1; j<=i+k; j++){
            if(m < number[j]){
                m = number[j];
                idx = j;
            }
        }
        ans += m;
    }

    return ans;
}

int main(){
    cout << solution("4177252841", 4);
    return 0;
}