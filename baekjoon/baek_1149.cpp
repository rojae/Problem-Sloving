#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n, ans=1000001;
    cin >> n;

    int a[1001][3];
    int dp[1001][3];

    dp[0][0] = dp[0][1] = dp[0][2] = 0;

    for(int i=1; i<=n; i++){
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }

    for(int i=1; i<=n; i++){
        dp[i][0] = a[i][0] + min(dp[i-1][1] , dp[i-1][2]);
        dp[i][1] = a[i][1] + min(dp[i-1][0] , dp[i-1][2]);
        dp[i][2] = a[i][2] + min(dp[i-1][0] , dp[i-1][1]);        
    }

    ans = min(ans, dp[n][0]);
    ans = min(ans, dp[n][1]);
    ans = min(ans, dp[n][2]);
    
    cout << ans;
}