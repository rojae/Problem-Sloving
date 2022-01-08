#include <iostream>

using namespace std;

int main(){
    int n, ans;
    cin >> n;

    int *a = new int[n+1];
    int dp[100001][2];  // dp[i][0] - 제거하지 않은 경우.

    for(int i=1; i<=n; i++)
        cin >> a[i];

    ans = a[1];

    for(int i=1; i<=n; i++){
        dp[i][0] = dp[i][1] = a[i];
        if(i == 1)
            continue;
        else{
            dp[i][0] = max(dp[i-1][0] + a[i], a[i]);
            dp[i][1] = max(dp[i-1][0], dp[i-1][1] + a[i]);
            ans = max(ans, max(dp[i][0], dp[i][1]));
        }
    }

    cout << ans;
    return 0;
}