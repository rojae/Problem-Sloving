/** ==================================================
* @fileName: joyStick.cpp
* @author: rojae 
* @date: 2022.03.28
* @description: https://programmers.co.kr/learn/courses/30/lessons/42860
==================================================**/

#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

int solution(string name) {
    int ans = 0;
    int shift = name.length() - 1; //커서를 좌 또는 우 한 쪽 방향만으로 이동했을 때

    for(int i=0; i<name.size(); i++){
        if(name[i] != 'A')
            notSameIdx.push_back(i);
        ans += min(name[i] - 'A', 'Z' - name[i] + 1);
    }

    for(int i = 0; i < name.length(); i++)
    {
        if(name[i] == 'A')
        {
            int target = i;
            while(target < name.length() && name[target] == 'A') 
            	target += 1; //A로만 이루어진 문자열 찾기
            int left = i == 0 ? 0 : i - 1; //찾은 문자열 왼쪽에서의 이동횟수
            int right = name.length() - target;  //찾은 문자열 오른쪽에서의 이동횟수
            shift = min(shift, left + right + min(left, right)); //가장 작은값 찾기
        }
    }

    return ans + shift;
}

int main(){
    cout << solution("BBAAAAAABBBAAAAAABB");
    return 0;
}