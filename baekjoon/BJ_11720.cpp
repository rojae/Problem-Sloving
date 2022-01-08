#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n, ans = 0;
	string str;
	cin>>n>>str;
	
	for(int i = 0; i < n; i++)
		ans += str[i] - '0';
	printf("%d", ans);
}
