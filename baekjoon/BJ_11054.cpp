#include<iostream>

using namespace std;
int main(){
	int n, max = 0;
	int a[1001];
	int dp[1001];		// upside 가장 왼쪽에서 LIS 적용 
	int dp2[1001];		// downside 가장 오른쪽에서 부터 LIS 적용 
	int check[1001];	
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
		
	for(int i = 0; i < n; i++){
		dp[i] = 1;
		for(int j = 0; j < i; j++){
			if(a[i] > a[j] && dp[i] < dp[j]+1)
				dp[i] = dp[j] + 1;
		}
	}
	for(int i = n-1; i >= 0; i--){
		dp2[i] = 1;
		for(int j = n-1; j >= i; j--){
			if(a[i] > a[j] && dp2[i] < dp2[j]+1)
				dp2[i] = dp2[j] + 1;
		}
		max = (max < dp[i]+dp2[i])? dp[i]+dp2[i]-1 : max;
	}
	printf("%d", max);
}
