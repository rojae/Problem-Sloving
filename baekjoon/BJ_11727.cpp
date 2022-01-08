#include<iostream>
#define SIZE 1001
using namespace std;

// Baekjoon problem 11727
int main(){
	int *dp = new int[SIZE];
	int n;
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 3;

	cin >> n;
	for(int i = 3; i <= n; i++)
		dp[i] = (dp[i-1] + 2*dp[i-2]) % 10007;
		
	cout << dp[n] <<endl;
}
