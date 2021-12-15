#include<iostream>
#define SIZE 1000001
using namespace std;

int main(){
	int n;
	int *dp = new int[SIZE];
	int temp = 0;
		
	dp[0] = dp[1] = 0;
	cin >> n;
	
	for(int i = 2; i <= n; i++)	{
		dp[i] = dp[i-1] + 1;		// n -> n-1
		if(i%3==0){				
			temp = dp[i/3] + 1;
			if(dp[i] > temp)	dp[i] = temp;
		}
		if(i%2==0){
			temp = dp[i/2] + 1;
			if(dp[i] > temp)	dp[i] = temp;
		}
	}
	cout<<dp[n]<<endl;
	delete[] dp;
	return 0;
}
