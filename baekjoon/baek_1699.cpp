#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n;
    cin >> n;

    int *dp = new int[n+1];

    // n까지 반복
    for(int i=1; i<=n; i++){
        dp[i] = i;  // 가장 최악의 경우

        // 제곱을 계산
        for(int j=1; j*j<=i; j++){
            dp[i] = min(dp[i], dp[i - j*j] + 1);    // buttom up 방식으로 연산 
        }
    }

    cout << dp[n];

    return 0;

}