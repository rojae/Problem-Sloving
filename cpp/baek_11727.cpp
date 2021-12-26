#include<iostream>

using namespace std;

int main(){
   int n;
   cin >> n;
   int *dp = new int[n+1];

   dp[0] = 0;
   dp[1] = 1;
   dp[2] = 3;
   dp[3] = 5;

   for(int i=4; i<=n; i++){
       dp[i] = (dp[i-1] + (2*dp[i-2]) % 10007);
   }

   cout << dp[n] % 10007;

}