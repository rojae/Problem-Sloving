#include <iostream>
#include <vector>

#define MAX 1001
using namespace std;

int n,m,ans;    // 정점 갯수, 간선 갯수
vector<int> v[MAX];
bool visit[MAX] = {false,};

void dfs(int depth, int node){
    visit[node] = true;
    
    for(int i=0; i<v[node].size(); i++){
        int next = v[node][i];
        if(!visit[next])
            dfs(depth+1, next);
    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for(int i=1; i<=n; i++){
        if(visit[i] == false){
            dfs(1, i);
            ans++;
        }
    }

    cout << ans;
    return 0;

}