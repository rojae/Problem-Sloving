#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int ans = 0;
int solution(vector<int> numbers, int target);

int main(){
    vector<int> numbers = {1,1,1,1,1};
    int target = 3;
    int ans = solution(numbers, target);
    cout << ans;
    return 0;
}

void dfs(vector<int> numbers, int target, int sum, int idx){
    if(idx == numbers.size()){
        if(sum == target){
            ans++;
            return;            
        }
        return;
    }
    else{
        dfs(numbers, target, sum + numbers.at(idx), idx+1);
        dfs(numbers, target, sum - numbers.at(idx), idx+1);
    }
}

int solution(vector<int> numbers, int target){
    dfs(numbers, target, 0, 0);
    return ans;
}

