#include<iostream>
#define size 11

using namespace std;

int main(){
	int t, n;
	int *dp = new int[size];
	
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 4; i <= n; i++)
			dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
		cout<<dp[n]<<endl;
	}
}
