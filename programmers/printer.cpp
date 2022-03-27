/** ==================================================
* @fileName: printer.cpp
* @author: rojae 
* @date: 2022.03.27
* @description: https://programmers.co.kr/learn/courses/30/lessons/42587
==================================================**/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int solution(vector<int> priorities, int location) {
    int ans = 0;
    priority_queue<int> pq;
    queue<pair<int, int>> q;

    for(int i=0; i<priorities.size(); i++){
        pq.push(priorities[i]);
        q.push(pair<int, int>(i, priorities.at(i)));
    }

    while(!q.empty()){
        int idx = q.front().first;
        int front = q.front().second;
        
        if(pq.top() == front){
            ans++;
            pq.pop();            
            if(idx == location)
                break;
        }
        else{
            q.push(pair<int,int> (idx, front));
        }
        q.pop();
    }
    
    return ans;
}

int main(){
    // vector<int> priorites = {2, 1, 3, 2};
    // int location = 2;

    vector<int> priorites = {1, 1, 9, 1, 1, 1};
    int location = 0;
    
    cout << solution(priorites, location);
    return 0;
}
