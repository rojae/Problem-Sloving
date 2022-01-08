#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n,ans=0;
    cin >> n;

    int *a = new int[n+1]();
    int *dp = new int[n+1]();

    for(int i=1; i<=n; i++)
        cin >> a[i];

    for(int i=1; i<=n; i++){
        dp[i] = a[i];
        for(int j=1; j<=i; j++){
            if(a[i] > a[j] && dp[i] < dp[j] + a[i]){
                dp[i] = dp[j] + a[i];
            }
        }
    }

    for(int i=1; i<=n; i++)
        ans = max(ans, dp[i]);

    cout << ans;
    return 0;

}
