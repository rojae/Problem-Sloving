#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n, ans = 0;
    cin >> n;

    int a[1001] = {0,};
    int dp[1001] = {0,};

    for(int i=1; i<=n; i++)
        cin >> a[i];

    for(int i=1; i<=n; i++){
        dp[i] = 1;
        for(int j=1; j<=i; j++){
            if(dp[j] + 1 > dp[i] && a[i] < a[j])
                dp[i] = dp[j] + 1;
        }
        ans = max(ans, dp[i]);
    }

    cout << ans;

    return 0;
}