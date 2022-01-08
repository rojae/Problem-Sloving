#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int t;
    cin >> t;
    int *dp = new int[t+1];

    dp[0] = 0;
    
    for(int i=1; i<=t; i++)
        cin >> dp[i];

    for(int i=1; i<=t; i++){
        for(int j=1; j<=i-1; j++){
            dp[i] = min(dp[i], dp[i-j]+dp[j]);
        }
    }

    cout << dp[t];
}