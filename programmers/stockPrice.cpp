/** ==================================================
* @fileName: stockPrice.cpp
* @author: rojae 
* @date: 2022.03.27
* @description: https://programmers.co.kr/learn/courses/30/lessons/42584
==================================================**/

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> ans;
    stack<int> st;

    for(int i=0; i<prices.size(); i++)
        ans.push_back(0);

    for(int i=0; i<prices.size()-1; i++){
        int cost = prices.at(i);
        
        if(st.empty()){
            st.push(i);
        }
        else{
            while(!st.empty()){
                int idx = st.top();
                int c = prices.at(idx);
                if(c > cost){
                    st.pop();
                }
                else{
                    break;
                }
            }
            st.push(i);
        }

        stack<int> tmp;
        tmp = st;

        while(!tmp.empty()){
            ans[tmp.top()]++;
            tmp.pop();
        }
    }

    return ans;
}

int main(){
    vector<int> price = {1, 2, 3, 2, 3};
    vector<int> ans = solution(price);

    for(auto i : ans)
        cout << i << ' ';
    return 0;
}