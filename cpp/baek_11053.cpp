#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n, ans=0;
    cin >> n;

    int *a = new int[n+1];
    int *dp = new int[n+1];

    a[0] = dp[0] = 0;

    for(int i=1; i<=n; i++)
        cin >> a[i];

    for(int i=1; i<=n; i++){
        dp[i] = 1;
        for(int j=1; j<i; j++){
            if(a[i] > a[j] && dp[i] < dp[j] + 1){
                dp[i] = dp[j] + 1;
            }
        }
    }

    for(int i=1; i<=n; i++)
        ans = (ans < dp[i])? dp[i] : ans;

    cout << ans;

}