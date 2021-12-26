#include <iostream>

using namespace std;

#define max 1000000

int main(){
    int t, n;

    long long *dp = new long long[max+1];
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;

    for(int i=3; i<=max; i++){
        dp[i] = (dp[i-1]%1000000009 + dp[i-2]%1000000009 + dp[i-3]%1000000009)%1000000009;
    }

    cin >> t;

    while(t--){
        cin >> n;
        cout << dp[n]%1000000009 << '\n';
    }
}
