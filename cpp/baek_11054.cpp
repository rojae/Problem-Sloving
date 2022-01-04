#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int a[1001];
    int dp[1001];
    int dp2[1001];
    int n, ans=0;

    cin >> n;

    for(int i=1; i<=n; i++){
        cin >> a[i];
    }

    for(int i=1; i<=n; i++){
        dp[i] = 1;
        for(int j=1; j<=i; j++){
            if(a[j] < a[i] && dp[j] + 1 > dp[i])
                dp[i] = dp[j] + 1;
        }
    }

    for(int i=n; i>=0; i--){
        dp2[i] = 1;
        for(int j=n; j>=i; j--){
            if(a[j] < a[i] && dp2[j] + 1 > dp2[i])
                dp2[i] = dp2[j] + 1;
        }
    }

    for(int i=1; i<=n; i++){
        ans = (ans < dp[i]+dp2[i])? dp[i]+dp2[i]-1 : ans;
    }

    cout << ans;

    return 0;
}