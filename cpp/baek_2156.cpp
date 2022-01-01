#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n;
    cin >> n;

    int *a= new int[n+1];
    int dp[10001][3] = {0, };       // n번째 포도주를 연속으로 1,2,3번 마셨을때

    for(int i=1; i<=n; i++)
        cin >> a[i];

    for(int i=1; i<=n; i++){
        dp[i][0] = max(dp[i-1][0], max(dp[i-1][1], dp[i-1][2]));
        dp[i][1] = dp[i-1][0] + a[i];
        dp[i][2] = dp[i-1][1] + a[i];
    }

    cout << max(dp[n][2], max(dp[n][0], dp[n][1]));

    return 0;
}