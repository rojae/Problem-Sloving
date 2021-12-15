#include<stdio.h>
#define min(x,y) ((x)>(y)? (y):(x))

int gcd(int x, int y);
int main(){
	int a,b;
	scanf("%d %d",&a,&b);
	int g = gcd(a,b);
	printf("%d\n",g);
	printf("%d",g*(a/g)*(b/g));
}
int gcd(int x, int y){
	if(y==0)	return x;
	else	gcd(y, x%y);	
}
