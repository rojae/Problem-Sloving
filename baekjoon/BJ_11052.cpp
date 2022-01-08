#include<iostream>

using namespace std;

int main(){
	int n;
	cin >> n;
	int *p = new int[n+1];
	int *dp = new int[n+1];
	
	p[0] = 0;
	dp[0] = 0;
	
	for(int i = 1; i <= n; i++){
		cin >> p[i];
		dp[i] = 0;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <=i; j++)
			dp[i] = max(p[j]+dp[i-j],dp[i]); 
	}
	cout<<dp[n]<<endl;
	return 0;	
}
