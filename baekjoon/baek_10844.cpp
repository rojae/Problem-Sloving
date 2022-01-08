#include <iostream>

using namespace std;

int main(){
    int MOD = 1e9;
    int n;
    long long ans = 0;
    cin >> n;

    // dp[n][m]. n의 길이를 가지는 마지막이 m으로 끝나는 수
    long long dp[101][10] = {0};

    for(int i=1; i<=9; i++)
        dp[1][i] = 1;

    for(int i=2; i<=100; i++){
        for(int j=0; j<=9; j++){
            // 9로 끝나는 수 
            // {8,9} = 
            if(j==9){
                dp[i][j] = dp[i-1][8] % MOD;
            }
            // 0으로 끝나는 수
            // {1,0} = {1}
            else if(j==0){
                dp[i][j] = dp[i-1][j+1] % MOD;
            }
            // 1~8로 끝나는 수
            // {7,8}, {9,8} = {7} + {8}
            else{
                dp[i][j] = dp[i-1][j-1] % MOD + dp[i-1][j+1] % MOD;
            }
        }
    }

    for(int i=0; i<=9; i++){
        ans += dp[n][i];
        ans = ans % MOD;
    }

    cout << ans % MOD;

    return 0;
}
