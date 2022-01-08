#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
	string str;
	int ans = 0;
	getline(cin,str,'\n');

	int s = str.size();

	stack<int> st;
	for(int i=0; i<str.size(); i++){
		// (
		if(str[i] == '('){
			st.push(i);
		}
		// )
		else{
			if(st.top() == i-1){
				st.pop();
				ans += st.size();
			}else{
				st.pop();
				ans += 1;
			}
		}
	}
	cout << ans << endl;
}