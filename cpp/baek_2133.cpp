#include <iostream>

using namespace std;

int main(){
    int *dp = new int[31]();

    dp[0] = 1;
    dp[1] = 0;
    dp[2] = 3;
    dp[3] = 0;

    int n;
    cin >> n;

    if(n%2==0){
        for(int i=4; i<=n; i+=2){
            dp[i] = dp[i-2] * 3;
            for(int j=4; j<=i; j+=2){
                dp[i] += dp[i-j] * 2;
            }
        }
        cout << dp[n];
    }
    else{
        cout << '0';
    }

    return 0;

}