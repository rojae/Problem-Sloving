#include <iostream>

using namespace std;

const int mod = 1e9 + 9;
const int MAX = 100000;

long long dp[MAX+1][4];

int main(){

    int t;
    cin >> t;

    // dp[n][m] = 마지막 오는 수가 m이며, n을 만드는 경우의 수

    dp[1][1] = dp[2][2] = dp[3][1] = dp[3][2] = dp[3][3] = 1;

        
    for(int i=4; i<=MAX+1; i++){
        dp[i][1] = (dp[i-1][2] + dp[i-1][3]) % mod;
        dp[i][2] = (dp[i-2][1] + dp[i-2][3]) % mod;
        dp[i][3] = (dp[i-3][1] + dp[i-3][2]) % mod;
    }

    while(t--){
        int n;
        cin >> n;
        cout << (dp[n][1] + dp[n][2] + dp[n][3]) % mod << '\n';
    }

    return 0;
}