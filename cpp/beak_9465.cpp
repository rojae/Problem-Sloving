#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n, ans = 0;
        cin >> n;

        int dp[100001][3] = {0,};      // dp[i][0] : 뜯지 않을때
        int cost[100001][3] = {0,};

        for(int j=1; j<=2; j++){
            for(int i=1; i<=n; i++){
                cin >> cost[i][j];
            }
        }

        for(int i=1; i<=n; i++){
            dp[i][0] = max(max(dp[i-1][0], dp[i-1][1]), dp[i-1][2]);
            dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + cost[i][1];
            dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + cost[i][2];

            ans = max(ans, dp[i][0]);
            ans = max(ans, dp[i][1]);
            ans = max(ans, dp[i][2]);
        }



        cout << ans << '\n';
    }

    return 0;
}