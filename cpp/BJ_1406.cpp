#include<iostream>
#include<stack>
#include<string>

using namespace std;
// Baekjoon problem : 1406
/*
 * Get str and command line
 * Command L moves the cursor to the left
 * Command D moves the cursor to the right
 * Command B delete left side character of cursor
 * Command P create alpha lefte side of cursor
 */
int main(){
	string str;
	stack<char> st1;	// cursor's left side
	stack<char> st2;	// cursor's right side
	int t;
	
	cin >> str;
	int n = str.size();
	for(int i = 0; i < n; i++)
		st1.push(str.at(i));

	cin >> t;

	for(int i =0; i < t; i++)
	{
		char command;
		cin >> command;
		
		if(command == 'L'){
			if(st1.size() != 0){
				st2.push(st1.top());
				st1.pop();
			}
		}
		else if(command == 'P'){
			char alpha;
			cin >> alpha;
			st1.push(alpha);;
		}
		else if(command == 'D'){
			if(st2.size() != 0){
				st1.push(st2.top());
				st2.pop();
			}	
		}
		else{	// command = B
			if(!st1.empty())
				st1.pop();
		}
	}
	while(!st1.empty()){
		st2.push(st1.top());
		st1.pop();
	}	
	while(!st2.empty()){
		cout<<st2.top();
		st2.pop();
	}
}
