#include<iostream>

using namespace std;

int main(){
	int n;
	int dp[30] = {1,0,3};
	
	scanf("%d", &n);
	
	if(n % 2 == 0){
		for(int i = 4; i <= n; i+=2){
			dp[i] = dp[i-2] * 3;
			for(int j = 4; i >= j; j+= 2)
				dp[i] += dp[i-j]*2;
		}
	}
	
	cout<<dp[n]<<endl;
	
	return 0;
}
