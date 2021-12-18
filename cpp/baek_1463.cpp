#include <iostream>
using namespace std;

// X가 3으로 나누어 떨어지면, 3으로 나눈다.
// X가 2로 나누어 떨어지면, 2로 나눈다.
// 1을 뺀다.

int main(void){
    int n;
    cin >> n;

    int *dp = new int[n+1];
    dp[0] = dp[1] = 0;

    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1]+1;
        if((i%2==0) && (dp[i] > dp[i/2]+1))
            dp[i] = dp[i/2]+1;
        if((i%3==0) && (dp[i] > dp[i/3]+1))
            dp[i] = dp[i/3]+1;
    }
    cout << dp[n] << endl;
    delete[] dp;
}