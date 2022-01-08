#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int dp[101][10] = {0,};
    long long n, ans=0;
    long long mod = 1000000000;

    cin >> n;

    // dp[1] = 9
    dp[1][0] = 0;
    for(int i=1; i<=9; i++){
        dp[1][i] = 1;
    }

    for(int i=2; i<=100; i++){
        for(int j=0; j<=9; j++){
            if(j == 0){
                dp[i][j] = dp[i-1][1] % mod;
            }
            else if(j==9){
                dp[i][j] = dp[i-1][8] % mod;
            }
            else{
                dp[i][j] = dp[i-1][j-1] % mod + dp[i-1][j+1] % mod;
            }
        }
    }

    for(int i=0; i<=9; i++){
        ans += dp[n][i];
        ans %= mod;
    }

    cout << ans % mod;

    return 0;
}