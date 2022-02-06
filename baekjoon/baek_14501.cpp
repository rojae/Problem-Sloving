#include<iostream>
#include<cmath>

using namespace std;

int n;
int times[15];
int pay[15];
int ans;

void dfs(int idx, int sum){

    if(idx > n)
        return;

    ans = max(ans, sum);

    for(int i=idx; i<n; i++)
        dfs(i+times[i], sum+pay[i]);
    // dfs(idx + times[idx], sum + pay[idx]);    
}

int main(){
    cin >> n;

    for(int i=0; i<n; i++)
        cin >> times[i] >> pay[i];
    
    dfs(0,0);

    cout << ans;
    return 0;
}