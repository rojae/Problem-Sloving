#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <memory.h>

#define MAX 1000+1
using namespace std;

int n,m,node;
bool check[MAX] = {false,};
vector<int> v[MAX];

void dfs(int node){
    stack<int> st;
    st.push(node);

    while(!st.empty()){
        int top = st.top();
        st.pop();

        if(check[top])
            continue;
        
        check[top] = true;
        cout << top << ' ';

        // 내림차순 ...
        // 9, 8, 7, .... 2, 1 (stack, 1부터 꺼내야 한다)
        sort(v[top].begin(), v[top].end(), greater<int>());

        for(unsigned int i = 0; i < v[top].size(); i++)
            st.push(v[top][i]);
    }
    cout << '\n';
}

void bfs(int node){
    queue<int> qu;
    qu.push(node);

    while(!qu.empty()){
        int front = qu.front();
        qu.pop();

        if(check[front])
            continue;

        check[front] = true;
        cout << front << ' ';

        // 오름차순 ...
        // 1, 2, 3, 4, ... 8, 9 (queue, 1부터 꺼내야 한다)
        sort(v[front].begin(), v[front].end());

        for(unsigned int i = 0; i < v[front].size(); i++){
            qu.push(v[front][i]);
        }
    }

    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> node;

    while(m--){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    dfs(node);
    memset(check, false, MAX);
    bfs(node);

    return 0;
}