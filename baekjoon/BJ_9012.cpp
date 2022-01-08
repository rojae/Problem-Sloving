#include<iostream>
#include<stack>
using namespace std;

/*
 * Check for correct pairs of brackets : ( )
 */
string valid(string s){
	int cnt = 0;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '(')
			cnt++;
		else
			cnt--;
		if(cnt < 0)
			return "NO";
	}
	if(cnt == 0)
		return "YES";
	else
		return "NO";
}
int main(){
	int test_case;
	cin >> test_case;
	while(test_case--){
		string str;
		cin >> str;
		cout<<valid(str)<<endl;;		
	}
}


