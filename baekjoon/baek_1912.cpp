#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n, ans;

    cin >> n;

    int *dp = new int[n+1];

    for(int i=1; i<=n; i++)
        cin >> dp[i];
    
    ans = dp[1];

    for(int i=2; i<=n; i++){
        dp[i] = max(dp[i], dp[i] + dp[i-1]);
        ans = max(ans, dp[i]);
    }

    cout << ans;

    return 0;
}