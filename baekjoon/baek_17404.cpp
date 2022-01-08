#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n, ans=1e9;
    cin >> n;

    int a[1001][3] = {0,};        // [i][0].. [i][2] : RGB
    int dp[1001][3] = {0,};

    for(int i=1; i<=n; i++){
        for(int j=0; j<3; j++){
            cin >> a[i][j];
        }
    }

    for(int i=0; i<=2; i++){
        for(int j=0; j<=2; j++){
            if(i==j)
                dp[1][j] = a[1][j];
            else
                dp[1][j] = 1e9;
        }

        for(int j=2; j<=n; j++){
            dp[j][0] = a[j][0] + min(dp[j-1][1], dp[j-1][2]);
            dp[j][1] = a[j][1] + min(dp[j-1][0], dp[j-1][2]);
            dp[j][2] = a[j][2] + min(dp[j-1][0], dp[j-1][1]);
        }


        for(int j=0; j<=2; j++){
            if(i==j)
                continue;
            ans = min(ans, dp[n][j]);
        }
    }

    cout << ans;

    return 0;    
}