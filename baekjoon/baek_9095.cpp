#include <iostream>

using namespace std;

int main(){
    int t, n;

    int *dp = new int[12];
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;

    for(int i=3; i<=11; i++){
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }

    cin >> t;

    while(t--){
        cin >> n;
        cout << dp[n] << '\n';
    }
}