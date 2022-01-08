#include<iostream>

using namespace std;

bool prime(int n){
	if(n<2){
		return false;
	}
	for(int i = 2; i*i <= n; i++){
		if(n % i == 0){
			return false;
		}
	}
	return true;
}
int main(){
	int n, ans;
	ans = 0;
	scanf("%d",&n);
	int list[n];
	for(int i = 0; i < n; i++){
		scanf("%d",&list[i]);
		if(prime(list[i])) 
			ans++;
	}
	printf("%d", ans);
}
