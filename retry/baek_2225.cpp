#include <iostream>

using namespace std;

int main(){
    int n, k;
    int mod = 1e9;

    cin >> n >> k;

    int dp[201][201] = {0,};

    // 1개의 수로 i를 만들기 위한 방법
    for(int i=0; i<=n; i++){ 
        dp[1][i] = 1; 
    }

    // 숫자 k개
    for(int i=2; i<=k; i++){
        // n을 만들기 위함
        for(int j=0; j<=n; j++){
            // 0 <= l <= n
            for(int l=0; l<=j; l++){
                // dp[k][n] = dp[k-1][0] + .... dp[k-1][n]
                dp[i][j] = (dp[i][j] + dp[i-1][j-l]) % mod;
            }
        }
    }

    cout << dp[k][n];

    return 0;
}