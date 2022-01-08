#include<iostream>
#include<algorithm>

using namespace std;

bool desc(int a, int b){
	return a > b;
}
int main(){
	int n,ans =0;
	scanf("%d",&n);
	int a[50];
	int b[50];

	for(int i = 0; i < n; i++)
		scanf("%d",&a[i]);
	for(int i = 0; i < n; i++)
		scanf("%d",&b[i]);
	sort(a,a+n);
	sort(b,b+n,desc);
	for(int i = 0; i < n; i++)
		ans += a[i]*b[i];
	printf("%d",ans);
}
