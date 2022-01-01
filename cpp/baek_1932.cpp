#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n, ans=0;
    cin >> n;

    int a[501][501] = {0,};
    int dp[501][501] = {0,};

    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cin >> a[i][j];
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            if(j==0)
                dp[i][j] = max(dp[i-1][0], dp[i-1][1]) + a[i][j];
            else
                dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + a[i][j];
        }
    }

    for(int i=1; i<=n; i++){
        ans = max(ans, dp[n][i]);
    }

    cout << ans;
}