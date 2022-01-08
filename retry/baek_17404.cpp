#include <iostream>

using namespace std;

int main(){
    int n,ans=1e9;
    cin >> n;

    int a[1001][3] = {0,};
    int dp[1001][3] = {0,};

    for(int i=1; i<=n; i++){
        // 순서대로 R, G, B
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }

    // 첫번째 집의 색상 선택
    for(int i=0; i<=2; i++){
        // dp에 첫번쨰 집의 색상 값을 강제 할당
        for(int j=0; j<=2; j++){
            if(i==j)
                dp[1][j] = a[1][i];
            else
                dp[1][j] = 1e9;
        }

        // 2번째 집부터, 서로 다른 색상의 집의 최소 값을 선택
        for(int j=2; j<=n; j++){
            dp[j][0] = a[j][0] + min(dp[j-1][1], dp[j-1][2]);
            dp[j][1] = a[j][1] + min(dp[j-1][0], dp[j-1][2]);
            dp[j][2] = a[j][2] + min(dp[j-1][0], dp[j-1][1]);
        }

        for(int j=0; j<=2; j++){
            if(i==j)    // 첫번째 집의 색과 마지막이 같은 경우
                continue;
            else
                ans = min(ans, dp[n][j]);
        }
    }

    cout << ans;
    return 0;
}