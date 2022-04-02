/** ==================================================
* @fileName: bridgeOfTuck.cpp
* @author: rojae 
* @date: 2022.03.27
* @description: 
==================================================**/

#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int ans = 0;
int currentWeight = 0;

int solution(int bridge_length, int weight, vector<int> truck_weights);

int main(){
    vector<int> truckWeights = {7,4,5,6};
    cout << solution(2, 10, truckWeights);
    return 0;
}

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int ans = 0;
    int idx = 0;
    int sum = 0;

    // 다리를 지나고 있는 트럭들
    queue<int> q;

    while(1){
        if(idx == truck_weights.size()){
            ans += bridge_length;
            break;
        }
        int tmp = truck_weights[idx];
        ans++;
        if(q.size() == bridge_length){
            sum -= q.front();
            q.pop();
        }
        if(tmp + sum <= weight){
            sum += tmp;
            q.push(tmp);
            idx++;
        }
        else{
            q.push(0);
        }
    }
    return ans;
}