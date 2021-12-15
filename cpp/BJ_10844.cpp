#include<iostream>
using namespace std;

int main(){
	int dp[100][10] = {0};
	int n;
	long mod = 1000000000;
	long ans = 0;
	
	cin >> n;
	for(int i = 1; i <=9; i++)
		dp[1][i] = 1;
	for(int i = 2; i <= n; i++){
		for(int j = 0;  j <= 9; j++){
			if(j == 9)
				dp[i][j] = dp[i-1][8];
			else if(j == 0)
				dp[i][j] = dp[i-1][1] ;
			else 
				dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1])%mod;
		}
	}
	for(int i = 0; i <=9; i++)
		ans += dp[n][i];
	cout<<ans%mod<<endl;
}
