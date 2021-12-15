#include<iostream>

int main(){
	int n,five=0;
	scanf("%d",&n);
	while(n){
		n/=5;
		five +=n;
	}
	printf("%d",five);
	return 0;
}
