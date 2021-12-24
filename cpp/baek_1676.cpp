#include<iostream>

using namespace std;

int main(){
	int n,five=0;
    cin >> n;
	while(n){
		n/=5;
		five +=n;
	}
    cout << five;
	return 0;
}