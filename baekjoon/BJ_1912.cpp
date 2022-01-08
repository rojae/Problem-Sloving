#include<iostream>

int main(){
	int i,n, max;
	int a[100000];
	int dp[100000];
	
	scanf("%d",&n);
	for(i=0; i<n; i++){
		scanf("%d",&a[i]);
	}
	max = a[0];
	for(i=0; i<n; i++){
		dp[i] = a[i];
		if(i==0) continue;
		if(dp[i] < dp[i-1] + a[i]){
			dp[i] = dp[i-1] + a[i];
		}
		max = (max < dp[i])? dp[i] : max;
	}
	printf("%d",max);
}
