#include<iostream>
#define SIZE 1001
using namespace std;

// Baekjoon problem 11726
int main(){
	int *dp = new int[SIZE];
	int n;
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;

	cin >> n;
	for(int i = 3; i <= n; i++)
		dp[i] = (dp[i-1] + dp[i-2]) % 10007;
		
	cout << dp[n] <<endl;
}
