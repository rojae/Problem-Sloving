#include <iostream>
#include <stack>
#include <string>

using namespace std;

// 알파벳 소문자('a'-'z'), 숫자('0'-'9'), 공백(' '), 특수 문자('<', '>')로만 이루어져 있다.
// 문자열의 시작과 끝은 공백이 아니다.
// '<'와 '>'가 문자열에 있는 경우 번갈아가면서 등장하며, '<'이 먼저 등장한다. 또, 두 문자의 개수는 같다.


int main(void){
	stack<char> stack;	// 뒤집힐 문자열이 들어가는 스택
    string str;
    string ans;
    bool isOpen = false;
    getline(cin,str);	// 문자 한 줄 입력
    
    for(int i=0; i<str.size(); i++){
    	char ch = str[i];
    	
		// "<"
		if(ch == '<'){
    		isOpen = true;    						
			
    		while(!stack.empty()){
				ans += stack.top();
				stack.pop();	
			}						
			
			ans += "<";
    	}
		// ">"
    	else if(ch == '>'){
    		isOpen = false;

			while(!stack.empty()){
    			ans += stack.top();
				stack.pop();	
			}
			
			ans += ">";
		}
		// " "
		else if(ch == ' '){
			while(!stack.empty()){
    			ans += stack.top();
				stack.pop();	
			}
			
			ans += " ";
		}
		// 일반 문자의 경우
		// "< >" 안에 있는 경우 뒤집지 않는다.
		// 괄호 밖에 있는 경우 뒤집는다.
		else{
			if(!isOpen)
				stack.push(str[i]);
			else
				ans += str[i];
		}
	}
	
	while(!stack.empty()){
		ans += stack.top();
		stack.pop();	
	}	
	
	cout << ans << endl;
	
}