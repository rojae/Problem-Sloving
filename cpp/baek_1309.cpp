#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n, MOD = 9901;
    cin >> n;

    int *dp = new int[n+1];

    dp[0]=0;
    dp[1]=3;
    dp[2]=7;

    for(int i=3; i<=n; i++){
        dp[i] = (dp[i-1]*2 % MOD) + (dp[i-2] % MOD);
    }

    cout << dp[n] % MOD;
}