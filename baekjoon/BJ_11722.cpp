#include<iostream>
using namespace std;

int main(){
	int n, max;
	cin >> n;

	int a[1001];
	int dp[1001];
	max = 0;
	
	for(int i = 0; i < n; i++)
		cin >> a[i];
		
	for(int i = 0; i < n; i++){
		dp[i] = 1;
		for(int j = 0; j < i; j++){
			if(a[i] < a[j] && dp[i] < dp[j]+1){
				dp[i] = dp[j] + 1;
			}
		}
		max = (max < dp[i])? dp[i] : max;				
	}
	cout<<max<<endl;
	return 0;
}
