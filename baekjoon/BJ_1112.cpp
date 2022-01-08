#include<iostream>
#include<stack>
#include<stdlib.h>

using namespace std;
// Fail
int main(){
	stack<int> st;
	long n;
	int b;
	scanf("%ld %d",&n,&b);
	if(n==0){
		printf("0");
		return 0;
	}
	while(n){
		st.push(abs(n%b));
		if(n>0)
			n /= b;
		else
			n = (abs(b)+n)/b;
	}
	while(!st.empty()){
		cout<<st.top();
		st.pop();
	}
	return 0;
}
