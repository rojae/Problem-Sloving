#include<iostream>
#include<algorithm>

using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	int a[300];
	int dp[300][3];
	
	for(int i =0; i < n; i++){
		scanf("%d",&a[i]);
	}
	dp[0][1] = a[0];
	dp[1][1] = a[1];
	dp[1][2] = a[0]+a[1];
	
	for(int i = 2; i < n; i++){
		dp[i][2] = dp[i-1][1] + a[i];
		dp[i][1] = max(dp[i-2][1], dp[i-2][2]) + a[i];
	}
	cout<<max(dp[n-1][1],dp[n-1][2])<<endl;
}
