#include<iostream>

using namespace std;

int main(){
	int ie,is,im;
	int e=0,s=0,m=0,y=0;
	cin >> ie >> is >> im;
	while(1){
		if(ie==e && is==s && im==m){
			cout << y;
			return 0;
		}
		e++,s++,m++,y++;
		if(e > 15)	e -= 15;
		if(s > 28)	s -= 28;
		if(m > 19)	m -= 19;
	}
	return 0;	
}