/** ==================================================
* @fileName: workoutClothes.cpp
* @author: rojae 
* @date: 2022.03.28
* @description: https://programmers.co.kr/learn/courses/30/lessons/42862
==================================================**/
#include <iostream>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> stu(n+2,0);     // n번쨰 학생 뒤에 학생, 1번째 학생 앞의 학생
    
    for(int i:lost){
        stu[i]--;
    }
    for(int i:reserve){
        stu[i]++;
    }
    
    for(int i=1; i<=n; i++){
        if(stu[i]<0){
            if(stu[i-1]==1){
                stu[i]++;
                stu[i-1]--;
            }
            else if(stu[i+1]==1){
                stu[i]++;
                stu[i+1]--;
            } 
        }
    }
    
    for(int i=1; i<=n; i++){
        if(stu[i]>=0)
            answer++;
    }
    
    return answer;
}

int main(){
    vector<int> lost = {3};
    vector<int> reserve = {1};

    sort(lost.begin(), lost.end(), greater<int>());
    sort(reserve.begin(), reserve.end(), greater<int>());

    cout << solution(3, lost, reserve);

    return 0;
}