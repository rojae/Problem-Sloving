#include<iostream>
#include<queue>

using namespace std;
/*
 * BaekJoon algorithm problem : 1158	
 */
int main(){
	queue<int> q;
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		q.push(i);
	cout<<"<";
	while(!q.empty()){
		for(int i = 0; i < m; i++){
			if(i != m-1)
				q.push(q.front());
			else if(q.size() > 1) 
				cout<<q.front()<<", ";
			else
				cout<<q.front();
			q.pop();
		}
	}
	cout<<">";	
}
