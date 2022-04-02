/** ==================================================
* @fileName: moreSpicy.cpp
* @author: rojae 
* @date: 2022.04.02
* @description: https://programmers.co.kr/learn/courses/30/lessons/42626
==================================================**/

#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<long, vector<long>, greater<long>> pq;

    for(int i=0; i<scoville.size(); i++)
        pq.push(scoville[i]);

    long ans = 0;

    while(1){
        long top = pq.top();

        if(pq.top() >= K || pq.size() < 2){
            break;
        }
        else{
            pq.pop();
            long long next = top + (2 * pq.top());
            pq.pop();
            pq.push(next);
            ans++;
        }
    }

    if(pq.top() < K && ans == scoville.size() - 1) // 모든 음식의 스코빌 지수를 K 이상으로 만들 수 없는 경우
        return -1;
    else
        return ans;
}

int main(){
    // Don't use the below code with scanf
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int k = 11;
    vector<int> scoville = {1,2,3};
    cout << solution(scoville, k);
    return 0;
}