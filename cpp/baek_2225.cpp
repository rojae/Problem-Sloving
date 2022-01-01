#include <iostream>

using namespace std;



int main(){
    int MOD = 1000000000;
    int dp[201][201] = {0, };   // 0부터 N까지의 정수 K개
    int n,k;

    cin >> n >> k;

    for(int i=0; i<=n; i++){
        dp[0][i] = 0;
        dp[1][i] = 1;
    }

    for(int i=2; i<=k; i++){
        for(int j=0; j<=n; j++){
            for(int l=0; l<=j; l++){
                dp[i][j] = (dp[i][j] + dp[i-1][j-l]) % MOD;
            }
        }
    }

    cout << dp[k][n];

    return 0;
}