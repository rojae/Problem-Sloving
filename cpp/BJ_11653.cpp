#include<iostream>
#include<stdio.h>

void prime_factorization(int n){
	for(int i = 2; i * i <=n; i++){
		while(n % i == 0){
			printf("%d\n",i);
			n /= i;
		}
	}
	if(n > 1)
		printf("%d\n",n);
}

int main(){
	int n;
	scanf("%d",&n);
	prime_factorization(n);
	return 0;
}
