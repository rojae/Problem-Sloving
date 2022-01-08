#include<iostream>
#include<stack>
#include<stdlib.h>
using namespace std;

int main(){
	stack<int> st;
	long long n;
	cin>>n;
	if(n==0)	{
		printf("0");
		return 0;
	}
	while(n){
		st.push(abs(n%-2));
		if(n>0)
			n /= -2;
		else
			n = (n-1)/-2;
	}
	while(!st.empty()){
		cout<<st.top();
		st.pop();
	}
	return 0;
}
