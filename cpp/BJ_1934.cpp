#include<iostream>

using namespace std;

int gcd(int x, int y){
	if(y==0)	
		return x;
	else	
		gcd(y,x%y);
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int a,b,g;
		scanf("%d %d",&a,&b);
		g = gcd(b,a);
		printf("%d\n",g*(a/g)*(b/g));
	}
}


