#include <iostream>

using namespace std;

int main(){
    int n, m = 1;
    long long ans = 0;
    cin >> n;

    // dp[n][m] : n자리이며 끝이 m으로 끝나는 이친수
    long long dp[n+1][m+1];

    dp[1][0] = 0;
    dp[1][1] = 1;
    dp[2][0] = 1;
    dp[2][1] = 0;

    for(int i=3; i<=n; i++){
        for(int j=0; j<=1; j++){
            if(j == 0)
                dp[i][0] = dp[i-1][0] + dp[i-1][1];
            else if(j == 1)
                dp[i][1] = dp[i-1][0];
        }
    }
    
    ans += dp[n][0];
    ans += dp[n][1];

    cout << ans;
    
    return 0;
}