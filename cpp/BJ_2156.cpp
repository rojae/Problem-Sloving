#include<iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	int a[n+1]= {0};		// ���� �� ��������  �� 
	int dp[n+1][3] = {0};	// n��° �����ָ� ����(0,1,2)������ ������ ��  
	
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= n; i++){
		dp[i][0] = max(dp[i-1][2],max(dp[i-1][0],dp[i-1][1]));
		dp[i][1] = dp[i-1][0] + a[i];
		dp[i][2] = dp[i-1][1] + a[i];
	}
	cout<<max(dp[n][2],max(dp[n][0],dp[n][1]))<<endl;
}
