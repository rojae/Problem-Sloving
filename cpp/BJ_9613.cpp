#include<stdio.h>

long gcd(int a,int b){
	if( b ==0)
		return a;
	return gcd(b, a %b);
}
int main(){
	int n,t;
	long long ans;
		
	scanf("%d",&t);
	
	while(t--){
		scanf("%d",&n);
		int list[n];
		ans = 0;
		for(int i = 0; i < n; i++)
			scanf("%d",&list[i]);
		for(int i = 0; i < n-1; i++){
			for(int j = i+1; j < n; j++){
				ans += gcd(list[i], list[j]);
			}
		}
		printf("%ld\n",ans);
	}
}

