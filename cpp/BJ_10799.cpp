#include<iostream>
#include<stack>
#include<string>

using namespace std;

// BaekJoon algoritm problem : 10799
int main(){
	string str;
	getline(cin,str,'\n');
	int str_size = str.size();
	int ans = 0;
	
	stack<int> st;
	for(int i = 0; i < str_size; i++){
		if(str[i] == '(')
			st.push(i);
		else{
			if(st.top() == i-1){
				st.pop();
				ans += st.size();
			}
			else{
				ans += 1;
				st.pop();
			}
		}
	}
	cout<<ans<<endl;	
}
