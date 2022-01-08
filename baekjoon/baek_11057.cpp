#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int dp[1001][10] = {0,};
    int ans = 0;
    int mod = 10007;
    int n;

    cin >> n;

    for(int i=0; i<=9; i++)
        dp[1][i] = 1;

    for(int i=1; i<=n; i++){
        for(int j=0; j<=9; j++){
            for(int l=0; l<=j; l++){
                dp[i][j] += dp[i-1][l] % mod;
            }
        }
    }

    for(int i=0; i<=9; i++)
        ans += dp[n][i] % mod;

    cout << ans % mod;
}