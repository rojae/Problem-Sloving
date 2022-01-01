#include<iostream>

using namespace std;

int main(){
	int n;
	int a[10000];
	int dp[10000] = {0,};
	int max = 0;	
	
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= n; i++){
		dp[i] = a[i];
		for(int j = 1; j <= i; j++){
			if(a[j] < a[i] && dp[i] < dp[j]+a[i])
				dp[i] = dp[j] + a[i];
		}
		if(max < dp[i])	max = dp[i];
	}
	cout<<max<<endl;
	return 0;
}