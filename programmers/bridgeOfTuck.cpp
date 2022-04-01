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
    int sum = 0;
    int idx = 0;
    queue<int> q;
  
    while(1){
        if(idx == truck_weights.size()){
            ans += bridge_length;
            break;
        }
        else{
            ans++;
            int tmp = truck_weights[idx];

            //차가 다리를 다 건넜을 경우 (다리에 트럭들이 꽉 찬 경우)
            if(q.size() == bridge_length){
                sum -= q.front();  //다 건넜으니 현재 다리에 있는 차들의 무게에서 제외
                q.pop();  
            }
            
            //다리에 다음 차가 진입할 수 있다면
            if(sum + tmp <= weight){
                sum += tmp;           //차량 무게 추가
                q.push(tmp);  
                idx++;                //다음 차량을 위해서
            }
            //진입할 수 없다면 0을 푸시해서 시간초 계산
            else{   
                q.push(0);            
            }
        }
    }
    
    return ans;
}