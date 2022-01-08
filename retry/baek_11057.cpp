#include <iostream>

using namespace std;

int main(){
    int n, ans=0, mod=10007;

    // dp[n][j] = 수의 길이 n, 마지막 숫자 j
    int dp[1001][10] = {0,};

    cin >> n;

    for(int i=0; i<=9; i++)
        dp[1][i] = 1;
    
    for(int i=2; i<=n; i++){
        for(int j=0; j<=9; j++){
            for(int l=0; l<=j; l++){
                // dp[i][j] = Σ dp[i-1][l] 
                // (0 <= l <= j)
                dp[i][j] = (dp[i][j] + dp[i-1][l]) % mod;
            }
        }
            
    }

    for(int i=0; i<=9; i++)
        ans += dp[n][i] % mod;

    cout << ans % mod;
}