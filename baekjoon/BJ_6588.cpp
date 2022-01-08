#include<iostream>
#define end 1000000

int main(){
	int n = 10;
	int *c = new int[end+1];
	c[1] = 1;
	for(int i = 2; i*i<= end; i++){
		if(c[i] == 0){
			for(int j = i * i; j <= end; j+=i){
				c[j] = 1;
			}
		}
	}
	while(n!=0){
		scanf("%d",&n);
		for(int i =2; i<n-1; i++){
			if((c[i] == 0) && (c[n-i] == 0) && (i % 2 != 0)){
				printf("%d = %d + %d\n",n,i,n-i);
				break;
			}
		}
	}
	delete c;
	return 0;
}
