#include<iostream>
using namespace std;

int main(){
	int input;
	cin >> input;
	int* dp = new int[input+1];
	dp[0] = dp[1] = 0;
	
	for(int i =2; i <= input; i++){
		dp[i] = dp[i-1]+1;
		if((i%2==0) && (dp[i] > dp[i/2] + 1))
			dp[i] = dp[i/2]+1;
		if((i%3==0) && (dp[i] > dp[i/3] + 1))
			dp[i] = dp[i/3]+1;
	}
	cout<<dp[input]<<endl;
	delete[] dp;
	return 0;
}
